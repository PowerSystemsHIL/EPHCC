/*
 * sel751test_model_1_1_sm_system_private.h
 *
 * Code generation for model "sel751test_model_1_1_sm_system".
 *
 * Model version              : 1.2542
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Tue Aug 23 11:24:18 2016
 *
 * Target selection: rtlab_rtmodel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_sel751test_model_1_1_sm_system_private_h_
#define RTW_HEADER_sel751test_model_1_1_sm_system_private_h_
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
extern void rt_invd5x5_snf(const real_T u[25], real_T y[25]);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
  ;
extern void sfun_discreteVariableDelay(SimStruct *rts);
extern void send_rt(SimStruct *rts);
extern void sfun_op7160ex1_digital_in(SimStruct *rts);
extern void sfun_op7160ex1_event_detector(SimStruct *rts);
extern void sfun_op7160ex1_pwm_in(SimStruct *rts);
extern void sfun_op7160ex1_analog_in(SimStruct *rts);
extern void RECV_Param(SimStruct *rts);
extern void recv_rt(SimStruct *rts);
extern void ssn_sfun_v1(SimStruct *rts);
extern void OP_SEND(SimStruct *rts);
extern void sfun_op7160ex1_analog_out(SimStruct *rts);
extern void sfun_op7160ex1_digital_out(SimStruct *rts);
extern void OpModbus(SimStruct *rts);
extern void sfun_opfromfile(SimStruct *rts);
extern void rte_svpwm(SimStruct *rts);
extern void rte_conversion(SimStruct *rts);
extern void sfun_ctrl_op7160ex1(SimStruct *rts);
extern void sfun_op7160ex1_pwm_out(SimStruct *rts);
extern void sfun_op7160ex1_event_generator(SimStruct *rts);
extern void sfun_fct_op7160ex1_send(SimStruct *rts);
extern void sel751test_model_1_1_sm_s_delay(real_T rtu_u,
  B_delay_sel751test_model_1_1__T *localB);
extern void sel751test_mo_Subsystempi2delay(uint8_T rtu_0, const real_T
  rtu_alpha_beta[2], real_T rtu_alpha_beta_k, B_Subsystempi2delay_sel751tes_T
  *localB);
extern void sel751test_model_1_1_Subsystem1(uint8_T rtu_0, const real_T
  rtu_alpha_beta[2], real_T rtu_alpha_beta_f, B_Subsystem1_sel751test_model_T
  *localB);

/* private model entry point functions */
extern void sel751test_model_1_1_sm_system_derivatives(void);

#endif                                 /* RTW_HEADER_sel751test_model_1_1_sm_system_private_h_ */
