#ifndef __c2_MPCRegelung1DOF1Versuch_h__
#define __c2_MPCRegelung1DOF1Versuch_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stdlib.h>
#ifndef typedef_SFc2_MPCRegelung1DOF1VersuchInstanceStruct
#define typedef_SFc2_MPCRegelung1DOF1VersuchInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_MPCRegelung1DOF1Versuch;
  real_T c2_G[10000];
  real_T c2_Rw[10000];
  real_T c2_b[10000];
  real_T c2_H[7000];
  real_T c2_a[7000];
  real_T c2_y[7000];
  real_T c2_b_b[7000];
  real_T c2_Qw[4900];
  real_T c2_b_y[4900];
  real_T c2_c_y[4900];
  real_T (*c2_F)[600];
  real_T (*c2_b_G)[10000];
  real_T (*c2_u)[2];
  real_T (*c2_b_H)[7000];
  real_T (*c2_b_Qw)[4900];
  real_T (*c2_b_Rw)[10000];
  real_T (*c2_r)[100];
  real_T (*c2_x)[6];
  real_T (*c2_BDu)[8];
  real_T *c2_v;
} SFc2_MPCRegelung1DOF1VersuchInstanceStruct;

#endif                                 /*typedef_SFc2_MPCRegelung1DOF1VersuchInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_MPCRegelung1DOF1Versuch_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_MPCRegelung1DOF1Versuch_get_check_sum(mxArray *plhs[]);
extern void c2_MPCRegelung1DOF1Versuch_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
