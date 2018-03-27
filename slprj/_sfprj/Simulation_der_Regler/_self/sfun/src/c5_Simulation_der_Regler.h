#ifndef __c5_Simulation_der_Regler_h__
#define __c5_Simulation_der_Regler_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_Simulation_der_ReglerInstanceStruct
#define typedef_SFc5_Simulation_der_ReglerInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_Simulation_der_Regler;
  real_T c5_M[20000];
  real_T c5_H[10000];
  real_T c5_G[10000];
  real_T c5_Rw[10000];
  real_T c5_Qw[10000];
  real_T c5_E[10000];
  real_T c5_C2[10000];
  real_T c5_b[10000];
  real_T c5_y[20000];
  real_T (*c5_F)[500];
  real_T (*c5_u)[2];
  real_T (*c5_b_H)[10000];
  real_T (*c5_b_G)[10000];
  real_T (*c5_Bu)[10];
  real_T *c5_C;
  real_T (*c5_b_Rw)[10000];
  real_T (*c5_b_Qw)[10000];
  real_T (*c5_ref)[100];
  real_T (*c5_dx)[5];
  real_T (*c5_b_u)[2];
  real_T *c5_dv;
  real_T (*c5_dUmin)[2];
  real_T (*c5_dUmax)[2];
  real_T (*c5_Umin)[2];
  real_T (*c5_Umax)[2];
  real_T *c5_Ymin;
  real_T *c5_Ymax;
} SFc5_Simulation_der_ReglerInstanceStruct;

#endif                                 /*typedef_SFc5_Simulation_der_ReglerInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c5_Simulation_der_Regler_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_Simulation_der_Regler_get_check_sum(mxArray *plhs[]);
extern void c5_Simulation_der_Regler_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
