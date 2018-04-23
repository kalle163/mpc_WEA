#ifndef __c7_Simulation_der_Regler_h__
#define __c7_Simulation_der_Regler_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stdlib.h>
#ifndef typedef_SFc7_Simulation_der_ReglerInstanceStruct
#define typedef_SFc7_Simulation_der_ReglerInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_Simulation_der_Regler;
  real_T c7_P[360000];
  real_T c7_C[360000];
  real_T c7_M[60000];
  real_T c7_a[60000];
  real_T c7_b_M[60000];
  real_T c7_b[60000];
  real_T c7_c_M[60000];
  real_T c7_E[10000];
  real_T c7_b_E[10000];
  real_T c7_c_E[10000];
  real_T c7_d_E[10000];
  real_T c7_e_E[10000];
  real_T c7_f_E[10000];
  real_T c7_A[10000];
  real_T c7_y[360000];
  real_T c7_dv5[360000];
  real_T c7_u[360000];
  real_T c7_b_u[60000];
  real_T c7_b_A[10000];
  real_T (*c7_g_E)[10000];
  real_T (*c7_u_erg)[2];
  real_T (*c7_f)[100];
  real_T (*c7_d_M)[60000];
  real_T (*c7_gamma)[600];
  real_T *c7_s1;
} SFc7_Simulation_der_ReglerInstanceStruct;

#endif                                 /*typedef_SFc7_Simulation_der_ReglerInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c7_Simulation_der_Regler_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_Simulation_der_Regler_get_check_sum(mxArray *plhs[]);
extern void c7_Simulation_der_Regler_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
