/* Include files */

#include <stddef.h>
#include "blas.h"
#include "relay_ANSI_functions_lib_sfun.h"
#include "c1_relay_ANSI_functions_lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "relay_ANSI_functions_lib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[25] = { "T50", "T51", "r", "nargin",
  "nargout", "Ts", "Reset", "Iinst", "Irms", "Vrms", "VRMSLL", "CT_p",
  "IOC_pickup", "IOC_tripDelay", "TOC_pickup", "curveType", "timeDial", "trip50",
  "trip51", "trip27", "trip59", "R50", "R51", "R27", "R59" };

static const char * c1_b_debug_family_names[12] = { "t50", "CT_tap", "Ipu",
  "bool_50", "nargin", "nargout", "Ts", "Iinst", "IOC_pickup", "IOC_timeDelay",
  "trip50", "n50" };

static const char * c1_c_debug_family_names[8] = { "nargin", "nargout", "TD",
  "M", "A", "B", "P", "t" };

static const char * c1_d_debug_family_names[6] = { "nargin", "nargout", "TD",
  "M", "tcc_type", "t" };

static const char * c1_e_debug_family_names[15] = { "CT_tap", "Ipu", "M", "y",
  "t51", "bool_51", "nargin", "nargout", "Ts", "Irms", "TOC_pickup", "curveType",
  "timeDial", "trip51", "n51" };

static const char * c1_f_debug_family_names[17] = { "additional_time_delay",
  "TUV", "TOV", "u", "y", "t27", "t59", "bool_27", "bool_59", "nargin",
  "nargout", "Ts", "Vrms", "VRMSLL", "r", "n27", "n59" };

/* Function Declarations */
static void initialize_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static void initialize_params_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static void enable_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static void disable_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static void set_sim_state_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static void sf_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static void initSimStructsc1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static void registerMessagesc1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance);
static boolean_T c1_relay_ANSI_51P_script
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, real_T c1_Ts,
   real_T c1_Irms[3], real_T c1_TOC_pickup, real_T c1_curveType, real_T
   c1_timeDial);
static void c1_op_time_US_TCC_eq(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, real_T c1_TD, real_T c1_M[3], real_T c1_A, real_T c1_B, real_T
  c1_P, real_T c1_t[3]);
static c1_s7JLMi156dXwW96IDsWdPSB c1_relay_ANSI_2759_script
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, real_T c1_Ts,
   real_T c1_Vrms[3], real_T c1_VRMSLL);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static boolean_T c1_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_b_R59, const char_T *c1_identifier);
static boolean_T c1_b_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_b_R27, const char_T *c1_identifier);
static boolean_T c1_d_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_e_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_b_R51, const char_T *c1_identifier);
static boolean_T c1_f_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_g_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_b_R50, const char_T *c1_identifier);
static boolean_T c1_h_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_i_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_trip59, const char_T *c1_identifier);
static boolean_T c1_j_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_k_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static c1_s7JLMi156dXwW96IDsWdPSB c1_l_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_m_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_b_n50, const char_T *c1_identifier);
static real_T c1_n_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_o_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_p_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_b_n51, const char_T *c1_identifier);
static real_T c1_q_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_r_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_b_n59, const char_T *c1_identifier);
static real_T c1_s_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_t_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_b_n27, const char_T *c1_identifier);
static real_T c1_u_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_v_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6]);
static void c1_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[53]);
static real_T c1_sum(SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance,
                     boolean_T c1_x[3]);
static void c1_rdivide(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, real_T c1_x[3], real_T c1_y, real_T c1_z[3]);
static void c1_eml_error(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance);
static void c1_eml_scalar_eg(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance);
static void c1_check_forloop_overflow_error
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, boolean_T
   c1_overflow);
static void c1_power(SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance,
                     real_T c1_a[6], real_T c1_y[6]);
static void c1_b_rdivide(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, real_T c1_x, real_T c1_y[6], real_T c1_z[6]);
static void c1_c_rdivide(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, real_T c1_x[6], real_T c1_y[6], real_T c1_z[6]);
static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_w_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_x_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_relay_ANSI_functions_lib,
  const char_T *c1_identifier);
static uint8_T c1_y_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_R50_not_empty = FALSE;
  chartInstance->c1_R51_not_empty = FALSE;
  chartInstance->c1_R27_not_empty = FALSE;
  chartInstance->c1_R59_not_empty = FALSE;
  chartInstance->c1_n50_not_empty = FALSE;
  chartInstance->c1_n51_not_empty = FALSE;
  chartInstance->c1_n27_not_empty = FALSE;
  chartInstance->c1_n59_not_empty = FALSE;
  chartInstance->c1_is_active_c1_relay_ANSI_functions_lib = 0U;
}

static void initialize_params_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
}

static void enable_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  boolean_T c1_hoistedGlobal;
  boolean_T c1_u;
  const mxArray *c1_b_y = NULL;
  boolean_T c1_b_hoistedGlobal;
  boolean_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  boolean_T c1_c_hoistedGlobal;
  boolean_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  boolean_T c1_d_hoistedGlobal;
  boolean_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  boolean_T c1_e_hoistedGlobal;
  boolean_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  boolean_T c1_f_hoistedGlobal;
  boolean_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  boolean_T c1_g_hoistedGlobal;
  boolean_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  boolean_T c1_h_hoistedGlobal;
  boolean_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_j_hoistedGlobal;
  real_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_k_hoistedGlobal;
  real_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_l_hoistedGlobal;
  real_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  uint8_T c1_m_hoistedGlobal;
  uint8_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  boolean_T *c1_trip27;
  boolean_T *c1_trip50;
  boolean_T *c1_trip51;
  boolean_T *c1_trip59;
  c1_trip59 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_trip27 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_trip51 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_trip50 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(13), FALSE);
  c1_hoistedGlobal = *c1_trip27;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_trip50;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_trip51;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_trip59;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = chartInstance->c1_R27;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  if (!chartInstance->c1_R27_not_empty) {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 11, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_R50;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  if (!chartInstance->c1_R50_not_empty) {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 11, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = chartInstance->c1_R51;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  if (!chartInstance->c1_R51_not_empty) {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 11, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = chartInstance->c1_R59;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  if (!chartInstance->c1_R59_not_empty) {
    sf_mex_assign(&c1_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 11, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = chartInstance->c1_n27;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  if (!chartInstance->c1_n27_not_empty) {
    sf_mex_assign(&c1_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = chartInstance->c1_n50;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  if (!chartInstance->c1_n50_not_empty) {
    sf_mex_assign(&c1_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 9, c1_k_y);
  c1_k_hoistedGlobal = chartInstance->c1_n51;
  c1_k_u = c1_k_hoistedGlobal;
  c1_l_y = NULL;
  if (!chartInstance->c1_n51_not_empty) {
    sf_mex_assign(&c1_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 10, c1_l_y);
  c1_l_hoistedGlobal = chartInstance->c1_n59;
  c1_l_u = c1_l_hoistedGlobal;
  c1_m_y = NULL;
  if (!chartInstance->c1_n59_not_empty) {
    sf_mex_assign(&c1_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 11, c1_m_y);
  c1_m_hoistedGlobal = chartInstance->c1_is_active_c1_relay_ANSI_functions_lib;
  c1_m_u = c1_m_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 12, c1_n_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_trip27;
  boolean_T *c1_trip50;
  boolean_T *c1_trip51;
  boolean_T *c1_trip59;
  c1_trip59 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_trip27 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_trip51 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_trip50 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_trip27 = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "trip27");
  *c1_trip50 = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "trip50");
  *c1_trip51 = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 2)), "trip51");
  *c1_trip59 = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "trip59");
  chartInstance->c1_R27 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 4)), "R27");
  chartInstance->c1_R50 = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 5)), "R50");
  chartInstance->c1_R51 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 6)), "R51");
  chartInstance->c1_R59 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 7)), "R59");
  chartInstance->c1_n27 = c1_t_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 8)), "n27");
  chartInstance->c1_n50 = c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 9)), "n50");
  chartInstance->c1_n51 = c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 10)), "n51");
  chartInstance->c1_n59 = c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 11)), "n59");
  chartInstance->c1_is_active_c1_relay_ANSI_functions_lib =
    c1_x_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 12)),
    "is_active_c1_relay_ANSI_functions_lib");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_relay_ANSI_functions_lib(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
}

static void sf_c1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_g_hoistedGlobal;
  real_T c1_h_hoistedGlobal;
  real_T c1_i_hoistedGlobal;
  real_T c1_Ts;
  real_T c1_Reset;
  int32_T c1_i3;
  real_T c1_Iinst[3];
  int32_T c1_i4;
  real_T c1_Irms[3];
  int32_T c1_i5;
  real_T c1_Vrms[3];
  real_T c1_VRMSLL;
  real_T c1_CT_p;
  real_T c1_IOC_pickup;
  real_T c1_IOC_tripDelay;
  real_T c1_TOC_pickup;
  real_T c1_curveType;
  real_T c1_timeDial;
  uint32_T c1_debug_family_var_map[25];
  boolean_T c1_T50;
  boolean_T c1_T51;
  c1_s7JLMi156dXwW96IDsWdPSB c1_r;
  real_T c1_nargin = 12.0;
  real_T c1_nargout = 4.0;
  boolean_T c1_trip50;
  boolean_T c1_trip51;
  boolean_T c1_trip27;
  boolean_T c1_trip59;
  real_T c1_B;
  real_T c1_y;
  real_T c1_b_y;
  real_T c1_c_y;
  int32_T c1_i6;
  real_T c1_a[3];
  real_T c1_b;
  int32_T c1_i7;
  real_T c1_b_B;
  real_T c1_d_y;
  real_T c1_e_y;
  real_T c1_f_y;
  int32_T c1_i8;
  real_T c1_b_b;
  int32_T c1_i9;
  boolean_T c1_b0;
  real_T c1_b_Ts;
  int32_T c1_i10;
  real_T c1_b_Iinst[3];
  real_T c1_b_IOC_pickup;
  real_T c1_IOC_timeDelay;
  uint32_T c1_b_debug_family_var_map[12];
  real_T c1_t50;
  real_T c1_CT_tap;
  real_T c1_Ipu;
  boolean_T c1_bool_50;
  real_T c1_b_nargin = 4.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_b_a;
  real_T c1_g_y;
  real_T c1_c_a;
  real_T c1_h_y;
  real_T c1_d_a;
  int32_T c1_i11;
  boolean_T c1_c_Iinst[3];
  int32_T c1_i12;
  real_T c1_b_Irms[3];
  int32_T c1_i13;
  real_T c1_b_Vrms[3];
  boolean_T *c1_b_trip59;
  boolean_T *c1_b_trip27;
  boolean_T *c1_b_trip51;
  boolean_T *c1_b_trip50;
  real_T *c1_b_timeDial;
  real_T *c1_b_curveType;
  real_T *c1_b_TOC_pickup;
  real_T *c1_b_IOC_tripDelay;
  real_T *c1_c_IOC_pickup;
  real_T *c1_b_CT_p;
  real_T *c1_b_VRMSLL;
  real_T *c1_b_Reset;
  real_T *c1_c_Ts;
  real_T (*c1_c_Vrms)[3];
  real_T (*c1_c_Irms)[3];
  real_T (*c1_d_Iinst)[3];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c1_b_timeDial = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c1_b_curveType = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c1_b_TOC_pickup = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c1_b_IOC_tripDelay = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c1_b_trip59 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_c_IOC_pickup = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c1_b_trip27 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_trip51 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_CT_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_VRMSLL = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_c_Vrms = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c1_c_Irms = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c1_d_Iinst = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_Reset = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_trip50 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_c_Ts = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_c_Ts, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_trip50, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Reset, 2U);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_d_Iinst)[c1_i0], 3U);
  }

  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((*c1_c_Irms)[c1_i1], 4U);
  }

  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_c_Vrms)[c1_i2], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_VRMSLL, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_b_CT_p, 7U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_trip51, 8U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_trip27, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_c_IOC_pickup, 10U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_b_trip59, 11U);
  _SFD_DATA_RANGE_CHECK(*c1_b_IOC_tripDelay, 12U);
  _SFD_DATA_RANGE_CHECK(*c1_b_TOC_pickup, 13U);
  _SFD_DATA_RANGE_CHECK(*c1_b_curveType, 14U);
  _SFD_DATA_RANGE_CHECK(*c1_b_timeDial, 15U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_c_Ts;
  c1_b_hoistedGlobal = *c1_b_Reset;
  c1_c_hoistedGlobal = *c1_b_VRMSLL;
  c1_d_hoistedGlobal = *c1_b_CT_p;
  c1_e_hoistedGlobal = *c1_c_IOC_pickup;
  c1_f_hoistedGlobal = *c1_b_IOC_tripDelay;
  c1_g_hoistedGlobal = *c1_b_TOC_pickup;
  c1_h_hoistedGlobal = *c1_b_curveType;
  c1_i_hoistedGlobal = *c1_b_timeDial;
  c1_Ts = c1_hoistedGlobal;
  c1_Reset = c1_b_hoistedGlobal;
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    c1_Iinst[c1_i3] = (*c1_d_Iinst)[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    c1_Irms[c1_i4] = (*c1_c_Irms)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_Vrms[c1_i5] = (*c1_c_Vrms)[c1_i5];
  }

  c1_VRMSLL = c1_c_hoistedGlobal;
  c1_CT_p = c1_d_hoistedGlobal;
  c1_IOC_pickup = c1_e_hoistedGlobal;
  c1_IOC_tripDelay = c1_f_hoistedGlobal;
  c1_TOC_pickup = c1_g_hoistedGlobal;
  c1_curveType = c1_h_hoistedGlobal;
  c1_timeDial = c1_i_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 25U, 25U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_T50, 0U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_T51, 1U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_r, 2U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 3U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 4U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_Ts, 5U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_Reset, 6U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Iinst, 7U, c1_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Irms, 8U, c1_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Vrms, 9U, c1_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_VRMSLL, 10U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_CT_p, 11U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_IOC_pickup, 12U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_IOC_tripDelay, 13U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_TOC_pickup, 14U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_curveType, 15U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_timeDial, 16U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_trip50, 17U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_trip51, 18U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_trip27, 19U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_trip59, 20U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_R50, 21U,
    c1_d_sf_marshallOut, c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_R51, 22U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_R27, 23U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_R59, 24U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  guard2 = FALSE;
  if (CV_EML_COND(0, 1, 0, !chartInstance->c1_R51_not_empty)) {
    guard2 = TRUE;
  } else if (CV_EML_COND(0, 1, 1, c1_Reset != 0.0) != 0.0) {
    guard2 = TRUE;
  } else {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
  }

  if (guard2 == TRUE) {
    CV_EML_MCDC(0, 1, 0, TRUE);
    CV_EML_IF(0, 1, 0, TRUE);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
    chartInstance->c1_R50 = FALSE;
    chartInstance->c1_R50_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
    chartInstance->c1_R51 = FALSE;
    chartInstance->c1_R51_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
    chartInstance->c1_R59 = FALSE;
    chartInstance->c1_R59_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
    chartInstance->c1_R27 = FALSE;
    chartInstance->c1_R27_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_B = c1_CT_p;
  c1_y = c1_B;
  c1_b_y = c1_y;
  c1_c_y = 5.0 / c1_b_y;
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_a[c1_i6] = c1_Iinst[c1_i6];
  }

  c1_b = c1_c_y;
  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    c1_Iinst[c1_i7] = c1_a[c1_i7] * c1_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_b_B = c1_CT_p;
  c1_d_y = c1_b_B;
  c1_e_y = c1_d_y;
  c1_f_y = 5.0 / c1_e_y;
  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_a[c1_i8] = c1_Irms[c1_i8];
  }

  c1_b_b = c1_f_y;
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_Irms[c1_i9] = c1_a[c1_i9] * c1_b_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 2, chartInstance->c1_R50)) {
    guard1 = TRUE;
  } else if (CV_EML_COND(0, 1, 3, chartInstance->c1_R51)) {
    guard1 = TRUE;
  } else {
    c1_b0 = FALSE;
  }

  if (guard1 == TRUE) {
    c1_b0 = TRUE;
  }

  if (CV_EML_IF(0, 1, 1, CV_EML_MCDC(0, 1, 1, !c1_b0))) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
    c1_b_Ts = c1_Ts;
    for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
      c1_b_Iinst[c1_i10] = c1_Iinst[c1_i10];
    }

    c1_b_IOC_pickup = c1_IOC_pickup;
    c1_IOC_timeDelay = c1_IOC_tripDelay;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c1_b_debug_family_names,
      c1_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_t50, 0U, c1_f_sf_marshallOut,
      c1_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML(&c1_CT_tap, 1U, c1_f_sf_marshallOut);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Ipu, 2U, c1_f_sf_marshallOut,
      c1_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bool_50, 3U, c1_e_sf_marshallOut,
      c1_e_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 4U, c1_f_sf_marshallOut,
      c1_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 5U, c1_f_sf_marshallOut,
      c1_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_Ts, 6U, c1_f_sf_marshallOut,
      c1_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_Iinst, 7U, c1_g_sf_marshallOut,
      c1_i_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_IOC_pickup, 8U,
      c1_f_sf_marshallOut, c1_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_IOC_timeDelay, 9U,
      c1_f_sf_marshallOut, c1_f_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_T50, 10U, c1_e_sf_marshallOut,
      c1_e_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_n50, 11U,
      c1_i_sf_marshallOut, c1_h_sf_marshallIn);
    CV_SCRIPT_FCN(0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 12);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 13);
    if (CV_SCRIPT_IF(0, 0, !chartInstance->c1_n50_not_empty)) {
      _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 14);
      chartInstance->c1_n50 = 0.0;
      chartInstance->c1_n50_not_empty = TRUE;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 18);
    c1_t50 = 0.0041666666666666666 + c1_IOC_timeDelay;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 20);
    c1_CT_tap = 1.0;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 23);
    c1_b_a = c1_b_IOC_pickup;
    c1_g_y = c1_b_a * 5.0;
    c1_c_a = c1_g_y;
    c1_h_y = c1_c_a;
    c1_d_a = c1_h_y;
    c1_Ipu = c1_d_a * 1.4142135623730951;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 25);
    for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
      c1_c_Iinst[c1_i11] = (c1_b_Iinst[c1_i11] > c1_Ipu);
    }

    c1_bool_50 = (c1_sum(chartInstance, c1_c_Iinst) > 0.0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 27);
    chartInstance->c1_n50 *= (real_T)c1_bool_50;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 29);
    chartInstance->c1_n50 += (real_T)c1_bool_50 * c1_b_Ts;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 31);
    c1_T50 = (chartInstance->c1_n50 > c1_t50);
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -31);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
    for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
      c1_b_Irms[c1_i12] = c1_Irms[c1_i12];
    }

    c1_T51 = c1_relay_ANSI_51P_script(chartInstance, c1_Ts, c1_b_Irms,
      c1_TOC_pickup, c1_curveType, c1_timeDial);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
    for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
      c1_b_Vrms[c1_i13] = c1_Vrms[c1_i13];
    }

    c1_r = c1_relay_ANSI_2759_script(chartInstance, c1_Ts, c1_b_Vrms, c1_VRMSLL);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
    chartInstance->c1_R50 = c1_T50;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
    chartInstance->c1_R51 = c1_T51;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
    chartInstance->c1_R27 = c1_r.trip27;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
    chartInstance->c1_R59 = c1_r.trip59;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
  c1_trip50 = chartInstance->c1_R50;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
  c1_trip51 = chartInstance->c1_R51;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
  c1_trip27 = chartInstance->c1_R27;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
  c1_trip59 = chartInstance->c1_R59;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -40);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_trip50 = c1_trip50;
  *c1_b_trip51 = c1_trip51;
  *c1_b_trip27 = c1_trip27;
  *c1_b_trip59 = c1_trip59;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_relay_ANSI_functions_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_relay_ANSI_functions_lib
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance)
{
}

static boolean_T c1_relay_ANSI_51P_script
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, real_T c1_Ts,
   real_T c1_Irms[3], real_T c1_TOC_pickup, real_T c1_curveType, real_T
   c1_timeDial)
{
  boolean_T c1_trip51;
  uint32_T c1_debug_family_var_map[15];
  real_T c1_CT_tap;
  real_T c1_Ipu;
  real_T c1_M[3];
  real_T c1_y[3];
  real_T c1_t51;
  boolean_T c1_bool_51;
  real_T c1_nargin = 5.0;
  real_T c1_nargout = 1.0;
  real_T c1_a;
  real_T c1_b_y;
  real_T c1_b_a;
  int32_T c1_i14;
  real_T c1_x[3];
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_i15;
  real_T c1_TD;
  int32_T c1_i16;
  real_T c1_b_M[3];
  real_T c1_tcc_type;
  uint32_T c1_b_debug_family_var_map[6];
  real_T c1_b_nargin = 3.0;
  real_T c1_b_nargout = 1.0;
  int32_T c1_i17;
  real_T c1_c_M[3];
  real_T c1_dv0[3];
  int32_T c1_i18;
  int32_T c1_i19;
  real_T c1_d_M[3];
  real_T c1_dv1[3];
  int32_T c1_i20;
  int32_T c1_i21;
  real_T c1_e_M[3];
  real_T c1_dv2[3];
  int32_T c1_i22;
  int32_T c1_i23;
  real_T c1_f_M[3];
  real_T c1_dv3[3];
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_ixstart;
  real_T c1_mtmp;
  real_T c1_b_x;
  boolean_T c1_b;
  int32_T c1_ix;
  int32_T c1_b_ix;
  real_T c1_c_x;
  boolean_T c1_b_b;
  int32_T c1_c_a;
  int32_T c1_i26;
  boolean_T c1_overflow;
  int32_T c1_c_ix;
  real_T c1_d_a;
  real_T c1_c_b;
  boolean_T c1_p;
  real_T c1_b_mtmp;
  int32_T c1_i27;
  boolean_T c1_b_Irms[3];
  boolean_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c1_e_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_CT_tap, 0U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Ipu, 1U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_M, 2U, c1_g_sf_marshallOut,
    c1_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_y, 3U, c1_g_sf_marshallOut,
    c1_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_t51, 4U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bool_51, 5U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 6U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 7U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Ts, 8U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Irms, 9U, c1_g_sf_marshallOut,
    c1_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_TOC_pickup, 10U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_curveType, 11U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_timeDial, 12U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_trip51, 13U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_n51, 14U,
    c1_j_sf_marshallOut, c1_j_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 12);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 13);
  if (CV_SCRIPT_IF(1, 0, !chartInstance->c1_n51_not_empty)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 14);
    chartInstance->c1_n51 = 0.0;
    chartInstance->c1_n51_not_empty = TRUE;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 18);
  c1_CT_tap = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 20);
  c1_a = c1_TOC_pickup;
  c1_b_y = c1_a * 5.0;
  c1_b_a = c1_b_y;
  c1_Ipu = c1_b_a;
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 22);
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    c1_x[c1_i14] = c1_Irms[c1_i14];
  }

  c1_c_y = c1_Ipu;
  c1_d_y = c1_c_y;
  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_M[c1_i15] = c1_x[c1_i15] / c1_d_y;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 23);
  c1_TD = c1_timeDial;
  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_b_M[c1_i16] = c1_M[c1_i16];
  }

  c1_tcc_type = c1_curveType;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c1_d_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_TD, 2U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_M, 3U, c1_g_sf_marshallOut,
    c1_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_tcc_type, 4U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_y, 5U, c1_g_sf_marshallOut,
    c1_i_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 18);
  if (CV_SCRIPT_IF(2, 0, c1_tcc_type == 1.0)) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 20);
    for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
      c1_c_M[c1_i17] = c1_b_M[c1_i17];
    }

    c1_op_time_US_TCC_eq(chartInstance, c1_TD, c1_c_M, 0.0104, 0.0226, 0.02,
                         c1_dv0);
    for (c1_i18 = 0; c1_i18 < 3; c1_i18++) {
      c1_y[c1_i18] = c1_dv0[c1_i18];
    }
  } else {
    _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 21);
    if (CV_SCRIPT_IF(2, 1, c1_tcc_type == 2.0)) {
      _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 23);
      for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
        c1_d_M[c1_i19] = c1_b_M[c1_i19];
      }

      c1_op_time_US_TCC_eq(chartInstance, c1_TD, c1_d_M, 5.95, 0.18, 2.0, c1_dv1);
      for (c1_i20 = 0; c1_i20 < 3; c1_i20++) {
        c1_y[c1_i20] = c1_dv1[c1_i20];
      }
    } else {
      _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 24);
      if (CV_SCRIPT_IF(2, 2, c1_tcc_type == 3.0)) {
        _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 26);
        for (c1_i21 = 0; c1_i21 < 3; c1_i21++) {
          c1_e_M[c1_i21] = c1_b_M[c1_i21];
        }

        c1_op_time_US_TCC_eq(chartInstance, c1_TD, c1_e_M, 3.88, 0.0963, 2.0,
                             c1_dv2);
        for (c1_i22 = 0; c1_i22 < 3; c1_i22++) {
          c1_y[c1_i22] = c1_dv2[c1_i22];
        }
      } else {
        _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 29);
        for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
          c1_f_M[c1_i23] = c1_b_M[c1_i23];
        }

        c1_op_time_US_TCC_eq(chartInstance, c1_TD, c1_f_M, 5.67, 0.0352, 2.0,
                             c1_dv3);
        for (c1_i24 = 0; c1_i24 < 3; c1_i24++) {
          c1_y[c1_i24] = c1_dv3[c1_i24];
        }
      }
    }
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, -29);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 25);
  for (c1_i25 = 0; c1_i25 < 3; c1_i25++) {
    c1_x[c1_i25] = c1_y[c1_i25];
  }

  c1_ixstart = 1;
  c1_mtmp = c1_x[0];
  c1_b_x = c1_mtmp;
  c1_b = muDoubleScalarIsNaN(c1_b_x);
  if (c1_b) {
    c1_ix = 2;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c1_ix < 4)) {
      c1_b_ix = c1_ix;
      c1_ixstart = c1_b_ix;
      c1_c_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
      c1_b_b = muDoubleScalarIsNaN(c1_c_x);
      if (!c1_b_b) {
        c1_mtmp = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
        exitg1 = TRUE;
      } else {
        c1_ix++;
      }
    }
  }

  if (c1_ixstart < 3) {
    c1_c_a = c1_ixstart;
    c1_i26 = c1_c_a;
    c1_overflow = FALSE;
    if (c1_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_overflow);
    }

    for (c1_c_ix = c1_i26 + 1; c1_c_ix < 4; c1_c_ix++) {
      c1_b_ix = c1_c_ix;
      c1_d_a = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
      c1_c_b = c1_mtmp;
      c1_p = (c1_d_a < c1_c_b);
      if (c1_p) {
        c1_mtmp = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
      }
    }
  }

  c1_b_mtmp = c1_mtmp;
  c1_t51 = c1_b_mtmp;
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 27);
  if (CV_SCRIPT_IF(1, 1, c1_t51 < 0.0)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 28);
    c1_t51 = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 32);
  for (c1_i27 = 0; c1_i27 < 3; c1_i27++) {
    c1_b_Irms[c1_i27] = (c1_Irms[c1_i27] > c1_Ipu);
  }

  c1_bool_51 = (c1_sum(chartInstance, c1_b_Irms) > 0.0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 34);
  chartInstance->c1_n51 *= (real_T)c1_bool_51;
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 36);
  chartInstance->c1_n51 += (real_T)c1_bool_51 * c1_Ts;
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 38);
  c1_trip51 = (chartInstance->c1_n51 > c1_t51);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
  return c1_trip51;
}

static void c1_op_time_US_TCC_eq(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, real_T c1_TD, real_T c1_M[3], real_T c1_A, real_T c1_B, real_T
  c1_P, real_T c1_t[3])
{
  uint32_T c1_debug_family_var_map[8];
  real_T c1_nargin = 5.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i28;
  real_T c1_a[3];
  real_T c1_b;
  real_T c1_b_b;
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_ak;
  real_T c1_bk;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_b_a;
  real_T c1_c_b;
  real_T c1_ar;
  real_T c1_br;
  real_T c1_y;
  real_T c1_b_y[3];
  real_T c1_c_x;
  int32_T c1_i29;
  real_T c1_d_x;
  int32_T c1_i30;
  int32_T c1_i31;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c1_c_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_TD, 2U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_M, 3U, c1_g_sf_marshallOut,
    c1_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_A, 4U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_B, 5U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_P, 6U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_t, 7U, c1_g_sf_marshallOut,
    c1_i_sf_marshallIn);
  CV_SCRIPT_FCN(2, 1);
  _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 43);
  for (c1_i28 = 0; c1_i28 < 3; c1_i28++) {
    c1_a[c1_i28] = c1_M[c1_i28];
  }

  c1_b = c1_P;
  c1_b_b = c1_b;
  for (c1_k = 0; c1_k < 3; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_ak = c1_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 1, 0) - 1];
    c1_bk = c1_b_b;
    if (c1_ak < 0.0) {
      c1_x = c1_bk;
      c1_b_x = c1_x;
      c1_b_x = muDoubleScalarFloor(c1_b_x);
      if (c1_b_x != c1_bk) {
        c1_eml_error(chartInstance);
      }
    }

    c1_b_a = c1_ak;
    c1_c_b = c1_bk;
    c1_eml_scalar_eg(chartInstance);
    c1_ar = c1_b_a;
    c1_br = c1_c_b;
    c1_y = muDoubleScalarPower(c1_ar, c1_br);
    c1_b_y[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 3, 1, 0) - 1] = c1_y;
  }

  c1_c_x = c1_A;
  for (c1_i29 = 0; c1_i29 < 3; c1_i29++) {
    c1_b_y[c1_i29]--;
  }

  c1_d_x = c1_c_x;
  for (c1_i30 = 0; c1_i30 < 3; c1_i30++) {
    c1_b_y[c1_i30] = c1_d_x / c1_b_y[c1_i30];
  }

  for (c1_i31 = 0; c1_i31 < 3; c1_i31++) {
    c1_t[c1_i31] = c1_TD * (c1_B + c1_b_y[c1_i31]);
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, -43);
  _SFD_SYMBOL_SCOPE_POP();
}

static c1_s7JLMi156dXwW96IDsWdPSB c1_relay_ANSI_2759_script
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, real_T c1_Ts,
   real_T c1_Vrms[3], real_T c1_VRMSLL)
{
  c1_s7JLMi156dXwW96IDsWdPSB c1_r;
  uint32_T c1_debug_family_var_map[17];
  real_T c1_additional_time_delay;
  real_T c1_TUV;
  real_T c1_TOV;
  real_T c1_u[6];
  real_T c1_y[6];
  real_T c1_t27;
  real_T c1_t59;
  boolean_T c1_bool_27;
  boolean_T c1_bool_59;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_a;
  real_T c1_b_y;
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_c_y;
  real_T c1_d_a;
  int32_T c1_i32;
  real_T c1_b_Vrms[3];
  real_T c1_varargin_1[3];
  int32_T c1_i33;
  real_T c1_c_Vrms[3];
  real_T c1_dv4[3];
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  real_T c1_b_u[6];
  real_T c1_dv5[6];
  int32_T c1_i37;
  real_T c1_dv6[6];
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  real_T c1_d_y[6];
  int32_T c1_i41;
  real_T c1_e_y[6];
  real_T c1_dv7[6];
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_ixstart;
  real_T c1_mtmp;
  real_T c1_x;
  boolean_T c1_b;
  int32_T c1_ix;
  int32_T c1_b_ix;
  real_T c1_b_x;
  boolean_T c1_b_b;
  int32_T c1_e_a;
  int32_T c1_i44;
  boolean_T c1_overflow;
  int32_T c1_c_ix;
  real_T c1_f_a;
  real_T c1_c_b;
  boolean_T c1_p;
  real_T c1_b_mtmp;
  real_T c1_minval;
  int32_T c1_i45;
  int32_T c1_b_ixstart;
  real_T c1_c_mtmp;
  real_T c1_c_x;
  boolean_T c1_d_b;
  int32_T c1_d_ix;
  int32_T c1_e_ix;
  real_T c1_d_x;
  boolean_T c1_e_b;
  int32_T c1_g_a;
  int32_T c1_i46;
  boolean_T c1_b_overflow;
  int32_T c1_f_ix;
  real_T c1_h_a;
  real_T c1_f_b;
  boolean_T c1_b_p;
  real_T c1_d_mtmp;
  real_T c1_b_minval;
  int32_T c1_i47;
  boolean_T c1_d_Vrms[3];
  int32_T c1_i48;
  boolean_T c1_e_Vrms[3];
  boolean_T exitg1;
  boolean_T exitg2;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c1_f_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_additional_time_delay, 0U,
    c1_f_sf_marshallOut, c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_TUV, 1U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_TOV, 2U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_u, 3U, c1_m_sf_marshallOut,
    c1_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_y, 4U, c1_m_sf_marshallOut,
    c1_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_t27, 5U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_t59, 6U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bool_27, 7U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_bool_59, 8U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 9U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 10U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Ts, 11U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Vrms, 12U, c1_g_sf_marshallOut,
    c1_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_VRMSLL, 13U, c1_f_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_r, 14U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_n27, 15U,
    c1_l_sf_marshallOut, c1_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c1_n59, 16U,
    c1_k_sf_marshallOut, c1_k_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 10);
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 11);
  if (CV_SCRIPT_IF(3, 0, !chartInstance->c1_n59_not_empty)) {
    _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 12);
    chartInstance->c1_n59 = 0.0;
    chartInstance->c1_n59_not_empty = TRUE;
    _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 13);
    chartInstance->c1_n27 = 0.0;
    chartInstance->c1_n27_not_empty = TRUE;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 18);
  c1_additional_time_delay = 0.1125;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 21);
  c1_a = c1_VRMSLL;
  c1_b_y = c1_a * 0.85;
  c1_b_a = c1_b_y;
  c1_TUV = c1_b_a * 0.57735026918962573;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 22);
  c1_c_a = c1_VRMSLL;
  c1_c_y = c1_c_a * 1.15;
  c1_d_a = c1_c_y;
  c1_TOV = c1_d_a * 0.57735026918962573;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 23);
  for (c1_i32 = 0; c1_i32 < 3; c1_i32++) {
    c1_b_Vrms[c1_i32] = c1_Vrms[c1_i32];
  }

  c1_rdivide(chartInstance, c1_b_Vrms, c1_TUV, c1_varargin_1);
  for (c1_i33 = 0; c1_i33 < 3; c1_i33++) {
    c1_c_Vrms[c1_i33] = c1_Vrms[c1_i33];
  }

  c1_rdivide(chartInstance, c1_c_Vrms, c1_TOV, c1_dv4);
  for (c1_i34 = 0; c1_i34 < 3; c1_i34++) {
    c1_u[c1_i34] = c1_varargin_1[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 3; c1_i35++) {
    c1_u[c1_i35 + 3] = c1_dv4[c1_i35];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 28);
  for (c1_i36 = 0; c1_i36 < 6; c1_i36++) {
    c1_b_u[c1_i36] = c1_u[c1_i36];
  }

  c1_power(chartInstance, c1_b_u, c1_dv5);
  for (c1_i37 = 0; c1_i37 < 6; c1_i37++) {
    c1_dv6[c1_i37] = c1_dv5[c1_i37] - 1.0;
  }

  c1_b_rdivide(chartInstance, 0.0515, c1_dv6, c1_dv5);
  for (c1_i38 = 0; c1_i38 < 6; c1_i38++) {
    c1_y[c1_i38] = 0.114 + c1_dv5[c1_i38];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 30);
  for (c1_i39 = 0; c1_i39 < 3; c1_i39++) {
    c1_y[c1_i39] = -c1_y[c1_i39];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 31);
  for (c1_i40 = 0; c1_i40 < 6; c1_i40++) {
    c1_d_y[c1_i40] = (real_T)(c1_y[c1_i40] > 0.0) * c1_y[c1_i40];
  }

  for (c1_i41 = 0; c1_i41 < 6; c1_i41++) {
    c1_e_y[c1_i41] = (real_T)(c1_y[c1_i41] > 0.0);
  }

  c1_c_rdivide(chartInstance, c1_d_y, c1_e_y, c1_dv7);
  for (c1_i42 = 0; c1_i42 < 6; c1_i42++) {
    c1_y[c1_i42] = c1_dv7[c1_i42];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 33);
  for (c1_i43 = 0; c1_i43 < 3; c1_i43++) {
    c1_varargin_1[c1_i43] = c1_y[c1_i43];
  }

  c1_ixstart = 1;
  c1_mtmp = c1_varargin_1[0];
  c1_x = c1_mtmp;
  c1_b = muDoubleScalarIsNaN(c1_x);
  if (c1_b) {
    c1_ix = 2;
    exitg2 = FALSE;
    while ((exitg2 == FALSE) && (c1_ix < 4)) {
      c1_b_ix = c1_ix;
      c1_ixstart = c1_b_ix;
      c1_b_x = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
      c1_b_b = muDoubleScalarIsNaN(c1_b_x);
      if (!c1_b_b) {
        c1_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
        exitg2 = TRUE;
      } else {
        c1_ix++;
      }
    }
  }

  if (c1_ixstart < 3) {
    c1_e_a = c1_ixstart;
    c1_i44 = c1_e_a;
    c1_overflow = FALSE;
    if (c1_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_overflow);
    }

    for (c1_c_ix = c1_i44 + 1; c1_c_ix < 4; c1_c_ix++) {
      c1_b_ix = c1_c_ix;
      c1_f_a = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
      c1_c_b = c1_mtmp;
      c1_p = (c1_f_a < c1_c_b);
      if (c1_p) {
        c1_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_ix), 1, 3, 1, 0) - 1];
      }
    }
  }

  c1_b_mtmp = c1_mtmp;
  c1_minval = c1_b_mtmp;
  c1_t27 = c1_minval + c1_additional_time_delay;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 34);
  for (c1_i45 = 0; c1_i45 < 3; c1_i45++) {
    c1_varargin_1[c1_i45] = c1_y[c1_i45 + 3];
  }

  c1_b_ixstart = 1;
  c1_c_mtmp = c1_varargin_1[0];
  c1_c_x = c1_c_mtmp;
  c1_d_b = muDoubleScalarIsNaN(c1_c_x);
  if (c1_d_b) {
    c1_d_ix = 2;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c1_d_ix < 4)) {
      c1_e_ix = c1_d_ix;
      c1_b_ixstart = c1_e_ix;
      c1_d_x = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_e_ix), 1, 3, 1, 0) - 1];
      c1_e_b = muDoubleScalarIsNaN(c1_d_x);
      if (!c1_e_b) {
        c1_c_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_e_ix), 1, 3, 1, 0) - 1];
        exitg1 = TRUE;
      } else {
        c1_d_ix++;
      }
    }
  }

  if (c1_b_ixstart < 3) {
    c1_g_a = c1_b_ixstart;
    c1_i46 = c1_g_a;
    c1_b_overflow = FALSE;
    if (c1_b_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_b_overflow);
    }

    for (c1_f_ix = c1_i46 + 1; c1_f_ix < 4; c1_f_ix++) {
      c1_e_ix = c1_f_ix;
      c1_h_a = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_e_ix), 1, 3, 1, 0) - 1];
      c1_f_b = c1_c_mtmp;
      c1_b_p = (c1_h_a < c1_f_b);
      if (c1_b_p) {
        c1_c_mtmp = c1_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_e_ix), 1, 3, 1, 0) - 1];
      }
    }
  }

  c1_d_mtmp = c1_c_mtmp;
  c1_b_minval = c1_d_mtmp;
  c1_t59 = c1_b_minval + c1_additional_time_delay;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 36);
  for (c1_i47 = 0; c1_i47 < 3; c1_i47++) {
    c1_d_Vrms[c1_i47] = (c1_Vrms[c1_i47] < c1_TUV);
  }

  c1_bool_27 = (c1_sum(chartInstance, c1_d_Vrms) > 0.0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 37);
  for (c1_i48 = 0; c1_i48 < 3; c1_i48++) {
    c1_e_Vrms[c1_i48] = (c1_Vrms[c1_i48] > c1_TOV);
  }

  c1_bool_59 = (c1_sum(chartInstance, c1_e_Vrms) > 0.0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 39);
  chartInstance->c1_n27 *= (real_T)c1_bool_27;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 40);
  chartInstance->c1_n59 *= (real_T)c1_bool_59;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 42);
  chartInstance->c1_n27 += (real_T)c1_bool_27 * c1_Ts;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 43);
  chartInstance->c1_n59 += (real_T)c1_bool_59 * c1_Ts;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 45);
  c1_r.trip27 = (chartInstance->c1_n27 > c1_t27);
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 46);
  c1_r.trip59 = (chartInstance->c1_n59 > c1_t59);
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, -46);
  _SFD_SYMBOL_SCOPE_POP();
  return c1_r;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_50P_script.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 1U, sf_debug_get_script_id(
    "C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_51P_script.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 2U, sf_debug_get_script_id(
    "C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_TCC.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 3U, sf_debug_get_script_id(
    "C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_R59_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_b_R59, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_R59), &c1_thisId);
  sf_mex_destroy(&c1_b_R59);
  return c1_y;
}

static boolean_T c1_b_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b1;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_R59_not_empty = FALSE;
  } else {
    chartInstance->c1_R59_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b1, 1, 11, 0U, 0, 0U, 0);
    c1_y = c1_b1;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_R59;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_b_R59 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_R59), &c1_thisId);
  sf_mex_destroy(&c1_b_R59);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_R27_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_b_R27, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_R27), &c1_thisId);
  sf_mex_destroy(&c1_b_R27);
  return c1_y;
}

static boolean_T c1_d_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b2;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_R27_not_empty = FALSE;
  } else {
    chartInstance->c1_R27_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b2, 1, 11, 0U, 0, 0U, 0);
    c1_y = c1_b2;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_R27;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_b_R27 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_R27), &c1_thisId);
  sf_mex_destroy(&c1_b_R27);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_R51_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_e_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_b_R51, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_R51), &c1_thisId);
  sf_mex_destroy(&c1_b_R51);
  return c1_y;
}

static boolean_T c1_f_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b3;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_R51_not_empty = FALSE;
  } else {
    chartInstance->c1_R51_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b3, 1, 11, 0U, 0, 0U, 0);
    c1_y = c1_b3;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_R51;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_b_R51 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_R51), &c1_thisId);
  sf_mex_destroy(&c1_b_R51);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_R50_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_g_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_b_R50, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_R50), &c1_thisId);
  sf_mex_destroy(&c1_b_R50);
  return c1_y;
}

static boolean_T c1_h_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b4;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_R50_not_empty = FALSE;
  } else {
    chartInstance->c1_R50_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b4, 1, 11, 0U, 0, 0U, 0);
    c1_y = c1_b4;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_R50;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_b_R50 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_R50), &c1_thisId);
  sf_mex_destroy(&c1_b_R50);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_i_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_trip59, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_trip59), &c1_thisId);
  sf_mex_destroy(&c1_trip59);
  return c1_y;
}

static boolean_T c1_j_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b5;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b5, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b5;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_trip59;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_trip59 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_trip59), &c1_thisId);
  sf_mex_destroy(&c1_trip59);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i49;
  real_T c1_b_inData[3];
  int32_T c1_i50;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i49 = 0; c1_i49 < 3; c1_i49++) {
    c1_b_inData[c1_i49] = (*(real_T (*)[3])c1_inData)[c1_i49];
  }

  for (c1_i50 = 0; c1_i50 < 3; c1_i50++) {
    c1_u[c1_i50] = c1_b_inData[c1_i50];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_k_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_s7JLMi156dXwW96IDsWdPSB c1_u;
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  boolean_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_s7JLMi156dXwW96IDsWdPSB *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c1_b_u = c1_u.trip27;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_b_y, "trip27", "trip27", 0);
  c1_c_u = c1_u.trip59;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c1_y, c1_c_y, "trip59", "trip59", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static c1_s7JLMi156dXwW96IDsWdPSB c1_l_emlrt_marshallIn
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  c1_s7JLMi156dXwW96IDsWdPSB c1_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[2] = { "trip27", "trip59" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 2, c1_fieldNames, 0U, 0);
  c1_thisId.fIdentifier = "trip27";
  c1_y.trip27 = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "trip27", "trip27", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "trip59";
  c1_y.trip59 = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "trip59", "trip59", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_r;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_s7JLMi156dXwW96IDsWdPSB c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_r = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_r), &c1_thisId);
  sf_mex_destroy(&c1_r);
  *(c1_s7JLMi156dXwW96IDsWdPSB *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_n50_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_m_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_b_n50, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n50), &c1_thisId);
  sf_mex_destroy(&c1_b_n50);
  return c1_y;
}

static real_T c1_n_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_n50_not_empty = FALSE;
  } else {
    chartInstance->c1_n50_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d1;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_n50;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_b_n50 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n50), &c1_thisId);
  sf_mex_destroy(&c1_b_n50);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_o_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv8[3];
  int32_T c1_i51;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv8, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i51 = 0; c1_i51 < 3; c1_i51++) {
    c1_y[c1_i51] = c1_dv8[c1_i51];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Iinst;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i52;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_Iinst = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Iinst), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Iinst);
  for (c1_i52 = 0; c1_i52 < 3; c1_i52++) {
    (*(real_T (*)[3])c1_outData)[c1_i52] = c1_y[c1_i52];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_n51_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_p_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_b_n51, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n51), &c1_thisId);
  sf_mex_destroy(&c1_b_n51);
  return c1_y;
}

static real_T c1_q_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_n51_not_empty = FALSE;
  } else {
    chartInstance->c1_n51_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d2;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_n51;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_b_n51 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n51), &c1_thisId);
  sf_mex_destroy(&c1_b_n51);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_n59_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_r_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_b_n59, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n59), &c1_thisId);
  sf_mex_destroy(&c1_b_n59);
  return c1_y;
}

static real_T c1_s_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d3;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_n59_not_empty = FALSE;
  } else {
    chartInstance->c1_n59_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d3, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d3;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_n59;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_b_n59 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n59), &c1_thisId);
  sf_mex_destroy(&c1_b_n59);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_n27_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_t_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_b_n27, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n27), &c1_thisId);
  sf_mex_destroy(&c1_b_n27);
  return c1_y;
}

static real_T c1_u_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d4;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_n27_not_empty = FALSE;
  } else {
    chartInstance->c1_n27_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d4, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d4;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_n27;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_b_n27 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_n27), &c1_thisId);
  sf_mex_destroy(&c1_b_n27);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i53;
  real_T c1_b_inData[6];
  int32_T c1_i54;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i53 = 0; c1_i53 < 6; c1_i53++) {
    c1_b_inData[c1_i53] = (*(real_T (*)[6])c1_inData)[c1_i53];
  }

  for (c1_i54 = 0; c1_i54 < 6; c1_i54++) {
    c1_u[c1_i54] = c1_b_inData[c1_i54];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_v_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[6])
{
  real_T c1_dv9[6];
  int32_T c1_i55;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv9, 1, 0, 0U, 1, 0U, 1, 6);
  for (c1_i55 = 0; c1_i55 < 6; c1_i55++) {
    c1_y[c1_i55] = c1_dv9[c1_i55];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y[6];
  int32_T c1_i56;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_v_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  for (c1_i56 = 0; c1_i56 < 6; c1_i56++) {
    (*(real_T (*)[6])c1_outData)[c1_i56] = c1_b_y[c1_i56];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_relay_ANSI_functions_lib_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[53];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i57;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 53), FALSE);
  for (c1_i57 = 0; c1_i57 < 53; c1_i57++) {
    c1_r0 = &c1_info[c1_i57];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i57);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i57);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i57);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i57);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i57);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i57);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i57);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i57);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[53])
{
  c1_info[0].context = "";
  c1_info[0].name = "mrdivide";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[0].fileTimeLo = 1357973148U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 1319751566U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].name = "rdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[1].fileTimeLo = 1346531988U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[2].name = "eml_scalexp_compatible";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[2].fileTimeLo = 1286840396U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[3].name = "eml_div";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[3].fileTimeLo = 1313369410U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "";
  c1_info[4].name = "mtimes";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[4].fileTimeLo = 1289541292U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "";
  c1_info[5].name = "relay_ANSI_50P_script";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_50P_script.m";
  c1_info[5].fileTimeLo = 1467940388U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_50P_script.m";
  c1_info[6].name = "mrdivide";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[6].fileTimeLo = 1357973148U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 1319751566U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_50P_script.m";
  c1_info[7].name = "mtimes";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[7].fileTimeLo = 1289541292U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_50P_script.m";
  c1_info[8].name = "sqrt";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[8].fileTimeLo = 1343851986U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[9].name = "eml_error";
  c1_info[9].dominantType = "char";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[9].fileTimeLo = 1343851958U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[10].name = "eml_scalar_sqrt";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[10].fileTimeLo = 1286840338U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_50P_script.m";
  c1_info[11].name = "sum";
  c1_info[11].dominantType = "logical";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[11].fileTimeLo = 1314758212U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[12].name = "isequal";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[12].fileTimeLo = 1286840358U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[13].name = "eml_isequal_core";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[13].fileTimeLo = 1286840386U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[14].name = "eml_const_nonsingleton_dim";
  c1_info[14].dominantType = "logical";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[14].fileTimeLo = 1286840296U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[15].name = "eml_scalar_eg";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[15].fileTimeLo = 1286840396U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[16].name = "eml_index_class";
  c1_info[16].dominantType = "";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[16].fileTimeLo = 1323192178U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[17].name = "eml_int_forloop_overflow_check";
  c1_info[17].dominantType = "";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[17].fileTimeLo = 1346531940U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[18].name = "intmax";
  c1_info[18].dominantType = "char";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[18].fileTimeLo = 1311276916U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context = "";
  c1_info[19].name = "relay_ANSI_51P_script";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_51P_script.m";
  c1_info[19].fileTimeLo = 1467940388U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_51P_script.m";
  c1_info[20].name = "mtimes";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[20].fileTimeLo = 1289541292U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_51P_script.m";
  c1_info[21].name = "rdivide";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[21].fileTimeLo = 1346531988U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_51P_script.m";
  c1_info[22].name = "relay_TCC";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_TCC.m";
  c1_info[22].fileTimeLo = 1467940388U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_TCC.m!op_time_US_TCC_eq";
  c1_info[23].name = "power";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[23].fileTimeLo = 1348213530U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[24].name = "eml_scalar_eg";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[24].fileTimeLo = 1286840396U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[25].name = "eml_scalexp_alloc";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[25].fileTimeLo = 1352446460U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[26].name = "floor";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[26].fileTimeLo = 1343851980U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[27].name = "eml_scalar_floor";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[27].fileTimeLo = 1286840326U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[28].name = "eml_error";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[28].fileTimeLo = 1343851958U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[29].name = "eml_scalar_eg";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[29].fileTimeLo = 1286840396U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_TCC.m!op_time_US_TCC_eq";
  c1_info[30].name = "rdivide";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[30].fileTimeLo = 1346531988U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_51P_script.m";
  c1_info[31].name = "min";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[31].fileTimeLo = 1311276918U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[32].name = "eml_min_or_max";
  c1_info[32].dominantType = "char";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[32].fileTimeLo = 1334093090U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c1_info[33].name = "eml_const_nonsingleton_dim";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[33].fileTimeLo = 1286840296U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c1_info[34].name = "eml_scalar_eg";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[34].fileTimeLo = 1286840396U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c1_info[35].name = "eml_index_class";
  c1_info[35].dominantType = "";
  c1_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[35].fileTimeLo = 1323192178U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c1_info[36].name = "eml_index_class";
  c1_info[36].dominantType = "";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[36].fileTimeLo = 1323192178U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c1_info[37].name = "isnan";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[37].fileTimeLo = 1286840360U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c1_info[38].name = "eml_index_plus";
  c1_info[38].dominantType = "coder.internal.indexInt";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[38].fileTimeLo = 1286840378U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[39].name = "eml_index_class";
  c1_info[39].dominantType = "";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[39].fileTimeLo = 1323192178U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c1_info[40].name = "eml_int_forloop_overflow_check";
  c1_info[40].dominantType = "";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[40].fileTimeLo = 1346531940U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c1_info[41].name = "eml_relop";
  c1_info[41].dominantType = "function_handle";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c1_info[41].fileTimeLo = 1342472782U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_51P_script.m";
  c1_info[42].name = "sum";
  c1_info[42].dominantType = "logical";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[42].fileTimeLo = 1314758212U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context = "";
  c1_info[43].name = "relay_ANSI_2759_script";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m";
  c1_info[43].fileTimeLo = 1467940388U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m";
  c1_info[44].name = "mtimes";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[44].fileTimeLo = 1289541292U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m";
  c1_info[45].name = "mrdivide";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[45].fileTimeLo = 1357973148U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 1319751566U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m";
  c1_info[46].name = "sqrt";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[46].fileTimeLo = 1343851986U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m";
  c1_info[47].name = "rdivide";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[47].fileTimeLo = 1346531988U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m";
  c1_info[48].name = "power";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[48].fileTimeLo = 1348213530U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[49].name = "isequal";
  c1_info[49].dominantType = "double";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[49].fileTimeLo = 1286840358U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c1_info[50].name = "isnan";
  c1_info[50].dominantType = "double";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[50].fileTimeLo = 1286840360U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m";
  c1_info[51].name = "min";
  c1_info[51].dominantType = "double";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[51].fileTimeLo = 1311276918U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[E]C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m";
  c1_info[52].name = "sum";
  c1_info[52].dominantType = "logical";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[52].fileTimeLo = 1314758212U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
}

static real_T c1_sum(SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance,
                     boolean_T c1_x[3])
{
  real_T c1_y;
  int32_T c1_k;
  int32_T c1_b_k;
  c1_y = (real_T)c1_x[0];
  for (c1_k = 2; c1_k < 4; c1_k++) {
    c1_b_k = c1_k;
    c1_y += (real_T)c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
  }

  return c1_y;
}

static void c1_rdivide(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, real_T c1_x[3], real_T c1_y, real_T c1_z[3])
{
  real_T c1_b_y;
  int32_T c1_i58;
  c1_b_y = c1_y;
  for (c1_i58 = 0; c1_i58 < 3; c1_i58++) {
    c1_z[c1_i58] = c1_x[c1_i58] / c1_b_y;
  }
}

static void c1_eml_error(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance)
{
  int32_T c1_i59;
  static char_T c1_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[31];
  const mxArray *c1_y = NULL;
  for (c1_i59 = 0; c1_i59 < 31; c1_i59++) {
    c1_u[c1_i59] = c1_cv0[c1_i59];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 31), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static void c1_eml_scalar_eg(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance)
{
}

static void c1_check_forloop_overflow_error
  (SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance, boolean_T
   c1_overflow)
{
  int32_T c1_i60;
  static char_T c1_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i61;
  static char_T c1_cv2[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c1_b_u[23];
  const mxArray *c1_b_y = NULL;
  if (!c1_overflow) {
  } else {
    for (c1_i60 = 0; c1_i60 < 34; c1_i60++) {
      c1_u[c1_i60] = c1_cv1[c1_i60];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c1_i61 = 0; c1_i61 < 23; c1_i61++) {
      c1_b_u[c1_i61] = c1_cv2[c1_i61];
    }

    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c1_y, 14, c1_b_y));
  }
}

static void c1_power(SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance,
                     real_T c1_a[6], real_T c1_y[6])
{
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_ak;
  real_T c1_b_a;
  real_T c1_ar;
  real_T c1_b_y;
  for (c1_k = 0; c1_k < 6; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_ak = c1_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 6, 1, 0) - 1];
    if (c1_ak < 0.0) {
      c1_eml_error(chartInstance);
    }

    c1_b_a = c1_ak;
    c1_eml_scalar_eg(chartInstance);
    c1_ar = c1_b_a;
    c1_b_y = muDoubleScalarPower(c1_ar, 0.02);
    c1_y[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 6, 1, 0) - 1] = c1_b_y;
  }
}

static void c1_b_rdivide(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, real_T c1_x, real_T c1_y[6], real_T c1_z[6])
{
  real_T c1_b_x;
  int32_T c1_i62;
  c1_b_x = c1_x;
  for (c1_i62 = 0; c1_i62 < 6; c1_i62++) {
    c1_z[c1_i62] = c1_b_x / c1_y[c1_i62];
  }
}

static void c1_c_rdivide(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, real_T c1_x[6], real_T c1_y[6], real_T c1_z[6])
{
  int32_T c1_i63;
  for (c1_i63 = 0; c1_i63 < 6; c1_i63++) {
    c1_z[c1_i63] = c1_x[c1_i63] / c1_y[c1_i63];
  }
}

static const mxArray *c1_n_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_w_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i64;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i64, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i64;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_x_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_relay_ANSI_functions_lib,
  const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_y_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_relay_ANSI_functions_lib), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_relay_ANSI_functions_lib);
  return c1_y;
}

static uint8_T c1_y_emlrt_marshallIn(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_relay_ANSI_functions_libInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_relay_ANSI_functions_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4034350667U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1629379643U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3163685964U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1196927900U);
}

mxArray *sf_c1_relay_ANSI_functions_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("UWbYIx696j6rQvWAsV1s7C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_relay_ANSI_functions_lib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_relay_ANSI_functions_lib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[6],T\"trip27\",},{M[1],M[22],T\"trip50\",},{M[1],M[5],T\"trip51\",},{M[1],M[11],T\"trip59\",},{M[4],M[0],T\"R27\",S'l','i','p'{{M1x2[351 354],M[0],}}},{M[4],M[0],T\"R50\",S'l','i','p'{{M1x2[343 346],M[0],}}},{M[4],M[0],T\"R51\",S'l','i','p'{{M1x2[347 350],M[0],}}},{M[4],M[0],T\"R59\",S'l','i','p'{{M1x2[355 358],M[0],}}},{M[4],M[0],T\"n27\",S'l','i','p'{{M1x2[190 193],M[1],T\"C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m\"}}},{M[4],M[0],T\"n50\",S'l','i','p'{{M1x2[272 275],M[1],T\"C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_50P_script.m\"}}}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[4],M[0],T\"n51\",S'l','i','p'{{M1x2[277 280],M[1],T\"C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_51P_script.m\"}}},{M[4],M[0],T\"n59\",S'l','i','p'{{M1x2[194 197],M[1],T\"C:/Users/ED12083/Desktop/GitRepositories/HIL/Components/Relay/relay_ANSI_2759_script.m\"}}},{M[8],M[0],T\"is_active_c1_relay_ANSI_functions_lib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_relay_ANSI_functions_lib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
    chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _relay_ANSI_functions_libMachineNumber_,
           1,
           1,
           1,
           16,
           0,
           0,
           0,
           0,
           4,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_relay_ANSI_functions_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_relay_ANSI_functions_libMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _relay_ANSI_functions_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ts");
          _SFD_SET_DATA_PROPS(1,2,0,1,"trip50");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Reset");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Iinst");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Irms");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Vrms");
          _SFD_SET_DATA_PROPS(6,1,1,0,"VRMSLL");
          _SFD_SET_DATA_PROPS(7,1,1,0,"CT_p");
          _SFD_SET_DATA_PROPS(8,2,0,1,"trip51");
          _SFD_SET_DATA_PROPS(9,2,0,1,"trip27");
          _SFD_SET_DATA_PROPS(10,1,1,0,"IOC_pickup");
          _SFD_SET_DATA_PROPS(11,2,0,1,"trip59");
          _SFD_SET_DATA_PROPS(12,1,1,0,"IOC_tripDelay");
          _SFD_SET_DATA_PROPS(13,1,1,0,"TOC_pickup");
          _SFD_SET_DATA_PROPS(14,1,1,0,"curveType");
          _SFD_SET_DATA_PROPS(15,1,1,0,"timeDial");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",112,-1,1059);
        _SFD_CV_INIT_EML_IF(0,1,0,359,383,-1,447);
        _SFD_CV_INIT_EML_IF(0,1,1,576,604,-1,952);

        {
          static int condStart[] = { 362, 378 };

          static int condEnd[] = { 374, 383 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,362,383,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 581, 594 };

          static int condEnd[] = { 590, 603 };

          static int pfixExpr[] = { 0, 1, -2, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,579,604,2,2,&(condStart[0]),&(condEnd[0]),
                                4,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"relay_ANSI_50P_script",112,-1,793);
        _SFD_CV_INIT_SCRIPT_IF(0,0,276,291,-1,306);
        _SFD_CV_INIT_SCRIPT(1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"relay_ANSI_51P_script",112,-1,934);
        _SFD_CV_INIT_SCRIPT_IF(1,0,281,296,-1,311);
        _SFD_CV_INIT_SCRIPT_IF(1,1,665,675,-1,692);
        _SFD_CV_INIT_SCRIPT(2,2,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"relay_TCC",112,-1,825);
        _SFD_CV_INIT_SCRIPT_FCN(2,1,"op_time_US_TCC_eq",828,-1,1184);
        _SFD_CV_INIT_SCRIPT_IF(2,0,463,479,561,820);
        _SFD_CV_INIT_SCRIPT_IF(2,1,561,581,646,820);
        _SFD_CV_INIT_SCRIPT_IF(2,2,646,666,737,820);
        _SFD_CV_INIT_SCRIPT(3,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"relay_ANSI_2759_script",112,-1,1165);
        _SFD_CV_INIT_SCRIPT_IF(3,0,198,213,-1,239);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_Ts;
          boolean_T *c1_trip50;
          real_T *c1_Reset;
          real_T *c1_VRMSLL;
          real_T *c1_CT_p;
          boolean_T *c1_trip51;
          boolean_T *c1_trip27;
          real_T *c1_IOC_pickup;
          boolean_T *c1_trip59;
          real_T *c1_IOC_tripDelay;
          real_T *c1_TOC_pickup;
          real_T *c1_curveType;
          real_T *c1_timeDial;
          real_T (*c1_Iinst)[3];
          real_T (*c1_Irms)[3];
          real_T (*c1_Vrms)[3];
          c1_timeDial = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c1_curveType = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c1_TOC_pickup = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c1_IOC_tripDelay = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c1_trip59 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_IOC_pickup = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c1_trip27 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_trip51 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_CT_p = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_VRMSLL = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_Vrms = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c1_Irms = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c1_Iinst = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c1_Reset = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_trip50 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Ts = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_Ts);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_trip50);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_Reset);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_Iinst);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_Irms);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_Vrms);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_VRMSLL);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_CT_p);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_trip51);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_trip27);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_IOC_pickup);
          _SFD_SET_DATA_VALUE_PTR(11U, c1_trip59);
          _SFD_SET_DATA_VALUE_PTR(12U, c1_IOC_tripDelay);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_TOC_pickup);
          _SFD_SET_DATA_VALUE_PTR(14U, c1_curveType);
          _SFD_SET_DATA_VALUE_PTR(15U, c1_timeDial);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _relay_ANSI_functions_libMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "YwIlEmBI4sCkfAiYlp2QrH";
}

static void sf_opaque_initialize_c1_relay_ANSI_functions_lib(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_relay_ANSI_functions_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_relay_ANSI_functions_lib
    ((SFc1_relay_ANSI_functions_libInstanceStruct*) chartInstanceVar);
  initialize_c1_relay_ANSI_functions_lib
    ((SFc1_relay_ANSI_functions_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_relay_ANSI_functions_lib(void *chartInstanceVar)
{
  enable_c1_relay_ANSI_functions_lib
    ((SFc1_relay_ANSI_functions_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_relay_ANSI_functions_lib(void *chartInstanceVar)
{
  disable_c1_relay_ANSI_functions_lib
    ((SFc1_relay_ANSI_functions_libInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_relay_ANSI_functions_lib(void *chartInstanceVar)
{
  sf_c1_relay_ANSI_functions_lib((SFc1_relay_ANSI_functions_libInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_relay_ANSI_functions_lib
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_relay_ANSI_functions_lib
    ((SFc1_relay_ANSI_functions_libInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_relay_ANSI_functions_lib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_relay_ANSI_functions_lib(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_relay_ANSI_functions_lib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_relay_ANSI_functions_lib
    ((SFc1_relay_ANSI_functions_libInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_relay_ANSI_functions_lib
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_relay_ANSI_functions_lib(S);
}

static void sf_opaque_set_sim_state_c1_relay_ANSI_functions_lib(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_relay_ANSI_functions_lib(S, st);
}

static void sf_opaque_terminate_c1_relay_ANSI_functions_lib(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_relay_ANSI_functions_libInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_relay_ANSI_functions_lib_optimization_info();
    }

    finalize_c1_relay_ANSI_functions_lib
      ((SFc1_relay_ANSI_functions_libInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_relay_ANSI_functions_lib
    ((SFc1_relay_ANSI_functions_libInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_relay_ANSI_functions_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_relay_ANSI_functions_lib
      ((SFc1_relay_ANSI_functions_libInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_relay_ANSI_functions_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_relay_ANSI_functions_lib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,12);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 12; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2744937586U));
  ssSetChecksum1(S,(3623009749U));
  ssSetChecksum2(S,(1741641498U));
  ssSetChecksum3(S,(222689753U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_relay_ANSI_functions_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_relay_ANSI_functions_lib(SimStruct *S)
{
  SFc1_relay_ANSI_functions_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_functions_libInstanceStruct *)utMalloc(sizeof
    (SFc1_relay_ANSI_functions_libInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_relay_ANSI_functions_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_relay_ANSI_functions_lib;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_relay_ANSI_functions_lib_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_relay_ANSI_functions_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_relay_ANSI_functions_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_relay_ANSI_functions_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_relay_ANSI_functions_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
