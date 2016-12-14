/*-------------------------------------------------------------------
 *  OPAL-RT Technologies inc
 *
 *  Copyright (C) 2014. All rights reserved.
 *
 *  File name =         AsyncEthernet.c
 *  Last modified by =  Simon Labbé
 *
 *  This is code example of an asynchronous program to establish
 *  an UDP or a TCP communication with a third-party device or
 *  with another simulator.
 *
 *  The code is only implementing basic communication. Feel free
 *  to use it as a starting point for your own asynchronous
 *  application.
 *-----------------------------------------------------------------*/
#ifndef WIN32
#define PROGNAME "AsyncEthernet"

// Standard ANSI C headers needed for this program
#include <stdio.h>
#include <stdarg.h>
#include <signal.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netdb.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#if defined(__QNXNTO__)
// For QNX v6.x threads
#include <process.h>
#include <sys/sched.h>
#include <pthread.h>
#include <devctl.h>
#include <sys/dcmd_chr.h>
#elif defined(__linux__)
#define _GNU_SOURCE   1
#include <sched.h>
#if defined(__redhawk__)
#include <cpuset.h>
#include <mpadvise.h>
#endif
#endif
// Define RTLAB before including OpalPrint.h for messages to be sent
// to the OpalDisplay. Otherwise stdout will be used.

#ifndef RTLAB
#define RTLAB
#endif

#include "OpalPrint.h"
#include "OpalGenAsyncParamCtrl.h"
#include "AsyncEthernet.h"


// This is just for initializing the shared memory access to communicate
// with the RT-LAB model. It's easier to remember the arguments like this
#define ASYNC_SHMEM_NAME argv[1]
#define ASYNC_SHMEM_SIZE atoi(argv[2])
#define PRINT_SHMEM_NAME argv[3]


// Use the smallest possible memory footprint to store the data_out
// and data_in structures.
#pragma pack(1)

// ****** FORMAT TO SPECIFIC PROTOCOL HERE ******************************
//
// Define the structure of the data that we exchange between send/recv threads


typedef struct data_in_out
{
  int                  ctrl_id;
  int                  nbr_to_remote_endpoint;
  int                  type_to_remote_endpoint;
  int                  offset_to_remote_endpoint;
  int                  nbr_from_remote_endpoint;
  int                  type_from_remote_endpoint;
  int                  offset_from_remote_endpoint;
  int                  swap_rx;
  int                  swap_tx;
  char                 nic_name[20];
  int                  protocol;
  int                  tcp_mode;
  int                  port;
  char                 remote_ip[20];
  int                  nbr_byte_to_remote_endpoint;
  int                  nbr_byte_from_remote_endpoint;
  double              *p_buf_to_model;
  double              *p_buf_from_model;
  char                *p_buf_tx;
  char                *p_buf_rx;
  int                  sock_id;
  int                  sock_id_data;
  int                  rx_status;
  int                  tx_status;
  int                  tx_ready;
  int                  conn_status;
  struct sockaddr_in   servaddr;
  struct sockaddr_in   hostaddr;
  socklen_t            servaddr_size;
  socklen_t            hostaddr_size;
  pthread_mutex_t      tx_lock;
  pthread_mutex_t      rx_lock;
} AsyncEthernetCfgStruct;
// **********************************************************************


/************************************************************************/
/* Defines
/************************************************************************/



/************************************************************************/
/* Pragma definitions
/************************************************************************/
#pragma pack()


/************************************************************************/
/* Global variables
/************************************************************************/



/************************************************************************/
/* Threads
/************************************************************************/

        void *read_from_model                  (void *p_arg);
        void *write_to_model                   (void *p_arg);
        void *rx_handler                       (void *p_arg);
        void *tx_handler                       (void *p_arg);

/************************************************************************/
/* Functions
/************************************************************************/

static  int   get_config                       (void *p_arg);

static  int   validate_config                  (void *p_arg);

static  int   validate_model                   (void *p_arg);

static  void  print_cfg                        (void *p_arg);

static  void  print_data_type                  (int data_type);

static  int   allocate_buffers                 (void *p_arg);

static  void  free_buffers                     (void *p_arg);

static int    get_nbr_bytes_per_signal         (int data_type);

static  int   init_locks                       (void *p_arg);

static  int   wait_trigger                     (void *p_arg);

static  int   init_tcp                         (void *p_arg);

static  int   init_udp                         (void *p_arg);

static  int   receive_packet                   (void *p_arg);

static  int   transmit_packet                  (void *p_arg);

static  int   validate_interface               (void *p_arg);

static  void  close_shm                        (char         *argv[]);

static  void  OpalTrace                        (const char   *format, ...);

static  int   AssignProcToCpu                  (void);




/************************************************************************/
/* Main
/************************************************************************/
int main (int argc, char *argv[])
{
    pthread_t                 tid_read;
    pthread_t                 tid_write;
	pthread_t                 tid_rx;
	pthread_t                 tid_tx;
    pthread_attr_t            attr_read;
    pthread_attr_t            attr_write;
	pthread_attr_t            attr_rx;
	pthread_attr_t            attr_tx;
    int                       model_state;
	int                       rc;
	int                       err;
	AsyncEthernetCfgStruct     *AsyncEthernetCfg;


    /* Check for the proper arguments to the program. */
    if (argc < 4)
    {
        printf("Invalid Arguments: 1-AsyncShmemName 2-AsyncShmemSize 3-PrintShmemName\n");
        exit(0);
    }

    /* Enable the OpalPrint function. This prints to the OpalDisplay. */
    if (OpalSystemCtrl_Register(PRINT_SHMEM_NAME) != 0)
    {
        printf("%s: ERROR: OpalPrint() access not available\n", PROGNAME);
        exit(-1);
    }

    /* Open Share Memory created by the model. */
    if((OpalOpenAsyncMem (ASYNC_SHMEM_SIZE, ASYNC_SHMEM_NAME)) != 0)
    {
        OpalPrint("%s -> Error: Model shared memory not available\n", PROGNAME);
		OpalPrint("%s -> Error: communication interface will not be started\n", PROGNAME);
        exit(-1);
    }

    /* Assign process to a given CPU order to support partial XHP. */
    AssignProcToCpu();

	/* Allocate the structure that will contains the block configuration. */
	AsyncEthernetCfg = (AsyncEthernetCfgStruct *)malloc (sizeof (AsyncEthernetCfgStruct));
	if (AsyncEthernetCfg == NULL)
	{
	    OpalPrint("%s -> Error: Failed to allocate configuration structure\n", PROGNAME);
	    OpalPrint("%s -> Error: communication interface will not be started\n", PROGNAME);
		close_shm(argv);
        exit(-1);
	}

    /* Get block configuration. */
    rc = get_config(AsyncEthernetCfg);
	if (rc != 0)
	{
		close_shm(argv);
        exit(-1);
	}

	/* Validate the configuration. */
	rc = validate_config(AsyncEthernetCfg);
	if (rc != 0)
	{
	    OpalPrint("%s -> Error: communication interface will not be started\n", PROGNAME);
		close_shm(argv);
        exit(-1);
	}

	/* Validate the model inputs. */
	rc = validate_model(AsyncEthernetCfg);
	if (rc != 0)
	{
	    OpalPrint("%s -> Error: communication interface will not be started\n", PROGNAME);
		close_shm(argv);
        exit(-1);
	}

	/* Display the configuration parameters. */
    print_cfg(AsyncEthernetCfg);

	/* Allocate transmit and receive buffers. */
	rc = allocate_buffers(AsyncEthernetCfg);
	if (rc != 0)
	{
        OpalPrint("%s[%d] -> Error: buffer allocation failed\n", PROGNAME, AsyncEthernetCfg->ctrl_id);
		OpalPrint("%s[%d] -> Error: communication interface will not be started\n", PROGNAME, AsyncEthernetCfg->ctrl_id);
		close_shm(argv);
		free_buffers(AsyncEthernetCfg);
        exit(-1);
	}

	/* Initialize lock mutexes. */
	rc = init_locks(AsyncEthernetCfg);
	if (rc != 0)
	{
	    OpalPrint("%s[%d] -> Error: communication interface will not be started\n", PROGNAME, AsyncEthernetCfg->ctrl_id);
		close_shm(argv);
		free_buffers(AsyncEthernetCfg);
        exit(-1);
	}

	/* Initialize TCP or UDP session. */
	if (AsyncEthernetCfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_TCP)
	{
		rc = init_tcp(AsyncEthernetCfg);
	} else {
		rc = init_udp(AsyncEthernetCfg);
	}

	if (rc != 0)
	{
	    OpalPrint("%s[%d] -> Error: communication interface will not be started\n", PROGNAME, AsyncEthernetCfg->ctrl_id);
		close_shm(argv);
		free_buffers(AsyncEthernetCfg);
        exit(-1);
	}


    /* Wait until the model is running. */
    do
    {
         usleep(1000);
		 /* Get model state. */
        model_state = OpalGetAsyncModelState();
	} while (model_state == STATE_PAUSE);

	/* Get model state. */
	model_state = OpalGetAsyncModelState();
	if ((model_state != STATE_RESET) && (model_state != STATE_STOP))
	{
		/* Start thread to write data to the model. */
		pthread_attr_init (&attr_write);
		if ((pthread_create (&tid_write, &attr_write, write_to_model, AsyncEthernetCfg)) == -1)
		{
			OpalPrint("%s[%d] -> Error: can not create thread (write_to_model), errno = %d\n", PROGNAME, AsyncEthernetCfg->ctrl_id, errno);
		}

     	/* Start thread to read data to the model. */
		pthread_attr_init (&attr_read);
		if ((pthread_create (&tid_read, &attr_read, read_from_model, AsyncEthernetCfg)) == -1)
		{
			OpalPrint("%s[%d] -> Error: can not create thread (read_from_model), errno = %d\n", PROGNAME, AsyncEthernetCfg->ctrl_id, errno);
		}

     	/* Start reception handler thread */
		pthread_attr_init (&attr_rx);
		if ((pthread_create (&tid_rx, &attr_rx, rx_handler, AsyncEthernetCfg)) == -1)
		{
			OpalPrint("%s %s-> Error: can not create TCP reception handler thread, errno = %d\n", PROGNAME, AsyncEthernetCfg->ctrl_id, errno);
		}

     	/* Start transmission handler thread */
		pthread_attr_init (&attr_tx);
		if ((pthread_create (&tid_tx, &attr_tx, tx_handler, AsyncEthernetCfg)) == -1)
		{
			OpalPrint("%s[%d] -> Error: can not create transmission handler thread, errno = %d\n", PROGNAME, AsyncEthernetCfg->ctrl_id, errno);
		}

		/* Wait for write thread to finish. */
		if ((err = pthread_join (tid_write, NULL)) != 0)
		{
			OpalPrint("%s[%d] -> Error: pthread_join (write_to_model), errno = %d\n", PROGNAME, AsyncEthernetCfg->ctrl_id, err);
		}

		/* Wait for read thread to finish. */
		if ((err = pthread_join (tid_read, NULL)) != 0)
		{
			OpalPrint("%s[%d] -> Error: pthread_join (read_from_model), errno = %d\n", PROGNAME, AsyncEthernetCfg->ctrl_id, err);
		}

		/* Wait for reception handler thread to finish. */
		if ((err = pthread_join (tid_rx, NULL)) != 0)
		{
			OpalPrint("%s[%d] -> Error: pthread_join (rx_handler), errno = %d\n", PROGNAME, AsyncEthernetCfg->ctrl_id, err);
		}

		/* Wait for transmission handler thread to finish. */
		if ((err = pthread_join (tid_tx, NULL)) != 0)
		{
			OpalPrint("%s[%d] -> Error: pthread_join (tx_handler), errno = %d\n", PROGNAME, AsyncEthernetCfg->ctrl_id, err);
		}

	}

	free_buffers(AsyncEthernetCfg);
	close_shm(argv);

    return(0);
}


/* =================================================================================
 * Name:          read_from_model()
 *
 * Description:   Read the data stored into the asynchronous memory by the model.
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        none.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
void  *read_from_model (void *p_arg)
{
	int  n;
    int  model_state;
    int  send_id;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

    do
    {
        /* Get model state. */
        model_state = OpalGetAsyncModelState();
        if(model_state == STATE_PAUSE)
        {
		    usleep(1000);
            continue;
        }

        send_id = 0;
		do {
			if((n = OpalWaitForAsyncSendRequest ((unsigned int *)&send_id)) != 0)
			{
				model_state = OpalGetAsyncModelState();
				if ((model_state != STATE_RESET) && (model_state != STATE_STOP) && (model_state != STATE_ERROR))
				{
					OpalSetAsyncSendIconError(n, send_id);
				} else {
                    return ((void *)0);
				}
			}
		} while (send_id != p_cfg->ctrl_id);

		/* Acquire lock before reading data from the model to make sure the TCP handler ...  */
        /* ... is not in the middle of writing the data buffer to be sent to remote endpoint.*/
		pthread_mutex_lock(&p_cfg->tx_lock);

		/* Read data from the model and copy data in the buffer. */
		OpalGetAsyncSendIconData (p_cfg->p_buf_from_model, ((p_cfg->nbr_to_remote_endpoint - (p_cfg->offset_to_remote_endpoint+7)/8) * sizeof(double)), p_cfg->ctrl_id);

		/* Set the transmission ready flag. */
		p_cfg->tx_ready = 1;

		/* Release the lock. */
		pthread_mutex_unlock(&p_cfg->tx_lock);

		/* Set the appropriate error on the asynchronous send block. */
        OpalSetAsyncSendIconError(p_cfg->tx_status, p_cfg->ctrl_id);

		/* Flag the transmission as done. */
        OpalAsyncSendRequestDone(p_cfg->ctrl_id);

		/* Sleep to avoid taking over the CPU0. */
		usleep(1000);

        /* Before continuing, we make sure that the real-time model ...       */
        /* ... has not been stopped. If it has, we stop the receive thread.   */
        model_state = OpalGetAsyncModelState();
    } while ((model_state != STATE_RESET) && (model_state != STATE_STOP) && (model_state != STATE_ERROR));


    return ((void *)0);
}

/* =================================================================================
 * Name:          write_to_model()
 *
 * Description:   Read the data from the received ethernet buffer and send it to the mode.
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        none.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
void  *write_to_model (void *p_arg)
{
    int model_state;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

	if (p_cfg->nbr_from_remote_endpoint <= 0)
		return ((void *)0);
		
	/* Initialize error code to 0. */
	OpalSetAsyncRecvIconError  (0, p_cfg->ctrl_id);
    do
    {
        /* Get model state. */
        model_state = OpalGetAsyncModelState();
        if(model_state == STATE_PAUSE)
        {
		    usleep(1000);
            continue;
        }

		/* Acquire lock before sending data to the model to make sure the TCP handler ...     */
        /* ... is not in the middle of reading the data buffer received from remote endpoint. */
		pthread_mutex_lock(&p_cfg->rx_lock);

		OpalSetAsyncRecvIconData(p_cfg->p_buf_to_model, ((p_cfg->nbr_from_remote_endpoint - (p_cfg->offset_from_remote_endpoint+7)/8) * sizeof(double)), p_cfg->ctrl_id);

		/* Release the lock. */
		pthread_mutex_unlock(&p_cfg->rx_lock);

		/* Set the appropriate error on the asynchronous receive block. */
		OpalSetAsyncRecvIconError(p_cfg->rx_status, p_cfg->ctrl_id);

        /* Before continuing, we make sure that the real-time model ...       */
        /* ... has not been stopped. If it has, we stop the receive thread.   */
        model_state = OpalGetAsyncModelState();

		/* Sleep to avoid taking over the CPU0. */
		usleep(1000);
    } while ((model_state != STATE_RESET) && (model_state != STATE_STOP) && (model_state != STATE_ERROR));


    return ((void *)0);
}

/* =================================================================================
 * Name:          rx_handler()
 *
 * Description:   Handle the TCP connection and data reception from remote endpoint
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        none.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
void  *rx_handler (void *p_arg)
{
    int model_state;
	int rx_error;
	int tx_error;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;
    struct sigaction  signal_action;
    int cmd_arg;
	int rc;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;


	/* Kill the reception thread if no data needs to be received from remote endpoint. */
	if((p_cfg->nbr_from_remote_endpoint <= (p_cfg->offset_from_remote_endpoint+7)/8)) {
		OpalPrint("%s[%d] -> Reception thread not started because no data is expected to be received\n", PROGNAME, p_cfg->ctrl_id);
		p_cfg->rx_status = -1;
		return ((void *)0);
	}
	
	if (p_cfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_TCP) {
		if (p_cfg->tcp_mode == ASYNC_ETH_PARAM_TCP_MODE_CLIENT) {
			/* Not supported for the moment. */
			OpalPrint("%s[%d] -> Trying to establish a connection with %s on port %d...\n", PROGNAME, p_cfg->ctrl_id, p_cfg->remote_ip, p_cfg->port);
		} else {
			OpalPrint("%s[%d] -> Waiting for a TCP connection on port %d...\n", PROGNAME, p_cfg->ctrl_id, p_cfg->port);
		}
	}

    do
    {
        /* Get model state. */
        model_state = OpalGetAsyncModelState();
        if(model_state == STATE_PAUSE)
        {
		    usleep(1000);
            continue;
        }

		if ((model_state == STATE_RESET) || \
		    (model_state == STATE_STOP)  || \
			(model_state == STATE_ERROR))
			return ((void *)0);

		if (p_cfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_TCP) {
			if (p_cfg->tcp_mode == ASYNC_ETH_PARAM_TCP_MODE_CLIENT) {
				/* Not supported for the moment */
				rc = connect(p_cfg->sock_id, (struct sockaddr *)&p_cfg->servaddr, sizeof(struct sockaddr_in));
				if (rc < 0)
				{
					/* Wait one second before retrying to connect. */
					sleep(1);
					continue;
				}
				OpalPrint("%s[%d] -> Connection established\n", PROGNAME, p_cfg->ctrl_id);
				p_cfg->sock_id_data = p_cfg->sock_id;
				p_cfg->conn_status = 1;
			} else {

				/* Accept the socket. */
				p_cfg->sock_id_data = accept(p_cfg->sock_id, &client_addr, &client_addr_size);
				if (p_cfg->sock_id_data == -1)
				{
					usleep(1000);
					continue;
				}
				OpalPrint("%s[%d] -> Connection established\n", PROGNAME, p_cfg->ctrl_id);

				/* 1. Set TCP keep-alive. */
				cmd_arg = 1;
				rc = setsockopt(p_cfg->sock_id_data, SOL_SOCKET, SO_KEEPALIVE, (char *) &cmd_arg, sizeof(cmd_arg));
				if (rc != 0)
				{
					OpalPrint("%s[%d] -> Error: failed to set TCP keep-alive on the accepted socket\n", PROGNAME, p_cfg->ctrl_id);
					OpalPrint("%s[%d] -> Error: communication interface will be disabled\n", PROGNAME, p_cfg->ctrl_id);
					close(p_cfg->sock_id);
					close(p_cfg->sock_id_data);
					return ((void *)0);
				}

				/* 2. Set TCP no delay. */
				cmd_arg = 1;
				rc = setsockopt(p_cfg->sock_id_data, SOL_TCP, TCP_NODELAY, (char *) &cmd_arg, sizeof(cmd_arg));
				if (rc != 0)
				{
					OpalPrint("%s[%d] -> Error: failed to set TCP no-delay on the accepted socket\n", PROGNAME, p_cfg->ctrl_id);
					OpalPrint("%s[%d] -> Error: communication interface will be disabled\n", PROGNAME, p_cfg->ctrl_id);
					close(p_cfg->sock_id);
					close(p_cfg->sock_id_data);
					return ((void *)0);
				}

				/* 3. Set blocking mode. */
				memset(&signal_action, sizeof(signal_action), 0);
				signal_action.sa_handler = SIG_IGN;
				sigaction(SIGPIPE, &signal_action, (struct sigaction *) NULL );
				rc = fcntl(p_cfg->sock_id_data, F_SETFL, O_NONBLOCK);
				if (rc != 0)
				{
					OpalPrint("%s[%d] -> Error: failed to set the accepted socket in non-blocking mode\n", PROGNAME, p_cfg->ctrl_id);
					OpalPrint("%s[%d] -> Error: communication interface will be disabled\n", PROGNAME, p_cfg->ctrl_id);
					close(p_cfg->sock_id);
					close(p_cfg->sock_id_data);
					return ((void *)0);
				}
				p_cfg->conn_status = 1;
			}
		}

		/* Handle data transmission in both directions until the socket is closed. */
		do
		{
			rx_error = receive_packet((void *)p_cfg);
			model_state = OpalGetAsyncModelState();
			usleep(1000);
		} while ((model_state != STATE_RESET) && (model_state != STATE_STOP) && (model_state != STATE_ERROR) && (rx_error != -1));

		/* Re-initalize the socket (client) or wait for the next connection (server). */
		p_cfg->conn_status = 0;
		p_cfg->rx_status   = 0;
		p_cfg->tx_status   = 0;

		if (p_cfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_TCP) {
			if (p_cfg->tcp_mode == ASYNC_ETH_PARAM_TCP_MODE_CLIENT) {
				close(p_cfg->sock_id);
				/* Re-initialize TCP session. */
				rc = init_tcp(p_cfg);
				if (rc != 0)
				{
					OpalPrint("%s[%d] -> Error: failed to re-initialize socket to attempt another connection\n", PROGNAME, p_cfg->ctrl_id);
					OpalPrint("%s[%d] -> Error: communication interface will be disabled\n", PROGNAME, p_cfg->ctrl_id);
					return ((void *)0);
				}
				OpalPrint("%s[%d] -> Trying to re-establish a connection with %s on port %d...\n", PROGNAME, p_cfg->ctrl_id, p_cfg->remote_ip, p_cfg->port);
			} else {
				close(p_cfg->sock_id_data);
				OpalPrint("%s[%d] -> Waiting for a TCP connection on port %d...\n", PROGNAME, p_cfg->ctrl_id, p_cfg->port);
			}
		}

        /* Before continuing, we make sure that the real-time model ...       */
        /* ... has not been stopped. If it has, we stop the receive thread.   */
        model_state = OpalGetAsyncModelState();

		/* Sleep to avoid taking over the CPU0. */
		usleep(1000);
    } while ((model_state != STATE_RESET) && (model_state != STATE_STOP) && (model_state != STATE_ERROR));

	close(p_cfg->sock_id);
	close(p_cfg->sock_id_data);
    return ((void *)0);
}

/* =================================================================================
 * Name:          tx_handler()
 *
 * Description:   Handle the TCP transmission of data to remote endpoint
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        none.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
void  *tx_handler (void *p_arg)
{
    int model_state;
	int tx_error;
	int rc;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

	/* Kill the transmission thread if no data needs to be sent to remote endpoint. */
	if((p_cfg->nbr_to_remote_endpoint <= (p_cfg->offset_to_remote_endpoint+7)/8)) {
		OpalPrint("%s[%d] -> Transmission thread not started because the number of data to be received is set to 0\n", PROGNAME, p_cfg->ctrl_id);
		p_cfg->tx_status = -1;
		return ((void *)0);
	}

    do
    {
        /* Get model state. */
        model_state = OpalGetAsyncModelState();
        if(model_state == STATE_PAUSE)
        {
		    usleep(1000);
            continue;
        }

		/* Wait until the connection is established. */
		do
		{
		    p_cfg->tx_status = 0;
			model_state = OpalGetAsyncModelState();
			if ((model_state == STATE_RESET) || \
  			    (model_state == STATE_STOP)  || \
				(model_state == STATE_ERROR))
				return ((void *)0);

				 usleep(1000);
				 continue;
		} while (p_cfg->conn_status == 0);

		/* Handle data transmission.  */
		do
		{
			tx_error = transmit_packet(p_cfg);
			model_state = OpalGetAsyncModelState();
			usleep(1000);
		} while ((model_state != STATE_RESET) && (model_state != STATE_STOP) && (model_state != STATE_ERROR) && (tx_error != -1));


        /* Before continuing, we make sure that the real-time model ...       */
        /* ... has not been stopped. If it has, we stop the receive thread.   */
        model_state = OpalGetAsyncModelState();

		/* Sleep to avoid taking over the CPU0. */
		usleep(1000);
    } while ((model_state != STATE_RESET) && (model_state != STATE_STOP) && (model_state != STATE_ERROR));

	close(p_cfg->sock_id);
	close(p_cfg->sock_id_data);
    return ((void *)0);
}



/* =================================================================================
 * Name:          get_config()
 *
 * Description:   Get block parameters.
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        0, if the initialization is successful.
 *
 *               -1, otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int get_config(void *p_arg)
{
    Opal_GenAsyncParam_Ctrl   IconCtrlStruct;
	int                       err;
	int                       nbr_byte_per_signal;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

	/* Initialize structures. */
	memset(p_cfg->remote_ip, 0,  sizeof(p_cfg->remote_ip));
	memset(p_cfg->nic_name,  0,  sizeof(p_cfg->nic_name));

    /* Get asynchronous controller parameters. */
    memset(&IconCtrlStruct, 0, sizeof(IconCtrlStruct));
    if((err = OpalGetAsyncCtrlParameters(&IconCtrlStruct, sizeof(IconCtrlStruct))) != 0)
    {
    	OpalPrint("%s -> Error: can not get block parameters (%d).\n", PROGNAME, err);
    	exit(-1);
    }

	/* Get controller ID. */
	p_cfg->ctrl_id = (int)IconCtrlStruct.controllerID;

	/* Fill the configuration structure with integer mask parameters. */
	p_cfg->nbr_to_remote_endpoint     = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_IX_NBR_DATA_TO_SEND];
	p_cfg->type_to_remote_endpoint    = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_IX_DATA_TYPE_TO_SEND];
	p_cfg->offset_to_remote_endpoint    = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_BYTE_OFFSET_TX];

	p_cfg->nbr_from_remote_endpoint   = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_IX_NBR_DATA_TO_RECEIVE];
	p_cfg->type_from_remote_endpoint  = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_IX_DATA_TYPE_TO_RECEIVE];
	p_cfg->offset_from_remote_endpoint  = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_BYTE_OFFSET_RX];
	
	p_cfg->swap_tx = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_SWAP_TX];
	p_cfg->swap_rx = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_SWAP_RX];

	p_cfg->protocol        = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_IX_PROTOCOL];
	p_cfg->tcp_mode        = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_IX_TCP_MODE];
	p_cfg->port            = (int)IconCtrlStruct.FloatParam[ASYNC_ETH_PARAM_IX_PORT];

	/* Fill the configuration structure with float mask parameters. */
    strcpy(p_cfg->nic_name,  IconCtrlStruct.StringParam[ASYNC_ETH_PARAM_IX_NIC_NAME]);
	strcpy(p_cfg->remote_ip, IconCtrlStruct.StringParam[ASYNC_ETH_PARAM_IX_REMOTE_IP]);

	/* Compute the number of bytes that have to be sent to the remote endpoint. */
	nbr_byte_per_signal = get_nbr_bytes_per_signal(p_cfg->type_to_remote_endpoint);
	p_cfg->nbr_byte_to_remote_endpoint = nbr_byte_per_signal * p_cfg->nbr_to_remote_endpoint;

	/* Compute the number of bytes that are expected to be received from the remote endpoint. */
	nbr_byte_per_signal = get_nbr_bytes_per_signal(p_cfg->type_from_remote_endpoint);
	p_cfg->nbr_byte_from_remote_endpoint = nbr_byte_per_signal * p_cfg->nbr_from_remote_endpoint;

	return (0);
}

/* =================================================================================
 * Name:          validate_config()
 *
 * Description:   Validate block parameters.
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        0, if the initialization is successful.
 *
 *               -1, otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int validate_config(void *p_arg)
{
	int rc;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;
	
	if (p_cfg->ctrl_id < 0)
	{
	    OpalPrint("%s -> Error: invalid controller ID (%d). Must be higher or equal than 0\n", PROGNAME);
		return -1;
	}	

	if (p_cfg->port < 0)
	{
	    OpalPrint("%s[%d] -> Error: invalid port (%d). Must be higher or equal than 0\n", PROGNAME, p_cfg->ctrl_id, p_cfg->port);
		return -1;
	}

	if (p_cfg->nbr_to_remote_endpoint < 0)
	{
	    OpalPrint("%s[%d] -> Error: invalid number of data configured to be sent (%d). Must be higher or equal than 0\n", PROGNAME, p_cfg->ctrl_id, p_cfg->nbr_to_remote_endpoint);
		return -1;
	}
	
	if (p_cfg->offset_to_remote_endpoint < 0)
	{
	    OpalPrint("%s[%d] -> Error: invalid byte offset of transmission buffer (%d). Must be higher or equal than 0\n", PROGNAME, p_cfg->ctrl_id, p_cfg->offset_to_remote_endpoint);
		return -1;
	}
	
	if (p_cfg->offset_from_remote_endpoint < 0)
	{
	    OpalPrint("%s[%d] -> Error: invalid byte offset of reception buffer (%d). Must be higher or equal than 0\n", PROGNAME, p_cfg->ctrl_id, p_cfg->offset_from_remote_endpoint);
		return -1;
	}		

	if (p_cfg->nbr_from_remote_endpoint < -1)
	{
	    OpalPrint("%s[%d] -> Error: invalid number of data expected to be received (%d). Must be higher or equal than 0\n", PROGNAME, p_cfg->ctrl_id, p_cfg->nbr_from_remote_endpoint);
		return -1;
	}

	if ((p_cfg->nbr_to_remote_endpoint == 0) && (p_cfg->nbr_from_remote_endpoint == 0))
	{
	    OpalPrint("%s[%d] -> Error: at least one signal must be expected to be received or configured to be sent to remote endpoint.\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
	}
	
	if ((p_cfg->swap_tx != 0) && (p_cfg->swap_tx  != 1))
	{
	    OpalPrint("%s[%d] -> Error: transmission endianness swapping must be 0 or 1.\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
	}
	
	if ((p_cfg->swap_rx != 0) && (p_cfg->swap_rx  != 1))
	{
	    OpalPrint("%s[%d] -> Error: reception endianness swapping must be 0 or 1.\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
	}	
	

	rc = validate_interface(p_cfg);
	if (rc != 0)
		return -1;

	p_cfg->nbr_to_remote_endpoint = p_cfg->nbr_to_remote_endpoint + (p_cfg->offset_to_remote_endpoint+7)/8;
	p_cfg->nbr_from_remote_endpoint = p_cfg->nbr_from_remote_endpoint + (p_cfg->offset_from_remote_endpoint+7)/8;
	p_cfg->nbr_byte_to_remote_endpoint = p_cfg->nbr_byte_to_remote_endpoint + p_cfg->offset_to_remote_endpoint;
	p_cfg->nbr_byte_from_remote_endpoint = p_cfg->nbr_byte_from_remote_endpoint + p_cfg->offset_from_remote_endpoint;

	return (0);
}

/* =================================================================================
 * Name:          validate_model()
 *
 * Description:   Validate model connections.
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        0, if no error.
 *
 *               -1, otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
 static int validate_model(void *p_arg)
 {
    int  mdldata_send_size;
    int  mdldata_to_remote_endpoint;
    int  mdldata_recv_size;
    int  mdldata_from_remote_endpoint;
	int  nbr_send_icon;
	int  nbr_recv_icon;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

    /* Get send block input width. */
	OpalGetAsyncSendIconDataLength (&mdldata_send_size,  p_cfg->ctrl_id);

	/* Compute the signals coming from the model to remote endpoint. */
	mdldata_to_remote_endpoint = mdldata_send_size/sizeof(double);

	/* Validate that it equals to the number of data configured in the block. */
	if ((p_cfg->nbr_to_remote_endpoint - (p_cfg->offset_to_remote_endpoint+7)/8) != 0) {	
		if (mdldata_to_remote_endpoint != p_cfg->nbr_to_remote_endpoint - (p_cfg->offset_to_remote_endpoint+7)/8)
		{
			OpalPrint("%s -> Error: The number of data to be sent (%d) does not match with the block configuration (%d).\n", PROGNAME, mdldata_to_remote_endpoint, p_cfg->nbr_to_remote_endpoint - (p_cfg->offset_to_remote_endpoint+7)/8);
			return(-1);
		}
	}

	
    /* Get recv block input width. */
	OpalGetAsyncRecvIconDataLength (&mdldata_recv_size,  p_cfg->ctrl_id);

	/* Compute the signals coming from the model to remote endpoint. */
	mdldata_from_remote_endpoint = mdldata_recv_size/sizeof(double);

	/* Validate that it equals to the number of data configured in the block. */
	if (p_cfg->nbr_from_remote_endpoint - (p_cfg->offset_from_remote_endpoint+7)/8 != -1) {
		if ((p_cfg->nbr_from_remote_endpoint - (p_cfg->offset_from_remote_endpoint+7)/8) != 0) {
			if (mdldata_from_remote_endpoint != p_cfg->nbr_from_remote_endpoint - (p_cfg->offset_from_remote_endpoint+7)/8)
			{
				OpalPrint("%s -> Error: The number of data expected to be received (%d) does not match with the block configuration (%d).\n", PROGNAME, mdldata_from_remote_endpoint, p_cfg->nbr_from_remote_endpoint - (p_cfg->offset_from_remote_endpoint+7)/8);
				return(-1);
			}
		}
	}
	
	/* Validate that the model has at least one send icon. */
    OpalGetNbAsyncSendIcon(&nbr_send_icon);
    if(nbr_send_icon <= 0)
    {
	    OpalPrint("%s -> Invalid number of Asynchronous Send blocks detected in the communication interface block.\n", PROGNAME);
		return(-1);
    }

	/* Validate that the model has at least one recv icon. */
	OpalGetNbAsyncRecvIcon(&nbr_recv_icon);
    if(nbr_recv_icon <= 0)
    {
	    OpalPrint("%s -> Invalid number of Asynchronous Recv blocks detected in the communication interface block.\n", PROGNAME);
		return(-1);
    }

    return(0);
 }

/* =================================================================================
 * Name:          print_cfg()
 *
 * Description:   Print the block configuration
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        none.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static void print_cfg(void *p_arg)
{
	int nbr_byte_per_signal;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

    OpalTrace("\n------------------------------------------------------------------------\n");
    OpalTrace(" %s[%d] communication interface configuration:\n", PROGNAME, p_cfg->ctrl_id, p_cfg->ctrl_id);

    OpalTrace("------------------------------------------------------------------------\n");
    OpalTrace("%s[%d] -> Device ID:                      %d\n", PROGNAME, p_cfg->ctrl_id, p_cfg->ctrl_id);
	OpalTrace("%s[%d] -> Number of data to send:         %d\n", PROGNAME, p_cfg->ctrl_id, p_cfg->nbr_to_remote_endpoint - (p_cfg->offset_to_remote_endpoint+7)/8);
	OpalTrace("%s[%d] -> Type of data to send:           "    , PROGNAME, p_cfg->ctrl_id);

	print_data_type(p_cfg->type_to_remote_endpoint);
	OpalTrace("%s[%d] -> Transmission buffer offset:     %d bytes\n", PROGNAME, p_cfg->ctrl_id, p_cfg->offset_to_remote_endpoint);

    if (p_cfg->swap_tx == 0)
    {
		OpalTrace("%s[%d] -> Swap data before transmission:  disabled\n", PROGNAME, p_cfg->ctrl_id);
    } else {
        OpalTrace("%s[%d] -> Swap data before transmission:  enabled\n", PROGNAME, p_cfg->ctrl_id);
    }
	
	OpalTrace("%s[%d] -> Number of data to receive:      %d\n", PROGNAME, p_cfg->ctrl_id, p_cfg->nbr_from_remote_endpoint - (p_cfg->offset_from_remote_endpoint+7)/8);
	OpalTrace("%s[%d] -> Type of data to receive:        "    , PROGNAME, p_cfg->ctrl_id);

	print_data_type(p_cfg->type_from_remote_endpoint);
	
	OpalTrace("%s[%d] -> Reception buffer offset:        %d bytes\n" , PROGNAME, p_cfg->ctrl_id, p_cfg->offset_from_remote_endpoint);
	
    if (p_cfg->swap_rx == 0)
    {
		OpalTrace("%s[%d] -> Swap data after reception:      disabled\n", PROGNAME, p_cfg->ctrl_id);
    } else {
        OpalTrace("%s[%d] -> Swap data after reception:      enabled\n", PROGNAME, p_cfg->ctrl_id);
    }	
	
    OpalTrace("%s[%d] -> Network interface:              %s\n", PROGNAME, p_cfg->ctrl_id, p_cfg->nic_name);


    if (p_cfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_UDP)
    {
		OpalTrace("%s[%d] -> Protocol:                       UDP\n", PROGNAME, p_cfg->ctrl_id);
    } else {
        OpalTrace("%s[%d] -> Protocol:                       TCP\n", PROGNAME, p_cfg->ctrl_id);
    }

	if (p_cfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_TCP)
	{
		if (p_cfg->tcp_mode == ASYNC_ETH_PARAM_TCP_MODE_CLIENT)
		{
			OpalTrace("%s[%d] -> TCP mode:                       Client\n", PROGNAME, p_cfg->ctrl_id);
		} else {
			OpalTrace("%s[%d] -> TCP mode:                       Server\n", PROGNAME, p_cfg->ctrl_id);
		}
	}

	OpalTrace("%s[%d] -> Port:                           %d\n", PROGNAME, p_cfg->ctrl_id, p_cfg->port);

    if ((p_cfg->tcp_mode == ASYNC_ETH_PARAM_TCP_MODE_CLIENT) ||
        (p_cfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_UDP))
    {
		OpalTrace("%s[%d] -> Remote IP address:              %s\n", PROGNAME, p_cfg->ctrl_id, p_cfg->remote_ip);
	}

    OpalTrace("------------------------------------------------------------------------\n\n");
 }

 /* =================================================================================
 * Name:          get_data_type()
 *
 * Description:   Get the data types selected by the user.
 *
 * Argument(s):   data_type		Type of the data to be printed
 *
 * Return:          none.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static void print_data_type(int data_type)
{
	switch(data_type)
	{
		case ASYNC_ETH_DATA_TYPE_UINT8:
			OpalTrace("UNSIGNED 8-bits\n");
			break;

		case ASYNC_ETH_DATA_TYPE_INT8:
			OpalTrace("SIGNED 8-bits\n");
			break;

		case ASYNC_ETH_DATA_TYPE_UINT16:
			OpalTrace("UNSIGNED 16-bits\n");
			break;

		case ASYNC_ETH_DATA_TYPE_INT16:
			OpalTrace("SIGNED 16-bits\n");
			break;

		case ASYNC_ETH_DATA_TYPE_UINT32:
			OpalTrace("UNSIGNED 32-bits\n");
			break;

		case ASYNC_ETH_DATA_TYPE_INT32:
			OpalTrace("SIGNED 32-bits\n");
			break;

		case ASYNC_ETH_DATA_TYPE_FLOAT:
			OpalTrace("FLOATING POINT (32-bits)\n");
			break;

		case ASYNC_ETH_DATA_TYPE_DOUBLE:
			OpalTrace("DOUBLE PRECISION FLOATING POINT (64-bits)\n");
			break;

		default:
			OpalTrace("INVALID\n");
			break;
	}
}

  /* =================================================================================
 * Name:          get_nbr_bytes_per_signal()
 *
 * Description:   Get the number of bytes per signal according to the configuration.
 *
 * Argument(s):   data_type		Type of the data to be printed
 *
 * Return:        Signal size, if no errors.
 *
 *                 -1. otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int get_nbr_bytes_per_signal(int data_type)
{
	int nbr_byte_per_signal;

	switch(data_type)
	{
		case ASYNC_ETH_DATA_TYPE_UINT8:
			nbr_byte_per_signal = sizeof(char);
			break;

		case ASYNC_ETH_DATA_TYPE_INT8:
			nbr_byte_per_signal = sizeof(char);
			break;

		case ASYNC_ETH_DATA_TYPE_UINT16:
			nbr_byte_per_signal =  sizeof(short);
			break;

		case ASYNC_ETH_DATA_TYPE_INT16:
			nbr_byte_per_signal =  sizeof(short);
			break;

		case ASYNC_ETH_DATA_TYPE_UINT32:
			nbr_byte_per_signal =  sizeof(int);
			break;

		case ASYNC_ETH_DATA_TYPE_INT32:
			nbr_byte_per_signal =  sizeof(int);
			break;

		case ASYNC_ETH_DATA_TYPE_FLOAT:
			nbr_byte_per_signal =  sizeof(float);
			break;

		case ASYNC_ETH_DATA_TYPE_DOUBLE:
			nbr_byte_per_signal =  sizeof(double);
			break;

		default:
			return -1;
	}

	return nbr_byte_per_signal;
}


 /* =================================================================================
 * Name:          allocate_buffers()
 *
 * Description:   Allocate transmit and receive buffers.
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        0, if no error.
 *
 *               -1, otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int allocate_buffers (void *p_arg)
{
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

	/* Allocate the buffer that will receive the data from the Simulink model. */
	if (p_cfg->nbr_to_remote_endpoint >= 0)
	{
		p_cfg->p_buf_from_model  = (double *)malloc (p_cfg->nbr_to_remote_endpoint * sizeof (double));
		if (p_cfg->p_buf_from_model == NULL)
			return -1;

		memset(p_cfg->p_buf_from_model, 0, p_cfg->nbr_to_remote_endpoint * sizeof (double));
	}

	/* Allocate the buffer that will send data to the Simulink model. */
	if (p_cfg->nbr_from_remote_endpoint >= 0)
	{
		p_cfg->p_buf_to_model  = (double *)malloc (p_cfg->nbr_from_remote_endpoint * sizeof (double));
		if (p_cfg->p_buf_to_model == NULL)
			return -1;

		memset(p_cfg->p_buf_to_model, 0, p_cfg->nbr_from_remote_endpoint * sizeof (double));
	}

	/* Allocate the transmit buffer. */
	if (p_cfg->nbr_byte_to_remote_endpoint >= 0)
	{
		p_cfg->p_buf_tx = (char *)malloc(p_cfg->nbr_byte_to_remote_endpoint);
		if (p_cfg->p_buf_tx == NULL)
			return -1;

		memset(p_cfg->p_buf_tx, 0, p_cfg->nbr_byte_to_remote_endpoint);
	}

	/* Allocate the receive buffer. */
	if (p_cfg->nbr_byte_from_remote_endpoint >= 0)
	{
		p_cfg->p_buf_rx = (char *)malloc(p_cfg->nbr_byte_from_remote_endpoint);
		if (p_cfg->p_buf_rx == NULL)
			return -1;

		memset(p_cfg->p_buf_rx, 0, p_cfg->nbr_byte_from_remote_endpoint);
	}

	return 0;
}

 /* =================================================================================
 * Name:          free_buffers()
 *
 * Description:   Free allocated buffers
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        none.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static void free_buffers (void *p_arg)
{
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

	if (p_cfg->p_buf_from_model)
		free(p_cfg->p_buf_from_model);

	if (p_cfg->p_buf_to_model)
		free(p_cfg->p_buf_to_model);

	if (p_cfg->p_buf_tx)
		free(p_cfg->p_buf_tx);

	if (p_cfg->p_buf_rx)
		free(p_cfg->p_buf_rx);
}


 /* =================================================================================
 * Name:          init_locks()
 *
 * Description:   Initialize mutexes used for data protection mecanisms.
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        0, if no error.
 *
 *               -1, otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int init_locks (void *p_arg)
{
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

    /* Initialize transmission lock mutex. */
    if(pthread_mutex_init(&p_cfg->tx_lock, NULL) != 0)
	{
		OpalPrint("%s[%d] -> Error: failed to initialize data transmission protection lock\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
    }

    /* Initialize reception lock mutex. */
    if(pthread_mutex_init(&p_cfg->rx_lock, NULL) != 0)
	{
		OpalPrint("%s[%d] -> Error: failed to initialize data reception protection lock\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
    }

	return 0;
}

 /* =================================================================================
 * Name:          init_tcp()
 *
 * Description:   Initialize TCP session according to the configuration
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        0, if no error.
 *
 *               -1, otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int init_tcp (void *p_arg)
{
    struct sockaddr_in local_addr;
	struct ifreq       ifr;
    struct sigaction   signal_action;
    char              *p_char;
    int                cmd_arg;
	int                rc;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

	/* Opening connection socket. */
	p_cfg->sock_id = socket(AF_INET, SOCK_STREAM, 0);
	if (p_cfg->sock_id == -1)
    {
		OpalPrint("%s[%d] -> Error: failed to create TCP socket\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
	}

	/* 1. Make socket reusable. */
	cmd_arg = 1;
    rc = setsockopt(p_cfg->sock_id, SOL_SOCKET, SO_REUSEADDR, (char *) &cmd_arg, sizeof(cmd_arg));
    if (rc != 0)
    {
		close(p_cfg->sock_id);
		OpalPrint("%s[%d] -> Error: failed to make TCP socket reusable\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
    }

	/* 2. Attach socket to physical network interface. */
	memset(&ifr, 0, sizeof(ifr));
    strncpy(&ifr.ifr_name[0], p_cfg->nic_name, strlen(p_cfg->nic_name));
    rc = setsockopt(p_cfg->sock_id, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr));
    if (rc != 0)
    {
		close(p_cfg->sock_id);
		OpalPrint("%s[%d] -> Error: failed attach TCP socket to physical network interface (%s)\n", PROGNAME, p_cfg->ctrl_id, p_cfg->nic_name);
		return -1;
    }

	/* 3. Set non-blocking mode. */
	memset(&signal_action, 0, sizeof(signal_action));
	signal_action.sa_handler = SIG_IGN;
	sigaction(SIGPIPE, &signal_action, (struct sigaction *) NULL );
	rc = fcntl(p_cfg->sock_id, F_SETFL, O_NONBLOCK);
	if (rc != 0)
	{
		close(p_cfg->sock_id);
		OpalPrint("%s[%d] -> Error: failed set TCP socket in non-blocking mode\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
	}

	/* 4. Bind the socket to the local port */
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(p_cfg->port);
	local_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    rc = bind(p_cfg->sock_id, (struct sockaddr *) &local_addr, sizeof(local_addr));
    if (rc != 0)
	{
		close(p_cfg->sock_id);
		OpalPrint("%s[%d] -> Error: failed to bind TCP socket to the local port (%d)\n", PROGNAME, p_cfg->ctrl_id, p_cfg->port);
		return -1;
    }

	/* 5. Init TCP session according to the selected TCP mode. */
	if (p_cfg->tcp_mode == ASYNC_ETH_PARAM_TCP_MODE_CLIENT) {
		/* 6. Set server address. */
		memset(&p_cfg->servaddr, 0, sizeof(struct sockaddr_in));
		p_cfg->servaddr.sin_family = AF_INET;
		p_cfg->servaddr.sin_addr.s_addr = inet_addr(p_cfg->remote_ip);
		p_cfg->servaddr.sin_port = htons(p_cfg->port);

	} else {

		/* Set the listening socket queue. */
		rc = listen(p_cfg->sock_id, 10);
		if (rc != 0)
		{
			close(p_cfg->sock_id);
			OpalPrint("%s[%d] -> Error: failed set the UDP socket listen queue\n", PROGNAME, p_cfg->ctrl_id);
			return -1;
		}
	}

	/* Initialize control and status variables. */
	p_cfg->rx_status   = 0;
	p_cfg->tx_status   = 0;
	p_cfg->tx_ready    = 0;
	p_cfg->conn_status = 0;


	return 0;
}

/* =================================================================================
 * Name:          init_udp()
 *
 * Description:   Initialize UDP session according to the configuration
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        0, if no error.
 *
 *               -1, otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int init_udp (void *p_arg)
{
    struct sockaddr_in local_addr;
	struct ifreq       ifr;
    struct sigaction   signal_action;
    char              *p_char;
    int                cmd_arg;
	int                rc;
	int                broadcast_en;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

	/* Opening TX data socket. */
	p_cfg->sock_id = socket(AF_INET, SOCK_DGRAM, 0);
	if (p_cfg->sock_id == -1)
    {
		OpalPrint("%s[%d] -> Error: failed to create UDP transmission socket\n", PROGNAME, p_cfg->ctrl_id);
		return -1;

	}
	
	/* Enable broadcast on the UDP socket if required. */
	broadcast_en = 0;
	if(strcmp(p_cfg->remote_ip, "255.255.255.255") == 0)  {
		broadcast_en = 1;		
		rc = setsockopt(p_cfg->sock_id, SOL_SOCKET, SO_BROADCAST, &broadcast_en, sizeof(broadcast_en));
		if (rc != 0)
		{
			close(p_cfg->sock_id);
			OpalPrint("%s[%d] -> Error: failed to enable broadcast mode on the UDP socket\n", PROGNAME, p_cfg->ctrl_id);
			return -1;
		}		
	}

	/* Opening RX socket. */
	p_cfg->sock_id_data = socket(AF_INET, SOCK_DGRAM, 0);
	if (p_cfg->sock_id_data == -1)
    {
		OpalPrint("%s[%d] -> Error: failed to create UDP reception socket\n", PROGNAME, p_cfg->ctrl_id);
		return -1;

	}

	/* 1. Make socket reusable. */
	cmd_arg = 1;
    rc = setsockopt(p_cfg->sock_id_data, SOL_SOCKET, SO_REUSEADDR, (char *) &cmd_arg, sizeof(cmd_arg));
    if (rc != 0)
    {
		close(p_cfg->sock_id);
		close(p_cfg->sock_id_data);
		OpalPrint("%s[%d] -> Error: failed to make UDP socket reusable\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
    }

	/* 2. Attach socket to physical network interface. */
	memset(&ifr, 0, sizeof(ifr));
    strncpy(&ifr.ifr_name[0], p_cfg->nic_name, strlen(p_cfg->nic_name));
    rc = setsockopt(p_cfg->sock_id_data, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr));
    if (rc != 0)
    {
		close(p_cfg->sock_id);
		close(p_cfg->sock_id_data);
		OpalPrint("%s[%d] -> Error: failed attach receive UDP socket to physical network interface (%s)\n", PROGNAME, p_cfg->ctrl_id, p_cfg->nic_name);
		return -1;
    }

    rc = setsockopt(p_cfg->sock_id, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr));
    if (rc != 0)
    {
		close(p_cfg->sock_id);
		close(p_cfg->sock_id_data);
		OpalPrint("%s[%d] -> Error: failed attach transmit UDP socket to physical network interface (%s)\n", PROGNAME, p_cfg->ctrl_id, p_cfg->nic_name);
		return -1;
    }

	/* 3. Set non-blocking mode. */
	memset(&signal_action, 0, sizeof(signal_action));
	signal_action.sa_handler = SIG_IGN;
	sigaction(SIGPIPE, &signal_action, (struct sigaction *) NULL );
	rc = fcntl(p_cfg->sock_id_data, F_SETFL, O_NONBLOCK);
	if (rc != 0)
	{
		close(p_cfg->sock_id);
		close(p_cfg->sock_id_data);
		OpalPrint("%s[%d] -> Error: failed set UDP socket in non-blocking mode\n", PROGNAME, p_cfg->ctrl_id);
		return -1;
	}

	/* 4. Bind the transmission socket to the local port */
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(p_cfg->port);
	local_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    rc = bind(p_cfg->sock_id_data, (struct sockaddr *) &local_addr, sizeof(local_addr));
    if (rc != 0)
	{
		close(p_cfg->sock_id_data);
		OpalPrint("%s[%d] -> Error: failed to bind UDP socket to the local port (%d)\n", PROGNAME, p_cfg->ctrl_id, p_cfg->port);
		return -1;
    }

	/* 5. Set server address. */
	memset(&p_cfg->servaddr, 0, sizeof(struct sockaddr_in));
	p_cfg->servaddr.sin_family = AF_INET;
	p_cfg->servaddr.sin_port = htons(p_cfg->port);
	
	if (broadcast_en  == 0) {
		p_cfg->servaddr.sin_addr.s_addr = inet_addr(p_cfg->remote_ip);
		OpalPrint("%s[%d] -> UDP communication successfully initialized\n", PROGNAME, p_cfg->ctrl_id);
	} else {
		OpalPrint("%s[%d] -> UDP broadcast communication successfully initialized\n", PROGNAME, p_cfg->ctrl_id);
		p_cfg->servaddr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
	}


	/* Initialize control and status variables. */
	p_cfg->rx_status   = 0;
	p_cfg->tx_status   = 0;
	p_cfg->tx_ready    = 0;
	p_cfg->conn_status = -10;


	return 0;
}

 /* =================================================================================
 * Name:          receive_packet()
 *
 * Description:   Receive  data from the data socket
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        0, if no error.
 *
 *               -1, otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int receive_packet (void *p_arg)
{
	char           *p_buf;
	unsigned short *p_buf_16;
	unsigned int   *p_buf_32;
	float          *p_buf_f32;
	double         *p_buf_64;
    int             rx_len;
	int             rx_data_cnt;
    struct  timeval tv;
	int             rc;
	fd_set          read_fd;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;

	/* Return if nothing needs to be received from remote endpoint. */
	if(p_cfg->nbr_from_remote_endpoint <= (p_cfg->offset_from_remote_endpoint+7)/8) {
		p_cfg->rx_status = -1;
		return 0;
	}

	if (p_cfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_TCP)
	{
		FD_ZERO(&read_fd);
		FD_SET(p_cfg->sock_id_data, &read_fd);

		tv.tv_sec  = 0;
		tv.tv_usec = 0;

		rc = select(p_cfg->sock_id_data + 1, &read_fd, NULL, NULL, &tv);
		if (rc != -1)
		{
			if (FD_ISSET(p_cfg->sock_id_data, &read_fd))
			{
			  memset((char *)p_cfg->p_buf_rx, 0, p_cfg->nbr_byte_from_remote_endpoint);
			  rx_len = recv(p_cfg->sock_id_data, (char *)p_cfg->p_buf_rx, p_cfg->nbr_byte_from_remote_endpoint, 0);
			}
		}

		/* Validate if the connection still alive. */
		if ((rc == 1) && (rx_len <= 0))
		{
			p_cfg->rx_status = 0;
			p_cfg->tx_status = 0;
			OpalPrint("%s[%d] -> Connection closed by the client\n", PROGNAME, p_cfg->ctrl_id);
			return -1;
		}
	} else {
		FD_ZERO(&read_fd);
		FD_SET(p_cfg->sock_id_data, &read_fd);

		tv.tv_sec  = 0;
		tv.tv_usec = 0;

		rc = select(p_cfg->sock_id_data + 1, &read_fd, NULL, NULL, &tv);
		if (rc != -1)
		{
			if (FD_ISSET(p_cfg->sock_id_data, &read_fd))
			{
			  memset((char *)p_cfg->p_buf_rx, 0, p_cfg->nbr_byte_from_remote_endpoint);
			  rx_len = recvfrom(p_cfg->sock_id_data, (char *)p_cfg->p_buf_rx, p_cfg->nbr_byte_from_remote_endpoint, 0, (struct sockaddr *)&p_cfg->hostaddr, &p_cfg->hostaddr_size);
			}
		}

		/* Validate if the connection still alive. */
		if ((rc == 1) && (rx_len <= 0))
		{
			p_cfg->rx_status = 0;
			p_cfg->tx_status = 0;
			OpalPrint("%s[%d] -> Connection closed by the client\n", PROGNAME, p_cfg->ctrl_id);
			return -1;
		}
	}

	if (rx_len == p_cfg->nbr_byte_from_remote_endpoint)
	{
	    p_cfg->rx_status = 1;

		/* Acquire transmission lock. */
		pthread_mutex_lock(&p_cfg->rx_lock);
		p_buf     = (char *)          p_cfg->p_buf_rx;
		p_buf     += p_cfg->offset_from_remote_endpoint;

		p_buf_16  = (unsigned short *)p_buf;
		p_buf_32  = (unsigned int *)  p_buf;
		p_buf_f32 = (float *)         p_buf;
		p_buf_64  = (double *)        p_buf;
		for (rx_data_cnt = 0; rx_data_cnt < p_cfg->nbr_from_remote_endpoint - (p_cfg->offset_from_remote_endpoint+7)/8; rx_data_cnt++) {
			switch(p_cfg->type_from_remote_endpoint)
			{
				case ASYNC_ETH_DATA_TYPE_UINT8:
					p_cfg->p_buf_to_model[rx_data_cnt] = (unsigned char)*p_buf;
					p_buf += sizeof(unsigned char);
					break;

				case ASYNC_ETH_DATA_TYPE_INT8:
					p_cfg->p_buf_to_model[rx_data_cnt] = (signed char)*p_buf;
					p_buf += sizeof(signed char);
					break;

				case ASYNC_ETH_DATA_TYPE_UINT16:
					if(p_cfg->swap_rx)			   
						*p_buf_16 = ntohs(*p_buf_16);					
					p_cfg->p_buf_to_model[rx_data_cnt] = (unsigned short)*p_buf_16;
					p_buf_16++;
					break;

				case ASYNC_ETH_DATA_TYPE_INT16:
					if(p_cfg->swap_rx)			   
						*p_buf_16 = ntohs(*p_buf_16);				
					p_cfg->p_buf_to_model[rx_data_cnt] = (signed short)*p_buf_16;
					p_buf_16++;
					break;

				case ASYNC_ETH_DATA_TYPE_UINT32:
					if(p_cfg->swap_rx)			   
						*p_buf_32 = ntohl(*p_buf_32);	
						
					p_cfg->p_buf_to_model[rx_data_cnt] = (unsigned int)*p_buf_32;
					p_buf_32++;
					break;

				case ASYNC_ETH_DATA_TYPE_INT32:
					if(p_cfg->swap_rx)			   
						*p_buf_32 = ntohl(*p_buf_32);				
				    p_cfg->p_buf_to_model[rx_data_cnt] = (signed int)*p_buf_32;
					p_buf_32++;
					break;

				case ASYNC_ETH_DATA_TYPE_FLOAT:
					if(p_cfg->swap_rx)
						swap32((void*)p_buf_f32);					
					p_cfg->p_buf_to_model[rx_data_cnt] = (float)*p_buf_f32;
					p_buf_f32++;
					break;

				case ASYNC_ETH_DATA_TYPE_DOUBLE:
					if(p_cfg->swap_rx)
						swap64((void*)p_buf_64);					
					p_cfg->p_buf_to_model[rx_data_cnt] = (double)*p_buf_64;
					p_buf_64++;
					break;

				default:
					break;
			}
		}

		/* Release reception lock. */
		pthread_mutex_unlock(&p_cfg->rx_lock);
	} else if (rx_len > 0) {
		p_cfg->rx_status = -2;
	}

	return 0;
}

/* =================================================================================
 * Name:          transmit_packet()
 *
 * Description:   Send data to the data socket
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        0, if no error.
 *
 *               -1, otherwise.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int transmit_packet (void *p_arg)
{
	int 			tx_len;
	char 			*p_buf;
	unsigned short 	*p_buf_16;
	unsigned int   	*p_buf_32;
	float          	*p_buf_f32;
	double         	*p_buf_64;
	int 			tx_data_cnt;
	unsigned int 	byte_cnt, offset_cnt;
	AsyncEthernetCfgStruct 	*p_cfg = (AsyncEthernetCfgStruct *) p_arg;

	/* Return if nothing needs to be transmitted to remote endpoint. */
	if(p_cfg->nbr_to_remote_endpoint <= (p_cfg->offset_to_remote_endpoint+7)/8) {
		p_cfg->tx_status = -1;
		return 0;
	}

    /* Acquire transmission lock. */
	pthread_mutex_lock(&p_cfg->tx_lock);

	/* Do not transmit if the trigger is not there. */
	if(p_cfg->tx_ready == 0) {
		/* Release transmission lock. */
		pthread_mutex_unlock(&p_cfg->tx_lock);
		return 0;
	}

	/* Do not transmit in TCP client if there is no connection. */
	if (p_cfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_TCP)
	{
		if ((p_cfg->tcp_mode != ASYNC_ETH_PARAM_TCP_MODE_SERVER)  &&
		   (p_cfg->conn_status != 1))
		{
			/* Release transmission lock. */
			pthread_mutex_unlock(&p_cfg->tx_lock);
			return 0;
		}
	}

	/* Fill the transmission buffer with the shared memory data. */
	p_buf     = (char *) p_cfg->p_buf_tx;
	
	/* Fill offset with data byte count */
	p_buf		+= p_cfg->offset_to_remote_endpoint;
	byte_cnt 	= p_cfg->nbr_byte_to_remote_endpoint - p_cfg->offset_to_remote_endpoint;
	offset_cnt	= p_cfg->offset_to_remote_endpoint;
	while (offset_cnt > 0) {
		p_buf--;
		*p_buf = (byte_cnt % 10) | 0x30;
		byte_cnt /= 10;
		offset_cnt--;
	}
	if ((byte_cnt != 0) && (offset_cnt != 0))
		OpalPrint("%s[%d] -> Error: Transmission offset not large enough to contain number of bytes to be transmitted\n", PROGNAME, p_cfg->ctrl_id);
	p_buf     += p_cfg->offset_to_remote_endpoint;

	p_buf_16  = (unsigned short *)	p_buf;
	p_buf_32  = (unsigned int *)  	p_buf;
	p_buf_f32 = (float *)         	p_buf;
	p_buf_64  = (double *)        	p_buf;
	for (tx_data_cnt = 0; tx_data_cnt < p_cfg->nbr_to_remote_endpoint - (p_cfg->offset_to_remote_endpoint+7)/8; tx_data_cnt++) {
		switch(p_cfg->type_to_remote_endpoint)
		{
			case ASYNC_ETH_DATA_TYPE_UINT8:
			   *p_buf = (unsigned char)p_cfg->p_buf_from_model[tx_data_cnt];
			    p_buf += sizeof(unsigned char);
				break;

			case ASYNC_ETH_DATA_TYPE_INT8:
			   *p_buf = (signed char)p_cfg->p_buf_from_model[tx_data_cnt];
			    p_buf += sizeof(signed char);
				break;

			case ASYNC_ETH_DATA_TYPE_UINT16:
			   *p_buf_16 = (unsigned short)p_cfg->p_buf_from_model[tx_data_cnt];
			    if(p_cfg->swap_tx)			   
					*p_buf_16 = ntohs(*p_buf_16);				   
			    p_buf_16++;
				break;

			case ASYNC_ETH_DATA_TYPE_INT16:
			   *p_buf_16 = (signed short)p_cfg->p_buf_from_model[tx_data_cnt];
			    if(p_cfg->swap_tx)			   
					*p_buf_16 = ntohs(*p_buf_16);			   
			    p_buf_16++;
				break;

			case ASYNC_ETH_DATA_TYPE_UINT32:
			   *p_buf_32 = (unsigned int)p_cfg->p_buf_from_model[tx_data_cnt];
			    if(p_cfg->swap_tx)			   
					*p_buf_32 = ntohl(*p_buf_32);				   
			    p_buf_32++;
				break;

			case ASYNC_ETH_DATA_TYPE_INT32:
			   *p_buf_32 = (signed int)p_cfg->p_buf_from_model[tx_data_cnt];
			    if(p_cfg->swap_tx)			   
					*p_buf_32 = ntohl(*p_buf_32);
				p_buf_32++;
				break;

			case ASYNC_ETH_DATA_TYPE_FLOAT:
			   *p_buf_f32 = (float)p_cfg->p_buf_from_model[tx_data_cnt];
			    if(p_cfg->swap_tx)
					swap32((void*)p_buf_f32);			   
			    p_buf_f32++;
				break;

			case ASYNC_ETH_DATA_TYPE_DOUBLE:
			   *p_buf_64 = (double)p_cfg->p_buf_from_model[tx_data_cnt];
			    if(p_cfg->swap_tx)
					swap64((void*)p_buf_64);
			    p_buf_64++;
				break;

			default:
				break;
		}
	}


	/* Send the buffer. */
	if (p_cfg->protocol == ASYNC_ETH_PARAM_PROTOCOL_TCP)
	{
		tx_len = send(p_cfg->sock_id_data, (char *)p_cfg->p_buf_tx, p_cfg->nbr_byte_to_remote_endpoint,0);
	} else {
	    tx_len = sendto(p_cfg->sock_id, (char *)p_cfg->p_buf_tx, p_cfg->nbr_byte_to_remote_endpoint, 0, (struct sockaddr *)&p_cfg->servaddr, sizeof(p_cfg->servaddr));
	}

	if (tx_len != p_cfg->nbr_byte_to_remote_endpoint) {
		/* Release transmission lock. */
		pthread_mutex_unlock(&p_cfg->tx_lock);
		p_cfg->tx_status = -2;
		return -1;
	}
	/* Flag the packet as sent. */
	p_cfg->tx_ready = 0;

	/* Set the transmission status as correct. */
	if (p_cfg->conn_status == 1)
		p_cfg->tx_status = 1;
	else
		p_cfg->tx_status = 0;

	/* Release transmission lock. */
	pthread_mutex_unlock(&p_cfg->tx_lock);

	return 0;
}

/* =================================================================================
 * Name:          close_shm()
 *
 * Description:   Close shared memory.
 *
 * Argument(s):   none.
 *
 * Return:        none.
 *
 * Caller(s):     main().
 *
 * Note(s):       none.
 * =================================================================================
 */
static void close_shm (char *argv[])
{
    /* Close the shared memories */
    OpalCloseAsyncMem (ASYNC_SHMEM_SIZE,ASYNC_SHMEM_NAME);
    OpalSystemCtrl_UnRegister(PRINT_SHMEM_NAME);
}


/* =================================================================================
 * Name:           OpalTrace()
 *
 * Description:    Wrapper to give the possibility to the application to disable
 *                 its own diagnostic messages using a macro configuration.
 *
 * Argument(s):    format   Pointer to string to display.
 *
 *                 ...      Arguments to convert into integers, strings, etc.
 *
 * Return:         none.
 *
 * Caller(s):      Various.
 *
 * Note(s):        none.
 * =================================================================================
 */
static  void  OpalTrace(const char *format, ...)
{
    va_list  arglist;
    char	 tmp_buf[512];


	va_start(arglist, format);
	vsprintf(tmp_buf, format, arglist);
	va_end(arglist);
	OpalPrint("%s", tmp_buf);
}


/* =================================================================================
 * Name:           AssignProcToCpu()
 *
 * Description:    Assign asynchronous process to a given CPU.
 *
 * Argument(s):    none
 *
 * Return:         0,     if successful,
 *                 errno, otherwise.
 *
 * Caller(s):      main().
 *
 * Note(s):        none.
 * =================================================================================
 */
static  int AssignProcToCpu(void)
{
#if defined(__linux__)
    int        cpu;
	char      *p_env_var;


	/* By default, assign process to CPU 0.*/
	cpu = 0;

 	if((p_env_var = getenv("OPAL_ASYNC_ETHERNET_ASSIGN_TO_CPU")) != NULL)
	{
		/* If environment variable value is valid, change the number of loops. */
		if((strcmp(p_env_var,  "-1") != 0) && \
		   (strcmp(p_env_var,  "")   != 0))
		{
		    cpu = atoi(p_env_var);
		}
	}

#	if defined(__redhawk__)
	int				rc;
	pid_t			pid = getpid();
	cpuset_t		*pCpuset;

	pCpuset = cpuset_alloc();
	if (NULL == pCpuset)
	{
		fprintf(stderr, "Error allocating a cpuset\n");
		return(ENOMEM);
	}
	cpuset_init(pCpuset);
	cpuset_set_cpu(pCpuset, cpu, 1);
	rc = mpadvise(MPA_PRC_SETBIAS, MPA_TID, pid, pCpuset);
	if (MPA_FAILURE == rc)
	{
		rc = errno;
		fprintf(stderr, "Error from mpadvise, %d %s, for pid %d\n", errno, strerror(errno), pid);
		cpuset_free(pCpuset);
		return(rc);
	}
	cpuset_free(pCpuset);
	return 0;
#	else
	cpu_set_t bindSet;

	CPU_ZERO(&bindSet);
	CPU_SET(cpu, &bindSet);

	/* Changing process cpu affinity. */
	if (sched_setaffinity( 0, sizeof(cpu_set_t), &bindSet ) != 0)
	{
		OpalPrint("Unable to bind the process to cpu #%d. sched_setaffinity() returned with errno %d\n", cpu, errno);
		return EINVAL;
	}
	return 0;
#	endif
#endif	// __linux__
}

/* =================================================================================
 * Name:          validate_interface()
 *
 * Description:   Validate the network interface
 *
 *                (1) Build the 'ifconfig | grep <nic_name>' string in the command
 *                    buffer.
 *
 *                (2) Launch the command from the command buffer.
 *
 *                (3) Validate the result.
 *
 * Argument(s):   p_arg    Pointer to the configuration structure.
 *
 * Return:        none.
 *
 * Caller(s):     validate_config().
 *
 * Note(s):       none.
 * =================================================================================
 */
static int validate_interface(void *p_arg)
{
    FILE *fp;
	char  cmd_buf[80];
	char  reply_buf[1024];
	char  c;
	char *p_char;
	int   i;
	AsyncEthernetCfgStruct *p_cfg = (AsyncEthernetCfgStruct *) p_arg;


	strcpy(&cmd_buf[0], "ifconfig | grep ");
	strcat(cmd_buf, p_cfg->nic_name);

	fp = popen(cmd_buf, "r");
	if(fp)
	{
		i = 0;
		while((c = fgetc(fp)) != EOF) {
			   reply_buf[i] = c;
			i++;
			if (i >= sizeof(reply_buf) -1 )
				break;
		}
		reply_buf[i] = '\0';
		pclose(fp);
	}

	if(strtok(reply_buf, p_cfg->nic_name) == 0)
	{
		OpalTrace("%s[%d} -> Invalid network interface (%s)\n", PROGNAME, p_cfg->ctrl_id, p_cfg->nic_name);
		return -1;
	}

	return 0;
}

/************************************************************************/
/* Swap the endianness of a double variable. */
/************************************************************************/
int swap64(void *p_data)
{
	unsigned char  i = 0;
	unsigned char  ByteBuf;
	unsigned NbSegments;
	typedef union{
		unsigned char  Bytes[8];
		unsigned short Shorts[4];
		unsigned int   Ints[2];
	} DataStruct;	

	DataStruct * Data = (DataStruct *)p_data;

	if(p_data == NULL)
		return -1;

	NbSegments=8;
	for(i=0;i<(NbSegments/2);i++)
	{
		ByteBuf=Data->Bytes[i];
		Data->Bytes[i]=Data->Bytes[NbSegments-1-i];
		Data->Bytes[NbSegments-1-i]=ByteBuf;
	}
	return 0;	
}

/************************************************************************/
/* Swap the endianness of a float variable. */
/************************************************************************/
int swap32(void *p_data)
{
	unsigned char i = 0;
	unsigned char  ByteBuf;
	unsigned NbSegments;
	typedef union{
		unsigned char  Bytes[4];
		unsigned short Shorts[2];
		unsigned int   Ints[1];
	} DataStruct;	

	DataStruct * Data = (DataStruct *)p_data;

	if(p_data == NULL)
		return -1;

	NbSegments=4;
	for(i=0;i<(NbSegments/2);i++)
	{
		ByteBuf=Data->Bytes[i];
		Data->Bytes[i]=Data->Bytes[NbSegments-1-i];
		Data->Bytes[NbSegments-1-i]=ByteBuf;
	}
	return 0;		
}


#endif
