#ifndef __c1_relay_ANSI_functions_lib_h__
#define __c1_relay_ANSI_functions_lib_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_s7JLMi156dXwW96IDsWdPSB
#define struct_s7JLMi156dXwW96IDsWdPSB

struct s7JLMi156dXwW96IDsWdPSB
{
  boolean_T trip27;
  boolean_T trip59;
};

#endif                                 /*struct_s7JLMi156dXwW96IDsWdPSB*/

#ifndef typedef_c1_s7JLMi156dXwW96IDsWdPSB
#define typedef_c1_s7JLMi156dXwW96IDsWdPSB

typedef struct s7JLMi156dXwW96IDsWdPSB c1_s7JLMi156dXwW96IDsWdPSB;

#endif                                 /*typedef_c1_s7JLMi156dXwW96IDsWdPSB*/

#ifndef typedef_c1_ResolvedFunctionInfo
#define typedef_c1_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c1_ResolvedFunctionInfo;

#endif                                 /*typedef_c1_ResolvedFunctionInfo*/

#ifndef typedef_SFc1_relay_ANSI_functions_libInstanceStruct
#define typedef_SFc1_relay_ANSI_functions_libInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_relay_ANSI_functions_lib;
  boolean_T c1_R50;
  boolean_T c1_R50_not_empty;
  boolean_T c1_R51;
  boolean_T c1_R51_not_empty;
  boolean_T c1_R27;
  boolean_T c1_R27_not_empty;
  boolean_T c1_R59;
  boolean_T c1_R59_not_empty;
  real_T c1_n50;
  boolean_T c1_n50_not_empty;
  real_T c1_n51;
  boolean_T c1_n51_not_empty;
  real_T c1_n27;
  boolean_T c1_n27_not_empty;
  real_T c1_n59;
  boolean_T c1_n59_not_empty;
} SFc1_relay_ANSI_functions_libInstanceStruct;

#endif                                 /*typedef_SFc1_relay_ANSI_functions_libInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_relay_ANSI_functions_lib_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_relay_ANSI_functions_lib_get_check_sum(mxArray *plhs[]);
extern void c1_relay_ANSI_functions_lib_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
