/* Include files */

#include "MPCRegelung1DOF1Versuch_sfun.h"
#include "c2_MPCRegelung1DOF1Versuch.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MPCRegelung1DOF1Versuch_sfun_debug_macros.h"
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
static const char * c2_debug_family_names[15] = { "v_vec", "s1", "u_work",
  "nargin", "nargout", "F", "G", "H", "Qw", "Rw", "r", "x", "BDu", "v", "u" };

/* Function Declarations */
static void initialize_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void initialize_params_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void enable_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void disable_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void set_sim_state_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void sf_gateway_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void mdl_start_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void c2_chartstep_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void initSimStructsc2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const char_T *c2_identifier, real_T
  c2_d_y[2]);
static void c2_b_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_d_y[2]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_d_y[70]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_e_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_d_y[100]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                     real_T c2_A[7000], real_T c2_B[10000], real_T c2_C[7000],
                     real_T c2_b_C[7000]);
static boolean_T c2_use_refblas(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_b_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_c_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_d_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_e_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_b_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[7000], real_T c2_B[7000], real_T c2_C[4900], real_T c2_b_C[4900]);
static void c2_f_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_inv(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                   real_T c2_b_x[4900], real_T c2_d_y[4900]);
static void c2_invNxN(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                      real_T c2_b_x[4900], real_T c2_d_y[4900]);
static void c2_xgetrf(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                      real_T c2_A[4900], real_T c2_b_A[4900], int32_T c2_ipiv[70]);
static void c2_error(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void c2_b_error(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  int32_T c2_varargin_2);
static void c2_eps(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static real_T c2_abs(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                     real_T c2_b_x);
static void c2_check_forloop_overflow_error
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance, boolean_T
   c2_overflow);
static void c2_eml_ipiv2perm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, int32_T c2_ipiv[70], int32_T c2_perm[70]);
static void c2_xtrsm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                     real_T c2_A[4900], real_T c2_B[4900], real_T c2_b_B[4900]);
static void c2_below_threshold(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static real_T c2_norm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                      real_T c2_b_x[4900]);
static void c2_warning(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance);
static void c2_b_warning(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, char_T c2_varargin_1[14]);
static void c2_g_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_h_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_c_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[600], real_T c2_B[6], real_T c2_C[100], real_T c2_b_C[100]);
static void c2_i_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_j_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_k_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_l_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void c2_f_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_sprintf, const char_T *c2_identifier, char_T
  c2_d_y[14]);
static void c2_g_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_d_y[14]);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_h_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *
  chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_i_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *
  chartInstance, const mxArray *c2_b_is_active_c2_MPCRegelung1DOF1Versuch, const
  char_T *c2_identifier);
static uint8_T c2_j_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *
  chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[7000], real_T c2_B[10000], real_T c2_C[7000]);
static void c2_e_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[7000], real_T c2_B[7000], real_T c2_C[4900]);
static void c2_b_xgetrf(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, real_T c2_A[4900], int32_T c2_ipiv[70]);
static void c2_b_xtrsm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[4900], real_T c2_B[4900]);
static void c2_f_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[600], real_T c2_B[6], real_T c2_C[100]);
static void init_dsm_address_info(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_MPCRegelung1DOF1Versuch(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_MPCRegelung1DOF1Versuch = 0U;
}

static void initialize_params_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_f_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_createcellmatrix(2, 1), false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", *chartInstance->c2_u, 0, 0U, 1U, 0U,
    1, 2), false);
  sf_mex_setcell(c2_d_y, 0, c2_e_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_MPCRegelung1DOF1Versuch;
  c2_b_u = c2_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_d_y, 1, c2_f_y);
  sf_mex_assign(&c2_st, c2_d_y, false);
  return c2_st;
}

static void set_sim_state_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_b_u;
  real_T c2_dv0[2];
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("u", c2_b_u, 0)),
                      "u", c2_dv0);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    (*chartInstance->c2_u)[c2_i0] = c2_dv0[c2_i0];
  }

  chartInstance->c2_is_active_c2_MPCRegelung1DOF1Versuch = c2_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c2_MPCRegelung1DOF1Versuch", c2_b_u, 1)),
     "is_active_c2_MPCRegelung1DOF1Versuch");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_MPCRegelung1DOF1Versuch(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_v, 8U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  for (c2_i1 = 0; c2_i1 < 8; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_BDu)[c2_i1], 7U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i2 = 0; c2_i2 < 6; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_x)[c2_i2], 6U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i3 = 0; c2_i3 < 100; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_r)[c2_i3], 5U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i4 = 0; c2_i4 < 10000; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_b_Rw)[c2_i4], 4U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i5 = 0; c2_i5 < 4900; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_b_Qw)[c2_i5], 3U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i6 = 0; c2_i6 < 7000; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_b_H)[c2_i6], 2U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i7 = 0; c2_i7 < 10000; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_b_G)[c2_i7], 1U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  for (c2_i8 = 0; c2_i8 < 600; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_F)[c2_i8], 0U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_MPCRegelung1DOF1Versuch(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MPCRegelung1DOF1VersuchMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_u)[c2_i9], 9U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }
}

static void mdl_start_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_chartstep_c2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  int32_T c2_i10;
  int32_T c2_i11;
  real_T c2_b_F[600];
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  real_T c2_b_r[100];
  int32_T c2_i17;
  real_T c2_b_x[6];
  real_T c2_b_v;
  real_T c2_b_BDu[8];
  uint32_T c2_debug_family_var_map[15];
  real_T c2_v_vec[100];
  real_T c2_s1;
  real_T c2_u_work[70];
  real_T c2_nargin = 9.0;
  real_T c2_nargout = 1.0;
  real_T c2_b_u[2];
  real_T c2_c_b;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  real_T c2_alpha1;
  int32_T c2_i30;
  real_T c2_beta1;
  int32_T c2_i31;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  int32_T c2_i32;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  real_T c2_b_a[600];
  int32_T c2_i37;
  real_T c2_d_b[6];
  real_T c2_d_y[100];
  int32_T c2_i38;
  int32_T c2_i39;
  real_T c2_b_alpha1;
  real_T c2_e_b[100];
  real_T c2_b_beta1;
  char_T c2_b_TRANSB;
  char_T c2_b_TRANSA;
  int32_T c2_i40;
  ptrdiff_t c2_b_m_t;
  real_T c2_e_y[100];
  ptrdiff_t c2_b_n_t;
  ptrdiff_t c2_b_k_t;
  ptrdiff_t c2_b_lda_t;
  ptrdiff_t c2_b_ldb_t;
  ptrdiff_t c2_b_ldc_t;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  real_T c2_c_alpha1;
  real_T c2_c_beta1;
  int32_T c2_i44;
  char_T c2_c_TRANSB;
  real_T c2_C[70];
  char_T c2_c_TRANSA;
  int32_T c2_i45;
  ptrdiff_t c2_c_m_t;
  ptrdiff_t c2_c_n_t;
  ptrdiff_t c2_c_k_t;
  ptrdiff_t c2_c_lda_t;
  ptrdiff_t c2_c_ldb_t;
  ptrdiff_t c2_c_ldc_t;
  int32_T c2_i46;
  int32_T c2_i47;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_v;
  for (c2_i10 = 0; c2_i10 < 600; c2_i10++) {
    c2_b_F[c2_i10] = (*chartInstance->c2_F)[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 10000; c2_i11++) {
    chartInstance->c2_G[c2_i11] = (*chartInstance->c2_b_G)[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 7000; c2_i12++) {
    chartInstance->c2_H[c2_i12] = (*chartInstance->c2_b_H)[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 4900; c2_i13++) {
    chartInstance->c2_Qw[c2_i13] = (*chartInstance->c2_b_Qw)[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 10000; c2_i14++) {
    chartInstance->c2_Rw[c2_i14] = (*chartInstance->c2_b_Rw)[c2_i14];
  }

  for (c2_i15 = 0; c2_i15 < 100; c2_i15++) {
    c2_b_r[c2_i15] = (*chartInstance->c2_r)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 6; c2_i16++) {
    c2_b_x[c2_i16] = (*chartInstance->c2_x)[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 8; c2_i17++) {
    c2_b_BDu[c2_i17] = (*chartInstance->c2_BDu)[c2_i17];
  }

  c2_b_v = c2_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_v_vec, 0U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_s1, 1U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_u_work, 2U, c2_j_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_F, 5U, c2_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_G, 6U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_H, 7U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_Qw, 8U, c2_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_Rw, 9U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_r, 10U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_x, 11U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_BDu, 12U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_v, 13U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_u, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  c2_c_b = c2_b_v;
  for (c2_i18 = 0; c2_i18 < 100; c2_i18++) {
    c2_v_vec[c2_i18] = c2_c_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_s1 = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_i19 = 0;
  for (c2_i20 = 0; c2_i20 < 100; c2_i20++) {
    c2_i22 = 0;
    for (c2_i23 = 0; c2_i23 < 70; c2_i23++) {
      chartInstance->c2_a[c2_i23 + c2_i19] = chartInstance->c2_H[c2_i22 + c2_i20];
      c2_i22 += 100;
    }

    c2_i19 += 70;
  }

  for (c2_i21 = 0; c2_i21 < 10000; c2_i21++) {
    chartInstance->c2_b[c2_i21] = chartInstance->c2_Rw[c2_i21];
  }

  for (c2_i24 = 0; c2_i24 < 7000; c2_i24++) {
    chartInstance->c2_y[c2_i24] = 0.0;
  }

  c2_d_xgemm(chartInstance, chartInstance->c2_a, chartInstance->c2_b,
             chartInstance->c2_y);
  for (c2_i25 = 0; c2_i25 < 7000; c2_i25++) {
    chartInstance->c2_b_b[c2_i25] = chartInstance->c2_H[c2_i25];
  }

  for (c2_i26 = 0; c2_i26 < 4900; c2_i26++) {
    chartInstance->c2_b_y[c2_i26] = 0.0;
  }

  c2_e_xgemm(chartInstance, chartInstance->c2_y, chartInstance->c2_b_b,
             chartInstance->c2_b_y);
  for (c2_i27 = 0; c2_i27 < 4900; c2_i27++) {
    chartInstance->c2_c_y[c2_i27] = chartInstance->c2_b_y[c2_i27] +
      chartInstance->c2_Qw[c2_i27];
  }

  c2_inv(chartInstance, chartInstance->c2_c_y, chartInstance->c2_b_y);
  c2_i28 = 0;
  for (c2_i29 = 0; c2_i29 < 100; c2_i29++) {
    c2_i30 = 0;
    for (c2_i31 = 0; c2_i31 < 70; c2_i31++) {
      chartInstance->c2_a[c2_i31 + c2_i28] = chartInstance->c2_H[c2_i30 + c2_i29];
      c2_i30 += 100;
    }

    c2_i28 += 70;
  }

  c2_alpha1 = 1.0;
  c2_beta1 = 0.0;
  c2_TRANSB = 'N';
  c2_TRANSA = 'N';
  for (c2_i32 = 0; c2_i32 < 7000; c2_i32++) {
    chartInstance->c2_y[c2_i32] = 0.0;
  }

  c2_m_t = (ptrdiff_t)70;
  c2_n_t = (ptrdiff_t)100;
  c2_k_t = (ptrdiff_t)70;
  c2_lda_t = (ptrdiff_t)70;
  c2_ldb_t = (ptrdiff_t)70;
  c2_ldc_t = (ptrdiff_t)70;
  dgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, &c2_alpha1,
        &chartInstance->c2_b_y[0], &c2_lda_t, &chartInstance->c2_a[0], &c2_ldb_t,
        &c2_beta1, &chartInstance->c2_y[0], &c2_ldc_t);
  for (c2_i33 = 0; c2_i33 < 10000; c2_i33++) {
    chartInstance->c2_b[c2_i33] = chartInstance->c2_Rw[c2_i33];
  }

  for (c2_i34 = 0; c2_i34 < 7000; c2_i34++) {
    chartInstance->c2_a[c2_i34] = 0.0;
  }

  c2_d_xgemm(chartInstance, chartInstance->c2_y, chartInstance->c2_b,
             chartInstance->c2_a);
  for (c2_i35 = 0; c2_i35 < 600; c2_i35++) {
    c2_b_a[c2_i35] = c2_b_F[c2_i35];
  }

  for (c2_i36 = 0; c2_i36 < 6; c2_i36++) {
    c2_d_b[c2_i36] = c2_b_x[c2_i36];
  }

  for (c2_i37 = 0; c2_i37 < 100; c2_i37++) {
    c2_d_y[c2_i37] = 0.0;
  }

  c2_f_xgemm(chartInstance, c2_b_a, c2_d_b, c2_d_y);
  for (c2_i38 = 0; c2_i38 < 10000; c2_i38++) {
    chartInstance->c2_b[c2_i38] = chartInstance->c2_G[c2_i38];
  }

  for (c2_i39 = 0; c2_i39 < 100; c2_i39++) {
    c2_e_b[c2_i39] = c2_v_vec[c2_i39];
  }

  c2_b_alpha1 = 1.0;
  c2_b_beta1 = 0.0;
  c2_b_TRANSB = 'N';
  c2_b_TRANSA = 'N';
  for (c2_i40 = 0; c2_i40 < 100; c2_i40++) {
    c2_e_y[c2_i40] = 0.0;
  }

  c2_b_m_t = (ptrdiff_t)100;
  c2_b_n_t = (ptrdiff_t)1;
  c2_b_k_t = (ptrdiff_t)100;
  c2_b_lda_t = (ptrdiff_t)100;
  c2_b_ldb_t = (ptrdiff_t)100;
  c2_b_ldc_t = (ptrdiff_t)100;
  dgemm(&c2_b_TRANSA, &c2_b_TRANSB, &c2_b_m_t, &c2_b_n_t, &c2_b_k_t,
        &c2_b_alpha1, &chartInstance->c2_b[0], &c2_b_lda_t, &c2_e_b[0],
        &c2_b_ldb_t, &c2_b_beta1, &c2_e_y[0], &c2_b_ldc_t);
  for (c2_i41 = 0; c2_i41 < 100; c2_i41++) {
    c2_d_y[c2_i41] = (c2_b_r[c2_i41] - c2_d_y[c2_i41]) + c2_e_y[c2_i41];
  }

  for (c2_i42 = 0; c2_i42 < 70; c2_i42++) {
    c2_u_work[c2_i42] = 0.0;
  }

  for (c2_i43 = 0; c2_i43 < 70; c2_i43++) {
    c2_u_work[c2_i43] = 0.0;
  }

  c2_c_alpha1 = 1.0;
  c2_c_beta1 = 0.0;
  for (c2_i44 = 0; c2_i44 < 70; c2_i44++) {
    c2_C[c2_i44] = c2_u_work[c2_i44];
  }

  c2_c_TRANSB = 'N';
  c2_c_TRANSA = 'N';
  for (c2_i45 = 0; c2_i45 < 70; c2_i45++) {
    c2_u_work[c2_i45] = c2_C[c2_i45];
  }

  c2_c_m_t = (ptrdiff_t)70;
  c2_c_n_t = (ptrdiff_t)1;
  c2_c_k_t = (ptrdiff_t)100;
  c2_c_lda_t = (ptrdiff_t)70;
  c2_c_ldb_t = (ptrdiff_t)100;
  c2_c_ldc_t = (ptrdiff_t)70;
  dgemm(&c2_c_TRANSA, &c2_c_TRANSB, &c2_c_m_t, &c2_c_n_t, &c2_c_k_t,
        &c2_c_alpha1, &chartInstance->c2_a[0], &c2_c_lda_t, &c2_d_y[0],
        &c2_c_ldb_t, &c2_c_beta1, &c2_u_work[0], &c2_c_ldc_t);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i46 = 0; c2_i46 < 2; c2_i46++) {
    c2_b_u[c2_i46] = c2_u_work[c2_i46];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i47 = 0; c2_i47 < 2; c2_i47++) {
    (*chartInstance->c2_u)[c2_i47] = c2_b_u[c2_i47];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_MPCRegelung1DOF1Versuch
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i48;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_u[2];
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i48 = 0; c2_i48 < 2; c2_i48++) {
    c2_b_u[c2_i48] = (*(real_T (*)[2])c2_inData)[c2_i48];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const char_T *c2_identifier, real_T
  c2_d_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId, c2_d_y);
  sf_mex_destroy(&c2_b_u);
}

static void c2_b_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_d_y[2])
{
  real_T c2_dv1[2];
  int32_T c2_i49;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i49 = 0; c2_i49 < 2; c2_i49++) {
    c2_d_y[c2_i49] = c2_dv1[c2_i49];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_u;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_d_y[2];
  int32_T c2_i50;
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_b_u = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_u), &c2_thisId, c2_d_y);
  sf_mex_destroy(&c2_b_u);
  for (c2_i50 = 0; c2_i50 < 2; c2_i50++) {
    (*(real_T (*)[2])c2_outData)[c2_i50] = c2_d_y[c2_i50];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_b_u;
  const mxArray *c2_d_y = NULL;
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i51;
  int32_T c2_i52;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i53;
  real_T c2_b_u[8];
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i51 = 0;
  for (c2_i52 = 0; c2_i52 < 2; c2_i52++) {
    for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
      c2_b_u[c2_i53 + c2_i51] = (*(real_T (*)[8])c2_inData)[c2_i53 + c2_i51];
    }

    c2_i51 += 4;
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 4, 2),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i54;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_u[6];
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i54 = 0; c2_i54 < 6; c2_i54++) {
    c2_b_u[c2_i54] = (*(real_T (*)[6])c2_inData)[c2_i54];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i55;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_u[100];
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i55 = 0; c2_i55 < 100; c2_i55++) {
    c2_b_u[c2_i55] = (*(real_T (*)[100])c2_inData)[c2_i55];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 100),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i56;
  int32_T c2_i57;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i58;
  real_T c2_b_u[10000];
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i56 = 0;
  for (c2_i57 = 0; c2_i57 < 100; c2_i57++) {
    for (c2_i58 = 0; c2_i58 < 100; c2_i58++) {
      c2_b_u[c2_i58 + c2_i56] = (*(real_T (*)[10000])c2_inData)[c2_i58 + c2_i56];
    }

    c2_i56 += 100;
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 100, 100),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i59;
  int32_T c2_i60;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i61;
  real_T c2_b_u[4900];
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i59 = 0;
  for (c2_i60 = 0; c2_i60 < 70; c2_i60++) {
    for (c2_i61 = 0; c2_i61 < 70; c2_i61++) {
      c2_b_u[c2_i61 + c2_i59] = (*(real_T (*)[4900])c2_inData)[c2_i61 + c2_i59];
    }

    c2_i59 += 70;
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 70, 70),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i62;
  int32_T c2_i63;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i64;
  real_T c2_b_u[7000];
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i62 = 0;
  for (c2_i63 = 0; c2_i63 < 70; c2_i63++) {
    for (c2_i64 = 0; c2_i64 < 100; c2_i64++) {
      c2_b_u[c2_i64 + c2_i62] = (*(real_T (*)[7000])c2_inData)[c2_i64 + c2_i62];
    }

    c2_i62 += 100;
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 100, 70),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i65;
  int32_T c2_i66;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i67;
  real_T c2_b_u[600];
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i65 = 0;
  for (c2_i66 = 0; c2_i66 < 6; c2_i66++) {
    for (c2_i67 = 0; c2_i67 < 100; c2_i67++) {
      c2_b_u[c2_i67 + c2_i65] = (*(real_T (*)[600])c2_inData)[c2_i67 + c2_i65];
    }

    c2_i65 += 100;
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 100, 6),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_d_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_d_y = c2_d0;
  sf_mex_destroy(&c2_b_u);
  return c2_d_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_d_y;
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout),
    &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_d_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i68;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_u[70];
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i68 = 0; c2_i68 < 70; c2_i68++) {
    c2_b_u[c2_i68] = (*(real_T (*)[70])c2_inData)[c2_i68];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 70), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_d_y[70])
{
  real_T c2_dv2[70];
  int32_T c2_i69;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 70);
  for (c2_i69 = 0; c2_i69 < 70; c2_i69++) {
    c2_d_y[c2_i69] = c2_dv2[c2_i69];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_u_work;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_d_y[70];
  int32_T c2_i70;
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_u_work = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_u_work), &c2_thisId, c2_d_y);
  sf_mex_destroy(&c2_u_work);
  for (c2_i70 = 0; c2_i70 < 70; c2_i70++) {
    (*(real_T (*)[70])c2_outData)[c2_i70] = c2_d_y[c2_i70];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_e_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_d_y[100])
{
  real_T c2_dv3[100];
  int32_T c2_i71;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv3, 1, 0, 0U, 1, 0U, 1, 100);
  for (c2_i71 = 0; c2_i71 < 100; c2_i71++) {
    c2_d_y[c2_i71] = c2_dv3[c2_i71];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_v_vec;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_d_y[100];
  int32_T c2_i72;
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_v_vec = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_v_vec), &c2_thisId, c2_d_y);
  sf_mex_destroy(&c2_v_vec);
  for (c2_i72 = 0; c2_i72 < 100; c2_i72++) {
    (*(real_T (*)[100])c2_outData)[c2_i72] = c2_d_y[c2_i72];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_MPCRegelung1DOF1Versuch_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                     real_T c2_A[7000], real_T c2_B[10000], real_T c2_C[7000],
                     real_T c2_b_C[7000])
{
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  real_T c2_b_A[7000];
  real_T c2_b_B[10000];
  for (c2_i73 = 0; c2_i73 < 7000; c2_i73++) {
    c2_b_C[c2_i73] = c2_C[c2_i73];
  }

  for (c2_i74 = 0; c2_i74 < 7000; c2_i74++) {
    c2_b_A[c2_i74] = c2_A[c2_i74];
  }

  for (c2_i75 = 0; c2_i75 < 10000; c2_i75++) {
    c2_b_B[c2_i75] = c2_B[c2_i75];
  }

  c2_d_xgemm(chartInstance, c2_b_A, c2_b_B, c2_b_C);
}

static boolean_T c2_use_refblas(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
  return false;
}

static void c2_b_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_c_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_d_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_e_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_b_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[7000], real_T c2_B[7000], real_T c2_C[4900], real_T c2_b_C[4900])
{
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  real_T c2_b_A[7000];
  real_T c2_b_B[7000];
  for (c2_i76 = 0; c2_i76 < 4900; c2_i76++) {
    c2_b_C[c2_i76] = c2_C[c2_i76];
  }

  for (c2_i77 = 0; c2_i77 < 7000; c2_i77++) {
    c2_b_A[c2_i77] = c2_A[c2_i77];
  }

  for (c2_i78 = 0; c2_i78 < 7000; c2_i78++) {
    c2_b_B[c2_i78] = c2_B[c2_i78];
  }

  c2_e_xgemm(chartInstance, c2_b_A, c2_b_B, c2_b_C);
}

static void c2_f_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_inv(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                   real_T c2_b_x[4900], real_T c2_d_y[4900])
{
  int32_T c2_i79;
  real_T c2_c_x[4900];
  int32_T c2_i80;
  real_T c2_n1x;
  real_T c2_d_x[4900];
  int32_T c2_i81;
  real_T c2_n1xinv;
  real_T c2_e_y[4900];
  real_T c2_rc;
  real_T c2_e_x;
  boolean_T c2_c_b;
  real_T c2_f_x;
  const mxArray *c2_f_y = NULL;
  static char_T c2_rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  real_T c2_b_u;
  const mxArray *c2_g_y = NULL;
  char_T c2_str[14];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  for (c2_i79 = 0; c2_i79 < 4900; c2_i79++) {
    c2_c_x[c2_i79] = c2_b_x[c2_i79];
  }

  c2_invNxN(chartInstance, c2_c_x, c2_d_y);
  for (c2_i80 = 0; c2_i80 < 4900; c2_i80++) {
    c2_d_x[c2_i80] = c2_b_x[c2_i80];
  }

  c2_n1x = c2_norm(chartInstance, c2_d_x);
  for (c2_i81 = 0; c2_i81 < 4900; c2_i81++) {
    c2_e_y[c2_i81] = c2_d_y[c2_i81];
  }

  c2_n1xinv = c2_norm(chartInstance, c2_e_y);
  c2_rc = 1.0 / (c2_n1x * c2_n1xinv);
  guard1 = false;
  guard2 = false;
  if (c2_n1x == 0.0) {
    guard2 = true;
  } else if (c2_n1xinv == 0.0) {
    guard2 = true;
  } else if (c2_rc == 0.0) {
    guard1 = true;
  } else {
    c2_e_x = c2_rc;
    c2_c_b = muDoubleScalarIsNaN(c2_e_x);
    guard3 = false;
    if (c2_c_b) {
      guard3 = true;
    } else {
      if (c2_rc < 2.2204460492503131E-16) {
        guard3 = true;
      }
    }

    if (guard3 == true) {
      c2_f_x = c2_rc;
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_rfmt, 10, 0U, 1U, 0U, 2, 1, 6),
                    false);
      c2_b_u = c2_f_x;
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      c2_f_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14,
        c2_f_y, 14, c2_g_y), "sprintf", c2_str);
      c2_b_warning(chartInstance, c2_str);
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c2_warning(chartInstance);
  }
}

static void c2_invNxN(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                      real_T c2_b_x[4900], real_T c2_d_y[4900])
{
  int32_T c2_i82;
  int32_T c2_ipiv[70];
  int32_T c2_p[70];
  int32_T c2_k;
  int32_T c2_i83;
  int32_T c2_b_k;
  int32_T c2_c;
  real_T c2_c_x[4900];
  int32_T c2_c_k;
  boolean_T c2_overflow;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_b_a;
  int32_T c2_i84;
  boolean_T c2_b_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  for (c2_i82 = 0; c2_i82 < 4900; c2_i82++) {
    c2_d_y[c2_i82] = 0.0;
  }

  c2_b_xgetrf(chartInstance, c2_b_x, c2_ipiv);
  c2_eml_ipiv2perm(chartInstance, c2_ipiv, c2_p);
  for (c2_k = 1; c2_k < 71; c2_k++) {
    c2_b_k = c2_k - 1;
    c2_c = c2_p[c2_b_k] - 1;
    c2_d_y[c2_b_k + 70 * c2_c] = 1.0;
    c2_c_k = c2_b_k + 1;
    c2_overflow = false;
    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_j = c2_c_k; c2_j < 71; c2_j++) {
      c2_b_j = c2_j - 1;
      if (c2_d_y[c2_b_j + 70 * c2_c] != 0.0) {
        c2_b_a = c2_b_j + 1;
        c2_i84 = c2_b_a;
        c2_b_overflow = false;
        if (c2_b_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
        }

        for (c2_i = c2_i84 + 1; c2_i < 71; c2_i++) {
          c2_b_i = c2_i - 1;
          c2_d_y[c2_b_i + 70 * c2_c] -= c2_d_y[c2_b_j + 70 * c2_c] *
            c2_b_x[c2_b_i + 70 * c2_b_j];
        }
      }
    }
  }

  for (c2_i83 = 0; c2_i83 < 4900; c2_i83++) {
    c2_c_x[c2_i83] = c2_b_x[c2_i83];
  }

  c2_b_xtrsm(chartInstance, c2_c_x, c2_d_y);
}

static void c2_xgetrf(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                      real_T c2_A[4900], real_T c2_b_A[4900], int32_T c2_ipiv[70])
{
  int32_T c2_i85;
  for (c2_i85 = 0; c2_i85 < 4900; c2_i85++) {
    c2_b_A[c2_i85] = c2_A[c2_i85];
  }

  c2_b_xgetrf(chartInstance, c2_b_A, c2_ipiv);
}

static void c2_error(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  const mxArray *c2_d_y = NULL;
  static char_T c2_b_u[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  (void)chartInstance;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_d_y));
}

static void c2_b_error(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  int32_T c2_varargin_2)
{
  const mxArray *c2_d_y = NULL;
  static char_T c2_b_u[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_c_u[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  int32_T c2_d_u;
  const mxArray *c2_f_y = NULL;
  (void)chartInstance;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_c_u, 10, 0U, 1U, 0U, 2, 1, 19),
                false);
  c2_d_u = c2_varargin_2;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c2_d_y, 14, c2_e_y, 14, c2_f_y));
}

static void c2_eps(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c2_abs(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                     real_T c2_b_x)
{
  real_T c2_c_x;
  real_T c2_d_x;
  (void)chartInstance;
  c2_c_x = c2_b_x;
  c2_d_x = c2_c_x;
  return muDoubleScalarAbs(c2_d_x);
}

static void c2_check_forloop_overflow_error
  (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance, boolean_T
   c2_overflow)
{
  const mxArray *c2_d_y = NULL;
  static char_T c2_b_u[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_c_u[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  if (!c2_overflow) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c2_d_y, 14, c2_e_y));
  }
}

static void c2_eml_ipiv2perm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, int32_T c2_ipiv[70], int32_T c2_perm[70])
{
  int32_T c2_i86;
  int32_T c2_k;
  real_T c2_b_k;
  int32_T c2_ipk;
  int32_T c2_b_a;
  real_T c2_c_b;
  int32_T c2_c_a;
  real_T c2_d_b;
  int32_T c2_idx;
  real_T c2_flt;
  boolean_T c2_p;
  int32_T c2_pipk;
  (void)chartInstance;
  for (c2_i86 = 0; c2_i86 < 70; c2_i86++) {
    c2_perm[c2_i86] = 1 + c2_i86;
  }

  for (c2_k = 0; c2_k < 69; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_ipk = c2_ipiv[(int32_T)c2_b_k - 1] - 1;
    c2_b_a = c2_ipk + 1;
    c2_c_b = c2_b_k;
    c2_c_a = c2_b_a;
    c2_d_b = c2_c_b;
    c2_idx = c2_c_a;
    c2_flt = c2_d_b;
    c2_p = ((real_T)c2_idx > c2_flt);
    if (c2_p) {
      c2_pipk = c2_perm[c2_ipk];
      c2_perm[c2_ipk] = c2_perm[(int32_T)c2_b_k - 1];
      c2_perm[(int32_T)c2_b_k - 1] = c2_pipk;
    }
  }
}

static void c2_xtrsm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                     real_T c2_A[4900], real_T c2_B[4900], real_T c2_b_B[4900])
{
  int32_T c2_i87;
  int32_T c2_i88;
  real_T c2_b_A[4900];
  for (c2_i87 = 0; c2_i87 < 4900; c2_i87++) {
    c2_b_B[c2_i87] = c2_B[c2_i87];
  }

  for (c2_i88 = 0; c2_i88 < 4900; c2_i88++) {
    c2_b_A[c2_i88] = c2_A[c2_i88];
  }

  c2_b_xtrsm(chartInstance, c2_b_A, c2_b_B);
}

static void c2_below_threshold(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c2_norm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
                      real_T c2_b_x[4900])
{
  real_T c2_d_y;
  int32_T c2_j;
  real_T c2_b_j;
  real_T c2_s;
  int32_T c2_i;
  real_T c2_c_x;
  real_T c2_b_i;
  boolean_T c2_c_b;
  boolean_T exitg1;
  c2_d_y = 0.0;
  c2_j = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c2_j < 70)) {
    c2_b_j = 1.0 + (real_T)c2_j;
    c2_s = 0.0;
    for (c2_i = 0; c2_i < 70; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_s += c2_abs(chartInstance, c2_b_x[((int32_T)c2_b_i + 70 * ((int32_T)
        c2_b_j - 1)) - 1]);
    }

    c2_c_x = c2_s;
    c2_c_b = muDoubleScalarIsNaN(c2_c_x);
    if (c2_c_b) {
      c2_d_y = rtNaN;
      exitg1 = true;
    } else {
      if (c2_s > c2_d_y) {
        c2_d_y = c2_s;
      }

      c2_j++;
    }
  }

  return c2_d_y;
}

static void c2_warning(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance)
{
  const mxArray *c2_d_y = NULL;
  static char_T c2_b_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_c_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_f_y = NULL;
  static char_T c2_msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  (void)chartInstance;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_d_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_e_y, 14, c2_f_y));
}

static void c2_b_warning(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, char_T c2_varargin_1[14])
{
  const mxArray *c2_d_y = NULL;
  static char_T c2_b_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_c_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_f_y = NULL;
  static char_T c2_msgID[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i', 'o',
    'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  const mxArray *c2_g_y = NULL;
  (void)chartInstance;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_varargin_1, 10, 0U, 1U, 0U, 2, 1,
    14), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_d_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    3U, 14, c2_e_y, 14, c2_f_y, 14, c2_g_y));
}

static void c2_g_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_h_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_c_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[600], real_T c2_B[6], real_T c2_C[100], real_T c2_b_C[100])
{
  int32_T c2_i89;
  int32_T c2_i90;
  int32_T c2_i91;
  real_T c2_b_A[600];
  real_T c2_b_B[6];
  for (c2_i89 = 0; c2_i89 < 100; c2_i89++) {
    c2_b_C[c2_i89] = c2_C[c2_i89];
  }

  for (c2_i90 = 0; c2_i90 < 600; c2_i90++) {
    c2_b_A[c2_i90] = c2_A[c2_i90];
  }

  for (c2_i91 = 0; c2_i91 < 6; c2_i91++) {
    c2_b_B[c2_i91] = c2_B[c2_i91];
  }

  c2_f_xgemm(chartInstance, c2_b_A, c2_b_B, c2_b_C);
}

static void c2_i_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_j_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_k_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_l_scalarEg(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_f_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_sprintf, const char_T *c2_identifier, char_T
  c2_d_y[14])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sprintf), &c2_thisId,
                        c2_d_y);
  sf_mex_destroy(&c2_sprintf);
}

static void c2_g_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  char_T c2_d_y[14])
{
  char_T c2_cv0[14];
  int32_T c2_i92;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_cv0, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c2_i92 = 0; c2_i92 < 14; c2_i92++) {
    c2_d_y[c2_i92] = c2_cv0[c2_i92];
  }

  sf_mex_destroy(&c2_b_u);
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_b_u;
  const mxArray *c2_d_y = NULL;
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_d_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_h_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *
  chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_d_y;
  int32_T c2_i93;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i93, 1, 6, 0U, 0, 0U, 0);
  c2_d_y = c2_i93;
  sf_mex_destroy(&c2_b_u);
  return c2_d_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_d_y;
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_d_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_i_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *
  chartInstance, const mxArray *c2_b_is_active_c2_MPCRegelung1DOF1Versuch, const
  char_T *c2_identifier)
{
  uint8_T c2_d_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_MPCRegelung1DOF1Versuch), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_MPCRegelung1DOF1Versuch);
  return c2_d_y;
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *
  chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_d_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_d_y = c2_u0;
  sf_mex_destroy(&c2_b_u);
  return c2_d_y;
}

static void c2_d_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[7000], real_T c2_B[10000], real_T c2_C[7000])
{
  real_T c2_alpha1;
  real_T c2_beta1;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  (void)chartInstance;
  c2_alpha1 = 1.0;
  c2_beta1 = 0.0;
  c2_TRANSB = 'N';
  c2_TRANSA = 'N';
  c2_m_t = (ptrdiff_t)70;
  c2_n_t = (ptrdiff_t)100;
  c2_k_t = (ptrdiff_t)100;
  c2_lda_t = (ptrdiff_t)70;
  c2_ldb_t = (ptrdiff_t)100;
  c2_ldc_t = (ptrdiff_t)70;
  dgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, &c2_alpha1, &c2_A[0],
        &c2_lda_t, &c2_B[0], &c2_ldb_t, &c2_beta1, &c2_C[0], &c2_ldc_t);
}

static void c2_e_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[7000], real_T c2_B[7000], real_T c2_C[4900])
{
  real_T c2_alpha1;
  real_T c2_beta1;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  (void)chartInstance;
  c2_alpha1 = 1.0;
  c2_beta1 = 0.0;
  c2_TRANSB = 'N';
  c2_TRANSA = 'N';
  c2_m_t = (ptrdiff_t)70;
  c2_n_t = (ptrdiff_t)70;
  c2_k_t = (ptrdiff_t)100;
  c2_lda_t = (ptrdiff_t)70;
  c2_ldb_t = (ptrdiff_t)100;
  c2_ldc_t = (ptrdiff_t)70;
  dgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, &c2_alpha1, &c2_A[0],
        &c2_lda_t, &c2_B[0], &c2_ldb_t, &c2_beta1, &c2_C[0], &c2_ldc_t);
}

static void c2_b_xgetrf(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance, real_T c2_A[4900], int32_T c2_ipiv[70])
{
  const mxArray *c2_header_name = NULL;
  const mxArray *c2_isMex = NULL;
  const mxArray *c2_b_header_name = NULL;
  const mxArray *c2_b_isMex = NULL;
  const mxArray *c2_c_header_name = NULL;
  const mxArray *c2_c_isMex = NULL;
  const mxArray *c2_d_header_name = NULL;
  const mxArray *c2_d_isMex = NULL;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  const mxArray *c2_e_header_name = NULL;
  const mxArray *c2_e_isMex = NULL;
  ptrdiff_t c2_info_t;
  ptrdiff_t c2_ipiv_t[70];
  int32_T c2_info;
  int32_T c2_b_info;
  const mxArray *c2_f_header_name = NULL;
  const mxArray *c2_f_isMex = NULL;
  int32_T c2_c_info;
  boolean_T c2_p;
  int32_T c2_k;
  int32_T c2_b_k;
  sf_mex_destroy(&c2_header_name);
  sf_mex_destroy(&c2_isMex);
  sf_mex_destroy(&c2_b_header_name);
  sf_mex_destroy(&c2_b_isMex);
  sf_mex_destroy(&c2_c_header_name);
  sf_mex_destroy(&c2_c_isMex);
  sf_mex_destroy(&c2_d_header_name);
  sf_mex_destroy(&c2_d_isMex);
  c2_m_t = (ptrdiff_t)70;
  c2_n_t = (ptrdiff_t)70;
  c2_lda_t = (ptrdiff_t)70;
  sf_mex_destroy(&c2_e_header_name);
  sf_mex_destroy(&c2_e_isMex);
  c2_info_t = LAPACKE_dgetrf_work(102, c2_m_t, c2_n_t, &c2_A[0], c2_lda_t,
    &c2_ipiv_t[0]);
  c2_info = (int32_T)c2_info_t;
  c2_b_info = c2_info;
  sf_mex_destroy(&c2_f_header_name);
  sf_mex_destroy(&c2_f_isMex);
  c2_c_info = c2_b_info;
  c2_p = (c2_c_info < 0);
  if (c2_p) {
    if (c2_b_info == -1010) {
      c2_error(chartInstance);
    } else {
      c2_b_error(chartInstance, c2_b_info);
    }
  }

  for (c2_k = 0; c2_k < 70; c2_k++) {
    c2_b_k = c2_k;
    c2_ipiv[c2_b_k] = (int32_T)c2_ipiv_t[c2_b_k];
  }
}

static void c2_b_xtrsm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[4900], real_T c2_B[4900])
{
  real_T c2_alpha1;
  int32_T c2_j;
  char_T c2_DIAGA;
  char_T c2_TRANSA;
  char_T c2_UPLO;
  int32_T c2_b_j;
  char_T c2_SIDE;
  int32_T c2_jBcol;
  ptrdiff_t c2_m_t;
  int32_T c2_k;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  int32_T c2_b_k;
  int32_T c2_kAcol;
  real_T c2_b_x;
  real_T c2_d_y;
  real_T c2_c_x;
  real_T c2_e_y;
  real_T c2_z;
  int32_T c2_i94;
  int32_T c2_c_b;
  int32_T c2_d_b;
  boolean_T c2_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  if (c2_use_refblas(chartInstance)) {
    for (c2_j = 1; c2_j < 71; c2_j++) {
      c2_b_j = c2_j - 1;
      c2_jBcol = 70 * c2_b_j;
      for (c2_k = 70; c2_k > 0; c2_k--) {
        c2_b_k = c2_k - 1;
        c2_kAcol = 70 * c2_b_k;
        if (c2_B[c2_b_k + c2_jBcol] != 0.0) {
          c2_b_x = c2_B[c2_b_k + c2_jBcol];
          c2_d_y = c2_A[c2_b_k + c2_kAcol];
          c2_c_x = c2_b_x;
          c2_e_y = c2_d_y;
          c2_z = c2_c_x / c2_e_y;
          c2_B[c2_b_k + c2_jBcol] = c2_z;
          c2_i94 = c2_b_k;
          c2_c_b = c2_i94;
          c2_d_b = c2_c_b;
          c2_overflow = ((!(1 > c2_d_b)) && (c2_d_b > 2147483646));
          if (c2_overflow) {
            c2_check_forloop_overflow_error(chartInstance, c2_overflow);
          }

          for (c2_i = 1; c2_i <= c2_i94; c2_i++) {
            c2_b_i = c2_i - 1;
            c2_B[c2_b_i + c2_jBcol] -= c2_B[c2_b_k + c2_jBcol] * c2_A[c2_b_i +
              c2_kAcol];
          }
        }
      }
    }
  } else {
    c2_alpha1 = 1.0;
    c2_DIAGA = 'N';
    c2_TRANSA = 'N';
    c2_UPLO = 'U';
    c2_SIDE = 'L';
    c2_m_t = (ptrdiff_t)70;
    c2_n_t = (ptrdiff_t)70;
    c2_lda_t = (ptrdiff_t)70;
    c2_ldb_t = (ptrdiff_t)70;
    dtrsm(&c2_SIDE, &c2_UPLO, &c2_TRANSA, &c2_DIAGA, &c2_m_t, &c2_n_t,
          &c2_alpha1, &c2_A[0], &c2_lda_t, &c2_B[0], &c2_ldb_t);
  }
}

static void c2_f_xgemm(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance,
  real_T c2_A[600], real_T c2_B[6], real_T c2_C[100])
{
  real_T c2_alpha1;
  real_T c2_beta1;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  (void)chartInstance;
  c2_alpha1 = 1.0;
  c2_beta1 = 0.0;
  c2_TRANSB = 'N';
  c2_TRANSA = 'N';
  c2_m_t = (ptrdiff_t)100;
  c2_n_t = (ptrdiff_t)1;
  c2_k_t = (ptrdiff_t)6;
  c2_lda_t = (ptrdiff_t)100;
  c2_ldb_t = (ptrdiff_t)6;
  c2_ldc_t = (ptrdiff_t)100;
  dgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, &c2_alpha1, &c2_A[0],
        &c2_lda_t, &c2_B[0], &c2_ldb_t, &c2_beta1, &c2_C[0], &c2_ldc_t);
}

static void init_dsm_address_info(SFc2_MPCRegelung1DOF1VersuchInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_MPCRegelung1DOF1VersuchInstanceStruct *
  chartInstance)
{
  chartInstance->c2_F = (real_T (*)[600])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_b_G = (real_T (*)[10000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_u = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_b_H = (real_T (*)[7000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_b_Qw = (real_T (*)[4900])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_b_Rw = (real_T (*)[10000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_r = (real_T (*)[100])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_x = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c2_BDu = (real_T (*)[8])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c2_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    8);
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

void sf_c2_MPCRegelung1DOF1Versuch_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1967785206U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1592738602U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3759669459U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(463892891U);
}

mxArray* sf_c2_MPCRegelung1DOF1Versuch_get_post_codegen_info(void);
mxArray *sf_c2_MPCRegelung1DOF1Versuch_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BNRCcWP066zDtvlLx3YxtF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      pr[1] = (double)(6);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      pr[1] = (double)(100);
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
      pr[0] = (double)(100);
      pr[1] = (double)(70);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(70);
      pr[1] = (double)(70);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      pr[1] = (double)(100);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(2);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
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
      sf_c2_MPCRegelung1DOF1Versuch_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_MPCRegelung1DOF1Versuch_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c2_MPCRegelung1DOF1Versuch_jit_fallback_info(void)
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

mxArray *sf_c2_MPCRegelung1DOF1Versuch_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_MPCRegelung1DOF1Versuch_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_MPCRegelung1DOF1Versuch(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u\",},{M[8],M[0],T\"is_active_c2_MPCRegelung1DOF1Versuch\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_MPCRegelung1DOF1Versuch_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance =
      (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MPCRegelung1DOF1VersuchMachineNumber_,
           2,
           1,
           1,
           0,
           10,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_MPCRegelung1DOF1VersuchMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_MPCRegelung1DOF1VersuchMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _MPCRegelung1DOF1VersuchMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"F");
          _SFD_SET_DATA_PROPS(1,1,1,0,"G");
          _SFD_SET_DATA_PROPS(2,1,1,0,"H");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Qw");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Rw");
          _SFD_SET_DATA_PROPS(5,1,1,0,"r");
          _SFD_SET_DATA_PROPS(6,1,1,0,"x");
          _SFD_SET_DATA_PROPS(7,1,1,0,"BDu");
          _SFD_SET_DATA_PROPS(8,1,1,0,"v");
          _SFD_SET_DATA_PROPS(9,2,0,1,"u");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,165);

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 70U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 70U;
          dimVector[1]= 70U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _MPCRegelung1DOF1VersuchMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance =
      (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c2_F);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c2_b_G);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c2_u);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c2_b_H);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c2_b_Qw);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c2_b_Rw);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c2_r);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c2_x);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c2_BDu);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c2_v);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s58YJd7vuYukMLK2oIq3k0E";
}

static void sf_opaque_initialize_c2_MPCRegelung1DOF1Versuch(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_MPCRegelung1DOF1Versuch
    ((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*) chartInstanceVar);
  initialize_c2_MPCRegelung1DOF1Versuch
    ((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_MPCRegelung1DOF1Versuch(void *chartInstanceVar)
{
  enable_c2_MPCRegelung1DOF1Versuch((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_MPCRegelung1DOF1Versuch(void *chartInstanceVar)
{
  disable_c2_MPCRegelung1DOF1Versuch((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_MPCRegelung1DOF1Versuch(void *chartInstanceVar)
{
  sf_gateway_c2_MPCRegelung1DOF1Versuch
    ((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_MPCRegelung1DOF1Versuch
  (SimStruct* S)
{
  return get_sim_state_c2_MPCRegelung1DOF1Versuch
    ((SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_MPCRegelung1DOF1Versuch(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c2_MPCRegelung1DOF1Versuch
    ((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c2_MPCRegelung1DOF1Versuch(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MPCRegelung1DOF1Versuch_optimization_info();
    }

    finalize_c2_MPCRegelung1DOF1Versuch
      ((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_MPCRegelung1DOF1Versuch
    ((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_MPCRegelung1DOF1Versuch(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_MPCRegelung1DOF1Versuch
      ((SFc2_MPCRegelung1DOF1VersuchInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_MPCRegelung1DOF1Versuch(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MPCRegelung1DOF1Versuch_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,9);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4214717527U));
  ssSetChecksum1(S,(3504264361U));
  ssSetChecksum2(S,(3257176133U));
  ssSetChecksum3(S,(2939057583U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_MPCRegelung1DOF1Versuch(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_MPCRegelung1DOF1Versuch(SimStruct *S)
{
  SFc2_MPCRegelung1DOF1VersuchInstanceStruct *chartInstance;
  chartInstance = (SFc2_MPCRegelung1DOF1VersuchInstanceStruct *)utMalloc(sizeof
    (SFc2_MPCRegelung1DOF1VersuchInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_MPCRegelung1DOF1VersuchInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_MPCRegelung1DOF1Versuch;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_MPCRegelung1DOF1Versuch;
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
  mdl_start_c2_MPCRegelung1DOF1Versuch(chartInstance);
}

void c2_MPCRegelung1DOF1Versuch_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_MPCRegelung1DOF1Versuch(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_MPCRegelung1DOF1Versuch(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_MPCRegelung1DOF1Versuch(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_MPCRegelung1DOF1Versuch_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
