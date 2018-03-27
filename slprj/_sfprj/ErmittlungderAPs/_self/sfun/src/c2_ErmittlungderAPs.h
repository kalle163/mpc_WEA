#ifndef __c2_ErmittlungderAPs_h__
#define __c2_ErmittlungderAPs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_ErmittlungderAPsInstanceStruct
#define typedef_SFc2_ErmittlungderAPsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_ErmittlungderAPs;
  real_T *c2_wr;
  real_T *c2_Mr;
  real_T *c2_R;
  real_T (*c2_c)[12];
  real_T *c2_v_c;
  real_T *c2_theta_c;
  real_T *c2_rho;
  real_T *c2_n_g_inv;
} SFc2_ErmittlungderAPsInstanceStruct;

#endif                                 /*typedef_SFc2_ErmittlungderAPsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_ErmittlungderAPs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_ErmittlungderAPs_get_check_sum(mxArray *plhs[]);
extern void c2_ErmittlungderAPs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
