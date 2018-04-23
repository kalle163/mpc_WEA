/* Include files */

#include "Simulation_der_Regler_sfun.h"
#include "c7_Simulation_der_Regler.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Simulation_der_Regler_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c7_debug_family_names[24] = { "n1", "m1", "u", "kk", "i",
  "P", "d", "n", "m", "x_ini", "lambda", "al", "km", "lambda_p", "w", "la",
  "nargin", "nargout", "E", "f", "M", "gamma", "s1", "u_erg" };

/* Function Declarations */
static void initialize_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void initialize_params_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void enable_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void disable_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void set_sim_state_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance, const mxArray *c7_st);
static void finalize_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void sf_gateway_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void mdl_start_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void c7_chartstep_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void initSimStructsc7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static void c7_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_b_u_erg, const char_T *c7_identifier, real_T
  c7_b_y[2]);
static void c7_b_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[2]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_d_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[600]);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_g_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_e_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[360000]);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_f_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[100]);
static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_mldivide(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[100], real_T c7_Y[100]);
static void c7_xgetrf(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
                      real_T c7_c_A[10000], real_T c7_d_A[10000], int32_T
                      c7_ipiv[100], int32_T *c7_info);
static void c7_error(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void c7_b_error(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  int32_T c7_varargin_2);
static void c7_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void c7_dimagree(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void c7_b_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_c_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_warning(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance);
static void c7_d_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
                     real_T c7_c_A[10000], real_T c7_B[100], real_T c7_b_B[100]);
static void c7_below_threshold(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_e_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_b_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[100], real_T c7_b_B[100]);
static void c7_f_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_b_mldivide(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, real_T c7_c_A[10000], real_T c7_B[60000], real_T c7_Y[60000]);
static void c7_g_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_c_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[60000], real_T c7_b_B[60000]);
static void c7_b_below_threshold(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_h_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_d_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[60000], real_T c7_b_B[60000]);
static void c7_i_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_j_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_k_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_l_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_m_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_n_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static real_T c7_xdot(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
                      real_T c7_x[600], real_T c7_b_y[600]);
static void c7_o_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c7_p_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static const mxArray *c7_h_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_g_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_h_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_Simulation_der_Regler, const
  char_T *c7_identifier);
static uint8_T c7_i_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_xgetrf(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], int32_T c7_ipiv[100], int32_T *c7_info);
static void c7_e_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[100]);
static void c7_f_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[100]);
static void c7_g_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[60000]);
static void c7_h_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[60000]);
static void init_dsm_address_info(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc7_Simulation_der_Regler(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_is_active_c7_Simulation_der_Regler = 0U;
}

static void initialize_params_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_b_y = NULL;
  const mxArray *c7_c_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_createcellmatrix(2, 1), false);
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", *chartInstance->c7_u_erg, 0, 0U, 1U,
    0U, 1, 2), false);
  sf_mex_setcell(c7_b_y, 0, c7_c_y);
  c7_hoistedGlobal = chartInstance->c7_is_active_c7_Simulation_der_Regler;
  c7_c_u = c7_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_b_y, 1, c7_d_y);
  sf_mex_assign(&c7_st, c7_b_y, false);
  return c7_st;
}

static void set_sim_state_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_c_u;
  real_T c7_dv0[2];
  int32_T c7_i0;
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_c_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("u_erg", c7_c_u,
    0)), "u_erg", c7_dv0);
  for (c7_i0 = 0; c7_i0 < 2; c7_i0++) {
    (*chartInstance->c7_u_erg)[c7_i0] = c7_dv0[c7_i0];
  }

  chartInstance->c7_is_active_c7_Simulation_der_Regler = c7_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c7_Simulation_der_Regler", c7_c_u, 1)),
     "is_active_c7_Simulation_der_Regler");
  sf_mex_destroy(&c7_c_u);
  c7_update_debugger_state_c7_Simulation_der_Regler(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  int32_T c7_i1;
  int32_T c7_i2;
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_s1, 4U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  for (c7_i1 = 0; c7_i1 < 600; c7_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c7_gamma)[c7_i1], 3U, 1U, 0U,
                          chartInstance->c7_sfEvent, false);
  }

  for (c7_i2 = 0; c7_i2 < 60000; c7_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c7_d_M)[c7_i2], 2U, 1U, 0U,
                          chartInstance->c7_sfEvent, false);
  }

  for (c7_i3 = 0; c7_i3 < 100; c7_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c7_f)[c7_i3], 1U, 1U, 0U,
                          chartInstance->c7_sfEvent, false);
  }

  for (c7_i4 = 0; c7_i4 < 10000; c7_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c7_g_E)[c7_i4], 0U, 1U, 0U,
                          chartInstance->c7_sfEvent, false);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  c7_chartstep_c7_Simulation_der_Regler(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Simulation_der_ReglerMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c7_i5 = 0; c7_i5 < 2; c7_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c7_u_erg)[c7_i5], 5U, 1U, 0U,
                          chartInstance->c7_sfEvent, false);
  }
}

static void mdl_start_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_chartstep_c7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  real_T c7_hoistedGlobal;
  int32_T c7_i6;
  int32_T c7_i7;
  int32_T c7_i8;
  real_T c7_b_f[100];
  int32_T c7_i9;
  real_T c7_b_s1;
  real_T c7_b_gamma[600];
  uint32_T c7_debug_family_var_map[24];
  real_T c7_n1;
  real_T c7_m1;
  real_T c7_c_u[100];
  real_T c7_kk;
  real_T c7_i;
  real_T c7_d[600];
  real_T c7_n;
  real_T c7_m;
  real_T c7_x_ini[600];
  real_T c7_lambda[600];
  real_T c7_al;
  real_T c7_km;
  real_T c7_lambda_p[600];
  real_T c7_w;
  real_T c7_la;
  real_T c7_nargin = 5.0;
  real_T c7_nargout = 1.0;
  real_T c7_b_u_erg[2];
  int32_T c7_i10;
  int32_T c7_i11;
  real_T c7_c_f[100];
  real_T c7_dv1[100];
  int32_T c7_i12;
  int32_T c7_b_i;
  int32_T c7_c_i;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  real_T c7_b_a[100];
  int32_T c7_i18;
  real_T c7_d0;
  real_T c7_b_b[100];
  int32_T c7_i19;
  int32_T c7_i20;
  int32_T c7_k;
  int32_T c7_i21;
  real_T c7_d1;
  int32_T c7_b_k;
  int32_T c7_i22;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  real_T c7_alpha1;
  real_T c7_beta1;
  int32_T c7_i26;
  char_T c7_TRANSB;
  char_T c7_TRANSA;
  int32_T c7_i27;
  ptrdiff_t c7_m_t;
  ptrdiff_t c7_n_t;
  ptrdiff_t c7_k_t;
  ptrdiff_t c7_lda_t;
  ptrdiff_t c7_ldb_t;
  ptrdiff_t c7_ldc_t;
  int32_T c7_i28;
  int32_T c7_i29;
  int32_T c7_i30;
  real_T c7_d_f[100];
  real_T c7_b_alpha1;
  real_T c7_b_beta1;
  char_T c7_b_TRANSB;
  char_T c7_b_TRANSA;
  int32_T c7_i31;
  ptrdiff_t c7_b_m_t;
  real_T c7_b_y[600];
  ptrdiff_t c7_b_n_t;
  ptrdiff_t c7_b_k_t;
  ptrdiff_t c7_b_lda_t;
  ptrdiff_t c7_b_ldb_t;
  ptrdiff_t c7_b_ldc_t;
  int32_T c7_i32;
  int32_T c7_i33;
  int32_T c7_i34;
  int32_T c7_b_km;
  int32_T c7_i35;
  int32_T c7_i36;
  int32_T c7_i37;
  int32_T c7_i38;
  int32_T c7_d_i;
  int32_T c7_i39;
  int32_T c7_i40;
  int32_T c7_i41;
  int32_T c7_i42;
  real_T c7_c_alpha1;
  int32_T c7_e_i;
  real_T c7_c_beta1;
  int32_T c7_i43;
  char_T c7_c_TRANSB;
  int32_T c7_i44;
  real_T c7_c_a[600];
  char_T c7_c_TRANSA;
  int32_T c7_i45;
  int32_T c7_i46;
  ptrdiff_t c7_c_m_t;
  real_T c7_c_y;
  ptrdiff_t c7_c_n_t;
  ptrdiff_t c7_c_k_t;
  ptrdiff_t c7_c_lda_t;
  ptrdiff_t c7_c_ldb_t;
  ptrdiff_t c7_c_ldc_t;
  real_T c7_c_A;
  real_T c7_B;
  int32_T c7_i47;
  real_T c7_x;
  real_T c7_d_y;
  real_T c7_b_x;
  int32_T c7_i48;
  real_T c7_e_y;
  real_T c7_e_f[100];
  real_T c7_dv2[100];
  real_T c7_varargin_2;
  int32_T c7_i49;
  real_T c7_varargin_3;
  real_T c7_f_y;
  real_T c7_g_y;
  real_T c7_h_y;
  int32_T c7_i50;
  real_T c7_maxval;
  int32_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *chartInstance->c7_s1;
  for (c7_i6 = 0; c7_i6 < 10000; c7_i6++) {
    chartInstance->c7_E[c7_i6] = (*chartInstance->c7_g_E)[c7_i6];
  }

  for (c7_i7 = 0; c7_i7 < 100; c7_i7++) {
    c7_b_f[c7_i7] = (*chartInstance->c7_f)[c7_i7];
  }

  for (c7_i8 = 0; c7_i8 < 60000; c7_i8++) {
    chartInstance->c7_M[c7_i8] = (*chartInstance->c7_d_M)[c7_i8];
  }

  for (c7_i9 = 0; c7_i9 < 600; c7_i9++) {
    c7_b_gamma[c7_i9] = (*chartInstance->c7_gamma)[c7_i9];
  }

  c7_b_s1 = c7_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_n1, 0U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_m1, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_c_u, 2U, c7_e_sf_marshallOut,
    c7_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_kk, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_i, 4U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c7_P, 5U,
    c7_g_sf_marshallOut, c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_d, 6U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_n, 7U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_m, 8U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_x_ini, 9U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_lambda, 10U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_al, 11U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_km, 12U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_lambda_p, 13U, c7_c_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_w, 14U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_la, 15U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 16U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 17U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c7_E, 18U, c7_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_b_f, 19U, c7_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c7_M, 20U, c7_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_b_gamma, 21U, c7_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_s1, 22U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_b_u_erg, 23U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_n1 = 600.0;
  c7_m1 = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
  for (c7_i10 = 0; c7_i10 < 10000; c7_i10++) {
    chartInstance->c7_b_E[c7_i10] = -chartInstance->c7_E[c7_i10];
  }

  for (c7_i11 = 0; c7_i11 < 100; c7_i11++) {
    c7_c_f[c7_i11] = c7_b_f[c7_i11];
  }

  c7_mldivide(chartInstance, chartInstance->c7_b_E, c7_c_f, c7_dv1);
  for (c7_i12 = 0; c7_i12 < 100; c7_i12++) {
    c7_c_u[c7_i12] = c7_dv1[c7_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 6);
  c7_kk = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_i = 1.0;
  c7_b_i = 0;
  while (c7_b_i < 600) {
    c7_i = 1.0 + (real_T)c7_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 8);
    c7_c_i = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 220, 1, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 220U, 1U, c7_i), 1, 600) - 1;
    for (c7_i15 = 0; c7_i15 < 100; c7_i15++) {
      c7_b_a[c7_i15] = chartInstance->c7_M[c7_c_i + 600 * c7_i15];
    }

    for (c7_i17 = 0; c7_i17 < 100; c7_i17++) {
      c7_b_b[c7_i17] = c7_c_u[c7_i17];
    }

    c7_d0 = 0.0;
    for (c7_k = 1; c7_k < 101; c7_k++) {
      c7_b_k = c7_k - 1;
      c7_d0 += c7_b_a[c7_b_k] * c7_b_b[c7_b_k];
    }

    c7_d1 = c7_b_gamma[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 227, 8, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 227U, 8U, c7_i), 1, 600) - 1];
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c7_d0, c7_d1, -1, 4U,
          c7_d0 > c7_d1))) {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
      c7_kk++;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 11);
    }

    c7_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c7_kk, 0.0, -1, 0U, c7_kk
        == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
    for (c7_i14 = 0; c7_i14 < 2; c7_i14++) {
      c7_b_u_erg[c7_i14] = c7_c_u[c7_i14];
    }

    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 18);
    for (c7_i13 = 0; c7_i13 < 60000; c7_i13++) {
      chartInstance->c7_a[c7_i13] = chartInstance->c7_M[c7_i13];
    }

    for (c7_i16 = 0; c7_i16 < 10000; c7_i16++) {
      chartInstance->c7_c_E[c7_i16] = chartInstance->c7_E[c7_i16];
    }

    c7_i18 = 0;
    for (c7_i19 = 0; c7_i19 < 600; c7_i19++) {
      c7_i21 = 0;
      for (c7_i23 = 0; c7_i23 < 100; c7_i23++) {
        chartInstance->c7_b_M[c7_i23 + c7_i18] = chartInstance->c7_M[c7_i21 +
          c7_i19];
        c7_i21 += 600;
      }

      c7_i18 += 100;
    }

    c7_b_mldivide(chartInstance, chartInstance->c7_c_E, chartInstance->c7_b_M,
                  chartInstance->c7_b);
    for (c7_i22 = 0; c7_i22 < 360000; c7_i22++) {
      chartInstance->c7_P[c7_i22] = 0.0;
    }

    for (c7_i24 = 0; c7_i24 < 360000; c7_i24++) {
      chartInstance->c7_C[c7_i24] = chartInstance->c7_P[c7_i24];
    }

    for (c7_i25 = 0; c7_i25 < 360000; c7_i25++) {
      chartInstance->c7_P[c7_i25] = chartInstance->c7_C[c7_i25];
    }

    c7_alpha1 = 1.0;
    c7_beta1 = 0.0;
    for (c7_i26 = 0; c7_i26 < 360000; c7_i26++) {
      chartInstance->c7_C[c7_i26] = chartInstance->c7_P[c7_i26];
    }

    c7_TRANSB = 'N';
    c7_TRANSA = 'N';
    for (c7_i27 = 0; c7_i27 < 360000; c7_i27++) {
      chartInstance->c7_P[c7_i27] = chartInstance->c7_C[c7_i27];
    }

    c7_m_t = (ptrdiff_t)600;
    c7_n_t = (ptrdiff_t)600;
    c7_k_t = (ptrdiff_t)100;
    c7_lda_t = (ptrdiff_t)600;
    c7_ldb_t = (ptrdiff_t)100;
    c7_ldc_t = (ptrdiff_t)600;
    dgemm(&c7_TRANSA, &c7_TRANSB, &c7_m_t, &c7_n_t, &c7_k_t, &c7_alpha1,
          &chartInstance->c7_a[0], &c7_lda_t, &chartInstance->c7_b[0], &c7_ldb_t,
          &c7_beta1, &chartInstance->c7_P[0], &c7_ldc_t);
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 19);
    for (c7_i28 = 0; c7_i28 < 60000; c7_i28++) {
      chartInstance->c7_a[c7_i28] = chartInstance->c7_M[c7_i28];
    }

    for (c7_i29 = 0; c7_i29 < 10000; c7_i29++) {
      chartInstance->c7_d_E[c7_i29] = chartInstance->c7_E[c7_i29];
    }

    for (c7_i30 = 0; c7_i30 < 100; c7_i30++) {
      c7_d_f[c7_i30] = c7_b_f[c7_i30];
    }

    c7_mldivide(chartInstance, chartInstance->c7_d_E, c7_d_f, c7_b_b);
    c7_b_alpha1 = 1.0;
    c7_b_beta1 = 0.0;
    c7_b_TRANSB = 'N';
    c7_b_TRANSA = 'N';
    for (c7_i31 = 0; c7_i31 < 600; c7_i31++) {
      c7_b_y[c7_i31] = 0.0;
    }

    c7_b_m_t = (ptrdiff_t)600;
    c7_b_n_t = (ptrdiff_t)1;
    c7_b_k_t = (ptrdiff_t)100;
    c7_b_lda_t = (ptrdiff_t)600;
    c7_b_ldb_t = (ptrdiff_t)100;
    c7_b_ldc_t = (ptrdiff_t)600;
    dgemm(&c7_b_TRANSA, &c7_b_TRANSB, &c7_b_m_t, &c7_b_n_t, &c7_b_k_t,
          &c7_b_alpha1, &chartInstance->c7_a[0], &c7_b_lda_t, &c7_b_b[0],
          &c7_b_ldb_t, &c7_b_beta1, &c7_b_y[0], &c7_b_ldc_t);
    for (c7_i32 = 0; c7_i32 < 600; c7_i32++) {
      c7_d[c7_i32] = c7_b_y[c7_i32] + c7_b_gamma[c7_i32];
    }

    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 20);
    c7_n = 600.0;
    c7_m = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 21);
    for (c7_i33 = 0; c7_i33 < 600; c7_i33++) {
      c7_x_ini[c7_i33] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 22);
    for (c7_i34 = 0; c7_i34 < 600; c7_i34++) {
      c7_lambda[c7_i34] = c7_x_ini[c7_i34];
    }

    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 23);
    c7_al = 10.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 24);
    c7_km = 1.0;
    c7_b_km = 0;
    do {
      exitg1 = 0;
      if (c7_b_km < 38) {
        c7_km = 1.0 + (real_T)c7_b_km;
        CV_EML_FOR(0, 1, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 25);
        for (c7_i36 = 0; c7_i36 < 600; c7_i36++) {
          c7_lambda_p[c7_i36] = c7_lambda[c7_i36];
        }

        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 26);
        c7_i = 1.0;
        c7_d_i = 0;
        while (c7_d_i < 600) {
          c7_i = 1.0 + (real_T)c7_d_i;
          CV_EML_FOR(0, 1, 2, 1);
          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 27);
          c7_e_i = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 483, 1, MAX_uint32_T, (int32_T)
            sf_integer_check(chartInstance->S, 1U, 483U, 1U, c7_i), 1, 600) - 1;
          for (c7_i43 = 0; c7_i43 < 600; c7_i43++) {
            c7_c_a[c7_i43] = chartInstance->c7_P[c7_e_i + 600 * c7_i43];
          }

          for (c7_i46 = 0; c7_i46 < 600; c7_i46++) {
            c7_b_y[c7_i46] = c7_lambda[c7_i46];
          }

          c7_c_y = c7_xdot(chartInstance, c7_c_a, c7_b_y);
          c7_w = c7_c_y - chartInstance->c7_P[(sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 497, 1,
             MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 497U,
            1U, c7_i), 1, 600) + 600 * (sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 499, 1,
             MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 499U,
            1U, c7_i), 1, 600) - 1)) - 1] * c7_lambda[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 509, 1,
             MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 509U,
              1U, c7_i), 1, 600) - 1];
          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 28);
          c7_w += c7_d[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 529, 1, MAX_uint32_T, (int32_T)
            sf_integer_check(chartInstance->S, 1U, 529U, 1U, c7_i), 1, 600) - 1];
          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 29);
          c7_c_A = -c7_w;
          c7_B = chartInstance->c7_P[(sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 551, 1,
             MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 551U,
            1U, c7_i), 1, 600) + 600 * (sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 553, 1,
             MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 553U,
            1U, c7_i), 1, 600) - 1)) - 1];
          c7_x = c7_c_A;
          c7_d_y = c7_B;
          c7_b_x = c7_x;
          c7_e_y = c7_d_y;
          c7_la = c7_b_x / c7_e_y;
          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 30);
          c7_varargin_2 = c7_la;
          c7_varargin_3 = c7_varargin_2;
          c7_f_y = c7_varargin_3;
          c7_g_y = c7_f_y;
          c7_h_y = c7_g_y;
          c7_maxval = muDoubleScalarMax(0.0, c7_h_y);
          c7_lambda[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 572, 1, MAX_uint32_T, (int32_T)
            sf_integer_check(chartInstance->S, 1U, 572U, 1U, c7_i), 1, 600) - 1]
            = c7_maxval;
          c7_d_i++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        CV_EML_FOR(0, 1, 2, 0);
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 32);
        for (c7_i42 = 0; c7_i42 < 600; c7_i42++) {
          c7_c_a[c7_i42] = c7_lambda[c7_i42] - c7_lambda_p[c7_i42];
        }

        for (c7_i44 = 0; c7_i44 < 600; c7_i44++) {
          c7_b_y[c7_i44] = c7_lambda[c7_i44] - c7_lambda_p[c7_i44];
        }

        c7_al = c7_xdot(chartInstance, c7_c_a, c7_b_y);
        _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 33);
        if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c7_al, 1.0E-7, -1,
              2U, c7_al < 1.0E-7))) {
          _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 34);
          exitg1 = 1;
        } else {
          c7_b_km++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }
      } else {
        CV_EML_FOR(0, 1, 1, 0);
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 37);
    for (c7_i35 = 0; c7_i35 < 10000; c7_i35++) {
      chartInstance->c7_e_E[c7_i35] = chartInstance->c7_E[c7_i35];
    }

    c7_i37 = 0;
    for (c7_i38 = 0; c7_i38 < 600; c7_i38++) {
      c7_i39 = 0;
      for (c7_i41 = 0; c7_i41 < 100; c7_i41++) {
        chartInstance->c7_c_M[c7_i41 + c7_i37] = chartInstance->c7_M[c7_i39 +
          c7_i38];
        c7_i39 += 600;
      }

      c7_i37 += 100;
    }

    c7_b_mldivide(chartInstance, chartInstance->c7_e_E, chartInstance->c7_c_M,
                  chartInstance->c7_b);
    for (c7_i40 = 0; c7_i40 < 600; c7_i40++) {
      c7_b_y[c7_i40] = c7_lambda[c7_i40];
    }

    c7_c_alpha1 = 1.0;
    c7_c_beta1 = 0.0;
    c7_c_TRANSB = 'N';
    c7_c_TRANSA = 'N';
    for (c7_i45 = 0; c7_i45 < 100; c7_i45++) {
      c7_b_b[c7_i45] = 0.0;
    }

    c7_c_m_t = (ptrdiff_t)100;
    c7_c_n_t = (ptrdiff_t)1;
    c7_c_k_t = (ptrdiff_t)600;
    c7_c_lda_t = (ptrdiff_t)100;
    c7_c_ldb_t = (ptrdiff_t)600;
    c7_c_ldc_t = (ptrdiff_t)100;
    dgemm(&c7_c_TRANSA, &c7_c_TRANSB, &c7_c_m_t, &c7_c_n_t, &c7_c_k_t,
          &c7_c_alpha1, &chartInstance->c7_b[0], &c7_c_lda_t, &c7_b_y[0],
          &c7_c_ldb_t, &c7_c_beta1, &c7_b_b[0], &c7_c_ldc_t);
    for (c7_i47 = 0; c7_i47 < 10000; c7_i47++) {
      chartInstance->c7_f_E[c7_i47] = -chartInstance->c7_E[c7_i47];
    }

    for (c7_i48 = 0; c7_i48 < 100; c7_i48++) {
      c7_e_f[c7_i48] = c7_b_f[c7_i48];
    }

    c7_mldivide(chartInstance, chartInstance->c7_f_E, c7_e_f, c7_dv2);
    for (c7_i49 = 0; c7_i49 < 100; c7_i49++) {
      c7_c_u[c7_i49] = c7_dv2[c7_i49] - c7_b_b[c7_i49];
    }

    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 38);
    for (c7_i50 = 0; c7_i50 < 2; c7_i50++) {
      c7_b_u_erg[c7_i50] = c7_c_u[c7_i50];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
  for (c7_i20 = 0; c7_i20 < 2; c7_i20++) {
    (*chartInstance->c7_u_erg)[c7_i20] = c7_b_u_erg[c7_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c7_sfEvent);
}

static void initSimStructsc7_Simulation_der_Regler
  (SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i51;
  const mxArray *c7_b_y = NULL;
  real_T c7_c_u[2];
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i51 = 0; c7_i51 < 2; c7_i51++) {
    c7_c_u[c7_i51] = (*(real_T (*)[2])c7_inData)[c7_i51];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_b_u_erg, const char_T *c7_identifier, real_T
  c7_b_y[2])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_u_erg), &c7_thisId,
                        c7_b_y);
  sf_mex_destroy(&c7_b_u_erg);
}

static void c7_b_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[2])
{
  real_T c7_dv3[2];
  int32_T c7_i52;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_c_u), c7_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c7_i52 = 0; c7_i52 < 2; c7_i52++) {
    c7_b_y[c7_i52] = c7_dv3[c7_i52];
  }

  sf_mex_destroy(&c7_c_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_u_erg;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_b_y[2];
  int32_T c7_i53;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_b_u_erg = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_u_erg), &c7_thisId,
                        c7_b_y);
  sf_mex_destroy(&c7_b_u_erg);
  for (c7_i53 = 0; c7_i53 < 2; c7_i53++) {
    (*(real_T (*)[2])c7_outData)[c7_i53] = c7_b_y[c7_i53];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_c_u;
  const mxArray *c7_b_y = NULL;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_c_u = *(real_T *)c7_inData;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i54;
  const mxArray *c7_b_y = NULL;
  real_T c7_c_u[600];
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i54 = 0; c7_i54 < 600; c7_i54++) {
    c7_c_u[c7_i54] = (*(real_T (*)[600])c7_inData)[c7_i54];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 600),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i55;
  int32_T c7_i56;
  const mxArray *c7_b_y = NULL;
  int32_T c7_i57;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i55 = 0;
  for (c7_i56 = 0; c7_i56 < 100; c7_i56++) {
    for (c7_i57 = 0; c7_i57 < 600; c7_i57++) {
      chartInstance->c7_b_u[c7_i57 + c7_i55] = (*(real_T (*)[60000])c7_inData)
        [c7_i57 + c7_i55];
    }

    c7_i55 += 600;
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", chartInstance->c7_b_u, 0, 0U, 1U, 0U,
    2, 600, 100), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i58;
  const mxArray *c7_b_y = NULL;
  real_T c7_c_u[100];
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i58 = 0; c7_i58 < 100; c7_i58++) {
    c7_c_u[c7_i58] = (*(real_T (*)[100])c7_inData)[c7_i58];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 100),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i59;
  int32_T c7_i60;
  const mxArray *c7_b_y = NULL;
  int32_T c7_i61;
  real_T c7_c_u[10000];
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i59 = 0;
  for (c7_i60 = 0; c7_i60 < 100; c7_i60++) {
    for (c7_i61 = 0; c7_i61 < 100; c7_i61++) {
      c7_c_u[c7_i61 + c7_i59] = (*(real_T (*)[10000])c7_inData)[c7_i61 + c7_i59];
    }

    c7_i59 += 100;
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 2, 100, 100),
                false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_b_y;
  real_T c7_d2;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_c_u), &c7_d2, 1, 0, 0U, 0, 0U, 0);
  c7_b_y = c7_d2;
  sf_mex_destroy(&c7_c_u);
  return c7_b_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_b_y;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout),
    &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_b_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static void c7_d_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[600])
{
  real_T c7_dv4[600];
  int32_T c7_i62;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_c_u), c7_dv4, 1, 0, 0U, 1, 0U, 1, 600);
  for (c7_i62 = 0; c7_i62 < 600; c7_i62++) {
    c7_b_y[c7_i62] = c7_dv4[c7_i62];
  }

  sf_mex_destroy(&c7_c_u);
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_lambda_p;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_b_y[600];
  int32_T c7_i63;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_lambda_p = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_lambda_p), &c7_thisId,
                        c7_b_y);
  sf_mex_destroy(&c7_lambda_p);
  for (c7_i63 = 0; c7_i63 < 600; c7_i63++) {
    (*(real_T (*)[600])c7_outData)[c7_i63] = c7_b_y[c7_i63];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_g_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i64;
  int32_T c7_i65;
  const mxArray *c7_b_y = NULL;
  int32_T c7_i66;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i64 = 0;
  for (c7_i65 = 0; c7_i65 < 600; c7_i65++) {
    for (c7_i66 = 0; c7_i66 < 600; c7_i66++) {
      chartInstance->c7_u[c7_i66 + c7_i64] = (*(real_T (*)[360000])c7_inData)
        [c7_i66 + c7_i64];
    }

    c7_i64 += 600;
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", chartInstance->c7_u, 0, 0U, 1U, 0U,
    2, 600, 600), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static void c7_e_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[360000])
{
  int32_T c7_i67;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_c_u), chartInstance->c7_dv5, 1, 0, 0U,
                1, 0U, 2, 600, 600);
  for (c7_i67 = 0; c7_i67 < 360000; c7_i67++) {
    c7_b_y[c7_i67] = chartInstance->c7_dv5[c7_i67];
  }

  sf_mex_destroy(&c7_c_u);
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_P;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_i68;
  int32_T c7_i69;
  int32_T c7_i70;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_b_P = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_P), &c7_thisId,
                        chartInstance->c7_y);
  sf_mex_destroy(&c7_b_P);
  c7_i68 = 0;
  for (c7_i69 = 0; c7_i69 < 600; c7_i69++) {
    for (c7_i70 = 0; c7_i70 < 600; c7_i70++) {
      (*(real_T (*)[360000])c7_outData)[c7_i70 + c7_i68] = chartInstance->
        c7_y[c7_i70 + c7_i68];
    }

    c7_i68 += 600;
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static void c7_f_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_b_y[100])
{
  real_T c7_dv6[100];
  int32_T c7_i71;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_c_u), c7_dv6, 1, 0, 0U, 1, 0U, 1, 100);
  for (c7_i71 = 0; c7_i71 < 100; c7_i71++) {
    c7_b_y[c7_i71] = c7_dv6[c7_i71];
  }

  sf_mex_destroy(&c7_c_u);
}

static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_c_u;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_b_y[100];
  int32_T c7_i72;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_c_u = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_c_u), &c7_thisId, c7_b_y);
  sf_mex_destroy(&c7_c_u);
  for (c7_i72 = 0; c7_i72 < 100; c7_i72++) {
    (*(real_T (*)[100])c7_outData)[c7_i72] = c7_b_y[c7_i72];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_Simulation_der_Regler_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static void c7_mldivide(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[100], real_T c7_Y[100])
{
  int32_T c7_i73;
  int32_T c7_ipiv[100];
  int32_T c7_info;
  int32_T c7_b_info;
  int32_T c7_i74;
  int32_T c7_xi;
  int32_T c7_i75;
  int32_T c7_b_xi;
  int32_T c7_ip;
  real_T c7_d_A[10000];
  real_T c7_temp;
  for (c7_i73 = 0; c7_i73 < 10000; c7_i73++) {
    chartInstance->c7_b_A[c7_i73] = c7_c_A[c7_i73];
  }

  c7_b_xgetrf(chartInstance, chartInstance->c7_b_A, c7_ipiv, &c7_info);
  c7_b_info = c7_info;
  if ((real_T)c7_b_info > 0.0) {
    c7_warning(chartInstance);
  }

  for (c7_i74 = 0; c7_i74 < 100; c7_i74++) {
    c7_Y[c7_i74] = c7_B[c7_i74];
  }

  for (c7_xi = 1; c7_xi < 100; c7_xi++) {
    c7_b_xi = c7_xi - 1;
    if (c7_ipiv[c7_b_xi] != c7_b_xi + 1) {
      c7_ip = c7_ipiv[c7_b_xi] - 1;
      c7_temp = c7_Y[c7_b_xi];
      c7_Y[c7_b_xi] = c7_Y[c7_ip];
      c7_Y[c7_ip] = c7_temp;
    }
  }

  for (c7_i75 = 0; c7_i75 < 10000; c7_i75++) {
    c7_d_A[c7_i75] = chartInstance->c7_b_A[c7_i75];
  }

  c7_e_xtrsm(chartInstance, c7_d_A, c7_Y);
  c7_f_xtrsm(chartInstance, chartInstance->c7_b_A, c7_Y);
}

static void c7_xgetrf(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
                      real_T c7_c_A[10000], real_T c7_d_A[10000], int32_T
                      c7_ipiv[100], int32_T *c7_info)
{
  int32_T c7_i76;
  for (c7_i76 = 0; c7_i76 < 10000; c7_i76++) {
    c7_d_A[c7_i76] = c7_c_A[c7_i76];
  }

  c7_b_xgetrf(chartInstance, c7_d_A, c7_ipiv, c7_info);
}

static void c7_error(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  const mxArray *c7_b_y = NULL;
  static char_T c7_c_u[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  (void)chartInstance;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c7_b_y));
}

static void c7_b_error(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  int32_T c7_varargin_2)
{
  const mxArray *c7_b_y = NULL;
  static char_T c7_c_u[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c7_c_y = NULL;
  static char_T c7_d_u[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  int32_T c7_e_u;
  const mxArray *c7_d_y = NULL;
  (void)chartInstance;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_d_u, 10, 0U, 1U, 0U, 2, 1, 19),
                false);
  c7_e_u = c7_varargin_2;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c7_b_y, 14, c7_c_y, 14, c7_d_y));
}

static void c7_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_dimagree(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c7_b_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_c_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_warning(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  const mxArray *c7_b_y = NULL;
  static char_T c7_c_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c7_c_y = NULL;
  static char_T c7_d_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c7_d_y = NULL;
  static char_T c7_msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  (void)chartInstance;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", c7_d_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", c7_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c7_b_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c7_c_y, 14, c7_d_y));
}

static void c7_d_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
                     real_T c7_c_A[10000], real_T c7_B[100], real_T c7_b_B[100])
{
  int32_T c7_i77;
  int32_T c7_i78;
  real_T c7_d_A[10000];
  for (c7_i77 = 0; c7_i77 < 100; c7_i77++) {
    c7_b_B[c7_i77] = c7_B[c7_i77];
  }

  for (c7_i78 = 0; c7_i78 < 10000; c7_i78++) {
    c7_d_A[c7_i78] = c7_c_A[c7_i78];
  }

  c7_e_xtrsm(chartInstance, c7_d_A, c7_b_B);
}

static void c7_below_threshold(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_e_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_b_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[100], real_T c7_b_B[100])
{
  int32_T c7_i79;
  int32_T c7_i80;
  real_T c7_d_A[10000];
  for (c7_i79 = 0; c7_i79 < 100; c7_i79++) {
    c7_b_B[c7_i79] = c7_B[c7_i79];
  }

  for (c7_i80 = 0; c7_i80 < 10000; c7_i80++) {
    c7_d_A[c7_i80] = c7_c_A[c7_i80];
  }

  c7_f_xtrsm(chartInstance, c7_d_A, c7_b_B);
}

static void c7_f_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_b_mldivide(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, real_T c7_c_A[10000], real_T c7_B[60000], real_T c7_Y[60000])
{
  int32_T c7_i81;
  int32_T c7_ipiv[100];
  int32_T c7_info;
  int32_T c7_b_info;
  int32_T c7_i82;
  int32_T c7_xi;
  int32_T c7_i83;
  int32_T c7_b_xi;
  int32_T c7_ip;
  real_T c7_d_A[10000];
  int32_T c7_xj;
  int32_T c7_b_xj;
  real_T c7_temp;
  for (c7_i81 = 0; c7_i81 < 10000; c7_i81++) {
    chartInstance->c7_A[c7_i81] = c7_c_A[c7_i81];
  }

  c7_b_xgetrf(chartInstance, chartInstance->c7_A, c7_ipiv, &c7_info);
  c7_b_info = c7_info;
  if ((real_T)c7_b_info > 0.0) {
    c7_warning(chartInstance);
  }

  for (c7_i82 = 0; c7_i82 < 60000; c7_i82++) {
    c7_Y[c7_i82] = c7_B[c7_i82];
  }

  for (c7_xi = 1; c7_xi < 100; c7_xi++) {
    c7_b_xi = c7_xi - 1;
    if (c7_ipiv[c7_b_xi] != c7_b_xi + 1) {
      c7_ip = c7_ipiv[c7_b_xi] - 1;
      for (c7_xj = 1; c7_xj < 601; c7_xj++) {
        c7_b_xj = c7_xj - 1;
        c7_temp = c7_Y[c7_b_xi + 100 * c7_b_xj];
        c7_Y[c7_b_xi + 100 * c7_b_xj] = c7_Y[c7_ip + 100 * c7_b_xj];
        c7_Y[c7_ip + 100 * c7_b_xj] = c7_temp;
      }
    }
  }

  for (c7_i83 = 0; c7_i83 < 10000; c7_i83++) {
    c7_d_A[c7_i83] = chartInstance->c7_A[c7_i83];
  }

  c7_g_xtrsm(chartInstance, c7_d_A, c7_Y);
  c7_h_xtrsm(chartInstance, chartInstance->c7_A, c7_Y);
}

static void c7_g_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_c_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[60000], real_T c7_b_B[60000])
{
  int32_T c7_i84;
  int32_T c7_i85;
  real_T c7_d_A[10000];
  for (c7_i84 = 0; c7_i84 < 60000; c7_i84++) {
    c7_b_B[c7_i84] = c7_B[c7_i84];
  }

  for (c7_i85 = 0; c7_i85 < 10000; c7_i85++) {
    c7_d_A[c7_i85] = c7_c_A[c7_i85];
  }

  c7_g_xtrsm(chartInstance, c7_d_A, c7_b_B);
}

static void c7_b_below_threshold(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_h_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_d_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[60000], real_T c7_b_B[60000])
{
  int32_T c7_i86;
  int32_T c7_i87;
  real_T c7_d_A[10000];
  for (c7_i86 = 0; c7_i86 < 60000; c7_i86++) {
    c7_b_B[c7_i86] = c7_B[c7_i86];
  }

  for (c7_i87 = 0; c7_i87 < 10000; c7_i87++) {
    c7_d_A[c7_i87] = c7_c_A[c7_i87];
  }

  c7_h_xtrsm(chartInstance, c7_d_A, c7_b_B);
}

static void c7_i_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_j_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_k_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_l_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_m_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_n_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c7_xdot(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
                      real_T c7_x[600], real_T c7_b_y[600])
{
  ptrdiff_t c7_n_t;
  ptrdiff_t c7_incx_t;
  ptrdiff_t c7_incy_t;
  (void)chartInstance;
  c7_n_t = (ptrdiff_t)600;
  c7_incx_t = (ptrdiff_t)1;
  c7_incy_t = (ptrdiff_t)1;
  return ddot(&c7_n_t, &c7_x[0], &c7_incx_t, &c7_b_y[0], &c7_incy_t);
}

static void c7_o_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_p_scalarEg(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c7_h_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_c_u;
  const mxArray *c7_b_y = NULL;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_c_u = *(int32_T *)c7_inData;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_b_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_g_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_b_y;
  int32_T c7_i88;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_c_u), &c7_i88, 1, 6, 0U, 0, 0U, 0);
  c7_b_y = c7_i88;
  sf_mex_destroy(&c7_c_u);
  return c7_b_y;
}

static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_b_y;
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_b_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_h_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_Simulation_der_Regler, const
  char_T *c7_identifier)
{
  uint8_T c7_b_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_b_y = c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_Simulation_der_Regler), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_Simulation_der_Regler);
  return c7_b_y;
}

static uint8_T c7_i_emlrt_marshallIn(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c7_c_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_b_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_c_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_b_y = c7_u0;
  sf_mex_destroy(&c7_c_u);
  return c7_b_y;
}

static void c7_b_xgetrf(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], int32_T c7_ipiv[100], int32_T *c7_info)
{
  const mxArray *c7_header_name = NULL;
  const mxArray *c7_isMex = NULL;
  const mxArray *c7_b_header_name = NULL;
  const mxArray *c7_b_isMex = NULL;
  const mxArray *c7_c_header_name = NULL;
  const mxArray *c7_c_isMex = NULL;
  const mxArray *c7_d_header_name = NULL;
  const mxArray *c7_d_isMex = NULL;
  ptrdiff_t c7_m_t;
  ptrdiff_t c7_n_t;
  ptrdiff_t c7_lda_t;
  const mxArray *c7_e_header_name = NULL;
  const mxArray *c7_e_isMex = NULL;
  ptrdiff_t c7_info_t;
  ptrdiff_t c7_ipiv_t[100];
  int32_T c7_b_info;
  int32_T c7_c_info;
  const mxArray *c7_f_header_name = NULL;
  const mxArray *c7_f_isMex = NULL;
  int32_T c7_d_info;
  boolean_T c7_p;
  int32_T c7_k;
  int32_T c7_b_k;
  sf_mex_destroy(&c7_header_name);
  sf_mex_destroy(&c7_isMex);
  sf_mex_destroy(&c7_b_header_name);
  sf_mex_destroy(&c7_b_isMex);
  sf_mex_destroy(&c7_c_header_name);
  sf_mex_destroy(&c7_c_isMex);
  sf_mex_destroy(&c7_d_header_name);
  sf_mex_destroy(&c7_d_isMex);
  c7_m_t = (ptrdiff_t)100;
  c7_n_t = (ptrdiff_t)100;
  c7_lda_t = (ptrdiff_t)100;
  sf_mex_destroy(&c7_e_header_name);
  sf_mex_destroy(&c7_e_isMex);
  c7_info_t = LAPACKE_dgetrf_work(102, c7_m_t, c7_n_t, &c7_c_A[0], c7_lda_t,
    &c7_ipiv_t[0]);
  c7_b_info = (int32_T)c7_info_t;
  c7_c_info = c7_b_info;
  sf_mex_destroy(&c7_f_header_name);
  sf_mex_destroy(&c7_f_isMex);
  c7_d_info = c7_c_info;
  c7_p = (c7_d_info < 0);
  if (c7_p) {
    if (c7_c_info == -1010) {
      c7_error(chartInstance);
    } else {
      c7_b_error(chartInstance, c7_c_info);
    }
  }

  for (c7_k = 0; c7_k < 100; c7_k++) {
    c7_b_k = c7_k;
    c7_ipiv[c7_b_k] = (int32_T)c7_ipiv_t[c7_b_k];
  }

  *c7_info = c7_b_info;
}

static void c7_e_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[100])
{
  real_T c7_alpha1;
  char_T c7_DIAGA;
  char_T c7_TRANSA;
  char_T c7_UPLO;
  char_T c7_SIDE;
  ptrdiff_t c7_m_t;
  ptrdiff_t c7_n_t;
  ptrdiff_t c7_lda_t;
  ptrdiff_t c7_ldb_t;
  (void)chartInstance;
  c7_alpha1 = 1.0;
  c7_DIAGA = 'U';
  c7_TRANSA = 'N';
  c7_UPLO = 'L';
  c7_SIDE = 'L';
  c7_m_t = (ptrdiff_t)100;
  c7_n_t = (ptrdiff_t)1;
  c7_lda_t = (ptrdiff_t)100;
  c7_ldb_t = (ptrdiff_t)100;
  dtrsm(&c7_SIDE, &c7_UPLO, &c7_TRANSA, &c7_DIAGA, &c7_m_t, &c7_n_t, &c7_alpha1,
        &c7_c_A[0], &c7_lda_t, &c7_B[0], &c7_ldb_t);
}

static void c7_f_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[100])
{
  real_T c7_alpha1;
  char_T c7_DIAGA;
  char_T c7_TRANSA;
  char_T c7_UPLO;
  char_T c7_SIDE;
  ptrdiff_t c7_m_t;
  ptrdiff_t c7_n_t;
  ptrdiff_t c7_lda_t;
  ptrdiff_t c7_ldb_t;
  (void)chartInstance;
  c7_alpha1 = 1.0;
  c7_DIAGA = 'N';
  c7_TRANSA = 'N';
  c7_UPLO = 'U';
  c7_SIDE = 'L';
  c7_m_t = (ptrdiff_t)100;
  c7_n_t = (ptrdiff_t)1;
  c7_lda_t = (ptrdiff_t)100;
  c7_ldb_t = (ptrdiff_t)100;
  dtrsm(&c7_SIDE, &c7_UPLO, &c7_TRANSA, &c7_DIAGA, &c7_m_t, &c7_n_t, &c7_alpha1,
        &c7_c_A[0], &c7_lda_t, &c7_B[0], &c7_ldb_t);
}

static void c7_g_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[60000])
{
  real_T c7_alpha1;
  char_T c7_DIAGA;
  char_T c7_TRANSA;
  char_T c7_UPLO;
  char_T c7_SIDE;
  ptrdiff_t c7_m_t;
  ptrdiff_t c7_n_t;
  ptrdiff_t c7_lda_t;
  ptrdiff_t c7_ldb_t;
  (void)chartInstance;
  c7_alpha1 = 1.0;
  c7_DIAGA = 'U';
  c7_TRANSA = 'N';
  c7_UPLO = 'L';
  c7_SIDE = 'L';
  c7_m_t = (ptrdiff_t)100;
  c7_n_t = (ptrdiff_t)600;
  c7_lda_t = (ptrdiff_t)100;
  c7_ldb_t = (ptrdiff_t)100;
  dtrsm(&c7_SIDE, &c7_UPLO, &c7_TRANSA, &c7_DIAGA, &c7_m_t, &c7_n_t, &c7_alpha1,
        &c7_c_A[0], &c7_lda_t, &c7_B[0], &c7_ldb_t);
}

static void c7_h_xtrsm(SFc7_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c7_c_A[10000], real_T c7_B[60000])
{
  real_T c7_alpha1;
  char_T c7_DIAGA;
  char_T c7_TRANSA;
  char_T c7_UPLO;
  char_T c7_SIDE;
  ptrdiff_t c7_m_t;
  ptrdiff_t c7_n_t;
  ptrdiff_t c7_lda_t;
  ptrdiff_t c7_ldb_t;
  (void)chartInstance;
  c7_alpha1 = 1.0;
  c7_DIAGA = 'N';
  c7_TRANSA = 'N';
  c7_UPLO = 'U';
  c7_SIDE = 'L';
  c7_m_t = (ptrdiff_t)100;
  c7_n_t = (ptrdiff_t)600;
  c7_lda_t = (ptrdiff_t)100;
  c7_ldb_t = (ptrdiff_t)100;
  dtrsm(&c7_SIDE, &c7_UPLO, &c7_TRANSA, &c7_DIAGA, &c7_m_t, &c7_n_t, &c7_alpha1,
        &c7_c_A[0], &c7_lda_t, &c7_B[0], &c7_ldb_t);
}

static void init_dsm_address_info(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc7_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  chartInstance->c7_g_E = (real_T (*)[10000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c7_u_erg = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_f = (real_T (*)[100])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_d_M = (real_T (*)[60000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c7_gamma = (real_T (*)[600])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c7_s1 = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
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

void sf_c7_Simulation_der_Regler_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2683919616U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4104118063U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3130301584U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(37808421U);
}

mxArray* sf_c7_Simulation_der_Regler_get_post_codegen_info(void);
mxArray *sf_c7_Simulation_der_Regler_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("boBxpStlCScZWFrwgi1nqC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      pr[1] = (double)(100);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(600);
      pr[1] = (double)(100);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(600);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c7_Simulation_der_Regler_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_Simulation_der_Regler_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c7_Simulation_der_Regler_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c7_Simulation_der_Regler_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c7_Simulation_der_Regler_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c7_Simulation_der_Regler(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u_erg\",},{M[8],M[0],T\"is_active_c7_Simulation_der_Regler\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_Simulation_der_Regler_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_Simulation_der_ReglerInstanceStruct *chartInstance =
      (SFc7_Simulation_der_ReglerInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Simulation_der_ReglerMachineNumber_,
           7,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Simulation_der_ReglerMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Simulation_der_ReglerMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Simulation_der_ReglerMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"E");
          _SFD_SET_DATA_PROPS(1,1,1,0,"f");
          _SFD_SET_DATA_PROPS(2,1,1,0,"M");
          _SFD_SET_DATA_PROPS(3,1,1,0,"gamma");
          _SFD_SET_DATA_PROPS(4,1,1,0,"s1");
          _SFD_SET_DATA_PROPS(5,2,0,1,"u_erg");
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
        _SFD_CV_INIT_EML(0,1,1,0,3,0,0,0,3,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",134,-1,724);
        _SFD_CV_INIT_EML_IF(0,1,0,215,236,258,287);
        _SFD_CV_INIT_EML_IF(0,1,1,292,301,-1,-2);
        _SFD_CV_INIT_EML_IF(0,1,2,645,657,-1,-2);
        _SFD_CV_INIT_EML_FOR(0,1,0,200,211,291);
        _SFD_CV_INIT_EML_FOR(0,1,1,423,436,684);
        _SFD_CV_INIT_EML_FOR(0,1,2,461,471,595);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,218,235,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,295,300,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,648,656,-1,2);

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 600U;
          dimVector[1]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 600U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Simulation_der_ReglerMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_Simulation_der_ReglerInstanceStruct *chartInstance =
      (SFc7_Simulation_der_ReglerInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c7_g_E);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c7_u_erg);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c7_f);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c7_d_M);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c7_gamma);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c7_s1);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "snBG5hBDjAkxTQODAkW2A1C";
}

static void sf_opaque_initialize_c7_Simulation_der_Regler(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_Simulation_der_Regler
    ((SFc7_Simulation_der_ReglerInstanceStruct*) chartInstanceVar);
  initialize_c7_Simulation_der_Regler((SFc7_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_Simulation_der_Regler(void *chartInstanceVar)
{
  enable_c7_Simulation_der_Regler((SFc7_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_Simulation_der_Regler(void *chartInstanceVar)
{
  disable_c7_Simulation_der_Regler((SFc7_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_Simulation_der_Regler(void *chartInstanceVar)
{
  sf_gateway_c7_Simulation_der_Regler((SFc7_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_Simulation_der_Regler(SimStruct*
  S)
{
  return get_sim_state_c7_Simulation_der_Regler
    ((SFc7_Simulation_der_ReglerInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_Simulation_der_Regler(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c7_Simulation_der_Regler
    ((SFc7_Simulation_der_ReglerInstanceStruct*)sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c7_Simulation_der_Regler(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_Simulation_der_ReglerInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Simulation_der_Regler_optimization_info();
    }

    finalize_c7_Simulation_der_Regler((SFc7_Simulation_der_ReglerInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_Simulation_der_Regler
    ((SFc7_Simulation_der_ReglerInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Simulation_der_Regler(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_Simulation_der_Regler
      ((SFc7_Simulation_der_ReglerInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c7_Simulation_der_Regler(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Simulation_der_Regler_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 7);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3309578314U));
  ssSetChecksum1(S,(3016897933U));
  ssSetChecksum2(S,(2361175653U));
  ssSetChecksum3(S,(1592226149U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_Simulation_der_Regler(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_Simulation_der_Regler(SimStruct *S)
{
  SFc7_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc7_Simulation_der_ReglerInstanceStruct *)utMalloc(sizeof
    (SFc7_Simulation_der_ReglerInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc7_Simulation_der_ReglerInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_Simulation_der_Regler;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_Simulation_der_Regler;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_Simulation_der_Regler;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_Simulation_der_Regler;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_Simulation_der_Regler;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_Simulation_der_Regler;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_Simulation_der_Regler;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_Simulation_der_Regler;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_Simulation_der_Regler;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_Simulation_der_Regler;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_Simulation_der_Regler;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c7_Simulation_der_Regler(chartInstance);
}

void c7_Simulation_der_Regler_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Simulation_der_Regler(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Simulation_der_Regler(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Simulation_der_Regler(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_Simulation_der_Regler_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
