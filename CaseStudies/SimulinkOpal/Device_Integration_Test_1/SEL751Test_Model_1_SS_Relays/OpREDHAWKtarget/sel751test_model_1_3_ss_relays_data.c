/*
 * sel751test_model_1_3_ss_relays_data.c
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
#include "sel751test_model_1_3_ss_relays.h"
#include "sel751test_model_1_3_ss_relays_private.h"

/* Block parameters (auto storage) */
P_sel751test_model_1_3_ss_relays_T sel751test_model_1_3_ss_relays_P = {
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S28>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S28>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S35>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S35>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S49>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S49>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S51>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S51>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S53>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S53>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S63>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S63>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S76>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S78>/Gain1'
                                        */
  1.0,                                 /* Expression: [1]
                                        * Referenced by: '<S68>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S72>/Gain1'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval
                                        * Referenced by: '<S74>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S74>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S74>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S74>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S74>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S76>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S74>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S74>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S74>/Step'
                                        */
  1.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S74>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S74>/Switch'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_m
                                        * Referenced by: '<S75>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S75>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S75>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S75>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S75>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S78>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S75>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S75>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S75>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S75>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S75>/Switch'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S72>/Rad->Deg.'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S68>/Saturation'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S68>/Saturation'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S81>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S92>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S94>/Gain1'
                                        */
  1.0,                                 /* Expression: [1]
                                        * Referenced by: '<S84>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S88>/Gain1'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_h
                                        * Referenced by: '<S90>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S90>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S90>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S90>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S90>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S92>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S90>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S90>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S90>/Step'
                                        */
  1.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S90>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S90>/Switch'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_n
                                        * Referenced by: '<S91>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S91>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S91>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S91>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S91>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S94>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S91>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S91>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S91>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S91>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S91>/Switch'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S88>/Rad->Deg.'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S84>/Saturation'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S84>/Saturation'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S97>/Gain1'
                                        */

  /*  Expression: [relay_settings(9:15)]
   * Referenced by: '<S20>/group#1 - gridtied parameters'
   */
  { 20.0, 0.0, 0.8, 1.0, 1.0, 0.9, 1.1 },

  /*  Expression: [relay_settings(16:22)]
   * Referenced by: '<S20>/group#2 - islanded parameters'
   */
  { 20.0, 1.0, 0.7, 2.0, 3.0, 0.9, 1.1 },
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S119>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S119>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S126>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S126>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S140>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S140>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S142>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S142>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S144>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S144>/Gain1'
                                        */
  0.0003333333333333523,               /* Expression: K1
                                        * Referenced by: '<S154>/Gain'
                                        */
  -0.0016666666666667045,              /* Expression: K2
                                        * Referenced by: '<S154>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S167>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S169>/Gain1'
                                        */
  1.0,                                 /* Expression: [1]
                                        * Referenced by: '<S159>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S163>/Gain1'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_c
                                        * Referenced by: '<S165>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S165>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S165>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S165>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S165>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S167>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S165>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S165>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S165>/Step'
                                        */
  1.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S165>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S165>/Switch'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_a
                                        * Referenced by: '<S166>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S166>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S166>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S166>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S166>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S169>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S166>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S166>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S166>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S166>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S166>/Switch'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S163>/Rad->Deg.'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S159>/Saturation'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S159>/Saturation'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S172>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S183>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S185>/Gain1'
                                        */
  1.0,                                 /* Expression: [1]
                                        * Referenced by: '<S175>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S179>/Gain1'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_f
                                        * Referenced by: '<S181>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S181>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S181>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S181>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S181>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S183>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S181>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S181>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S181>/Step'
                                        */
  1.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S181>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S181>/Switch'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_i
                                        * Referenced by: '<S182>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S182>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S182>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S182>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S182>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S185>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S182>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S182>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S182>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S182>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S182>/Switch'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S179>/Rad->Deg.'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S175>/Saturation'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S175>/Saturation'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S188>/Gain1'
                                        */

  /*  Expression: [relay_settings(9:15)]
   * Referenced by: '<S111>/group#1 - gridtied parameters'
   */
  { 20.0, 0.0, 0.8, 1.0, 1.0, 0.9, 1.1 },

  /*  Expression: [relay_settings(16:22)]
   * Referenced by: '<S111>/group#2 - islanded parameters'
   */
  { 20.0, 1.0, 0.7, 2.0, 3.0, 0.9, 1.1 },

  /*  Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S198>/S-Function'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: dest
                                        * Referenced by: '<S198>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S198>/S-Function'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: priority2
                                        * Referenced by: '<S198>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P3_Size
   * Referenced by: '<S198>/S-Function'
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: st
                                        * Referenced by: '<S198>/S-Function'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/S-Function1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/S-Function'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */

  /*  Computed Parameter: SFunction_P1_Size_g
   * Referenced by: '<S197>/S-Function'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: Acqu_group
                                        * Referenced by: '<S197>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P1_Size_p
   * Referenced by: '<S199>/S-Function'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: src
                                        * Referenced by: '<S199>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P2_Size_c
   * Referenced by: '<S199>/S-Function'
   */
  { 1.0, 1.0 },
  23.0,                                /* Expression: Data_width
                                        * Referenced by: '<S199>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P3_Size_g
   * Referenced by: '<S199>/S-Function'
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: st
                                        * Referenced by: '<S199>/S-Function'
                                        */

  /*  Expression: [relay_settings(1:8)]
   * Referenced by: '<S20>/base parameters'
   */
  { 1.0, 13800.0, 5.0, 12.0, 0.5, 0.5, 400.0, 1.0 },
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S10>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S10>/Discrete-Time Integrator'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S10>/Constant4'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S29>/K1'
                                        */
  0.8660254037844386,                  /* Expression: sqrt(3)/2
                                        * Referenced by: '<S29>/K2'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_g
                                        * Referenced by: '<S28>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S28>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S28>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S28>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S28>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S28>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S28>/Switch'
                                        */
  180.0,                               /* Expression: Kp
                                        * Referenced by: '<S26>/Kp4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                                        * Referenced by: '<S26>/Discrete-Time Integrator'
                                        */
  376.99111843077515,                  /* Expression: Init
                                        * Referenced by: '<S26>/Discrete-Time Integrator'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S26>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S26>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: Kd
                                        * Referenced by: '<S26>/Kp6'
                                        */
  10000.0,                             /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S30>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S30>/UD'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S26>/Saturation2'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S26>/Saturation2'
                                        */
  0.15915494309189535,                 /* Expression: 1/2/pi
                                        * Referenced by: '<S10>/Gain10'
                                        */
  60.0,                                /* Expression: Vinit
                                        * Referenced by: '<S27>/Unit  Delay'
                                        */
  0.0012000000000000001,               /* Expression: UpperLimit
                                        * Referenced by: '<S27>/Saturation'
                                        */
  -0.0012000000000000001,              /* Expression: LowerLimit
                                        * Referenced by: '<S27>/Saturation'
                                        */

  /*  Computed Parameter: DiscreteStateSpace_A
   * Referenced by: '<S25>/Discrete State-Space'
   */
  { 0.977912228775521, -2.4401514047614183, 9.8895611438776042E-5,
    0.99987799242976183 },

  /*  Computed Parameter: DiscreteStateSpace_B
   * Referenced by: '<S25>/Discrete State-Space'
   */
  { 0.98895611438776054, 4.9447805719388021E-5 },

  /*  Computed Parameter: DiscreteStateSpace_C
   * Referenced by: '<S25>/Discrete State-Space'
   */
  { 0.0001220075702380709, 2.4672505794658162 },
  6.100378511903545E-5,                /* Computed Parameter: DiscreteStateSpace_D
                                        * Referenced by: '<S25>/Discrete State-Space'
                                        */

  /*  Expression: x0d
   * Referenced by: '<S25>/Discrete State-Space'
   */
  { 0.0, 24.317084074161063 },
  3200.0,                              /* Expression: Ki
                                        * Referenced by: '<S26>/Kp5'
                                        */
  60.0,                                /* Expression: Finit
                                        * Referenced by: '<S10>/Unit Delay'
                                        */
  0.33333333333333331,                 /* Expression: 1/3
                                        * Referenced by: '<S29>/Gain1'
                                        */
  1.414,                               /* Expression: 1.414
                                        * Referenced by: '<S5>/Gain21'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S11>/Constant4'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S36>/K1'
                                        */
  0.8660254037844386,                  /* Expression: sqrt(3)/2
                                        * Referenced by: '<S36>/K2'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_nf
                                        * Referenced by: '<S35>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S35>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S35>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S35>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S35>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S35>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S35>/Switch'
                                        */
  180.0,                               /* Expression: Kp
                                        * Referenced by: '<S33>/Kp4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                                        * Referenced by: '<S33>/Discrete-Time Integrator'
                                        */
  376.99111843077515,                  /* Expression: Init
                                        * Referenced by: '<S33>/Discrete-Time Integrator'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S33>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S33>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: Kd
                                        * Referenced by: '<S33>/Kp6'
                                        */
  10000.0,                             /* Computed Parameter: TSamp_WtEt_n
                                        * Referenced by: '<S37>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S37>/UD'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S33>/Saturation2'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S33>/Saturation2'
                                        */
  0.15915494309189535,                 /* Expression: 1/2/pi
                                        * Referenced by: '<S11>/Gain10'
                                        */
  60.0,                                /* Expression: Vinit
                                        * Referenced by: '<S34>/Unit  Delay'
                                        */
  0.0012000000000000001,               /* Expression: UpperLimit
                                        * Referenced by: '<S34>/Saturation'
                                        */
  -0.0012000000000000001,              /* Expression: LowerLimit
                                        * Referenced by: '<S34>/Saturation'
                                        */

  /*  Computed Parameter: DiscreteStateSpace_A_o
   * Referenced by: '<S32>/Discrete State-Space'
   */
  { 0.977912228775521, -2.4401514047614183, 9.8895611438776042E-5,
    0.99987799242976183 },

  /*  Computed Parameter: DiscreteStateSpace_B_o
   * Referenced by: '<S32>/Discrete State-Space'
   */
  { 0.98895611438776054, 4.9447805719388021E-5 },

  /*  Computed Parameter: DiscreteStateSpace_C_b
   * Referenced by: '<S32>/Discrete State-Space'
   */
  { 0.0001220075702380709, 2.4672505794658162 },
  6.100378511903545E-5,                /* Computed Parameter: DiscreteStateSpace_D_h
                                        * Referenced by: '<S32>/Discrete State-Space'
                                        */

  /*  Expression: x0d
   * Referenced by: '<S32>/Discrete State-Space'
   */
  { 0.0, 24.317084074161063 },
  3200.0,                              /* Expression: Ki
                                        * Referenced by: '<S33>/Kp5'
                                        */
  60.0,                                /* Expression: Finit
                                        * Referenced by: '<S11>/Unit Delay'
                                        */
  0.33333333333333331,                 /* Expression: 1/3
                                        * Referenced by: '<S36>/Gain1'
                                        */
  0.57735026918962584,                 /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S48>/pu->V'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_f3
                                        * Referenced by: '<S49>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S49>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S49>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S49>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S49>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S49>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S49>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S49>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S49>/Switch'
                                        */
  1.0,                                 /* Expression: const
                                        * Referenced by: '<S39>/Constant'
                                        */
  1.0,                                 /* Expression: const
                                        * Referenced by: '<S40>/Constant'
                                        */
  0.0,                                 /* Expression: const
                                        * Referenced by: '<S41>/Constant'
                                        */
  0.0,                                 /* Expression: const
                                        * Referenced by: '<S42>/Constant'
                                        */
  1.0,                                 /* Expression: vinit
                                        * Referenced by: '<S43>/FixPt Unit Delay1'
                                        */
  0.033333333333333333,                /* Expression: 2/60
                                        * Referenced by: '<S5>/Constant1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S5>/Constant2'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S5>/Constant4'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S23>/a4'
                                        */

  /*  Computed Parameter: SFunction_P1_Size_c
   * Referenced by: '<S192>/S-Function'
   */
  { 1.0, 1.0 },
  6.0,                                 /* Expression: Data_width
                                        * Referenced by: '<S192>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P2_Size_i
   * Referenced by: '<S192>/S-Function'
   */
  { 6.0, 1.0 },

  /*  Expression: InitialConditions
   * Referenced by: '<S192>/S-Function'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_cf
                                        * Referenced by: '<S51>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S51>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S51>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S51>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S51>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S51>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S51>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S51>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S51>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S51>/Switch'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_b
                                        * Referenced by: '<S53>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S53>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S53>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S53>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S53>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S53>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S53>/Switch'
                                        */
  0.5773588718407644,                  /* Expression: 1/1.732025
                                        * Referenced by: '<S23>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S20>/Switch'
                                        */
  0.57736720554272514,                 /* Expression: 1/1.732
                                        * Referenced by: '<S5>/Gain2'
                                        */
  8.0,                                 /* Expression: 2^3
                                        * Referenced by: '<S5>/Gain'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S5>/Gain1'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S5>/Gain10'
                                        */
  120.0,                               /* Expression: 120
                                        * Referenced by: '<S16>/Constant5'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S16>/Constant7'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S5>/Gain11'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S5>/Gain12'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S5>/Gain13'
                                        */
  16384.0,                             /* Expression: 2^14
                                        * Referenced by: '<S5>/Gain14'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain15'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain16'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain17'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain18'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain19'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain20'
                                        */
  120.0,                               /* Expression: 120
                                        * Referenced by: '<S15>/Constant6'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S15>/Constant8'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S5>/Gain3'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S5>/Gain4'
                                        */
  120.0,                               /* Expression: 120
                                        * Referenced by: '<S15>/Constant5'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S15>/Constant7'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S5>/Gain5'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S5>/Gain6'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S5>/Gain7'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S5>/Gain8'
                                        */
  120.0,                               /* Expression: 120
                                        * Referenced by: '<S16>/Constant6'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S16>/Constant8'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S5>/Gain9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/never_reset'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S46>/Delay Input1'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_me
                                        * Referenced by: '<S63>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S63>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S63>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S63>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S63>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S63>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S63>/Switch'
                                        */
  1.7321,                              /* Expression: 1.7321
                                        * Referenced by: '<S19>/sqrt3'
                                        */
  60.0,                                /* Expression: Finit
                                        * Referenced by: '<S66>/Unit Delay'
                                        */
  60.0,                                /* Expression: Finit
                                        * Referenced by: '<S65>/Unit Delay'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                        * Referenced by: '<S66>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S66>/Discrete-Time Integrator'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S66>/Constant4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                        * Referenced by: '<S65>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S65>/Discrete-Time Integrator'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S65>/Constant4'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S56>/Constant3'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S62>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory9'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_e
                                        * Referenced by: '<S71>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S71>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S71>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S71>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S71>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S81>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S71>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S71>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S71>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S71>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S71>/Switch'
                                        */
  1.0,                                 /* Expression: AGC
                                        * Referenced by: '<S65>/Constant1'
                                        */
  180.0,                               /* Expression: Kp
                                        * Referenced by: '<S69>/Kp4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                        * Referenced by: '<S69>/Discrete-Time Integrator'
                                        */
  376.99111843077515,                  /* Expression: Init
                                        * Referenced by: '<S69>/Discrete-Time Integrator'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S69>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S69>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: Kd
                                        * Referenced by: '<S69>/Kp6'
                                        */
  10000.0,                             /* Computed Parameter: TSamp_WtEt_n0
                                        * Referenced by: '<S80>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S80>/UD'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S69>/Saturation2'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S69>/Saturation2'
                                        */
  0.15915494309189535,                 /* Expression: 1/2/pi
                                        * Referenced by: '<S65>/Gain10'
                                        */
  60.0,                                /* Expression: Vinit
                                        * Referenced by: '<S70>/Unit  Delay'
                                        */
  0.0012000000000000001,               /* Expression: UpperLimit
                                        * Referenced by: '<S70>/Saturation'
                                        */
  -0.0012000000000000001,              /* Expression: LowerLimit
                                        * Referenced by: '<S70>/Saturation'
                                        */

  /*  Computed Parameter: DiscreteStateSpace_A_g
   * Referenced by: '<S67>/Discrete State-Space'
   */
  { 0.977912228775521, -2.4401514047614183, 9.8895611438776042E-5,
    0.99987799242976183 },

  /*  Computed Parameter: DiscreteStateSpace_B_a
   * Referenced by: '<S67>/Discrete State-Space'
   */
  { 0.98895611438776054, 4.9447805719388021E-5 },

  /*  Computed Parameter: DiscreteStateSpace_C_l
   * Referenced by: '<S67>/Discrete State-Space'
   */
  { 0.0001220075702380709, 2.4672505794658162 },
  6.100378511903545E-5,                /* Computed Parameter: DiscreteStateSpace_D_l
                                        * Referenced by: '<S67>/Discrete State-Space'
                                        */

  /*  Expression: x0d
   * Referenced by: '<S67>/Discrete State-Space'
   */
  { 0.0, 24.317084074161063 },
  3200.0,                              /* Expression: Ki
                                        * Referenced by: '<S69>/Kp5'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_hr
                                        * Referenced by: '<S87>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S87>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S87>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S87>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S87>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S97>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S87>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S87>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S87>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S87>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S87>/Switch'
                                        */
  1.0,                                 /* Expression: AGC
                                        * Referenced by: '<S66>/Constant1'
                                        */
  180.0,                               /* Expression: Kp
                                        * Referenced by: '<S85>/Kp4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainv_f4
                                        * Referenced by: '<S85>/Discrete-Time Integrator'
                                        */
  376.99111843077515,                  /* Expression: Init
                                        * Referenced by: '<S85>/Discrete-Time Integrator'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S85>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S85>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: Kd
                                        * Referenced by: '<S85>/Kp6'
                                        */
  10000.0,                             /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S96>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S96>/UD'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S85>/Saturation2'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S85>/Saturation2'
                                        */
  0.15915494309189535,                 /* Expression: 1/2/pi
                                        * Referenced by: '<S66>/Gain10'
                                        */
  60.0,                                /* Expression: Vinit
                                        * Referenced by: '<S86>/Unit  Delay'
                                        */
  0.0012000000000000001,               /* Expression: UpperLimit
                                        * Referenced by: '<S86>/Saturation'
                                        */
  -0.0012000000000000001,              /* Expression: LowerLimit
                                        * Referenced by: '<S86>/Saturation'
                                        */

  /*  Computed Parameter: DiscreteStateSpace_A_h
   * Referenced by: '<S83>/Discrete State-Space'
   */
  { 0.977912228775521, -2.4401514047614183, 9.8895611438776042E-5,
    0.99987799242976183 },

  /*  Computed Parameter: DiscreteStateSpace_B_ow
   * Referenced by: '<S83>/Discrete State-Space'
   */
  { 0.98895611438776054, 4.9447805719388021E-5 },

  /*  Computed Parameter: DiscreteStateSpace_C_bf
   * Referenced by: '<S83>/Discrete State-Space'
   */
  { 0.0001220075702380709, 2.4672505794658162 },
  6.100378511903545E-5,                /* Computed Parameter: DiscreteStateSpace_D_d
                                        * Referenced by: '<S83>/Discrete State-Space'
                                        */

  /*  Expression: x0d
   * Referenced by: '<S83>/Discrete State-Space'
   */
  { 0.0, 24.317084074161063 },
  3200.0,                              /* Expression: Ki
                                        * Referenced by: '<S85>/Kp5'
                                        */

  /*  Expression: [relay_settings(1:8)]
   * Referenced by: '<S111>/base parameters'
   */
  { 2.0, 13800.0, 3.0, 8.0, 0.3, 0.5, 250.0, 1.0 },
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                        * Referenced by: '<S101>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S101>/Discrete-Time Integrator'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S101>/Constant4'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S120>/K1'
                                        */
  0.8660254037844386,                  /* Expression: sqrt(3)/2
                                        * Referenced by: '<S120>/K2'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_k
                                        * Referenced by: '<S119>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S119>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S119>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S119>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S119>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S119>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S119>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S119>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S119>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S119>/Switch'
                                        */
  180.0,                               /* Expression: Kp
                                        * Referenced by: '<S117>/Kp4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                        * Referenced by: '<S117>/Discrete-Time Integrator'
                                        */
  376.99111843077515,                  /* Expression: Init
                                        * Referenced by: '<S117>/Discrete-Time Integrator'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S117>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S117>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: Kd
                                        * Referenced by: '<S117>/Kp6'
                                        */
  10000.0,                             /* Computed Parameter: TSamp_WtEt_g
                                        * Referenced by: '<S121>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S121>/UD'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S117>/Saturation2'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S117>/Saturation2'
                                        */
  0.15915494309189535,                 /* Expression: 1/2/pi
                                        * Referenced by: '<S101>/Gain10'
                                        */
  60.0,                                /* Expression: Vinit
                                        * Referenced by: '<S118>/Unit  Delay'
                                        */
  0.0012000000000000001,               /* Expression: UpperLimit
                                        * Referenced by: '<S118>/Saturation'
                                        */
  -0.0012000000000000001,              /* Expression: LowerLimit
                                        * Referenced by: '<S118>/Saturation'
                                        */

  /*  Computed Parameter: DiscreteStateSpace_A_m
   * Referenced by: '<S116>/Discrete State-Space'
   */
  { 0.977912228775521, -2.4401514047614183, 9.8895611438776042E-5,
    0.99987799242976183 },

  /*  Computed Parameter: DiscreteStateSpace_B_j
   * Referenced by: '<S116>/Discrete State-Space'
   */
  { 0.98895611438776054, 4.9447805719388021E-5 },

  /*  Computed Parameter: DiscreteStateSpace_C_c
   * Referenced by: '<S116>/Discrete State-Space'
   */
  { 0.0001220075702380709, 2.4672505794658162 },
  6.100378511903545E-5,                /* Computed Parameter: DiscreteStateSpace_D_dp
                                        * Referenced by: '<S116>/Discrete State-Space'
                                        */

  /*  Expression: x0d
   * Referenced by: '<S116>/Discrete State-Space'
   */
  { 0.0, 24.317084074161063 },
  3200.0,                              /* Expression: Ki
                                        * Referenced by: '<S117>/Kp5'
                                        */
  60.0,                                /* Expression: Finit
                                        * Referenced by: '<S101>/Unit Delay'
                                        */
  0.33333333333333331,                 /* Expression: 1/3
                                        * Referenced by: '<S120>/Gain1'
                                        */
  1.414,                               /* Expression: 1.414
                                        * Referenced by: '<S6>/Gain21'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                                        * Referenced by: '<S102>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S102>/Discrete-Time Integrator'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S102>/Constant4'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S127>/K1'
                                        */
  0.8660254037844386,                  /* Expression: sqrt(3)/2
                                        * Referenced by: '<S127>/K2'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_g3
                                        * Referenced by: '<S126>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S126>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S126>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S126>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S126>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S126>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S126>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S126>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S126>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S126>/Switch'
                                        */
  180.0,                               /* Expression: Kp
                                        * Referenced by: '<S124>/Kp4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                        * Referenced by: '<S124>/Discrete-Time Integrator'
                                        */
  376.99111843077515,                  /* Expression: Init
                                        * Referenced by: '<S124>/Discrete-Time Integrator'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S124>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S124>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: Kd
                                        * Referenced by: '<S124>/Kp6'
                                        */
  10000.0,                             /* Computed Parameter: TSamp_WtEt_l
                                        * Referenced by: '<S128>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S128>/UD'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S124>/Saturation2'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S124>/Saturation2'
                                        */
  0.15915494309189535,                 /* Expression: 1/2/pi
                                        * Referenced by: '<S102>/Gain10'
                                        */
  60.0,                                /* Expression: Vinit
                                        * Referenced by: '<S125>/Unit  Delay'
                                        */
  0.0012000000000000001,               /* Expression: UpperLimit
                                        * Referenced by: '<S125>/Saturation'
                                        */
  -0.0012000000000000001,              /* Expression: LowerLimit
                                        * Referenced by: '<S125>/Saturation'
                                        */

  /*  Computed Parameter: DiscreteStateSpace_A_hs
   * Referenced by: '<S123>/Discrete State-Space'
   */
  { 0.977912228775521, -2.4401514047614183, 9.8895611438776042E-5,
    0.99987799242976183 },

  /*  Computed Parameter: DiscreteStateSpace_B_f
   * Referenced by: '<S123>/Discrete State-Space'
   */
  { 0.98895611438776054, 4.9447805719388021E-5 },

  /*  Computed Parameter: DiscreteStateSpace_C_o
   * Referenced by: '<S123>/Discrete State-Space'
   */
  { 0.0001220075702380709, 2.4672505794658162 },
  6.100378511903545E-5,                /* Computed Parameter: DiscreteStateSpace_D_i
                                        * Referenced by: '<S123>/Discrete State-Space'
                                        */

  /*  Expression: x0d
   * Referenced by: '<S123>/Discrete State-Space'
   */
  { 0.0, 24.317084074161063 },
  3200.0,                              /* Expression: Ki
                                        * Referenced by: '<S124>/Kp5'
                                        */
  60.0,                                /* Expression: Finit
                                        * Referenced by: '<S102>/Unit Delay'
                                        */
  0.33333333333333331,                 /* Expression: 1/3
                                        * Referenced by: '<S127>/Gain1'
                                        */
  0.57735026918962584,                 /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S139>/pu->V'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_mc
                                        * Referenced by: '<S140>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S140>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S140>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S140>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S140>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S140>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S140>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S140>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S140>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S140>/Switch'
                                        */
  1.0,                                 /* Expression: const
                                        * Referenced by: '<S130>/Constant'
                                        */
  1.0,                                 /* Expression: const
                                        * Referenced by: '<S131>/Constant'
                                        */
  0.0,                                 /* Expression: const
                                        * Referenced by: '<S132>/Constant'
                                        */
  0.0,                                 /* Expression: const
                                        * Referenced by: '<S133>/Constant'
                                        */
  1.0,                                 /* Expression: vinit
                                        * Referenced by: '<S134>/FixPt Unit Delay1'
                                        */
  0.033333333333333333,                /* Expression: 2/60
                                        * Referenced by: '<S6>/Constant1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S6>/Constant2'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S6>/Constant4'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S114>/a4'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_nk
                                        * Referenced by: '<S142>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S142>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S142>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S142>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S142>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S142>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S142>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S142>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S142>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S142>/Switch'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_nj
                                        * Referenced by: '<S144>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S144>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S144>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S144>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S144>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S144>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S144>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S144>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S144>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S144>/Switch'
                                        */
  0.5773588718407644,                  /* Expression: 1/1.732025
                                        * Referenced by: '<S114>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S111>/Switch'
                                        */
  0.57736720554272514,                 /* Expression: 1/1.732
                                        * Referenced by: '<S6>/Gain2'
                                        */
  8.0,                                 /* Expression: 2^3
                                        * Referenced by: '<S6>/Gain'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S6>/Gain1'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S6>/Gain10'
                                        */
  120.0,                               /* Expression: 120
                                        * Referenced by: '<S107>/Constant5'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S107>/Constant7'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S6>/Gain11'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S6>/Gain12'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S6>/Gain13'
                                        */
  16384.0,                             /* Expression: 2^14
                                        * Referenced by: '<S6>/Gain14'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain15'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain16'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain17'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain18'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain19'
                                        */
  1.4142,                              /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain20'
                                        */
  120.0,                               /* Expression: 120
                                        * Referenced by: '<S106>/Constant6'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S106>/Constant8'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S6>/Gain3'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S6>/Gain4'
                                        */
  120.0,                               /* Expression: 120
                                        * Referenced by: '<S106>/Constant5'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S106>/Constant7'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S6>/Gain5'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S6>/Gain6'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S6>/Gain7'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S6>/Gain8'
                                        */
  120.0,                               /* Expression: 120
                                        * Referenced by: '<S107>/Constant6'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S107>/Constant8'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S6>/Gain9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S104>/never_reset'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S137>/Delay Input1'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_an
                                        * Referenced by: '<S154>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S154>/Integ4'
                                        */
  0.0167,                              /* Expression: Delay
                                        * Referenced by: '<S154>/K1'
                                        */
  60.0,                                /* Expression: Freq
                                        * Referenced by: '<S154>/K2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S154>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Freq
                                        * Referenced by: '<S154>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S154>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S154>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S154>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S154>/Switch'
                                        */
  1.7321,                              /* Expression: 1.7321
                                        * Referenced by: '<S110>/sqrt3'
                                        */
  60.0,                                /* Expression: Finit
                                        * Referenced by: '<S157>/Unit Delay'
                                        */
  60.0,                                /* Expression: Finit
                                        * Referenced by: '<S156>/Unit Delay'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainv_kv
                                        * Referenced by: '<S157>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S157>/Discrete-Time Integrator'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S157>/Constant4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                        * Referenced by: '<S156>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S156>/Discrete-Time Integrator'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S156>/Constant4'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S147>/Constant3'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S153>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory9'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_p
                                        * Referenced by: '<S162>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S162>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S162>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S162>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S162>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S172>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S162>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S162>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S162>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S162>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S162>/Switch'
                                        */
  1.0,                                 /* Expression: AGC
                                        * Referenced by: '<S156>/Constant1'
                                        */
  180.0,                               /* Expression: Kp
                                        * Referenced by: '<S160>/Kp4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainva_h
                                        * Referenced by: '<S160>/Discrete-Time Integrator'
                                        */
  376.99111843077515,                  /* Expression: Init
                                        * Referenced by: '<S160>/Discrete-Time Integrator'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S160>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S160>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: Kd
                                        * Referenced by: '<S160>/Kp6'
                                        */
  10000.0,                             /* Computed Parameter: TSamp_WtEt_f
                                        * Referenced by: '<S171>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S171>/UD'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S160>/Saturation2'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S160>/Saturation2'
                                        */
  0.15915494309189535,                 /* Expression: 1/2/pi
                                        * Referenced by: '<S156>/Gain10'
                                        */
  60.0,                                /* Expression: Vinit
                                        * Referenced by: '<S161>/Unit  Delay'
                                        */
  0.0012000000000000001,               /* Expression: UpperLimit
                                        * Referenced by: '<S161>/Saturation'
                                        */
  -0.0012000000000000001,              /* Expression: LowerLimit
                                        * Referenced by: '<S161>/Saturation'
                                        */

  /*  Computed Parameter: DiscreteStateSpace_A_b
   * Referenced by: '<S158>/Discrete State-Space'
   */
  { 0.977912228775521, -2.4401514047614183, 9.8895611438776042E-5,
    0.99987799242976183 },

  /*  Computed Parameter: DiscreteStateSpace_B_m
   * Referenced by: '<S158>/Discrete State-Space'
   */
  { 0.98895611438776054, 4.9447805719388021E-5 },

  /*  Computed Parameter: DiscreteStateSpace_C_f
   * Referenced by: '<S158>/Discrete State-Space'
   */
  { 0.0001220075702380709, 2.4672505794658162 },
  6.100378511903545E-5,                /* Computed Parameter: DiscreteStateSpace_D_hy
                                        * Referenced by: '<S158>/Discrete State-Space'
                                        */

  /*  Expression: x0d
   * Referenced by: '<S158>/Discrete State-Space'
   */
  { 0.0, 24.317084074161063 },
  3200.0,                              /* Expression: Ki
                                        * Referenced by: '<S160>/Kp5'
                                        */
  5.0E-5,                              /* Computed Parameter: Integ4_gainval_eg
                                        * Referenced by: '<S178>/Integ4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S178>/Integ4'
                                        */
  1.0E+6,                              /* Expression: 1e6
                                        * Referenced by: '<S178>/To avoid division by zero'
                                        */
  1.0E-6,                              /* Expression: 1e-6
                                        * Referenced by: '<S178>/To avoid division by zero'
                                        */
  0.0001,                              /* Expression: Ts
                                        * Referenced by: '<S178>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S188>/Unit Delay'
                                        */
  0.016666666666666666,                /* Expression: 1/Finit
                                        * Referenced by: '<S178>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S178>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S178>/Step'
                                        */
  0.0,                                 /* Expression: Vinit
                                        * Referenced by: '<S178>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S178>/Switch'
                                        */
  1.0,                                 /* Expression: AGC
                                        * Referenced by: '<S157>/Constant1'
                                        */
  180.0,                               /* Expression: Kp
                                        * Referenced by: '<S176>/Kp4'
                                        */
  0.0001,                              /* Computed Parameter: DiscreteTimeIntegrator_gainv_kk
                                        * Referenced by: '<S176>/Discrete-Time Integrator'
                                        */
  376.99111843077515,                  /* Expression: Init
                                        * Referenced by: '<S176>/Discrete-Time Integrator'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S176>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S176>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: Kd
                                        * Referenced by: '<S176>/Kp6'
                                        */
  10000.0,                             /* Computed Parameter: TSamp_WtEt_j
                                        * Referenced by: '<S187>/TSamp'
                                        */
  0.0,                                 /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S187>/UD'
                                        */
  10000.0,                             /* Expression: UpperLimit
                                        * Referenced by: '<S176>/Saturation2'
                                        */
  0.0,                                 /* Expression: LowerLimit
                                        * Referenced by: '<S176>/Saturation2'
                                        */
  0.15915494309189535,                 /* Expression: 1/2/pi
                                        * Referenced by: '<S157>/Gain10'
                                        */
  60.0,                                /* Expression: Vinit
                                        * Referenced by: '<S177>/Unit  Delay'
                                        */
  0.0012000000000000001,               /* Expression: UpperLimit
                                        * Referenced by: '<S177>/Saturation'
                                        */
  -0.0012000000000000001,              /* Expression: LowerLimit
                                        * Referenced by: '<S177>/Saturation'
                                        */

  /*  Computed Parameter: DiscreteStateSpace_A_hy
   * Referenced by: '<S174>/Discrete State-Space'
   */
  { 0.977912228775521, -2.4401514047614183, 9.8895611438776042E-5,
    0.99987799242976183 },

  /*  Computed Parameter: DiscreteStateSpace_B_l
   * Referenced by: '<S174>/Discrete State-Space'
   */
  { 0.98895611438776054, 4.9447805719388021E-5 },

  /*  Computed Parameter: DiscreteStateSpace_C_d
   * Referenced by: '<S174>/Discrete State-Space'
   */
  { 0.0001220075702380709, 2.4672505794658162 },
  6.100378511903545E-5,                /* Computed Parameter: DiscreteStateSpace_D_l2
                                        * Referenced by: '<S174>/Discrete State-Space'
                                        */

  /*  Expression: x0d
   * Referenced by: '<S174>/Discrete State-Space'
   */
  { 0.0, 24.317084074161063 },
  3200.0,                              /* Expression: Ki
                                        * Referenced by: '<S176>/Kp5'
                                        */
  1,                                   /* Computed Parameter: ShiftArithmetic_Power2Exponent
                                        * Referenced by: '<S21>/Shift Arithmetic'
                                        */
  2,                                   /* Computed Parameter: ShiftArithmetic1_Power2Exponent
                                        * Referenced by: '<S21>/Shift Arithmetic1'
                                        */
  3,                                   /* Computed Parameter: ShiftArithmetic2_Power2Exponent
                                        * Referenced by: '<S21>/Shift Arithmetic2'
                                        */
  4,                                   /* Computed Parameter: ShiftArithmetic3_Power2Exponent
                                        * Referenced by: '<S21>/Shift Arithmetic3'
                                        */
  5,                                   /* Computed Parameter: ShiftArithmetic4_Power2Exponent
                                        * Referenced by: '<S21>/Shift Arithmetic4'
                                        */
  6,                                   /* Computed Parameter: ShiftArithmetic5_Power2Exponent
                                        * Referenced by: '<S21>/Shift Arithmetic5'
                                        */
  1,                                   /* Computed Parameter: ShiftArithmetic_Power2Exponen_k
                                        * Referenced by: '<S22>/Shift Arithmetic'
                                        */
  1,                                   /* Computed Parameter: ShiftArithmetic_Power2Exponen_i
                                        * Referenced by: '<S112>/Shift Arithmetic'
                                        */
  2,                                   /* Computed Parameter: ShiftArithmetic1_Power2Expone_c
                                        * Referenced by: '<S112>/Shift Arithmetic1'
                                        */
  3,                                   /* Computed Parameter: ShiftArithmetic2_Power2Expone_g
                                        * Referenced by: '<S112>/Shift Arithmetic2'
                                        */
  4,                                   /* Computed Parameter: ShiftArithmetic3_Power2Expone_e
                                        * Referenced by: '<S112>/Shift Arithmetic3'
                                        */
  5,                                   /* Computed Parameter: ShiftArithmetic4_Power2Expone_n
                                        * Referenced by: '<S112>/Shift Arithmetic4'
                                        */
  6,                                   /* Computed Parameter: ShiftArithmetic5_Power2Expone_l
                                        * Referenced by: '<S112>/Shift Arithmetic5'
                                        */
  1,                                   /* Computed Parameter: ShiftArithmetic_Power2Exponen_m
                                        * Referenced by: '<S113>/Shift Arithmetic'
                                        */
  1,                                   /* Computed Parameter: FixPtUnitDelay1_InitialCondit_a
                                        * Referenced by: '<S44>/FixPt Unit Delay1'
                                        */
  1,                                   /* Computed Parameter: FixPtUnitDelay1_InitialCondit_g
                                        * Referenced by: '<S45>/FixPt Unit Delay1'
                                        */
  0,                                   /* Computed Parameter: DelayInput1_InitialCondition_i
                                        * Referenced by: '<S99>/Delay Input1'
                                        */
  0,                                   /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S47>/Memory'
                                        */

  /*  Computed Parameter: Logic_table
   * Referenced by: '<S47>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  0,                                   /* Computed Parameter: Memory_X0_p
                                        * Referenced by: '<S58>/Memory'
                                        */

  /*  Computed Parameter: Logic_table_n
   * Referenced by: '<S58>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  1,                                   /* Computed Parameter: FixPtUnitDelay1_InitialCondit_k
                                        * Referenced by: '<S135>/FixPt Unit Delay1'
                                        */
  1,                                   /* Computed Parameter: FixPtUnitDelay1_InitialCondit_e
                                        * Referenced by: '<S136>/FixPt Unit Delay1'
                                        */
  0,                                   /* Computed Parameter: DelayInput1_InitialCondition_l
                                        * Referenced by: '<S190>/Delay Input1'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_f
                                        * Referenced by: '<S138>/Memory'
                                        */

  /*  Computed Parameter: Logic_table_d
   * Referenced by: '<S138>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  0,                                   /* Computed Parameter: Memory_X0_l
                                        * Referenced by: '<S149>/Memory'
                                        */

  /*  Computed Parameter: Logic_table_f
   * Referenced by: '<S149>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 }
};

/* Constant parameters (auto storage) */
const ConstP_sel751test_model_1_3_ss_relays_T
  sel751test_model_1_3_ss_relays_ConstP = {
  /* Pooled Parameter (Expression: tol)
   * Referenced by:
   *   '<S56>/Unwrap'
   *   '<S147>/Unwrap'
   */
  3.1415926535897931
};
