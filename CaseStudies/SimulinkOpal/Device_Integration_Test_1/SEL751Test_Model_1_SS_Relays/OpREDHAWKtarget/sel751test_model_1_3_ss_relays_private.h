/*
 * sel751test_model_1_3_ss_relays_private.h
 *
 * Code generation for model "sel751test_model_1_3_ss_relays".
 *
 * Model version              : 1.2540
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Tue Aug 23 08:04:55 2016
 *
 * Target selection: rtlab_rtmodel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_sel751test_model_1_3_ss_relays_private_h_
#define RTW_HEADER_sel751test_model_1_3_ss_relays_private_h_
#include "rtwtypes.h"
#include <math.h>
#include <stdlib.h>
#define MAX_DELAY_BUFFER_SIZE          32768
#ifndef ssGetFixedStepSize
#define ssGetFixedStepSize(S)          (S).stepSize
#endif                                 /* ssGetFixedStepSize */

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void send_rt(SimStruct *rts);
extern void OP_SEND(SimStruct *rts);
extern void recv_rt(SimStruct *rts);
extern void RECV_Param(SimStruct *rts);
extern void sel751test_model_1_3_deadbusfcn(real_T rtu_Vbus, real_T rtu_Vline,
  real_T rtu_VRMSLL, B_deadbusfcn_sel751test_model_T *localB);
extern void sel751test_model_1__Relays_Init(DW_Relays_sel751test_model_1__T
  *localDW);
extern void sel751test_model_1_3_ss__Relays(boolean_T rtu_Enable_logic, real_T
  rtu_Ts, real_T rtu_Reset, const real_T rtu_Iinst[3], const real_T rtu_Irms[3],
  const real_T rtu_Vrms[3], real_T rtu_VRMSLN, real_T rtu_CT_p, real_T
  rtu_IOC_pickup, real_T rtu_IOC_tripDelay, real_T rtu_TOC_pickup, real_T
  rtu_curveType, real_T rtu_timeDial, real_T rtu_UV_pickup, real_T rtu_OV_pickup,
  real_T rtu_UVOV_tripDelay, B_Relays_sel751test_model_1_3_T *localB,
  DW_Relays_sel751test_model_1__T *localDW);
extern void sel751test_mod_trip_outmng_Init(DW_trip_outmng_sel751test_mod_T
  *localDW);
extern void sel751test_model_1__trip_outmng(real_T rtu_Ts, boolean_T
  rtu_bool_R25, real_T rtu_op_mode_in, real_T rtu_trip_in, real_T
  rtu_synch_check_time, real_T rtu_clock_time, real_T rtu_time_delay,
  B_trip_outmng_sel751test_mode_T *localB, DW_trip_outmng_sel751test_mod_T
  *localDW);

#endif                                 /* RTW_HEADER_sel751test_model_1_3_ss_relays_private_h_ */
