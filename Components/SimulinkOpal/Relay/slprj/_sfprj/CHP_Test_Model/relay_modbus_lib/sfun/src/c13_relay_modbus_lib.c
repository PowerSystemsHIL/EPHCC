/* Include files */

#include <stddef.h>
#include "blas.h"
#include "relay_modbus_lib_sfun.h"
#include "c13_relay_modbus_lib.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "relay_modbus_lib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c13_debug_family_names[11] = { "nargin", "nargout", "Ts",
  "bool_R25", "op_mode_in", "trip_in", "synch_check_time", "trip_out", "n25",
  "prev_mode", "prev_trip_in" };

/* Function Declarations */
static void initialize_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance);
static void initialize_params_c13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance);
static void enable_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance);
static void disable_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance);
static void c13_update_debugger_state_c13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance);
static void set_sim_state_c13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance, const mxArray *c13_st);
static void finalize_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance);
static void sf_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance);
static void initSimStructsc13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance);
static void registerMessagesc13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_b_prev_trip_in, const char_T
  *c13_identifier);
static real_T c13_b_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_c_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_b_prev_mode, const char_T *c13_identifier);
static real_T c13_d_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_e_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_b_n25, const char_T *c13_identifier);
static real_T c13_f_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_g_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_trip_out, const char_T *c13_identifier);
static real_T c13_h_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_i_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_j_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_relay_modbus_lib, const
  char_T *c13_identifier);
static uint8_T c13_k_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void init_dsm_address_info(SFc13_relay_modbus_libInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c13_n25_not_empty = FALSE;
  chartInstance->c13_prev_mode_not_empty = FALSE;
  chartInstance->c13_prev_trip_in_not_empty = FALSE;
  chartInstance->c13_is_active_c13_relay_modbus_lib = 0U;
}

static void initialize_params_c13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance)
{
}

static void enable_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c13_update_debugger_state_c13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  real_T c13_hoistedGlobal;
  real_T c13_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_b_hoistedGlobal;
  real_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  real_T c13_c_hoistedGlobal;
  real_T c13_c_u;
  const mxArray *c13_d_y = NULL;
  real_T c13_d_hoistedGlobal;
  real_T c13_d_u;
  const mxArray *c13_e_y = NULL;
  uint8_T c13_e_hoistedGlobal;
  uint8_T c13_e_u;
  const mxArray *c13_f_y = NULL;
  real_T *c13_trip_out;
  c13_trip_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(5), FALSE);
  c13_hoistedGlobal = *c13_trip_out;
  c13_u = c13_hoistedGlobal;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = chartInstance->c13_n25;
  c13_b_u = c13_b_hoistedGlobal;
  c13_c_y = NULL;
  if (!chartInstance->c13_n25_not_empty) {
    sf_mex_assign(&c13_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_c_hoistedGlobal = chartInstance->c13_prev_mode;
  c13_c_u = c13_c_hoistedGlobal;
  c13_d_y = NULL;
  if (!chartInstance->c13_prev_mode_not_empty) {
    sf_mex_assign(&c13_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c13_y, 2, c13_d_y);
  c13_d_hoistedGlobal = chartInstance->c13_prev_trip_in;
  c13_d_u = c13_d_hoistedGlobal;
  c13_e_y = NULL;
  if (!chartInstance->c13_prev_trip_in_not_empty) {
    sf_mex_assign(&c13_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_d_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c13_y, 3, c13_e_y);
  c13_e_hoistedGlobal = chartInstance->c13_is_active_c13_relay_modbus_lib;
  c13_e_u = c13_e_hoistedGlobal;
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 4, c13_f_y);
  sf_mex_assign(&c13_st, c13_y, FALSE);
  return c13_st;
}

static void set_sim_state_c13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  real_T *c13_trip_out;
  c13_trip_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  *c13_trip_out = c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 0)), "trip_out");
  chartInstance->c13_n25 = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 1)), "n25");
  chartInstance->c13_prev_mode = c13_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 2)), "prev_mode");
  chartInstance->c13_prev_trip_in = c13_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 3)), "prev_trip_in");
  chartInstance->c13_is_active_c13_relay_modbus_lib = c13_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 4)),
     "is_active_c13_relay_modbus_lib");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_relay_modbus_lib(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance)
{
}

static void sf_c13_relay_modbus_lib(SFc13_relay_modbus_libInstanceStruct
  *chartInstance)
{
  real_T c13_hoistedGlobal;
  boolean_T c13_b_hoistedGlobal;
  real_T c13_c_hoistedGlobal;
  real_T c13_d_hoistedGlobal;
  real_T c13_e_hoistedGlobal;
  real_T c13_Ts;
  boolean_T c13_bool_R25;
  real_T c13_op_mode_in;
  real_T c13_trip_in;
  real_T c13_synch_check_time;
  uint32_T c13_debug_family_var_map[11];
  real_T c13_nargin = 5.0;
  real_T c13_nargout = 1.0;
  real_T c13_trip_out;
  real_T c13_a;
  boolean_T c13_b;
  real_T c13_f_hoistedGlobal;
  real_T c13_b_a;
  boolean_T c13_b_b;
  real_T c13_g_hoistedGlobal;
  boolean_T c13_c_a;
  real_T c13_c_b;
  real_T c13_y;
  real_T *c13_b_Ts;
  boolean_T *c13_b_bool_R25;
  real_T *c13_b_op_mode_in;
  real_T *c13_b_trip_out;
  real_T *c13_b_trip_in;
  real_T *c13_b_synch_check_time;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c13_b_synch_check_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c13_b_trip_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c13_b_trip_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_b_op_mode_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c13_b_bool_R25 = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c13_b_Ts = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c13_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c13_b_Ts, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c13_b_bool_R25, 1U);
  _SFD_DATA_RANGE_CHECK(*c13_b_op_mode_in, 2U);
  _SFD_DATA_RANGE_CHECK(*c13_b_trip_out, 3U);
  _SFD_DATA_RANGE_CHECK(*c13_b_trip_in, 4U);
  _SFD_DATA_RANGE_CHECK(*c13_b_synch_check_time, 5U);
  chartInstance->c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c13_sfEvent);
  c13_hoistedGlobal = *c13_b_Ts;
  c13_b_hoistedGlobal = *c13_b_bool_R25;
  c13_c_hoistedGlobal = *c13_b_op_mode_in;
  c13_d_hoistedGlobal = *c13_b_trip_in;
  c13_e_hoistedGlobal = *c13_b_synch_check_time;
  c13_Ts = c13_hoistedGlobal;
  c13_bool_R25 = c13_b_hoistedGlobal;
  c13_op_mode_in = c13_c_hoistedGlobal;
  c13_trip_in = c13_d_hoistedGlobal;
  c13_synch_check_time = c13_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_Ts, 2U, c13_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_bool_R25, 3U, c13_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_op_mode_in, 4U, c13_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_trip_in, 5U, c13_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_synch_check_time, 6U, c13_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_trip_out, 7U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c13_n25, 8U,
    c13_c_sf_marshallOut, c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c13_prev_mode, 9U,
    c13_b_sf_marshallOut, c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c13_prev_trip_in, 10U,
    c13_sf_marshallOut, c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c13_prev_mode_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 6);
    chartInstance->c13_n25 = 0.0;
    chartInstance->c13_n25_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
    chartInstance->c13_prev_mode = 0.0;
    chartInstance->c13_prev_mode_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 8);
    chartInstance->c13_prev_trip_in = 1.0;
    chartInstance->c13_prev_trip_in_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 11);
  c13_a = c13_trip_in;
  c13_b = c13_bool_R25;
  c13_trip_out = c13_a * (real_T)c13_b;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 15);
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  guard4 = FALSE;
  if (CV_EML_COND(0, 1, 0, chartInstance->c13_prev_mode == 2.0)) {
    guard4 = TRUE;
  } else if (CV_EML_COND(0, 1, 1, chartInstance->c13_prev_trip_in == 0.0)) {
    guard4 = TRUE;
  } else {
    guard2 = TRUE;
  }

  if (guard4 == TRUE) {
    if (CV_EML_COND(0, 1, 2, c13_op_mode_in == 1.0)) {
      guard3 = TRUE;
    } else if (CV_EML_COND(0, 1, 3, c13_op_mode_in == 0.0)) {
      guard3 = TRUE;
    } else {
      guard2 = TRUE;
    }
  }

  if (guard3 == TRUE) {
    if (CV_EML_COND(0, 1, 4, c13_trip_in == 1.0)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 1, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 18);
      c13_f_hoistedGlobal = chartInstance->c13_n25;
      c13_b_a = c13_f_hoistedGlobal;
      c13_b_b = c13_bool_R25;
      chartInstance->c13_n25 = c13_b_a * (real_T)c13_b_b;
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 19);
      c13_g_hoistedGlobal = chartInstance->c13_n25;
      c13_c_a = c13_bool_R25;
      c13_c_b = c13_Ts;
      c13_y = (real_T)c13_c_a * c13_c_b;
      chartInstance->c13_n25 = c13_g_hoistedGlobal + c13_y;
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 20);
      if (CV_EML_IF(0, 1, 2, chartInstance->c13_n25 > c13_synch_check_time)) {
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 21);
        c13_trip_out = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 23);
        chartInstance->c13_prev_mode = c13_op_mode_in;
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 24);
        chartInstance->c13_prev_trip_in = c13_trip_in;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 26);
        chartInstance->c13_prev_mode = 2.0;
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 27);
        chartInstance->c13_prev_trip_in = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 28);
        c13_trip_out = 0.0;
      }
    } else {
      guard1 = TRUE;
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 1, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 31);
    if (CV_EML_IF(0, 1, 3, c13_op_mode_in == 2.0)) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 32);
      chartInstance->c13_prev_mode = 2.0;
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 33);
      chartInstance->c13_prev_trip_in = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 34);
      c13_trip_out = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 35);
      chartInstance->c13_n25 = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 37);
      chartInstance->c13_n25 = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -37);
  _SFD_SYMBOL_SCOPE_POP();
  *c13_b_trip_out = c13_trip_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c13_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_relay_modbus_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance)
{
}

static void registerMessagesc13_relay_modbus_lib
  (SFc13_relay_modbus_libInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  if (!chartInstance->c13_prev_trip_in_not_empty) {
    sf_mex_assign(&c13_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_b_prev_trip_in, const char_T
  *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_prev_trip_in),
    &c13_thisId);
  sf_mex_destroy(&c13_b_prev_trip_in);
  return c13_y;
}

static real_T c13_b_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  if (mxIsEmpty(c13_u)) {
    chartInstance->c13_prev_trip_in_not_empty = FALSE;
  } else {
    chartInstance->c13_prev_trip_in_not_empty = TRUE;
    sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
    c13_y = c13_d0;
  }

  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_prev_trip_in;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_b_prev_trip_in = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_prev_trip_in),
    &c13_thisId);
  sf_mex_destroy(&c13_b_prev_trip_in);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  if (!chartInstance->c13_prev_mode_not_empty) {
    sf_mex_assign(&c13_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_c_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_b_prev_mode, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_prev_mode),
    &c13_thisId);
  sf_mex_destroy(&c13_b_prev_mode);
  return c13_y;
}

static real_T c13_d_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d1;
  if (mxIsEmpty(c13_u)) {
    chartInstance->c13_prev_mode_not_empty = FALSE;
  } else {
    chartInstance->c13_prev_mode_not_empty = TRUE;
    sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d1, 1, 0, 0U, 0, 0U, 0);
    c13_y = c13_d1;
  }

  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_prev_mode;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_b_prev_mode = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_prev_mode),
    &c13_thisId);
  sf_mex_destroy(&c13_b_prev_mode);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  if (!chartInstance->c13_n25_not_empty) {
    sf_mex_assign(&c13_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_e_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_b_n25, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_n25),
    &c13_thisId);
  sf_mex_destroy(&c13_b_n25);
  return c13_y;
}

static real_T c13_f_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d2;
  if (mxIsEmpty(c13_u)) {
    chartInstance->c13_n25_not_empty = FALSE;
  } else {
    chartInstance->c13_n25_not_empty = TRUE;
    sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d2, 1, 0, 0U, 0, 0U, 0);
    c13_y = c13_d2;
  }

  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_n25;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_b_n25 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_n25),
    &c13_thisId);
  sf_mex_destroy(&c13_b_n25);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_g_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_trip_out, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_trip_out),
    &c13_thisId);
  sf_mex_destroy(&c13_trip_out);
  return c13_y;
}

static real_T c13_h_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d3;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d3, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d3;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_trip_out;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_trip_out = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_trip_out),
    &c13_thisId);
  sf_mex_destroy(&c13_trip_out);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  boolean_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(boolean_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

const mxArray *sf_c13_relay_modbus_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo;
  c13_ResolvedFunctionInfo c13_info[1];
  c13_ResolvedFunctionInfo (*c13_b_info)[1];
  const mxArray *c13_m0 = NULL;
  int32_T c13_i0;
  c13_ResolvedFunctionInfo *c13_r0;
  c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  c13_b_info = (c13_ResolvedFunctionInfo (*)[1])c13_info;
  (*c13_b_info)[0].context = "";
  (*c13_b_info)[0].name = "mtimes";
  (*c13_b_info)[0].dominantType = "double";
  (*c13_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c13_b_info)[0].fileTimeLo = 1289541292U;
  (*c13_b_info)[0].fileTimeHi = 0U;
  (*c13_b_info)[0].mFileTimeLo = 0U;
  (*c13_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c13_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c13_i0 = 0; c13_i0 < 1; c13_i0++) {
    c13_r0 = &c13_info[c13_i0];
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->context)), "context", "nameCaptureInfo",
                    c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->name)), "name", "nameCaptureInfo", c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      c13_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->resolved)), "resolved",
                    "nameCaptureInfo", c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      &c13_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c13_i0);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      &c13_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c13_i0);
  }

  sf_mex_assign(&c13_nameCaptureInfo, c13_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c13_nameCaptureInfo);
  return c13_nameCaptureInfo;
}

static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static int32_T c13_i_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i1;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i1, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i1;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_j_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_relay_modbus_lib, const
  char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_relay_modbus_lib), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_relay_modbus_lib);
  return c13_y;
}

static uint8_T c13_k_emlrt_marshallIn(SFc13_relay_modbus_libInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void init_dsm_address_info(SFc13_relay_modbus_libInstanceStruct
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

void sf_c13_relay_modbus_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(304869637U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1974256675U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3048983067U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1892771332U);
}

mxArray *sf_c13_relay_modbus_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("B6JJCjlHamg3E8Oj920GqF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c13_relay_modbus_lib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c13_relay_modbus_lib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[8],T\"trip_out\",},{M[4],M[0],T\"n25\",S'l','i','p'{{M1x2[105 108],M[0],}}},{M[4],M[0],T\"prev_mode\",S'l','i','p'{{M1x2[109 118],M[0],}}},{M[4],M[0],T\"prev_trip_in\",S'l','i','p'{{M1x2[119 131],M[0],}}},{M[8],M[0],T\"is_active_c13_relay_modbus_lib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_relay_modbus_lib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_relay_modbus_libInstanceStruct *chartInstance;
    chartInstance = (SFc13_relay_modbus_libInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _relay_modbus_libMachineNumber_,
           13,
           1,
           1,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_relay_modbus_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_relay_modbus_libMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _relay_modbus_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ts");
          _SFD_SET_DATA_PROPS(1,1,1,0,"bool_R25");
          _SFD_SET_DATA_PROPS(2,1,1,0,"op_mode_in");
          _SFD_SET_DATA_PROPS(3,2,0,1,"trip_out");
          _SFD_SET_DATA_PROPS(4,1,1,0,"trip_in");
          _SFD_SET_DATA_PROPS(5,1,1,0,"synch_check_time");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,5,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,943);
        _SFD_CV_INIT_EML_IF(0,1,0,132,153,-1,275);
        _SFD_CV_INIT_EML_IF(0,1,1,415,501,828,942);
        _SFD_CV_INIT_EML_IF(0,1,2,592,617,739,822);
        _SFD_CV_INIT_EML_IF(0,1,3,828,848,921,942);

        {
          static int condStart[] = { 419, 435, 456, 473, 491 };

          static int condEnd[] = { 431, 450, 469, 486, 501 };

          static int pfixExpr[] = { 0, 1, -2, 2, 3, -2, -3, 4, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,418,501,5,0,&(condStart[0]),&(condEnd[0]),
                                9,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_d_sf_marshallOut,(MexInFcnForType)
          c13_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c13_Ts;
          boolean_T *c13_bool_R25;
          real_T *c13_op_mode_in;
          real_T *c13_trip_out;
          real_T *c13_trip_in;
          real_T *c13_synch_check_time;
          c13_synch_check_time = (real_T *)ssGetInputPortSignal(chartInstance->S,
            4);
          c13_trip_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c13_trip_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c13_op_mode_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c13_bool_R25 = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c13_Ts = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_Ts);
          _SFD_SET_DATA_VALUE_PTR(1U, c13_bool_R25);
          _SFD_SET_DATA_VALUE_PTR(2U, c13_op_mode_in);
          _SFD_SET_DATA_VALUE_PTR(3U, c13_trip_out);
          _SFD_SET_DATA_VALUE_PTR(4U, c13_trip_in);
          _SFD_SET_DATA_VALUE_PTR(5U, c13_synch_check_time);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _relay_modbus_libMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Xr2jG8uHiW2DwQLy5wHfm";
}

static void sf_opaque_initialize_c13_relay_modbus_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_relay_modbus_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_relay_modbus_lib((SFc13_relay_modbus_libInstanceStruct*)
    chartInstanceVar);
  initialize_c13_relay_modbus_lib((SFc13_relay_modbus_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_relay_modbus_lib(void *chartInstanceVar)
{
  enable_c13_relay_modbus_lib((SFc13_relay_modbus_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_relay_modbus_lib(void *chartInstanceVar)
{
  disable_c13_relay_modbus_lib((SFc13_relay_modbus_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_relay_modbus_lib(void *chartInstanceVar)
{
  sf_c13_relay_modbus_lib((SFc13_relay_modbus_libInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_relay_modbus_lib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_relay_modbus_lib
    ((SFc13_relay_modbus_libInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_relay_modbus_lib();/* state var info */
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

extern void sf_internal_set_sim_state_c13_relay_modbus_lib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_relay_modbus_lib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_relay_modbus_lib((SFc13_relay_modbus_libInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_relay_modbus_lib(SimStruct* S)
{
  return sf_internal_get_sim_state_c13_relay_modbus_lib(S);
}

static void sf_opaque_set_sim_state_c13_relay_modbus_lib(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c13_relay_modbus_lib(S, st);
}

static void sf_opaque_terminate_c13_relay_modbus_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_relay_modbus_libInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_relay_modbus_lib_optimization_info();
    }

    finalize_c13_relay_modbus_lib((SFc13_relay_modbus_libInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_relay_modbus_lib((SFc13_relay_modbus_libInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_relay_modbus_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_relay_modbus_lib((SFc13_relay_modbus_libInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_relay_modbus_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_relay_modbus_lib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,13,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3509418718U));
  ssSetChecksum1(S,(3224131664U));
  ssSetChecksum2(S,(3326784779U));
  ssSetChecksum3(S,(411549263U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_relay_modbus_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_relay_modbus_lib(SimStruct *S)
{
  SFc13_relay_modbus_libInstanceStruct *chartInstance;
  chartInstance = (SFc13_relay_modbus_libInstanceStruct *)utMalloc(sizeof
    (SFc13_relay_modbus_libInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_relay_modbus_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_relay_modbus_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_relay_modbus_lib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_relay_modbus_lib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_relay_modbus_lib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_relay_modbus_lib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_relay_modbus_lib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_relay_modbus_lib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_relay_modbus_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_relay_modbus_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_relay_modbus_lib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_relay_modbus_lib;
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

void c13_relay_modbus_lib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_relay_modbus_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_relay_modbus_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_relay_modbus_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_relay_modbus_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
