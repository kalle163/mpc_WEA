/* Include files */

#include "Simulation_der_Regler_sfun.h"
#include "c5_Simulation_der_Regler.h"
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
static const char * c5_debug_family_names[41] = { "s1", "s2", "s3", "Nu", "N2",
  "v_vec", "E", "f", "gamma1min", "gamma1max", "gamma2min", "gamma2max", "k",
  "gamma3min", "gamma3max", "C1", "C2", "l", "M", "gamma", "u_work", "options",
  "nargin", "nargout", "F", "H", "G", "Bu", "C", "Rw", "Qw", "ref", "dx", "u",
  "dv", "dUmin", "dUmax", "Umin", "Umax", "Ymin", "Ymax" };

/* Function Declarations */
static void initialize_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void initialize_params_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void enable_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void disable_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void set_sim_state_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void sf_gateway_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void mdl_start_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void c5_chartstep_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void initSimStructsc5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const char_T *c5_identifier, real_T
  c5_b_y[2]);
static void c5_b_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[2]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_d_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[200]);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_e_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[20000]);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_f_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[10000]);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_g_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[200]);
static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static void c5_xgemm(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
                     real_T c5_A[10000], real_T c5_B[10000], real_T c5_b_C[10000],
                     real_T c5_c_C[10000]);
static void c5_b_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c5_c_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c5_d_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c5_e_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c5_f_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void c5_b_xgemm(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c5_A[10000], real_T c5_B[100], real_T c5_b_C[100], real_T c5_c_C[100]);
static void c5_eye(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
                   real_T c5_I[4]);
static void c5_g_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static const mxArray *c5_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const char_T c5_c_u
   [8]);
static const mxArray *c5_b_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const char_T c5_c_u
   [9]);
static const mxArray *c5_c_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const char_T c5_c_u
   [21]);
static const mxArray *c5_d_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [10000]);
static const mxArray *c5_e_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [100]);
static const mxArray *c5_f_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [20000]);
static const mxArray *c5_g_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [200]);
static const mxArray *c5_h_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance);
static const mxArray *c5_i_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [2]);
static void c5_h_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_quadprog, const char_T *c5_identifier,
  real_T c5_b_y[100]);
static void c5_i_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[100]);
static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_j_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_k_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_Simulation_der_Regler, const
  char_T *c5_identifier);
static uint8_T c5_l_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_xgemm(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c5_A[10000], real_T c5_B[10000], real_T c5_b_C[10000]);
static void c5_d_xgemm(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c5_A[10000], real_T c5_B[100], real_T c5_b_C[100]);
static void init_dsm_address_info(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc5_Simulation_der_Regler(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_Simulation_der_Regler = 0U;
}

static void initialize_params_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createcellmatrix(2, 1), false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", *chartInstance->c5_u, 0, 0U, 1U, 0U,
    1, 2), false);
  sf_mex_setcell(c5_b_y, 0, c5_c_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_Simulation_der_Regler;
  c5_c_u = c5_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_b_y, 1, c5_d_y);
  sf_mex_assign(&c5_st, c5_b_y, false);
  return c5_st;
}

static void set_sim_state_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_c_u;
  real_T c5_dv0[2];
  int32_T c5_i0;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_c_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("u", c5_c_u, 0)),
                      "u", c5_dv0);
  for (c5_i0 = 0; c5_i0 < 2; c5_i0++) {
    (*chartInstance->c5_u)[c5_i0] = c5_dv0[c5_i0];
  }

  chartInstance->c5_is_active_c5_Simulation_der_Regler = c5_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c5_Simulation_der_Regler", c5_c_u, 1)),
     "is_active_c5_Simulation_der_Regler");
  sf_mex_destroy(&c5_c_u);
  c5_update_debugger_state_c5_Simulation_der_Regler(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_Ymax, 16U, 1U, 0U,
                        chartInstance->c5_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_Ymin, 15U, 1U, 0U,
                        chartInstance->c5_sfEvent, false);
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_Umax)[c5_i1], 14U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_Umin)[c5_i2], 13U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_dUmax)[c5_i3], 12U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_dUmin)[c5_i4], 11U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_dv, 10U, 1U, 0U,
                        chartInstance->c5_sfEvent, false);
  for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_b_u)[c5_i5], 9U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i6 = 0; c5_i6 < 5; c5_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_dx)[c5_i6], 8U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i7 = 0; c5_i7 < 100; c5_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_ref)[c5_i7], 7U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i8 = 0; c5_i8 < 10000; c5_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_b_Qw)[c5_i8], 6U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i9 = 0; c5_i9 < 10000; c5_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_b_Rw)[c5_i9], 5U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_C, 4U, 1U, 0U,
                        chartInstance->c5_sfEvent, false);
  for (c5_i10 = 0; c5_i10 < 10; c5_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_Bu)[c5_i10], 3U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i11 = 0; c5_i11 < 10000; c5_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_b_G)[c5_i11], 2U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i12 = 0; c5_i12 < 10000; c5_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_b_H)[c5_i12], 1U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  for (c5_i13 = 0; c5_i13 < 500; c5_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_F)[c5_i13], 0U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_Simulation_der_Regler(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Simulation_der_ReglerMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c5_i14 = 0; c5_i14 < 2; c5_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_u)[c5_i14], 17U, 1U, 0U,
                          chartInstance->c5_sfEvent, false);
  }
}

static void mdl_start_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_chartstep_c5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  int32_T c5_i15;
  int32_T c5_i16;
  real_T c5_b_F[500];
  int32_T c5_i17;
  int32_T c5_i18;
  real_T c5_b_C;
  real_T c5_b_Bu[10];
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  real_T c5_b_ref[100];
  int32_T c5_i23;
  real_T c5_b_dx[5];
  real_T c5_b_dv;
  real_T c5_c_u[2];
  int32_T c5_i24;
  int32_T c5_i25;
  real_T c5_b_dUmin[2];
  int32_T c5_i26;
  real_T c5_b_dUmax[2];
  int32_T c5_i27;
  real_T c5_b_Umin[2];
  real_T c5_b_Ymin;
  real_T c5_b_Umax[2];
  real_T c5_b_Ymax;
  uint32_T c5_debug_family_var_map[41];
  real_T c5_s1;
  real_T c5_s2;
  real_T c5_s3;
  real_T c5_Nu;
  real_T c5_N2;
  real_T c5_v_vec[100];
  real_T c5_f[100];
  real_T c5_gamma1min[100];
  real_T c5_gamma1max[100];
  real_T c5_gamma2min[100];
  real_T c5_gamma2max[100];
  real_T c5_k;
  real_T c5_gamma3min[100];
  real_T c5_gamma3max[100];
  real_T c5_C1[200];
  real_T c5_l;
  real_T c5_gamma[200];
  real_T c5_u_work[100];
  const mxArray *c5_options = NULL;
  real_T c5_nargin = 17.0;
  real_T c5_nargout = 1.0;
  real_T c5_d_u[2];
  int32_T c5_i28;
  real_T c5_b_b;
  int32_T c5_i29;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  real_T c5_a[10000];
  real_T c5_b_y[10000];
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  real_T c5_b_a[500];
  int32_T c5_i49;
  real_T c5_c_b[5];
  int32_T c5_i50;
  real_T c5_c_y[100];
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  real_T c5_d_b[100];
  real_T c5_d_y[100];
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_b_k;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_c_k;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i70;
  int32_T c5_d_k;
  int32_T c5_e_k;
  real_T c5_dv1[4];
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_b_l;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i80;
  int32_T c5_i81;
  real_T c5_dv2[4];
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  real_T c5_c_a[200];
  int32_T c5_i86;
  int32_T c5_i87;
  real_T c5_e_b[2];
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  static char_T c5_cv0[8] = { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  static char_T c5_cv1[9] = { 'A', 'l', 'g', 'o', 'r', 'i', 't', 'h', 'm' };

  static char_T c5_cv2[21] = { 'i', 'n', 't', 'e', 'r', 'i', 'o', 'r', '-', 'p',
    'o', 'i', 'n', 't', '-', 'c', 'o', 'n', 'v', 'e', 'x' };

  real_T c5_dv3[100];
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i100;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *chartInstance->c5_C;
  c5_b_hoistedGlobal = *chartInstance->c5_dv;
  c5_c_hoistedGlobal = *chartInstance->c5_Ymin;
  c5_d_hoistedGlobal = *chartInstance->c5_Ymax;
  for (c5_i15 = 0; c5_i15 < 500; c5_i15++) {
    c5_b_F[c5_i15] = (*chartInstance->c5_F)[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 10000; c5_i16++) {
    chartInstance->c5_H[c5_i16] = (*chartInstance->c5_b_H)[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 10000; c5_i17++) {
    chartInstance->c5_G[c5_i17] = (*chartInstance->c5_b_G)[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 10; c5_i18++) {
    c5_b_Bu[c5_i18] = (*chartInstance->c5_Bu)[c5_i18];
  }

  c5_b_C = c5_hoistedGlobal;
  for (c5_i19 = 0; c5_i19 < 10000; c5_i19++) {
    chartInstance->c5_Rw[c5_i19] = (*chartInstance->c5_b_Rw)[c5_i19];
  }

  for (c5_i20 = 0; c5_i20 < 10000; c5_i20++) {
    chartInstance->c5_Qw[c5_i20] = (*chartInstance->c5_b_Qw)[c5_i20];
  }

  for (c5_i21 = 0; c5_i21 < 100; c5_i21++) {
    c5_b_ref[c5_i21] = (*chartInstance->c5_ref)[c5_i21];
  }

  for (c5_i22 = 0; c5_i22 < 5; c5_i22++) {
    c5_b_dx[c5_i22] = (*chartInstance->c5_dx)[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 2; c5_i23++) {
    c5_c_u[c5_i23] = (*chartInstance->c5_b_u)[c5_i23];
  }

  c5_b_dv = c5_b_hoistedGlobal;
  for (c5_i24 = 0; c5_i24 < 2; c5_i24++) {
    c5_b_dUmin[c5_i24] = (*chartInstance->c5_dUmin)[c5_i24];
  }

  for (c5_i25 = 0; c5_i25 < 2; c5_i25++) {
    c5_b_dUmax[c5_i25] = (*chartInstance->c5_dUmax)[c5_i25];
  }

  for (c5_i26 = 0; c5_i26 < 2; c5_i26++) {
    c5_b_Umin[c5_i26] = (*chartInstance->c5_Umin)[c5_i26];
  }

  for (c5_i27 = 0; c5_i27 < 2; c5_i27++) {
    c5_b_Umax[c5_i27] = (*chartInstance->c5_Umax)[c5_i27];
  }

  c5_b_Ymin = c5_c_hoistedGlobal;
  c5_b_Ymax = c5_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 41U, 42U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_s1, 0U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_s2, 1U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_s3, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_Nu, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_N2, 4U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_v_vec, 5U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c5_E, 6U,
    c5_e_sf_marshallOut, c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_f, 7U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_gamma1min, 8U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_gamma1max, 9U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_gamma2min, 10U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_gamma2max, 11U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_k, 12U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_gamma3min, 13U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_gamma3max, 14U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_C1, 15U, c5_k_sf_marshallOut,
    c5_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c5_C2, 16U,
    c5_e_sf_marshallOut, c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_l, 17U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c5_M, 18U,
    c5_j_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_gamma, 19U, c5_i_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_u_work, 20U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_options, 21U, c5_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 22U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 23U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_F, 24U, c5_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c5_H, 25U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c5_G, 26U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_Bu, 27U, c5_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_C, 28U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c5_Rw, 29U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c5_Qw, 30U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_ref, 31U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_dx, 32U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_c_u, 33U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_dv, 34U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_dUmin, 35U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_dUmax, 36U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_Umin, 37U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_Umax, 38U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_Ymin, 39U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_Ymax, 40U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_d_u, MAX_uint32_T, c5_sf_marshallOut,
    c5_sf_marshallIn);
  for (c5_i28 = 0; c5_i28 < 2; c5_i28++) {
    c5_d_u[c5_i28] = c5_c_u[c5_i28];
  }

  _SFD_SYMBOL_SWITCH(33U, 41U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_s1 = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_s2 = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_s3 = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_Nu = 50.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_N2 = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_b_b = c5_b_dv;
  for (c5_i29 = 0; c5_i29 < 100; c5_i29++) {
    c5_v_vec[c5_i29] = c5_b_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_i30 = 0;
  for (c5_i31 = 0; c5_i31 < 100; c5_i31++) {
    c5_i33 = 0;
    for (c5_i34 = 0; c5_i34 < 100; c5_i34++) {
      c5_a[c5_i34 + c5_i30] = chartInstance->c5_H[c5_i33 + c5_i31];
      c5_i33 += 100;
    }

    c5_i30 += 100;
  }

  for (c5_i32 = 0; c5_i32 < 10000; c5_i32++) {
    chartInstance->c5_b[c5_i32] = chartInstance->c5_Rw[c5_i32];
  }

  for (c5_i35 = 0; c5_i35 < 10000; c5_i35++) {
    c5_b_y[c5_i35] = 0.0;
  }

  c5_c_xgemm(chartInstance, c5_a, chartInstance->c5_b, c5_b_y);
  for (c5_i36 = 0; c5_i36 < 10000; c5_i36++) {
    chartInstance->c5_b[c5_i36] = chartInstance->c5_H[c5_i36];
  }

  for (c5_i37 = 0; c5_i37 < 10000; c5_i37++) {
    c5_a[c5_i37] = 0.0;
  }

  c5_c_xgemm(chartInstance, c5_b_y, chartInstance->c5_b, c5_a);
  for (c5_i38 = 0; c5_i38 < 10000; c5_i38++) {
    c5_a[c5_i38] += chartInstance->c5_Qw[c5_i38];
  }

  for (c5_i39 = 0; c5_i39 < 10000; c5_i39++) {
    chartInstance->c5_E[c5_i39] = 2.0 * c5_a[c5_i39];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_i40 = 0;
  for (c5_i41 = 0; c5_i41 < 100; c5_i41++) {
    c5_i43 = 0;
    for (c5_i44 = 0; c5_i44 < 100; c5_i44++) {
      chartInstance->c5_b[c5_i44 + c5_i40] = chartInstance->c5_H[c5_i43 + c5_i41];
      c5_i43 += 100;
    }

    c5_i40 += 100;
  }

  for (c5_i42 = 0; c5_i42 < 10000; c5_i42++) {
    chartInstance->c5_b[c5_i42] *= 2.0;
  }

  for (c5_i45 = 0; c5_i45 < 10000; c5_i45++) {
    c5_a[c5_i45] = chartInstance->c5_Rw[c5_i45];
  }

  for (c5_i46 = 0; c5_i46 < 10000; c5_i46++) {
    c5_b_y[c5_i46] = 0.0;
  }

  c5_c_xgemm(chartInstance, chartInstance->c5_b, c5_a, c5_b_y);
  for (c5_i47 = 0; c5_i47 < 500; c5_i47++) {
    c5_b_a[c5_i47] = c5_b_F[c5_i47];
  }

  for (c5_i48 = 0; c5_i48 < 5; c5_i48++) {
    c5_c_b[c5_i48] = c5_b_dx[c5_i48];
  }

  for (c5_i49 = 0; c5_i49 < 100; c5_i49++) {
    c5_c_y[c5_i49] = 0.0;
    c5_i51 = 0;
    for (c5_i52 = 0; c5_i52 < 5; c5_i52++) {
      c5_c_y[c5_i49] += c5_b_a[c5_i51 + c5_i49] * c5_c_b[c5_i52];
      c5_i51 += 100;
    }
  }

  for (c5_i50 = 0; c5_i50 < 10000; c5_i50++) {
    c5_a[c5_i50] = chartInstance->c5_G[c5_i50];
  }

  for (c5_i53 = 0; c5_i53 < 100; c5_i53++) {
    c5_d_b[c5_i53] = c5_v_vec[c5_i53];
  }

  for (c5_i54 = 0; c5_i54 < 100; c5_i54++) {
    c5_d_y[c5_i54] = 0.0;
  }

  c5_d_xgemm(chartInstance, c5_a, c5_d_b, c5_d_y);
  for (c5_i55 = 0; c5_i55 < 100; c5_i55++) {
    c5_c_y[c5_i55] = (c5_b_ref[c5_i55] - c5_c_y[c5_i55]) - c5_d_y[c5_i55];
  }

  for (c5_i56 = 0; c5_i56 < 100; c5_i56++) {
    c5_f[c5_i56] = 0.0;
  }

  for (c5_i57 = 0; c5_i57 < 100; c5_i57++) {
    c5_d_b[c5_i57] = 0.0;
  }

  c5_d_xgemm(chartInstance, c5_b_y, c5_c_y, c5_d_b);
  for (c5_i58 = 0; c5_i58 < 100; c5_i58++) {
    c5_f[c5_i58] = c5_d_b[c5_i58];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i59 = 0; c5_i59 < 100; c5_i59++) {
    c5_gamma1min[c5_i59] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  for (c5_i60 = 0; c5_i60 < 100; c5_i60++) {
    c5_gamma1max[c5_i60] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  for (c5_i61 = 0; c5_i61 < 100; c5_i61++) {
    c5_gamma2min[c5_i61] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  for (c5_i62 = 0; c5_i62 < 100; c5_i62++) {
    c5_gamma2max[c5_i62] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  c5_k = 0.0;
  c5_b_k = 0;
  while (c5_b_k < 50) {
    c5_k = (real_T)c5_b_k * 2.0;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
    for (c5_i64 = 0; c5_i64 < 2; c5_i64++) {
      c5_gamma1min[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 425, 8, MAX_uint32_T, (int32_T)sf_integer_check
        (chartInstance->S, 1U, 425U, 8U, c5_k + (real_T)(c5_i64 + 1)), 1, 100) -
        1] = c5_b_Umin[c5_i64];
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
    for (c5_i66 = 0; c5_i66 < 2; c5_i66++) {
      c5_gamma1max[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 455, 8, MAX_uint32_T, (int32_T)sf_integer_check
        (chartInstance->S, 1U, 455U, 8U, c5_k + (real_T)(c5_i66 + 1)), 1, 100) -
        1] = c5_b_Umax[c5_i66];
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
    for (c5_i67 = 0; c5_i67 < 2; c5_i67++) {
      c5_gamma2min[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 485, 8, MAX_uint32_T, (int32_T)sf_integer_check
        (chartInstance->S, 1U, 485U, 8U, c5_k + (real_T)(c5_i67 + 1)), 1, 100) -
        1] = c5_b_dUmin[c5_i67];
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
    for (c5_i68 = 0; c5_i68 < 2; c5_i68++) {
      c5_gamma2max[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 516, 8, MAX_uint32_T, (int32_T)sf_integer_check
        (chartInstance->S, 1U, 516U, 8U, c5_k + (real_T)(c5_i68 + 1)), 1, 100) -
        1] = c5_b_dUmin[c5_i68];
    }

    c5_b_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
  for (c5_i63 = 0; c5_i63 < 100; c5_i63++) {
    c5_gamma3min[c5_i63] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
  for (c5_i65 = 0; c5_i65 < 100; c5_i65++) {
    c5_gamma3max[c5_i65] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
  c5_k = 0.0;
  c5_c_k = 0;
  while (c5_c_k < 100) {
    c5_k = (real_T)c5_c_k;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
    c5_gamma3min[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 623, 8, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 623U, 8U, c5_k + 1.0), 1, 100) - 1] = c5_b_Ymin;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
    c5_gamma3max[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 651, 8, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 651U, 8U, c5_k + 1.0), 1, 100) - 1] = c5_b_Ymax;
    c5_c_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 29);
  for (c5_i69 = 0; c5_i69 < 200; c5_i69++) {
    c5_C1[c5_i69] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 30);
  for (c5_i70 = 0; c5_i70 < 10000; c5_i70++) {
    chartInstance->c5_C2[c5_i70] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 31);
  c5_k = 0.0;
  c5_d_k = 0;
  while (c5_d_k < 50) {
    c5_k = (real_T)c5_d_k * 2.0;
    CV_EML_FOR(0, 1, 2, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 32);
    c5_eye(chartInstance, c5_dv1);
    for (c5_i71 = 0; c5_i71 < 2; c5_i71++) {
      for (c5_i72 = 0; c5_i72 < 2; c5_i72++) {
        c5_C1[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                chartInstance->S, 1U, 741, 8, MAX_uint32_T, (int32_T)
                sf_integer_check(chartInstance->S, 1U, 741U, 8U, c5_k + (real_T)
                 (c5_i72 + 1)), 1, 100) + 100 * c5_i71) - 1] = c5_dv1[c5_i72 +
          (c5_i71 << 1)];
      }
    }

    c5_d_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 2, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 34);
  c5_k = 0.0;
  c5_e_k = 0;
  while (c5_e_k < 50) {
    c5_k = (real_T)c5_e_k * 2.0;
    CV_EML_FOR(0, 1, 3, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 35);
    c5_l = 0.0;
    c5_b_l = 0;
    while (c5_b_l < 50) {
      c5_l = (real_T)c5_b_l * 2.0;
      CV_EML_FOR(0, 1, 4, 1);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 36);
      if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c5_k - c5_l, 0.0, -1,
            5U, c5_k - c5_l >= 0.0))) {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 37);
        c5_eye(chartInstance, c5_dv2);
        for (c5_i83 = 0; c5_i83 < 2; c5_i83++) {
          for (c5_i86 = 0; c5_i86 < 2; c5_i86++) {
            chartInstance->c5_C2[(sf_eml_array_bounds_check
                                  (sfGlobalDebugInstanceStruct, chartInstance->S,
              1U, 821, 8, MAX_uint32_T, (int32_T)sf_integer_check
              (chartInstance->S, 1U, 821U, 8U, c5_k + (real_T)(c5_i86 + 1)), 1,
              100) + 100 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
                             830, 8, MAX_uint32_T, (int32_T)sf_integer_check
                             (chartInstance->S, 1U, 830U, 8U, c5_l + (real_T)
                              (c5_i83 + 1)), 1, 100) - 1)) - 1] = c5_dv2[c5_i86
              + (c5_i83 << 1)];
          }
        }
      } else {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 39);
        for (c5_i81 = 0; c5_i81 < 2; c5_i81++) {
          for (c5_i84 = 0; c5_i84 < 2; c5_i84++) {
            chartInstance->c5_C2[(sf_eml_array_bounds_check
                                  (sfGlobalDebugInstanceStruct, chartInstance->S,
              1U, 857, 8, MAX_uint32_T, (int32_T)sf_integer_check
              (chartInstance->S, 1U, 857U, 8U, c5_k + (real_T)(c5_i84 + 1)), 1,
              100) + 100 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
                             866, 8, MAX_uint32_T, (int32_T)sf_integer_check
                             (chartInstance->S, 1U, 866U, 8U, c5_l + (real_T)
                              (c5_i81 + 1)), 1, 100) - 1)) - 1] = 0.0;
          }
        }
      }

      c5_b_l++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 4, 0);
    c5_e_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 3, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 44);
  c5_i73 = 0;
  c5_i74 = 0;
  for (c5_i75 = 0; c5_i75 < 100; c5_i75++) {
    for (c5_i77 = 0; c5_i77 < 100; c5_i77++) {
      chartInstance->c5_M[c5_i77 + c5_i73] = -chartInstance->c5_C2[c5_i77 +
        c5_i74];
    }

    c5_i73 += 200;
    c5_i74 += 100;
  }

  c5_i76 = 0;
  c5_i78 = 0;
  for (c5_i79 = 0; c5_i79 < 100; c5_i79++) {
    for (c5_i80 = 0; c5_i80 < 100; c5_i80++) {
      chartInstance->c5_M[(c5_i80 + c5_i76) + 100] = chartInstance->c5_C2[c5_i80
        + c5_i78];
    }

    c5_i76 += 200;
    c5_i78 += 100;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 45);
  for (c5_i82 = 0; c5_i82 < 200; c5_i82++) {
    c5_c_a[c5_i82] = c5_C1[c5_i82];
  }

  for (c5_i85 = 0; c5_i85 < 2; c5_i85++) {
    c5_e_b[c5_i85] = c5_d_u[c5_i85];
  }

  for (c5_i87 = 0; c5_i87 < 100; c5_i87++) {
    c5_c_y[c5_i87] = 0.0;
    c5_i89 = 0;
    for (c5_i90 = 0; c5_i90 < 2; c5_i90++) {
      c5_c_y[c5_i87] += c5_c_a[c5_i89 + c5_i87] * c5_e_b[c5_i90];
      c5_i89 += 100;
    }
  }

  for (c5_i88 = 0; c5_i88 < 200; c5_i88++) {
    c5_c_a[c5_i88] = c5_C1[c5_i88];
  }

  for (c5_i91 = 0; c5_i91 < 2; c5_i91++) {
    c5_e_b[c5_i91] = c5_d_u[c5_i91];
  }

  for (c5_i92 = 0; c5_i92 < 100; c5_i92++) {
    c5_d_y[c5_i92] = 0.0;
    c5_i94 = 0;
    for (c5_i95 = 0; c5_i95 < 2; c5_i95++) {
      c5_d_y[c5_i92] += c5_c_a[c5_i94 + c5_i92] * c5_e_b[c5_i95];
      c5_i94 += 100;
    }
  }

  for (c5_i93 = 0; c5_i93 < 100; c5_i93++) {
    c5_gamma[c5_i93] = -c5_gamma1min[c5_i93] + c5_c_y[c5_i93];
  }

  for (c5_i96 = 0; c5_i96 < 100; c5_i96++) {
    c5_gamma[c5_i96 + 100] = c5_gamma1max[c5_i96] - c5_d_y[c5_i96];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 48);
  for (c5_i97 = 0; c5_i97 < 100; c5_i97++) {
    c5_u_work[c5_i97] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 49);
  sf_mex_assign(&c5_options, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "optimoptions", 1U, 3U, 14, c5_emlrt_marshallOut(chartInstance, c5_cv0), 14,
    c5_b_emlrt_marshallOut(chartInstance, c5_cv1), 14, c5_c_emlrt_marshallOut
    (chartInstance, c5_cv2)), false);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 50);
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "quadprog", 1U, 10U, 14,
    c5_d_emlrt_marshallOut(chartInstance, chartInstance->c5_E), 14,
    c5_e_emlrt_marshallOut(chartInstance, c5_f), 14, c5_f_emlrt_marshallOut
    (chartInstance, chartInstance->c5_M), 14, c5_g_emlrt_marshallOut
    (chartInstance, c5_gamma), 14, c5_h_emlrt_marshallOut(chartInstance), 14,
    c5_h_emlrt_marshallOut(chartInstance), 14, c5_i_emlrt_marshallOut
    (chartInstance, c5_b_dUmin), 14, c5_i_emlrt_marshallOut(chartInstance,
    c5_b_dUmax), 14, c5_e_emlrt_marshallOut(chartInstance, c5_u_work), 14,
    sf_mex_dup(c5_options)), "quadprog", c5_dv3);
  for (c5_i98 = 0; c5_i98 < 100; c5_i98++) {
    c5_u_work[c5_i98] = c5_dv3[c5_i98];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 51);
  for (c5_i99 = 0; c5_i99 < 2; c5_i99++) {
    c5_d_u[c5_i99] = c5_u_work[c5_i99];
  }

  _SFD_SYMBOL_SWITCH(33U, 41U);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -51);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c5_options);
  for (c5_i100 = 0; c5_i100 < 2; c5_i100++) {
    (*chartInstance->c5_u)[c5_i100] = c5_d_u[c5_i100];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_Simulation_der_Regler
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i101;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u[2];
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i101 = 0; c5_i101 < 2; c5_i101++) {
    c5_c_u[c5_i101] = (*(real_T (*)[2])c5_inData)[c5_i101];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const char_T *c5_identifier, real_T
  c5_b_y[2])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_c_u), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_c_u);
}

static void c5_b_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[2])
{
  real_T c5_dv4[2];
  int32_T c5_i102;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), c5_dv4, 1, 0, 0U, 1, 0U, 1, 2);
  for (c5_i102 = 0; c5_i102 < 2; c5_i102++) {
    c5_b_y[c5_i102] = c5_dv4[c5_i102];
  }

  sf_mex_destroy(&c5_c_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_c_u;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[2];
  int32_T c5_i103;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_c_u = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_c_u), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_c_u);
  for (c5_i103 = 0; c5_i103 < 2; c5_i103++) {
    (*(real_T (*)[2])c5_outData)[c5_i103] = c5_b_y[c5_i103];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_c_u;
  const mxArray *c5_b_y = NULL;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_c_u = *(real_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i104;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u[5];
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i104 = 0; c5_i104 < 5; c5_i104++) {
    c5_c_u[c5_i104] = (*(real_T (*)[5])c5_inData)[c5_i104];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i105;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u[100];
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i105 = 0; c5_i105 < 100; c5_i105++) {
    c5_c_u[c5_i105] = (*(real_T (*)[100])c5_inData)[c5_i105];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 100),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i106;
  int32_T c5_i107;
  const mxArray *c5_b_y = NULL;
  int32_T c5_i108;
  real_T c5_c_u[10000];
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i106 = 0;
  for (c5_i107 = 0; c5_i107 < 100; c5_i107++) {
    for (c5_i108 = 0; c5_i108 < 100; c5_i108++) {
      c5_c_u[c5_i108 + c5_i106] = (*(real_T (*)[10000])c5_inData)[c5_i108 +
        c5_i106];
    }

    c5_i106 += 100;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 100, 100),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i109;
  int32_T c5_i110;
  const mxArray *c5_b_y = NULL;
  int32_T c5_i111;
  real_T c5_c_u[10];
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i109 = 0;
  for (c5_i110 = 0; c5_i110 < 2; c5_i110++) {
    for (c5_i111 = 0; c5_i111 < 5; c5_i111++) {
      c5_c_u[c5_i111 + c5_i109] = (*(real_T (*)[10])c5_inData)[c5_i111 + c5_i109];
    }

    c5_i109 += 5;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 5, 2),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i112;
  int32_T c5_i113;
  const mxArray *c5_b_y = NULL;
  int32_T c5_i114;
  real_T c5_c_u[500];
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i112 = 0;
  for (c5_i113 = 0; c5_i113 < 5; c5_i113++) {
    for (c5_i114 = 0; c5_i114 < 100; c5_i114++) {
      c5_c_u[c5_i114 + c5_i112] = (*(real_T (*)[500])c5_inData)[c5_i114 +
        c5_i112];
    }

    c5_i112 += 100;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 100, 5),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_b_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_b_y = c5_d0;
  sf_mex_destroy(&c5_c_u);
  return c5_b_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout),
    &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  const mxArray *c5_c_u;
  const mxArray *c5_b_y = NULL;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_c_u = sf_mex_dup(*(const mxArray **)c5_inData);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_duplicatearraysafe(&c5_c_u), false);
  sf_mex_destroy(&c5_c_u);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_quadprog;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[100];
  int32_T c5_i115;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_quadprog = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_quadprog), &c5_thisId,
                        c5_b_y);
  sf_mex_destroy(&c5_quadprog);
  for (c5_i115 = 0; c5_i115 < 100; c5_i115++) {
    (*(real_T (*)[100])c5_outData)[c5_i115] = c5_b_y[c5_i115];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i116;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u[200];
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i116 = 0; c5_i116 < 200; c5_i116++) {
    c5_c_u[c5_i116] = (*(real_T (*)[200])c5_inData)[c5_i116];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 200),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_d_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[200])
{
  real_T c5_dv5[200];
  int32_T c5_i117;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), c5_dv5, 1, 0, 0U, 1, 0U, 1, 200);
  for (c5_i117 = 0; c5_i117 < 200; c5_i117++) {
    c5_b_y[c5_i117] = c5_dv5[c5_i117];
  }

  sf_mex_destroy(&c5_c_u);
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_gamma;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[200];
  int32_T c5_i118;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_gamma = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_gamma), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_gamma);
  for (c5_i118 = 0; c5_i118 < 200; c5_i118++) {
    (*(real_T (*)[200])c5_outData)[c5_i118] = c5_b_y[c5_i118];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i119;
  int32_T c5_i120;
  const mxArray *c5_b_y = NULL;
  int32_T c5_i121;
  real_T c5_c_u[20000];
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i119 = 0;
  for (c5_i120 = 0; c5_i120 < 100; c5_i120++) {
    for (c5_i121 = 0; c5_i121 < 200; c5_i121++) {
      c5_c_u[c5_i121 + c5_i119] = (*(real_T (*)[20000])c5_inData)[c5_i121 +
        c5_i119];
    }

    c5_i119 += 200;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 200, 100),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_e_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[20000])
{
  real_T c5_dv6[20000];
  int32_T c5_i122;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), c5_dv6, 1, 0, 0U, 1, 0U, 2, 200,
                100);
  for (c5_i122 = 0; c5_i122 < 20000; c5_i122++) {
    c5_b_y[c5_i122] = c5_dv6[c5_i122];
  }

  sf_mex_destroy(&c5_c_u);
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_M;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_i123;
  int32_T c5_i124;
  int32_T c5_i125;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_b_M = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_M), &c5_thisId,
                        chartInstance->c5_y);
  sf_mex_destroy(&c5_b_M);
  c5_i123 = 0;
  for (c5_i124 = 0; c5_i124 < 100; c5_i124++) {
    for (c5_i125 = 0; c5_i125 < 200; c5_i125++) {
      (*(real_T (*)[20000])c5_outData)[c5_i125 + c5_i123] = chartInstance->
        c5_y[c5_i125 + c5_i123];
    }

    c5_i123 += 200;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static void c5_f_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[10000])
{
  real_T c5_dv7[10000];
  int32_T c5_i126;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), c5_dv7, 1, 0, 0U, 1, 0U, 2, 100,
                100);
  for (c5_i126 = 0; c5_i126 < 10000; c5_i126++) {
    c5_b_y[c5_i126] = c5_dv7[c5_i126];
  }

  sf_mex_destroy(&c5_c_u);
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_C2;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[10000];
  int32_T c5_i127;
  int32_T c5_i128;
  int32_T c5_i129;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_b_C2 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_C2), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_b_C2);
  c5_i127 = 0;
  for (c5_i128 = 0; c5_i128 < 100; c5_i128++) {
    for (c5_i129 = 0; c5_i129 < 100; c5_i129++) {
      (*(real_T (*)[10000])c5_outData)[c5_i129 + c5_i127] = c5_b_y[c5_i129 +
        c5_i127];
    }

    c5_i127 += 100;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i130;
  int32_T c5_i131;
  const mxArray *c5_b_y = NULL;
  int32_T c5_i132;
  real_T c5_c_u[200];
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i130 = 0;
  for (c5_i131 = 0; c5_i131 < 2; c5_i131++) {
    for (c5_i132 = 0; c5_i132 < 100; c5_i132++) {
      c5_c_u[c5_i132 + c5_i130] = (*(real_T (*)[200])c5_inData)[c5_i132 +
        c5_i130];
    }

    c5_i130 += 100;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 100, 2),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_g_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[200])
{
  real_T c5_dv8[200];
  int32_T c5_i133;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), c5_dv8, 1, 0, 0U, 1, 0U, 2, 100,
                2);
  for (c5_i133 = 0; c5_i133 < 200; c5_i133++) {
    c5_b_y[c5_i133] = c5_dv8[c5_i133];
  }

  sf_mex_destroy(&c5_c_u);
}

static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_C1;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[200];
  int32_T c5_i134;
  int32_T c5_i135;
  int32_T c5_i136;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_C1 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_C1), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_C1);
  c5_i134 = 0;
  for (c5_i135 = 0; c5_i135 < 2; c5_i135++) {
    for (c5_i136 = 0; c5_i136 < 100; c5_i136++) {
      (*(real_T (*)[200])c5_outData)[c5_i136 + c5_i134] = c5_b_y[c5_i136 +
        c5_i134];
    }

    c5_i134 += 100;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_Simulation_der_Regler_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static void c5_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_xgemm(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
                     real_T c5_A[10000], real_T c5_B[10000], real_T c5_b_C[10000],
                     real_T c5_c_C[10000])
{
  int32_T c5_i137;
  int32_T c5_i138;
  int32_T c5_i139;
  real_T c5_b_A[10000];
  real_T c5_b_B[10000];
  for (c5_i137 = 0; c5_i137 < 10000; c5_i137++) {
    c5_c_C[c5_i137] = c5_b_C[c5_i137];
  }

  for (c5_i138 = 0; c5_i138 < 10000; c5_i138++) {
    c5_b_A[c5_i138] = c5_A[c5_i138];
  }

  for (c5_i139 = 0; c5_i139 < 10000; c5_i139++) {
    c5_b_B[c5_i139] = c5_B[c5_i139];
  }

  c5_c_xgemm(chartInstance, c5_b_A, c5_b_B, c5_c_C);
}

static void c5_b_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_c_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_d_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_e_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_f_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_b_xgemm(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c5_A[10000], real_T c5_B[100], real_T c5_b_C[100], real_T c5_c_C[100])
{
  int32_T c5_i140;
  int32_T c5_i141;
  int32_T c5_i142;
  real_T c5_b_A[10000];
  real_T c5_b_B[100];
  for (c5_i140 = 0; c5_i140 < 100; c5_i140++) {
    c5_c_C[c5_i140] = c5_b_C[c5_i140];
  }

  for (c5_i141 = 0; c5_i141 < 10000; c5_i141++) {
    c5_b_A[c5_i141] = c5_A[c5_i141];
  }

  for (c5_i142 = 0; c5_i142 < 100; c5_i142++) {
    c5_b_B[c5_i142] = c5_B[c5_i142];
  }

  c5_d_xgemm(chartInstance, c5_b_A, c5_b_B, c5_c_C);
}

static void c5_eye(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
                   real_T c5_I[4])
{
  int32_T c5_i143;
  int32_T c5_k;
  int32_T c5_b_k;
  (void)chartInstance;
  for (c5_i143 = 0; c5_i143 < 4; c5_i143++) {
    c5_I[c5_i143] = 0.0;
  }

  for (c5_k = 1; c5_k < 3; c5_k++) {
    c5_b_k = c5_k - 1;
    c5_I[c5_b_k + (c5_b_k << 1)] = 1.0;
  }
}

static void c5_g_scalarEg(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c5_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const char_T c5_c_u
   [8])
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 10, 0U, 1U, 0U, 2, 1, 8),
                false);
  return c5_b_y;
}

static const mxArray *c5_b_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const char_T c5_c_u
   [9])
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 10, 0U, 1U, 0U, 2, 1, 9),
                false);
  return c5_b_y;
}

static const mxArray *c5_c_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const char_T c5_c_u
   [21])
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  return c5_b_y;
}

static const mxArray *c5_d_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [10000])
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 100, 100),
                false);
  return c5_b_y;
}

static const mxArray *c5_e_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [100])
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 100),
                false);
  return c5_b_y;
}

static const mxArray *c5_f_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [20000])
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 200, 100),
                false);
  return c5_b_y;
}

static const mxArray *c5_g_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [200])
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 200),
                false);
  return c5_b_y;
}

static const mxArray *c5_h_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance)
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  return c5_b_y;
}

static const mxArray *c5_i_emlrt_marshallOut
  (SFc5_Simulation_der_ReglerInstanceStruct *chartInstance, const real_T c5_c_u
   [2])
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 2), false);
  return c5_b_y;
}

static void c5_h_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_quadprog, const char_T *c5_identifier,
  real_T c5_b_y[100])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_quadprog), &c5_thisId,
                        c5_b_y);
  sf_mex_destroy(&c5_quadprog);
}

static void c5_i_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_b_y[100])
{
  real_T c5_dv9[100];
  int32_T c5_i144;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), c5_dv9, 1, 0, 0U, 1, 0U, 1, 100);
  for (c5_i144 = 0; c5_i144 < 100; c5_i144++) {
    c5_b_y[c5_i144] = c5_dv9[c5_i144];
  }

  sf_mex_destroy(&c5_c_u);
}

static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_c_u;
  const mxArray *c5_b_y = NULL;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_c_u = *(int32_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_j_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_b_y;
  int32_T c5_i145;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), &c5_i145, 1, 6, 0U, 0, 0U, 0);
  c5_b_y = c5_i145;
  sf_mex_destroy(&c5_c_u);
  return c5_b_y;
}

static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_b_y;
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_k_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_Simulation_der_Regler, const
  char_T *c5_identifier)
{
  uint8_T c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_Simulation_der_Regler), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_Simulation_der_Regler);
  return c5_b_y;
}

static uint8_T c5_l_emlrt_marshallIn(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance, const mxArray *c5_c_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_b_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_c_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_b_y = c5_u0;
  sf_mex_destroy(&c5_c_u);
  return c5_b_y;
}

static void c5_c_xgemm(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c5_A[10000], real_T c5_B[10000], real_T c5_b_C[10000])
{
  real_T c5_alpha1;
  real_T c5_beta1;
  char_T c5_TRANSB;
  char_T c5_TRANSA;
  ptrdiff_t c5_m_t;
  ptrdiff_t c5_n_t;
  ptrdiff_t c5_k_t;
  ptrdiff_t c5_lda_t;
  ptrdiff_t c5_ldb_t;
  ptrdiff_t c5_ldc_t;
  (void)chartInstance;
  c5_alpha1 = 1.0;
  c5_beta1 = 0.0;
  c5_TRANSB = 'N';
  c5_TRANSA = 'N';
  c5_m_t = (ptrdiff_t)100;
  c5_n_t = (ptrdiff_t)100;
  c5_k_t = (ptrdiff_t)100;
  c5_lda_t = (ptrdiff_t)100;
  c5_ldb_t = (ptrdiff_t)100;
  c5_ldc_t = (ptrdiff_t)100;
  dgemm(&c5_TRANSA, &c5_TRANSB, &c5_m_t, &c5_n_t, &c5_k_t, &c5_alpha1, &c5_A[0],
        &c5_lda_t, &c5_B[0], &c5_ldb_t, &c5_beta1, &c5_b_C[0], &c5_ldc_t);
}

static void c5_d_xgemm(SFc5_Simulation_der_ReglerInstanceStruct *chartInstance,
  real_T c5_A[10000], real_T c5_B[100], real_T c5_b_C[100])
{
  real_T c5_alpha1;
  real_T c5_beta1;
  char_T c5_TRANSB;
  char_T c5_TRANSA;
  ptrdiff_t c5_m_t;
  ptrdiff_t c5_n_t;
  ptrdiff_t c5_k_t;
  ptrdiff_t c5_lda_t;
  ptrdiff_t c5_ldb_t;
  ptrdiff_t c5_ldc_t;
  (void)chartInstance;
  c5_alpha1 = 1.0;
  c5_beta1 = 0.0;
  c5_TRANSB = 'N';
  c5_TRANSA = 'N';
  c5_m_t = (ptrdiff_t)100;
  c5_n_t = (ptrdiff_t)1;
  c5_k_t = (ptrdiff_t)100;
  c5_lda_t = (ptrdiff_t)100;
  c5_ldb_t = (ptrdiff_t)100;
  c5_ldc_t = (ptrdiff_t)100;
  dgemm(&c5_TRANSA, &c5_TRANSB, &c5_m_t, &c5_n_t, &c5_k_t, &c5_alpha1, &c5_A[0],
        &c5_lda_t, &c5_B[0], &c5_ldb_t, &c5_beta1, &c5_b_C[0], &c5_ldc_t);
}

static void init_dsm_address_info(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_Simulation_der_ReglerInstanceStruct
  *chartInstance)
{
  chartInstance->c5_F = (real_T (*)[500])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_u = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_b_H = (real_T (*)[10000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_b_G = (real_T (*)[10000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_Bu = (real_T (*)[10])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c5_C = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c5_b_Rw = (real_T (*)[10000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c5_b_Qw = (real_T (*)[10000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c5_ref = (real_T (*)[100])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c5_dx = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c5_b_u = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c5_dv = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    10);
  chartInstance->c5_dUmin = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c5_dUmax = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c5_Umin = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c5_Umax = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c5_Ymin = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c5_Ymax = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 16);
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

void sf_c5_Simulation_der_Regler_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1718119171U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2971819657U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3933618129U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(13544641U);
}

mxArray* sf_c5_Simulation_der_Regler_get_post_codegen_info(void);
mxArray *sf_c5_Simulation_der_Regler_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IXRkucEPuUIsOXE0DEoGQ");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,17,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      pr[1] = (double)(5);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      pr[1] = (double)(100);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
      pr[1] = (double)(100);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(100);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));
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
      sf_c5_Simulation_der_Regler_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_Simulation_der_Regler_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c5_Simulation_der_Regler_jit_fallback_info(void)
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

mxArray *sf_c5_Simulation_der_Regler_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_Simulation_der_Regler_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c5_Simulation_der_Regler(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u\",},{M[8],M[0],T\"is_active_c5_Simulation_der_Regler\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Simulation_der_Regler_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_Simulation_der_ReglerInstanceStruct *chartInstance =
      (SFc5_Simulation_der_ReglerInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Simulation_der_ReglerMachineNumber_,
           5,
           1,
           1,
           0,
           18,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"F");
          _SFD_SET_DATA_PROPS(1,1,1,0,"H");
          _SFD_SET_DATA_PROPS(2,1,1,0,"G");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Bu");
          _SFD_SET_DATA_PROPS(4,1,1,0,"C");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Rw");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Qw");
          _SFD_SET_DATA_PROPS(7,1,1,0,"ref");
          _SFD_SET_DATA_PROPS(8,1,1,0,"dx");
          _SFD_SET_DATA_PROPS(9,1,1,0,"u");
          _SFD_SET_DATA_PROPS(10,1,1,0,"dv");
          _SFD_SET_DATA_PROPS(11,1,1,0,"dUmin");
          _SFD_SET_DATA_PROPS(12,1,1,0,"dUmax");
          _SFD_SET_DATA_PROPS(13,1,1,0,"Umin");
          _SFD_SET_DATA_PROPS(14,1,1,0,"Umax");
          _SFD_SET_DATA_PROPS(15,1,1,0,"Ymin");
          _SFD_SET_DATA_PROPS(16,1,1,0,"Ymax");
          _SFD_SET_DATA_PROPS(17,2,0,1,"u");
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
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0,5,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1265);
        _SFD_CV_INIT_EML_IF(0,1,0,808,817,849,894);
        _SFD_CV_INIT_EML_FOR(0,1,0,392,413,538);
        _SFD_CV_INIT_EML_FOR(0,1,1,592,613,672);
        _SFD_CV_INIT_EML_FOR(0,1,2,717,738,765);
        _SFD_CV_INIT_EML_FOR(0,1,3,766,787,902);
        _SFD_CV_INIT_EML_FOR(0,1,4,787,808,898);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,811,817,-1,5);

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 5U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 5U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 100U;
          dimVector[1]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 100U;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5U;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
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
    SFc5_Simulation_der_ReglerInstanceStruct *chartInstance =
      (SFc5_Simulation_der_ReglerInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c5_F);
        _SFD_SET_DATA_VALUE_PTR(17U, *chartInstance->c5_u);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c5_b_H);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c5_b_G);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c5_Bu);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c5_C);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c5_b_Rw);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c5_b_Qw);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c5_ref);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c5_dx);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c5_b_u);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c5_dv);
        _SFD_SET_DATA_VALUE_PTR(11U, *chartInstance->c5_dUmin);
        _SFD_SET_DATA_VALUE_PTR(12U, *chartInstance->c5_dUmax);
        _SFD_SET_DATA_VALUE_PTR(13U, *chartInstance->c5_Umin);
        _SFD_SET_DATA_VALUE_PTR(14U, *chartInstance->c5_Umax);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c5_Ymin);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c5_Ymax);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "slpp76p6kmOyqxTOHWV4ArB";
}

static void sf_opaque_initialize_c5_Simulation_der_Regler(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_Simulation_der_Regler
    ((SFc5_Simulation_der_ReglerInstanceStruct*) chartInstanceVar);
  initialize_c5_Simulation_der_Regler((SFc5_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_Simulation_der_Regler(void *chartInstanceVar)
{
  enable_c5_Simulation_der_Regler((SFc5_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_Simulation_der_Regler(void *chartInstanceVar)
{
  disable_c5_Simulation_der_Regler((SFc5_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_Simulation_der_Regler(void *chartInstanceVar)
{
  sf_gateway_c5_Simulation_der_Regler((SFc5_Simulation_der_ReglerInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_Simulation_der_Regler(SimStruct*
  S)
{
  return get_sim_state_c5_Simulation_der_Regler
    ((SFc5_Simulation_der_ReglerInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_Simulation_der_Regler(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c5_Simulation_der_Regler
    ((SFc5_Simulation_der_ReglerInstanceStruct*)sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c5_Simulation_der_Regler(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_Simulation_der_ReglerInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Simulation_der_Regler_optimization_info();
    }

    finalize_c5_Simulation_der_Regler((SFc5_Simulation_der_ReglerInstanceStruct*)
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
  initSimStructsc5_Simulation_der_Regler
    ((SFc5_Simulation_der_ReglerInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Simulation_der_Regler(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_Simulation_der_Regler
      ((SFc5_Simulation_der_ReglerInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c5_Simulation_der_Regler(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortOverWritable(S, 9, 1);
  ssSetOutputPortOverwritesInputPort(S, 1, 9);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Simulation_der_Regler_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 5);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,5);
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
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,17);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 17; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(425460074U));
  ssSetChecksum1(S,(1111212740U));
  ssSetChecksum2(S,(2650748957U));
  ssSetChecksum3(S,(2170502364U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_Simulation_der_Regler(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Simulation_der_Regler(SimStruct *S)
{
  SFc5_Simulation_der_ReglerInstanceStruct *chartInstance;
  chartInstance = (SFc5_Simulation_der_ReglerInstanceStruct *)utMalloc(sizeof
    (SFc5_Simulation_der_ReglerInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_Simulation_der_ReglerInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_Simulation_der_Regler;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_Simulation_der_Regler;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_Simulation_der_Regler;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_Simulation_der_Regler;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_Simulation_der_Regler;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_Simulation_der_Regler;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_Simulation_der_Regler;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_Simulation_der_Regler;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Simulation_der_Regler;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Simulation_der_Regler;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_Simulation_der_Regler;
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
  mdl_start_c5_Simulation_der_Regler(chartInstance);
}

void c5_Simulation_der_Regler_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Simulation_der_Regler(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Simulation_der_Regler(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Simulation_der_Regler(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Simulation_der_Regler_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
