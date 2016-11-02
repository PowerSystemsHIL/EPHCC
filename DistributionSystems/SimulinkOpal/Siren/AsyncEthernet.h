/*-------------------------------------------------------------------
 *  OPAL-RT Technologies inc
 *
 *  Copyright (C) 2015. All rights reserved.
 *
 *  File name =         AsyncSocket.h
 *  Last modified by =  Simon Labbé
 *
 *
 *-----------------------------------------------------------------*/

#ifndef OPAL_ASYNC_ETH_INTERFACE_H
#define OPAL_ASYNC_ETH_INTERFACE_H

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef RT
#define RT
#endif
#include "OpalPrint.h"
#include "AsyncApi.h"
#include "OpalGenAsyncParamCtrl.h"
#pragma pack()

#define  ASYNC_ETH_NBR_SEND_BLOCK                  1   
#define  ASYNC_ETH_NBR_RECV_BLOCK                  1   

#define  ASYNC_ETH_PARAM_IX_NBR_DATA_TO_SEND       0
#define  ASYNC_ETH_PARAM_IX_DATA_TYPE_TO_SEND      1
#define  ASYNC_ETH_PARAM_IX_NBR_DATA_TO_RECEIVE    2
#define  ASYNC_ETH_PARAM_IX_DATA_TYPE_TO_RECEIVE   3
#define  ASYNC_ETH_PARAM_IX_PROTOCOL               4
#define  ASYNC_ETH_PARAM_IX_TCP_MODE               5
#define  ASYNC_ETH_PARAM_IX_PORT                   6
#define  ASYNC_ETH_PARAM_BYTE_OFFSET_TX            7
#define  ASYNC_ETH_PARAM_BYTE_OFFSET_RX            8
#define  ASYNC_ETH_PARAM_SWAP_TX                   9
#define  ASYNC_ETH_PARAM_SWAP_RX                  10

#define  ASYNC_ETH_PARAM_IX_NIC_NAME               0
#define  ASYNC_ETH_PARAM_IX_REMOTE_IP              1

#define  ASYNC_ETH_PARAM_TCP_MODE_CLIENT           1
#define  ASYNC_ETH_PARAM_TCP_MODE_SERVER           2

#define  ASYNC_ETH_PARAM_PROTOCOL_UDP              1
#define  ASYNC_ETH_PARAM_PROTOCOL_TCP              2

#define  ASYNC_ETH_DATA_TYPE_UINT8                 1
#define  ASYNC_ETH_DATA_TYPE_INT8                  2
#define  ASYNC_ETH_DATA_TYPE_UINT16                3
#define  ASYNC_ETH_DATA_TYPE_INT16                 4
#define  ASYNC_ETH_DATA_TYPE_UINT32                5
#define  ASYNC_ETH_DATA_TYPE_INT32                 6
#define  ASYNC_ETH_DATA_TYPE_FLOAT                 7
#define  ASYNC_ETH_DATA_TYPE_DOUBLE                8


#endif
