/* Include files */

#include <stddef.h>
#include "blas.h"
#include "relay_ANSI_F25_lib_sfun.h"
#include "c1_relay_ANSI_F25_lib.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "relay_ANSI_F25_lib_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[10] = { "threshold", "a", "b", "c",
  "nargin", "nargout", "Vbus", "Vline", "VRMSLL", "y" };

/* Function Declarations */
static void initialize_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance);
static void initialize_params_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance);
static void enable_c1_relay_ANSI_F25_lib(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance);
static void disable_c1_relay_ANSI_F25_lib(SFc1_relay_ANSI_F25_libInstanceStruct *
  chartInstance);
static void c1_update_debugger_state_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance);
static void set_sim_state_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_relay_ANSI_F25_lib(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance);
static void sf_c1_relay_ANSI_F25_lib(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance);
static void initSimStructsc1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance);
static void registerMessagesc1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static boolean_T c1_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_y, const char_T *c1_identifier);
static boolean_T c1_b_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_relay_ANSI_F25_lib, const
  char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_relay_ANSI_F25_lib = 0U;
}

static void initialize_params_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance)
{
}

static void enable_c1_relay_ANSI_F25_lib(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_relay_ANSI_F25_lib(SFc1_relay_ANSI_F25_libInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  boolean_T c1_hoistedGlobal;
  boolean_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  boolean_T *c1_d_y;
  c1_d_y = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  c1_hoistedGlobal = *c1_d_y;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_relay_ANSI_F25_lib;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_y;
  c1_y = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "y");
  chartInstance->c1_is_active_c1_relay_ANSI_F25_lib = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_relay_ANSI_F25_lib");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_relay_ANSI_F25_lib(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_relay_ANSI_F25_lib(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance)
{
}

static void sf_c1_relay_ANSI_F25_lib(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_Vbus;
  real_T c1_Vline;
  real_T c1_VRMSLL;
  uint32_T c1_debug_family_var_map[10];
  real_T c1_threshold;
  boolean_T c1_a;
  boolean_T c1_b;
  boolean_T c1_c;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_y;
  real_T c1_x;
  boolean_T c1_b_b;
  real_T c1_b_x;
  boolean_T c1_c_b;
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_d_a;
  real_T c1_b_y;
  real_T c1_e_a;
  real_T c1_c_y;
  boolean_T c1_b0;
  real_T c1_f_a;
  real_T c1_d_y;
  real_T c1_g_a;
  real_T c1_e_y;
  boolean_T c1_b1;
  boolean_T c1_b2;
  boolean_T c1_b3;
  real_T *c1_b_Vbus;
  boolean_T *c1_f_y;
  real_T *c1_b_Vline;
  real_T *c1_b_VRMSLL;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T guard7 = FALSE;
  c1_b_VRMSLL = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_Vline = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_f_y = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Vbus = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_Vbus, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_f_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Vline, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_VRMSLL, 3U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_Vbus;
  c1_b_hoistedGlobal = *c1_b_Vline;
  c1_c_hoistedGlobal = *c1_b_VRMSLL;
  c1_Vbus = c1_hoistedGlobal;
  c1_Vline = c1_b_hoistedGlobal;
  c1_VRMSLL = c1_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_threshold, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_a, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_Vbus, 6U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_Vline, 7U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_VRMSLL, 8U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_y, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_x = c1_Vbus;
  c1_b_b = muDoubleScalarIsNaN(c1_x);
  if (CV_EML_IF(0, 1, 0, c1_b_b)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
    c1_Vbus = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
    c1_b_x = c1_Vline;
    c1_c_b = muDoubleScalarIsNaN(c1_b_x);
    if (CV_EML_IF(0, 1, 1, c1_c_b)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
      c1_Vline = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  if (CV_EML_IF(0, 1, 2, c1_VRMSLL > 400.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
    c1_b_a = c1_VRMSLL;
    c1_threshold = c1_b_a * 0.003;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
    c1_c_a = c1_VRMSLL;
    c1_threshold = c1_c_a * 0.05;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_d_a = c1_VRMSLL;
  c1_b_y = c1_d_a * 0.9;
  guard6 = FALSE;
  guard7 = FALSE;
  if (c1_Vbus > c1_b_y) {
    c1_e_a = c1_VRMSLL;
    c1_c_y = c1_e_a * 1.2;
    if (c1_Vbus < c1_c_y) {
      if (c1_Vline < c1_threshold) {
        c1_b0 = TRUE;
      } else {
        guard6 = TRUE;
      }
    } else {
      guard7 = TRUE;
    }
  } else {
    guard7 = TRUE;
  }

  if (guard7 == TRUE) {
    guard6 = TRUE;
  }

  if (guard6 == TRUE) {
    c1_b0 = FALSE;
  }

  c1_a = c1_b0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_f_a = c1_VRMSLL;
  c1_d_y = c1_f_a * 0.9;
  guard4 = FALSE;
  guard5 = FALSE;
  if (c1_Vline > c1_d_y) {
    c1_g_a = c1_VRMSLL;
    c1_e_y = c1_g_a * 1.2;
    if (c1_Vline < c1_e_y) {
      if (c1_Vbus < c1_threshold) {
        c1_b1 = TRUE;
      } else {
        guard4 = TRUE;
      }
    } else {
      guard5 = TRUE;
    }
  } else {
    guard5 = TRUE;
  }

  if (guard5 == TRUE) {
    guard4 = TRUE;
  }

  if (guard4 == TRUE) {
    c1_b1 = FALSE;
  }

  c1_b = c1_b1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  guard3 = FALSE;
  if (c1_Vline < c1_threshold) {
    if (c1_Vbus < c1_threshold) {
      c1_b2 = TRUE;
    } else {
      guard3 = TRUE;
    }
  } else {
    guard3 = TRUE;
  }

  if (guard3 == TRUE) {
    c1_b2 = FALSE;
  }

  c1_c = c1_b2;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  guard1 = FALSE;
  guard2 = FALSE;
  if (c1_a) {
    guard2 = TRUE;
  } else if (c1_b) {
    guard2 = TRUE;
  } else if (c1_c) {
    guard1 = TRUE;
  } else {
    c1_b3 = FALSE;
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c1_b3 = TRUE;
  }

  c1_y = c1_b3;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -26);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_f_y = c1_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_relay_ANSI_F25_libMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_relay_ANSI_F25_lib
  (SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_F25_libInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_y, const char_T *c1_identifier)
{
  boolean_T c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId);
  sf_mex_destroy(&c1_y);
  return c1_b_y;
}

static boolean_T c1_b_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b4;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b4, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b4;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_b_y;
  SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_F25_libInstanceStruct *)chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId);
  sf_mex_destroy(&c1_y);
  *(boolean_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_F25_libInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_F25_libInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_relay_ANSI_F25_lib_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[2];
  c1_ResolvedFunctionInfo (*c1_b_info)[2];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i0;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[2])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "isnan";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  (*c1_b_info)[0].fileTimeLo = 1286840360U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context = "";
  (*c1_b_info)[1].name = "mtimes";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[1].fileTimeLo = 1289541292U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2), FALSE);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    c1_r0 = &c1_info[c1_i0];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i0);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_F25_libInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i1, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_F25_libInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_relay_ANSI_F25_lib, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_relay_ANSI_F25_lib), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_relay_ANSI_F25_lib);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_relay_ANSI_F25_libInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_relay_ANSI_F25_libInstanceStruct
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

void sf_c1_relay_ANSI_F25_lib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4245064663U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2882785701U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4119679566U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(436497198U);
}

mxArray *sf_c1_relay_ANSI_F25_lib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WvXWNP19vPLil3DsP1HmlD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

mxArray *sf_c1_relay_ANSI_F25_lib_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_relay_ANSI_F25_lib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_relay_ANSI_F25_lib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_relay_ANSI_F25_lib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance;
    chartInstance = (SFc1_relay_ANSI_F25_libInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _relay_ANSI_F25_libMachineNumber_,
           1,
           1,
           1,
           4,
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
          init_script_number_translation(_relay_ANSI_F25_libMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_relay_ANSI_F25_libMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _relay_ANSI_F25_libMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Vbus");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Vline");
          _SFD_SET_DATA_PROPS(3,1,1,0,"VRMSLL");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",112,-1,611);
        _SFD_CV_INIT_EML_IF(0,1,0,160,174,187,206);
        _SFD_CV_INIT_EML_IF(0,1,1,187,206,-1,206);
        _SFD_CV_INIT_EML_IF(0,1,2,259,274,316,362);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_Vbus;
          boolean_T *c1_y;
          real_T *c1_Vline;
          real_T *c1_VRMSLL;
          c1_VRMSLL = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_Vline = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_y = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Vbus = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_Vbus);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_Vline);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_VRMSLL);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _relay_ANSI_F25_libMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "IfkJ69AfnGVwqu37lXvEm";
}

static void sf_opaque_initialize_c1_relay_ANSI_F25_lib(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_relay_ANSI_F25_libInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_relay_ANSI_F25_lib((SFc1_relay_ANSI_F25_libInstanceStruct*)
    chartInstanceVar);
  initialize_c1_relay_ANSI_F25_lib((SFc1_relay_ANSI_F25_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_relay_ANSI_F25_lib(void *chartInstanceVar)
{
  enable_c1_relay_ANSI_F25_lib((SFc1_relay_ANSI_F25_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_relay_ANSI_F25_lib(void *chartInstanceVar)
{
  disable_c1_relay_ANSI_F25_lib((SFc1_relay_ANSI_F25_libInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_relay_ANSI_F25_lib(void *chartInstanceVar)
{
  sf_c1_relay_ANSI_F25_lib((SFc1_relay_ANSI_F25_libInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_relay_ANSI_F25_lib(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_relay_ANSI_F25_lib
    ((SFc1_relay_ANSI_F25_libInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_relay_ANSI_F25_lib();/* state var info */
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

extern void sf_internal_set_sim_state_c1_relay_ANSI_F25_lib(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_relay_ANSI_F25_lib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_relay_ANSI_F25_lib((SFc1_relay_ANSI_F25_libInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_relay_ANSI_F25_lib(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_relay_ANSI_F25_lib(S);
}

static void sf_opaque_set_sim_state_c1_relay_ANSI_F25_lib(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_relay_ANSI_F25_lib(S, st);
}

static void sf_opaque_terminate_c1_relay_ANSI_F25_lib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_relay_ANSI_F25_libInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_relay_ANSI_F25_lib_optimization_info();
    }

    finalize_c1_relay_ANSI_F25_lib((SFc1_relay_ANSI_F25_libInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_relay_ANSI_F25_lib((SFc1_relay_ANSI_F25_libInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_relay_ANSI_F25_lib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_relay_ANSI_F25_lib
      ((SFc1_relay_ANSI_F25_libInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_relay_ANSI_F25_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_relay_ANSI_F25_lib_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1989518483U));
  ssSetChecksum1(S,(1822255290U));
  ssSetChecksum2(S,(4021513024U));
  ssSetChecksum3(S,(1860269503U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_relay_ANSI_F25_lib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_relay_ANSI_F25_lib(SimStruct *S)
{
  SFc1_relay_ANSI_F25_libInstanceStruct *chartInstance;
  chartInstance = (SFc1_relay_ANSI_F25_libInstanceStruct *)utMalloc(sizeof
    (SFc1_relay_ANSI_F25_libInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_relay_ANSI_F25_libInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_relay_ANSI_F25_lib;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_relay_ANSI_F25_lib;
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

void c1_relay_ANSI_F25_lib_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_relay_ANSI_F25_lib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_relay_ANSI_F25_lib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_relay_ANSI_F25_lib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_relay_ANSI_F25_lib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
