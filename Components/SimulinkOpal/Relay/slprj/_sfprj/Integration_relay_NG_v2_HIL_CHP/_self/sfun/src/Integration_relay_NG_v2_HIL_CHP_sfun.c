/* Include files */

#include "Integration_relay_NG_v2_HIL_CHP_sfun.h"
#include "Integration_relay_NG_v2_HIL_CHP_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Integration_relay_NG_v2_HIL_CHPMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Integration_relay_NG_v2_HIL_CHP_initializer(void)
{
}

void Integration_relay_NG_v2_HIL_CHP_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Integration_relay_NG_v2_HIL_CHP_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  return 0;
}

unsigned int sf_Integration_relay_NG_v2_HIL_CHP_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(839325407U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2027632108U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1191325560U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4028087317U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1466817249U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1441414167U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3167978563U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(488440259U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3671716505U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(761638822U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(966005375U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2739926485U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1151396223U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(142676203U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1557597785U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2148225855U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Integration_relay_NG_v2_HIL_CHP_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Integration_relay_NG_v2_HIL_CHP_get_eml_resolved_functions_info(
  int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Integration_relay_NG_v2_HIL_CHP_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Integration_relay_NG_v2_HIL_CHP_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _Integration_relay_NG_v2_HIL_CHPMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"Integration_relay_NG_v2_HIL_CHP","sfun",0,0,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Integration_relay_NG_v2_HIL_CHPMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Integration_relay_NG_v2_HIL_CHPMachineNumber_,0);
}

void Integration_relay_NG_v2_HIL_CHP_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Integration_relay_NG_v2_HIL_CHP_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Integration_relay_NG_v2_HIL_CHP", "Integration_relay_NG_v2_HIL_CHP");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Integration_relay_NG_v2_HIL_CHP_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
