/*
 * sel751test_model_1_3_ss_relays.c
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

/* Block signals (auto storage) */
B_sel751test_model_1_3_ss_relays_T sel751test_model_1_3_ss_relays_B;

/* Block states (auto storage) */
DW_sel751test_model_1_3_ss_relays_T sel751test_model_1_3_ss_relays_DW;

/* Real-time model */
RT_MODEL_sel751test_model_1_3_ss_relays_T sel751test_model_1_3_ss_relays_M_;
RT_MODEL_sel751test_model_1_3_ss_relays_T *const
  sel751test_model_1_3_ss_relays_M = &sel751test_model_1_3_ss_relays_M_;

/*
 * Output and update for atomic system:
 *    '<S19>/deadbus fcn'
 *    '<S110>/deadbus fcn'
 */
void sel751test_model_1_3_deadbusfcn(real_T rtu_Vbus, real_T rtu_Vline, real_T
  rtu_VRMSLL, B_deadbusfcn_sel751test_model_T *localB)
{
  real_T Vbus;
  real_T Vline;
  real_T threshold;
  boolean_T b;
  boolean_T c;
  boolean_T d;
  Vbus = rtu_Vbus;
  Vline = rtu_Vline;

  /* MATLAB Function 'Relay 25 - Sync Check - ext_param/deadbus fcn': '<S60>:1' */
  /*  Copyright (c) 2016 Massachusetts Institute of Technology */
  /*  Permission is hereby granted, free of charge, to any person obtaining a copy of this  */
  /*  software and associated documentation files (the "Software"), to deal in the Software */
  /*  without restriction, including without limitation the rights to use, copy, modify,  */
  /*  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  */
  /*  permit persons to whom the Software is furnished to do so, subject to the following  */
  /*  conditions: */
  /*   */
  /*  The above copyright notice and this permission notice shall be included in  */
  /*  all copies or substantial portions of the Software. */
  /*   */
  /*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,  */
  /*  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  */
  /*  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  */
  /*  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  */
  /*  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  */
  /*  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
  /*  */
  /* % */
  if (rtIsNaN(rtu_Vbus)) {
    /* '<S60>:1:26' */
    Vbus = 0.0;
  } else {
    if (rtIsNaN(rtu_Vline)) {
      /* '<S60>:1:28' */
      Vline = 0.0;
    }
  }

  /*  voltage threshold for deadbus */
  if (rtu_VRMSLL > 400.0) {
    /* '<S60>:1:32' */
    /* '<S60>:1:33' */
    threshold = rtu_VRMSLL * 0.003;

    /*  @ 0.3% */
  } else {
    /* '<S60>:1:35' */
    threshold = rtu_VRMSLL * 0.05;

    /*  @ 5% */
  }

  /*  bounding open-circuit voltage at 120% */
  if ((Vbus > rtu_VRMSLL * 0.9) && (Vbus < rtu_VRMSLL * 1.2) && (Vline <
       threshold)) {
    /* '<S60>:1:39' */
    b = TRUE;
  } else {
    /* '<S60>:1:39' */
    b = FALSE;
  }

  if ((Vline > rtu_VRMSLL * 0.9) && (Vline < rtu_VRMSLL * 1.2) && (Vbus <
       threshold)) {
    /* '<S60>:1:40' */
    c = TRUE;
  } else {
    /* '<S60>:1:40' */
    c = FALSE;
  }

  if ((Vline < threshold) && (Vbus < threshold)) {
    /* '<S60>:1:41' */
    d = TRUE;
  } else {
    /* '<S60>:1:41' */
    d = FALSE;
  }

  if (b || c || d) {
    /* '<S60>:1:39' */
    /* '<S60>:1:40' */
    /* '<S60>:1:41' */
    /* '<S60>:1:42' */
    b = TRUE;
  } else {
    /* '<S60>:1:42' */
  }

  /* '<S60>:1:42' */
  localB->y = b;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/*
 * Initial conditions for atomic system:
 *    '<S23>/Relays'
 *    '<S114>/Relays'
 */
void sel751test_model_1__Relays_Init(DW_Relays_sel751test_model_1__T *localDW)
{
  localDW->R51_not_empty = FALSE;
  localDW->n50 = 0.0;
  localDW->n51 = 0.0;
  localDW->n27 = 0.0;
  localDW->n59 = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S23>/Relays'
 *    '<S114>/Relays'
 */
void sel751test_model_1_3_ss__Relays(boolean_T rtu_Enable_logic, real_T rtu_Ts,
  real_T rtu_Reset, const real_T rtu_Iinst[3], const real_T rtu_Irms[3], const
  real_T rtu_Vrms[3], real_T rtu_VRMSLN, real_T rtu_CT_p, real_T rtu_IOC_pickup,
  real_T rtu_IOC_tripDelay, real_T rtu_TOC_pickup, real_T rtu_curveType, real_T
  rtu_timeDial, real_T rtu_UV_pickup, real_T rtu_OV_pickup, real_T
  rtu_UVOV_tripDelay, B_Relays_sel751test_model_1_3_T *localB,
  DW_Relays_sel751test_model_1__T *localDW)
{
  real_T Ipu;
  boolean_T bool_0;
  real_T d_y[3];
  real_T t;
  int32_T ixstart;
  int32_T ix;
  real_T Irms_idx;
  real_T Irms_idx_0;
  real_T Irms_idx_1;
  boolean_T x_idx;
  boolean_T x_idx_0;
  real_T M_idx;
  real_T M_idx_0;

  /* MATLAB Function 'relay_protection_functions/Relays': '<S100>:1' */
  /*  Copyright (c) 2016 Massachusetts Institute of Technology */
  /*  Permission is hereby granted, free of charge, to any person obtaining a copy of this  */
  /*  software and associated documentation files (the "Software"), to deal in the Software */
  /*  without restriction, including without limitation the rights to use, copy, modify,  */
  /*  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  */
  /*  permit persons to whom the Software is furnished to do so, subject to the following  */
  /*  conditions: */
  /*   */
  /*  The above copyright notice and this permission notice shall be included in  */
  /*  all copies or substantial portions of the Software. */
  /*   */
  /*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,  */
  /*  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  */
  /*  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  */
  /*  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  */
  /*  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  */
  /*  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
  /*  */
  /* % */
  /*  initialize or reset the trip signals */
  if ((!localDW->R51_not_empty) || (rtu_Reset != 0.0)) {
    /* '<S100>:1:29' */
    /* '<S100>:1:30' */
    localDW->R50 = FALSE;

    /* '<S100>:1:31' */
    localDW->R51 = FALSE;
    localDW->R51_not_empty = TRUE;

    /* '<S100>:1:32' */
    localDW->R59 = FALSE;

    /* '<S100>:1:33' */
    localDW->R27 = FALSE;
  }

  /*  applying turns CT ratio - assuming protection type CT */
  /* '<S100>:1:37' */
  t = 5.0 / rtu_CT_p;

  /* '<S100>:1:38' */
  Ipu = 5.0 / rtu_CT_p;
  Irms_idx = rtu_Irms[0] * Ipu;
  Irms_idx_0 = rtu_Irms[1] * Ipu;
  Irms_idx_1 = rtu_Irms[2] * Ipu;

  /*  latch for true signals */
  if (localDW->R50 || localDW->R51) {
    /* '<S100>:1:41' */
    bool_0 = TRUE;
  } else {
    /* '<S100>:1:41' */
    bool_0 = FALSE;
  }

  if ((!bool_0) && (rtu_Enable_logic == 1)) {
    /* '<S100>:1:41' */
    /*  calling external function expressing relay protection elements */
    /* '<S100>:1:43' */
    /*  Copyright (c) 2016 Massachusetts Institute of Technology */
    /*  Permission is hereby granted, free of charge, to any person obtaining a copy of this  */
    /*  software and associated documentation files (the "Software"), to deal in the Software */
    /*  without restriction, including without limitation the rights to use, copy, modify,  */
    /*  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  */
    /*  permit persons to whom the Software is furnished to do so, subject to the following  */
    /*  conditions: */
    /*   */
    /*  The above copyright notice and this permission notice shall be included in  */
    /*  all copies or substantial portions of the Software. */
    /*   */
    /*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,  */
    /*  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  */
    /*  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  */
    /*  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  */
    /*  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  */
    /*  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
    /*  */
    /* % */
    /*  current is expected as seem at the secondary of the CT */
    /*  trip delay + 1/4 of a cycle */
    /*  assuming tap = 1, this could be adjusted as an input */
    /*  Ipu = pickup * CT_secondary * tap */
    /*  multiply by sqrt(2) for peak current */
    Ipu = rtu_IOC_pickup * 5.0 * 1.4142135623730951;

    /*  check signal threshold */
    bool_0 = (rtu_Iinst[0] * t > Ipu);
    x_idx = (rtu_Iinst[1] * t > Ipu);
    x_idx_0 = (rtu_Iinst[2] * t > Ipu);
    Ipu = bool_0;
    Ipu += (real_T)x_idx;
    Ipu += (real_T)x_idx_0;
    bool_0 = (Ipu > 0.0);

    /*  resetting count at signal within threshold */
    localDW->n50 *= (real_T)bool_0;

    /*  increase count by Ts at signal out of threshold */
    localDW->n50 += (real_T)bool_0 * rtu_Ts;

    /*  check trip signal */
    /* '<S100>:1:44' */
    /*  Copyright (c) 2016 Massachusetts Institute of Technology */
    /*  Permission is hereby granted, free of charge, to any person obtaining a copy of this  */
    /*  software and associated documentation files (the "Software"), to deal in the Software */
    /*  without restriction, including without limitation the rights to use, copy, modify,  */
    /*  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  */
    /*  permit persons to whom the Software is furnished to do so, subject to the following  */
    /*  conditions: */
    /*   */
    /*  The above copyright notice and this permission notice shall be included in  */
    /*  all copies or substantial portions of the Software. */
    /*   */
    /*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,  */
    /*  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  */
    /*  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  */
    /*  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  */
    /*  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  */
    /*  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
    /*  */
    /* % */
    /*  current is expected as seem at teh secondary of the CT */
    /*  assuming tap = 1, this could be adjusted as an input */
    /*  Ipu = pickup * CT_secondary * tap */
    Ipu = rtu_TOC_pickup * 5.0;

    /*  Trip time calculation */
    t = Irms_idx / Ipu;
    M_idx = Irms_idx_0 / Ipu;
    M_idx_0 = Irms_idx_1 / Ipu;

    /*  multiples of pickup */
    /*  Copyright (c) 2016 Massachusetts Institute of Technology */
    /*  Permission is hereby granted, free of charge, to any person obtaining a copy of this  */
    /*  software and associated documentation files (the "Software"), to deal in the Software */
    /*  without restriction, including without limitation the rights to use, copy, modify,  */
    /*  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  */
    /*  permit persons to whom the Software is furnished to do so, subject to the following  */
    /*  conditions: */
    /*   */
    /*  The above copyright notice and this permission notice shall be included in  */
    /*  all copies or substantial portions of the Software. */
    /*   */
    /*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,  */
    /*  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  */
    /*  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  */
    /*  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  */
    /*  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  */
    /*  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
    /*  */
    /* % */
    /*  returns the operating time in seconds */
    /*  see: SEL751 manual, page 4.23 - table 4.17 */
    /*  calc. pickup time as given in IEEE Std C37.112-1996 */
    /*  TD: time dial */
    /*  B: minimum operating time for high currents */
    /*  A, P: define degree of inverseness of TCC */
    /*  M: multiples of pickup */
    /*  t = TD .* (B + (A ./ (M.^P - 1))); */
    if (rtu_curveType == 1.0) {
      /*  moderately inverse */
      /*  returns the operating time in seconds */
      /*  see: SEL751 manual, page 4.23 - table 4.17 */
      /*  calc. pickup time as given in IEEE Std C37.112-1996 */
      /*  TD: time dial */
      /*  B: minimum operating time for high currents */
      /*  A, P: define degree of inverseness of TCC */
      /*  M: multiples of pickup */
      d_y[0] = rt_powd_snf(t, 0.02);
      d_y[1] = rt_powd_snf(M_idx, 0.02);
      d_y[2] = rt_powd_snf(M_idx_0, 0.02);
      t = d_y[0];
      t = (0.0104 / (t - 1.0) + 0.0226) * rtu_timeDial;
      d_y[0] = t;
      t = d_y[1];
      t = (0.0104 / (t - 1.0) + 0.0226) * rtu_timeDial;
      d_y[1] = t;
      t = d_y[2];
      t = (0.0104 / (t - 1.0) + 0.0226) * rtu_timeDial;
      d_y[2] = t;
    } else if (rtu_curveType == 2.0) {
      /*  inverse */
      /*  returns the operating time in seconds */
      /*  see: SEL751 manual, page 4.23 - table 4.17 */
      /*  calc. pickup time as given in IEEE Std C37.112-1996 */
      /*  TD: time dial */
      /*  B: minimum operating time for high currents */
      /*  A, P: define degree of inverseness of TCC */
      /*  M: multiples of pickup */
      d_y[0] = rt_powd_snf(t, 2.0);
      d_y[1] = rt_powd_snf(M_idx, 2.0);
      d_y[2] = rt_powd_snf(M_idx_0, 2.0);
      t = d_y[0];
      t = (5.95 / (t - 1.0) + 0.18) * rtu_timeDial;
      d_y[0] = t;
      t = d_y[1];
      t = (5.95 / (t - 1.0) + 0.18) * rtu_timeDial;
      d_y[1] = t;
      t = d_y[2];
      t = (5.95 / (t - 1.0) + 0.18) * rtu_timeDial;
      d_y[2] = t;
    } else if (rtu_curveType == 3.0) {
      /*  very inverse */
      /*  returns the operating time in seconds */
      /*  see: SEL751 manual, page 4.23 - table 4.17 */
      /*  calc. pickup time as given in IEEE Std C37.112-1996 */
      /*  TD: time dial */
      /*  B: minimum operating time for high currents */
      /*  A, P: define degree of inverseness of TCC */
      /*  M: multiples of pickup */
      d_y[0] = rt_powd_snf(t, 2.0);
      d_y[1] = rt_powd_snf(M_idx, 2.0);
      d_y[2] = rt_powd_snf(M_idx_0, 2.0);
      t = d_y[0];
      t = (3.88 / (t - 1.0) + 0.0963) * rtu_timeDial;
      d_y[0] = t;
      t = d_y[1];
      t = (3.88 / (t - 1.0) + 0.0963) * rtu_timeDial;
      d_y[1] = t;
      t = d_y[2];
      t = (3.88 / (t - 1.0) + 0.0963) * rtu_timeDial;
      d_y[2] = t;
    } else {
      /*  extremely inverse */
      /*  returns the operating time in seconds */
      /*  see: SEL751 manual, page 4.23 - table 4.17 */
      /*  calc. pickup time as given in IEEE Std C37.112-1996 */
      /*  TD: time dial */
      /*  B: minimum operating time for high currents */
      /*  A, P: define degree of inverseness of TCC */
      /*  M: multiples of pickup */
      d_y[0] = rt_powd_snf(t, 2.0);
      d_y[1] = rt_powd_snf(M_idx, 2.0);
      d_y[2] = rt_powd_snf(M_idx_0, 2.0);
      t = d_y[0];
      t = (5.67 / (t - 1.0) + 0.0352) * rtu_timeDial;
      d_y[0] = t;
      t = d_y[1];
      t = (5.67 / (t - 1.0) + 0.0352) * rtu_timeDial;
      d_y[1] = t;
      t = d_y[2];
      t = (5.67 / (t - 1.0) + 0.0352) * rtu_timeDial;
      d_y[2] = t;
    }

    /*  selecting the smallest trip time */
    ixstart = 1;
    t = d_y[0];
    if (rtIsNaN(d_y[0])) {
      ix = 2;
      bool_0 = FALSE;
      while ((!bool_0) && (ix < 4)) {
        ixstart = ix;
        if (!rtIsNaN(d_y[ix - 1])) {
          t = d_y[ix - 1];
          bool_0 = TRUE;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < 3) {
      while (ixstart + 1 < 4) {
        if (d_y[ixstart] < t) {
          t = d_y[ixstart];
        }

        ixstart++;
      }
    }

    /*  reset the timer if the Irms is less than the pickup current */
    if (t < 0.0) {
      t = 0.0;
    }

    /*  check signal threshold */
    bool_0 = (Irms_idx > Ipu);
    x_idx = (Irms_idx_0 > Ipu);
    x_idx_0 = (Irms_idx_1 > Ipu);
    Ipu = bool_0;
    Ipu += (real_T)x_idx;
    Ipu += (real_T)x_idx_0;
    bool_0 = (Ipu > 0.0);

    /*  resetting count at signal within threshold */
    localDW->n51 *= (real_T)bool_0;

    /*  increase count by Ts at signal out of threshold */
    localDW->n51 += (real_T)bool_0 * rtu_Ts;

    /*  check trip signal */
    /* '<S100>:1:45' */
    Ipu = rtu_UV_pickup;

    /*  Copyright (c) 2016 Massachusetts Institute of Technology */
    /*  Permission is hereby granted, free of charge, to any person obtaining a copy of this  */
    /*  software and associated documentation files (the "Software"), to deal in the Software */
    /*  without restriction, including without limitation the rights to use, copy, modify,  */
    /*  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  */
    /*  permit persons to whom the Software is furnished to do so, subject to the following  */
    /*  conditions: */
    /*   */
    /*  The above copyright notice and this permission notice shall be included in  */
    /*  all copies or substantial portions of the Software. */
    /*   */
    /*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,  */
    /*  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  */
    /*  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  */
    /*  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  */
    /*  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  */
    /*  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
    /*  */
    /* % */
    /*  using a very simple model for the voltage protection. future work */
    /*  includes the revision of this function */
    /*  using 0.9 pu as default in case of inputs over 1.0 pu for undervoltage */
    if ((rtu_UV_pickup > 1.0) || (rtu_UV_pickup == 0.0)) {
      Ipu = 0.9;
    }

    /*  trip delay + 1/4 of a cycle */
    /*  ratio of measurement to nominal voltage */
    /*  check signal threshold */
    bool_0 = (rtu_Vrms[0] / rtu_VRMSLN <= Ipu);
    x_idx = (rtu_Vrms[1] / rtu_VRMSLN <= Ipu);
    x_idx_0 = (rtu_Vrms[2] / rtu_VRMSLN <= Ipu);
    Ipu = bool_0;
    Ipu += (real_T)x_idx;
    Ipu += (real_T)x_idx_0;
    bool_0 = (Ipu > 0.0);

    /*  resetting count at signal within threshold */
    localDW->n27 *= (real_T)bool_0;

    /*  increase count by Ts at signal out of threshold */
    localDW->n27 += (real_T)bool_0 * rtu_Ts;

    /*  check trip signal */
    /* '<S100>:1:46' */
    Ipu = rtu_OV_pickup;

    /*  Copyright (c) 2016 Massachusetts Institute of Technology */
    /*  Permission is hereby granted, free of charge, to any person obtaining a copy of this  */
    /*  software and associated documentation files (the "Software"), to deal in the Software */
    /*  without restriction, including without limitation the rights to use, copy, modify,  */
    /*  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  */
    /*  permit persons to whom the Software is furnished to do so, subject to the following  */
    /*  conditions: */
    /*   */
    /*  The above copyright notice and this permission notice shall be included in  */
    /*  all copies or substantial portions of the Software. */
    /*   */
    /*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,  */
    /*  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  */
    /*  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  */
    /*  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  */
    /*  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  */
    /*  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
    /*  */
    /* % */
    /*  using a very simple model for the voltage protection. future work */
    /*  includes the revision of this function */
    /*  using 1.1 pu as default in case of inputs under 1.0 pu for overvoltage */
    if ((rtu_OV_pickup < 1.0) || (rtu_OV_pickup == 0.0)) {
      Ipu = 1.1;
    }

    /*  trip delay + 1/4 of a cycle */
    /*  ratio of measurement to nominal voltage */
    /*  check signal threshold */
    bool_0 = (rtu_Vrms[0] / rtu_VRMSLN >= Ipu);
    x_idx = (rtu_Vrms[1] / rtu_VRMSLN >= Ipu);
    x_idx_0 = (rtu_Vrms[2] / rtu_VRMSLN >= Ipu);
    Ipu = bool_0;
    Ipu += (real_T)x_idx;
    Ipu += (real_T)x_idx_0;
    bool_0 = (Ipu > 0.0);

    /*  resetting count at signal within threshold */
    localDW->n59 *= (real_T)bool_0;

    /*  increase count by Ts at signal out of threshold */
    localDW->n59 += (real_T)bool_0 * rtu_Ts;

    /*  check trip signal */
    /* '<S100>:1:48' */
    localDW->R50 = (localDW->n50 > 0.0041666666666666666 + rtu_IOC_tripDelay);

    /* '<S100>:1:49' */
    localDW->R51 = (localDW->n51 > t);

    /* '<S100>:1:50' */
    localDW->R27 = (localDW->n27 > 0.0041666666666666666 + rtu_UVOV_tripDelay);

    /* '<S100>:1:51' */
    localDW->R59 = (localDW->n59 > 0.0041666666666666666 + rtu_UVOV_tripDelay);
  }

  /* '<S100>:1:54' */
  localB->trip50 = localDW->R50;

  /*  latched */
  /* '<S100>:1:55' */
  localB->trip51 = localDW->R51;

  /*  latched */
  /* '<S100>:1:56' */
  localB->trip27 = localDW->R27;

  /*  not latched */
  /* '<S100>:1:57' */
  localB->trip59 = localDW->R59;

  /*  not latched */
}

/*
 * Initial conditions for atomic system:
 *    '<S5>/trip_out mng'
 *    '<S6>/trip_out mng'
 */
void sel751test_mod_trip_outmng_Init(DW_trip_outmng_sel751test_mod_T *localDW)
{
  localDW->n25 = 0.0;
  localDW->prev_mode = 0.0;
  localDW->prev_trip_in = 1.0;
}

/*
 * Output and update for atomic system:
 *    '<S5>/trip_out mng'
 *    '<S6>/trip_out mng'
 */
void sel751test_model_1__trip_outmng(real_T rtu_Ts, boolean_T rtu_bool_R25,
  real_T rtu_op_mode_in, real_T rtu_trip_in, real_T rtu_synch_check_time, real_T
  rtu_clock_time, real_T rtu_time_delay, B_trip_outmng_sel751test_mode_T *localB,
  DW_trip_outmng_sel751test_mod_T *localDW)
{
  /* MATLAB Function 'trip_out mng': '<S24>:1' */
  /*  Copyright (c) 2016 Massachusetts Institute of Technology */
  /*  Permission is hereby granted, free of charge, to any person obtaining a copy of this  */
  /*  software and associated documentation files (the "Software"), to deal in the Software */
  /*  without restriction, including without limitation the rights to use, copy, modify,  */
  /*  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  */
  /*  permit persons to whom the Software is furnished to do so, subject to the following  */
  /*  conditions: */
  /*   */
  /*  The above copyright notice and this permission notice shall be included in  */
  /*  all copies or substantial portions of the Software. */
  /*   */
  /*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,  */
  /*  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  */
  /*  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  */
  /*  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION  */
  /*  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  */
  /*  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
  /*  */
  /* % */
  /*  1) Evaluates the status of the relay signals, the cmds, and the signal */
  /*  from the synch check to issue a connect/disconnect to the CB */
  /*  2) Establish the delay synch check time (currently 2 cycles) */
  /*  */
  /* '<S24>:1:38' */
  localB->trip_out = rtu_trip_in * (real_T)rtu_bool_R25;

  /*  the R25 logic will be active if the breaker has been opened, and a */
  /*  forced-to-close command is applied */
  if (((localDW->prev_mode == 2.0) || (localDW->prev_trip_in == 0.0)) &&
      ((rtu_op_mode_in == 1.0) || (rtu_op_mode_in == 0.0)) && (rtu_trip_in ==
       1.0)) {
    /* '<S24>:1:42' */
    /*  time accumulation */
    /* '<S24>:1:45' */
    localDW->n25 *= (real_T)rtu_bool_R25;

    /* '<S24>:1:46' */
    localDW->n25 += (real_T)rtu_bool_R25 * rtu_Ts;
    if (localDW->n25 > rtu_synch_check_time) {
      /* '<S24>:1:47' */
      /* '<S24>:1:48' */
      localB->trip_out = 1.0;

      /*  reset history values */
      /* '<S24>:1:50' */
      localDW->prev_mode = rtu_op_mode_in;

      /* '<S24>:1:51' */
      localDW->prev_trip_in = rtu_trip_in;
    } else {
      /* '<S24>:1:53' */
      localDW->prev_mode = 2.0;

      /* '<S24>:1:54' */
      localDW->prev_trip_in = 0.0;

      /* '<S24>:1:55' */
      localB->trip_out = 0.0;
    }
  } else if (rtu_op_mode_in == 2.0) {
    /* '<S24>:1:58' */
    /* '<S24>:1:59' */
    localDW->prev_mode = 2.0;

    /* '<S24>:1:60' */
    localDW->prev_trip_in = 0.0;

    /* '<S24>:1:61' */
    localB->trip_out = 0.0;

    /* '<S24>:1:62' */
    localDW->n25 = 0.0;
  } else {
    /* '<S24>:1:64' */
    localDW->n25 = 0.0;
  }

  /*  time delay [sec] to activate logic. Forces the trip_out signal */
  /*  to 1 (close) until the simulation clock exceeds the threshold */
  if (rtu_clock_time < rtu_time_delay) {
    /* '<S24>:1:70' */
    /* '<S24>:1:71' */
    localB->trip_out = 1.0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T y_0;
  real_T u;
  boolean_T y_1;
  if (u1 == 0.0) {
    y = u0;
  } else {
    u = u0;
    y_0 = ((!rtIsNaN(u)) && (!rtIsInf(u)));
    u = u1;
    y_1 = ((!rtIsNaN(u)) && (!rtIsInf(u)));
    if (!(y_0 && y_1)) {
      y = (rtNaN);
    } else {
      u = u0 / u1;
      if (u1 <= floor(u1)) {
        y = u0 - floor(u) * u1;
      } else {
        if (fabs(u - rt_roundd_snf(u)) <= DBL_EPSILON * fabs(u)) {
          y = 0.0;
        } else {
          y = (u - floor(u)) * u1;
        }
      }
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  real_T b;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
static void sel751test_model_1_3_ss_relays_output(void)
{
  real_T dp;
  real_T dsp2Pi;
  real_T tmpForInput[9];
  int32_T tmp;
  int32_T i;
  boolean_T unnamed_idx;
  real_T u;
  real_T u_0;

  /* Memory: '<S2>/S-Function' */
  sel751test_model_1_3_ss_relays_B.SFunction =
    sel751test_model_1_3_ss_relays_DW.SFunction_PreviousInput;

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/S-Function1'
   */
  sel751test_model_1_3_ss_relays_B.Sum =
    sel751test_model_1_3_ss_relays_P.SFunction1_Value +
    sel751test_model_1_3_ss_relays_B.SFunction;

  /* Stop: '<S2>/Stop Simulation' */
  if (sel751test_model_1_3_ss_relays_B.Sum != 0.0) {
    rtmSetStopRequested(sel751test_model_1_3_ss_relays_M, 1);
  }

  /* End of Stop: '<S2>/Stop Simulation' */

  /* Memory: '<S5>/Memory1' */
  sel751test_model_1_3_ss_relays_B.op_mode =
    sel751test_model_1_3_ss_relays_DW.Memory1_PreviousInput;

  /* Memory: '<S5>/Memory8' */
  sel751test_model_1_3_ss_relays_B.Logic_trip =
    sel751test_model_1_3_ss_relays_DW.Memory8_PreviousInput;

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Iabc[0] =
    sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput[0];
  sel751test_model_1_3_ss_relays_B.Iabc[1] =
    sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput[1];
  sel751test_model_1_3_ss_relays_B.Iabc[2] =
    sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput[2];

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Vabc[0] =
    sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput[0];
  sel751test_model_1_3_ss_relays_B.Vabc[1] =
    sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput[1];
  sel751test_model_1_3_ss_relays_B.Vabc[2] =
    sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput[2];

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.P =
    sel751test_model_1_3_ss_relays_DW.Memory3_3_PreviousInput;

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Q =
    sel751test_model_1_3_ss_relays_DW.Memory3_4_PreviousInput;

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.freq =
    sel751test_model_1_3_ss_relays_DW.Memory3_5_PreviousInput;

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Va_rms =
    sel751test_model_1_3_ss_relays_DW.Memory3_6_PreviousInput;

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.pf =
    sel751test_model_1_3_ss_relays_DW.Memory3_7_PreviousInput;

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Vpu =
    sel751test_model_1_3_ss_relays_DW.Memory3_8_PreviousInput;

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.status =
    sel751test_model_1_3_ss_relays_DW.Memory3_9_PreviousInput;

  /* Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_B.pf_states =
    sel751test_model_1_3_ss_relays_DW.Memory3_10_PreviousInput;

  /* Memory: '<S6>/Memory1' */
  sel751test_model_1_3_ss_relays_B.op_mode_d =
    sel751test_model_1_3_ss_relays_DW.Memory1_PreviousInput_e;

  /* Memory: '<S6>/Memory8' */
  sel751test_model_1_3_ss_relays_B.Logic_trip_h =
    sel751test_model_1_3_ss_relays_DW.Memory8_PreviousInput_e;

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Iabc_b[0] =
    sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput_p[0];
  sel751test_model_1_3_ss_relays_B.Iabc_b[1] =
    sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput_p[1];
  sel751test_model_1_3_ss_relays_B.Iabc_b[2] =
    sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput_p[2];

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Vabc_n[0] =
    sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput_l[0];
  sel751test_model_1_3_ss_relays_B.Vabc_n[1] =
    sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput_l[1];
  sel751test_model_1_3_ss_relays_B.Vabc_n[2] =
    sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput_l[2];

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.P_a =
    sel751test_model_1_3_ss_relays_DW.Memory3_3_PreviousInput_n;

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Q_j =
    sel751test_model_1_3_ss_relays_DW.Memory3_4_PreviousInput_g;

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.freq_m =
    sel751test_model_1_3_ss_relays_DW.Memory3_5_PreviousInput_d;

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Va_rms_o =
    sel751test_model_1_3_ss_relays_DW.Memory3_6_PreviousInput_m;

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.pf_b =
    sel751test_model_1_3_ss_relays_DW.Memory3_7_PreviousInput_c;

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.Vpu_h =
    sel751test_model_1_3_ss_relays_DW.Memory3_8_PreviousInput_d;

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.status_f =
    sel751test_model_1_3_ss_relays_DW.Memory3_9_PreviousInput_l;

  /* Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_B.pf_states_i =
    sel751test_model_1_3_ss_relays_DW.Memory3_10_PreviousInput_e;

  /* Outputs for Atomic SubSystem: '<S8>/Subsystem2' */

  /* Level2 S-Function Block: '<S198>/S-Function' (send_rt) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* End of Outputs for SubSystem: '<S8>/Subsystem2' */

  /* Level2 S-Function Block: '<S197>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S199>/S-Function' (recv_rt) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Product: '<S5>/Divide1' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Divide1[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[4] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[1];
  sel751test_model_1_3_ss_relays_B.Divide1[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[5] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[1];
  sel751test_model_1_3_ss_relays_B.Divide1[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[6] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[1];

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE;

  /* Math: '<S10>/Math Function' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator,
     sel751test_model_1_3_ss_relays_P.Constant4_Value);

  /* Trigonometry: '<S10>/Trigonometric Function' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction = sin
    (sel751test_model_1_3_ss_relays_B.MathFunction);

  /* Trigonometry: '<S10>/Trigonometric Function2' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction2 = cos
    (sel751test_model_1_3_ss_relays_B.MathFunction);

  /* Product: '<S29>/Product' incorporates:
   *  Constant: '<S29>/K1'
   */
  sel751test_model_1_3_ss_relays_B.Product =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction *
    sel751test_model_1_3_ss_relays_P.K1_Value;

  /* Product: '<S29>/Product1' incorporates:
   *  Constant: '<S29>/K2'
   */
  sel751test_model_1_3_ss_relays_B.Product1 =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2 *
    sel751test_model_1_3_ss_relays_P.K2_Value;

  /* Sum: '<S29>/Sum' */
  sel751test_model_1_3_ss_relays_B.sinwt2pi3 = (0.0 -
    sel751test_model_1_3_ss_relays_B.Product) -
    sel751test_model_1_3_ss_relays_B.Product1;

  /* Product: '<S29>/Product3' incorporates:
   *  Constant: '<S29>/K1'
   */
  sel751test_model_1_3_ss_relays_B.Product3 =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2 *
    sel751test_model_1_3_ss_relays_P.K1_Value;

  /* Product: '<S29>/Product2' incorporates:
   *  Constant: '<S29>/K2'
   */
  sel751test_model_1_3_ss_relays_B.Product2 =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction *
    sel751test_model_1_3_ss_relays_P.K2_Value;

  /* Sum: '<S29>/Sum1' */
  sel751test_model_1_3_ss_relays_B.coswt2pi3 =
    sel751test_model_1_3_ss_relays_B.Product2 -
    sel751test_model_1_3_ss_relays_B.Product3;

  /* Sum: '<S29>/Sum2' */
  sel751test_model_1_3_ss_relays_B.sinwt2pi3_i = (0.0 -
    sel751test_model_1_3_ss_relays_B.sinwt2pi3) -
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction;

  /* Sum: '<S29>/Sum3' */
  sel751test_model_1_3_ss_relays_B.coswt2pi3_k = (0.0 -
    sel751test_model_1_3_ss_relays_B.coswt2pi3) -
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2;

  /* Fcn: '<S29>/Fcn1' */
  sel751test_model_1_3_ss_relays_B.Vq =
    ((sel751test_model_1_3_ss_relays_B.Divide1[0] *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction2 +
      sel751test_model_1_3_ss_relays_B.Divide1[1] *
      sel751test_model_1_3_ss_relays_B.coswt2pi3) +
     sel751test_model_1_3_ss_relays_B.Divide1[2] *
     sel751test_model_1_3_ss_relays_B.coswt2pi3_k) * 0.66666666666666663;

  /* DiscreteIntegrator: '<S28>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4 =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE;
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4 =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_g *
      sel751test_model_1_3_ss_relays_B.Vq +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S28>/Integ4' */
  /* S-Function block: <S31>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e.uBuffers)
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4;

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_n/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_e = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e.uBuffers)[indDelayed];
  }

  /* UnitDelay: '<S28>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE;

  /* Step: '<S28>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_j) {
    sel751test_model_1_3_ss_relays_B.Step =
      sel751test_model_1_3_ss_relays_P.Step_Y0_ky;
  } else {
    sel751test_model_1_3_ss_relays_B.Step =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_ps;
  }

  /* End of Step: '<S28>/Step' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_k2) {
    /* Gain: '<S28>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_c =
      sel751test_model_1_3_ss_relays_P.Gain_Gain *
      sel751test_model_1_3_ss_relays_B.UnitDelay;

    /* Gain: '<S28>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_b1 =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain *
      sel751test_model_1_3_ss_relays_B.Vq;

    /* Sum: '<S28>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_bl =
      sel751test_model_1_3_ss_relays_B.Gain1_b1 -
      sel751test_model_1_3_ss_relays_B.Gain_c;

    /* Sum: '<S28>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_ch =
      sel751test_model_1_3_ss_relays_B.Integ4 -
      sel751test_model_1_3_ss_relays_B.SFunction_e;

    /* Product: '<S28>/Product' incorporates:
     *  Constant: '<S28>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_l =
      sel751test_model_1_3_ss_relays_B.Sum7_ch *
      sel751test_model_1_3_ss_relays_P.K2_Value_i;

    /* Sum: '<S28>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_pb =
      sel751test_model_1_3_ss_relays_B.Meanvalue_l +
      sel751test_model_1_3_ss_relays_B.Correction_bl;
    sel751test_model_1_3_ss_relays_B.Switch =
      sel751test_model_1_3_ss_relays_B.Sum5_pb;
  } else {
    sel751test_model_1_3_ss_relays_B.Switch =
      sel751test_model_1_3_ss_relays_P.Constant_Value_f;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Gain: '<S26>/Kp4' */
  sel751test_model_1_3_ss_relays_B.Kp4 =
    sel751test_model_1_3_ss_relays_P.Kp4_Gain *
    sel751test_model_1_3_ss_relays_B.Switch;

  /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_k =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_d;

  /* Gain: '<S26>/Kp6' */
  sel751test_model_1_3_ss_relays_B.Kp6 =
    sel751test_model_1_3_ss_relays_P.Kp6_Gain *
    sel751test_model_1_3_ss_relays_B.Switch;

  /* ZeroOrderHold: '<S26>/Zero-Order Hold' */
  sel751test_model_1_3_ss_relays_B.ZeroOrderHold =
    sel751test_model_1_3_ss_relays_B.Kp6;

  /* SampleTimeMath: '<S30>/TSamp'
   *
   * About '<S30>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  sel751test_model_1_3_ss_relays_B.TSamp =
    sel751test_model_1_3_ss_relays_B.ZeroOrderHold *
    sel751test_model_1_3_ss_relays_P.TSamp_WtEt;

  /* UnitDelay: '<S30>/UD' */
  sel751test_model_1_3_ss_relays_B.Uk1 =
    sel751test_model_1_3_ss_relays_DW.UD_DSTATE;

  /* Sum: '<S30>/Diff' */
  sel751test_model_1_3_ss_relays_B.Diff = sel751test_model_1_3_ss_relays_B.TSamp
    - sel751test_model_1_3_ss_relays_B.Uk1;

  /* Sum: '<S26>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6 = (sel751test_model_1_3_ss_relays_B.Kp4
    + sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_k) +
    sel751test_model_1_3_ss_relays_B.Diff;

  /* Saturate: '<S26>/Saturation2' */
  u = sel751test_model_1_3_ss_relays_B.Sum6;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation2_LowerSat;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation2_UpperSat;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Saturation2 = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Saturation2 = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Saturation2 = u;
  }

  /* End of Saturate: '<S26>/Saturation2' */

  /* Gain: '<S10>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10 =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain *
    sel751test_model_1_3_ss_relays_B.Saturation2;

  /* UnitDelay: '<S27>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_B.y1 =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_l;

  /* Sum: '<S27>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1 =
    sel751test_model_1_3_ss_relays_B.Gain10 -
    sel751test_model_1_3_ss_relays_B.y1;

  /* Saturate: '<S27>/Saturation' */
  u = sel751test_model_1_3_ss_relays_B.Sum1;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_c;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_m;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Deltau_limit = u;
  }

  /* End of Saturate: '<S27>/Saturation' */

  /* Sum: '<S27>/Sum' */
  sel751test_model_1_3_ss_relays_B.y =
    sel751test_model_1_3_ss_relays_B.Deltau_limit +
    sel751test_model_1_3_ss_relays_B.y1;

  /* DiscreteStateSpace: '<S25>/Discrete State-Space' */
  {
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace =
      (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE[1];
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace +=
      sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_D*
      sel751test_model_1_3_ss_relays_B.y;
  }

  /* Gain: '<S26>/Kp5' */
  sel751test_model_1_3_ss_relays_B.Kp5 =
    sel751test_model_1_3_ss_relays_P.Kp5_Gain *
    sel751test_model_1_3_ss_relays_B.Switch;

  /* UnitDelay: '<S10>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_e =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_n;

  /* Fcn: '<S29>/Fcn2' */
  sel751test_model_1_3_ss_relays_B.Vd =
    ((sel751test_model_1_3_ss_relays_B.Divide1[0] *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction +
      sel751test_model_1_3_ss_relays_B.Divide1[1] *
      sel751test_model_1_3_ss_relays_B.sinwt2pi3) +
     sel751test_model_1_3_ss_relays_B.Divide1[2] *
     sel751test_model_1_3_ss_relays_B.sinwt2pi3_i) * 0.66666666666666663;

  /* Sum: '<S29>/Sum4' */
  tmpForInput[0] = sel751test_model_1_3_ss_relays_B.Divide1[0];
  tmpForInput[1] = sel751test_model_1_3_ss_relays_B.Divide1[1];
  tmpForInput[2] = sel751test_model_1_3_ss_relays_B.Divide1[2];
  tmpForInput[3] = sel751test_model_1_3_ss_relays_B.TrigonometricFunction;
  tmpForInput[4] = sel751test_model_1_3_ss_relays_B.TrigonometricFunction2;
  tmpForInput[5] = sel751test_model_1_3_ss_relays_B.sinwt2pi3;
  tmpForInput[6] = sel751test_model_1_3_ss_relays_B.coswt2pi3;
  tmpForInput[7] = sel751test_model_1_3_ss_relays_B.sinwt2pi3_i;
  tmpForInput[8] = sel751test_model_1_3_ss_relays_B.coswt2pi3_k;
  dsp2Pi = tmpForInput[0];
  for (i = 0; i < 8; i++) {
    tmp = i + 1;
    dsp2Pi += tmpForInput[tmp];
  }

  sel751test_model_1_3_ss_relays_B.Sum4 = dsp2Pi;

  /* End of Sum: '<S29>/Sum4' */

  /* Gain: '<S29>/Gain1' */
  sel751test_model_1_3_ss_relays_B.Gain1 =
    sel751test_model_1_3_ss_relays_P.Gain1_Gain_a0 *
    sel751test_model_1_3_ss_relays_B.Sum4;

  /* Gain: '<S5>/Gain21' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Gain21 =
    sel751test_model_1_3_ss_relays_P.Gain21_Gain *
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[6];

  /* Product: '<S5>/Divide' */
  sel751test_model_1_3_ss_relays_B.Divide[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[1] /
    sel751test_model_1_3_ss_relays_B.Gain21;
  sel751test_model_1_3_ss_relays_B.Divide[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[2] /
    sel751test_model_1_3_ss_relays_B.Gain21;
  sel751test_model_1_3_ss_relays_B.Divide[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[3] /
    sel751test_model_1_3_ss_relays_B.Gain21;

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_m =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_i;

  /* Math: '<S11>/Math Function' incorporates:
   *  Constant: '<S11>/Constant4'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_i = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_m,
     sel751test_model_1_3_ss_relays_P.Constant4_Value_o);

  /* Trigonometry: '<S11>/Trigonometric Function' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction_j = sin
    (sel751test_model_1_3_ss_relays_B.MathFunction_i);

  /* Trigonometry: '<S11>/Trigonometric Function2' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_n = cos
    (sel751test_model_1_3_ss_relays_B.MathFunction_i);

  /* Product: '<S36>/Product' incorporates:
   *  Constant: '<S36>/K1'
   */
  sel751test_model_1_3_ss_relays_B.Product_m =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction_j *
    sel751test_model_1_3_ss_relays_P.K1_Value_d;

  /* Product: '<S36>/Product1' incorporates:
   *  Constant: '<S36>/K2'
   */
  sel751test_model_1_3_ss_relays_B.Product1_o =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_n *
    sel751test_model_1_3_ss_relays_P.K2_Value_e;

  /* Sum: '<S36>/Sum' */
  sel751test_model_1_3_ss_relays_B.sinwt2pi3_g = (0.0 -
    sel751test_model_1_3_ss_relays_B.Product_m) -
    sel751test_model_1_3_ss_relays_B.Product1_o;

  /* Product: '<S36>/Product3' incorporates:
   *  Constant: '<S36>/K1'
   */
  sel751test_model_1_3_ss_relays_B.Product3_o =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_n *
    sel751test_model_1_3_ss_relays_P.K1_Value_d;

  /* Product: '<S36>/Product2' incorporates:
   *  Constant: '<S36>/K2'
   */
  sel751test_model_1_3_ss_relays_B.Product2_e =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction_j *
    sel751test_model_1_3_ss_relays_P.K2_Value_e;

  /* Sum: '<S36>/Sum1' */
  sel751test_model_1_3_ss_relays_B.coswt2pi3_g =
    sel751test_model_1_3_ss_relays_B.Product2_e -
    sel751test_model_1_3_ss_relays_B.Product3_o;

  /* Sum: '<S36>/Sum2' */
  sel751test_model_1_3_ss_relays_B.sinwt2pi3_n = (0.0 -
    sel751test_model_1_3_ss_relays_B.sinwt2pi3_g) -
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction_j;

  /* Sum: '<S36>/Sum3' */
  sel751test_model_1_3_ss_relays_B.coswt2pi3_j = (0.0 -
    sel751test_model_1_3_ss_relays_B.coswt2pi3_g) -
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_n;

  /* Fcn: '<S36>/Fcn1' */
  sel751test_model_1_3_ss_relays_B.Vq_i =
    ((sel751test_model_1_3_ss_relays_B.Divide[0] *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_n +
      sel751test_model_1_3_ss_relays_B.Divide[1] *
      sel751test_model_1_3_ss_relays_B.coswt2pi3_g) +
     sel751test_model_1_3_ss_relays_B.Divide[2] *
     sel751test_model_1_3_ss_relays_B.coswt2pi3_j) * 0.66666666666666663;

  /* DiscreteIntegrator: '<S35>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_o != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_j =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_o;
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_j =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_nf *
      sel751test_model_1_3_ss_relays_B.Vq_i +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_o;
  }

  /* End of DiscreteIntegrator: '<S35>/Integ4' */
  /* S-Function block: <S38>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_a.uBuffers)
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_j;

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_l/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_f = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_a.uBuffers)[indDelayed];
  }

  /* UnitDelay: '<S35>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_c =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_n1;

  /* Step: '<S35>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_b) {
    sel751test_model_1_3_ss_relays_B.Step_i =
      sel751test_model_1_3_ss_relays_P.Step_Y0_l;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_i =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_cz;
  }

  /* End of Step: '<S35>/Step' */

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_i >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_ad) {
    /* Gain: '<S35>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_pz =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_p *
      sel751test_model_1_3_ss_relays_B.UnitDelay_c;

    /* Gain: '<S35>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_oy =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_a *
      sel751test_model_1_3_ss_relays_B.Vq_i;

    /* Sum: '<S35>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_jn =
      sel751test_model_1_3_ss_relays_B.Gain1_oy -
      sel751test_model_1_3_ss_relays_B.Gain_pz;

    /* Sum: '<S35>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_lm =
      sel751test_model_1_3_ss_relays_B.Integ4_j -
      sel751test_model_1_3_ss_relays_B.SFunction_f;

    /* Product: '<S35>/Product' incorporates:
     *  Constant: '<S35>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_px =
      sel751test_model_1_3_ss_relays_B.Sum7_lm *
      sel751test_model_1_3_ss_relays_P.K2_Value_c;

    /* Sum: '<S35>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_pz =
      sel751test_model_1_3_ss_relays_B.Meanvalue_px +
      sel751test_model_1_3_ss_relays_B.Correction_jn;
    sel751test_model_1_3_ss_relays_B.Switch_k =
      sel751test_model_1_3_ss_relays_B.Sum5_pz;
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_k =
      sel751test_model_1_3_ss_relays_P.Constant_Value_gq;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Gain: '<S33>/Kp4' */
  sel751test_model_1_3_ss_relays_B.Kp4_k =
    sel751test_model_1_3_ss_relays_P.Kp4_Gain_i *
    sel751test_model_1_3_ss_relays_B.Switch_k;

  /* DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_kv =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_b;

  /* Gain: '<S33>/Kp6' */
  sel751test_model_1_3_ss_relays_B.Kp6_c =
    sel751test_model_1_3_ss_relays_P.Kp6_Gain_j *
    sel751test_model_1_3_ss_relays_B.Switch_k;

  /* ZeroOrderHold: '<S33>/Zero-Order Hold' */
  sel751test_model_1_3_ss_relays_B.ZeroOrderHold_e =
    sel751test_model_1_3_ss_relays_B.Kp6_c;

  /* SampleTimeMath: '<S37>/TSamp'
   *
   * About '<S37>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  sel751test_model_1_3_ss_relays_B.TSamp_c =
    sel751test_model_1_3_ss_relays_B.ZeroOrderHold_e *
    sel751test_model_1_3_ss_relays_P.TSamp_WtEt_n;

  /* UnitDelay: '<S37>/UD' */
  sel751test_model_1_3_ss_relays_B.Uk1_c =
    sel751test_model_1_3_ss_relays_DW.UD_DSTATE_p;

  /* Sum: '<S37>/Diff' */
  sel751test_model_1_3_ss_relays_B.Diff_d =
    sel751test_model_1_3_ss_relays_B.TSamp_c -
    sel751test_model_1_3_ss_relays_B.Uk1_c;

  /* Sum: '<S33>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6_b =
    (sel751test_model_1_3_ss_relays_B.Kp4_k +
     sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_kv) +
    sel751test_model_1_3_ss_relays_B.Diff_d;

  /* Saturate: '<S33>/Saturation2' */
  u = sel751test_model_1_3_ss_relays_B.Sum6_b;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation2_LowerSat_h;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation2_UpperSat_j;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Saturation2_a = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Saturation2_a = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Saturation2_a = u;
  }

  /* End of Saturate: '<S33>/Saturation2' */

  /* Gain: '<S11>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10_p =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain_h *
    sel751test_model_1_3_ss_relays_B.Saturation2_a;

  /* UnitDelay: '<S34>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_B.y1_c =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_e;

  /* Sum: '<S34>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1_e =
    sel751test_model_1_3_ss_relays_B.Gain10_p -
    sel751test_model_1_3_ss_relays_B.y1_c;

  /* Saturate: '<S34>/Saturation' */
  u = sel751test_model_1_3_ss_relays_B.Sum1_e;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_f;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_lx;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_j = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_j = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_j = u;
  }

  /* End of Saturate: '<S34>/Saturation' */

  /* Sum: '<S34>/Sum' */
  sel751test_model_1_3_ss_relays_B.y_g =
    sel751test_model_1_3_ss_relays_B.Deltau_limit_j +
    sel751test_model_1_3_ss_relays_B.y1_c;

  /* DiscreteStateSpace: '<S32>/Discrete State-Space' */
  {
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_d =
      (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_b[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_b[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_b[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_b[1];
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_d +=
      sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_D_h*
      sel751test_model_1_3_ss_relays_B.y_g;
  }

  /* Gain: '<S33>/Kp5' */
  sel751test_model_1_3_ss_relays_B.Kp5_l =
    sel751test_model_1_3_ss_relays_P.Kp5_Gain_o *
    sel751test_model_1_3_ss_relays_B.Switch_k;

  /* UnitDelay: '<S11>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_j =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_k;

  /* Fcn: '<S36>/Fcn2' */
  sel751test_model_1_3_ss_relays_B.Vd_g =
    ((sel751test_model_1_3_ss_relays_B.Divide[0] *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction_j +
      sel751test_model_1_3_ss_relays_B.Divide[1] *
      sel751test_model_1_3_ss_relays_B.sinwt2pi3_g) +
     sel751test_model_1_3_ss_relays_B.Divide[2] *
     sel751test_model_1_3_ss_relays_B.sinwt2pi3_n) * 0.66666666666666663;

  /* Sum: '<S36>/Sum4' */
  tmpForInput[0] = sel751test_model_1_3_ss_relays_B.Divide[0];
  tmpForInput[1] = sel751test_model_1_3_ss_relays_B.Divide[1];
  tmpForInput[2] = sel751test_model_1_3_ss_relays_B.Divide[2];
  tmpForInput[3] = sel751test_model_1_3_ss_relays_B.TrigonometricFunction_j;
  tmpForInput[4] = sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_n;
  tmpForInput[5] = sel751test_model_1_3_ss_relays_B.sinwt2pi3_g;
  tmpForInput[6] = sel751test_model_1_3_ss_relays_B.coswt2pi3_g;
  tmpForInput[7] = sel751test_model_1_3_ss_relays_B.sinwt2pi3_n;
  tmpForInput[8] = sel751test_model_1_3_ss_relays_B.coswt2pi3_j;
  dsp2Pi = tmpForInput[0];
  for (i = 0; i < 8; i++) {
    tmp = i + 1;
    dsp2Pi += tmpForInput[tmp];
  }

  sel751test_model_1_3_ss_relays_B.Sum4_h = dsp2Pi;

  /* End of Sum: '<S36>/Sum4' */

  /* Gain: '<S36>/Gain1' */
  sel751test_model_1_3_ss_relays_B.Gain1_p =
    sel751test_model_1_3_ss_relays_P.Gain1_Gain_n1 *
    sel751test_model_1_3_ss_relays_B.Sum4_h;

  /* Product: '<S48>/Product1' */
  sel751test_model_1_3_ss_relays_B.Product1_k[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[4] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[1];
  sel751test_model_1_3_ss_relays_B.Product1_k[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[5] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[2];
  sel751test_model_1_3_ss_relays_B.Product1_k[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[6] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[3];

  /* Sum: '<S48>/Sum4' */
  dsp2Pi = sel751test_model_1_3_ss_relays_B.Product1_k[0];
  dsp2Pi += sel751test_model_1_3_ss_relays_B.Product1_k[1];
  dsp2Pi += sel751test_model_1_3_ss_relays_B.Product1_k[2];
  sel751test_model_1_3_ss_relays_B.P_i = dsp2Pi;

  /* Sum: '<S48>/Sum5' */
  sel751test_model_1_3_ss_relays_B.Sum5 =
    sel751test_model_1_3_ss_relays_B.SFunction_l[5] -
    sel751test_model_1_3_ss_relays_B.SFunction_l[6];

  /* Sum: '<S48>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6_m =
    sel751test_model_1_3_ss_relays_B.SFunction_l[6] -
    sel751test_model_1_3_ss_relays_B.SFunction_l[4];

  /* Sum: '<S48>/Sum' */
  sel751test_model_1_3_ss_relays_B.Sum_d =
    sel751test_model_1_3_ss_relays_B.SFunction_l[4] -
    sel751test_model_1_3_ss_relays_B.SFunction_l[5];

  /* Product: '<S48>/Product3' */
  sel751test_model_1_3_ss_relays_B.Product3_g[0] =
    sel751test_model_1_3_ss_relays_B.Sum5 *
    sel751test_model_1_3_ss_relays_B.SFunction_l[1];
  sel751test_model_1_3_ss_relays_B.Product3_g[1] =
    sel751test_model_1_3_ss_relays_B.Sum6_m *
    sel751test_model_1_3_ss_relays_B.SFunction_l[2];
  sel751test_model_1_3_ss_relays_B.Product3_g[2] =
    sel751test_model_1_3_ss_relays_B.Sum_d *
    sel751test_model_1_3_ss_relays_B.SFunction_l[3];

  /* Sum: '<S48>/Sum1' */
  dsp2Pi = sel751test_model_1_3_ss_relays_B.Product3_g[0];
  dsp2Pi += sel751test_model_1_3_ss_relays_B.Product3_g[1];
  dsp2Pi += sel751test_model_1_3_ss_relays_B.Product3_g[2];
  sel751test_model_1_3_ss_relays_B.Sum1_c = dsp2Pi;

  /* Gain: '<S48>/pu->V' */
  sel751test_model_1_3_ss_relays_B.Q_b =
    sel751test_model_1_3_ss_relays_P.puV_Gain *
    sel751test_model_1_3_ss_relays_B.Sum1_c;

  /* DiscreteIntegrator: '<S49>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_k != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_c[0] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_i[0];
    sel751test_model_1_3_ss_relays_B.Integ4_c[1] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_i[1];
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_c[0] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_f3 *
      sel751test_model_1_3_ss_relays_B.P_i +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_i[0];
    sel751test_model_1_3_ss_relays_B.Integ4_c[1] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_f3 *
      sel751test_model_1_3_ss_relays_B.Q_b +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_i[1];
  }

  /* End of DiscreteIntegrator: '<S49>/Integ4' */
  /* S-Function block: <S50>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[0])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_c[0];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[1])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_c[1];

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_m/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_ek[0] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[0])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_ek[1] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[1])
      [indDelayed];
  }

  /* UnitDelay: '<S49>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_n[0] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_kt[0];
  sel751test_model_1_3_ss_relays_B.UnitDelay_n[1] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_kt[1];

  /* Step: '<S49>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_d) {
    sel751test_model_1_3_ss_relays_B.Step_l =
      sel751test_model_1_3_ss_relays_P.Step_Y0_e;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_l =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_a;
  }

  /* End of Step: '<S49>/Step' */

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_l >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_e) {
    /* Gain: '<S49>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_o[0] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_h *
      sel751test_model_1_3_ss_relays_B.UnitDelay_n[0];
    sel751test_model_1_3_ss_relays_B.Gain_o[1] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_h *
      sel751test_model_1_3_ss_relays_B.UnitDelay_n[1];

    /* Gain: '<S49>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_bh[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_m *
      sel751test_model_1_3_ss_relays_B.P_i;
    sel751test_model_1_3_ss_relays_B.Gain1_bh[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_m *
      sel751test_model_1_3_ss_relays_B.Q_b;

    /* Sum: '<S49>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_l[0] =
      sel751test_model_1_3_ss_relays_B.Gain1_bh[0] -
      sel751test_model_1_3_ss_relays_B.Gain_o[0];
    sel751test_model_1_3_ss_relays_B.Correction_l[1] =
      sel751test_model_1_3_ss_relays_B.Gain1_bh[1] -
      sel751test_model_1_3_ss_relays_B.Gain_o[1];

    /* Sum: '<S49>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_ji[0] =
      sel751test_model_1_3_ss_relays_B.Integ4_c[0] -
      sel751test_model_1_3_ss_relays_B.SFunction_ek[0];
    sel751test_model_1_3_ss_relays_B.Sum7_ji[1] =
      sel751test_model_1_3_ss_relays_B.Integ4_c[1] -
      sel751test_model_1_3_ss_relays_B.SFunction_ek[1];

    /* Product: '<S49>/Product' incorporates:
     *  Constant: '<S49>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_c4[0] =
      sel751test_model_1_3_ss_relays_B.Sum7_ji[0] *
      sel751test_model_1_3_ss_relays_P.K2_Value_b;
    sel751test_model_1_3_ss_relays_B.Meanvalue_c4[1] =
      sel751test_model_1_3_ss_relays_B.Sum7_ji[1] *
      sel751test_model_1_3_ss_relays_P.K2_Value_b;

    /* Sum: '<S49>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_m0[0] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_c4[0] +
      sel751test_model_1_3_ss_relays_B.Correction_l[0];
    sel751test_model_1_3_ss_relays_B.Sum5_m0[1] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_c4[1] +
      sel751test_model_1_3_ss_relays_B.Correction_l[1];
    sel751test_model_1_3_ss_relays_B.Switch_kt[0] =
      sel751test_model_1_3_ss_relays_B.Sum5_m0[0];
    sel751test_model_1_3_ss_relays_B.Switch_kt[1] =
      sel751test_model_1_3_ss_relays_B.Sum5_m0[1];
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_kt[0] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_h;
    sel751test_model_1_3_ss_relays_B.Switch_kt[1] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_h;
  }

  /* End of Switch: '<S49>/Switch' */

  /* Abs: '<S12>/Abs' */
  sel751test_model_1_3_ss_relays_B.Abs = fabs
    (sel751test_model_1_3_ss_relays_B.Switch_kt[0]);

  /* Abs: '<S12>/Abs1' */
  sel751test_model_1_3_ss_relays_B.Abs1 = fabs
    (sel751test_model_1_3_ss_relays_B.Switch_kt[1]);

  /* Abs: '<S12>/Abs2' */
  sel751test_model_1_3_ss_relays_B.Abs2 = fabs
    (sel751test_model_1_3_ss_relays_B.Switch_kt[0]);

  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Constant: '<S39>/Constant'
   */
  sel751test_model_1_3_ss_relays_B.Compare = (uint8_T)
    (sel751test_model_1_3_ss_relays_B.Abs2 >
     sel751test_model_1_3_ss_relays_P.Constant_Value_io);

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   */
  sel751test_model_1_3_ss_relays_B.Compare_c = (uint8_T)
    (sel751test_model_1_3_ss_relays_B.Abs1 >
     sel751test_model_1_3_ss_relays_P.Constant_Value_j);

  /* Fcn: '<S12>/Fcn' */
  u = sel751test_model_1_3_ss_relays_B.Switch_kt[1];
  dsp2Pi = rt_powd_snf(u, 2.0);
  u = sel751test_model_1_3_ss_relays_B.Switch_kt[0];
  u = rt_powd_snf(u, 2.0);
  dsp2Pi += u;
  if (dsp2Pi < 0.0) {
    dsp2Pi = -sqrt(-dsp2Pi);
  } else {
    dsp2Pi = sqrt(dsp2Pi);
  }

  sel751test_model_1_3_ss_relays_B.Fcn = dsp2Pi + 0.0001;

  /* End of Fcn: '<S12>/Fcn' */

  /* Product: '<S12>/Divide2' */
  sel751test_model_1_3_ss_relays_B.Divide2 =
    sel751test_model_1_3_ss_relays_B.Abs / sel751test_model_1_3_ss_relays_B.Fcn;

  /* RelationalOperator: '<S41>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   */
  sel751test_model_1_3_ss_relays_B.Compare_b =
    (sel751test_model_1_3_ss_relays_B.Switch_kt[0] >
     sel751test_model_1_3_ss_relays_P.Constant_Value_c);

  /* RelationalOperator: '<S42>/Compare' incorporates:
   *  Constant: '<S42>/Constant'
   */
  sel751test_model_1_3_ss_relays_B.Compare_h =
    (sel751test_model_1_3_ss_relays_B.Switch_kt[1] >
     sel751test_model_1_3_ss_relays_P.Constant_Value_k);

  /* Logic: '<S12>/Logical Operator' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator =
    ((sel751test_model_1_3_ss_relays_B.Compare_c != 0) &&
     (sel751test_model_1_3_ss_relays_B.Compare != 0));

  /* UnitDelay: '<S43>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1 =
    sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE;

  /* Switch: '<S43>/Enable' */
  if (sel751test_model_1_3_ss_relays_B.LogicalOperator) {
    sel751test_model_1_3_ss_relays_B.Xnew =
      sel751test_model_1_3_ss_relays_B.Divide2;
  } else {
    sel751test_model_1_3_ss_relays_B.Xnew =
      sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1;
  }

  /* End of Switch: '<S43>/Enable' */

  /* UnitDelay: '<S44>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_d =
    sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_n;

  /* Switch: '<S44>/Enable' */
  if (sel751test_model_1_3_ss_relays_B.LogicalOperator) {
    sel751test_model_1_3_ss_relays_B.Xnew_p =
      sel751test_model_1_3_ss_relays_B.Compare_b;
  } else {
    sel751test_model_1_3_ss_relays_B.Xnew_p =
      sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_d;
  }

  /* End of Switch: '<S44>/Enable' */

  /* UnitDelay: '<S45>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_p =
    sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_n0;

  /* Switch: '<S45>/Enable' */
  if (sel751test_model_1_3_ss_relays_B.LogicalOperator) {
    sel751test_model_1_3_ss_relays_B.Xnew_o =
      sel751test_model_1_3_ss_relays_B.Compare_h;
  } else {
    sel751test_model_1_3_ss_relays_B.Xnew_o =
      sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_p;
  }

  /* End of Switch: '<S45>/Enable' */

  /* DigitalClock: '<S5>/Digital Clock' */
  sel751test_model_1_3_ss_relays_B.DigitalClock =
    sel751test_model_1_3_ss_relays_M->Timing.t[0];

  /* RelationalOperator: '<S23>/Relational Operator' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  sel751test_model_1_3_ss_relays_B.RelationalOperator =
    (sel751test_model_1_3_ss_relays_B.DigitalClock >=
     sel751test_model_1_3_ss_relays_P.Constant2_Value);

  /* Level2 S-Function Block: '<S192>/S-Function' (RECV_Param) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Logic: '<S20>/Logical Operator1' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator1 =
    ((sel751test_model_1_3_ss_relays_B.SFunction_o[0] != 0.0) ||
     (sel751test_model_1_3_ss_relays_B.SFunction_o[1] != 0.0));

  /* UnitDelay: '<S99>/Delay Input1' */
  sel751test_model_1_3_ss_relays_B.Uk1_b =
    sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE_k;

  /* RelationalOperator: '<S99>/FixPt Relational Operator' */
  sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator = (uint8_T)
    (sel751test_model_1_3_ss_relays_B.LogicalOperator1 !=
     sel751test_model_1_3_ss_relays_B.Uk1_b);

  /* DataTypeConversion: '<S23>/Data Type Conversion3' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion3 =
    sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator;

  /* Product: '<S17>/Product3' */
  sel751test_model_1_3_ss_relays_B.Product3_c[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[1] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[1];
  sel751test_model_1_3_ss_relays_B.Product3_c[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[2] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[2];
  sel751test_model_1_3_ss_relays_B.Product3_c[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[3] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[3];

  /* DiscreteIntegrator: '<S51>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_d != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_ct[0] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[0];
    sel751test_model_1_3_ss_relays_B.Integ4_ct[1] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[1];
    sel751test_model_1_3_ss_relays_B.Integ4_ct[2] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[2];
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_ct[0] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_cf *
      sel751test_model_1_3_ss_relays_B.Product3_c[0] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[0];
    sel751test_model_1_3_ss_relays_B.Integ4_ct[1] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_cf *
      sel751test_model_1_3_ss_relays_B.Product3_c[1] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[1];
    sel751test_model_1_3_ss_relays_B.Integ4_ct[2] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_cf *
      sel751test_model_1_3_ss_relays_B.Product3_c[2] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[2];
  }

  /* End of DiscreteIntegrator: '<S51>/Integ4' */
  /* S-Function block: <S52>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[0])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_ct[0];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[1])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_ct[1];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[2])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_ct[2];

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_b/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_p[0] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[0])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_p[1] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[1])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_p[2] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[2])
      [indDelayed];
  }

  /* UnitDelay: '<S51>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_b[0] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_h[0];
  sel751test_model_1_3_ss_relays_B.UnitDelay_b[1] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_h[1];
  sel751test_model_1_3_ss_relays_B.UnitDelay_b[2] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_h[2];

  /* Step: '<S51>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_dt) {
    sel751test_model_1_3_ss_relays_B.Step_j =
      sel751test_model_1_3_ss_relays_P.Step_Y0_ih;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_j =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_i;
  }

  /* End of Step: '<S51>/Step' */

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_j >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_b2) {
    /* Gain: '<S51>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_g[0] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_m *
      sel751test_model_1_3_ss_relays_B.UnitDelay_b[0];
    sel751test_model_1_3_ss_relays_B.Gain_g[1] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_m *
      sel751test_model_1_3_ss_relays_B.UnitDelay_b[1];
    sel751test_model_1_3_ss_relays_B.Gain_g[2] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_m *
      sel751test_model_1_3_ss_relays_B.UnitDelay_b[2];

    /* Gain: '<S51>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_o2[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_o *
      sel751test_model_1_3_ss_relays_B.Product3_c[0];
    sel751test_model_1_3_ss_relays_B.Gain1_o2[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_o *
      sel751test_model_1_3_ss_relays_B.Product3_c[1];
    sel751test_model_1_3_ss_relays_B.Gain1_o2[2] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_o *
      sel751test_model_1_3_ss_relays_B.Product3_c[2];

    /* Sum: '<S51>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_b[0] =
      sel751test_model_1_3_ss_relays_B.Gain1_o2[0] -
      sel751test_model_1_3_ss_relays_B.Gain_g[0];
    sel751test_model_1_3_ss_relays_B.Correction_b[1] =
      sel751test_model_1_3_ss_relays_B.Gain1_o2[1] -
      sel751test_model_1_3_ss_relays_B.Gain_g[1];
    sel751test_model_1_3_ss_relays_B.Correction_b[2] =
      sel751test_model_1_3_ss_relays_B.Gain1_o2[2] -
      sel751test_model_1_3_ss_relays_B.Gain_g[2];

    /* Sum: '<S51>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_c[0] =
      sel751test_model_1_3_ss_relays_B.Integ4_ct[0] -
      sel751test_model_1_3_ss_relays_B.SFunction_p[0];
    sel751test_model_1_3_ss_relays_B.Sum7_c[1] =
      sel751test_model_1_3_ss_relays_B.Integ4_ct[1] -
      sel751test_model_1_3_ss_relays_B.SFunction_p[1];
    sel751test_model_1_3_ss_relays_B.Sum7_c[2] =
      sel751test_model_1_3_ss_relays_B.Integ4_ct[2] -
      sel751test_model_1_3_ss_relays_B.SFunction_p[2];

    /* Product: '<S51>/Product' incorporates:
     *  Constant: '<S51>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_os[0] =
      sel751test_model_1_3_ss_relays_B.Sum7_c[0] *
      sel751test_model_1_3_ss_relays_P.K2_Value_g;
    sel751test_model_1_3_ss_relays_B.Meanvalue_os[1] =
      sel751test_model_1_3_ss_relays_B.Sum7_c[1] *
      sel751test_model_1_3_ss_relays_P.K2_Value_g;
    sel751test_model_1_3_ss_relays_B.Meanvalue_os[2] =
      sel751test_model_1_3_ss_relays_B.Sum7_c[2] *
      sel751test_model_1_3_ss_relays_P.K2_Value_g;

    /* Sum: '<S51>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_ec[0] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_os[0] +
      sel751test_model_1_3_ss_relays_B.Correction_b[0];
    sel751test_model_1_3_ss_relays_B.Sum5_ec[1] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_os[1] +
      sel751test_model_1_3_ss_relays_B.Correction_b[1];
    sel751test_model_1_3_ss_relays_B.Sum5_ec[2] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_os[2] +
      sel751test_model_1_3_ss_relays_B.Correction_b[2];
    sel751test_model_1_3_ss_relays_B.Switch_i[0] =
      sel751test_model_1_3_ss_relays_B.Sum5_ec[0];
    sel751test_model_1_3_ss_relays_B.Switch_i[1] =
      sel751test_model_1_3_ss_relays_B.Sum5_ec[1];
    sel751test_model_1_3_ss_relays_B.Switch_i[2] =
      sel751test_model_1_3_ss_relays_B.Sum5_ec[2];
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_i[0] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_b;
    sel751test_model_1_3_ss_relays_B.Switch_i[1] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_b;
    sel751test_model_1_3_ss_relays_B.Switch_i[2] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_b;
  }

  /* End of Switch: '<S51>/Switch' */

  /* Sqrt: '<S17>/Signed Sqrt' */
  sel751test_model_1_3_ss_relays_B.SignedSqrt[0] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_i[0]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt[1] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_i[1]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt[2] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_i[2]);

  /* Product: '<S18>/Product3' */
  sel751test_model_1_3_ss_relays_B.Product3_h[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[4] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[4];
  sel751test_model_1_3_ss_relays_B.Product3_h[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[5] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[5];
  sel751test_model_1_3_ss_relays_B.Product3_h[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[6] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[6];

  /* DiscreteIntegrator: '<S53>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_b != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_d[0] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[0];
    sel751test_model_1_3_ss_relays_B.Integ4_d[1] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[1];
    sel751test_model_1_3_ss_relays_B.Integ4_d[2] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[2];
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_d[0] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_b *
      sel751test_model_1_3_ss_relays_B.Product3_h[0] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[0];
    sel751test_model_1_3_ss_relays_B.Integ4_d[1] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_b *
      sel751test_model_1_3_ss_relays_B.Product3_h[1] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[1];
    sel751test_model_1_3_ss_relays_B.Integ4_d[2] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_b *
      sel751test_model_1_3_ss_relays_B.Product3_h[2] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[2];
  }

  /* End of DiscreteIntegrator: '<S53>/Integ4' */
  /* S-Function block: <S54>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[0])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_d[0];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[1])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_d[1];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[2])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_d[2];

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_d5/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_b[0] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[0])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_b[1] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[1])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_b[2] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[2])
      [indDelayed];
  }

  /* UnitDelay: '<S53>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_cs[0] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_d[0];
  sel751test_model_1_3_ss_relays_B.UnitDelay_cs[1] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_d[1];
  sel751test_model_1_3_ss_relays_B.UnitDelay_cs[2] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_d[2];

  /* Step: '<S53>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_pt) {
    sel751test_model_1_3_ss_relays_B.Step_k =
      sel751test_model_1_3_ss_relays_P.Step_Y0_de;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_k =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_k;
  }

  /* End of Step: '<S53>/Step' */

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S53>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_k >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_e1) {
    /* Gain: '<S53>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_pg[0] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_o *
      sel751test_model_1_3_ss_relays_B.UnitDelay_cs[0];
    sel751test_model_1_3_ss_relays_B.Gain_pg[1] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_o *
      sel751test_model_1_3_ss_relays_B.UnitDelay_cs[1];
    sel751test_model_1_3_ss_relays_B.Gain_pg[2] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_o *
      sel751test_model_1_3_ss_relays_B.UnitDelay_cs[2];

    /* Gain: '<S53>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_jr[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_l *
      sel751test_model_1_3_ss_relays_B.Product3_h[0];
    sel751test_model_1_3_ss_relays_B.Gain1_jr[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_l *
      sel751test_model_1_3_ss_relays_B.Product3_h[1];
    sel751test_model_1_3_ss_relays_B.Gain1_jr[2] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_l *
      sel751test_model_1_3_ss_relays_B.Product3_h[2];

    /* Sum: '<S53>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_g[0] =
      sel751test_model_1_3_ss_relays_B.Gain1_jr[0] -
      sel751test_model_1_3_ss_relays_B.Gain_pg[0];
    sel751test_model_1_3_ss_relays_B.Correction_g[1] =
      sel751test_model_1_3_ss_relays_B.Gain1_jr[1] -
      sel751test_model_1_3_ss_relays_B.Gain_pg[1];
    sel751test_model_1_3_ss_relays_B.Correction_g[2] =
      sel751test_model_1_3_ss_relays_B.Gain1_jr[2] -
      sel751test_model_1_3_ss_relays_B.Gain_pg[2];

    /* Sum: '<S53>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_o[0] =
      sel751test_model_1_3_ss_relays_B.Integ4_d[0] -
      sel751test_model_1_3_ss_relays_B.SFunction_b[0];
    sel751test_model_1_3_ss_relays_B.Sum7_o[1] =
      sel751test_model_1_3_ss_relays_B.Integ4_d[1] -
      sel751test_model_1_3_ss_relays_B.SFunction_b[1];
    sel751test_model_1_3_ss_relays_B.Sum7_o[2] =
      sel751test_model_1_3_ss_relays_B.Integ4_d[2] -
      sel751test_model_1_3_ss_relays_B.SFunction_b[2];

    /* Product: '<S53>/Product' incorporates:
     *  Constant: '<S53>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_du[0] =
      sel751test_model_1_3_ss_relays_B.Sum7_o[0] *
      sel751test_model_1_3_ss_relays_P.K2_Value_d;
    sel751test_model_1_3_ss_relays_B.Meanvalue_du[1] =
      sel751test_model_1_3_ss_relays_B.Sum7_o[1] *
      sel751test_model_1_3_ss_relays_P.K2_Value_d;
    sel751test_model_1_3_ss_relays_B.Meanvalue_du[2] =
      sel751test_model_1_3_ss_relays_B.Sum7_o[2] *
      sel751test_model_1_3_ss_relays_P.K2_Value_d;

    /* Sum: '<S53>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_ba[0] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_du[0] +
      sel751test_model_1_3_ss_relays_B.Correction_g[0];
    sel751test_model_1_3_ss_relays_B.Sum5_ba[1] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_du[1] +
      sel751test_model_1_3_ss_relays_B.Correction_g[1];
    sel751test_model_1_3_ss_relays_B.Sum5_ba[2] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_du[2] +
      sel751test_model_1_3_ss_relays_B.Correction_g[2];
    sel751test_model_1_3_ss_relays_B.Switch_e[0] =
      sel751test_model_1_3_ss_relays_B.Sum5_ba[0];
    sel751test_model_1_3_ss_relays_B.Switch_e[1] =
      sel751test_model_1_3_ss_relays_B.Sum5_ba[1];
    sel751test_model_1_3_ss_relays_B.Switch_e[2] =
      sel751test_model_1_3_ss_relays_B.Sum5_ba[2];
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_e[0] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_dm;
    sel751test_model_1_3_ss_relays_B.Switch_e[1] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_dm;
    sel751test_model_1_3_ss_relays_B.Switch_e[2] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_dm;
  }

  /* End of Switch: '<S53>/Switch' */

  /* Sqrt: '<S18>/Signed Sqrt' */
  sel751test_model_1_3_ss_relays_B.SignedSqrt_k[0] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_e[0]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt_k[1] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_e[1]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt_k[2] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_e[2]);

  /* Gain: '<S23>/Gain' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Gain =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_b *
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[1];

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/group#1 - gridtied parameters'
   *  Constant: '<S20>/group#2 - islanded parameters'
   */
  if (sel751test_model_1_3_ss_relays_B.SFunction_o[2] >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_m) {
    for (i = 0; i < 7; i++) {
      sel751test_model_1_3_ss_relays_B.Switch_a[i] =
        sel751test_model_1_3_ss_relays_P.group2islandedparameters_Value[i];
    }
  } else {
    for (i = 0; i < 7; i++) {
      sel751test_model_1_3_ss_relays_B.Switch_a[i] =
        sel751test_model_1_3_ss_relays_P.group1gridtiedparameters_Value[i];
    }
  }

  /* End of Switch: '<S20>/Switch' */

  /* MATLAB Function: '<S23>/Relays' incorporates:
   *  Constant: '<S20>/base parameters'
   *  Constant: '<S23>/a4'
   */
  sel751test_model_1_3_ss__Relays
    (sel751test_model_1_3_ss_relays_B.RelationalOperator,
     sel751test_model_1_3_ss_relays_P.a4_Value,
     sel751test_model_1_3_ss_relays_B.DataTypeConversion3,
     &sel751test_model_1_3_ss_relays_B.SFunction_l[1],
     sel751test_model_1_3_ss_relays_B.SignedSqrt,
     sel751test_model_1_3_ss_relays_B.SignedSqrt_k,
     sel751test_model_1_3_ss_relays_B.Gain,
     sel751test_model_1_3_ss_relays_P.baseparameters_Value[6],
     sel751test_model_1_3_ss_relays_B.Switch_a[0],
     sel751test_model_1_3_ss_relays_B.Switch_a[1],
     sel751test_model_1_3_ss_relays_B.Switch_a[2],
     sel751test_model_1_3_ss_relays_B.Switch_a[3],
     sel751test_model_1_3_ss_relays_B.Switch_a[4],
     sel751test_model_1_3_ss_relays_B.Switch_a[5],
     sel751test_model_1_3_ss_relays_B.Switch_a[6],
     sel751test_model_1_3_ss_relays_P.baseparameters_Value[5],
     &sel751test_model_1_3_ss_relays_B.sf_Relays,
     &sel751test_model_1_3_ss_relays_DW.sf_Relays);

  /* Logic: '<S5>/Logical Operator4' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator4 =
    (sel751test_model_1_3_ss_relays_B.sf_Relays.trip50 ||
     sel751test_model_1_3_ss_relays_B.sf_Relays.trip51 ||
     sel751test_model_1_3_ss_relays_B.sf_Relays.trip27 ||
     sel751test_model_1_3_ss_relays_B.sf_Relays.trip59);

  /* Logic: '<S5>/Logical Operator' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator_f =
    !sel751test_model_1_3_ss_relays_B.LogicalOperator4;

  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  sel751test_model_1_3_ss_relays_B.trip_in =
    sel751test_model_1_3_ss_relays_B.LogicalOperator_f;

  /* DataTypeConversion: '<S5>/Data Type Conversion2' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion2 =
    sel751test_model_1_3_ss_relays_B.Logic_trip;

  /* DataTypeConversion: '<S5>/Data Type Conversion3' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion3_j[0] =
    sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_d;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion3_j[1] =
    sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_p;

  /* DataTypeConversion: '<S5>/Data Type Conversion4' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion4[0] =
    sel751test_model_1_3_ss_relays_B.sf_Relays.trip50;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion4[1] =
    sel751test_model_1_3_ss_relays_B.sf_Relays.trip51;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion4[2] =
    sel751test_model_1_3_ss_relays_B.sf_Relays.trip27;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion4[3] =
    sel751test_model_1_3_ss_relays_B.sf_Relays.trip59;

  /* DataTypeConversion: '<S5>/Data Type Conversion5' */
  sel751test_model_1_3_ss_relays_B.reset =
    (sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator != 0);

  /* DataTypeConversion: '<S5>/Data Type Conversion6' */
  sel751test_model_1_3_ss_relays_B.Status =
    (sel751test_model_1_3_ss_relays_B.Logic_trip != 0.0);

  /* Gain: '<S5>/Gain2' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Gain2 =
    sel751test_model_1_3_ss_relays_P.Gain2_Gain *
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[1];

  /* Product: '<S5>/Divide2' */
  sel751test_model_1_3_ss_relays_B.Vpu_hv =
    sel751test_model_1_3_ss_relays_B.SignedSqrt_k[0] /
    sel751test_model_1_3_ss_relays_B.Gain2;

  /* Gain: '<S5>/Gain' */
  sel751test_model_1_3_ss_relays_B.Gain_p =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_a *
    sel751test_model_1_3_ss_relays_B.DataTypeConversion4[1];

  /* Gain: '<S5>/Gain1' */
  sel751test_model_1_3_ss_relays_B.Gain1_a =
    sel751test_model_1_3_ss_relays_P.Gain1_Gain_dm *
    sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1;

  /* Gain: '<S5>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10_k =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain_p *
    sel751test_model_1_3_ss_relays_B.Switch_kt[0];

  /* Sum: '<S16>/Add2' incorporates:
   *  Constant: '<S16>/Constant5'
   */
  sel751test_model_1_3_ss_relays_B.Add2 =
    sel751test_model_1_3_ss_relays_B.MathFunction_i -
    sel751test_model_1_3_ss_relays_P.Constant5_Value;

  /* Math: '<S16>/Math Function' incorporates:
   *  Constant: '<S16>/Constant7'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_e = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.Add2,
     sel751test_model_1_3_ss_relays_P.Constant7_Value);

  /* Gain: '<S5>/Gain11' */
  sel751test_model_1_3_ss_relays_B.Gain11 =
    sel751test_model_1_3_ss_relays_P.Gain11_Gain *
    sel751test_model_1_3_ss_relays_B.MathFunction_e;

  /* Gain: '<S5>/Gain12' */
  sel751test_model_1_3_ss_relays_B.Gain12 =
    sel751test_model_1_3_ss_relays_P.Gain12_Gain *
    sel751test_model_1_3_ss_relays_B.MathFunction_i;

  /* Gain: '<S5>/Gain13' */
  sel751test_model_1_3_ss_relays_B.Gain13 =
    sel751test_model_1_3_ss_relays_P.Gain13_Gain *
    sel751test_model_1_3_ss_relays_B.DataTypeConversion4[3];

  /* Gain: '<S5>/Gain14' */
  sel751test_model_1_3_ss_relays_B.Gain14 =
    sel751test_model_1_3_ss_relays_P.Gain14_Gain *
    sel751test_model_1_3_ss_relays_B.DataTypeConversion2;

  /* Gain: '<S5>/Gain15' */
  sel751test_model_1_3_ss_relays_B.Gain15 =
    sel751test_model_1_3_ss_relays_P.Gain15_Gain *
    sel751test_model_1_3_ss_relays_B.SignedSqrt[0];

  /* Gain: '<S5>/Gain16' */
  sel751test_model_1_3_ss_relays_B.Gain16 =
    sel751test_model_1_3_ss_relays_P.Gain16_Gain *
    sel751test_model_1_3_ss_relays_B.SignedSqrt[1];

  /* Gain: '<S5>/Gain17' */
  sel751test_model_1_3_ss_relays_B.Gain17 =
    sel751test_model_1_3_ss_relays_P.Gain17_Gain *
    sel751test_model_1_3_ss_relays_B.SignedSqrt[2];

  /* Gain: '<S5>/Gain18' */
  sel751test_model_1_3_ss_relays_B.Gain18 =
    sel751test_model_1_3_ss_relays_P.Gain18_Gain *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_k[0];

  /* Gain: '<S5>/Gain19' */
  sel751test_model_1_3_ss_relays_B.Gain19 =
    sel751test_model_1_3_ss_relays_P.Gain19_Gain *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_k[1];

  /* Gain: '<S5>/Gain20' */
  sel751test_model_1_3_ss_relays_B.Gain20 =
    sel751test_model_1_3_ss_relays_P.Gain20_Gain *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_k[2];

  /* Sum: '<S15>/Add3' incorporates:
   *  Constant: '<S15>/Constant6'
   */
  sel751test_model_1_3_ss_relays_B.Add3 =
    sel751test_model_1_3_ss_relays_B.MathFunction +
    sel751test_model_1_3_ss_relays_P.Constant6_Value;

  /* Math: '<S15>/Math Function1' incorporates:
   *  Constant: '<S15>/Constant8'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction1 = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.Add3,
     sel751test_model_1_3_ss_relays_P.Constant8_Value);

  /* Gain: '<S5>/Gain3' */
  sel751test_model_1_3_ss_relays_B.Gain3 =
    sel751test_model_1_3_ss_relays_P.Gain3_Gain *
    sel751test_model_1_3_ss_relays_B.MathFunction1;

  /* Gain: '<S5>/Gain4' */
  sel751test_model_1_3_ss_relays_B.Gain4 =
    sel751test_model_1_3_ss_relays_P.Gain4_Gain *
    sel751test_model_1_3_ss_relays_B.UnitDelay_e;

  /* Sum: '<S15>/Add2' incorporates:
   *  Constant: '<S15>/Constant5'
   */
  sel751test_model_1_3_ss_relays_B.Add2_h =
    sel751test_model_1_3_ss_relays_B.MathFunction -
    sel751test_model_1_3_ss_relays_P.Constant5_Value_b;

  /* Math: '<S15>/Math Function' incorporates:
   *  Constant: '<S15>/Constant7'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_g = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.Add2_h,
     sel751test_model_1_3_ss_relays_P.Constant7_Value_b);

  /* Gain: '<S5>/Gain5' */
  sel751test_model_1_3_ss_relays_B.Gain5 =
    sel751test_model_1_3_ss_relays_P.Gain5_Gain *
    sel751test_model_1_3_ss_relays_B.MathFunction_g;

  /* Gain: '<S5>/Gain6' */
  sel751test_model_1_3_ss_relays_B.Gain6 =
    sel751test_model_1_3_ss_relays_P.Gain6_Gain *
    sel751test_model_1_3_ss_relays_B.Switch_kt[1];

  /* Gain: '<S5>/Gain7' */
  sel751test_model_1_3_ss_relays_B.Gain7 =
    sel751test_model_1_3_ss_relays_P.Gain7_Gain *
    sel751test_model_1_3_ss_relays_B.Fcn;

  /* Gain: '<S5>/Gain8' */
  sel751test_model_1_3_ss_relays_B.Gain8 =
    sel751test_model_1_3_ss_relays_P.Gain8_Gain *
    sel751test_model_1_3_ss_relays_B.MathFunction;

  /* Sum: '<S16>/Add3' incorporates:
   *  Constant: '<S16>/Constant6'
   */
  sel751test_model_1_3_ss_relays_B.Add3_h =
    sel751test_model_1_3_ss_relays_B.MathFunction_i +
    sel751test_model_1_3_ss_relays_P.Constant6_Value_h;

  /* Math: '<S16>/Math Function1' incorporates:
   *  Constant: '<S16>/Constant8'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction1_g = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.Add3_h,
     sel751test_model_1_3_ss_relays_P.Constant8_Value_l);

  /* Gain: '<S5>/Gain9' */
  sel751test_model_1_3_ss_relays_B.Gain9 =
    sel751test_model_1_3_ss_relays_P.Gain9_Gain *
    sel751test_model_1_3_ss_relays_B.MathFunction1_g;

  /* DataTypeConversion: '<S13>/Data Type Conversion1' incorporates:
   *  Constant: '<S13>/never_reset'
   */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion1_a =
    (sel751test_model_1_3_ss_relays_P.never_reset_Value != 0.0);

  /* UnitDelay: '<S46>/Delay Input1' */
  sel751test_model_1_3_ss_relays_B.Uk1_a =
    sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE;

  /* RelationalOperator: '<S46>/FixPt Relational Operator' */
  sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator_e =
    (sel751test_model_1_3_ss_relays_B.SFunction_o[1] !=
     sel751test_model_1_3_ss_relays_B.Uk1_a);

  /* Memory: '<S47>/Memory' */
  sel751test_model_1_3_ss_relays_B.Memory =
    sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput;

  /* CombinatorialLogic: '<S47>/Logic' */
  unnamed_idx = sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator_e;
  i = unnamed_idx;
  unnamed_idx = sel751test_model_1_3_ss_relays_B.DataTypeConversion1_a;
  i = (int32_T)(((uint32_T)i << 1) + unnamed_idx);
  unnamed_idx = sel751test_model_1_3_ss_relays_B.Memory;
  i = (int32_T)(((uint32_T)i << 1) + unnamed_idx);
  sel751test_model_1_3_ss_relays_B.Logic[0U] =
    sel751test_model_1_3_ss_relays_P.Logic_table[(uint32_T)i];
  sel751test_model_1_3_ss_relays_B.Logic[1U] =
    sel751test_model_1_3_ss_relays_P.Logic_table[i + 8U];

  /* Product: '<S57>/Product3' */
  sel751test_model_1_3_ss_relays_B.Product3_oh[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[4] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[4];
  sel751test_model_1_3_ss_relays_B.Product3_oh[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[7] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[7];

  /* DiscreteIntegrator: '<S63>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_e != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_m[0] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_id[0];
    sel751test_model_1_3_ss_relays_B.Integ4_m[1] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_id[1];
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_m[0] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_me *
      sel751test_model_1_3_ss_relays_B.Product3_oh[0] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_id[0];
    sel751test_model_1_3_ss_relays_B.Integ4_m[1] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_me *
      sel751test_model_1_3_ss_relays_B.Product3_oh[1] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_id[1];
  }

  /* End of DiscreteIntegrator: '<S63>/Integ4' */
  /* S-Function block: <S64>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers[0])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_m[0];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers[1])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_m[1];

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_j/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_i[0] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers[0])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_i[1] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers[1])
      [indDelayed];
  }

  /* UnitDelay: '<S63>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_g[0] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_m[0];
  sel751test_model_1_3_ss_relays_B.UnitDelay_g[1] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_m[1];

  /* Step: '<S63>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_p0) {
    sel751test_model_1_3_ss_relays_B.Step_g =
      sel751test_model_1_3_ss_relays_P.Step_Y0_o;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_g =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_ii;
  }

  /* End of Step: '<S63>/Step' */

  /* Switch: '<S63>/Switch' incorporates:
   *  Constant: '<S63>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_g >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_et) {
    /* Gain: '<S63>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_j[0] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_oj *
      sel751test_model_1_3_ss_relays_B.UnitDelay_g[0];
    sel751test_model_1_3_ss_relays_B.Gain_j[1] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_oj *
      sel751test_model_1_3_ss_relays_B.UnitDelay_g[1];

    /* Gain: '<S63>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_lq[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_c *
      sel751test_model_1_3_ss_relays_B.Product3_oh[0];
    sel751test_model_1_3_ss_relays_B.Gain1_lq[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_c *
      sel751test_model_1_3_ss_relays_B.Product3_oh[1];

    /* Sum: '<S63>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_i[0] =
      sel751test_model_1_3_ss_relays_B.Gain1_lq[0] -
      sel751test_model_1_3_ss_relays_B.Gain_j[0];
    sel751test_model_1_3_ss_relays_B.Correction_i[1] =
      sel751test_model_1_3_ss_relays_B.Gain1_lq[1] -
      sel751test_model_1_3_ss_relays_B.Gain_j[1];

    /* Sum: '<S63>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_d[0] =
      sel751test_model_1_3_ss_relays_B.Integ4_m[0] -
      sel751test_model_1_3_ss_relays_B.SFunction_i[0];
    sel751test_model_1_3_ss_relays_B.Sum7_d[1] =
      sel751test_model_1_3_ss_relays_B.Integ4_m[1] -
      sel751test_model_1_3_ss_relays_B.SFunction_i[1];

    /* Product: '<S63>/Product' incorporates:
     *  Constant: '<S63>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_cy[0] =
      sel751test_model_1_3_ss_relays_B.Sum7_d[0] *
      sel751test_model_1_3_ss_relays_P.K2_Value_k;
    sel751test_model_1_3_ss_relays_B.Meanvalue_cy[1] =
      sel751test_model_1_3_ss_relays_B.Sum7_d[1] *
      sel751test_model_1_3_ss_relays_P.K2_Value_k;

    /* Sum: '<S63>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_an[0] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_cy[0] +
      sel751test_model_1_3_ss_relays_B.Correction_i[0];
    sel751test_model_1_3_ss_relays_B.Sum5_an[1] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_cy[1] +
      sel751test_model_1_3_ss_relays_B.Correction_i[1];
    sel751test_model_1_3_ss_relays_B.Switch_p[0] =
      sel751test_model_1_3_ss_relays_B.Sum5_an[0];
    sel751test_model_1_3_ss_relays_B.Switch_p[1] =
      sel751test_model_1_3_ss_relays_B.Sum5_an[1];
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_p[0] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_n;
    sel751test_model_1_3_ss_relays_B.Switch_p[1] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_n;
  }

  /* End of Switch: '<S63>/Switch' */

  /* Sqrt: '<S57>/Signed Sqrt' */
  sel751test_model_1_3_ss_relays_B.SignedSqrt_a[0] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_p[0]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt_a[1] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_p[1]);

  /* Gain: '<S19>/sqrt3' */
  sel751test_model_1_3_ss_relays_B.sqrt3[0] =
    sel751test_model_1_3_ss_relays_P.sqrt3_Gain *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_a[0];
  sel751test_model_1_3_ss_relays_B.sqrt3[1] =
    sel751test_model_1_3_ss_relays_P.sqrt3_Gain *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_a[1];

  /* MATLAB Function: '<S19>/deadbus fcn' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_deadbusfcn(sel751test_model_1_3_ss_relays_B.sqrt3[0],
    sel751test_model_1_3_ss_relays_B.sqrt3[1],
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[1],
    &sel751test_model_1_3_ss_relays_B.sf_deadbusfcn);

  /* Fcn: '<S19>/Fcn' */
  sel751test_model_1_3_ss_relays_B.Fcn_e =
    (sel751test_model_1_3_ss_relays_B.SFunction_o[1] == 2.0);

  /* Product: '<S59>/Product' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Product_k =
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[1] *
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[2];

  /* Fcn: '<S59>/Fcn2' */
  sel751test_model_1_3_ss_relays_B.thshld = (fabs
    (sel751test_model_1_3_ss_relays_B.sqrt3[1] -
     sel751test_model_1_3_ss_relays_B.sqrt3[0]) <=
    sel751test_model_1_3_ss_relays_B.Product_k);

  /* UnitDelay: '<S66>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_jh =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_j;

  /* UnitDelay: '<S65>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_d =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ez;

  /* Fcn: '<S55>/Fcn2' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Fcn2 = (fabs
    (sel751test_model_1_3_ss_relays_B.UnitDelay_d -
     sel751test_model_1_3_ss_relays_B.UnitDelay_jh) <=
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[4]);

  /* DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_f =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_h;

  /* Math: '<S66>/Math Function' incorporates:
   *  Constant: '<S66>/Constant4'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_p = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_f,
     sel751test_model_1_3_ss_relays_P.Constant4_Value_d);

  /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_o =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_o;

  /* Math: '<S65>/Math Function' incorporates:
   *  Constant: '<S65>/Constant4'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_d = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_o,
     sel751test_model_1_3_ss_relays_P.Constant4_Value_e);

  /* SignalConversion: '<S56>/TmpSignal ConversionAtMath FunctionInport1' */
  sel751test_model_1_3_ss_relays_B.TmpSignalConversionAtMathFuncti[0] =
    sel751test_model_1_3_ss_relays_B.MathFunction_p;
  sel751test_model_1_3_ss_relays_B.TmpSignalConversionAtMathFuncti[1] =
    sel751test_model_1_3_ss_relays_B.MathFunction_d;

  /* Math: '<S56>/Math Function' incorporates:
   *  Constant: '<S56>/Constant3'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_n[0] = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.TmpSignalConversionAtMathFuncti[0],
     sel751test_model_1_3_ss_relays_P.Constant3_Value);
  sel751test_model_1_3_ss_relays_B.MathFunction_n[1] = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.TmpSignalConversionAtMathFuncti[1],
     sel751test_model_1_3_ss_relays_P.Constant3_Value);

  /* S-Function (sdspunwrap2): '<S56>/Unwrap' */
  if (sel751test_model_1_3_ss_relays_DW.Unwrap_FirstStep) {
    sel751test_model_1_3_ss_relays_DW.Unwrap_Prev =
      sel751test_model_1_3_ss_relays_B.MathFunction_n[0];
    sel751test_model_1_3_ss_relays_DW.Unwrap_FirstStep = FALSE;
  }

  u_0 = sel751test_model_1_3_ss_relays_DW.Unwrap_Cumsum;
  dsp2Pi = sel751test_model_1_3_ss_relays_DW.Unwrap_Prev;
  dp = sel751test_model_1_3_ss_relays_B.MathFunction_n[0] - dsp2Pi;
  u = (dp + 3.1415926535897931) / 6.2831853071795862;
  u = floor(u);
  dsp2Pi = dp - 6.2831853071795862 * u;
  if ((dsp2Pi == -3.1415926535897931) && (dp > 0.0)) {
    dsp2Pi = 3.1415926535897931;
  }

  dsp2Pi -= dp;
  if (fabs(dsp2Pi) > sel751test_model_1_3_ss_relays_ConstP.pooled1) {
    u_0 += dsp2Pi;
  }

  dsp2Pi = sel751test_model_1_3_ss_relays_B.MathFunction_n[0];
  sel751test_model_1_3_ss_relays_B.Unwrap[0] =
    sel751test_model_1_3_ss_relays_B.MathFunction_n[0] + u_0;
  dp = sel751test_model_1_3_ss_relays_B.MathFunction_n[1] - dsp2Pi;
  u = (dp + 3.1415926535897931) / 6.2831853071795862;
  u = floor(u);
  dsp2Pi = dp - 6.2831853071795862 * u;
  if ((dsp2Pi == -3.1415926535897931) && (dp > 0.0)) {
    dsp2Pi = 3.1415926535897931;
  }

  dsp2Pi -= dp;
  if (fabs(dsp2Pi) > sel751test_model_1_3_ss_relays_ConstP.pooled1) {
    u_0 += dsp2Pi;
  }

  dsp2Pi = sel751test_model_1_3_ss_relays_B.MathFunction_n[1];
  sel751test_model_1_3_ss_relays_B.Unwrap[1] =
    sel751test_model_1_3_ss_relays_B.MathFunction_n[1] + u_0;
  sel751test_model_1_3_ss_relays_DW.Unwrap_Prev = dsp2Pi;
  sel751test_model_1_3_ss_relays_DW.Unwrap_Cumsum = u_0;

  /* End of S-Function (sdspunwrap2): '<S56>/Unwrap' */

  /* Fcn: '<S56>/Fcn3' */
  sel751test_model_1_3_ss_relays_B.diff = fabs
    (sel751test_model_1_3_ss_relays_B.Unwrap[1] -
     sel751test_model_1_3_ss_relays_B.Unwrap[0]);

  /* Gain: '<S62>/Gain' */
  sel751test_model_1_3_ss_relays_B.Gain_a =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_bc *
    sel751test_model_1_3_ss_relays_B.diff;

  /* Fcn: '<S56>/Fcn1' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.bool_k =
    (sel751test_model_1_3_ss_relays_B.Gain_a <=
     sel751test_model_1_3_ss_relays_P.baseparameters_Value[3]);

  /* Logic: '<S19>/Logical Operator' */
  sel751test_model_1_3_ss_relays_B.dVdFdW =
    ((sel751test_model_1_3_ss_relays_B.thshld != 0.0) &&
     (sel751test_model_1_3_ss_relays_B.Fcn2 != 0.0) &&
     (sel751test_model_1_3_ss_relays_B.bool_k != 0.0));

  /* Logic: '<S19>/Logical Operator1' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator1_b =
    (sel751test_model_1_3_ss_relays_B.LogicalOperator4 ||
     (sel751test_model_1_3_ss_relays_B.Fcn_e != 0.0) ||
     sel751test_model_1_3_ss_relays_B.dVdFdW);

  /* Memory: '<S58>/Memory' */
  sel751test_model_1_3_ss_relays_B.Memory_m =
    sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput_o;

  /* CombinatorialLogic: '<S58>/Logic' */
  unnamed_idx = sel751test_model_1_3_ss_relays_B.sf_deadbusfcn.y;
  i = unnamed_idx;
  unnamed_idx = sel751test_model_1_3_ss_relays_B.LogicalOperator1_b;
  i = (int32_T)(((uint32_T)i << 1) + unnamed_idx);
  unnamed_idx = sel751test_model_1_3_ss_relays_B.Memory_m;
  i = (int32_T)(((uint32_T)i << 1) + unnamed_idx);
  sel751test_model_1_3_ss_relays_B.Logic_a[0U] =
    sel751test_model_1_3_ss_relays_P.Logic_table_n[(uint32_T)i];
  sel751test_model_1_3_ss_relays_B.Logic_a[1U] =
    sel751test_model_1_3_ss_relays_P.Logic_table_n[i + 8U];

  /* Logic: '<S19>/Logical Operator3' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator3 =
    (sel751test_model_1_3_ss_relays_B.Logic_a[0] ||
     sel751test_model_1_3_ss_relays_B.dVdFdW);

  /* MATLAB Function: '<S5>/trip_out mng' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant4'
   */
  sel751test_model_1__trip_outmng
    (sel751test_model_1_3_ss_relays_P.Constant4_Value_g,
     sel751test_model_1_3_ss_relays_B.LogicalOperator3,
     sel751test_model_1_3_ss_relays_B.SFunction_o[1],
     sel751test_model_1_3_ss_relays_B.trip_in,
     sel751test_model_1_3_ss_relays_P.Constant1_Value,
     sel751test_model_1_3_ss_relays_B.DigitalClock,
     sel751test_model_1_3_ss_relays_P.Constant2_Value,
     &sel751test_model_1_3_ss_relays_B.sf_trip_outmng,
     &sel751test_model_1_3_ss_relays_DW.sf_trip_outmng);

  /* Switch: '<S13>/Switch' */
  if (sel751test_model_1_3_ss_relays_B.Logic[0]) {
    sel751test_model_1_3_ss_relays_B.Logic_out =
      sel751test_model_1_3_ss_relays_B.sf_trip_outmng.trip_out;
  } else {
    /* Fcn: '<S13>/Fcn' incorporates:
     *  Constant: '<S20>/base parameters'
     */
    sel751test_model_1_3_ss_relays_B.Fcn_fz =
      (sel751test_model_1_3_ss_relays_P.baseparameters_Value[7] != 0.0);

    /* DataTypeConversion: '<S13>/Data Type Conversion' */
    sel751test_model_1_3_ss_relays_B.DataTypeConversion_i =
      sel751test_model_1_3_ss_relays_B.Fcn_fz;
    sel751test_model_1_3_ss_relays_B.Logic_out =
      sel751test_model_1_3_ss_relays_B.DataTypeConversion_i;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Memory: '<S5>/Memory2' */
  sel751test_model_1_3_ss_relays_B.Memory2 =
    sel751test_model_1_3_ss_relays_DW.Memory2_PreviousInput;

  /* Memory: '<S5>/Memory9' */
  sel751test_model_1_3_ss_relays_B.Memory9 =
    sel751test_model_1_3_ss_relays_DW.Memory9_PreviousInput;

  /* Product: '<S61>/Divide' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Divide_a =
    sel751test_model_1_3_ss_relays_B.SFunction_l[7] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[1];

  /* Trigonometry: '<S65>/Trigonometric Function2' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_o = cos
    (sel751test_model_1_3_ss_relays_B.MathFunction_d);

  /* Product: '<S65>/Product1' */
  sel751test_model_1_3_ss_relays_B.Vq_b =
    sel751test_model_1_3_ss_relays_B.Divide_a *
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_o;

  /* DiscreteIntegrator: '<S71>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_eh != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_e =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_m;
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_e =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_e *
      sel751test_model_1_3_ss_relays_B.Vq_b +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_m;
  }

  /* End of DiscreteIntegrator: '<S71>/Integ4' */

  /* Saturate: '<S71>/To avoid division by zero' */
  u = sel751test_model_1_3_ss_relays_B.UnitDelay_d;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerS_gb;
  u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperSa_g;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Freq = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Freq = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Freq = u;
  }

  /* End of Saturate: '<S71>/To avoid division by zero' */

  /* Fcn: '<S71>/Number of samples per cycle' */
  sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle = 1.0 /
    sel751test_model_1_3_ss_relays_B.Freq / 0.0001;

  /* Rounding: '<S71>/Rounding Function' */
  sel751test_model_1_3_ss_relays_B.RoundingFunction = ceil
    (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle);

  /* Gain: '<S71>/Gain' */
  sel751test_model_1_3_ss_relays_B.Delay =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_h2 *
    sel751test_model_1_3_ss_relays_B.RoundingFunction;

  /* S-Function block: <S82>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_g.uBuffers)
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_e;

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_j = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_g.uBuffers)[indDelayed];
  }

  /* UnitDelay: '<S81>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_o =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ed;

  /* Step: '<S71>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_ls) {
    sel751test_model_1_3_ss_relays_B.Step_p =
      sel751test_model_1_3_ss_relays_P.Step_Y0_c;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_p =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_g;
  }

  /* End of Step: '<S71>/Step' */

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S71>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_p >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_am) {
    /* Sum: '<S81>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Sum1_hp =
      sel751test_model_1_3_ss_relays_B.Vq_b -
      sel751test_model_1_3_ss_relays_B.UnitDelay_o;

    /* Sum: '<S81>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_p =
      sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle -
      sel751test_model_1_3_ss_relays_B.RoundingFunction;

    /* Product: '<S81>/Product5' */
    sel751test_model_1_3_ss_relays_B.Product5_n =
      sel751test_model_1_3_ss_relays_B.Sum5_p *
      sel751test_model_1_3_ss_relays_B.Sum1_hp;

    /* Gain: '<S81>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_ol =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_g *
      sel751test_model_1_3_ss_relays_B.Product5_n;

    /* Sum: '<S81>/Sum4' */
    sel751test_model_1_3_ss_relays_B.Sum4_n =
      sel751test_model_1_3_ss_relays_B.Gain1_ol +
      sel751test_model_1_3_ss_relays_B.Vq_b;

    /* Product: '<S81>/Product2' */
    sel751test_model_1_3_ss_relays_B.Product2_k =
      sel751test_model_1_3_ss_relays_B.Sum5_p /
      sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle;

    /* Product: '<S81>/Product4' */
    sel751test_model_1_3_ss_relays_B.Product4_jj =
      sel751test_model_1_3_ss_relays_B.Product2_k *
      sel751test_model_1_3_ss_relays_B.Sum4_n;

    /* Sum: '<S71>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_e1 =
      sel751test_model_1_3_ss_relays_B.Integ4_e -
      sel751test_model_1_3_ss_relays_B.SFunction_j;

    /* Product: '<S71>/Product' */
    sel751test_model_1_3_ss_relays_B.Meanvalue_k =
      sel751test_model_1_3_ss_relays_B.Sum7_e1 *
      sel751test_model_1_3_ss_relays_B.UnitDelay_d;

    /* Sum: '<S71>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_mk =
      sel751test_model_1_3_ss_relays_B.Meanvalue_k +
      sel751test_model_1_3_ss_relays_B.Product4_jj;
    sel751test_model_1_3_ss_relays_B.Switch_f =
      sel751test_model_1_3_ss_relays_B.Sum5_mk;
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_f =
      sel751test_model_1_3_ss_relays_P.Constant_Value_g5;
  }

  /* End of Switch: '<S71>/Switch' */

  /* Trigonometry: '<S65>/Trigonometric Function' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction_h = sin
    (sel751test_model_1_3_ss_relays_B.MathFunction_d);

  /* Outputs for Enabled SubSystem: '<S65>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S68>/Enable'
   */
  /* Constant: '<S65>/Constant1' */
  if (sel751test_model_1_3_ss_relays_P.Constant1_Value_b > 0.0) {
    if (!sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE) {
      /* Enable for DiscreteIntegrator: '<S74>/Integ4' */
      sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_m = 1U;

      /* Enable for DiscreteIntegrator: '<S75>/Integ4' */
      sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_ei = 1U;
      sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE = TRUE;
    }

    /* Gain: '<S72>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_h1[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_f *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction_h;
    sel751test_model_1_3_ss_relays_B.Gain1_h1[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_f *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_o;

    /* Product: '<S72>/Product' */
    sel751test_model_1_3_ss_relays_B.Product_k3[0] =
      sel751test_model_1_3_ss_relays_B.Divide_a *
      sel751test_model_1_3_ss_relays_B.Gain1_h1[0];
    sel751test_model_1_3_ss_relays_B.Product_k3[1] =
      sel751test_model_1_3_ss_relays_B.Divide_a *
      sel751test_model_1_3_ss_relays_B.Gain1_h1[1];

    /* DiscreteIntegrator: '<S74>/Integ4' */
    if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_m != 0) {
      sel751test_model_1_3_ss_relays_B.Integ4_h =
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_n;
    } else {
      sel751test_model_1_3_ss_relays_B.Integ4_h =
        sel751test_model_1_3_ss_relays_P.Integ4_gainval *
        sel751test_model_1_3_ss_relays_B.Product_k3[0] +
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_n;
    }

    /* End of DiscreteIntegrator: '<S74>/Integ4' */

    /* Saturate: '<S74>/To avoid division by zero' */
    u = sel751test_model_1_3_ss_relays_B.UnitDelay_d;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerSat;
    u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperSat;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Freq_ms = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Freq_ms = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Freq_ms = u;
    }

    /* End of Saturate: '<S74>/To avoid division by zero' */

    /* Fcn: '<S74>/Number of samples per cycle' */
    sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_cy = 1.0 /
      sel751test_model_1_3_ss_relays_B.Freq_ms / 0.0001;

    /* Rounding: '<S74>/Rounding Function' */
    sel751test_model_1_3_ss_relays_B.RoundingFunction_g = ceil
      (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_cy);

    /* Gain: '<S74>/Gain' */
    sel751test_model_1_3_ss_relays_B.Delay_p =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_l *
      sel751test_model_1_3_ss_relays_B.RoundingFunction_g;

    /* S-Function block: <S77>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_es.uBuffers)
        [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.indEnd] =
        sel751test_model_1_3_ss_relays_B.Integ4_h;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_p/0.0001) + 0.5);
      if (discreteDelay >
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.maxDiscrDelay)
        discreteDelay =
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.maxDiscrDelay;
      indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed +=
            sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.bufSz;
      }

      /* Output past value(s) */
      sel751test_model_1_3_ss_relays_B.SFunction_nb = ((real_T *)
        sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_es.uBuffers)
        [indDelayed];
    }

    /* UnitDelay: '<S76>/Unit Delay' */
    sel751test_model_1_3_ss_relays_B.UnitDelay_be =
      sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_b5;

    /* Step: '<S74>/Step' */
    dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
    if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time) {
      sel751test_model_1_3_ss_relays_B.Step_dh =
        sel751test_model_1_3_ss_relays_P.Step_Y0;
    } else {
      sel751test_model_1_3_ss_relays_B.Step_dh =
        sel751test_model_1_3_ss_relays_P.Step_YFinal;
    }

    /* End of Step: '<S74>/Step' */

    /* Switch: '<S74>/Switch' incorporates:
     *  Constant: '<S74>/Constant'
     */
    if (sel751test_model_1_3_ss_relays_B.Step_dh >=
        sel751test_model_1_3_ss_relays_P.Switch_Threshold) {
      /* Sum: '<S76>/Sum1' */
      sel751test_model_1_3_ss_relays_B.Sum1_f0 =
        sel751test_model_1_3_ss_relays_B.Product_k3[0] -
        sel751test_model_1_3_ss_relays_B.UnitDelay_be;

      /* Sum: '<S76>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_nc =
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_cy -
        sel751test_model_1_3_ss_relays_B.RoundingFunction_g;

      /* Product: '<S76>/Product5' */
      sel751test_model_1_3_ss_relays_B.Product5_av =
        sel751test_model_1_3_ss_relays_B.Sum5_nc *
        sel751test_model_1_3_ss_relays_B.Sum1_f0;

      /* Gain: '<S76>/Gain1' */
      sel751test_model_1_3_ss_relays_B.Gain1_ov =
        sel751test_model_1_3_ss_relays_P.Gain1_Gain_n *
        sel751test_model_1_3_ss_relays_B.Product5_av;

      /* Sum: '<S76>/Sum4' */
      sel751test_model_1_3_ss_relays_B.Sum4_o =
        sel751test_model_1_3_ss_relays_B.Gain1_ov +
        sel751test_model_1_3_ss_relays_B.Product_k3[0];

      /* Product: '<S76>/Product2' */
      sel751test_model_1_3_ss_relays_B.Product2_d =
        sel751test_model_1_3_ss_relays_B.Sum5_nc /
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_cy;

      /* Product: '<S76>/Product4' */
      sel751test_model_1_3_ss_relays_B.Product4_nf =
        sel751test_model_1_3_ss_relays_B.Product2_d *
        sel751test_model_1_3_ss_relays_B.Sum4_o;

      /* Sum: '<S74>/Sum7' */
      sel751test_model_1_3_ss_relays_B.Sum7_i =
        sel751test_model_1_3_ss_relays_B.Integ4_h -
        sel751test_model_1_3_ss_relays_B.SFunction_nb;

      /* Product: '<S74>/Product' */
      sel751test_model_1_3_ss_relays_B.Meanvalue_cl =
        sel751test_model_1_3_ss_relays_B.Sum7_i *
        sel751test_model_1_3_ss_relays_B.UnitDelay_d;

      /* Sum: '<S74>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_bk =
        sel751test_model_1_3_ss_relays_B.Meanvalue_cl +
        sel751test_model_1_3_ss_relays_B.Product4_nf;
      sel751test_model_1_3_ss_relays_B.Switch_dh =
        sel751test_model_1_3_ss_relays_B.Sum5_bk;
    } else {
      sel751test_model_1_3_ss_relays_B.Switch_dh =
        sel751test_model_1_3_ss_relays_P.Constant_Value;
    }

    /* End of Switch: '<S74>/Switch' */

    /* DiscreteIntegrator: '<S75>/Integ4' */
    if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_ei != 0) {
      sel751test_model_1_3_ss_relays_B.Integ4_k =
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_j;
    } else {
      sel751test_model_1_3_ss_relays_B.Integ4_k =
        sel751test_model_1_3_ss_relays_P.Integ4_gainval_m *
        sel751test_model_1_3_ss_relays_B.Product_k3[1] +
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_j;
    }

    /* End of DiscreteIntegrator: '<S75>/Integ4' */

    /* Saturate: '<S75>/To avoid division by zero' */
    u = sel751test_model_1_3_ss_relays_B.UnitDelay_d;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerSa_m;
    u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperSa_f;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Freq_jb = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Freq_jb = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Freq_jb = u;
    }

    /* End of Saturate: '<S75>/To avoid division by zero' */

    /* Fcn: '<S75>/Number of samples per cycle' */
    sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_e4 = 1.0 /
      sel751test_model_1_3_ss_relays_B.Freq_jb / 0.0001;

    /* Rounding: '<S75>/Rounding Function' */
    sel751test_model_1_3_ss_relays_B.RoundingFunction_m3 = ceil
      (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_e4);

    /* Gain: '<S75>/Gain' */
    sel751test_model_1_3_ss_relays_B.Delay_c =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_pn *
      sel751test_model_1_3_ss_relays_B.RoundingFunction_m3;

    /* S-Function block: <S79>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_h.uBuffers)
        [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.indEnd] =
        sel751test_model_1_3_ss_relays_B.Integ4_k;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_c/0.0001) + 0.5);
      if (discreteDelay >
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.maxDiscrDelay)
        discreteDelay =
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.maxDiscrDelay;
      indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed +=
            sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.bufSz;
      }

      /* Output past value(s) */
      sel751test_model_1_3_ss_relays_B.SFunction_g = ((real_T *)
        sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_h.uBuffers)[indDelayed];
    }

    /* UnitDelay: '<S78>/Unit Delay' */
    sel751test_model_1_3_ss_relays_B.UnitDelay_en =
      sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_hf;

    /* Step: '<S75>/Step' */
    dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
    if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_m) {
      sel751test_model_1_3_ss_relays_B.Step_db =
        sel751test_model_1_3_ss_relays_P.Step_Y0_k;
    } else {
      sel751test_model_1_3_ss_relays_B.Step_db =
        sel751test_model_1_3_ss_relays_P.Step_YFinal_p;
    }

    /* End of Step: '<S75>/Step' */

    /* Switch: '<S75>/Switch' incorporates:
     *  Constant: '<S75>/Constant'
     */
    if (sel751test_model_1_3_ss_relays_B.Step_db >=
        sel751test_model_1_3_ss_relays_P.Switch_Threshold_i) {
      /* Sum: '<S78>/Sum1' */
      sel751test_model_1_3_ss_relays_B.Sum1_lu =
        sel751test_model_1_3_ss_relays_B.Product_k3[1] -
        sel751test_model_1_3_ss_relays_B.UnitDelay_en;

      /* Sum: '<S78>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_hq =
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_e4 -
        sel751test_model_1_3_ss_relays_B.RoundingFunction_m3;

      /* Product: '<S78>/Product5' */
      sel751test_model_1_3_ss_relays_B.Product5_dd =
        sel751test_model_1_3_ss_relays_B.Sum5_hq *
        sel751test_model_1_3_ss_relays_B.Sum1_lu;

      /* Gain: '<S78>/Gain1' */
      sel751test_model_1_3_ss_relays_B.Gain1_mp =
        sel751test_model_1_3_ss_relays_P.Gain1_Gain_cf *
        sel751test_model_1_3_ss_relays_B.Product5_dd;

      /* Sum: '<S78>/Sum4' */
      sel751test_model_1_3_ss_relays_B.Sum4_a3 =
        sel751test_model_1_3_ss_relays_B.Gain1_mp +
        sel751test_model_1_3_ss_relays_B.Product_k3[1];

      /* Product: '<S78>/Product2' */
      sel751test_model_1_3_ss_relays_B.Product2_g5 =
        sel751test_model_1_3_ss_relays_B.Sum5_hq /
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_e4;

      /* Product: '<S78>/Product4' */
      sel751test_model_1_3_ss_relays_B.Product4_g =
        sel751test_model_1_3_ss_relays_B.Product2_g5 *
        sel751test_model_1_3_ss_relays_B.Sum4_a3;

      /* Sum: '<S75>/Sum7' */
      sel751test_model_1_3_ss_relays_B.Sum7_ad =
        sel751test_model_1_3_ss_relays_B.Integ4_k -
        sel751test_model_1_3_ss_relays_B.SFunction_g;

      /* Product: '<S75>/Product' */
      sel751test_model_1_3_ss_relays_B.Meanvalue_ht =
        sel751test_model_1_3_ss_relays_B.Sum7_ad *
        sel751test_model_1_3_ss_relays_B.UnitDelay_d;

      /* Sum: '<S75>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_b5 =
        sel751test_model_1_3_ss_relays_B.Meanvalue_ht +
        sel751test_model_1_3_ss_relays_B.Product4_g;
      sel751test_model_1_3_ss_relays_B.Switch_lo =
        sel751test_model_1_3_ss_relays_B.Sum5_b5;
    } else {
      sel751test_model_1_3_ss_relays_B.Switch_lo =
        sel751test_model_1_3_ss_relays_P.Constant_Value_o;
    }

    /* End of Switch: '<S75>/Switch' */

    /* Fcn: '<S73>/x->r' */
    sel751test_model_1_3_ss_relays_B.xr_h = rt_hypotd_snf
      (sel751test_model_1_3_ss_relays_B.Switch_dh,
       sel751test_model_1_3_ss_relays_B.Switch_lo);

    /* Fcn: '<S73>/x->theta' */
    sel751test_model_1_3_ss_relays_B.xtheta_f = rt_atan2d_snf
      (sel751test_model_1_3_ss_relays_B.Switch_lo,
       sel751test_model_1_3_ss_relays_B.Switch_dh);

    /* Gain: '<S72>/Rad->Deg.' */
    sel751test_model_1_3_ss_relays_B.RadDeg_c =
      sel751test_model_1_3_ss_relays_P.RadDeg_Gain *
      sel751test_model_1_3_ss_relays_B.xtheta_f;

    /* Saturate: '<S68>/Saturation' */
    u = sel751test_model_1_3_ss_relays_B.xr_h;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat;
    u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Saturation_l = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Saturation_l = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Saturation_l = u;
    }

    /* End of Saturate: '<S68>/Saturation' */

    /* Math: '<S68>/Math Function'
     *
     * About '<S68>/Math Function':
     *  Operator: reciprocal
     */
    sel751test_model_1_3_ss_relays_B.MathFunction_gy = 1.0 /
      sel751test_model_1_3_ss_relays_B.Saturation_l;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE) {
      sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE = FALSE;
    }
  }

  /* End of Constant: '<S65>/Constant1' */
  /* End of Outputs for SubSystem: '<S65>/Automatic Gain Control' */

  /* Product: '<S65>/Divide' */
  sel751test_model_1_3_ss_relays_B.Divide_n =
    sel751test_model_1_3_ss_relays_B.Switch_f *
    sel751test_model_1_3_ss_relays_B.MathFunction_gy;

  /* Gain: '<S69>/Kp4' */
  sel751test_model_1_3_ss_relays_B.Kp4_d =
    sel751test_model_1_3_ss_relays_P.Kp4_Gain_i3 *
    sel751test_model_1_3_ss_relays_B.Divide_n;

  /* DiscreteIntegrator: '<S69>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_d =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_a;

  /* Gain: '<S69>/Kp6' */
  sel751test_model_1_3_ss_relays_B.Kp6_n =
    sel751test_model_1_3_ss_relays_P.Kp6_Gain_d *
    sel751test_model_1_3_ss_relays_B.Divide_n;

  /* ZeroOrderHold: '<S69>/Zero-Order Hold' */
  sel751test_model_1_3_ss_relays_B.ZeroOrderHold_m =
    sel751test_model_1_3_ss_relays_B.Kp6_n;

  /* SampleTimeMath: '<S80>/TSamp'
   *
   * About '<S80>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  sel751test_model_1_3_ss_relays_B.TSamp_b =
    sel751test_model_1_3_ss_relays_B.ZeroOrderHold_m *
    sel751test_model_1_3_ss_relays_P.TSamp_WtEt_n0;

  /* UnitDelay: '<S80>/UD' */
  sel751test_model_1_3_ss_relays_B.Uk1_ck =
    sel751test_model_1_3_ss_relays_DW.UD_DSTATE_e;

  /* Sum: '<S80>/Diff' */
  sel751test_model_1_3_ss_relays_B.Diff_l =
    sel751test_model_1_3_ss_relays_B.TSamp_b -
    sel751test_model_1_3_ss_relays_B.Uk1_ck;

  /* Sum: '<S69>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6_a =
    (sel751test_model_1_3_ss_relays_B.Kp4_d +
     sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_d) +
    sel751test_model_1_3_ss_relays_B.Diff_l;

  /* Saturate: '<S69>/Saturation2' */
  u = sel751test_model_1_3_ss_relays_B.Sum6_a;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation2_LowerSat_ha;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation2_UpperSat_n;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Saturation2_m = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Saturation2_m = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Saturation2_m = u;
  }

  /* End of Saturate: '<S69>/Saturation2' */

  /* Gain: '<S65>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10_c =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain_g *
    sel751test_model_1_3_ss_relays_B.Saturation2_m;

  /* UnitDelay: '<S70>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_B.y1_a =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_i;

  /* Sum: '<S70>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1_a =
    sel751test_model_1_3_ss_relays_B.Gain10_c -
    sel751test_model_1_3_ss_relays_B.y1_a;

  /* Saturate: '<S70>/Saturation' */
  u = sel751test_model_1_3_ss_relays_B.Sum1_a;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_m;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_j;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_d = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_d = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_d = u;
  }

  /* End of Saturate: '<S70>/Saturation' */

  /* Sum: '<S70>/Sum' */
  sel751test_model_1_3_ss_relays_B.y_o =
    sel751test_model_1_3_ss_relays_B.Deltau_limit_d +
    sel751test_model_1_3_ss_relays_B.y1_a;

  /* DiscreteStateSpace: '<S67>/Discrete State-Space' */
  {
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_m =
      (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_l[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_l[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_l[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_l[1];
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_m +=
      sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_D_l*
      sel751test_model_1_3_ss_relays_B.y_o;
  }

  /* Gain: '<S69>/Kp5' */
  sel751test_model_1_3_ss_relays_B.Kp5_k =
    sel751test_model_1_3_ss_relays_P.Kp5_Gain_l *
    sel751test_model_1_3_ss_relays_B.Divide_n;

  /* Product: '<S61>/Divide1' incorporates:
   *  Constant: '<S20>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Divide1_g =
    sel751test_model_1_3_ss_relays_B.SFunction_l[4] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value[1];

  /* Trigonometry: '<S66>/Trigonometric Function2' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_b = cos
    (sel751test_model_1_3_ss_relays_B.MathFunction_p);

  /* Product: '<S66>/Product1' */
  sel751test_model_1_3_ss_relays_B.Vq_n =
    sel751test_model_1_3_ss_relays_B.Divide1_g *
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_b;

  /* DiscreteIntegrator: '<S87>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_od != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_mb =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_oi;
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_mb =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_hr *
      sel751test_model_1_3_ss_relays_B.Vq_n +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_oi;
  }

  /* End of DiscreteIntegrator: '<S87>/Integ4' */

  /* Saturate: '<S87>/To avoid division by zero' */
  u = sel751test_model_1_3_ss_relays_B.UnitDelay_jh;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerS_mf;
  u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperS_mf;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Freq_n = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Freq_n = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Freq_n = u;
  }

  /* End of Saturate: '<S87>/To avoid division by zero' */

  /* Fcn: '<S87>/Number of samples per cycle' */
  sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_a = 1.0 /
    sel751test_model_1_3_ss_relays_B.Freq_n / 0.0001;

  /* Rounding: '<S87>/Rounding Function' */
  sel751test_model_1_3_ss_relays_B.RoundingFunction_i = ceil
    (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_a);

  /* Gain: '<S87>/Gain' */
  sel751test_model_1_3_ss_relays_B.Delay_d =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_ni *
    sel751test_model_1_3_ss_relays_B.RoundingFunction_i;

  /* S-Function block: <S98>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_f.uBuffers)
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_mb;

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_d/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_n = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_f.uBuffers)[indDelayed];
  }

  /* UnitDelay: '<S97>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_m =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_g;

  /* Step: '<S87>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_l0) {
    sel751test_model_1_3_ss_relays_B.Step_k5 =
      sel751test_model_1_3_ss_relays_P.Step_Y0_p;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_k5 =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_ab;
  }

  /* End of Step: '<S87>/Step' */

  /* Switch: '<S87>/Switch' incorporates:
   *  Constant: '<S87>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_k5 >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_ni) {
    /* Sum: '<S97>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Sum1_cc =
      sel751test_model_1_3_ss_relays_B.Vq_n -
      sel751test_model_1_3_ss_relays_B.UnitDelay_m;

    /* Sum: '<S97>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_a =
      sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_a -
      sel751test_model_1_3_ss_relays_B.RoundingFunction_i;

    /* Product: '<S97>/Product5' */
    sel751test_model_1_3_ss_relays_B.Product5_f =
      sel751test_model_1_3_ss_relays_B.Sum5_a *
      sel751test_model_1_3_ss_relays_B.Sum1_cc;

    /* Gain: '<S97>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_hb =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_e *
      sel751test_model_1_3_ss_relays_B.Product5_f;

    /* Sum: '<S97>/Sum4' */
    sel751test_model_1_3_ss_relays_B.Sum4_p =
      sel751test_model_1_3_ss_relays_B.Gain1_hb +
      sel751test_model_1_3_ss_relays_B.Vq_n;

    /* Product: '<S97>/Product2' */
    sel751test_model_1_3_ss_relays_B.Product2_m =
      sel751test_model_1_3_ss_relays_B.Sum5_a /
      sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_a;

    /* Product: '<S97>/Product4' */
    sel751test_model_1_3_ss_relays_B.Product4_nr =
      sel751test_model_1_3_ss_relays_B.Product2_m *
      sel751test_model_1_3_ss_relays_B.Sum4_p;

    /* Sum: '<S87>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_e =
      sel751test_model_1_3_ss_relays_B.Integ4_mb -
      sel751test_model_1_3_ss_relays_B.SFunction_n;

    /* Product: '<S87>/Product' */
    sel751test_model_1_3_ss_relays_B.Meanvalue_aq =
      sel751test_model_1_3_ss_relays_B.Sum7_e *
      sel751test_model_1_3_ss_relays_B.UnitDelay_jh;

    /* Sum: '<S87>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_om =
      sel751test_model_1_3_ss_relays_B.Meanvalue_aq +
      sel751test_model_1_3_ss_relays_B.Product4_nr;
    sel751test_model_1_3_ss_relays_B.Switch_pm =
      sel751test_model_1_3_ss_relays_B.Sum5_om;
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_pm =
      sel751test_model_1_3_ss_relays_P.Constant_Value_iq;
  }

  /* End of Switch: '<S87>/Switch' */

  /* Trigonometry: '<S66>/Trigonometric Function' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction_c = sin
    (sel751test_model_1_3_ss_relays_B.MathFunction_p);

  /* Outputs for Enabled SubSystem: '<S66>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S84>/Enable'
   */
  /* Constant: '<S66>/Constant1' */
  if (sel751test_model_1_3_ss_relays_P.Constant1_Value_bu > 0.0) {
    if (!sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_c) {
      /* Enable for DiscreteIntegrator: '<S90>/Integ4' */
      sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_ll = 1U;

      /* Enable for DiscreteIntegrator: '<S91>/Integ4' */
      sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_fr = 1U;
      sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_c = TRUE;
    }

    /* Gain: '<S88>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_p3[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_co *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction_c;
    sel751test_model_1_3_ss_relays_B.Gain1_p3[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_co *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_b;

    /* Product: '<S88>/Product' */
    sel751test_model_1_3_ss_relays_B.Product_hq[0] =
      sel751test_model_1_3_ss_relays_B.Divide1_g *
      sel751test_model_1_3_ss_relays_B.Gain1_p3[0];
    sel751test_model_1_3_ss_relays_B.Product_hq[1] =
      sel751test_model_1_3_ss_relays_B.Divide1_g *
      sel751test_model_1_3_ss_relays_B.Gain1_p3[1];

    /* DiscreteIntegrator: '<S90>/Integ4' */
    if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_ll != 0) {
      sel751test_model_1_3_ss_relays_B.Integ4_pk =
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_er;
    } else {
      sel751test_model_1_3_ss_relays_B.Integ4_pk =
        sel751test_model_1_3_ss_relays_P.Integ4_gainval_h *
        sel751test_model_1_3_ss_relays_B.Product_hq[0] +
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_er;
    }

    /* End of DiscreteIntegrator: '<S90>/Integ4' */

    /* Saturate: '<S90>/To avoid division by zero' */
    u = sel751test_model_1_3_ss_relays_B.UnitDelay_jh;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerSa_e;
    u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperSa_l;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Freq_d = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Freq_d = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Freq_d = u;
    }

    /* End of Saturate: '<S90>/To avoid division by zero' */

    /* Fcn: '<S90>/Number of samples per cycle' */
    sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_m = 1.0 /
      sel751test_model_1_3_ss_relays_B.Freq_d / 0.0001;

    /* Rounding: '<S90>/Rounding Function' */
    sel751test_model_1_3_ss_relays_B.RoundingFunction_m = ceil
      (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_m);

    /* Gain: '<S90>/Gain' */
    sel751test_model_1_3_ss_relays_B.Delay_k =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_f *
      sel751test_model_1_3_ss_relays_B.RoundingFunction_m;

    /* S-Function block: <S93>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gl.uBuffers)
        [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.indEnd] =
        sel751test_model_1_3_ss_relays_B.Integ4_pk;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_k/0.0001) + 0.5);
      if (discreteDelay >
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.maxDiscrDelay)
        discreteDelay =
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.maxDiscrDelay;
      indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed +=
            sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.bufSz;
      }

      /* Output past value(s) */
      sel751test_model_1_3_ss_relays_B.SFunction_i5 = ((real_T *)
        sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gl.uBuffers)
        [indDelayed];
    }

    /* UnitDelay: '<S92>/Unit Delay' */
    sel751test_model_1_3_ss_relays_B.UnitDelay_ma =
      sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_go;

    /* Step: '<S90>/Step' */
    dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
    if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_k) {
      sel751test_model_1_3_ss_relays_B.Step_ce =
        sel751test_model_1_3_ss_relays_P.Step_Y0_i;
    } else {
      sel751test_model_1_3_ss_relays_B.Step_ce =
        sel751test_model_1_3_ss_relays_P.Step_YFinal_pu;
    }

    /* End of Step: '<S90>/Step' */

    /* Switch: '<S90>/Switch' incorporates:
     *  Constant: '<S90>/Constant'
     */
    if (sel751test_model_1_3_ss_relays_B.Step_ce >=
        sel751test_model_1_3_ss_relays_P.Switch_Threshold_ir) {
      /* Sum: '<S92>/Sum1' */
      sel751test_model_1_3_ss_relays_B.Sum1_a3 =
        sel751test_model_1_3_ss_relays_B.Product_hq[0] -
        sel751test_model_1_3_ss_relays_B.UnitDelay_ma;

      /* Sum: '<S92>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_b =
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_m -
        sel751test_model_1_3_ss_relays_B.RoundingFunction_m;

      /* Product: '<S92>/Product5' */
      sel751test_model_1_3_ss_relays_B.Product5_j =
        sel751test_model_1_3_ss_relays_B.Sum5_b *
        sel751test_model_1_3_ss_relays_B.Sum1_a3;

      /* Gain: '<S92>/Gain1' */
      sel751test_model_1_3_ss_relays_B.Gain1_m0g =
        sel751test_model_1_3_ss_relays_P.Gain1_Gain_b *
        sel751test_model_1_3_ss_relays_B.Product5_j;

      /* Sum: '<S92>/Sum4' */
      sel751test_model_1_3_ss_relays_B.Sum4_az =
        sel751test_model_1_3_ss_relays_B.Gain1_m0g +
        sel751test_model_1_3_ss_relays_B.Product_hq[0];

      /* Product: '<S92>/Product2' */
      sel751test_model_1_3_ss_relays_B.Product2_p =
        sel751test_model_1_3_ss_relays_B.Sum5_b /
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_m;

      /* Product: '<S92>/Product4' */
      sel751test_model_1_3_ss_relays_B.Product4_k =
        sel751test_model_1_3_ss_relays_B.Product2_p *
        sel751test_model_1_3_ss_relays_B.Sum4_az;

      /* Sum: '<S90>/Sum7' */
      sel751test_model_1_3_ss_relays_B.Sum7_p =
        sel751test_model_1_3_ss_relays_B.Integ4_pk -
        sel751test_model_1_3_ss_relays_B.SFunction_i5;

      /* Product: '<S90>/Product' */
      sel751test_model_1_3_ss_relays_B.Meanvalue_od =
        sel751test_model_1_3_ss_relays_B.Sum7_p *
        sel751test_model_1_3_ss_relays_B.UnitDelay_jh;

      /* Sum: '<S90>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_cb =
        sel751test_model_1_3_ss_relays_B.Meanvalue_od +
        sel751test_model_1_3_ss_relays_B.Product4_k;
      sel751test_model_1_3_ss_relays_B.Switch_l =
        sel751test_model_1_3_ss_relays_B.Sum5_cb;
    } else {
      sel751test_model_1_3_ss_relays_B.Switch_l =
        sel751test_model_1_3_ss_relays_P.Constant_Value_oz;
    }

    /* End of Switch: '<S90>/Switch' */

    /* DiscreteIntegrator: '<S91>/Integ4' */
    if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_fr != 0) {
      sel751test_model_1_3_ss_relays_B.Integ4_f =
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_h4;
    } else {
      sel751test_model_1_3_ss_relays_B.Integ4_f =
        sel751test_model_1_3_ss_relays_P.Integ4_gainval_n *
        sel751test_model_1_3_ss_relays_B.Product_hq[1] +
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_h4;
    }

    /* End of DiscreteIntegrator: '<S91>/Integ4' */

    /* Saturate: '<S91>/To avoid division by zero' */
    u = sel751test_model_1_3_ss_relays_B.UnitDelay_jh;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerSa_g;
    u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperSa_h;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Freq_c = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Freq_c = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Freq_c = u;
    }

    /* End of Saturate: '<S91>/To avoid division by zero' */

    /* Fcn: '<S91>/Number of samples per cycle' */
    sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_g = 1.0 /
      sel751test_model_1_3_ss_relays_B.Freq_c / 0.0001;

    /* Rounding: '<S91>/Rounding Function' */
    sel751test_model_1_3_ss_relays_B.RoundingFunction_hw = ceil
      (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_g);

    /* Gain: '<S91>/Gain' */
    sel751test_model_1_3_ss_relays_B.Delay_ox =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_j *
      sel751test_model_1_3_ss_relays_B.RoundingFunction_hw;

    /* S-Function block: <S95>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_l.uBuffers)
        [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.indEnd] =
        sel751test_model_1_3_ss_relays_B.Integ4_f;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_ox/0.0001) + 0.5);
      if (discreteDelay >
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.maxDiscrDelay)
        discreteDelay =
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.maxDiscrDelay;
      indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed +=
            sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.bufSz;
      }

      /* Output past value(s) */
      sel751test_model_1_3_ss_relays_B.SFunction_mm = ((real_T *)
        sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_l.uBuffers)[indDelayed];
    }

    /* UnitDelay: '<S94>/Unit Delay' */
    sel751test_model_1_3_ss_relays_B.UnitDelay_ik =
      sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ku;

    /* Step: '<S91>/Step' */
    dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
    if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_n) {
      sel751test_model_1_3_ss_relays_B.Step_kd =
        sel751test_model_1_3_ss_relays_P.Step_Y0_h;
    } else {
      sel751test_model_1_3_ss_relays_B.Step_kd =
        sel751test_model_1_3_ss_relays_P.Step_YFinal_j;
    }

    /* End of Step: '<S91>/Step' */

    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S91>/Constant'
     */
    if (sel751test_model_1_3_ss_relays_B.Step_kd >=
        sel751test_model_1_3_ss_relays_P.Switch_Threshold_k) {
      /* Sum: '<S94>/Sum1' */
      sel751test_model_1_3_ss_relays_B.Sum1_g =
        sel751test_model_1_3_ss_relays_B.Product_hq[1] -
        sel751test_model_1_3_ss_relays_B.UnitDelay_ik;

      /* Sum: '<S94>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_l =
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_g -
        sel751test_model_1_3_ss_relays_B.RoundingFunction_hw;

      /* Product: '<S94>/Product5' */
      sel751test_model_1_3_ss_relays_B.Product5_o0 =
        sel751test_model_1_3_ss_relays_B.Sum5_l *
        sel751test_model_1_3_ss_relays_B.Sum1_g;

      /* Gain: '<S94>/Gain1' */
      sel751test_model_1_3_ss_relays_B.Gain1_c =
        sel751test_model_1_3_ss_relays_P.Gain1_Gain_cfi *
        sel751test_model_1_3_ss_relays_B.Product5_o0;

      /* Sum: '<S94>/Sum4' */
      sel751test_model_1_3_ss_relays_B.Sum4_al =
        sel751test_model_1_3_ss_relays_B.Gain1_c +
        sel751test_model_1_3_ss_relays_B.Product_hq[1];

      /* Product: '<S94>/Product2' */
      sel751test_model_1_3_ss_relays_B.Product2_l0 =
        sel751test_model_1_3_ss_relays_B.Sum5_l /
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_g;

      /* Product: '<S94>/Product4' */
      sel751test_model_1_3_ss_relays_B.Product4_c =
        sel751test_model_1_3_ss_relays_B.Product2_l0 *
        sel751test_model_1_3_ss_relays_B.Sum4_al;

      /* Sum: '<S91>/Sum7' */
      sel751test_model_1_3_ss_relays_B.Sum7_k =
        sel751test_model_1_3_ss_relays_B.Integ4_f -
        sel751test_model_1_3_ss_relays_B.SFunction_mm;

      /* Product: '<S91>/Product' */
      sel751test_model_1_3_ss_relays_B.Meanvalue_b =
        sel751test_model_1_3_ss_relays_B.Sum7_k *
        sel751test_model_1_3_ss_relays_B.UnitDelay_jh;

      /* Sum: '<S91>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_n5 =
        sel751test_model_1_3_ss_relays_B.Meanvalue_b +
        sel751test_model_1_3_ss_relays_B.Product4_c;
      sel751test_model_1_3_ss_relays_B.Switch_n =
        sel751test_model_1_3_ss_relays_B.Sum5_n5;
    } else {
      sel751test_model_1_3_ss_relays_B.Switch_n =
        sel751test_model_1_3_ss_relays_P.Constant_Value_a;
    }

    /* End of Switch: '<S91>/Switch' */

    /* Fcn: '<S89>/x->r' */
    sel751test_model_1_3_ss_relays_B.xr_p = rt_hypotd_snf
      (sel751test_model_1_3_ss_relays_B.Switch_l,
       sel751test_model_1_3_ss_relays_B.Switch_n);

    /* Fcn: '<S89>/x->theta' */
    sel751test_model_1_3_ss_relays_B.xtheta_g = rt_atan2d_snf
      (sel751test_model_1_3_ss_relays_B.Switch_n,
       sel751test_model_1_3_ss_relays_B.Switch_l);

    /* Gain: '<S88>/Rad->Deg.' */
    sel751test_model_1_3_ss_relays_B.RadDeg_l =
      sel751test_model_1_3_ss_relays_P.RadDeg_Gain_p *
      sel751test_model_1_3_ss_relays_B.xtheta_g;

    /* Saturate: '<S84>/Saturation' */
    u = sel751test_model_1_3_ss_relays_B.xr_p;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_o;
    u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_h;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Saturation_k = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Saturation_k = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Saturation_k = u;
    }

    /* End of Saturate: '<S84>/Saturation' */

    /* Math: '<S84>/Math Function'
     *
     * About '<S84>/Math Function':
     *  Operator: reciprocal
     */
    sel751test_model_1_3_ss_relays_B.MathFunction_g0 = 1.0 /
      sel751test_model_1_3_ss_relays_B.Saturation_k;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_c) {
      sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_c = FALSE;
    }
  }

  /* End of Constant: '<S66>/Constant1' */
  /* End of Outputs for SubSystem: '<S66>/Automatic Gain Control' */

  /* Product: '<S66>/Divide' */
  sel751test_model_1_3_ss_relays_B.Divide_h =
    sel751test_model_1_3_ss_relays_B.Switch_pm *
    sel751test_model_1_3_ss_relays_B.MathFunction_g0;

  /* Gain: '<S85>/Kp4' */
  sel751test_model_1_3_ss_relays_B.Kp4_l =
    sel751test_model_1_3_ss_relays_P.Kp4_Gain_b *
    sel751test_model_1_3_ss_relays_B.Divide_h;

  /* DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_c =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_iq;

  /* Gain: '<S85>/Kp6' */
  sel751test_model_1_3_ss_relays_B.Kp6_k =
    sel751test_model_1_3_ss_relays_P.Kp6_Gain_c *
    sel751test_model_1_3_ss_relays_B.Divide_h;

  /* ZeroOrderHold: '<S85>/Zero-Order Hold' */
  sel751test_model_1_3_ss_relays_B.ZeroOrderHold_j =
    sel751test_model_1_3_ss_relays_B.Kp6_k;

  /* SampleTimeMath: '<S96>/TSamp'
   *
   * About '<S96>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  sel751test_model_1_3_ss_relays_B.TSamp_m =
    sel751test_model_1_3_ss_relays_B.ZeroOrderHold_j *
    sel751test_model_1_3_ss_relays_P.TSamp_WtEt_k;

  /* UnitDelay: '<S96>/UD' */
  sel751test_model_1_3_ss_relays_B.Uk1_k =
    sel751test_model_1_3_ss_relays_DW.UD_DSTATE_b;

  /* Sum: '<S96>/Diff' */
  sel751test_model_1_3_ss_relays_B.Diff_p =
    sel751test_model_1_3_ss_relays_B.TSamp_m -
    sel751test_model_1_3_ss_relays_B.Uk1_k;

  /* Sum: '<S85>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6_a0 =
    (sel751test_model_1_3_ss_relays_B.Kp4_l +
     sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_c) +
    sel751test_model_1_3_ss_relays_B.Diff_p;

  /* Saturate: '<S85>/Saturation2' */
  u = sel751test_model_1_3_ss_relays_B.Sum6_a0;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation2_LowerSat_d;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation2_UpperSat_p;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Saturation2_j = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Saturation2_j = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Saturation2_j = u;
  }

  /* End of Saturate: '<S85>/Saturation2' */

  /* Gain: '<S66>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10_i =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain_k *
    sel751test_model_1_3_ss_relays_B.Saturation2_j;

  /* UnitDelay: '<S86>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_B.y1_f =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_a;

  /* Sum: '<S86>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1_n =
    sel751test_model_1_3_ss_relays_B.Gain10_i -
    sel751test_model_1_3_ss_relays_B.y1_f;

  /* Saturate: '<S86>/Saturation' */
  u = sel751test_model_1_3_ss_relays_B.Sum1_n;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_d;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_n;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_b = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_b = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_b = u;
  }

  /* End of Saturate: '<S86>/Saturation' */

  /* Sum: '<S86>/Sum' */
  sel751test_model_1_3_ss_relays_B.y_k =
    sel751test_model_1_3_ss_relays_B.Deltau_limit_b +
    sel751test_model_1_3_ss_relays_B.y1_f;

  /* DiscreteStateSpace: '<S83>/Discrete State-Space' */
  {
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_n =
      (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_bf[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_k[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_bf[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_k[1];
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_n +=
      sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_D_d*
      sel751test_model_1_3_ss_relays_B.y_k;
  }

  /* Gain: '<S85>/Kp5' */
  sel751test_model_1_3_ss_relays_B.Kp5_m =
    sel751test_model_1_3_ss_relays_P.Kp5_Gain_b *
    sel751test_model_1_3_ss_relays_B.Divide_h;

  /* Sum: '<S5>/Sum' */
  sel751test_model_1_3_ss_relays_B.Sum_o =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion4[0] +
    sel751test_model_1_3_ss_relays_B.Gain_p;

  /* Sum: '<S5>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1_i =
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion4[2] +
     sel751test_model_1_3_ss_relays_B.Gain13) +
    sel751test_model_1_3_ss_relays_B.Gain14;

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[0] =
    sel751test_model_1_3_ss_relays_B.Status;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[1] =
    sel751test_model_1_3_ss_relays_B.LogicalOperator3;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[2] =
    sel751test_model_1_3_ss_relays_B.sf_Relays.trip27;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[3] =
    sel751test_model_1_3_ss_relays_B.sf_Relays.trip50;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[4] =
    sel751test_model_1_3_ss_relays_B.sf_Relays.trip51;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[5] =
    sel751test_model_1_3_ss_relays_B.sf_Relays.trip59;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[6] =
    sel751test_model_1_3_ss_relays_B.reset;

  /* ArithShift: '<S21>/Shift Arithmetic' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[1] << 1);

  /* ArithShift: '<S21>/Shift Arithmetic1' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic1 = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[2] << 2);

  /* ArithShift: '<S21>/Shift Arithmetic2' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic2 = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[3] << 3);

  /* ArithShift: '<S21>/Shift Arithmetic3' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic3 = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[4] << 4);

  /* ArithShift: '<S21>/Shift Arithmetic4' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic4 = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[5] << 5);

  /* ArithShift: '<S21>/Shift Arithmetic5' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic5 = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[6] << 6);

  /* S-Function (sfix_bitop): '<S21>/Bitwise Operator' */
  sel751test_model_1_3_ss_relays_B.BitwiseOperator = (uint16_T)((uint16_T)
    ((uint16_T)((uint16_T)((uint16_T)((uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_h[0] |
     sel751test_model_1_3_ss_relays_B.ShiftArithmetic) |
    sel751test_model_1_3_ss_relays_B.ShiftArithmetic1) |
    sel751test_model_1_3_ss_relays_B.ShiftArithmetic2) |
                sel751test_model_1_3_ss_relays_B.ShiftArithmetic3) |
     sel751test_model_1_3_ss_relays_B.ShiftArithmetic4) |
    sel751test_model_1_3_ss_relays_B.ShiftArithmetic5);

  /* DataTypeConversion: '<S21>/Data Type Conversion1' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion1 =
    sel751test_model_1_3_ss_relays_B.BitwiseOperator;

  /* DataTypeConversion: '<S22>/Data Type Conversion' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_a[0] =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion3_j[0];
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_a[1] =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion3_j[1];

  /* ArithShift: '<S22>/Shift Arithmetic' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic_g = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_a[1] << 1);

  /* S-Function (sfix_bitop): '<S22>/Bitwise Operator' */
  sel751test_model_1_3_ss_relays_B.BitwiseOperator_k = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_a[0] |
     sel751test_model_1_3_ss_relays_B.ShiftArithmetic_g);

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion1_g =
    sel751test_model_1_3_ss_relays_B.BitwiseOperator_k;

  /* Product: '<S6>/Divide1' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Divide1_i[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[14] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[1];
  sel751test_model_1_3_ss_relays_B.Divide1_i[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[15] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[1];
  sel751test_model_1_3_ss_relays_B.Divide1_i[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[16] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[1];

  /* DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_g =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_p;

  /* Math: '<S101>/Math Function' incorporates:
   *  Constant: '<S101>/Constant4'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_nc = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_g,
     sel751test_model_1_3_ss_relays_P.Constant4_Value_a);

  /* Trigonometry: '<S101>/Trigonometric Function' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction_jk = sin
    (sel751test_model_1_3_ss_relays_B.MathFunction_nc);

  /* Trigonometry: '<S101>/Trigonometric Function2' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_f = cos
    (sel751test_model_1_3_ss_relays_B.MathFunction_nc);

  /* Product: '<S120>/Product' incorporates:
   *  Constant: '<S120>/K1'
   */
  sel751test_model_1_3_ss_relays_B.Product_e =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction_jk *
    sel751test_model_1_3_ss_relays_P.K1_Value_ny;

  /* Product: '<S120>/Product1' incorporates:
   *  Constant: '<S120>/K2'
   */
  sel751test_model_1_3_ss_relays_B.Product1_g =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_f *
    sel751test_model_1_3_ss_relays_P.K2_Value_o;

  /* Sum: '<S120>/Sum' */
  sel751test_model_1_3_ss_relays_B.sinwt2pi3_g2 = (0.0 -
    sel751test_model_1_3_ss_relays_B.Product_e) -
    sel751test_model_1_3_ss_relays_B.Product1_g;

  /* Product: '<S120>/Product3' incorporates:
   *  Constant: '<S120>/K1'
   */
  sel751test_model_1_3_ss_relays_B.Product3_m =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_f *
    sel751test_model_1_3_ss_relays_P.K1_Value_ny;

  /* Product: '<S120>/Product2' incorporates:
   *  Constant: '<S120>/K2'
   */
  sel751test_model_1_3_ss_relays_B.Product2_l =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction_jk *
    sel751test_model_1_3_ss_relays_P.K2_Value_o;

  /* Sum: '<S120>/Sum1' */
  sel751test_model_1_3_ss_relays_B.coswt2pi3_h =
    sel751test_model_1_3_ss_relays_B.Product2_l -
    sel751test_model_1_3_ss_relays_B.Product3_m;

  /* Sum: '<S120>/Sum2' */
  sel751test_model_1_3_ss_relays_B.sinwt2pi3_d = (0.0 -
    sel751test_model_1_3_ss_relays_B.sinwt2pi3_g2) -
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction_jk;

  /* Sum: '<S120>/Sum3' */
  sel751test_model_1_3_ss_relays_B.coswt2pi3_l = (0.0 -
    sel751test_model_1_3_ss_relays_B.coswt2pi3_h) -
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_f;

  /* Fcn: '<S120>/Fcn1' */
  sel751test_model_1_3_ss_relays_B.Vq_j =
    ((sel751test_model_1_3_ss_relays_B.Divide1_i[0] *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_f +
      sel751test_model_1_3_ss_relays_B.Divide1_i[1] *
      sel751test_model_1_3_ss_relays_B.coswt2pi3_h) +
     sel751test_model_1_3_ss_relays_B.Divide1_i[2] *
     sel751test_model_1_3_ss_relays_B.coswt2pi3_l) * 0.66666666666666663;

  /* DiscreteIntegrator: '<S119>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_l != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_jt =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_h;
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_jt =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_k *
      sel751test_model_1_3_ss_relays_B.Vq_j +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_h;
  }

  /* End of DiscreteIntegrator: '<S119>/Integ4' */
  /* S-Function block: <S122>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_b.uBuffers)
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_jt;

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_a/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_h = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_b.uBuffers)[indDelayed];
  }

  /* UnitDelay: '<S119>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_nr =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_au;

  /* Step: '<S119>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_i) {
    sel751test_model_1_3_ss_relays_B.Step_jv =
      sel751test_model_1_3_ss_relays_P.Step_Y0_er;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_jv =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_m3;
  }

  /* End of Step: '<S119>/Step' */

  /* Switch: '<S119>/Switch' incorporates:
   *  Constant: '<S119>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_jv >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_ao) {
    /* Gain: '<S119>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_i =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_n *
      sel751test_model_1_3_ss_relays_B.UnitDelay_nr;

    /* Gain: '<S119>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_i =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_k *
      sel751test_model_1_3_ss_relays_B.Vq_j;

    /* Sum: '<S119>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_e =
      sel751test_model_1_3_ss_relays_B.Gain1_i -
      sel751test_model_1_3_ss_relays_B.Gain_i;

    /* Sum: '<S119>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_gd =
      sel751test_model_1_3_ss_relays_B.Integ4_jt -
      sel751test_model_1_3_ss_relays_B.SFunction_h;

    /* Product: '<S119>/Product' incorporates:
     *  Constant: '<S119>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_iu =
      sel751test_model_1_3_ss_relays_B.Sum7_gd *
      sel751test_model_1_3_ss_relays_P.K2_Value_ce;

    /* Sum: '<S119>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_or =
      sel751test_model_1_3_ss_relays_B.Meanvalue_iu +
      sel751test_model_1_3_ss_relays_B.Correction_e;
    sel751test_model_1_3_ss_relays_B.Switch_j =
      sel751test_model_1_3_ss_relays_B.Sum5_or;
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_j =
      sel751test_model_1_3_ss_relays_P.Constant_Value_jg;
  }

  /* End of Switch: '<S119>/Switch' */

  /* Gain: '<S117>/Kp4' */
  sel751test_model_1_3_ss_relays_B.Kp4_dr =
    sel751test_model_1_3_ss_relays_P.Kp4_Gain_e *
    sel751test_model_1_3_ss_relays_B.Switch_j;

  /* DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_i =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_j;

  /* Gain: '<S117>/Kp6' */
  sel751test_model_1_3_ss_relays_B.Kp6_o =
    sel751test_model_1_3_ss_relays_P.Kp6_Gain_cp *
    sel751test_model_1_3_ss_relays_B.Switch_j;

  /* ZeroOrderHold: '<S117>/Zero-Order Hold' */
  sel751test_model_1_3_ss_relays_B.ZeroOrderHold_h =
    sel751test_model_1_3_ss_relays_B.Kp6_o;

  /* SampleTimeMath: '<S121>/TSamp'
   *
   * About '<S121>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  sel751test_model_1_3_ss_relays_B.TSamp_e =
    sel751test_model_1_3_ss_relays_B.ZeroOrderHold_h *
    sel751test_model_1_3_ss_relays_P.TSamp_WtEt_g;

  /* UnitDelay: '<S121>/UD' */
  sel751test_model_1_3_ss_relays_B.Uk1_i =
    sel751test_model_1_3_ss_relays_DW.UD_DSTATE_n;

  /* Sum: '<S121>/Diff' */
  sel751test_model_1_3_ss_relays_B.Diff_b =
    sel751test_model_1_3_ss_relays_B.TSamp_e -
    sel751test_model_1_3_ss_relays_B.Uk1_i;

  /* Sum: '<S117>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6_g =
    (sel751test_model_1_3_ss_relays_B.Kp4_dr +
     sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_i) +
    sel751test_model_1_3_ss_relays_B.Diff_b;

  /* Saturate: '<S117>/Saturation2' */
  u = sel751test_model_1_3_ss_relays_B.Sum6_g;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation2_LowerSat_p;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation2_UpperSat_o;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Saturation2_d = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Saturation2_d = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Saturation2_d = u;
  }

  /* End of Saturate: '<S117>/Saturation2' */

  /* Gain: '<S101>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10_d =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain_d *
    sel751test_model_1_3_ss_relays_B.Saturation2_d;

  /* UnitDelay: '<S118>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_B.y1_p =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_o;

  /* Sum: '<S118>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1_k =
    sel751test_model_1_3_ss_relays_B.Gain10_d -
    sel751test_model_1_3_ss_relays_B.y1_p;

  /* Saturate: '<S118>/Saturation' */
  u = sel751test_model_1_3_ss_relays_B.Sum1_k;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_g;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_p;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_c = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_c = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_c = u;
  }

  /* End of Saturate: '<S118>/Saturation' */

  /* Sum: '<S118>/Sum' */
  sel751test_model_1_3_ss_relays_B.y_gn =
    sel751test_model_1_3_ss_relays_B.Deltau_limit_c +
    sel751test_model_1_3_ss_relays_B.y1_p;

  /* DiscreteStateSpace: '<S116>/Discrete State-Space' */
  {
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_mz =
      (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_c[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_d[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_c[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_d[1];
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_mz +=
      sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_D_dp*
      sel751test_model_1_3_ss_relays_B.y_gn;
  }

  /* Gain: '<S117>/Kp5' */
  sel751test_model_1_3_ss_relays_B.Kp5_g =
    sel751test_model_1_3_ss_relays_P.Kp5_Gain_e *
    sel751test_model_1_3_ss_relays_B.Switch_j;

  /* UnitDelay: '<S101>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_b3 =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_b;

  /* Fcn: '<S120>/Fcn2' */
  sel751test_model_1_3_ss_relays_B.Vd_n =
    ((sel751test_model_1_3_ss_relays_B.Divide1_i[0] *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction_jk +
      sel751test_model_1_3_ss_relays_B.Divide1_i[1] *
      sel751test_model_1_3_ss_relays_B.sinwt2pi3_g2) +
     sel751test_model_1_3_ss_relays_B.Divide1_i[2] *
     sel751test_model_1_3_ss_relays_B.sinwt2pi3_d) * 0.66666666666666663;

  /* Sum: '<S120>/Sum4' */
  tmpForInput[0] = sel751test_model_1_3_ss_relays_B.Divide1_i[0];
  tmpForInput[1] = sel751test_model_1_3_ss_relays_B.Divide1_i[1];
  tmpForInput[2] = sel751test_model_1_3_ss_relays_B.Divide1_i[2];
  tmpForInput[3] = sel751test_model_1_3_ss_relays_B.TrigonometricFunction_jk;
  tmpForInput[4] = sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_f;
  tmpForInput[5] = sel751test_model_1_3_ss_relays_B.sinwt2pi3_g2;
  tmpForInput[6] = sel751test_model_1_3_ss_relays_B.coswt2pi3_h;
  tmpForInput[7] = sel751test_model_1_3_ss_relays_B.sinwt2pi3_d;
  tmpForInput[8] = sel751test_model_1_3_ss_relays_B.coswt2pi3_l;
  dsp2Pi = tmpForInput[0];
  for (i = 0; i < 8; i++) {
    tmp = i + 1;
    dsp2Pi += tmpForInput[tmp];
  }

  sel751test_model_1_3_ss_relays_B.Sum4_k = dsp2Pi;

  /* End of Sum: '<S120>/Sum4' */

  /* Gain: '<S120>/Gain1' */
  sel751test_model_1_3_ss_relays_B.Gain1_m =
    sel751test_model_1_3_ss_relays_P.Gain1_Gain_in *
    sel751test_model_1_3_ss_relays_B.Sum4_k;

  /* Gain: '<S6>/Gain21' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Gain21_o =
    sel751test_model_1_3_ss_relays_P.Gain21_Gain_k *
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[6];

  /* Product: '<S6>/Divide' */
  sel751test_model_1_3_ss_relays_B.Divide_o[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[11] /
    sel751test_model_1_3_ss_relays_B.Gain21_o;
  sel751test_model_1_3_ss_relays_B.Divide_o[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[12] /
    sel751test_model_1_3_ss_relays_B.Gain21_o;
  sel751test_model_1_3_ss_relays_B.Divide_o[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[13] /
    sel751test_model_1_3_ss_relays_B.Gain21_o;

  /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_p =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_m;

  /* Math: '<S102>/Math Function' incorporates:
   *  Constant: '<S102>/Constant4'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_k = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_p,
     sel751test_model_1_3_ss_relays_P.Constant4_Value_l);

  /* Trigonometry: '<S102>/Trigonometric Function' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction_a = sin
    (sel751test_model_1_3_ss_relays_B.MathFunction_k);

  /* Trigonometry: '<S102>/Trigonometric Function2' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_d = cos
    (sel751test_model_1_3_ss_relays_B.MathFunction_k);

  /* Product: '<S127>/Product' incorporates:
   *  Constant: '<S127>/K1'
   */
  sel751test_model_1_3_ss_relays_B.Product_j =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction_a *
    sel751test_model_1_3_ss_relays_P.K1_Value_g;

  /* Product: '<S127>/Product1' incorporates:
   *  Constant: '<S127>/K2'
   */
  sel751test_model_1_3_ss_relays_B.Product1_m =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_d *
    sel751test_model_1_3_ss_relays_P.K2_Value_ek;

  /* Sum: '<S127>/Sum' */
  sel751test_model_1_3_ss_relays_B.sinwt2pi3_dr = (0.0 -
    sel751test_model_1_3_ss_relays_B.Product_j) -
    sel751test_model_1_3_ss_relays_B.Product1_m;

  /* Product: '<S127>/Product3' incorporates:
   *  Constant: '<S127>/K1'
   */
  sel751test_model_1_3_ss_relays_B.Product3_j =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_d *
    sel751test_model_1_3_ss_relays_P.K1_Value_g;

  /* Product: '<S127>/Product2' incorporates:
   *  Constant: '<S127>/K2'
   */
  sel751test_model_1_3_ss_relays_B.Product2_li =
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction_a *
    sel751test_model_1_3_ss_relays_P.K2_Value_ek;

  /* Sum: '<S127>/Sum1' */
  sel751test_model_1_3_ss_relays_B.coswt2pi3_i =
    sel751test_model_1_3_ss_relays_B.Product2_li -
    sel751test_model_1_3_ss_relays_B.Product3_j;

  /* Sum: '<S127>/Sum2' */
  sel751test_model_1_3_ss_relays_B.sinwt2pi3_na = (0.0 -
    sel751test_model_1_3_ss_relays_B.sinwt2pi3_dr) -
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction_a;

  /* Sum: '<S127>/Sum3' */
  sel751test_model_1_3_ss_relays_B.coswt2pi3_m = (0.0 -
    sel751test_model_1_3_ss_relays_B.coswt2pi3_i) -
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_d;

  /* Fcn: '<S127>/Fcn1' */
  sel751test_model_1_3_ss_relays_B.Vq_f =
    ((sel751test_model_1_3_ss_relays_B.Divide_o[0] *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_d +
      sel751test_model_1_3_ss_relays_B.Divide_o[1] *
      sel751test_model_1_3_ss_relays_B.coswt2pi3_i) +
     sel751test_model_1_3_ss_relays_B.Divide_o[2] *
     sel751test_model_1_3_ss_relays_B.coswt2pi3_m) * 0.66666666666666663;

  /* DiscreteIntegrator: '<S126>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_c != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_l =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_cw;
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_l =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_g3 *
      sel751test_model_1_3_ss_relays_B.Vq_f +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_cw;
  }

  /* End of DiscreteIntegrator: '<S126>/Integ4' */
  /* S-Function block: <S129>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_bf.uBuffers)
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_l;

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_b2/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_oy = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_bf.uBuffers)[indDelayed];
  }

  /* UnitDelay: '<S126>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_i =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jt;

  /* Step: '<S126>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_kr) {
    sel751test_model_1_3_ss_relays_B.Step_c =
      sel751test_model_1_3_ss_relays_P.Step_Y0_df;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_c =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_cr;
  }

  /* End of Step: '<S126>/Step' */

  /* Switch: '<S126>/Switch' incorporates:
   *  Constant: '<S126>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_c >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_b1) {
    /* Gain: '<S126>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_mo =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_c *
      sel751test_model_1_3_ss_relays_B.UnitDelay_i;

    /* Gain: '<S126>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_h3 =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_l0 *
      sel751test_model_1_3_ss_relays_B.Vq_f;

    /* Sum: '<S126>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_p =
      sel751test_model_1_3_ss_relays_B.Gain1_h3 -
      sel751test_model_1_3_ss_relays_B.Gain_mo;

    /* Sum: '<S126>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_g =
      sel751test_model_1_3_ss_relays_B.Integ4_l -
      sel751test_model_1_3_ss_relays_B.SFunction_oy;

    /* Product: '<S126>/Product' incorporates:
     *  Constant: '<S126>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_a =
      sel751test_model_1_3_ss_relays_B.Sum7_g *
      sel751test_model_1_3_ss_relays_P.K2_Value_e1;

    /* Sum: '<S126>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_o =
      sel751test_model_1_3_ss_relays_B.Meanvalue_a +
      sel751test_model_1_3_ss_relays_B.Correction_p;
    sel751test_model_1_3_ss_relays_B.Switch_fw =
      sel751test_model_1_3_ss_relays_B.Sum5_o;
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_fw =
      sel751test_model_1_3_ss_relays_P.Constant_Value_g5s;
  }

  /* End of Switch: '<S126>/Switch' */

  /* Gain: '<S124>/Kp4' */
  sel751test_model_1_3_ss_relays_B.Kp4_o =
    sel751test_model_1_3_ss_relays_P.Kp4_Gain_h *
    sel751test_model_1_3_ss_relays_B.Switch_fw;

  /* DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_i2 =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_jr;

  /* Gain: '<S124>/Kp6' */
  sel751test_model_1_3_ss_relays_B.Kp6_i =
    sel751test_model_1_3_ss_relays_P.Kp6_Gain_cd *
    sel751test_model_1_3_ss_relays_B.Switch_fw;

  /* ZeroOrderHold: '<S124>/Zero-Order Hold' */
  sel751test_model_1_3_ss_relays_B.ZeroOrderHold_l =
    sel751test_model_1_3_ss_relays_B.Kp6_i;

  /* SampleTimeMath: '<S128>/TSamp'
   *
   * About '<S128>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  sel751test_model_1_3_ss_relays_B.TSamp_d =
    sel751test_model_1_3_ss_relays_B.ZeroOrderHold_l *
    sel751test_model_1_3_ss_relays_P.TSamp_WtEt_l;

  /* UnitDelay: '<S128>/UD' */
  sel751test_model_1_3_ss_relays_B.Uk1_e =
    sel751test_model_1_3_ss_relays_DW.UD_DSTATE_m;

  /* Sum: '<S128>/Diff' */
  sel751test_model_1_3_ss_relays_B.Diff_lk =
    sel751test_model_1_3_ss_relays_B.TSamp_d -
    sel751test_model_1_3_ss_relays_B.Uk1_e;

  /* Sum: '<S124>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6_n =
    (sel751test_model_1_3_ss_relays_B.Kp4_o +
     sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_i2) +
    sel751test_model_1_3_ss_relays_B.Diff_lk;

  /* Saturate: '<S124>/Saturation2' */
  u = sel751test_model_1_3_ss_relays_B.Sum6_n;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation2_LowerSat_n;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation2_UpperSat_d;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Saturation2_k = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Saturation2_k = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Saturation2_k = u;
  }

  /* End of Saturate: '<S124>/Saturation2' */

  /* Gain: '<S102>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10_b =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain_a *
    sel751test_model_1_3_ss_relays_B.Saturation2_k;

  /* UnitDelay: '<S125>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_B.y1_b =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_an;

  /* Sum: '<S125>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1_o =
    sel751test_model_1_3_ss_relays_B.Gain10_b -
    sel751test_model_1_3_ss_relays_B.y1_b;

  /* Saturate: '<S125>/Saturation' */
  u = sel751test_model_1_3_ss_relays_B.Sum1_o;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_i;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_o;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_m = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_m = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_m = u;
  }

  /* End of Saturate: '<S125>/Saturation' */

  /* Sum: '<S125>/Sum' */
  sel751test_model_1_3_ss_relays_B.y_h =
    sel751test_model_1_3_ss_relays_B.Deltau_limit_m +
    sel751test_model_1_3_ss_relays_B.y1_b;

  /* DiscreteStateSpace: '<S123>/Discrete State-Space' */
  {
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_mi =
      (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_o[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_j[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_o[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_j[1];
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_mi +=
      sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_D_i*
      sel751test_model_1_3_ss_relays_B.y_h;
  }

  /* Gain: '<S124>/Kp5' */
  sel751test_model_1_3_ss_relays_B.Kp5_a =
    sel751test_model_1_3_ss_relays_P.Kp5_Gain_i *
    sel751test_model_1_3_ss_relays_B.Switch_fw;

  /* UnitDelay: '<S102>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_k =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_hh;

  /* Fcn: '<S127>/Fcn2' */
  sel751test_model_1_3_ss_relays_B.Vd_i =
    ((sel751test_model_1_3_ss_relays_B.Divide_o[0] *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction_a +
      sel751test_model_1_3_ss_relays_B.Divide_o[1] *
      sel751test_model_1_3_ss_relays_B.sinwt2pi3_dr) +
     sel751test_model_1_3_ss_relays_B.Divide_o[2] *
     sel751test_model_1_3_ss_relays_B.sinwt2pi3_na) * 0.66666666666666663;

  /* Sum: '<S127>/Sum4' */
  tmpForInput[0] = sel751test_model_1_3_ss_relays_B.Divide_o[0];
  tmpForInput[1] = sel751test_model_1_3_ss_relays_B.Divide_o[1];
  tmpForInput[2] = sel751test_model_1_3_ss_relays_B.Divide_o[2];
  tmpForInput[3] = sel751test_model_1_3_ss_relays_B.TrigonometricFunction_a;
  tmpForInput[4] = sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_d;
  tmpForInput[5] = sel751test_model_1_3_ss_relays_B.sinwt2pi3_dr;
  tmpForInput[6] = sel751test_model_1_3_ss_relays_B.coswt2pi3_i;
  tmpForInput[7] = sel751test_model_1_3_ss_relays_B.sinwt2pi3_na;
  tmpForInput[8] = sel751test_model_1_3_ss_relays_B.coswt2pi3_m;
  dsp2Pi = tmpForInput[0];
  for (i = 0; i < 8; i++) {
    tmp = i + 1;
    dsp2Pi += tmpForInput[tmp];
  }

  sel751test_model_1_3_ss_relays_B.Sum4_a = dsp2Pi;

  /* End of Sum: '<S127>/Sum4' */

  /* Gain: '<S127>/Gain1' */
  sel751test_model_1_3_ss_relays_B.Gain1_mg =
    sel751test_model_1_3_ss_relays_P.Gain1_Gain_ez *
    sel751test_model_1_3_ss_relays_B.Sum4_a;

  /* Product: '<S139>/Product1' */
  sel751test_model_1_3_ss_relays_B.Product1_n[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[14] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[11];
  sel751test_model_1_3_ss_relays_B.Product1_n[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[15] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[12];
  sel751test_model_1_3_ss_relays_B.Product1_n[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[16] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[13];

  /* Sum: '<S139>/Sum4' */
  dsp2Pi = sel751test_model_1_3_ss_relays_B.Product1_n[0];
  dsp2Pi += sel751test_model_1_3_ss_relays_B.Product1_n[1];
  dsp2Pi += sel751test_model_1_3_ss_relays_B.Product1_n[2];
  sel751test_model_1_3_ss_relays_B.P_j = dsp2Pi;

  /* Sum: '<S139>/Sum5' */
  sel751test_model_1_3_ss_relays_B.Sum5_e =
    sel751test_model_1_3_ss_relays_B.SFunction_l[15] -
    sel751test_model_1_3_ss_relays_B.SFunction_l[16];

  /* Sum: '<S139>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6_bc =
    sel751test_model_1_3_ss_relays_B.SFunction_l[16] -
    sel751test_model_1_3_ss_relays_B.SFunction_l[14];

  /* Sum: '<S139>/Sum' */
  sel751test_model_1_3_ss_relays_B.Sum_l =
    sel751test_model_1_3_ss_relays_B.SFunction_l[14] -
    sel751test_model_1_3_ss_relays_B.SFunction_l[15];

  /* Product: '<S139>/Product3' */
  sel751test_model_1_3_ss_relays_B.Product3_cj[0] =
    sel751test_model_1_3_ss_relays_B.Sum5_e *
    sel751test_model_1_3_ss_relays_B.SFunction_l[11];
  sel751test_model_1_3_ss_relays_B.Product3_cj[1] =
    sel751test_model_1_3_ss_relays_B.Sum6_bc *
    sel751test_model_1_3_ss_relays_B.SFunction_l[12];
  sel751test_model_1_3_ss_relays_B.Product3_cj[2] =
    sel751test_model_1_3_ss_relays_B.Sum_l *
    sel751test_model_1_3_ss_relays_B.SFunction_l[13];

  /* Sum: '<S139>/Sum1' */
  dsp2Pi = sel751test_model_1_3_ss_relays_B.Product3_cj[0];
  dsp2Pi += sel751test_model_1_3_ss_relays_B.Product3_cj[1];
  dsp2Pi += sel751test_model_1_3_ss_relays_B.Product3_cj[2];
  sel751test_model_1_3_ss_relays_B.Sum1_ei = dsp2Pi;

  /* Gain: '<S139>/pu->V' */
  sel751test_model_1_3_ss_relays_B.Q_f =
    sel751test_model_1_3_ss_relays_P.puV_Gain_l *
    sel751test_model_1_3_ss_relays_B.Sum1_ei;

  /* DiscreteIntegrator: '<S140>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_lg != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_b[0] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_e[0];
    sel751test_model_1_3_ss_relays_B.Integ4_b[1] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_e[1];
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_b[0] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_mc *
      sel751test_model_1_3_ss_relays_B.P_j +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_e[0];
    sel751test_model_1_3_ss_relays_B.Integ4_b[1] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_mc *
      sel751test_model_1_3_ss_relays_B.Q_f +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_e[1];
  }

  /* End of DiscreteIntegrator: '<S140>/Integ4' */
  /* S-Function block: <S141>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[0])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_b[0];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[1])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_b[1];

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_dv/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_j1[0] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[0])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_j1[1] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[1])
      [indDelayed];
  }

  /* UnitDelay: '<S140>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_cx[0] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_e5[0];
  sel751test_model_1_3_ss_relays_B.UnitDelay_cx[1] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_e5[1];

  /* Step: '<S140>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_g) {
    sel751test_model_1_3_ss_relays_B.Step_n =
      sel751test_model_1_3_ss_relays_P.Step_Y0_du;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_n =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_b;
  }

  /* End of Step: '<S140>/Step' */

  /* Switch: '<S140>/Switch' incorporates:
   *  Constant: '<S140>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_n >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_es) {
    /* Gain: '<S140>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_fu[0] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_ls *
      sel751test_model_1_3_ss_relays_B.UnitDelay_cx[0];
    sel751test_model_1_3_ss_relays_B.Gain_fu[1] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_ls *
      sel751test_model_1_3_ss_relays_B.UnitDelay_cx[1];

    /* Gain: '<S140>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_oz[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_bu *
      sel751test_model_1_3_ss_relays_B.P_j;
    sel751test_model_1_3_ss_relays_B.Gain1_oz[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_bu *
      sel751test_model_1_3_ss_relays_B.Q_f;

    /* Sum: '<S140>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_k[0] =
      sel751test_model_1_3_ss_relays_B.Gain1_oz[0] -
      sel751test_model_1_3_ss_relays_B.Gain_fu[0];
    sel751test_model_1_3_ss_relays_B.Correction_k[1] =
      sel751test_model_1_3_ss_relays_B.Gain1_oz[1] -
      sel751test_model_1_3_ss_relays_B.Gain_fu[1];

    /* Sum: '<S140>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_fx[0] =
      sel751test_model_1_3_ss_relays_B.Integ4_b[0] -
      sel751test_model_1_3_ss_relays_B.SFunction_j1[0];
    sel751test_model_1_3_ss_relays_B.Sum7_fx[1] =
      sel751test_model_1_3_ss_relays_B.Integ4_b[1] -
      sel751test_model_1_3_ss_relays_B.SFunction_j1[1];

    /* Product: '<S140>/Product' incorporates:
     *  Constant: '<S140>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_h[0] =
      sel751test_model_1_3_ss_relays_B.Sum7_fx[0] *
      sel751test_model_1_3_ss_relays_P.K2_Value_p;
    sel751test_model_1_3_ss_relays_B.Meanvalue_h[1] =
      sel751test_model_1_3_ss_relays_B.Sum7_fx[1] *
      sel751test_model_1_3_ss_relays_P.K2_Value_p;

    /* Sum: '<S140>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_n[0] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_h[0] +
      sel751test_model_1_3_ss_relays_B.Correction_k[0];
    sel751test_model_1_3_ss_relays_B.Sum5_n[1] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_h[1] +
      sel751test_model_1_3_ss_relays_B.Correction_k[1];
    sel751test_model_1_3_ss_relays_B.Switch_m[0] =
      sel751test_model_1_3_ss_relays_B.Sum5_n[0];
    sel751test_model_1_3_ss_relays_B.Switch_m[1] =
      sel751test_model_1_3_ss_relays_B.Sum5_n[1];
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_m[0] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_lu;
    sel751test_model_1_3_ss_relays_B.Switch_m[1] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_lu;
  }

  /* End of Switch: '<S140>/Switch' */

  /* Abs: '<S103>/Abs' */
  sel751test_model_1_3_ss_relays_B.Abs_f = fabs
    (sel751test_model_1_3_ss_relays_B.Switch_m[0]);

  /* Abs: '<S103>/Abs1' */
  sel751test_model_1_3_ss_relays_B.Abs1_h = fabs
    (sel751test_model_1_3_ss_relays_B.Switch_m[1]);

  /* Abs: '<S103>/Abs2' */
  sel751test_model_1_3_ss_relays_B.Abs2_l = fabs
    (sel751test_model_1_3_ss_relays_B.Switch_m[0]);

  /* RelationalOperator: '<S130>/Compare' incorporates:
   *  Constant: '<S130>/Constant'
   */
  sel751test_model_1_3_ss_relays_B.Compare_d = (uint8_T)
    (sel751test_model_1_3_ss_relays_B.Abs2_l >
     sel751test_model_1_3_ss_relays_P.Constant_Value_e);

  /* RelationalOperator: '<S131>/Compare' incorporates:
   *  Constant: '<S131>/Constant'
   */
  sel751test_model_1_3_ss_relays_B.Compare_f = (uint8_T)
    (sel751test_model_1_3_ss_relays_B.Abs1_h >
     sel751test_model_1_3_ss_relays_P.Constant_Value_fx);

  /* Fcn: '<S103>/Fcn' */
  u = sel751test_model_1_3_ss_relays_B.Switch_m[1];
  dsp2Pi = rt_powd_snf(u, 2.0);
  u = sel751test_model_1_3_ss_relays_B.Switch_m[0];
  u = rt_powd_snf(u, 2.0);
  dsp2Pi += u;
  if (dsp2Pi < 0.0) {
    dsp2Pi = -sqrt(-dsp2Pi);
  } else {
    dsp2Pi = sqrt(dsp2Pi);
  }

  sel751test_model_1_3_ss_relays_B.Fcn_p = dsp2Pi + 0.0001;

  /* End of Fcn: '<S103>/Fcn' */

  /* Product: '<S103>/Divide2' */
  sel751test_model_1_3_ss_relays_B.Divide2_f =
    sel751test_model_1_3_ss_relays_B.Abs_f /
    sel751test_model_1_3_ss_relays_B.Fcn_p;

  /* RelationalOperator: '<S132>/Compare' incorporates:
   *  Constant: '<S132>/Constant'
   */
  sel751test_model_1_3_ss_relays_B.Compare_i =
    (sel751test_model_1_3_ss_relays_B.Switch_m[0] >
     sel751test_model_1_3_ss_relays_P.Constant_Value_ht);

  /* RelationalOperator: '<S133>/Compare' incorporates:
   *  Constant: '<S133>/Constant'
   */
  sel751test_model_1_3_ss_relays_B.Compare_o =
    (sel751test_model_1_3_ss_relays_B.Switch_m[1] >
     sel751test_model_1_3_ss_relays_P.Constant_Value_bg);

  /* Logic: '<S103>/Logical Operator' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator_e =
    ((sel751test_model_1_3_ss_relays_B.Compare_f != 0) &&
     (sel751test_model_1_3_ss_relays_B.Compare_d != 0));

  /* UnitDelay: '<S134>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_a =
    sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_g;

  /* Switch: '<S134>/Enable' */
  if (sel751test_model_1_3_ss_relays_B.LogicalOperator_e) {
    sel751test_model_1_3_ss_relays_B.Xnew_h =
      sel751test_model_1_3_ss_relays_B.Divide2_f;
  } else {
    sel751test_model_1_3_ss_relays_B.Xnew_h =
      sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_a;
  }

  /* End of Switch: '<S134>/Enable' */

  /* UnitDelay: '<S135>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_i =
    sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_b;

  /* Switch: '<S135>/Enable' */
  if (sel751test_model_1_3_ss_relays_B.LogicalOperator_e) {
    sel751test_model_1_3_ss_relays_B.Xnew_b =
      sel751test_model_1_3_ss_relays_B.Compare_i;
  } else {
    sel751test_model_1_3_ss_relays_B.Xnew_b =
      sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_i;
  }

  /* End of Switch: '<S135>/Enable' */

  /* UnitDelay: '<S136>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_j =
    sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_a;

  /* Switch: '<S136>/Enable' */
  if (sel751test_model_1_3_ss_relays_B.LogicalOperator_e) {
    sel751test_model_1_3_ss_relays_B.Xnew_f =
      sel751test_model_1_3_ss_relays_B.Compare_o;
  } else {
    sel751test_model_1_3_ss_relays_B.Xnew_f =
      sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_j;
  }

  /* End of Switch: '<S136>/Enable' */

  /* DigitalClock: '<S6>/Digital Clock' */
  sel751test_model_1_3_ss_relays_B.DigitalClock_p =
    sel751test_model_1_3_ss_relays_M->Timing.t[0];

  /* RelationalOperator: '<S114>/Relational Operator' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  sel751test_model_1_3_ss_relays_B.RelationalOperator_n =
    (sel751test_model_1_3_ss_relays_B.DigitalClock_p >=
     sel751test_model_1_3_ss_relays_P.Constant2_Value_e);

  /* Logic: '<S111>/Logical Operator1' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator1_g =
    ((sel751test_model_1_3_ss_relays_B.SFunction_o[3] != 0.0) ||
     (sel751test_model_1_3_ss_relays_B.SFunction_o[4] != 0.0));

  /* UnitDelay: '<S190>/Delay Input1' */
  sel751test_model_1_3_ss_relays_B.Uk1_d =
    sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE_o;

  /* RelationalOperator: '<S190>/FixPt Relational Operator' */
  sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator_h = (uint8_T)
    (sel751test_model_1_3_ss_relays_B.LogicalOperator1_g !=
     sel751test_model_1_3_ss_relays_B.Uk1_d);

  /* DataTypeConversion: '<S114>/Data Type Conversion3' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion3_l =
    sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator_h;

  /* Product: '<S108>/Product3' */
  sel751test_model_1_3_ss_relays_B.Product3_d[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[11] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[11];
  sel751test_model_1_3_ss_relays_B.Product3_d[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[12] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[12];
  sel751test_model_1_3_ss_relays_B.Product3_d[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[13] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[13];

  /* DiscreteIntegrator: '<S142>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_f != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_ja[0] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[0];
    sel751test_model_1_3_ss_relays_B.Integ4_ja[1] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[1];
    sel751test_model_1_3_ss_relays_B.Integ4_ja[2] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[2];
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_ja[0] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_nk *
      sel751test_model_1_3_ss_relays_B.Product3_d[0] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[0];
    sel751test_model_1_3_ss_relays_B.Integ4_ja[1] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_nk *
      sel751test_model_1_3_ss_relays_B.Product3_d[1] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[1];
    sel751test_model_1_3_ss_relays_B.Integ4_ja[2] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_nk *
      sel751test_model_1_3_ss_relays_B.Product3_d[2] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[2];
  }

  /* End of DiscreteIntegrator: '<S142>/Integ4' */
  /* S-Function block: <S143>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[0])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_ja[0];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[1])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_ja[1];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[2])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_ja[2];

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_ja/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_m[0] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[0])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_m[1] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[1])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_m[2] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[2])
      [indDelayed];
  }

  /* UnitDelay: '<S142>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_i2[0] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_p[0];
  sel751test_model_1_3_ss_relays_B.UnitDelay_i2[1] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_p[1];
  sel751test_model_1_3_ss_relays_B.UnitDelay_i2[2] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_p[2];

  /* Step: '<S142>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_lw) {
    sel751test_model_1_3_ss_relays_B.Step_ip =
      sel751test_model_1_3_ss_relays_P.Step_Y0_bx;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_ip =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_a3;
  }

  /* End of Step: '<S142>/Step' */

  /* Switch: '<S142>/Switch' incorporates:
   *  Constant: '<S142>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_ip >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_f) {
    /* Gain: '<S142>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_m0[0] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_or *
      sel751test_model_1_3_ss_relays_B.UnitDelay_i2[0];
    sel751test_model_1_3_ss_relays_B.Gain_m0[1] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_or *
      sel751test_model_1_3_ss_relays_B.UnitDelay_i2[1];
    sel751test_model_1_3_ss_relays_B.Gain_m0[2] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_or *
      sel751test_model_1_3_ss_relays_B.UnitDelay_i2[2];

    /* Gain: '<S142>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_j[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_kr *
      sel751test_model_1_3_ss_relays_B.Product3_d[0];
    sel751test_model_1_3_ss_relays_B.Gain1_j[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_kr *
      sel751test_model_1_3_ss_relays_B.Product3_d[1];
    sel751test_model_1_3_ss_relays_B.Gain1_j[2] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_kr *
      sel751test_model_1_3_ss_relays_B.Product3_d[2];

    /* Sum: '<S142>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_j[0] =
      sel751test_model_1_3_ss_relays_B.Gain1_j[0] -
      sel751test_model_1_3_ss_relays_B.Gain_m0[0];
    sel751test_model_1_3_ss_relays_B.Correction_j[1] =
      sel751test_model_1_3_ss_relays_B.Gain1_j[1] -
      sel751test_model_1_3_ss_relays_B.Gain_m0[1];
    sel751test_model_1_3_ss_relays_B.Correction_j[2] =
      sel751test_model_1_3_ss_relays_B.Gain1_j[2] -
      sel751test_model_1_3_ss_relays_B.Gain_m0[2];

    /* Sum: '<S142>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_jf[0] =
      sel751test_model_1_3_ss_relays_B.Integ4_ja[0] -
      sel751test_model_1_3_ss_relays_B.SFunction_m[0];
    sel751test_model_1_3_ss_relays_B.Sum7_jf[1] =
      sel751test_model_1_3_ss_relays_B.Integ4_ja[1] -
      sel751test_model_1_3_ss_relays_B.SFunction_m[1];
    sel751test_model_1_3_ss_relays_B.Sum7_jf[2] =
      sel751test_model_1_3_ss_relays_B.Integ4_ja[2] -
      sel751test_model_1_3_ss_relays_B.SFunction_m[2];

    /* Product: '<S142>/Product' incorporates:
     *  Constant: '<S142>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_d[0] =
      sel751test_model_1_3_ss_relays_B.Sum7_jf[0] *
      sel751test_model_1_3_ss_relays_P.K2_Value_d3;
    sel751test_model_1_3_ss_relays_B.Meanvalue_d[1] =
      sel751test_model_1_3_ss_relays_B.Sum7_jf[1] *
      sel751test_model_1_3_ss_relays_P.K2_Value_d3;
    sel751test_model_1_3_ss_relays_B.Meanvalue_d[2] =
      sel751test_model_1_3_ss_relays_B.Sum7_jf[2] *
      sel751test_model_1_3_ss_relays_P.K2_Value_d3;

    /* Sum: '<S142>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_ds[0] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_d[0] +
      sel751test_model_1_3_ss_relays_B.Correction_j[0];
    sel751test_model_1_3_ss_relays_B.Sum5_ds[1] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_d[1] +
      sel751test_model_1_3_ss_relays_B.Correction_j[1];
    sel751test_model_1_3_ss_relays_B.Sum5_ds[2] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_d[2] +
      sel751test_model_1_3_ss_relays_B.Correction_j[2];
    sel751test_model_1_3_ss_relays_B.Switch_c[0] =
      sel751test_model_1_3_ss_relays_B.Sum5_ds[0];
    sel751test_model_1_3_ss_relays_B.Switch_c[1] =
      sel751test_model_1_3_ss_relays_B.Sum5_ds[1];
    sel751test_model_1_3_ss_relays_B.Switch_c[2] =
      sel751test_model_1_3_ss_relays_B.Sum5_ds[2];
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_c[0] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_by;
    sel751test_model_1_3_ss_relays_B.Switch_c[1] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_by;
    sel751test_model_1_3_ss_relays_B.Switch_c[2] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_by;
  }

  /* End of Switch: '<S142>/Switch' */

  /* Sqrt: '<S108>/Signed Sqrt' */
  sel751test_model_1_3_ss_relays_B.SignedSqrt_p[0] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_c[0]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt_p[1] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_c[1]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt_p[2] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_c[2]);

  /* Product: '<S109>/Product3' */
  sel751test_model_1_3_ss_relays_B.Product3_b[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[14] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[14];
  sel751test_model_1_3_ss_relays_B.Product3_b[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[15] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[15];
  sel751test_model_1_3_ss_relays_B.Product3_b[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[16] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[16];

  /* DiscreteIntegrator: '<S144>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_fs != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_cl[0] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[0];
    sel751test_model_1_3_ss_relays_B.Integ4_cl[1] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[1];
    sel751test_model_1_3_ss_relays_B.Integ4_cl[2] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[2];
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_cl[0] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_nj *
      sel751test_model_1_3_ss_relays_B.Product3_b[0] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[0];
    sel751test_model_1_3_ss_relays_B.Integ4_cl[1] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_nj *
      sel751test_model_1_3_ss_relays_B.Product3_b[1] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[1];
    sel751test_model_1_3_ss_relays_B.Integ4_cl[2] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_nj *
      sel751test_model_1_3_ss_relays_B.Product3_b[2] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[2];
  }

  /* End of DiscreteIntegrator: '<S144>/Integ4' */
  /* S-Function block: <S145>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[0])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_cl[0];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[1])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_cl[1];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[2])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_cl[2];

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_mw/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_of[0] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[0])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_of[1] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[1])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_of[2] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[2])
      [indDelayed];
  }

  /* UnitDelay: '<S144>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_cn[0] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jf[0];
  sel751test_model_1_3_ss_relays_B.UnitDelay_cn[1] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jf[1];
  sel751test_model_1_3_ss_relays_B.UnitDelay_cn[2] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jf[2];

  /* Step: '<S144>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_pv) {
    sel751test_model_1_3_ss_relays_B.Step_j4 =
      sel751test_model_1_3_ss_relays_P.Step_Y0_cj;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_j4 =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_pg;
  }

  /* End of Step: '<S144>/Step' */

  /* Switch: '<S144>/Switch' incorporates:
   *  Constant: '<S144>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_j4 >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_bk) {
    /* Gain: '<S144>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_e[0] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_i *
      sel751test_model_1_3_ss_relays_B.UnitDelay_cn[0];
    sel751test_model_1_3_ss_relays_B.Gain_e[1] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_i *
      sel751test_model_1_3_ss_relays_B.UnitDelay_cn[1];
    sel751test_model_1_3_ss_relays_B.Gain_e[2] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_i *
      sel751test_model_1_3_ss_relays_B.UnitDelay_cn[2];

    /* Gain: '<S144>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_mb[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_d *
      sel751test_model_1_3_ss_relays_B.Product3_b[0];
    sel751test_model_1_3_ss_relays_B.Gain1_mb[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_d *
      sel751test_model_1_3_ss_relays_B.Product3_b[1];
    sel751test_model_1_3_ss_relays_B.Gain1_mb[2] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_d *
      sel751test_model_1_3_ss_relays_B.Product3_b[2];

    /* Sum: '<S144>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction_n[0] =
      sel751test_model_1_3_ss_relays_B.Gain1_mb[0] -
      sel751test_model_1_3_ss_relays_B.Gain_e[0];
    sel751test_model_1_3_ss_relays_B.Correction_n[1] =
      sel751test_model_1_3_ss_relays_B.Gain1_mb[1] -
      sel751test_model_1_3_ss_relays_B.Gain_e[1];
    sel751test_model_1_3_ss_relays_B.Correction_n[2] =
      sel751test_model_1_3_ss_relays_B.Gain1_mb[2] -
      sel751test_model_1_3_ss_relays_B.Gain_e[2];

    /* Sum: '<S144>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_f[0] =
      sel751test_model_1_3_ss_relays_B.Integ4_cl[0] -
      sel751test_model_1_3_ss_relays_B.SFunction_of[0];
    sel751test_model_1_3_ss_relays_B.Sum7_f[1] =
      sel751test_model_1_3_ss_relays_B.Integ4_cl[1] -
      sel751test_model_1_3_ss_relays_B.SFunction_of[1];
    sel751test_model_1_3_ss_relays_B.Sum7_f[2] =
      sel751test_model_1_3_ss_relays_B.Integ4_cl[2] -
      sel751test_model_1_3_ss_relays_B.SFunction_of[2];

    /* Product: '<S144>/Product' incorporates:
     *  Constant: '<S144>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_p[0] =
      sel751test_model_1_3_ss_relays_B.Sum7_f[0] *
      sel751test_model_1_3_ss_relays_P.K2_Value_pu;
    sel751test_model_1_3_ss_relays_B.Meanvalue_p[1] =
      sel751test_model_1_3_ss_relays_B.Sum7_f[1] *
      sel751test_model_1_3_ss_relays_P.K2_Value_pu;
    sel751test_model_1_3_ss_relays_B.Meanvalue_p[2] =
      sel751test_model_1_3_ss_relays_B.Sum7_f[2] *
      sel751test_model_1_3_ss_relays_P.K2_Value_pu;

    /* Sum: '<S144>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_mz[0] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_p[0] +
      sel751test_model_1_3_ss_relays_B.Correction_n[0];
    sel751test_model_1_3_ss_relays_B.Sum5_mz[1] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_p[1] +
      sel751test_model_1_3_ss_relays_B.Correction_n[1];
    sel751test_model_1_3_ss_relays_B.Sum5_mz[2] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_p[2] +
      sel751test_model_1_3_ss_relays_B.Correction_n[2];
    sel751test_model_1_3_ss_relays_B.Switch_as[0] =
      sel751test_model_1_3_ss_relays_B.Sum5_mz[0];
    sel751test_model_1_3_ss_relays_B.Switch_as[1] =
      sel751test_model_1_3_ss_relays_B.Sum5_mz[1];
    sel751test_model_1_3_ss_relays_B.Switch_as[2] =
      sel751test_model_1_3_ss_relays_B.Sum5_mz[2];
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_as[0] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_ic;
    sel751test_model_1_3_ss_relays_B.Switch_as[1] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_ic;
    sel751test_model_1_3_ss_relays_B.Switch_as[2] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_ic;
  }

  /* End of Switch: '<S144>/Switch' */

  /* Sqrt: '<S109>/Signed Sqrt' */
  sel751test_model_1_3_ss_relays_B.SignedSqrt_d[0] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_as[0]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt_d[1] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_as[1]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt_d[2] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_as[2]);

  /* Gain: '<S114>/Gain' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Gain_m =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_pd *
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[1];

  /* Switch: '<S111>/Switch' incorporates:
   *  Constant: '<S111>/group#1 - gridtied parameters'
   *  Constant: '<S111>/group#2 - islanded parameters'
   */
  if (sel751test_model_1_3_ss_relays_B.SFunction_o[5] >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_o) {
    for (i = 0; i < 7; i++) {
      sel751test_model_1_3_ss_relays_B.Switch_d[i] =
        sel751test_model_1_3_ss_relays_P.group2islandedparameters_Valu_n[i];
    }
  } else {
    for (i = 0; i < 7; i++) {
      sel751test_model_1_3_ss_relays_B.Switch_d[i] =
        sel751test_model_1_3_ss_relays_P.group1gridtiedparameters_Valu_b[i];
    }
  }

  /* End of Switch: '<S111>/Switch' */

  /* MATLAB Function: '<S114>/Relays' incorporates:
   *  Constant: '<S111>/base parameters'
   *  Constant: '<S114>/a4'
   */
  sel751test_model_1_3_ss__Relays
    (sel751test_model_1_3_ss_relays_B.RelationalOperator_n,
     sel751test_model_1_3_ss_relays_P.a4_Value_l,
     sel751test_model_1_3_ss_relays_B.DataTypeConversion3_l,
     &sel751test_model_1_3_ss_relays_B.SFunction_l[11],
     sel751test_model_1_3_ss_relays_B.SignedSqrt_p,
     sel751test_model_1_3_ss_relays_B.SignedSqrt_d,
     sel751test_model_1_3_ss_relays_B.Gain_m,
     sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[6],
     sel751test_model_1_3_ss_relays_B.Switch_d[0],
     sel751test_model_1_3_ss_relays_B.Switch_d[1],
     sel751test_model_1_3_ss_relays_B.Switch_d[2],
     sel751test_model_1_3_ss_relays_B.Switch_d[3],
     sel751test_model_1_3_ss_relays_B.Switch_d[4],
     sel751test_model_1_3_ss_relays_B.Switch_d[5],
     sel751test_model_1_3_ss_relays_B.Switch_d[6],
     sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[5],
     &sel751test_model_1_3_ss_relays_B.sf_Relays_c,
     &sel751test_model_1_3_ss_relays_DW.sf_Relays_c);

  /* Logic: '<S6>/Logical Operator4' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator4_o =
    (sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip50 ||
     sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip51 ||
     sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip27 ||
     sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip59);

  /* Logic: '<S6>/Logical Operator' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator_fs =
    !sel751test_model_1_3_ss_relays_B.LogicalOperator4_o;

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  sel751test_model_1_3_ss_relays_B.trip_in_n =
    sel751test_model_1_3_ss_relays_B.LogicalOperator_fs;

  /* DataTypeConversion: '<S6>/Data Type Conversion2' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion2_p =
    sel751test_model_1_3_ss_relays_B.Logic_trip_h;

  /* DataTypeConversion: '<S6>/Data Type Conversion3' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion3_a[0] =
    sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_i;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion3_a[1] =
    sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_j;

  /* DataTypeConversion: '<S6>/Data Type Conversion4' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion4_e[0] =
    sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip50;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion4_e[1] =
    sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip51;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion4_e[2] =
    sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip27;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion4_e[3] =
    sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip59;

  /* DataTypeConversion: '<S6>/Data Type Conversion5' */
  sel751test_model_1_3_ss_relays_B.reset_j =
    (sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator_h != 0);

  /* DataTypeConversion: '<S6>/Data Type Conversion6' */
  sel751test_model_1_3_ss_relays_B.Status_n =
    (sel751test_model_1_3_ss_relays_B.Logic_trip_h != 0.0);

  /* Gain: '<S6>/Gain2' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Gain2_m =
    sel751test_model_1_3_ss_relays_P.Gain2_Gain_e *
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[1];

  /* Product: '<S6>/Divide2' */
  sel751test_model_1_3_ss_relays_B.Vpu_n =
    sel751test_model_1_3_ss_relays_B.SignedSqrt_d[0] /
    sel751test_model_1_3_ss_relays_B.Gain2_m;

  /* Gain: '<S6>/Gain' */
  sel751test_model_1_3_ss_relays_B.Gain_d =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_j2 *
    sel751test_model_1_3_ss_relays_B.DataTypeConversion4_e[1];

  /* Gain: '<S6>/Gain1' */
  sel751test_model_1_3_ss_relays_B.Gain1_az =
    sel751test_model_1_3_ss_relays_P.Gain1_Gain_h *
    sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_a;

  /* Gain: '<S6>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10_dl =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain_b *
    sel751test_model_1_3_ss_relays_B.Switch_m[0];

  /* Sum: '<S107>/Add2' incorporates:
   *  Constant: '<S107>/Constant5'
   */
  sel751test_model_1_3_ss_relays_B.Add2_j =
    sel751test_model_1_3_ss_relays_B.MathFunction_k -
    sel751test_model_1_3_ss_relays_P.Constant5_Value_l;

  /* Math: '<S107>/Math Function' incorporates:
   *  Constant: '<S107>/Constant7'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_b = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.Add2_j,
     sel751test_model_1_3_ss_relays_P.Constant7_Value_m);

  /* Gain: '<S6>/Gain11' */
  sel751test_model_1_3_ss_relays_B.Gain11_e =
    sel751test_model_1_3_ss_relays_P.Gain11_Gain_b *
    sel751test_model_1_3_ss_relays_B.MathFunction_b;

  /* Gain: '<S6>/Gain12' */
  sel751test_model_1_3_ss_relays_B.Gain12_j =
    sel751test_model_1_3_ss_relays_P.Gain12_Gain_a *
    sel751test_model_1_3_ss_relays_B.MathFunction_k;

  /* Gain: '<S6>/Gain13' */
  sel751test_model_1_3_ss_relays_B.Gain13_o =
    sel751test_model_1_3_ss_relays_P.Gain13_Gain_b *
    sel751test_model_1_3_ss_relays_B.DataTypeConversion4_e[3];

  /* Gain: '<S6>/Gain14' */
  sel751test_model_1_3_ss_relays_B.Gain14_f =
    sel751test_model_1_3_ss_relays_P.Gain14_Gain_d *
    sel751test_model_1_3_ss_relays_B.DataTypeConversion2_p;

  /* Gain: '<S6>/Gain15' */
  sel751test_model_1_3_ss_relays_B.Gain15_a =
    sel751test_model_1_3_ss_relays_P.Gain15_Gain_f *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_p[0];

  /* Gain: '<S6>/Gain16' */
  sel751test_model_1_3_ss_relays_B.Gain16_j =
    sel751test_model_1_3_ss_relays_P.Gain16_Gain_k *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_p[1];

  /* Gain: '<S6>/Gain17' */
  sel751test_model_1_3_ss_relays_B.Gain17_l =
    sel751test_model_1_3_ss_relays_P.Gain17_Gain_c *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_p[2];

  /* Gain: '<S6>/Gain18' */
  sel751test_model_1_3_ss_relays_B.Gain18_d =
    sel751test_model_1_3_ss_relays_P.Gain18_Gain_d *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_d[0];

  /* Gain: '<S6>/Gain19' */
  sel751test_model_1_3_ss_relays_B.Gain19_g =
    sel751test_model_1_3_ss_relays_P.Gain19_Gain_c *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_d[1];

  /* Gain: '<S6>/Gain20' */
  sel751test_model_1_3_ss_relays_B.Gain20_m =
    sel751test_model_1_3_ss_relays_P.Gain20_Gain_b *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_d[2];

  /* Sum: '<S106>/Add3' incorporates:
   *  Constant: '<S106>/Constant6'
   */
  sel751test_model_1_3_ss_relays_B.Add3_i =
    sel751test_model_1_3_ss_relays_B.MathFunction_nc +
    sel751test_model_1_3_ss_relays_P.Constant6_Value_j;

  /* Math: '<S106>/Math Function1' incorporates:
   *  Constant: '<S106>/Constant8'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction1_b = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.Add3_i,
     sel751test_model_1_3_ss_relays_P.Constant8_Value_m);

  /* Gain: '<S6>/Gain3' */
  sel751test_model_1_3_ss_relays_B.Gain3_d =
    sel751test_model_1_3_ss_relays_P.Gain3_Gain_e *
    sel751test_model_1_3_ss_relays_B.MathFunction1_b;

  /* Gain: '<S6>/Gain4' */
  sel751test_model_1_3_ss_relays_B.Gain4_h =
    sel751test_model_1_3_ss_relays_P.Gain4_Gain_k *
    sel751test_model_1_3_ss_relays_B.UnitDelay_b3;

  /* Sum: '<S106>/Add2' incorporates:
   *  Constant: '<S106>/Constant5'
   */
  sel751test_model_1_3_ss_relays_B.Add2_l =
    sel751test_model_1_3_ss_relays_B.MathFunction_nc -
    sel751test_model_1_3_ss_relays_P.Constant5_Value_f;

  /* Math: '<S106>/Math Function' incorporates:
   *  Constant: '<S106>/Constant7'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_dh = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.Add2_l,
     sel751test_model_1_3_ss_relays_P.Constant7_Value_e);

  /* Gain: '<S6>/Gain5' */
  sel751test_model_1_3_ss_relays_B.Gain5_n =
    sel751test_model_1_3_ss_relays_P.Gain5_Gain_n *
    sel751test_model_1_3_ss_relays_B.MathFunction_dh;

  /* Gain: '<S6>/Gain6' */
  sel751test_model_1_3_ss_relays_B.Gain6_p =
    sel751test_model_1_3_ss_relays_P.Gain6_Gain_e *
    sel751test_model_1_3_ss_relays_B.Switch_m[1];

  /* Gain: '<S6>/Gain7' */
  sel751test_model_1_3_ss_relays_B.Gain7_l =
    sel751test_model_1_3_ss_relays_P.Gain7_Gain_a *
    sel751test_model_1_3_ss_relays_B.Fcn_p;

  /* Gain: '<S6>/Gain8' */
  sel751test_model_1_3_ss_relays_B.Gain8_p =
    sel751test_model_1_3_ss_relays_P.Gain8_Gain_i *
    sel751test_model_1_3_ss_relays_B.MathFunction_nc;

  /* Sum: '<S107>/Add3' incorporates:
   *  Constant: '<S107>/Constant6'
   */
  sel751test_model_1_3_ss_relays_B.Add3_f =
    sel751test_model_1_3_ss_relays_B.MathFunction_k +
    sel751test_model_1_3_ss_relays_P.Constant6_Value_i;

  /* Math: '<S107>/Math Function1' incorporates:
   *  Constant: '<S107>/Constant8'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction1_gd = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.Add3_f,
     sel751test_model_1_3_ss_relays_P.Constant8_Value_a);

  /* Gain: '<S6>/Gain9' */
  sel751test_model_1_3_ss_relays_B.Gain9_p =
    sel751test_model_1_3_ss_relays_P.Gain9_Gain_i *
    sel751test_model_1_3_ss_relays_B.MathFunction1_gd;

  /* DataTypeConversion: '<S104>/Data Type Conversion1' incorporates:
   *  Constant: '<S104>/never_reset'
   */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion1_n =
    (sel751test_model_1_3_ss_relays_P.never_reset_Value_m != 0.0);

  /* UnitDelay: '<S137>/Delay Input1' */
  sel751test_model_1_3_ss_relays_B.Uk1_l =
    sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE_a;

  /* RelationalOperator: '<S137>/FixPt Relational Operator' */
  sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator_p =
    (sel751test_model_1_3_ss_relays_B.SFunction_o[4] !=
     sel751test_model_1_3_ss_relays_B.Uk1_l);

  /* Memory: '<S138>/Memory' */
  sel751test_model_1_3_ss_relays_B.Memory_j =
    sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput_g;

  /* CombinatorialLogic: '<S138>/Logic' */
  unnamed_idx = sel751test_model_1_3_ss_relays_B.FixPtRelationalOperator_p;
  i = unnamed_idx;
  unnamed_idx = sel751test_model_1_3_ss_relays_B.DataTypeConversion1_n;
  i = (int32_T)(((uint32_T)i << 1) + unnamed_idx);
  unnamed_idx = sel751test_model_1_3_ss_relays_B.Memory_j;
  i = (int32_T)(((uint32_T)i << 1) + unnamed_idx);
  sel751test_model_1_3_ss_relays_B.Logic_h[0U] =
    sel751test_model_1_3_ss_relays_P.Logic_table_d[(uint32_T)i];
  sel751test_model_1_3_ss_relays_B.Logic_h[1U] =
    sel751test_model_1_3_ss_relays_P.Logic_table_d[i + 8U];

  /* Product: '<S148>/Product3' */
  sel751test_model_1_3_ss_relays_B.Product3_f[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[14] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[14];
  sel751test_model_1_3_ss_relays_B.Product3_f[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[17] *
    sel751test_model_1_3_ss_relays_B.SFunction_l[17];

  /* DiscreteIntegrator: '<S154>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_h != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_ef[0] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_p[0];
    sel751test_model_1_3_ss_relays_B.Integ4_ef[1] =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_p[1];
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_ef[0] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_an *
      sel751test_model_1_3_ss_relays_B.Product3_f[0] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_p[0];
    sel751test_model_1_3_ss_relays_B.Integ4_ef[1] =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_an *
      sel751test_model_1_3_ss_relays_B.Product3_f[1] +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_p[1];
  }

  /* End of DiscreteIntegrator: '<S154>/Integ4' */
  /* S-Function block: <S155>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers[0])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_ef[0];
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers[1])
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_ef[1];

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_P.K1_Value_gb/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_li[0] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers[0])
      [indDelayed];
    sel751test_model_1_3_ss_relays_B.SFunction_li[1] = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers[1])
      [indDelayed];
  }

  /* UnitDelay: '<S154>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_ny[0] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ea[0];
  sel751test_model_1_3_ss_relays_B.UnitDelay_ny[1] =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ea[1];

  /* Step: '<S154>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_cd) {
    sel751test_model_1_3_ss_relays_B.Step_px =
      sel751test_model_1_3_ss_relays_P.Step_Y0_n;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_px =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_h;
  }

  /* End of Step: '<S154>/Step' */

  /* Switch: '<S154>/Switch' incorporates:
   *  Constant: '<S154>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_px >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_kt) {
    /* Gain: '<S154>/Gain' */
    sel751test_model_1_3_ss_relays_B.Gain_f[0] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_k *
      sel751test_model_1_3_ss_relays_B.UnitDelay_ny[0];
    sel751test_model_1_3_ss_relays_B.Gain_f[1] =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_k *
      sel751test_model_1_3_ss_relays_B.UnitDelay_ny[1];

    /* Gain: '<S154>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_n[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_i *
      sel751test_model_1_3_ss_relays_B.Product3_f[0];
    sel751test_model_1_3_ss_relays_B.Gain1_n[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_i *
      sel751test_model_1_3_ss_relays_B.Product3_f[1];

    /* Sum: '<S154>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Correction[0] =
      sel751test_model_1_3_ss_relays_B.Gain1_n[0] -
      sel751test_model_1_3_ss_relays_B.Gain_f[0];
    sel751test_model_1_3_ss_relays_B.Correction[1] =
      sel751test_model_1_3_ss_relays_B.Gain1_n[1] -
      sel751test_model_1_3_ss_relays_B.Gain_f[1];

    /* Sum: '<S154>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_l[0] =
      sel751test_model_1_3_ss_relays_B.Integ4_ef[0] -
      sel751test_model_1_3_ss_relays_B.SFunction_li[0];
    sel751test_model_1_3_ss_relays_B.Sum7_l[1] =
      sel751test_model_1_3_ss_relays_B.Integ4_ef[1] -
      sel751test_model_1_3_ss_relays_B.SFunction_li[1];

    /* Product: '<S154>/Product' incorporates:
     *  Constant: '<S154>/K2'
     */
    sel751test_model_1_3_ss_relays_B.Meanvalue_o[0] =
      sel751test_model_1_3_ss_relays_B.Sum7_l[0] *
      sel751test_model_1_3_ss_relays_P.K2_Value_l;
    sel751test_model_1_3_ss_relays_B.Meanvalue_o[1] =
      sel751test_model_1_3_ss_relays_B.Sum7_l[1] *
      sel751test_model_1_3_ss_relays_P.K2_Value_l;

    /* Sum: '<S154>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_g0[0] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_o[0] +
      sel751test_model_1_3_ss_relays_B.Correction[0];
    sel751test_model_1_3_ss_relays_B.Sum5_g0[1] =
      sel751test_model_1_3_ss_relays_B.Meanvalue_o[1] +
      sel751test_model_1_3_ss_relays_B.Correction[1];
    sel751test_model_1_3_ss_relays_B.Switch_h[0] =
      sel751test_model_1_3_ss_relays_B.Sum5_g0[0];
    sel751test_model_1_3_ss_relays_B.Switch_h[1] =
      sel751test_model_1_3_ss_relays_B.Sum5_g0[1];
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_h[0] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_af;
    sel751test_model_1_3_ss_relays_B.Switch_h[1] =
      sel751test_model_1_3_ss_relays_P.Constant_Value_af;
  }

  /* End of Switch: '<S154>/Switch' */

  /* Sqrt: '<S148>/Signed Sqrt' */
  sel751test_model_1_3_ss_relays_B.SignedSqrt_o[0] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_h[0]);
  sel751test_model_1_3_ss_relays_B.SignedSqrt_o[1] = sqrt
    (sel751test_model_1_3_ss_relays_B.Switch_h[1]);

  /* Gain: '<S110>/sqrt3' */
  sel751test_model_1_3_ss_relays_B.sqrt3_o[0] =
    sel751test_model_1_3_ss_relays_P.sqrt3_Gain_o *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_o[0];
  sel751test_model_1_3_ss_relays_B.sqrt3_o[1] =
    sel751test_model_1_3_ss_relays_P.sqrt3_Gain_o *
    sel751test_model_1_3_ss_relays_B.SignedSqrt_o[1];

  /* MATLAB Function: '<S110>/deadbus fcn' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_deadbusfcn(sel751test_model_1_3_ss_relays_B.sqrt3_o[0],
    sel751test_model_1_3_ss_relays_B.sqrt3_o[1],
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[1],
    &sel751test_model_1_3_ss_relays_B.sf_deadbusfcn_l);

  /* Fcn: '<S110>/Fcn' */
  sel751test_model_1_3_ss_relays_B.Fcn_f =
    (sel751test_model_1_3_ss_relays_B.SFunction_o[4] == 2.0);

  /* Product: '<S150>/Product' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Product_d =
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[1] *
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[2];

  /* Fcn: '<S150>/Fcn2' */
  sel751test_model_1_3_ss_relays_B.thshld_g = (fabs
    (sel751test_model_1_3_ss_relays_B.sqrt3_o[1] -
     sel751test_model_1_3_ss_relays_B.sqrt3_o[0]) <=
    sel751test_model_1_3_ss_relays_B.Product_d);

  /* UnitDelay: '<S157>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_cu =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jm;

  /* UnitDelay: '<S156>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_jf =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_im;

  /* Fcn: '<S146>/Fcn2' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Fcn2_l = (fabs
    (sel751test_model_1_3_ss_relays_B.UnitDelay_jf -
     sel751test_model_1_3_ss_relays_B.UnitDelay_cu) <=
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[4]);

  /* DiscreteIntegrator: '<S157>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_a =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_ii;

  /* Math: '<S157>/Math Function' incorporates:
   *  Constant: '<S157>/Constant4'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_iq = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_a,
     sel751test_model_1_3_ss_relays_P.Constant4_Value_i);

  /* DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_g5 =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_f;

  /* Math: '<S156>/Math Function' incorporates:
   *  Constant: '<S156>/Constant4'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_n3 = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_g5,
     sel751test_model_1_3_ss_relays_P.Constant4_Value_op);

  /* SignalConversion: '<S147>/TmpSignal ConversionAtMath FunctionInport1' */
  sel751test_model_1_3_ss_relays_B.TmpSignalConversionAtMathFunc_p[0] =
    sel751test_model_1_3_ss_relays_B.MathFunction_iq;
  sel751test_model_1_3_ss_relays_B.TmpSignalConversionAtMathFunc_p[1] =
    sel751test_model_1_3_ss_relays_B.MathFunction_n3;

  /* Math: '<S147>/Math Function' incorporates:
   *  Constant: '<S147>/Constant3'
   */
  sel751test_model_1_3_ss_relays_B.MathFunction_a[0] = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.TmpSignalConversionAtMathFunc_p[0],
     sel751test_model_1_3_ss_relays_P.Constant3_Value_p);
  sel751test_model_1_3_ss_relays_B.MathFunction_a[1] = rt_modd_snf
    (sel751test_model_1_3_ss_relays_B.TmpSignalConversionAtMathFunc_p[1],
     sel751test_model_1_3_ss_relays_P.Constant3_Value_p);

  /* S-Function (sdspunwrap2): '<S147>/Unwrap' */
  if (sel751test_model_1_3_ss_relays_DW.Unwrap_FirstStep_b) {
    sel751test_model_1_3_ss_relays_DW.Unwrap_Prev_a =
      sel751test_model_1_3_ss_relays_B.MathFunction_a[0];
    sel751test_model_1_3_ss_relays_DW.Unwrap_FirstStep_b = FALSE;
  }

  u_0 = sel751test_model_1_3_ss_relays_DW.Unwrap_Cumsum_b;
  dsp2Pi = sel751test_model_1_3_ss_relays_DW.Unwrap_Prev_a;
  dp = sel751test_model_1_3_ss_relays_B.MathFunction_a[0] - dsp2Pi;
  u = (dp + 3.1415926535897931) / 6.2831853071795862;
  u = floor(u);
  dsp2Pi = dp - 6.2831853071795862 * u;
  if ((dsp2Pi == -3.1415926535897931) && (dp > 0.0)) {
    dsp2Pi = 3.1415926535897931;
  }

  dsp2Pi -= dp;
  if (fabs(dsp2Pi) > sel751test_model_1_3_ss_relays_ConstP.pooled1) {
    u_0 += dsp2Pi;
  }

  dsp2Pi = sel751test_model_1_3_ss_relays_B.MathFunction_a[0];
  sel751test_model_1_3_ss_relays_B.Unwrap_p[0] =
    sel751test_model_1_3_ss_relays_B.MathFunction_a[0] + u_0;
  dp = sel751test_model_1_3_ss_relays_B.MathFunction_a[1] - dsp2Pi;
  u = (dp + 3.1415926535897931) / 6.2831853071795862;
  u = floor(u);
  dsp2Pi = dp - 6.2831853071795862 * u;
  if ((dsp2Pi == -3.1415926535897931) && (dp > 0.0)) {
    dsp2Pi = 3.1415926535897931;
  }

  dsp2Pi -= dp;
  if (fabs(dsp2Pi) > sel751test_model_1_3_ss_relays_ConstP.pooled1) {
    u_0 += dsp2Pi;
  }

  dsp2Pi = sel751test_model_1_3_ss_relays_B.MathFunction_a[1];
  sel751test_model_1_3_ss_relays_B.Unwrap_p[1] =
    sel751test_model_1_3_ss_relays_B.MathFunction_a[1] + u_0;
  sel751test_model_1_3_ss_relays_DW.Unwrap_Prev_a = dsp2Pi;
  sel751test_model_1_3_ss_relays_DW.Unwrap_Cumsum_b = u_0;

  /* End of S-Function (sdspunwrap2): '<S147>/Unwrap' */

  /* Fcn: '<S147>/Fcn3' */
  sel751test_model_1_3_ss_relays_B.diff_o = fabs
    (sel751test_model_1_3_ss_relays_B.Unwrap_p[1] -
     sel751test_model_1_3_ss_relays_B.Unwrap_p[0]);

  /* Gain: '<S153>/Gain' */
  sel751test_model_1_3_ss_relays_B.Gain_pk =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_e *
    sel751test_model_1_3_ss_relays_B.diff_o;

  /* Fcn: '<S147>/Fcn1' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.bool_h =
    (sel751test_model_1_3_ss_relays_B.Gain_pk <=
     sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[3]);

  /* Logic: '<S110>/Logical Operator' */
  sel751test_model_1_3_ss_relays_B.dVdFdW_c =
    ((sel751test_model_1_3_ss_relays_B.thshld_g != 0.0) &&
     (sel751test_model_1_3_ss_relays_B.Fcn2_l != 0.0) &&
     (sel751test_model_1_3_ss_relays_B.bool_h != 0.0));

  /* Logic: '<S110>/Logical Operator1' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator1_gn =
    (sel751test_model_1_3_ss_relays_B.LogicalOperator4_o ||
     (sel751test_model_1_3_ss_relays_B.Fcn_f != 0.0) ||
     sel751test_model_1_3_ss_relays_B.dVdFdW_c);

  /* Memory: '<S149>/Memory' */
  sel751test_model_1_3_ss_relays_B.Memory_jt =
    sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput_h;

  /* CombinatorialLogic: '<S149>/Logic' */
  unnamed_idx = sel751test_model_1_3_ss_relays_B.sf_deadbusfcn_l.y;
  i = unnamed_idx;
  unnamed_idx = sel751test_model_1_3_ss_relays_B.LogicalOperator1_gn;
  i = (int32_T)(((uint32_T)i << 1) + unnamed_idx);
  unnamed_idx = sel751test_model_1_3_ss_relays_B.Memory_jt;
  i = (int32_T)(((uint32_T)i << 1) + unnamed_idx);
  sel751test_model_1_3_ss_relays_B.Logic_b[0U] =
    sel751test_model_1_3_ss_relays_P.Logic_table_f[(uint32_T)i];
  sel751test_model_1_3_ss_relays_B.Logic_b[1U] =
    sel751test_model_1_3_ss_relays_P.Logic_table_f[i + 8U];

  /* Logic: '<S110>/Logical Operator3' */
  sel751test_model_1_3_ss_relays_B.LogicalOperator3_d =
    (sel751test_model_1_3_ss_relays_B.Logic_b[0] ||
     sel751test_model_1_3_ss_relays_B.dVdFdW_c);

  /* MATLAB Function: '<S6>/trip_out mng' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant4'
   */
  sel751test_model_1__trip_outmng
    (sel751test_model_1_3_ss_relays_P.Constant4_Value_b,
     sel751test_model_1_3_ss_relays_B.LogicalOperator3_d,
     sel751test_model_1_3_ss_relays_B.SFunction_o[4],
     sel751test_model_1_3_ss_relays_B.trip_in_n,
     sel751test_model_1_3_ss_relays_P.Constant1_Value_j,
     sel751test_model_1_3_ss_relays_B.DigitalClock_p,
     sel751test_model_1_3_ss_relays_P.Constant2_Value_e,
     &sel751test_model_1_3_ss_relays_B.sf_trip_outmng_a,
     &sel751test_model_1_3_ss_relays_DW.sf_trip_outmng_a);

  /* Switch: '<S104>/Switch' */
  if (sel751test_model_1_3_ss_relays_B.Logic_h[0]) {
    sel751test_model_1_3_ss_relays_B.Logic_out_p =
      sel751test_model_1_3_ss_relays_B.sf_trip_outmng_a.trip_out;
  } else {
    /* Fcn: '<S104>/Fcn' incorporates:
     *  Constant: '<S111>/base parameters'
     */
    sel751test_model_1_3_ss_relays_B.Fcn_f2 =
      (sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[7] != 0.0);

    /* DataTypeConversion: '<S104>/Data Type Conversion' */
    sel751test_model_1_3_ss_relays_B.DataTypeConversion =
      sel751test_model_1_3_ss_relays_B.Fcn_f2;
    sel751test_model_1_3_ss_relays_B.Logic_out_p =
      sel751test_model_1_3_ss_relays_B.DataTypeConversion;
  }

  /* End of Switch: '<S104>/Switch' */

  /* Memory: '<S6>/Memory2' */
  sel751test_model_1_3_ss_relays_B.Memory2_n =
    sel751test_model_1_3_ss_relays_DW.Memory2_PreviousInput_j;

  /* Memory: '<S6>/Memory9' */
  sel751test_model_1_3_ss_relays_B.Memory9_g =
    sel751test_model_1_3_ss_relays_DW.Memory9_PreviousInput_i;

  /* Product: '<S152>/Divide' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Divide_b =
    sel751test_model_1_3_ss_relays_B.SFunction_l[17] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[1];

  /* Trigonometry: '<S156>/Trigonometric Function2' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_e = cos
    (sel751test_model_1_3_ss_relays_B.MathFunction_n3);

  /* Product: '<S156>/Product1' */
  sel751test_model_1_3_ss_relays_B.Vq_l =
    sel751test_model_1_3_ss_relays_B.Divide_b *
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_e;

  /* DiscreteIntegrator: '<S162>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_bf != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_p =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_pp;
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_p =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_p *
      sel751test_model_1_3_ss_relays_B.Vq_l +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_pp;
  }

  /* End of DiscreteIntegrator: '<S162>/Integ4' */

  /* Saturate: '<S162>/To avoid division by zero' */
  u = sel751test_model_1_3_ss_relays_B.UnitDelay_jf;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerS_hk;
  u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperSa_o;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Freq_o = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Freq_o = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Freq_o = u;
  }

  /* End of Saturate: '<S162>/To avoid division by zero' */

  /* Fcn: '<S162>/Number of samples per cycle' */
  sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_c = 1.0 /
    sel751test_model_1_3_ss_relays_B.Freq_o / 0.0001;

  /* Rounding: '<S162>/Rounding Function' */
  sel751test_model_1_3_ss_relays_B.RoundingFunction_l = ceil
    (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_c);

  /* Gain: '<S162>/Gain' */
  sel751test_model_1_3_ss_relays_B.Delay_o =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_jk *
    sel751test_model_1_3_ss_relays_B.RoundingFunction_l;

  /* S-Function block: <S173>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o3.uBuffers)
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_p;

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_o/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_e0 = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o3.uBuffers)[indDelayed];
  }

  /* UnitDelay: '<S172>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_cv =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_l0;

  /* Step: '<S162>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_eq) {
    sel751test_model_1_3_ss_relays_B.Step_d =
      sel751test_model_1_3_ss_relays_P.Step_Y0_a;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_d =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_pi;
  }

  /* End of Step: '<S162>/Step' */

  /* Switch: '<S162>/Switch' incorporates:
   *  Constant: '<S162>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_d >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_kq) {
    /* Sum: '<S172>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Sum1_lc =
      sel751test_model_1_3_ss_relays_B.Vq_l -
      sel751test_model_1_3_ss_relays_B.UnitDelay_cv;

    /* Sum: '<S172>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_i =
      sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_c -
      sel751test_model_1_3_ss_relays_B.RoundingFunction_l;

    /* Product: '<S172>/Product5' */
    sel751test_model_1_3_ss_relays_B.Product5_o =
      sel751test_model_1_3_ss_relays_B.Sum5_i *
      sel751test_model_1_3_ss_relays_B.Sum1_lc;

    /* Gain: '<S172>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_l =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_mj *
      sel751test_model_1_3_ss_relays_B.Product5_o;

    /* Sum: '<S172>/Sum4' */
    sel751test_model_1_3_ss_relays_B.Sum4_g =
      sel751test_model_1_3_ss_relays_B.Gain1_l +
      sel751test_model_1_3_ss_relays_B.Vq_l;

    /* Product: '<S172>/Product2' */
    sel751test_model_1_3_ss_relays_B.Product2_f =
      sel751test_model_1_3_ss_relays_B.Sum5_i /
      sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_c;

    /* Product: '<S172>/Product4' */
    sel751test_model_1_3_ss_relays_B.Product4_l =
      sel751test_model_1_3_ss_relays_B.Product2_f *
      sel751test_model_1_3_ss_relays_B.Sum4_g;

    /* Sum: '<S162>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7_a =
      sel751test_model_1_3_ss_relays_B.Integ4_p -
      sel751test_model_1_3_ss_relays_B.SFunction_e0;

    /* Product: '<S162>/Product' */
    sel751test_model_1_3_ss_relays_B.Meanvalue_f =
      sel751test_model_1_3_ss_relays_B.Sum7_a *
      sel751test_model_1_3_ss_relays_B.UnitDelay_jf;

    /* Sum: '<S162>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_ct =
      sel751test_model_1_3_ss_relays_B.Meanvalue_f +
      sel751test_model_1_3_ss_relays_B.Product4_l;
    sel751test_model_1_3_ss_relays_B.Switch_m2 =
      sel751test_model_1_3_ss_relays_B.Sum5_ct;
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_m2 =
      sel751test_model_1_3_ss_relays_P.Constant_Value_fn;
  }

  /* End of Switch: '<S162>/Switch' */

  /* Trigonometry: '<S156>/Trigonometric Function' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction_cx = sin
    (sel751test_model_1_3_ss_relays_B.MathFunction_n3);

  /* Outputs for Enabled SubSystem: '<S156>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S159>/Enable'
   */
  /* Constant: '<S156>/Constant1' */
  if (sel751test_model_1_3_ss_relays_P.Constant1_Value_l > 0.0) {
    if (!sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_m) {
      /* Enable for DiscreteIntegrator: '<S165>/Integ4' */
      sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_kt = 1U;

      /* Enable for DiscreteIntegrator: '<S166>/Integ4' */
      sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_ds = 1U;
      sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_m = TRUE;
    }

    /* Gain: '<S163>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_o[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_pd *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction_cx;
    sel751test_model_1_3_ss_relays_B.Gain1_o[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_pd *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_e;

    /* Product: '<S163>/Product' */
    sel751test_model_1_3_ss_relays_B.Product_a[0] =
      sel751test_model_1_3_ss_relays_B.Divide_b *
      sel751test_model_1_3_ss_relays_B.Gain1_o[0];
    sel751test_model_1_3_ss_relays_B.Product_a[1] =
      sel751test_model_1_3_ss_relays_B.Divide_b *
      sel751test_model_1_3_ss_relays_B.Gain1_o[1];

    /* DiscreteIntegrator: '<S165>/Integ4' */
    if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_kt != 0) {
      sel751test_model_1_3_ss_relays_B.Integ4_cf =
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_my;
    } else {
      sel751test_model_1_3_ss_relays_B.Integ4_cf =
        sel751test_model_1_3_ss_relays_P.Integ4_gainval_c *
        sel751test_model_1_3_ss_relays_B.Product_a[0] +
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_my;
    }

    /* End of DiscreteIntegrator: '<S165>/Integ4' */

    /* Saturate: '<S165>/To avoid division by zero' */
    u = sel751test_model_1_3_ss_relays_B.UnitDelay_jf;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerSa_f;
    u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperSa_a;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Freq_j = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Freq_j = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Freq_j = u;
    }

    /* End of Saturate: '<S165>/To avoid division by zero' */

    /* Fcn: '<S165>/Number of samples per cycle' */
    sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_k = 1.0 /
      sel751test_model_1_3_ss_relays_B.Freq_j / 0.0001;

    /* Rounding: '<S165>/Rounding Function' */
    sel751test_model_1_3_ss_relays_B.RoundingFunction_a = ceil
      (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_k);

    /* Gain: '<S165>/Gain' */
    sel751test_model_1_3_ss_relays_B.Delay_at =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_lv *
      sel751test_model_1_3_ss_relays_B.RoundingFunction_a;

    /* S-Function block: <S168>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e5.uBuffers)
        [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.indEnd] =
        sel751test_model_1_3_ss_relays_B.Integ4_cf;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_at/0.0001) + 0.5);
      if (discreteDelay >
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.maxDiscrDelay)
        discreteDelay =
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.maxDiscrDelay;
      indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed +=
            sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.bufSz;
      }

      /* Output past value(s) */
      sel751test_model_1_3_ss_relays_B.SFunction_mq = ((real_T *)
        sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e5.uBuffers)
        [indDelayed];
    }

    /* UnitDelay: '<S167>/Unit Delay' */
    sel751test_model_1_3_ss_relays_B.UnitDelay_dg =
      sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ir;

    /* Step: '<S165>/Step' */
    dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
    if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_c) {
      sel751test_model_1_3_ss_relays_B.Step_e =
        sel751test_model_1_3_ss_relays_P.Step_Y0_j;
    } else {
      sel751test_model_1_3_ss_relays_B.Step_e =
        sel751test_model_1_3_ss_relays_P.Step_YFinal_jv;
    }

    /* End of Step: '<S165>/Step' */

    /* Switch: '<S165>/Switch' incorporates:
     *  Constant: '<S165>/Constant'
     */
    if (sel751test_model_1_3_ss_relays_B.Step_e >=
        sel751test_model_1_3_ss_relays_P.Switch_Threshold_a) {
      /* Sum: '<S167>/Sum1' */
      sel751test_model_1_3_ss_relays_B.Sum1_ol =
        sel751test_model_1_3_ss_relays_B.Product_a[0] -
        sel751test_model_1_3_ss_relays_B.UnitDelay_dg;

      /* Sum: '<S167>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_d3 =
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_k -
        sel751test_model_1_3_ss_relays_B.RoundingFunction_a;

      /* Product: '<S167>/Product5' */
      sel751test_model_1_3_ss_relays_B.Product5_l =
        sel751test_model_1_3_ss_relays_B.Sum5_d3 *
        sel751test_model_1_3_ss_relays_B.Sum1_ol;

      /* Gain: '<S167>/Gain1' */
      sel751test_model_1_3_ss_relays_B.Gain1_d =
        sel751test_model_1_3_ss_relays_P.Gain1_Gain_p *
        sel751test_model_1_3_ss_relays_B.Product5_l;

      /* Sum: '<S167>/Sum4' */
      sel751test_model_1_3_ss_relays_B.Sum4_c =
        sel751test_model_1_3_ss_relays_B.Gain1_d +
        sel751test_model_1_3_ss_relays_B.Product_a[0];

      /* Product: '<S167>/Product2' */
      sel751test_model_1_3_ss_relays_B.Product2_lv =
        sel751test_model_1_3_ss_relays_B.Sum5_d3 /
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_k;

      /* Product: '<S167>/Product4' */
      sel751test_model_1_3_ss_relays_B.Product4_n =
        sel751test_model_1_3_ss_relays_B.Product2_lv *
        sel751test_model_1_3_ss_relays_B.Sum4_c;

      /* Sum: '<S165>/Sum7' */
      sel751test_model_1_3_ss_relays_B.Sum7_m =
        sel751test_model_1_3_ss_relays_B.Integ4_cf -
        sel751test_model_1_3_ss_relays_B.SFunction_mq;

      /* Product: '<S165>/Product' */
      sel751test_model_1_3_ss_relays_B.Meanvalue_c =
        sel751test_model_1_3_ss_relays_B.Sum7_m *
        sel751test_model_1_3_ss_relays_B.UnitDelay_jf;

      /* Sum: '<S165>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_f =
        sel751test_model_1_3_ss_relays_B.Meanvalue_c +
        sel751test_model_1_3_ss_relays_B.Product4_n;
      sel751test_model_1_3_ss_relays_B.Switch_be =
        sel751test_model_1_3_ss_relays_B.Sum5_f;
    } else {
      sel751test_model_1_3_ss_relays_B.Switch_be =
        sel751test_model_1_3_ss_relays_P.Constant_Value_l;
    }

    /* End of Switch: '<S165>/Switch' */

    /* DiscreteIntegrator: '<S166>/Integ4' */
    if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_ds != 0) {
      sel751test_model_1_3_ss_relays_B.Integ4_d2 =
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_ip;
    } else {
      sel751test_model_1_3_ss_relays_B.Integ4_d2 =
        sel751test_model_1_3_ss_relays_P.Integ4_gainval_a *
        sel751test_model_1_3_ss_relays_B.Product_a[1] +
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_ip;
    }

    /* End of DiscreteIntegrator: '<S166>/Integ4' */

    /* Saturate: '<S166>/To avoid division by zero' */
    u = sel751test_model_1_3_ss_relays_B.UnitDelay_jf;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerSa_h;
    u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperS_fc;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Freq_bf = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Freq_bf = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Freq_bf = u;
    }

    /* End of Saturate: '<S166>/To avoid division by zero' */

    /* Fcn: '<S166>/Number of samples per cycle' */
    sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_l = 1.0 /
      sel751test_model_1_3_ss_relays_B.Freq_bf / 0.0001;

    /* Rounding: '<S166>/Rounding Function' */
    sel751test_model_1_3_ss_relays_B.RoundingFunction_h = ceil
      (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_l);

    /* Gain: '<S166>/Gain' */
    sel751test_model_1_3_ss_relays_B.Delay_m =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_kv *
      sel751test_model_1_3_ss_relays_B.RoundingFunction_h;

    /* S-Function block: <S170>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gs.uBuffers)
        [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.indEnd] =
        sel751test_model_1_3_ss_relays_B.Integ4_d2;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_m/0.0001) + 0.5);
      if (discreteDelay >
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.maxDiscrDelay)
        discreteDelay =
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.maxDiscrDelay;
      indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed +=
            sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.bufSz;
      }

      /* Output past value(s) */
      sel751test_model_1_3_ss_relays_B.SFunction_fa = ((real_T *)
        sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gs.uBuffers)
        [indDelayed];
    }

    /* UnitDelay: '<S169>/Unit Delay' */
    sel751test_model_1_3_ss_relays_B.UnitDelay_p =
      sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_lv;

    /* Step: '<S166>/Step' */
    dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
    if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_l) {
      sel751test_model_1_3_ss_relays_B.Step_b =
        sel751test_model_1_3_ss_relays_P.Step_Y0_d;
    } else {
      sel751test_model_1_3_ss_relays_B.Step_b =
        sel751test_model_1_3_ss_relays_P.Step_YFinal_pt;
    }

    /* End of Step: '<S166>/Step' */

    /* Switch: '<S166>/Switch' incorporates:
     *  Constant: '<S166>/Constant'
     */
    if (sel751test_model_1_3_ss_relays_B.Step_b >=
        sel751test_model_1_3_ss_relays_P.Switch_Threshold_ap) {
      /* Sum: '<S169>/Sum1' */
      sel751test_model_1_3_ss_relays_B.Sum1_oz =
        sel751test_model_1_3_ss_relays_B.Product_a[1] -
        sel751test_model_1_3_ss_relays_B.UnitDelay_p;

      /* Sum: '<S169>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_gz =
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_l -
        sel751test_model_1_3_ss_relays_B.RoundingFunction_h;

      /* Product: '<S169>/Product5' */
      sel751test_model_1_3_ss_relays_B.Product5_a =
        sel751test_model_1_3_ss_relays_B.Sum5_gz *
        sel751test_model_1_3_ss_relays_B.Sum1_oz;

      /* Gain: '<S169>/Gain1' */
      sel751test_model_1_3_ss_relays_B.Gain1_b =
        sel751test_model_1_3_ss_relays_P.Gain1_Gain_oo *
        sel751test_model_1_3_ss_relays_B.Product5_a;

      /* Sum: '<S169>/Sum4' */
      sel751test_model_1_3_ss_relays_B.Sum4_m =
        sel751test_model_1_3_ss_relays_B.Gain1_b +
        sel751test_model_1_3_ss_relays_B.Product_a[1];

      /* Product: '<S169>/Product2' */
      sel751test_model_1_3_ss_relays_B.Product2_h =
        sel751test_model_1_3_ss_relays_B.Sum5_gz /
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_l;

      /* Product: '<S169>/Product4' */
      sel751test_model_1_3_ss_relays_B.Product4_j =
        sel751test_model_1_3_ss_relays_B.Product2_h *
        sel751test_model_1_3_ss_relays_B.Sum4_m;

      /* Sum: '<S166>/Sum7' */
      sel751test_model_1_3_ss_relays_B.Sum7_j =
        sel751test_model_1_3_ss_relays_B.Integ4_d2 -
        sel751test_model_1_3_ss_relays_B.SFunction_fa;

      /* Product: '<S166>/Product' */
      sel751test_model_1_3_ss_relays_B.Meanvalue_n =
        sel751test_model_1_3_ss_relays_B.Sum7_j *
        sel751test_model_1_3_ss_relays_B.UnitDelay_jf;

      /* Sum: '<S166>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_mh =
        sel751test_model_1_3_ss_relays_B.Meanvalue_n +
        sel751test_model_1_3_ss_relays_B.Product4_j;
      sel751test_model_1_3_ss_relays_B.Switch_ms =
        sel751test_model_1_3_ss_relays_B.Sum5_mh;
    } else {
      sel751test_model_1_3_ss_relays_B.Switch_ms =
        sel751test_model_1_3_ss_relays_P.Constant_Value_g;
    }

    /* End of Switch: '<S166>/Switch' */

    /* Fcn: '<S164>/x->r' */
    sel751test_model_1_3_ss_relays_B.xr_b = rt_hypotd_snf
      (sel751test_model_1_3_ss_relays_B.Switch_be,
       sel751test_model_1_3_ss_relays_B.Switch_ms);

    /* Fcn: '<S164>/x->theta' */
    sel751test_model_1_3_ss_relays_B.xtheta_m = rt_atan2d_snf
      (sel751test_model_1_3_ss_relays_B.Switch_ms,
       sel751test_model_1_3_ss_relays_B.Switch_be);

    /* Gain: '<S163>/Rad->Deg.' */
    sel751test_model_1_3_ss_relays_B.RadDeg_i =
      sel751test_model_1_3_ss_relays_P.RadDeg_Gain_e *
      sel751test_model_1_3_ss_relays_B.xtheta_m;

    /* Saturate: '<S159>/Saturation' */
    u = sel751test_model_1_3_ss_relays_B.xr_b;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_k;
    u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_c;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Saturation_h = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Saturation_h = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Saturation_h = u;
    }

    /* End of Saturate: '<S159>/Saturation' */

    /* Math: '<S159>/Math Function'
     *
     * About '<S159>/Math Function':
     *  Operator: reciprocal
     */
    sel751test_model_1_3_ss_relays_B.MathFunction_ib = 1.0 /
      sel751test_model_1_3_ss_relays_B.Saturation_h;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_m) {
      sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_m = FALSE;
    }
  }

  /* End of Constant: '<S156>/Constant1' */
  /* End of Outputs for SubSystem: '<S156>/Automatic Gain Control' */

  /* Product: '<S156>/Divide' */
  sel751test_model_1_3_ss_relays_B.Divide_i =
    sel751test_model_1_3_ss_relays_B.Switch_m2 *
    sel751test_model_1_3_ss_relays_B.MathFunction_ib;

  /* Gain: '<S160>/Kp4' */
  sel751test_model_1_3_ss_relays_B.Kp4_p =
    sel751test_model_1_3_ss_relays_P.Kp4_Gain_d *
    sel751test_model_1_3_ss_relays_B.Divide_i;

  /* DiscreteIntegrator: '<S160>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_l =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_pw;

  /* Gain: '<S160>/Kp6' */
  sel751test_model_1_3_ss_relays_B.Kp6_a =
    sel751test_model_1_3_ss_relays_P.Kp6_Gain_g *
    sel751test_model_1_3_ss_relays_B.Divide_i;

  /* ZeroOrderHold: '<S160>/Zero-Order Hold' */
  sel751test_model_1_3_ss_relays_B.ZeroOrderHold_d =
    sel751test_model_1_3_ss_relays_B.Kp6_a;

  /* SampleTimeMath: '<S171>/TSamp'
   *
   * About '<S171>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  sel751test_model_1_3_ss_relays_B.TSamp_n =
    sel751test_model_1_3_ss_relays_B.ZeroOrderHold_d *
    sel751test_model_1_3_ss_relays_P.TSamp_WtEt_f;

  /* UnitDelay: '<S171>/UD' */
  sel751test_model_1_3_ss_relays_B.Uk1_p =
    sel751test_model_1_3_ss_relays_DW.UD_DSTATE_h;

  /* Sum: '<S171>/Diff' */
  sel751test_model_1_3_ss_relays_B.Diff_pb =
    sel751test_model_1_3_ss_relays_B.TSamp_n -
    sel751test_model_1_3_ss_relays_B.Uk1_p;

  /* Sum: '<S160>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6_p =
    (sel751test_model_1_3_ss_relays_B.Kp4_p +
     sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_l) +
    sel751test_model_1_3_ss_relays_B.Diff_pb;

  /* Saturate: '<S160>/Saturation2' */
  u = sel751test_model_1_3_ss_relays_B.Sum6_p;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation2_LowerSat_b;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation2_UpperSat_i;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Saturation2_jn = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Saturation2_jn = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Saturation2_jn = u;
  }

  /* End of Saturate: '<S160>/Saturation2' */

  /* Gain: '<S156>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10_m =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain_e *
    sel751test_model_1_3_ss_relays_B.Saturation2_jn;

  /* UnitDelay: '<S161>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_B.y1_p2 =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_gp;

  /* Sum: '<S161>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1_f =
    sel751test_model_1_3_ss_relays_B.Gain10_m -
    sel751test_model_1_3_ss_relays_B.y1_p2;

  /* Saturate: '<S161>/Saturation' */
  u = sel751test_model_1_3_ss_relays_B.Sum1_f;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_o0;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_b;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_cm = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_cm = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_cm = u;
  }

  /* End of Saturate: '<S161>/Saturation' */

  /* Sum: '<S161>/Sum' */
  sel751test_model_1_3_ss_relays_B.y_l =
    sel751test_model_1_3_ss_relays_B.Deltau_limit_cm +
    sel751test_model_1_3_ss_relays_B.y1_p2;

  /* DiscreteStateSpace: '<S158>/Discrete State-Space' */
  {
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_c =
      (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_f[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_h[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_f[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_h[1];
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_c +=
      sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_D_hy*
      sel751test_model_1_3_ss_relays_B.y_l;
  }

  /* Gain: '<S160>/Kp5' */
  sel751test_model_1_3_ss_relays_B.Kp5_kx =
    sel751test_model_1_3_ss_relays_P.Kp5_Gain_p *
    sel751test_model_1_3_ss_relays_B.Divide_i;

  /* Product: '<S152>/Divide1' incorporates:
   *  Constant: '<S111>/base parameters'
   */
  sel751test_model_1_3_ss_relays_B.Divide1_o =
    sel751test_model_1_3_ss_relays_B.SFunction_l[14] /
    sel751test_model_1_3_ss_relays_P.baseparameters_Value_f[1];

  /* Trigonometry: '<S157>/Trigonometric Function2' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_j = cos
    (sel751test_model_1_3_ss_relays_B.MathFunction_iq);

  /* Product: '<S157>/Product1' */
  sel751test_model_1_3_ss_relays_B.Vq_il =
    sel751test_model_1_3_ss_relays_B.Divide1_o *
    sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_j;

  /* DiscreteIntegrator: '<S178>/Integ4' */
  if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_os != 0) {
    sel751test_model_1_3_ss_relays_B.Integ4_pa =
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_ei;
  } else {
    sel751test_model_1_3_ss_relays_B.Integ4_pa =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_eg *
      sel751test_model_1_3_ss_relays_B.Vq_il +
      sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_ei;
  }

  /* End of DiscreteIntegrator: '<S178>/Integ4' */

  /* Saturate: '<S178>/To avoid division by zero' */
  u = sel751test_model_1_3_ss_relays_B.UnitDelay_cu;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerSa_n;
  u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperSa_j;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Freq_m = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Freq_m = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Freq_m = u;
  }

  /* End of Saturate: '<S178>/To avoid division by zero' */

  /* Fcn: '<S178>/Number of samples per cycle' */
  sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_j = 1.0 /
    sel751test_model_1_3_ss_relays_B.Freq_m / 0.0001;

  /* Rounding: '<S178>/Rounding Function' */
  sel751test_model_1_3_ss_relays_B.RoundingFunction_c = ceil
    (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_j);

  /* Gain: '<S178>/Gain' */
  sel751test_model_1_3_ss_relays_B.Delay_ds =
    sel751test_model_1_3_ss_relays_P.Gain_Gain_ei *
    sel751test_model_1_3_ss_relays_B.RoundingFunction_c;

  /* S-Function block: <S189>/S-Function  */
  {
    int_T indDelayed;
    int_T discreteDelay;

    /* Input present value(s) */
    ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_kx.uBuffers)
      [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.indEnd] =
      sel751test_model_1_3_ss_relays_B.Integ4_pa;

    /* Calculate delayed index */
    discreteDelay =
      (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_ds/0.0001) + 0.5);
    if (discreteDelay >
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.maxDiscrDelay)
      discreteDelay =
        sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.maxDiscrDelay;
    indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.indEnd -
      ((discreteDelay > 0) ? discreteDelay : 0);
    if (indDelayed < 0) {
      if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.indBeg == 0 )
        indDelayed = 0;
      else
        indDelayed += sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.bufSz;
    }

    /* Output past value(s) */
    sel751test_model_1_3_ss_relays_B.SFunction_je = ((real_T *)
      sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_kx.uBuffers)[indDelayed];
  }

  /* UnitDelay: '<S188>/Unit Delay' */
  sel751test_model_1_3_ss_relays_B.UnitDelay_bh =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_lo;

  /* Step: '<S178>/Step' */
  dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
  if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_kt) {
    sel751test_model_1_3_ss_relays_B.Step_lg =
      sel751test_model_1_3_ss_relays_P.Step_Y0_ac;
  } else {
    sel751test_model_1_3_ss_relays_B.Step_lg =
      sel751test_model_1_3_ss_relays_P.Step_YFinal_l;
  }

  /* End of Step: '<S178>/Step' */

  /* Switch: '<S178>/Switch' incorporates:
   *  Constant: '<S178>/Constant'
   */
  if (sel751test_model_1_3_ss_relays_B.Step_lg >=
      sel751test_model_1_3_ss_relays_P.Switch_Threshold_nn) {
    /* Sum: '<S188>/Sum1' */
    sel751test_model_1_3_ss_relays_B.Sum1_l =
      sel751test_model_1_3_ss_relays_B.Vq_il -
      sel751test_model_1_3_ss_relays_B.UnitDelay_bh;

    /* Sum: '<S188>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_c =
      sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_j -
      sel751test_model_1_3_ss_relays_B.RoundingFunction_c;

    /* Product: '<S188>/Product5' */
    sel751test_model_1_3_ss_relays_B.Product5 =
      sel751test_model_1_3_ss_relays_B.Sum5_c *
      sel751test_model_1_3_ss_relays_B.Sum1_l;

    /* Gain: '<S188>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_m0 =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_cb *
      sel751test_model_1_3_ss_relays_B.Product5;

    /* Sum: '<S188>/Sum4' */
    sel751test_model_1_3_ss_relays_B.Sum4_d =
      sel751test_model_1_3_ss_relays_B.Gain1_m0 +
      sel751test_model_1_3_ss_relays_B.Vq_il;

    /* Product: '<S188>/Product2' */
    sel751test_model_1_3_ss_relays_B.Product2_b =
      sel751test_model_1_3_ss_relays_B.Sum5_c /
      sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_j;

    /* Product: '<S188>/Product4' */
    sel751test_model_1_3_ss_relays_B.Product4 =
      sel751test_model_1_3_ss_relays_B.Product2_b *
      sel751test_model_1_3_ss_relays_B.Sum4_d;

    /* Sum: '<S178>/Sum7' */
    sel751test_model_1_3_ss_relays_B.Sum7 =
      sel751test_model_1_3_ss_relays_B.Integ4_pa -
      sel751test_model_1_3_ss_relays_B.SFunction_je;

    /* Product: '<S178>/Product' */
    sel751test_model_1_3_ss_relays_B.Meanvalue =
      sel751test_model_1_3_ss_relays_B.Sum7 *
      sel751test_model_1_3_ss_relays_B.UnitDelay_cu;

    /* Sum: '<S178>/Sum5' */
    sel751test_model_1_3_ss_relays_B.Sum5_h =
      sel751test_model_1_3_ss_relays_B.Meanvalue +
      sel751test_model_1_3_ss_relays_B.Product4;
    sel751test_model_1_3_ss_relays_B.Switch_b =
      sel751test_model_1_3_ss_relays_B.Sum5_h;
  } else {
    sel751test_model_1_3_ss_relays_B.Switch_b =
      sel751test_model_1_3_ss_relays_P.Constant_Value_fj;
  }

  /* End of Switch: '<S178>/Switch' */

  /* Trigonometry: '<S157>/Trigonometric Function' */
  sel751test_model_1_3_ss_relays_B.TrigonometricFunction_e = sin
    (sel751test_model_1_3_ss_relays_B.MathFunction_iq);

  /* Outputs for Enabled SubSystem: '<S157>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S175>/Enable'
   */
  /* Constant: '<S157>/Constant1' */
  if (sel751test_model_1_3_ss_relays_P.Constant1_Value_m > 0.0) {
    if (!sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_o) {
      /* Enable for DiscreteIntegrator: '<S181>/Integ4' */
      sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_l4 = 1U;

      /* Enable for DiscreteIntegrator: '<S182>/Integ4' */
      sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_hr = 1U;
      sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_o = TRUE;
    }

    /* Gain: '<S179>/Gain1' */
    sel751test_model_1_3_ss_relays_B.Gain1_p4[0] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_n3 *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction_e;
    sel751test_model_1_3_ss_relays_B.Gain1_p4[1] =
      sel751test_model_1_3_ss_relays_P.Gain1_Gain_n3 *
      sel751test_model_1_3_ss_relays_B.TrigonometricFunction2_j;

    /* Product: '<S179>/Product' */
    sel751test_model_1_3_ss_relays_B.Product_h[0] =
      sel751test_model_1_3_ss_relays_B.Divide1_o *
      sel751test_model_1_3_ss_relays_B.Gain1_p4[0];
    sel751test_model_1_3_ss_relays_B.Product_h[1] =
      sel751test_model_1_3_ss_relays_B.Divide1_o *
      sel751test_model_1_3_ss_relays_B.Gain1_p4[1];

    /* DiscreteIntegrator: '<S181>/Integ4' */
    if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_l4 != 0) {
      sel751test_model_1_3_ss_relays_B.Integ4_a =
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_pe;
    } else {
      sel751test_model_1_3_ss_relays_B.Integ4_a =
        sel751test_model_1_3_ss_relays_P.Integ4_gainval_f *
        sel751test_model_1_3_ss_relays_B.Product_h[0] +
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_pe;
    }

    /* End of DiscreteIntegrator: '<S181>/Integ4' */

    /* Saturate: '<S181>/To avoid division by zero' */
    u = sel751test_model_1_3_ss_relays_B.UnitDelay_cu;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerS_fy;
    u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperS_au;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Freq_mz = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Freq_mz = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Freq_mz = u;
    }

    /* End of Saturate: '<S181>/To avoid division by zero' */

    /* Fcn: '<S181>/Number of samples per cycle' */
    sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_e = 1.0 /
      sel751test_model_1_3_ss_relays_B.Freq_mz / 0.0001;

    /* Rounding: '<S181>/Rounding Function' */
    sel751test_model_1_3_ss_relays_B.RoundingFunction_l5 = ceil
      (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_e);

    /* Gain: '<S181>/Gain' */
    sel751test_model_1_3_ss_relays_B.Delay_a =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_mb *
      sel751test_model_1_3_ss_relays_B.RoundingFunction_l5;

    /* S-Function block: <S184>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_i.uBuffers)
        [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.indEnd] =
        sel751test_model_1_3_ss_relays_B.Integ4_a;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_a/0.0001) + 0.5);
      if (discreteDelay >
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.maxDiscrDelay)
        discreteDelay =
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.maxDiscrDelay;
      indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed +=
            sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.bufSz;
      }

      /* Output past value(s) */
      sel751test_model_1_3_ss_relays_B.SFunction_lx = ((real_T *)
        sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_i.uBuffers)[indDelayed];
    }

    /* UnitDelay: '<S183>/Unit Delay' */
    sel751test_model_1_3_ss_relays_B.UnitDelay_jj =
      sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_pr;

    /* Step: '<S181>/Step' */
    dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
    if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_e) {
      sel751test_model_1_3_ss_relays_B.Step_cz =
        sel751test_model_1_3_ss_relays_P.Step_Y0_m;
    } else {
      sel751test_model_1_3_ss_relays_B.Step_cz =
        sel751test_model_1_3_ss_relays_P.Step_YFinal_m;
    }

    /* End of Step: '<S181>/Step' */

    /* Switch: '<S181>/Switch' incorporates:
     *  Constant: '<S181>/Constant'
     */
    if (sel751test_model_1_3_ss_relays_B.Step_cz >=
        sel751test_model_1_3_ss_relays_P.Switch_Threshold_n) {
      /* Sum: '<S183>/Sum1' */
      sel751test_model_1_3_ss_relays_B.Sum1_hg =
        sel751test_model_1_3_ss_relays_B.Product_h[0] -
        sel751test_model_1_3_ss_relays_B.UnitDelay_jj;

      /* Sum: '<S183>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_hn =
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_e -
        sel751test_model_1_3_ss_relays_B.RoundingFunction_l5;

      /* Product: '<S183>/Product5' */
      sel751test_model_1_3_ss_relays_B.Product5_b =
        sel751test_model_1_3_ss_relays_B.Sum5_hn *
        sel751test_model_1_3_ss_relays_B.Sum1_hg;

      /* Gain: '<S183>/Gain1' */
      sel751test_model_1_3_ss_relays_B.Gain1_f =
        sel751test_model_1_3_ss_relays_P.Gain1_Gain_as *
        sel751test_model_1_3_ss_relays_B.Product5_b;

      /* Sum: '<S183>/Sum4' */
      sel751test_model_1_3_ss_relays_B.Sum4_i =
        sel751test_model_1_3_ss_relays_B.Gain1_f +
        sel751test_model_1_3_ss_relays_B.Product_h[0];

      /* Product: '<S183>/Product2' */
      sel751test_model_1_3_ss_relays_B.Product2_g =
        sel751test_model_1_3_ss_relays_B.Sum5_hn /
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_e;

      /* Product: '<S183>/Product4' */
      sel751test_model_1_3_ss_relays_B.Product4_o =
        sel751test_model_1_3_ss_relays_B.Product2_g *
        sel751test_model_1_3_ss_relays_B.Sum4_i;

      /* Sum: '<S181>/Sum7' */
      sel751test_model_1_3_ss_relays_B.Sum7_h =
        sel751test_model_1_3_ss_relays_B.Integ4_a -
        sel751test_model_1_3_ss_relays_B.SFunction_lx;

      /* Product: '<S181>/Product' */
      sel751test_model_1_3_ss_relays_B.Meanvalue_e =
        sel751test_model_1_3_ss_relays_B.Sum7_h *
        sel751test_model_1_3_ss_relays_B.UnitDelay_cu;

      /* Sum: '<S181>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_m =
        sel751test_model_1_3_ss_relays_B.Meanvalue_e +
        sel751test_model_1_3_ss_relays_B.Product4_o;
      sel751test_model_1_3_ss_relays_B.Switch_g =
        sel751test_model_1_3_ss_relays_B.Sum5_m;
    } else {
      sel751test_model_1_3_ss_relays_B.Switch_g =
        sel751test_model_1_3_ss_relays_P.Constant_Value_d;
    }

    /* End of Switch: '<S181>/Switch' */

    /* DiscreteIntegrator: '<S182>/Integ4' */
    if (sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_hr != 0) {
      sel751test_model_1_3_ss_relays_B.Integ4_c0 =
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_d;
    } else {
      sel751test_model_1_3_ss_relays_B.Integ4_c0 =
        sel751test_model_1_3_ss_relays_P.Integ4_gainval_i *
        sel751test_model_1_3_ss_relays_B.Product_h[1] +
        sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_d;
    }

    /* End of DiscreteIntegrator: '<S182>/Integ4' */

    /* Saturate: '<S182>/To avoid division by zero' */
    u = sel751test_model_1_3_ss_relays_B.UnitDelay_cu;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_LowerSa_k;
    u_0 = sel751test_model_1_3_ss_relays_P.Toavoiddivisionbyzero_UpperSa_m;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Freq_b = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Freq_b = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Freq_b = u;
    }

    /* End of Saturate: '<S182>/To avoid division by zero' */

    /* Fcn: '<S182>/Number of samples per cycle' */
    sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_d = 1.0 /
      sel751test_model_1_3_ss_relays_B.Freq_b / 0.0001;

    /* Rounding: '<S182>/Rounding Function' */
    sel751test_model_1_3_ss_relays_B.RoundingFunction_cc = ceil
      (sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_d);

    /* Gain: '<S182>/Gain' */
    sel751test_model_1_3_ss_relays_B.Delay_oy =
      sel751test_model_1_3_ss_relays_P.Gain_Gain_lx *
      sel751test_model_1_3_ss_relays_B.RoundingFunction_cc;

    /* S-Function block: <S186>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_fl.uBuffers)
        [sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.indEnd] =
        sel751test_model_1_3_ss_relays_B.Integ4_c0;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((sel751test_model_1_3_ss_relays_B.Delay_oy/0.0001) + 0.5);
      if (discreteDelay >
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.maxDiscrDelay)
        discreteDelay =
          sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.maxDiscrDelay;
      indDelayed = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed +=
            sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.bufSz;
      }

      /* Output past value(s) */
      sel751test_model_1_3_ss_relays_B.SFunction_m2 = ((real_T *)
        sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_fl.uBuffers)
        [indDelayed];
    }

    /* UnitDelay: '<S185>/Unit Delay' */
    sel751test_model_1_3_ss_relays_B.UnitDelay_jp =
      sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_hw;

    /* Step: '<S182>/Step' */
    dsp2Pi = sel751test_model_1_3_ss_relays_M->Timing.t[0];
    if (dsp2Pi < sel751test_model_1_3_ss_relays_P.Step_Time_p) {
      sel751test_model_1_3_ss_relays_B.Step_dd =
        sel751test_model_1_3_ss_relays_P.Step_Y0_b;
    } else {
      sel751test_model_1_3_ss_relays_B.Step_dd =
        sel751test_model_1_3_ss_relays_P.Step_YFinal_c;
    }

    /* End of Step: '<S182>/Step' */

    /* Switch: '<S182>/Switch' incorporates:
     *  Constant: '<S182>/Constant'
     */
    if (sel751test_model_1_3_ss_relays_B.Step_dd >=
        sel751test_model_1_3_ss_relays_P.Switch_Threshold_b) {
      /* Sum: '<S185>/Sum1' */
      sel751test_model_1_3_ss_relays_B.Sum1_h =
        sel751test_model_1_3_ss_relays_B.Product_h[1] -
        sel751test_model_1_3_ss_relays_B.UnitDelay_jp;

      /* Sum: '<S185>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_g =
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_d -
        sel751test_model_1_3_ss_relays_B.RoundingFunction_cc;

      /* Product: '<S185>/Product5' */
      sel751test_model_1_3_ss_relays_B.Product5_d =
        sel751test_model_1_3_ss_relays_B.Sum5_g *
        sel751test_model_1_3_ss_relays_B.Sum1_h;

      /* Gain: '<S185>/Gain1' */
      sel751test_model_1_3_ss_relays_B.Gain1_h =
        sel751test_model_1_3_ss_relays_P.Gain1_Gain_om *
        sel751test_model_1_3_ss_relays_B.Product5_d;

      /* Sum: '<S185>/Sum4' */
      sel751test_model_1_3_ss_relays_B.Sum4_km =
        sel751test_model_1_3_ss_relays_B.Gain1_h +
        sel751test_model_1_3_ss_relays_B.Product_h[1];

      /* Product: '<S185>/Product2' */
      sel751test_model_1_3_ss_relays_B.Product2_b3 =
        sel751test_model_1_3_ss_relays_B.Sum5_g /
        sel751test_model_1_3_ss_relays_B.Numberofsamplespercycle_d;

      /* Product: '<S185>/Product4' */
      sel751test_model_1_3_ss_relays_B.Product4_m =
        sel751test_model_1_3_ss_relays_B.Product2_b3 *
        sel751test_model_1_3_ss_relays_B.Sum4_km;

      /* Sum: '<S182>/Sum7' */
      sel751test_model_1_3_ss_relays_B.Sum7_b =
        sel751test_model_1_3_ss_relays_B.Integ4_c0 -
        sel751test_model_1_3_ss_relays_B.SFunction_m2;

      /* Product: '<S182>/Product' */
      sel751test_model_1_3_ss_relays_B.Meanvalue_i =
        sel751test_model_1_3_ss_relays_B.Sum7_b *
        sel751test_model_1_3_ss_relays_B.UnitDelay_cu;

      /* Sum: '<S182>/Sum5' */
      sel751test_model_1_3_ss_relays_B.Sum5_d =
        sel751test_model_1_3_ss_relays_B.Meanvalue_i +
        sel751test_model_1_3_ss_relays_B.Product4_m;
      sel751test_model_1_3_ss_relays_B.Switch_bu =
        sel751test_model_1_3_ss_relays_B.Sum5_d;
    } else {
      sel751test_model_1_3_ss_relays_B.Switch_bu =
        sel751test_model_1_3_ss_relays_P.Constant_Value_i;
    }

    /* End of Switch: '<S182>/Switch' */

    /* Fcn: '<S180>/x->r' */
    sel751test_model_1_3_ss_relays_B.xr = rt_hypotd_snf
      (sel751test_model_1_3_ss_relays_B.Switch_g,
       sel751test_model_1_3_ss_relays_B.Switch_bu);

    /* Fcn: '<S180>/x->theta' */
    sel751test_model_1_3_ss_relays_B.xtheta = rt_atan2d_snf
      (sel751test_model_1_3_ss_relays_B.Switch_bu,
       sel751test_model_1_3_ss_relays_B.Switch_g);

    /* Gain: '<S179>/Rad->Deg.' */
    sel751test_model_1_3_ss_relays_B.RadDeg =
      sel751test_model_1_3_ss_relays_P.RadDeg_Gain_a *
      sel751test_model_1_3_ss_relays_B.xtheta;

    /* Saturate: '<S175>/Saturation' */
    u = sel751test_model_1_3_ss_relays_B.xr;
    dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_e;
    u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_l;
    if (u >= u_0) {
      sel751test_model_1_3_ss_relays_B.Saturation = u_0;
    } else if (u <= dsp2Pi) {
      sel751test_model_1_3_ss_relays_B.Saturation = dsp2Pi;
    } else {
      sel751test_model_1_3_ss_relays_B.Saturation = u;
    }

    /* End of Saturate: '<S175>/Saturation' */

    /* Math: '<S175>/Math Function'
     *
     * About '<S175>/Math Function':
     *  Operator: reciprocal
     */
    sel751test_model_1_3_ss_relays_B.MathFunction_o = 1.0 /
      sel751test_model_1_3_ss_relays_B.Saturation;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_o) {
      sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_o = FALSE;
    }
  }

  /* End of Constant: '<S157>/Constant1' */
  /* End of Outputs for SubSystem: '<S157>/Automatic Gain Control' */

  /* Product: '<S157>/Divide' */
  sel751test_model_1_3_ss_relays_B.Divide_av =
    sel751test_model_1_3_ss_relays_B.Switch_b *
    sel751test_model_1_3_ss_relays_B.MathFunction_o;

  /* Gain: '<S176>/Kp4' */
  sel751test_model_1_3_ss_relays_B.Kp4_b =
    sel751test_model_1_3_ss_relays_P.Kp4_Gain_dg *
    sel751test_model_1_3_ss_relays_B.Divide_av;

  /* DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_pa =
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_c;

  /* Gain: '<S176>/Kp6' */
  sel751test_model_1_3_ss_relays_B.Kp6_e =
    sel751test_model_1_3_ss_relays_P.Kp6_Gain_l *
    sel751test_model_1_3_ss_relays_B.Divide_av;

  /* ZeroOrderHold: '<S176>/Zero-Order Hold' */
  sel751test_model_1_3_ss_relays_B.ZeroOrderHold_j2 =
    sel751test_model_1_3_ss_relays_B.Kp6_e;

  /* SampleTimeMath: '<S187>/TSamp'
   *
   * About '<S187>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  sel751test_model_1_3_ss_relays_B.TSamp_h =
    sel751test_model_1_3_ss_relays_B.ZeroOrderHold_j2 *
    sel751test_model_1_3_ss_relays_P.TSamp_WtEt_j;

  /* UnitDelay: '<S187>/UD' */
  sel751test_model_1_3_ss_relays_B.Uk1_pi =
    sel751test_model_1_3_ss_relays_DW.UD_DSTATE_i;

  /* Sum: '<S187>/Diff' */
  sel751test_model_1_3_ss_relays_B.Diff_n =
    sel751test_model_1_3_ss_relays_B.TSamp_h -
    sel751test_model_1_3_ss_relays_B.Uk1_pi;

  /* Sum: '<S176>/Sum6' */
  sel751test_model_1_3_ss_relays_B.Sum6_h =
    (sel751test_model_1_3_ss_relays_B.Kp4_b +
     sel751test_model_1_3_ss_relays_B.DiscreteTimeIntegrator_pa) +
    sel751test_model_1_3_ss_relays_B.Diff_n;

  /* Saturate: '<S176>/Saturation2' */
  u = sel751test_model_1_3_ss_relays_B.Sum6_h;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation2_LowerSat_pm;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation2_UpperSat_c;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Saturation2_l = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Saturation2_l = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Saturation2_l = u;
  }

  /* End of Saturate: '<S176>/Saturation2' */

  /* Gain: '<S157>/Gain10' */
  sel751test_model_1_3_ss_relays_B.Gain10_l =
    sel751test_model_1_3_ss_relays_P.Gain10_Gain_g0 *
    sel751test_model_1_3_ss_relays_B.Saturation2_l;

  /* UnitDelay: '<S177>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_B.y1_a4 =
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_pk;

  /* Sum: '<S177>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1_c0 =
    sel751test_model_1_3_ss_relays_B.Gain10_l -
    sel751test_model_1_3_ss_relays_B.y1_a4;

  /* Saturate: '<S177>/Saturation' */
  u = sel751test_model_1_3_ss_relays_B.Sum1_c0;
  dsp2Pi = sel751test_model_1_3_ss_relays_P.Saturation_LowerSat_a;
  u_0 = sel751test_model_1_3_ss_relays_P.Saturation_UpperSat_ns;
  if (u >= u_0) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_e = u_0;
  } else if (u <= dsp2Pi) {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_e = dsp2Pi;
  } else {
    sel751test_model_1_3_ss_relays_B.Deltau_limit_e = u;
  }

  /* End of Saturate: '<S177>/Saturation' */

  /* Sum: '<S177>/Sum' */
  sel751test_model_1_3_ss_relays_B.y_e =
    sel751test_model_1_3_ss_relays_B.Deltau_limit_e +
    sel751test_model_1_3_ss_relays_B.y1_a4;

  /* DiscreteStateSpace: '<S174>/Discrete State-Space' */
  {
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_l =
      (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_d[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_m[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_C_d[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_m[1];
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_l +=
      sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_D_l2*
      sel751test_model_1_3_ss_relays_B.y_e;
  }

  /* Gain: '<S176>/Kp5' */
  sel751test_model_1_3_ss_relays_B.Kp5_e =
    sel751test_model_1_3_ss_relays_P.Kp5_Gain_j *
    sel751test_model_1_3_ss_relays_B.Divide_av;

  /* Sum: '<S6>/Sum' */
  sel751test_model_1_3_ss_relays_B.Sum_m =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion4_e[0] +
    sel751test_model_1_3_ss_relays_B.Gain_d;

  /* Sum: '<S6>/Sum1' */
  sel751test_model_1_3_ss_relays_B.Sum1_n2 =
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion4_e[2] +
     sel751test_model_1_3_ss_relays_B.Gain13_o) +
    sel751test_model_1_3_ss_relays_B.Gain14_f;

  /* DataTypeConversion: '<S112>/Data Type Conversion' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[0] =
    sel751test_model_1_3_ss_relays_B.Status_n;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[1] =
    sel751test_model_1_3_ss_relays_B.LogicalOperator3_d;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[2] =
    sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip27;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[3] =
    sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip50;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[4] =
    sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip51;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[5] =
    sel751test_model_1_3_ss_relays_B.sf_Relays_c.trip59;
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[6] =
    sel751test_model_1_3_ss_relays_B.reset_j;

  /* ArithShift: '<S112>/Shift Arithmetic' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic_h = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[1] << 1);

  /* ArithShift: '<S112>/Shift Arithmetic1' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic1_j = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[2] << 2);

  /* ArithShift: '<S112>/Shift Arithmetic2' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic2_h = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[3] << 3);

  /* ArithShift: '<S112>/Shift Arithmetic3' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic3_h = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[4] << 4);

  /* ArithShift: '<S112>/Shift Arithmetic4' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic4_n = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[5] << 5);

  /* ArithShift: '<S112>/Shift Arithmetic5' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic5_o = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[6] << 6);

  /* S-Function (sfix_bitop): '<S112>/Bitwise Operator' */
  sel751test_model_1_3_ss_relays_B.BitwiseOperator_m = (uint16_T)((uint16_T)
    ((uint16_T)((uint16_T)((uint16_T)((uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_k[0] |
     sel751test_model_1_3_ss_relays_B.ShiftArithmetic_h) |
    sel751test_model_1_3_ss_relays_B.ShiftArithmetic1_j) |
    sel751test_model_1_3_ss_relays_B.ShiftArithmetic2_h) |
                sel751test_model_1_3_ss_relays_B.ShiftArithmetic3_h) |
     sel751test_model_1_3_ss_relays_B.ShiftArithmetic4_n) |
    sel751test_model_1_3_ss_relays_B.ShiftArithmetic5_o);

  /* DataTypeConversion: '<S112>/Data Type Conversion1' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion1_o =
    sel751test_model_1_3_ss_relays_B.BitwiseOperator_m;

  /* DataTypeConversion: '<S113>/Data Type Conversion' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_f[0] =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion3_a[0];
  sel751test_model_1_3_ss_relays_B.DataTypeConversion_f[1] =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion3_a[1];

  /* ArithShift: '<S113>/Shift Arithmetic' */
  sel751test_model_1_3_ss_relays_B.ShiftArithmetic_m = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_f[1] << 1);

  /* S-Function (sfix_bitop): '<S113>/Bitwise Operator' */
  sel751test_model_1_3_ss_relays_B.BitwiseOperator_a = (uint16_T)
    (sel751test_model_1_3_ss_relays_B.DataTypeConversion_f[0] |
     sel751test_model_1_3_ss_relays_B.ShiftArithmetic_m);

  /* DataTypeConversion: '<S113>/Data Type Conversion1' */
  sel751test_model_1_3_ss_relays_B.DataTypeConversion1_e =
    sel751test_model_1_3_ss_relays_B.BitwiseOperator_a;
}

/* Model update function */
static void sel751test_model_1_3_ss_relays_update(void)
{
  /* Update for Memory: '<S2>/S-Function' */
  sel751test_model_1_3_ss_relays_DW.SFunction_PreviousInput =
    sel751test_model_1_3_ss_relays_B.Sum;

  /* Update for Memory: '<S5>/Memory1' */
  sel751test_model_1_3_ss_relays_DW.Memory1_PreviousInput =
    sel751test_model_1_3_ss_relays_B.SFunction_o[1];

  /* Update for Memory: '<S5>/Memory8' */
  sel751test_model_1_3_ss_relays_DW.Memory8_PreviousInput =
    sel751test_model_1_3_ss_relays_B.Logic_out;

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[1];
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[2];
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[3];

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[4];
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[5];
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[6];

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_3_PreviousInput =
    sel751test_model_1_3_ss_relays_B.Switch_kt[0];

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_4_PreviousInput =
    sel751test_model_1_3_ss_relays_B.Switch_kt[1];

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_5_PreviousInput =
    sel751test_model_1_3_ss_relays_B.UnitDelay_e;

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_6_PreviousInput =
    sel751test_model_1_3_ss_relays_B.SignedSqrt_k[0];

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_7_PreviousInput =
    sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1;

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_8_PreviousInput =
    sel751test_model_1_3_ss_relays_B.Vpu_hv;

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_9_PreviousInput =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion1;

  /* Update for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_10_PreviousInput =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion1_g;

  /* Update for Memory: '<S6>/Memory1' */
  sel751test_model_1_3_ss_relays_DW.Memory1_PreviousInput_e =
    sel751test_model_1_3_ss_relays_B.SFunction_o[4];

  /* Update for Memory: '<S6>/Memory8' */
  sel751test_model_1_3_ss_relays_DW.Memory8_PreviousInput_e =
    sel751test_model_1_3_ss_relays_B.Logic_out_p;

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput_p[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[11];
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput_p[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[12];
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput_p[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[13];

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput_l[0] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[14];
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput_l[1] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[15];
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput_l[2] =
    sel751test_model_1_3_ss_relays_B.SFunction_l[16];

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_3_PreviousInput_n =
    sel751test_model_1_3_ss_relays_B.Switch_m[0];

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_4_PreviousInput_g =
    sel751test_model_1_3_ss_relays_B.Switch_m[1];

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_5_PreviousInput_d =
    sel751test_model_1_3_ss_relays_B.UnitDelay_b3;

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_6_PreviousInput_m =
    sel751test_model_1_3_ss_relays_B.SignedSqrt_d[0];

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_7_PreviousInput_c =
    sel751test_model_1_3_ss_relays_B.FixPtUnitDelay1_a;

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_8_PreviousInput_d =
    sel751test_model_1_3_ss_relays_B.Vpu_n;

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_9_PreviousInput_l =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion1_o;

  /* Update for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_10_PreviousInput_e =
    sel751test_model_1_3_ss_relays_B.DataTypeConversion1_e;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainval *
    sel751test_model_1_3_ss_relays_B.Saturation2;

  /* Update for DiscreteIntegrator: '<S28>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_g *
    sel751test_model_1_3_ss_relays_B.Vq +
    sel751test_model_1_3_ss_relays_B.Integ4;

  /* S-Function block: <S31>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S28>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE =
    sel751test_model_1_3_ss_relays_B.Vq;

  /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_d +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_f *
    sel751test_model_1_3_ss_relays_B.Kp5;
  if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_d >=
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperSat) {
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_d =
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_d <=
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerSat) {
      sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_d =
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S30>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE =
    sel751test_model_1_3_ss_relays_B.TSamp;

  /* Update for UnitDelay: '<S27>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_l =
    sel751test_model_1_3_ss_relays_B.y;

  /* Update for DiscreteStateSpace: '<S25>/Discrete State-Space' */
  {
    real_T xnew[2];
    xnew[0] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE[1];
    xnew[0] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B[0])*
      sel751test_model_1_3_ss_relays_B.y;
    xnew[1] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A[2])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A[3])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE[1];
    xnew[1] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B[1])*
      sel751test_model_1_3_ss_relays_B.y;
    (void) memcpy(&sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE[0],
                  xnew,
                  sizeof(real_T)*2);
  }

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_n =
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_i +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_k *
    sel751test_model_1_3_ss_relays_B.Saturation2_a;

  /* Update for DiscreteIntegrator: '<S35>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_o = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_o =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_nf *
    sel751test_model_1_3_ss_relays_B.Vq_i +
    sel751test_model_1_3_ss_relays_B.Integ4_j;

  /* S-Function block: <S38>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S35>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_n1 =
    sel751test_model_1_3_ss_relays_B.Vq_i;

  /* Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_b +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_c *
    sel751test_model_1_3_ss_relays_B.Kp5_l;
  if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_b >=
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_a) {
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_b =
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_a;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_b <=
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_n) {
      sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_b =
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_n;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S37>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_p =
    sel751test_model_1_3_ss_relays_B.TSamp_c;

  /* Update for UnitDelay: '<S34>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_e =
    sel751test_model_1_3_ss_relays_B.y_g;

  /* Update for DiscreteStateSpace: '<S32>/Discrete State-Space' */
  {
    real_T xnew[2];
    xnew[0] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_o[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_b[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_o[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_b[1];
    xnew[0] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_o[0])*
      sel751test_model_1_3_ss_relays_B.y_g;
    xnew[1] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_o[2])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_b[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_o[3])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_b[1];
    xnew[1] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_o[1])*
      sel751test_model_1_3_ss_relays_B.y_g;
    (void) memcpy
      (&sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_b[0], xnew,
       sizeof(real_T)*2);
  }

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_k =
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_d;

  /* Update for DiscreteIntegrator: '<S49>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_k = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_i[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_f3 *
    sel751test_model_1_3_ss_relays_B.P_i +
    sel751test_model_1_3_ss_relays_B.Integ4_c[0];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_i[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_f3 *
    sel751test_model_1_3_ss_relays_B.Q_b +
    sel751test_model_1_3_ss_relays_B.Integ4_c[1];

  /* S-Function block: <S50>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S49>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_kt[0] =
    sel751test_model_1_3_ss_relays_B.P_i;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_kt[1] =
    sel751test_model_1_3_ss_relays_B.Q_b;

  /* Update for UnitDelay: '<S43>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE =
    sel751test_model_1_3_ss_relays_B.Xnew;

  /* Update for UnitDelay: '<S44>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_n =
    sel751test_model_1_3_ss_relays_B.Xnew_p;

  /* Update for UnitDelay: '<S45>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_n0 =
    sel751test_model_1_3_ss_relays_B.Xnew_o;

  /* Update for UnitDelay: '<S99>/Delay Input1' */
  sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE_k =
    sel751test_model_1_3_ss_relays_B.LogicalOperator1;

  /* Update for DiscreteIntegrator: '<S51>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_d = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_cf *
    sel751test_model_1_3_ss_relays_B.Product3_c[0] +
    sel751test_model_1_3_ss_relays_B.Integ4_ct[0];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_cf *
    sel751test_model_1_3_ss_relays_B.Product3_c[1] +
    sel751test_model_1_3_ss_relays_B.Integ4_ct[1];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[2] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_cf *
    sel751test_model_1_3_ss_relays_B.Product3_c[2] +
    sel751test_model_1_3_ss_relays_B.Integ4_ct[2];

  /* S-Function block: <S52>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S51>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_h[0] =
    sel751test_model_1_3_ss_relays_B.Product3_c[0];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_h[1] =
    sel751test_model_1_3_ss_relays_B.Product3_c[1];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_h[2] =
    sel751test_model_1_3_ss_relays_B.Product3_c[2];

  /* Update for DiscreteIntegrator: '<S53>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_b = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_b *
    sel751test_model_1_3_ss_relays_B.Product3_h[0] +
    sel751test_model_1_3_ss_relays_B.Integ4_d[0];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_b *
    sel751test_model_1_3_ss_relays_B.Product3_h[1] +
    sel751test_model_1_3_ss_relays_B.Integ4_d[1];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[2] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_b *
    sel751test_model_1_3_ss_relays_B.Product3_h[2] +
    sel751test_model_1_3_ss_relays_B.Integ4_d[2];

  /* S-Function block: <S54>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S53>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_d[0] =
    sel751test_model_1_3_ss_relays_B.Product3_h[0];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_d[1] =
    sel751test_model_1_3_ss_relays_B.Product3_h[1];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_d[2] =
    sel751test_model_1_3_ss_relays_B.Product3_h[2];

  /* Update for UnitDelay: '<S46>/Delay Input1' */
  sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE =
    sel751test_model_1_3_ss_relays_B.SFunction_o[1];

  /* Update for Memory: '<S47>/Memory' */
  sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput =
    sel751test_model_1_3_ss_relays_B.Logic[0];

  /* Update for DiscreteIntegrator: '<S63>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_e = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_id[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_me *
    sel751test_model_1_3_ss_relays_B.Product3_oh[0] +
    sel751test_model_1_3_ss_relays_B.Integ4_m[0];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_id[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_me *
    sel751test_model_1_3_ss_relays_B.Product3_oh[1] +
    sel751test_model_1_3_ss_relays_B.Integ4_m[1];

  /* S-Function block: <S64>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S63>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_m[0] =
    sel751test_model_1_3_ss_relays_B.Product3_oh[0];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_m[1] =
    sel751test_model_1_3_ss_relays_B.Product3_oh[1];

  /* Update for UnitDelay: '<S66>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_j =
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_n;

  /* Update for UnitDelay: '<S65>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ez =
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_m;

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_h +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_n *
    sel751test_model_1_3_ss_relays_B.Saturation2_j;

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_o +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_l *
    sel751test_model_1_3_ss_relays_B.Saturation2_m;

  /* Update for Memory: '<S58>/Memory' */
  sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput_o =
    sel751test_model_1_3_ss_relays_B.Logic_a[0];

  /* Update for Memory: '<S5>/Memory2' */
  sel751test_model_1_3_ss_relays_DW.Memory2_PreviousInput =
    sel751test_model_1_3_ss_relays_B.Sum1_i;

  /* Update for Memory: '<S5>/Memory9' */
  sel751test_model_1_3_ss_relays_DW.Memory9_PreviousInput =
    sel751test_model_1_3_ss_relays_B.Sum_o;

  /* Update for DiscreteIntegrator: '<S71>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_eh = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_m =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_e *
    sel751test_model_1_3_ss_relays_B.Vq_b +
    sel751test_model_1_3_ss_relays_B.Integ4_e;

  /* S-Function block: <S82>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S81>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ed =
    sel751test_model_1_3_ss_relays_B.Vq_b;

  /* Update for Enabled SubSystem: '<S65>/Automatic Gain Control' incorporates:
   *  Update for EnablePort: '<S68>/Enable'
   */
  if (sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE) {
    /* Update for DiscreteIntegrator: '<S74>/Integ4' */
    sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_m = 0U;
    sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_n =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval *
      sel751test_model_1_3_ss_relays_B.Product_k3[0] +
      sel751test_model_1_3_ss_relays_B.Integ4_h;

    /* S-Function block: <S77>/S-Function  */
    {
      int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.indBeg;
      int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.indEnd;
      int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.indBeg = indBeg;
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S76>/Unit Delay' */
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_b5 =
      sel751test_model_1_3_ss_relays_B.Product_k3[0];

    /* Update for DiscreteIntegrator: '<S75>/Integ4' */
    sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_ei = 0U;
    sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_j =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_m *
      sel751test_model_1_3_ss_relays_B.Product_k3[1] +
      sel751test_model_1_3_ss_relays_B.Integ4_k;

    /* S-Function block: <S79>/S-Function  */
    {
      int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.indBeg;
      int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.indEnd;
      int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.indBeg = indBeg;
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S78>/Unit Delay' */
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_hf =
      sel751test_model_1_3_ss_relays_B.Product_k3[1];
  }

  /* End of Update for SubSystem: '<S65>/Automatic Gain Control' */

  /* Update for DiscreteIntegrator: '<S69>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_a +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_m *
    sel751test_model_1_3_ss_relays_B.Kp5_k;
  if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_a >=
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_k) {
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_a =
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_k;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_a <=
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_h) {
      sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_a =
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_h;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S69>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S80>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_e =
    sel751test_model_1_3_ss_relays_B.TSamp_b;

  /* Update for UnitDelay: '<S70>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_i =
    sel751test_model_1_3_ss_relays_B.y_o;

  /* Update for DiscreteStateSpace: '<S67>/Discrete State-Space' */
  {
    real_T xnew[2];
    xnew[0] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_g[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_l[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_g[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_l[1];
    xnew[0] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_a[0])*
      sel751test_model_1_3_ss_relays_B.y_o;
    xnew[1] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_g[2])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_l[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_g[3])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_l[1];
    xnew[1] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_a[1])*
      sel751test_model_1_3_ss_relays_B.y_o;
    (void) memcpy
      (&sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_l[0], xnew,
       sizeof(real_T)*2);
  }

  /* Update for DiscreteIntegrator: '<S87>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_od = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_oi =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_hr *
    sel751test_model_1_3_ss_relays_B.Vq_n +
    sel751test_model_1_3_ss_relays_B.Integ4_mb;

  /* S-Function block: <S98>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S97>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_g =
    sel751test_model_1_3_ss_relays_B.Vq_n;

  /* Update for Enabled SubSystem: '<S66>/Automatic Gain Control' incorporates:
   *  Update for EnablePort: '<S84>/Enable'
   */
  if (sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_c) {
    /* Update for DiscreteIntegrator: '<S90>/Integ4' */
    sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_ll = 0U;
    sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_er =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_h *
      sel751test_model_1_3_ss_relays_B.Product_hq[0] +
      sel751test_model_1_3_ss_relays_B.Integ4_pk;

    /* S-Function block: <S93>/S-Function  */
    {
      int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.indBeg;
      int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.indEnd;
      int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.indBeg = indBeg;
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S92>/Unit Delay' */
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_go =
      sel751test_model_1_3_ss_relays_B.Product_hq[0];

    /* Update for DiscreteIntegrator: '<S91>/Integ4' */
    sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_fr = 0U;
    sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_h4 =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_n *
      sel751test_model_1_3_ss_relays_B.Product_hq[1] +
      sel751test_model_1_3_ss_relays_B.Integ4_f;

    /* S-Function block: <S95>/S-Function  */
    {
      int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.indBeg;
      int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.indEnd;
      int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.indBeg = indBeg;
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S94>/Unit Delay' */
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ku =
      sel751test_model_1_3_ss_relays_B.Product_hq[1];
  }

  /* End of Update for SubSystem: '<S66>/Automatic Gain Control' */

  /* Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_iq +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainv_f4 *
    sel751test_model_1_3_ss_relays_B.Kp5_m;
  if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_iq >=
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_n) {
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_iq =
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_n;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_iq <=
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_l) {
      sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_iq =
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_l;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S96>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_b =
    sel751test_model_1_3_ss_relays_B.TSamp_m;

  /* Update for UnitDelay: '<S86>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_a =
    sel751test_model_1_3_ss_relays_B.y_k;

  /* Update for DiscreteStateSpace: '<S83>/Discrete State-Space' */
  {
    real_T xnew[2];
    xnew[0] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_h[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_k[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_h[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_k[1];
    xnew[0] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_ow[0])*
      sel751test_model_1_3_ss_relays_B.y_k;
    xnew[1] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_h[2])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_k[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_h[3])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_k[1];
    xnew[1] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_ow[1])*
      sel751test_model_1_3_ss_relays_B.y_k;
    (void) memcpy
      (&sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_k[0], xnew,
       sizeof(real_T)*2);
  }

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_p +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_b *
    sel751test_model_1_3_ss_relays_B.Saturation2_d;

  /* Update for DiscreteIntegrator: '<S119>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_l = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_h =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_k *
    sel751test_model_1_3_ss_relays_B.Vq_j +
    sel751test_model_1_3_ss_relays_B.Integ4_jt;

  /* S-Function block: <S122>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S119>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_au =
    sel751test_model_1_3_ss_relays_B.Vq_j;

  /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_j +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_p *
    sel751test_model_1_3_ss_relays_B.Kp5_g;
  if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_j >=
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_m) {
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_j =
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_m;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_j <=
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_o) {
      sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_j =
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_o;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S121>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_n =
    sel751test_model_1_3_ss_relays_B.TSamp_e;

  /* Update for UnitDelay: '<S118>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_o =
    sel751test_model_1_3_ss_relays_B.y_gn;

  /* Update for DiscreteStateSpace: '<S116>/Discrete State-Space' */
  {
    real_T xnew[2];
    xnew[0] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_m[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_d[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_m[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_d[1];
    xnew[0] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_j[0])*
      sel751test_model_1_3_ss_relays_B.y_gn;
    xnew[1] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_m[2])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_d[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_m[3])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_d[1];
    xnew[1] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_j[1])*
      sel751test_model_1_3_ss_relays_B.y_gn;
    (void) memcpy
      (&sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_d[0], xnew,
       sizeof(real_T)*2);
  }

  /* Update for UnitDelay: '<S101>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_b =
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_mz;

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_m +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_g *
    sel751test_model_1_3_ss_relays_B.Saturation2_k;

  /* Update for DiscreteIntegrator: '<S126>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_c = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_cw =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_g3 *
    sel751test_model_1_3_ss_relays_B.Vq_f +
    sel751test_model_1_3_ss_relays_B.Integ4_l;

  /* S-Function block: <S129>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S126>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jt =
    sel751test_model_1_3_ss_relays_B.Vq_f;

  /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_jr +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_o *
    sel751test_model_1_3_ss_relays_B.Kp5_a;
  if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_jr >=
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_Upper_m5) {
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_jr =
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_Upper_m5;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_jr <=
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_m) {
      sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_jr =
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_m;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S128>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_m =
    sel751test_model_1_3_ss_relays_B.TSamp_d;

  /* Update for UnitDelay: '<S125>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_an =
    sel751test_model_1_3_ss_relays_B.y_h;

  /* Update for DiscreteStateSpace: '<S123>/Discrete State-Space' */
  {
    real_T xnew[2];
    xnew[0] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_hs[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_j[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_hs[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_j[1];
    xnew[0] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_f[0])*
      sel751test_model_1_3_ss_relays_B.y_h;
    xnew[1] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_hs[2])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_j[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_hs[3])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_j[1];
    xnew[1] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_f[1])*
      sel751test_model_1_3_ss_relays_B.y_h;
    (void) memcpy
      (&sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_j[0], xnew,
       sizeof(real_T)*2);
  }

  /* Update for UnitDelay: '<S102>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_hh =
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_mi;

  /* Update for DiscreteIntegrator: '<S140>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_lg = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_e[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_mc *
    sel751test_model_1_3_ss_relays_B.P_j +
    sel751test_model_1_3_ss_relays_B.Integ4_b[0];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_e[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_mc *
    sel751test_model_1_3_ss_relays_B.Q_f +
    sel751test_model_1_3_ss_relays_B.Integ4_b[1];

  /* S-Function block: <S141>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S140>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_e5[0] =
    sel751test_model_1_3_ss_relays_B.P_j;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_e5[1] =
    sel751test_model_1_3_ss_relays_B.Q_f;

  /* Update for UnitDelay: '<S134>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_g =
    sel751test_model_1_3_ss_relays_B.Xnew_h;

  /* Update for UnitDelay: '<S135>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_b =
    sel751test_model_1_3_ss_relays_B.Xnew_b;

  /* Update for UnitDelay: '<S136>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_a =
    sel751test_model_1_3_ss_relays_B.Xnew_f;

  /* Update for UnitDelay: '<S190>/Delay Input1' */
  sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE_o =
    sel751test_model_1_3_ss_relays_B.LogicalOperator1_g;

  /* Update for DiscreteIntegrator: '<S142>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_f = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_nk *
    sel751test_model_1_3_ss_relays_B.Product3_d[0] +
    sel751test_model_1_3_ss_relays_B.Integ4_ja[0];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_nk *
    sel751test_model_1_3_ss_relays_B.Product3_d[1] +
    sel751test_model_1_3_ss_relays_B.Integ4_ja[1];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[2] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_nk *
    sel751test_model_1_3_ss_relays_B.Product3_d[2] +
    sel751test_model_1_3_ss_relays_B.Integ4_ja[2];

  /* S-Function block: <S143>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S142>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_p[0] =
    sel751test_model_1_3_ss_relays_B.Product3_d[0];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_p[1] =
    sel751test_model_1_3_ss_relays_B.Product3_d[1];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_p[2] =
    sel751test_model_1_3_ss_relays_B.Product3_d[2];

  /* Update for DiscreteIntegrator: '<S144>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_fs = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_nj *
    sel751test_model_1_3_ss_relays_B.Product3_b[0] +
    sel751test_model_1_3_ss_relays_B.Integ4_cl[0];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_nj *
    sel751test_model_1_3_ss_relays_B.Product3_b[1] +
    sel751test_model_1_3_ss_relays_B.Integ4_cl[1];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[2] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_nj *
    sel751test_model_1_3_ss_relays_B.Product3_b[2] +
    sel751test_model_1_3_ss_relays_B.Integ4_cl[2];

  /* S-Function block: <S145>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S144>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jf[0] =
    sel751test_model_1_3_ss_relays_B.Product3_b[0];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jf[1] =
    sel751test_model_1_3_ss_relays_B.Product3_b[1];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jf[2] =
    sel751test_model_1_3_ss_relays_B.Product3_b[2];

  /* Update for UnitDelay: '<S137>/Delay Input1' */
  sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE_a =
    sel751test_model_1_3_ss_relays_B.SFunction_o[4];

  /* Update for Memory: '<S138>/Memory' */
  sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput_g =
    sel751test_model_1_3_ss_relays_B.Logic_h[0];

  /* Update for DiscreteIntegrator: '<S154>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_h = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_p[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_an *
    sel751test_model_1_3_ss_relays_B.Product3_f[0] +
    sel751test_model_1_3_ss_relays_B.Integ4_ef[0];
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_p[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_an *
    sel751test_model_1_3_ss_relays_B.Product3_f[1] +
    sel751test_model_1_3_ss_relays_B.Integ4_ef[1];

  /* S-Function block: <S155>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S154>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ea[0] =
    sel751test_model_1_3_ss_relays_B.Product3_f[0];
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ea[1] =
    sel751test_model_1_3_ss_relays_B.Product3_f[1];

  /* Update for UnitDelay: '<S157>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jm =
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_l;

  /* Update for UnitDelay: '<S156>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_im =
    sel751test_model_1_3_ss_relays_B.DiscreteStateSpace_c;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_ii +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainv_kv *
    sel751test_model_1_3_ss_relays_B.Saturation2_l;

  /* Update for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_f +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_j *
    sel751test_model_1_3_ss_relays_B.Saturation2_jn;

  /* Update for Memory: '<S149>/Memory' */
  sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput_h =
    sel751test_model_1_3_ss_relays_B.Logic_b[0];

  /* Update for Memory: '<S6>/Memory2' */
  sel751test_model_1_3_ss_relays_DW.Memory2_PreviousInput_j =
    sel751test_model_1_3_ss_relays_B.Sum1_n2;

  /* Update for Memory: '<S6>/Memory9' */
  sel751test_model_1_3_ss_relays_DW.Memory9_PreviousInput_i =
    sel751test_model_1_3_ss_relays_B.Sum_m;

  /* Update for DiscreteIntegrator: '<S162>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_bf = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_pp =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_p *
    sel751test_model_1_3_ss_relays_B.Vq_l +
    sel751test_model_1_3_ss_relays_B.Integ4_p;

  /* S-Function block: <S173>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S172>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_l0 =
    sel751test_model_1_3_ss_relays_B.Vq_l;

  /* Update for Enabled SubSystem: '<S156>/Automatic Gain Control' incorporates:
   *  Update for EnablePort: '<S159>/Enable'
   */
  if (sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_m) {
    /* Update for DiscreteIntegrator: '<S165>/Integ4' */
    sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_kt = 0U;
    sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_my =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_c *
      sel751test_model_1_3_ss_relays_B.Product_a[0] +
      sel751test_model_1_3_ss_relays_B.Integ4_cf;

    /* S-Function block: <S168>/S-Function  */
    {
      int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.indBeg;
      int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.indEnd;
      int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.indBeg = indBeg;
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S167>/Unit Delay' */
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ir =
      sel751test_model_1_3_ss_relays_B.Product_a[0];

    /* Update for DiscreteIntegrator: '<S166>/Integ4' */
    sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_ds = 0U;
    sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_ip =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_a *
      sel751test_model_1_3_ss_relays_B.Product_a[1] +
      sel751test_model_1_3_ss_relays_B.Integ4_d2;

    /* S-Function block: <S170>/S-Function  */
    {
      int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.indBeg;
      int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.indEnd;
      int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.indBeg = indBeg;
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S169>/Unit Delay' */
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_lv =
      sel751test_model_1_3_ss_relays_B.Product_a[1];
  }

  /* End of Update for SubSystem: '<S156>/Automatic Gain Control' */

  /* Update for DiscreteIntegrator: '<S160>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_pw +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainva_h *
    sel751test_model_1_3_ss_relays_B.Kp5_kx;
  if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_pw >=
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_o) {
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_pw =
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_UpperS_o;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_pw <=
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_Lower_hx) {
      sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_pw =
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_Lower_hx;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S160>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S171>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_h =
    sel751test_model_1_3_ss_relays_B.TSamp_n;

  /* Update for UnitDelay: '<S161>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_gp =
    sel751test_model_1_3_ss_relays_B.y_l;

  /* Update for DiscreteStateSpace: '<S158>/Discrete State-Space' */
  {
    real_T xnew[2];
    xnew[0] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_b[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_h[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_b[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_h[1];
    xnew[0] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_m[0])*
      sel751test_model_1_3_ss_relays_B.y_l;
    xnew[1] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_b[2])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_h[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_b[3])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_h[1];
    xnew[1] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_m[1])*
      sel751test_model_1_3_ss_relays_B.y_l;
    (void) memcpy
      (&sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_h[0], xnew,
       sizeof(real_T)*2);
  }

  /* Update for DiscreteIntegrator: '<S178>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_os = 0U;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_ei =
    sel751test_model_1_3_ss_relays_P.Integ4_gainval_eg *
    sel751test_model_1_3_ss_relays_B.Vq_il +
    sel751test_model_1_3_ss_relays_B.Integ4_pa;

  /* S-Function block: <S189>/S-Function  */
  {
    int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.indBeg;
    int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.indEnd;
    int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.bufSz;
    indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
    if (indEnd == indBeg) {
      indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
    }

    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.indBeg = indBeg;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.indEnd = indEnd;
  }

  /* Update for UnitDelay: '<S188>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_lo =
    sel751test_model_1_3_ss_relays_B.Vq_il;

  /* Update for Enabled SubSystem: '<S157>/Automatic Gain Control' incorporates:
   *  Update for EnablePort: '<S175>/Enable'
   */
  if (sel751test_model_1_3_ss_relays_DW.AutomaticGainControl_MODE_o) {
    /* Update for DiscreteIntegrator: '<S181>/Integ4' */
    sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_l4 = 0U;
    sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_pe =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_f *
      sel751test_model_1_3_ss_relays_B.Product_h[0] +
      sel751test_model_1_3_ss_relays_B.Integ4_a;

    /* S-Function block: <S184>/S-Function  */
    {
      int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.indBeg;
      int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.indEnd;
      int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.indBeg = indBeg;
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S183>/Unit Delay' */
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_pr =
      sel751test_model_1_3_ss_relays_B.Product_h[0];

    /* Update for DiscreteIntegrator: '<S182>/Integ4' */
    sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_hr = 0U;
    sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_d =
      sel751test_model_1_3_ss_relays_P.Integ4_gainval_i *
      sel751test_model_1_3_ss_relays_B.Product_h[1] +
      sel751test_model_1_3_ss_relays_B.Integ4_c0;

    /* S-Function block: <S186>/S-Function  */
    {
      int_T indBeg = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.indBeg;
      int_T indEnd = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.indEnd;
      int_T bufSz = sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.indBeg = indBeg;
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S185>/Unit Delay' */
    sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_hw =
      sel751test_model_1_3_ss_relays_B.Product_h[1];
  }

  /* End of Update for SubSystem: '<S157>/Automatic Gain Control' */

  /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_c +=
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_gainv_kk *
    sel751test_model_1_3_ss_relays_B.Kp5_e;
  if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_c >=
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_Upper_au) {
    sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_c =
      sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_Upper_au;
  } else {
    if (sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_c <=
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_p) {
      sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_c =
        sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_LowerS_p;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S187>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_i =
    sel751test_model_1_3_ss_relays_B.TSamp_h;

  /* Update for UnitDelay: '<S177>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_pk =
    sel751test_model_1_3_ss_relays_B.y_e;

  /* Update for DiscreteStateSpace: '<S174>/Discrete State-Space' */
  {
    real_T xnew[2];
    xnew[0] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_hy[0])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_m[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_hy[1])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_m[1];
    xnew[0] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_l[0])*
      sel751test_model_1_3_ss_relays_B.y_e;
    xnew[1] = (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_hy[2])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_m[0]
      + (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_A_hy[3])*
      sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_m[1];
    xnew[1] += (sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_B_l[1])*
      sel751test_model_1_3_ss_relays_B.y_e;
    (void) memcpy
      (&sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_m[0], xnew,
       sizeof(real_T)*2);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sel751test_model_1_3_ss_relays_M->Timing.clockTick0)) {
    ++sel751test_model_1_3_ss_relays_M->Timing.clockTickH0;
  }

  sel751test_model_1_3_ss_relays_M->Timing.t[0] =
    sel751test_model_1_3_ss_relays_M->Timing.clockTick0 *
    sel751test_model_1_3_ss_relays_M->Timing.stepSize0 +
    sel751test_model_1_3_ss_relays_M->Timing.clockTickH0 *
    sel751test_model_1_3_ss_relays_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void sel751test_model_1_3_ss_relays_initialize(void)
{
  /* S-Function Block: <S31>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_e.indEnd = 1;
  }

  /* S-Function Block: <S38>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_a.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_a.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_a.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_h.indEnd = 1;
  }

  /* S-Function Block: <S50>/S-Function  */
  {
    static real_T dvtd_buffer[2 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[0] = (void *)
      &dvtd_buffer[0];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[1] = (void *)
      &dvtd_buffer[168];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[0] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[0])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[1] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o.uBuffers[1])
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_l.indEnd = 1;
  }

  /* S-Function Block: <S52>/S-Function  */
  {
    static real_T dvtd_buffer[3 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[0] = (void *)
      &dvtd_buffer[0];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[1] = (void *)
      &dvtd_buffer[168];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[2] = (void *)
      &dvtd_buffer[336];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[0] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[0])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[1] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[1])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[2] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_n.uBuffers[2])
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_j.indEnd = 1;
  }

  /* S-Function Block: <S54>/S-Function  */
  {
    static real_T dvtd_buffer[3 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[0] = (void *)
      &dvtd_buffer[0];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[1] = (void *)
      &dvtd_buffer[168];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[2] = (void *)
      &dvtd_buffer[336];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[0] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[0])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[1] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[1])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[2] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_m.uBuffers[2])
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_es.indEnd = 1;
  }

  /* S-Function Block: <S64>/S-Function  */
  {
    static real_T dvtd_buffer[2 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers[0] = (void *)
      &dvtd_buffer[0];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers[1] = (void *)
      &dvtd_buffer[168];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers[0] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers
        [0]) = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers[1] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ne.uBuffers
        [1]) = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f.indEnd = 1;
  }

  /* S-Function Block: <S82>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_g.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_g.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_g.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hj.indEnd = 1;
  }

  /* Start for Enabled SubSystem: '<S65>/Automatic Gain Control' */

  /* S-Function Block: <S77>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_es.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_es.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_es.uBuffers)
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_f5.indEnd = 1;
  }

  /* S-Function Block: <S79>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_h.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_h.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_h.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_dt.indEnd = 1;
  }

  /* End of Start for SubSystem: '<S65>/Automatic Gain Control' */

  /* InitializeConditions for Enabled SubSystem: '<S65>/Automatic Gain Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S74>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_n =
    sel751test_model_1_3_ss_relays_P.Integ4_IC;

  /* InitializeConditions for UnitDelay: '<S76>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_b5 =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_j =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_o;

  /* InitializeConditions for UnitDelay: '<S78>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_hf =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_e;

  /* End of InitializeConditions for SubSystem: '<S65>/Automatic Gain Control' */

  /* Start for Enabled SubSystem: '<S65>/Automatic Gain Control' */
  /* VirtualOutportStart for Outport: '<S68>/Gain' */
  sel751test_model_1_3_ss_relays_B.MathFunction_gy =
    sel751test_model_1_3_ss_relays_P.Gain_Y0;

  /* End of Start for SubSystem: '<S65>/Automatic Gain Control' */

  /* S-Function Block: <S98>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_f.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_f.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_f.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_d.indEnd = 1;
  }

  /* Start for Enabled SubSystem: '<S66>/Automatic Gain Control' */

  /* S-Function Block: <S93>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gl.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gl.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gl.uBuffers)
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_m.indEnd = 1;
  }

  /* S-Function Block: <S95>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_l.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_l.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_l.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_nd.indEnd = 1;
  }

  /* End of Start for SubSystem: '<S66>/Automatic Gain Control' */

  /* InitializeConditions for Enabled SubSystem: '<S66>/Automatic Gain Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S90>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_er =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_a;

  /* InitializeConditions for UnitDelay: '<S92>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_go =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_g;

  /* InitializeConditions for DiscreteIntegrator: '<S91>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_h4 =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_i;

  /* InitializeConditions for UnitDelay: '<S94>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ku =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_i;

  /* End of InitializeConditions for SubSystem: '<S66>/Automatic Gain Control' */

  /* Start for Enabled SubSystem: '<S66>/Automatic Gain Control' */
  /* VirtualOutportStart for Outport: '<S84>/Gain' */
  sel751test_model_1_3_ss_relays_B.MathFunction_g0 =
    sel751test_model_1_3_ss_relays_P.Gain_Y0_p;

  /* End of Start for SubSystem: '<S66>/Automatic Gain Control' */

  /* S-Function Block: <S122>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_b.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_b.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_b.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a.indEnd = 1;
  }

  /* S-Function Block: <S129>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_bf.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_bf.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_bf.uBuffers)
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fv.indEnd = 1;
  }

  /* S-Function Block: <S141>/S-Function  */
  {
    static real_T dvtd_buffer[2 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[0] = (void *)
      &dvtd_buffer[0];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[1] = (void *)
      &dvtd_buffer[168];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[0] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[0])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[1] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_k.uBuffers[1])
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_jj.indEnd = 1;
  }

  /* S-Function Block: <S143>/S-Function  */
  {
    static real_T dvtd_buffer[3 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[0] = (void *)
      &dvtd_buffer[0];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[1] = (void *)
      &dvtd_buffer[168];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[2] = (void *)
      &dvtd_buffer[336];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[0] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[0])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[1] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[1])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[2] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_c.uBuffers[2])
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_k.indEnd = 1;
  }

  /* S-Function Block: <S145>/S-Function  */
  {
    static real_T dvtd_buffer[3 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[0] = (void *)
      &dvtd_buffer[0];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[1] = (void *)
      &dvtd_buffer[168];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[2] = (void *)
      &dvtd_buffer[336];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[0] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[0])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[1] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[1])
        = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[2] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_p.uBuffers[2])
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p.indEnd = 1;
  }

  /* S-Function Block: <S155>/S-Function  */
  {
    static real_T dvtd_buffer[2 * 168];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.bufSz = 168;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers[0] = (void *)
      &dvtd_buffer[0];
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers[1] = (void *)
      &dvtd_buffer[168];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers[0] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers
        [0]) = (real_T)0.0;
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers[1] != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_ko.uBuffers
        [1]) = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_hc.indEnd = 1;
  }

  /* S-Function Block: <S173>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o3.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o3.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_o3.uBuffers)
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_fs.indEnd = 1;
  }

  /* Start for Enabled SubSystem: '<S156>/Automatic Gain Control' */

  /* S-Function Block: <S168>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e5.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e5.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_e5.uBuffers)
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_a2.indEnd = 1;
  }

  /* S-Function Block: <S170>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gs.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gs.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_gs.uBuffers)
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_n.indEnd = 1;
  }

  /* End of Start for SubSystem: '<S156>/Automatic Gain Control' */

  /* InitializeConditions for Enabled SubSystem: '<S156>/Automatic Gain Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S165>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_my =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_b;

  /* InitializeConditions for UnitDelay: '<S167>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ir =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_j;

  /* InitializeConditions for DiscreteIntegrator: '<S166>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_ip =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_om;

  /* InitializeConditions for UnitDelay: '<S169>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_lv =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_p;

  /* End of InitializeConditions for SubSystem: '<S156>/Automatic Gain Control' */

  /* Start for Enabled SubSystem: '<S156>/Automatic Gain Control' */
  /* VirtualOutportStart for Outport: '<S159>/Gain' */
  sel751test_model_1_3_ss_relays_B.MathFunction_ib =
    sel751test_model_1_3_ss_relays_P.Gain_Y0_f;

  /* End of Start for SubSystem: '<S156>/Automatic Gain Control' */

  /* S-Function Block: <S189>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_kx.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_kx.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_kx.uBuffers)
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_ff.indEnd = 1;
  }

  /* Start for Enabled SubSystem: '<S157>/Automatic Gain Control' */

  /* S-Function Block: <S184>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_i.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_i.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_i.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_p1.indEnd = 1;
  }

  /* S-Function Block: <S186>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 224];
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.bufSz = 224;
    sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_fl.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.maxDiscrDelay =
      sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_fl.uBuffers != NULL)
      *((real_T *)sel751test_model_1_3_ss_relays_DW.SFunction_PWORK_fl.uBuffers)
        = (real_T)0.0;

    /* Set work values */
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.indBeg = 0;
    sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_c.indEnd = 1;
  }

  /* End of Start for SubSystem: '<S157>/Automatic Gain Control' */

  /* InitializeConditions for Enabled SubSystem: '<S157>/Automatic Gain Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S181>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_pe =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_h;

  /* InitializeConditions for UnitDelay: '<S183>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_pr =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_jg;

  /* InitializeConditions for DiscreteIntegrator: '<S182>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_d =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_m;

  /* InitializeConditions for UnitDelay: '<S185>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_hw =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_c;

  /* End of InitializeConditions for SubSystem: '<S157>/Automatic Gain Control' */

  /* Start for Enabled SubSystem: '<S157>/Automatic Gain Control' */
  /* VirtualOutportStart for Outport: '<S175>/Gain' */
  sel751test_model_1_3_ss_relays_B.MathFunction_o =
    sel751test_model_1_3_ss_relays_P.Gain_Y0_k;

  /* End of Start for SubSystem: '<S157>/Automatic Gain Control' */

  /* user code (Initialize function Body) */

  /* System '<Root>' */

  /* Opal-RT Technologies */
  opalSizeDwork = sizeof(rtDWork);

#ifdef USE_RTMODEL

  if (Opal_rtmGetNumBlockIO(pRtModel) != 0)
    opalSizeBlockIO = sizeof(rtB);
  else
    opalSizeBlockIO = 0;
  if (Opal_rtmGetNumBlockParams(pRtModel) != 0)
    opalSizeRTP = sizeof(rtP);
  else
    opalSizeRTP = 0;

#else

  if (ssGetNumBlockIO(rtS) != 0)
    opalSizeBlockIO = sizeof(rtB);
  else
    opalSizeBlockIO = 0;
  if (ssGetNumBlockParams(rtS) != 0)
    opalSizeRTP = sizeof(rtP);
  else
    opalSizeRTP = 0;

#endif

  /* InitializeConditions for Memory: '<S2>/S-Function' */
  sel751test_model_1_3_ss_relays_DW.SFunction_PreviousInput =
    sel751test_model_1_3_ss_relays_P.SFunction_X0;

  /* InitializeConditions for Memory: '<S5>/Memory1' */
  sel751test_model_1_3_ss_relays_DW.Memory1_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S5>/Memory8' */
  sel751test_model_1_3_ss_relays_DW.Memory8_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory8_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput[0] =
    sel751test_model_1_3_ss_relays_P.Memory3_1_X0;
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput[1] =
    sel751test_model_1_3_ss_relays_P.Memory3_1_X0;
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput[2] =
    sel751test_model_1_3_ss_relays_P.Memory3_1_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput[0] =
    sel751test_model_1_3_ss_relays_P.Memory3_2_X0;
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput[1] =
    sel751test_model_1_3_ss_relays_P.Memory3_2_X0;
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput[2] =
    sel751test_model_1_3_ss_relays_P.Memory3_2_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_3_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory3_3_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_4_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory3_4_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_5_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory3_5_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_6_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory3_6_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_7_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory3_7_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_8_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory3_8_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_9_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory3_9_X0;

  /* InitializeConditions for Memory: '<S5>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_10_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory3_10_X0;

  /* InitializeConditions for Memory: '<S6>/Memory1' */
  sel751test_model_1_3_ss_relays_DW.Memory1_PreviousInput_e =
    sel751test_model_1_3_ss_relays_P.Memory1_X0_l;

  /* InitializeConditions for Memory: '<S6>/Memory8' */
  sel751test_model_1_3_ss_relays_DW.Memory8_PreviousInput_e =
    sel751test_model_1_3_ss_relays_P.Memory8_X0_o;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput_p[0] =
    sel751test_model_1_3_ss_relays_P.Memory3_1_X0_b;
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput_p[1] =
    sel751test_model_1_3_ss_relays_P.Memory3_1_X0_b;
  sel751test_model_1_3_ss_relays_DW.Memory3_1_PreviousInput_p[2] =
    sel751test_model_1_3_ss_relays_P.Memory3_1_X0_b;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput_l[0] =
    sel751test_model_1_3_ss_relays_P.Memory3_2_X0_b;
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput_l[1] =
    sel751test_model_1_3_ss_relays_P.Memory3_2_X0_b;
  sel751test_model_1_3_ss_relays_DW.Memory3_2_PreviousInput_l[2] =
    sel751test_model_1_3_ss_relays_P.Memory3_2_X0_b;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_3_PreviousInput_n =
    sel751test_model_1_3_ss_relays_P.Memory3_3_X0_b;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_4_PreviousInput_g =
    sel751test_model_1_3_ss_relays_P.Memory3_4_X0_b;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_5_PreviousInput_d =
    sel751test_model_1_3_ss_relays_P.Memory3_5_X0_b;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_6_PreviousInput_m =
    sel751test_model_1_3_ss_relays_P.Memory3_6_X0_b;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_7_PreviousInput_c =
    sel751test_model_1_3_ss_relays_P.Memory3_7_X0_b;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_8_PreviousInput_d =
    sel751test_model_1_3_ss_relays_P.Memory3_8_X0_b;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_9_PreviousInput_l =
    sel751test_model_1_3_ss_relays_P.Memory3_9_X0_b;

  /* InitializeConditions for Memory: '<S6>/Memory3' */
  sel751test_model_1_3_ss_relays_DW.Memory3_10_PreviousInput_e =
    sel751test_model_1_3_ss_relays_P.Memory3_10_X0_b;

  /* InitializeConditions for Atomic SubSystem: '<S8>/Subsystem2' */

  /* Level2 S-Function Block: '<S198>/S-Function' (send_rt) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of InitializeConditions for SubSystem: '<S8>/Subsystem2' */

  /* Level2 S-Function Block: '<S197>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S199>/S-Function' (recv_rt) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_bo;

  /* InitializeConditions for UnitDelay: '<S28>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_h;

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_d =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_m;

  /* InitializeConditions for UnitDelay: '<S30>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE =
    sel751test_model_1_3_ss_relays_P.UD_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S27>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_l =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_ia;

  /* InitializeConditions for DiscreteStateSpace: '<S25>/Discrete State-Space' */
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE[0] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0[0];
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE[1] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0[1];

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_n =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_k;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_i =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_l;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_o =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_f;

  /* InitializeConditions for UnitDelay: '<S35>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_n1 =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_a;

  /* InitializeConditions for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_b =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_me;

  /* InitializeConditions for UnitDelay: '<S37>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_p =
    sel751test_model_1_3_ss_relays_P.UD_InitialCondition_e;

  /* InitializeConditions for UnitDelay: '<S34>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_e =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_aa;

  /* InitializeConditions for DiscreteStateSpace: '<S32>/Discrete State-Space' */
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_b[0] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_i[0];
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_b[1] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_i[1];

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_k =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_b;

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_i[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_i4;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_i[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_i4;

  /* InitializeConditions for UnitDelay: '<S49>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_kt[0] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_f;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_kt[1] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_f;

  /* InitializeConditions for UnitDelay: '<S43>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE =
    sel751test_model_1_3_ss_relays_P.FixPtUnitDelay1_InitialConditio;

  /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_n =
    sel751test_model_1_3_ss_relays_P.FixPtUnitDelay1_InitialCondit_a;

  /* InitializeConditions for UnitDelay: '<S45>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_n0 =
    sel751test_model_1_3_ss_relays_P.FixPtUnitDelay1_InitialCondit_g;

  /* Level2 S-Function Block: '<S192>/S-Function' (RECV_Param) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[3];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S99>/Delay Input1' */
  sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE_k =
    sel751test_model_1_3_ss_relays_P.DelayInput1_InitialCondition_i;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_k;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_k;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_c[2] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_k;

  /* InitializeConditions for UnitDelay: '<S51>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_h[0] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_jv;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_h[1] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_jv;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_h[2] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_jv;

  /* InitializeConditions for DiscreteIntegrator: '<S53>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_fb;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_fb;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_a[2] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_fb;

  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_d[0] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_aw;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_d[1] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_aw;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_d[2] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_aw;

  /* InitializeConditions for MATLAB Function: '<S23>/Relays' */
  sel751test_model_1__Relays_Init(&sel751test_model_1_3_ss_relays_DW.sf_Relays);

  /* InitializeConditions for UnitDelay: '<S46>/Delay Input1' */
  sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE =
    sel751test_model_1_3_ss_relays_P.DelayInput1_InitialCondition;

  /* InitializeConditions for Memory: '<S47>/Memory' */
  sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory_X0;

  /* InitializeConditions for DiscreteIntegrator: '<S63>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_id[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_ke;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_id[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_ke;

  /* InitializeConditions for UnitDelay: '<S63>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_m[0] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_k3;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_m[1] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_k3;

  /* InitializeConditions for UnitDelay: '<S66>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_j =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_cg;

  /* InitializeConditions for UnitDelay: '<S65>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ez =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_ab;

  /* InitializeConditions for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_h =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_p;

  /* InitializeConditions for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_o =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_b;

  /* InitializeConditions for S-Function (sdspunwrap2): '<S56>/Unwrap' */
  sel751test_model_1_3_ss_relays_DW.Unwrap_FirstStep = TRUE;
  sel751test_model_1_3_ss_relays_DW.Unwrap_Cumsum = 0.0;

  /* InitializeConditions for Memory: '<S58>/Memory' */
  sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput_o =
    sel751test_model_1_3_ss_relays_P.Memory_X0_p;

  /* InitializeConditions for MATLAB Function: '<S5>/trip_out mng' */
  sel751test_mod_trip_outmng_Init
    (&sel751test_model_1_3_ss_relays_DW.sf_trip_outmng);

  /* InitializeConditions for Memory: '<S5>/Memory2' */
  sel751test_model_1_3_ss_relays_DW.Memory2_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory2_X0;

  /* InitializeConditions for Memory: '<S5>/Memory9' */
  sel751test_model_1_3_ss_relays_DW.Memory9_PreviousInput =
    sel751test_model_1_3_ss_relays_P.Memory9_X0;

  /* InitializeConditions for DiscreteIntegrator: '<S71>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_m =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_j;

  /* InitializeConditions for UnitDelay: '<S81>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ed =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_ij;

  /* InitializeConditions for DiscreteIntegrator: '<S69>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_a =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_m2;

  /* InitializeConditions for UnitDelay: '<S80>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_e =
    sel751test_model_1_3_ss_relays_P.UD_InitialCondition_k;

  /* InitializeConditions for UnitDelay: '<S70>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_i =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_bu;

  /* InitializeConditions for DiscreteStateSpace: '<S67>/Discrete State-Space' */
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_l[0] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_o[0];
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_l[1] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_o[1];

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_oi =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_j3;

  /* InitializeConditions for UnitDelay: '<S97>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_g =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_ff;

  /* InitializeConditions for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_iq =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_i;

  /* InitializeConditions for UnitDelay: '<S96>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_b =
    sel751test_model_1_3_ss_relays_P.UD_InitialCondition_b;

  /* InitializeConditions for UnitDelay: '<S86>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_a =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_m;

  /* InitializeConditions for DiscreteStateSpace: '<S83>/Discrete State-Space' */
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_k[0] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_j[0];
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_k[1] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_j[1];

  /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_p =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_g;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_h =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_mt;

  /* InitializeConditions for UnitDelay: '<S119>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_au =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_l;

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_j =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_b2;

  /* InitializeConditions for UnitDelay: '<S121>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_n =
    sel751test_model_1_3_ss_relays_P.UD_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S118>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_o =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_o;

  /* InitializeConditions for DiscreteStateSpace: '<S116>/Discrete State-Space' */
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_d[0] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_k[0];
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_d[1] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_k[1];

  /* InitializeConditions for UnitDelay: '<S101>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_b =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_hc;

  /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_m =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_e;

  /* InitializeConditions for DiscreteIntegrator: '<S126>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_cw =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_l;

  /* InitializeConditions for UnitDelay: '<S126>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jt =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_d;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_jr =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_h;

  /* InitializeConditions for UnitDelay: '<S128>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_m =
    sel751test_model_1_3_ss_relays_P.UD_InitialCondition_a;

  /* InitializeConditions for UnitDelay: '<S125>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_an =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_as;

  /* InitializeConditions for DiscreteStateSpace: '<S123>/Discrete State-Space' */
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_j[0] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_n[0];
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_j[1] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_n[1];

  /* InitializeConditions for UnitDelay: '<S102>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_hh =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_px;

  /* InitializeConditions for DiscreteIntegrator: '<S140>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_e[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_p;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_e[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_p;

  /* InitializeConditions for UnitDelay: '<S140>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_e5[0] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_lr;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_e5[1] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_lr;

  /* InitializeConditions for UnitDelay: '<S134>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_g =
    sel751test_model_1_3_ss_relays_P.FixPtUnitDelay1_InitialCondit_c;

  /* InitializeConditions for UnitDelay: '<S135>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_b =
    sel751test_model_1_3_ss_relays_P.FixPtUnitDelay1_InitialCondit_k;

  /* InitializeConditions for UnitDelay: '<S136>/FixPt Unit Delay1' */
  sel751test_model_1_3_ss_relays_DW.FixPtUnitDelay1_DSTATE_a =
    sel751test_model_1_3_ss_relays_P.FixPtUnitDelay1_InitialCondit_e;

  /* InitializeConditions for UnitDelay: '<S190>/Delay Input1' */
  sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE_o =
    sel751test_model_1_3_ss_relays_P.DelayInput1_InitialCondition_l;

  /* InitializeConditions for DiscreteIntegrator: '<S142>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_jj;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_jj;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_f[2] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_jj;

  /* InitializeConditions for UnitDelay: '<S142>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_p[0] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_kx;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_p[1] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_kx;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_p[2] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_kx;

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_fn;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_fn;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_k[2] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_fn;

  /* InitializeConditions for UnitDelay: '<S144>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jf[0] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_lz;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jf[1] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_lz;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jf[2] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_lz;

  /* InitializeConditions for MATLAB Function: '<S114>/Relays' */
  sel751test_model_1__Relays_Init(&sel751test_model_1_3_ss_relays_DW.sf_Relays_c);

  /* InitializeConditions for UnitDelay: '<S137>/Delay Input1' */
  sel751test_model_1_3_ss_relays_DW.DelayInput1_DSTATE_a =
    sel751test_model_1_3_ss_relays_P.DelayInput1_InitialCondition_a;

  /* InitializeConditions for Memory: '<S138>/Memory' */
  sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput_g =
    sel751test_model_1_3_ss_relays_P.Memory_X0_f;

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_p[0] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_jt;
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_p[1] =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_jt;

  /* InitializeConditions for UnitDelay: '<S154>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ea[0] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_ig;
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_ea[1] =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_ig;

  /* InitializeConditions for UnitDelay: '<S157>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_jm =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_ip;

  /* InitializeConditions for UnitDelay: '<S156>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_im =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_ed;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_ii =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_gi;

  /* InitializeConditions for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_f =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_pm;

  /* InitializeConditions for S-Function (sdspunwrap2): '<S147>/Unwrap' */
  sel751test_model_1_3_ss_relays_DW.Unwrap_FirstStep_b = TRUE;
  sel751test_model_1_3_ss_relays_DW.Unwrap_Cumsum_b = 0.0;

  /* InitializeConditions for Memory: '<S149>/Memory' */
  sel751test_model_1_3_ss_relays_DW.Memory_PreviousInput_h =
    sel751test_model_1_3_ss_relays_P.Memory_X0_l;

  /* InitializeConditions for MATLAB Function: '<S6>/trip_out mng' */
  sel751test_mod_trip_outmng_Init
    (&sel751test_model_1_3_ss_relays_DW.sf_trip_outmng_a);

  /* InitializeConditions for Memory: '<S6>/Memory2' */
  sel751test_model_1_3_ss_relays_DW.Memory2_PreviousInput_j =
    sel751test_model_1_3_ss_relays_P.Memory2_X0_l;

  /* InitializeConditions for Memory: '<S6>/Memory9' */
  sel751test_model_1_3_ss_relays_DW.Memory9_PreviousInput_i =
    sel751test_model_1_3_ss_relays_P.Memory9_X0_g;

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_pp =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_mh;

  /* InitializeConditions for UnitDelay: '<S172>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_l0 =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_ew;

  /* InitializeConditions for DiscreteIntegrator: '<S160>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTAT_pw =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_f;

  /* InitializeConditions for UnitDelay: '<S171>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_h =
    sel751test_model_1_3_ss_relays_P.UD_InitialCondition_o;

  /* InitializeConditions for UnitDelay: '<S161>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_gp =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_c0;

  /* InitializeConditions for DiscreteStateSpace: '<S158>/Discrete State-Space' */
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_h[0] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_e[0];
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_h[1] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_e[1];

  /* InitializeConditions for DiscreteIntegrator: '<S178>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_DSTATE_ei =
    sel751test_model_1_3_ss_relays_P.Integ4_IC_o5;

  /* InitializeConditions for UnitDelay: '<S188>/Unit Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_lo =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_n;

  /* InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */
  sel751test_model_1_3_ss_relays_DW.DiscreteTimeIntegrator_DSTATE_c =
    sel751test_model_1_3_ss_relays_P.DiscreteTimeIntegrator_IC_d;

  /* InitializeConditions for UnitDelay: '<S187>/UD' */
  sel751test_model_1_3_ss_relays_DW.UD_DSTATE_i =
    sel751test_model_1_3_ss_relays_P.UD_InitialCondition_g;

  /* InitializeConditions for UnitDelay: '<S177>/Unit  Delay' */
  sel751test_model_1_3_ss_relays_DW.UnitDelay_DSTATE_pk =
    sel751test_model_1_3_ss_relays_P.UnitDelay_InitialCondition_kl;

  /* InitializeConditions for DiscreteStateSpace: '<S174>/Discrete State-Space' */
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_m[0] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_g[0];
  sel751test_model_1_3_ss_relays_DW.DiscreteStateSpace_DSTATE_m[1] =
    sel751test_model_1_3_ss_relays_P.DiscreteStateSpace_X0_g[1];

  /* Enable for DiscreteIntegrator: '<S28>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S35>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_o = 1U;

  /* Enable for DiscreteIntegrator: '<S49>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_k = 1U;

  /* Enable for DiscreteIntegrator: '<S51>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_d = 1U;

  /* Enable for DiscreteIntegrator: '<S53>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_b = 1U;

  /* Enable for DiscreteIntegrator: '<S63>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_e = 1U;

  /* Enable for DiscreteIntegrator: '<S71>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_eh = 1U;

  /* Enable for DiscreteIntegrator: '<S87>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_od = 1U;

  /* Enable for DiscreteIntegrator: '<S119>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_l = 1U;

  /* Enable for DiscreteIntegrator: '<S126>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_c = 1U;

  /* Enable for DiscreteIntegrator: '<S140>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_lg = 1U;

  /* Enable for DiscreteIntegrator: '<S142>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_f = 1U;

  /* Enable for DiscreteIntegrator: '<S144>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_fs = 1U;

  /* Enable for DiscreteIntegrator: '<S154>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_h = 1U;

  /* Enable for DiscreteIntegrator: '<S162>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_bf = 1U;

  /* Enable for DiscreteIntegrator: '<S178>/Integ4' */
  sel751test_model_1_3_ss_relays_DW.Integ4_SYSTEM_ENABLE_os = 1U;
}

/* Model terminate function */
void sel751test_model_1_3_ss_relays_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<S8>/Subsystem2' */

  /* Level2 S-Function Block: '<S198>/S-Function' (send_rt) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S8>/Subsystem2' */

  /* Level2 S-Function Block: '<S197>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S199>/S-Function' (recv_rt) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* S-Function block: <S31>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S38>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S50>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* Level2 S-Function Block: '<S192>/S-Function' (RECV_Param) */
  {
    SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* S-Function block: <S52>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S54>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S64>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S82>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* Terminate for Enabled SubSystem: '<S65>/Automatic Gain Control' */

  /* S-Function block: <S77>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S79>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* End of Terminate for SubSystem: '<S65>/Automatic Gain Control' */

  /* S-Function block: <S98>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* Terminate for Enabled SubSystem: '<S66>/Automatic Gain Control' */

  /* S-Function block: <S93>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S95>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* End of Terminate for SubSystem: '<S66>/Automatic Gain Control' */

  /* S-Function block: <S122>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S129>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S141>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S143>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S145>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S155>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S173>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* Terminate for Enabled SubSystem: '<S156>/Automatic Gain Control' */

  /* S-Function block: <S168>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S170>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* End of Terminate for SubSystem: '<S156>/Automatic Gain Control' */

  /* S-Function block: <S189>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* Terminate for Enabled SubSystem: '<S157>/Automatic Gain Control' */

  /* S-Function block: <S184>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* S-Function block: <S186>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* End of Terminate for SubSystem: '<S157>/Automatic Gain Control' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  sel751test_model_1_3_ss_relays_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  sel751test_model_1_3_ss_relays_update();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  sel751test_model_1_3_ss_relays_initialize();
}

void MdlTerminate(void)
{
  sel751test_model_1_3_ss_relays_terminate();
}

/* Registration function */
RT_MODEL_sel751test_model_1_3_ss_relays_T *sel751test_model_1_3_ss_relays(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sel751test_model_1_3_ss_relays_M, 0,
                sizeof(RT_MODEL_sel751test_model_1_3_ss_relays_T));
  rtsiSetSolverName(&sel751test_model_1_3_ss_relays_M->solverInfo,
                    "FixedStepDiscrete");
  sel751test_model_1_3_ss_relays_M->solverInfoPtr =
    (&sel751test_model_1_3_ss_relays_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      sel751test_model_1_3_ss_relays_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    sel751test_model_1_3_ss_relays_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    sel751test_model_1_3_ss_relays_M->Timing.sampleTimes =
      (&sel751test_model_1_3_ss_relays_M->Timing.sampleTimesArray[0]);
    sel751test_model_1_3_ss_relays_M->Timing.offsetTimes =
      (&sel751test_model_1_3_ss_relays_M->Timing.offsetTimesArray[0]);

    /* task periods */
    sel751test_model_1_3_ss_relays_M->Timing.sampleTimes[0] = (0.0001);

    /* task offsets */
    sel751test_model_1_3_ss_relays_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(sel751test_model_1_3_ss_relays_M,
             &sel751test_model_1_3_ss_relays_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      sel751test_model_1_3_ss_relays_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    sel751test_model_1_3_ss_relays_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(sel751test_model_1_3_ss_relays_M, 100.0);
  sel751test_model_1_3_ss_relays_M->Timing.stepSize0 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    sel751test_model_1_3_ss_relays_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(sel751test_model_1_3_ss_relays_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(sel751test_model_1_3_ss_relays_M->rtwLogInfo, (NULL));
    rtliSetLogT(sel751test_model_1_3_ss_relays_M->rtwLogInfo, "");
    rtliSetLogX(sel751test_model_1_3_ss_relays_M->rtwLogInfo, "");
    rtliSetLogXFinal(sel751test_model_1_3_ss_relays_M->rtwLogInfo, "");
    rtliSetSigLog(sel751test_model_1_3_ss_relays_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(sel751test_model_1_3_ss_relays_M->rtwLogInfo,
      "rt_");
    rtliSetLogFormat(sel751test_model_1_3_ss_relays_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(sel751test_model_1_3_ss_relays_M->rtwLogInfo, 0);
    rtliSetLogDecimation(sel751test_model_1_3_ss_relays_M->rtwLogInfo, 1);
    rtliSetLogY(sel751test_model_1_3_ss_relays_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(sel751test_model_1_3_ss_relays_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(sel751test_model_1_3_ss_relays_M->rtwLogInfo, (NULL));
  }

  sel751test_model_1_3_ss_relays_M->solverInfoPtr =
    (&sel751test_model_1_3_ss_relays_M->solverInfo);
  sel751test_model_1_3_ss_relays_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&sel751test_model_1_3_ss_relays_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&sel751test_model_1_3_ss_relays_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  sel751test_model_1_3_ss_relays_M->ModelData.blockIO = ((void *)
    &sel751test_model_1_3_ss_relays_B);
  (void) memset(((void *) &sel751test_model_1_3_ss_relays_B), 0,
                sizeof(B_sel751test_model_1_3_ss_relays_T));

  /* parameters */
  sel751test_model_1_3_ss_relays_M->ModelData.defaultParam = ((real_T *)
    &sel751test_model_1_3_ss_relays_P);

  /* states (dwork) */
  sel751test_model_1_3_ss_relays_M->ModelData.dwork = ((void *)
    &sel751test_model_1_3_ss_relays_DW);
  (void) memset((void *)&sel751test_model_1_3_ss_relays_DW, 0,
                sizeof(DW_sel751test_model_1_3_ss_relays_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.sfcnInfo;
    sel751test_model_1_3_ss_relays_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (sel751test_model_1_3_ss_relays_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &sel751test_model_1_3_ss_relays_M->Sizes.numSampTimes);
    sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(sel751test_model_1_3_ss_relays_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,
                   sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(sel751test_model_1_3_ss_relays_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(sel751test_model_1_3_ss_relays_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (sel751test_model_1_3_ss_relays_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &sel751test_model_1_3_ss_relays_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (sel751test_model_1_3_ss_relays_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &sel751test_model_1_3_ss_relays_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &sel751test_model_1_3_ss_relays_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &sel751test_model_1_3_ss_relays_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &sel751test_model_1_3_ss_relays_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &sel751test_model_1_3_ss_relays_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &sel751test_model_1_3_ss_relays_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &sel751test_model_1_3_ss_relays_M->solverInfoPtr);
  }

  sel751test_model_1_3_ss_relays_M->Sizes.numSFcns = (4);

  /* register each child */
  {
    (void) memset((void *)
                  &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  4*sizeof(SimStruct));
    sel751test_model_1_3_ss_relays_M->childSfunctions =
      (&sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    sel751test_model_1_3_ss_relays_M->childSfunctions[0] =
      (&sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.childSFunctions[0]);
    sel751test_model_1_3_ss_relays_M->childSfunctions[1] =
      (&sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.childSFunctions[1]);
    sel751test_model_1_3_ss_relays_M->childSfunctions[2] =
      (&sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.childSFunctions[2]);
    sel751test_model_1_3_ss_relays_M->childSfunctions[3] =
      (&sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.childSFunctions[3]);

    /* Level2 S-Function Block: sel751test_model_1_3_ss_relays/<S198>/S-Function (send_rt) */
    {
      SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      ssSetRTWSfcnInfo(rts, sel751test_model_1_3_ss_relays_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.statesInfo2
                         [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &sel751test_model_1_3_ss_relays_M->
          NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &sel751test_model_1_3_ss_relays_B.op_mode;
          sfcnUPtrs[1] = &sel751test_model_1_3_ss_relays_B.Logic_trip;
          sfcnUPtrs[2] = &sel751test_model_1_3_ss_relays_B.Iabc[0];
          sfcnUPtrs[3] = &sel751test_model_1_3_ss_relays_B.Iabc[1];
          sfcnUPtrs[4] = &sel751test_model_1_3_ss_relays_B.Iabc[2];
          sfcnUPtrs[5] = &sel751test_model_1_3_ss_relays_B.Vabc[0];
          sfcnUPtrs[6] = &sel751test_model_1_3_ss_relays_B.Vabc[1];
          sfcnUPtrs[7] = &sel751test_model_1_3_ss_relays_B.Vabc[2];
          sfcnUPtrs[8] = &sel751test_model_1_3_ss_relays_B.P;
          sfcnUPtrs[9] = &sel751test_model_1_3_ss_relays_B.Q;
          sfcnUPtrs[10] = &sel751test_model_1_3_ss_relays_B.freq;
          sfcnUPtrs[11] = &sel751test_model_1_3_ss_relays_B.Va_rms;
          sfcnUPtrs[12] = &sel751test_model_1_3_ss_relays_B.pf;
          sfcnUPtrs[13] = &sel751test_model_1_3_ss_relays_B.Vpu;
          sfcnUPtrs[14] = &sel751test_model_1_3_ss_relays_B.status;
          sfcnUPtrs[15] = &sel751test_model_1_3_ss_relays_B.pf_states;
          sfcnUPtrs[16] = &sel751test_model_1_3_ss_relays_B.op_mode_d;
          sfcnUPtrs[17] = &sel751test_model_1_3_ss_relays_B.Logic_trip_h;
          sfcnUPtrs[18] = &sel751test_model_1_3_ss_relays_B.Iabc_b[0];
          sfcnUPtrs[19] = &sel751test_model_1_3_ss_relays_B.Iabc_b[1];
          sfcnUPtrs[20] = &sel751test_model_1_3_ss_relays_B.Iabc_b[2];
          sfcnUPtrs[21] = &sel751test_model_1_3_ss_relays_B.Vabc_n[0];
          sfcnUPtrs[22] = &sel751test_model_1_3_ss_relays_B.Vabc_n[1];
          sfcnUPtrs[23] = &sel751test_model_1_3_ss_relays_B.Vabc_n[2];
          sfcnUPtrs[24] = &sel751test_model_1_3_ss_relays_B.P_a;
          sfcnUPtrs[25] = &sel751test_model_1_3_ss_relays_B.Q_j;
          sfcnUPtrs[26] = &sel751test_model_1_3_ss_relays_B.freq_m;
          sfcnUPtrs[27] = &sel751test_model_1_3_ss_relays_B.Va_rms_o;
          sfcnUPtrs[28] = &sel751test_model_1_3_ss_relays_B.pf_b;
          sfcnUPtrs[29] = &sel751test_model_1_3_ss_relays_B.Vpu_h;
          sfcnUPtrs[30] = &sel751test_model_1_3_ss_relays_B.status_f;
          sfcnUPtrs[31] = &sel751test_model_1_3_ss_relays_B.pf_states_i;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 32);
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "sel751test_model_1_3_ss_relays/SS_Relays/rtlab_send_subsystem/Subsystem2/Send2/S-Function");
      ssSetRTModel(rts,sel751test_model_1_3_ss_relays_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       sel751test_model_1_3_ss_relays_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       sel751test_model_1_3_ss_relays_P.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       sel751test_model_1_3_ss_relays_P.SFunction_P3_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_g[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &sel751test_model_1_3_ss_relays_DW.SFunction_IWORK_g
                   [0]);
      }

      /* registration */
      send_rt(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 32);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: sel751test_model_1_3_ss_relays/<S197>/S-Function (OP_SEND) */
    {
      SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      ssSetRTWSfcnInfo(rts, sel751test_model_1_3_ss_relays_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.statesInfo2
                         [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &sel751test_model_1_3_ss_relays_M->
          NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &sel751test_model_1_3_ss_relays_B.op_mode;
          sfcnUPtrs[1] = &sel751test_model_1_3_ss_relays_B.Logic_trip;
          sfcnUPtrs[2] = &sel751test_model_1_3_ss_relays_B.Iabc[0];
          sfcnUPtrs[3] = &sel751test_model_1_3_ss_relays_B.Iabc[1];
          sfcnUPtrs[4] = &sel751test_model_1_3_ss_relays_B.Iabc[2];
          sfcnUPtrs[5] = &sel751test_model_1_3_ss_relays_B.Vabc[0];
          sfcnUPtrs[6] = &sel751test_model_1_3_ss_relays_B.Vabc[1];
          sfcnUPtrs[7] = &sel751test_model_1_3_ss_relays_B.Vabc[2];
          sfcnUPtrs[8] = &sel751test_model_1_3_ss_relays_B.P;
          sfcnUPtrs[9] = &sel751test_model_1_3_ss_relays_B.Q;
          sfcnUPtrs[10] = &sel751test_model_1_3_ss_relays_B.freq;
          sfcnUPtrs[11] = &sel751test_model_1_3_ss_relays_B.Va_rms;
          sfcnUPtrs[12] = &sel751test_model_1_3_ss_relays_B.pf;
          sfcnUPtrs[13] = &sel751test_model_1_3_ss_relays_B.Vpu;
          sfcnUPtrs[14] = &sel751test_model_1_3_ss_relays_B.status;
          sfcnUPtrs[15] = &sel751test_model_1_3_ss_relays_B.pf_states;
          sfcnUPtrs[16] = &sel751test_model_1_3_ss_relays_B.op_mode_d;
          sfcnUPtrs[17] = &sel751test_model_1_3_ss_relays_B.Logic_trip_h;
          sfcnUPtrs[18] = &sel751test_model_1_3_ss_relays_B.Iabc_b[0];
          sfcnUPtrs[19] = &sel751test_model_1_3_ss_relays_B.Iabc_b[1];
          sfcnUPtrs[20] = &sel751test_model_1_3_ss_relays_B.Iabc_b[2];
          sfcnUPtrs[21] = &sel751test_model_1_3_ss_relays_B.Vabc_n[0];
          sfcnUPtrs[22] = &sel751test_model_1_3_ss_relays_B.Vabc_n[1];
          sfcnUPtrs[23] = &sel751test_model_1_3_ss_relays_B.Vabc_n[2];
          sfcnUPtrs[24] = &sel751test_model_1_3_ss_relays_B.P_a;
          sfcnUPtrs[25] = &sel751test_model_1_3_ss_relays_B.Q_j;
          sfcnUPtrs[26] = &sel751test_model_1_3_ss_relays_B.freq_m;
          sfcnUPtrs[27] = &sel751test_model_1_3_ss_relays_B.Va_rms_o;
          sfcnUPtrs[28] = &sel751test_model_1_3_ss_relays_B.pf_b;
          sfcnUPtrs[29] = &sel751test_model_1_3_ss_relays_B.Vpu_h;
          sfcnUPtrs[30] = &sel751test_model_1_3_ss_relays_B.status_f;
          sfcnUPtrs[31] = &sel751test_model_1_3_ss_relays_B.pf_states_i;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 32);
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "sel751test_model_1_3_ss_relays/SS_Relays/rtlab_send_subsystem/Subsystem1/Send1/S-Function");
      ssSetRTModel(rts,sel751test_model_1_3_ss_relays_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       sel751test_model_1_3_ss_relays_P.SFunction_P1_Size_g);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &sel751test_model_1_3_ss_relays_DW.SFunction_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &sel751test_model_1_3_ss_relays_DW.SFunction_IWORK[0]);
      }

      /* registration */
      OP_SEND(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 32);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: sel751test_model_1_3_ss_relays/<S199>/S-Function (recv_rt) */
    {
      SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      ssSetRTWSfcnInfo(rts, sel751test_model_1_3_ss_relays_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.statesInfo2
                         [2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn2.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 23);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            sel751test_model_1_3_ss_relays_B.SFunction_l));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "sel751test_model_1_3_ss_relays/SS_Relays/zzzOpComm/Receive_1/S-Function");
      ssSetRTModel(rts,sel751test_model_1_3_ss_relays_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       sel751test_model_1_3_ss_relays_P.SFunction_P1_Size_p);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       sel751test_model_1_3_ss_relays_P.SFunction_P2_Size_c);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       sel751test_model_1_3_ss_relays_P.SFunction_P3_Size_g);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &sel751test_model_1_3_ss_relays_DW.SFunction_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &sel751test_model_1_3_ss_relays_DW.SFunction_PWORK);
      }

      /* registration */
      recv_rt(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: sel751test_model_1_3_ss_relays/<S192>/S-Function (RECV_Param) */
    {
      SimStruct *rts = sel751test_model_1_3_ss_relays_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      ssSetRTWSfcnInfo(rts, sel751test_model_1_3_ss_relays_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.methods3
                           [3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.statesInfo2
                         [3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn3.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 6);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            sel751test_model_1_3_ss_relays_B.SFunction_o));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "sel751test_model_1_3_ss_relays/SS_Relays/OpComm1/Receive/S-Function");
      ssSetRTModel(rts,sel751test_model_1_3_ss_relays_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &sel751test_model_1_3_ss_relays_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       sel751test_model_1_3_ss_relays_P.SFunction_P1_Size_c);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       sel751test_model_1_3_ss_relays_P.SFunction_P2_Size_i);
      }

      /* registration */
      RECV_Param(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  sel751test_model_1_3_ss_relays_M->Sizes.numContStates = (0);/* Number of continuous states */
  sel751test_model_1_3_ss_relays_M->Sizes.numY = (0);/* Number of model outputs */
  sel751test_model_1_3_ss_relays_M->Sizes.numU = (0);/* Number of model inputs */
  sel751test_model_1_3_ss_relays_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  sel751test_model_1_3_ss_relays_M->Sizes.numSampTimes = (1);/* Number of sample times */
  sel751test_model_1_3_ss_relays_M->Sizes.numBlocks = (1056);/* Number of blocks */
  sel751test_model_1_3_ss_relays_M->Sizes.numBlockIO = (896);/* Number of block outputs */
  sel751test_model_1_3_ss_relays_M->Sizes.numBlockPrms = (852);/* Sum of parameter "widths" */
  return sel751test_model_1_3_ss_relays_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
