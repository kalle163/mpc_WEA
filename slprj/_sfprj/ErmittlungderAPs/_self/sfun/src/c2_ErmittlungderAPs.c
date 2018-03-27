/* Include files */

#include "ErmittlungderAPs_sfun.h"
#include "c2_ErmittlungderAPs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ErmittlungderAPs_sfun_debug_macros.h"
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
static const char * c2_debug_family_names[18] = { "lambda_local",
  "lambda_i_local", "f_0_local", "f_1_local", "f_2_local", "f_3_local",
  "CM_tilde_local", "CM_local", "nargin", "nargout", "wr", "R", "c", "v_c",
  "theta_c", "rho", "n_g_inv", "Mr" };

/* Function Declarations */
static void initialize_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance);
static void initialize_params_c2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance);
static void enable_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance);
static void disable_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance);
static void set_sim_state_c2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance);
static void sf_gateway_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance);
static void mdl_start_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance);
static void initSimStructsc2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_b_Mr, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_mpower(SFc2_ErmittlungderAPsInstanceStruct *chartInstance,
  real_T c2_a);
static void c2_scalarEg(SFc2_ErmittlungderAPsInstanceStruct *chartInstance);
static void c2_dimagree(SFc2_ErmittlungderAPsInstanceStruct *chartInstance);
static boolean_T c2_fltpower_domain_error(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, real_T c2_a, real_T c2_b);
static void c2_error(SFc2_ErmittlungderAPsInstanceStruct *chartInstance);
static real_T c2_b_mpower(SFc2_ErmittlungderAPsInstanceStruct *chartInstance,
  real_T c2_a);
static void c2_b_error(SFc2_ErmittlungderAPsInstanceStruct *chartInstance);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_ErmittlungderAPs, const
  char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_ErmittlungderAPs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_ErmittlungderAPs = 0U;
}

static void initialize_params_c2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_Mr;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_ErmittlungderAPs;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_Mr = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Mr", c2_u, 0)), "Mr");
  chartInstance->c2_is_active_c2_ErmittlungderAPs = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c2_ErmittlungderAPs",
       c2_u, 1)), "is_active_c2_ErmittlungderAPs");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_ErmittlungderAPs(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance)
{
  int32_T c2_i0;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_n_g_inv, 6U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_rho, 5U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_theta_c, 4U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_v_c, 3U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  for (c2_i0 = 0; c2_i0 < 12; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_c)[c2_i0], 2U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_R, 1U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_wr, 0U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_ErmittlungderAPs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ErmittlungderAPsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_Mr, 7U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
}

static void mdl_start_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_chartstep_c2_ErmittlungderAPs(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_b_wr;
  real_T c2_b_R;
  int32_T c2_i1;
  real_T c2_b_v_c;
  real_T c2_b_c[12];
  real_T c2_b_theta_c;
  real_T c2_b_rho;
  real_T c2_b_n_g_inv;
  uint32_T c2_debug_family_var_map[18];
  real_T c2_lambda_local;
  real_T c2_lambda_i_local;
  real_T c2_f_0_local;
  real_T c2_f_1_local;
  real_T c2_f_2_local;
  real_T c2_f_3_local;
  real_T c2_CM_tilde_local;
  real_T c2_CM_local;
  real_T c2_nargin = 7.0;
  real_T c2_nargout = 1.0;
  real_T c2_b_Mr;
  real_T c2_A;
  real_T c2_B;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_b_B;
  real_T c2_c_y;
  real_T c2_d_y;
  real_T c2_e_y;
  real_T c2_c_B;
  real_T c2_f_y;
  real_T c2_g_y;
  real_T c2_h_y;
  real_T c2_b_A;
  real_T c2_d_B;
  real_T c2_c_x;
  real_T c2_i_y;
  real_T c2_d_x;
  real_T c2_j_y;
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_e_x;
  real_T c2_k_y;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_ar;
  real_T c2_br;
  real_T c2_c_c;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_c_A;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_e_a;
  real_T c2_f_a;
  real_T c2_g_a;
  real_T c2_m_x;
  real_T c2_h_a;
  real_T c2_d_c;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_wr;
  c2_b_hoistedGlobal = *chartInstance->c2_R;
  c2_c_hoistedGlobal = *chartInstance->c2_v_c;
  c2_d_hoistedGlobal = *chartInstance->c2_theta_c;
  c2_e_hoistedGlobal = *chartInstance->c2_rho;
  c2_f_hoistedGlobal = *chartInstance->c2_n_g_inv;
  c2_b_wr = c2_hoistedGlobal;
  c2_b_R = c2_b_hoistedGlobal;
  for (c2_i1 = 0; c2_i1 < 12; c2_i1++) {
    c2_b_c[c2_i1] = (*chartInstance->c2_c)[c2_i1];
  }

  c2_b_v_c = c2_c_hoistedGlobal;
  c2_b_theta_c = c2_d_hoistedGlobal;
  c2_b_rho = c2_e_hoistedGlobal;
  c2_b_n_g_inv = c2_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_lambda_local, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_lambda_i_local, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_0_local, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_1_local, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_2_local, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_f_3_local, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_CM_tilde_local, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_CM_local, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_wr, 10U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_R, 11U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_c, 12U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_v_c, 13U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_theta_c, 14U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_rho, 15U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_n_g_inv, 16U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_Mr, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c2_b_wr, 0.5, -1, 2U,
        c2_b_wr < 0.5))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
    c2_b_wr = 1.2671;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_A = c2_b_wr * c2_b_R;
  c2_B = c2_b_v_c;
  c2_x = c2_A;
  c2_y = c2_B;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  c2_lambda_local = c2_b_x / c2_b_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_b_B = c2_lambda_local + 0.08 * c2_b_theta_c;
  c2_c_y = c2_b_B;
  c2_d_y = c2_c_y;
  c2_e_y = 1.0 / c2_d_y;
  c2_c_B = c2_b_c[10] + c2_b_c[11] * c2_mpower(chartInstance, c2_b_theta_c);
  c2_f_y = c2_c_B;
  c2_g_y = c2_f_y;
  c2_h_y = 0.035 / c2_g_y;
  c2_lambda_i_local = c2_e_y - c2_h_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_f_0_local = c2_b_c[0] * (1.0 + c2_b_c[1] * c2_b_mpower(chartInstance,
    c2_b_theta_c + c2_b_c[2]));
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_b_A = c2_b_c[3];
  c2_d_B = c2_lambda_local;
  c2_c_x = c2_b_A;
  c2_i_y = c2_d_B;
  c2_d_x = c2_c_x;
  c2_j_y = c2_i_y;
  c2_f_1_local = c2_d_x / c2_j_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_a = c2_b_theta_c;
  c2_b = c2_b_c[7];
  c2_b_a = c2_a;
  c2_b_b = c2_b;
  c2_c_a = c2_b_a;
  c2_c_b = c2_b_b;
  c2_e_x = c2_c_a;
  c2_k_y = c2_c_b;
  c2_d_a = c2_e_x;
  c2_d_b = c2_k_y;
  c2_ar = c2_d_a;
  c2_br = c2_d_b;
  c2_c_c = muDoubleScalarPower(c2_ar, c2_br);
  if (c2_fltpower_domain_error(chartInstance, c2_c_a, c2_c_b)) {
    c2_error(chartInstance);
  }

  c2_f_2_local = ((c2_b_c[4] * c2_lambda_i_local - c2_b_c[5] * c2_b_theta_c) -
                  c2_b_c[6] * c2_c_c) - c2_b_c[8];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_f_x = -c2_b_c[9] * c2_lambda_i_local;
  c2_f_3_local = c2_f_x;
  c2_g_x = c2_f_3_local;
  c2_f_3_local = c2_g_x;
  c2_h_x = c2_f_3_local;
  c2_f_3_local = c2_h_x;
  c2_f_3_local = muDoubleScalarExp(c2_f_3_local);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_CM_tilde_local = c2_f_0_local + c2_f_1_local * c2_f_2_local * c2_f_3_local;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_i_x = c2_CM_tilde_local;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarSign(c2_j_x);
  c2_c_A = c2_CM_tilde_local * (1.0 + c2_j_x);
  c2_k_x = c2_c_A;
  c2_l_x = c2_k_x;
  c2_CM_local = c2_l_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_e_a = c2_b_v_c;
  c2_f_a = c2_e_a;
  c2_g_a = c2_f_a;
  c2_m_x = c2_g_a;
  c2_h_a = c2_m_x;
  c2_d_c = c2_h_a * c2_h_a;
  if (c2_fltpower_domain_error(chartInstance, c2_g_a, 2.0)) {
    c2_error(chartInstance);
  }

  c2_b_Mr = 0.5 * c2_b_rho * 3.1415926535897931 * c2_mpower(chartInstance,
    c2_b_R) * c2_d_c * c2_CM_local * c2_b_n_g_inv;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c2_Mr = c2_b_Mr;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_ErmittlungderAPs
  (SFc2_ErmittlungderAPsInstanceStruct *chartInstance)
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
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ErmittlungderAPsInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErmittlungderAPsInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_b_Mr, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Mr), &c2_thisId);
  sf_mex_destroy(&c2_b_Mr);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_Mr;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_ErmittlungderAPsInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErmittlungderAPsInstanceStruct *)chartInstanceVoid;
  c2_b_Mr = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Mr), &c2_thisId);
  sf_mex_destroy(&c2_b_Mr);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i2;
  const mxArray *c2_y = NULL;
  real_T c2_u[12];
  SFc2_ErmittlungderAPsInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErmittlungderAPsInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i2 = 0; c2_i2 < 12; c2_i2++) {
    c2_u[c2_i2] = (*(real_T (*)[12])c2_inData)[c2_i2];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_ErmittlungderAPs_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static real_T c2_mpower(SFc2_ErmittlungderAPsInstanceStruct *chartInstance,
  real_T c2_a)
{
  real_T c2_b_c;
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_x;
  real_T c2_d_a;
  real_T c2_ar;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_x = c2_c_a;
  c2_d_a = c2_x;
  c2_ar = c2_d_a;
  c2_b_c = muDoubleScalarPower(c2_ar, 3.0);
  if (c2_fltpower_domain_error(chartInstance, c2_c_a, 3.0)) {
    c2_error(chartInstance);
  }

  return c2_b_c;
}

static void c2_scalarEg(SFc2_ErmittlungderAPsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_dimagree(SFc2_ErmittlungderAPsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c2_fltpower_domain_error(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, real_T c2_a, real_T c2_b)
{
  boolean_T c2_p;
  real_T c2_x;
  boolean_T c2_b_b;
  boolean_T c2_b0;
  real_T c2_b_x;
  real_T c2_c_x;
  boolean_T c2_b1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  (void)chartInstance;
  c2_p = false;
  if (c2_a < 0.0) {
    guard1 = false;
    if (c2_p) {
      guard1 = true;
    } else {
      c2_x = c2_b;
      c2_b_b = muDoubleScalarIsNaN(c2_x);
      guard2 = false;
      if (c2_b_b) {
        guard2 = true;
      } else {
        c2_b_x = c2_b;
        c2_c_x = c2_b_x;
        c2_c_x = muDoubleScalarFloor(c2_c_x);
        if (c2_c_x == c2_b) {
          guard2 = true;
        } else {
          c2_b1 = false;
        }
      }

      if (guard2 == true) {
        c2_b1 = true;
      }

      if (!c2_b1) {
        guard1 = true;
      } else {
        c2_b0 = false;
      }
    }

    if (guard1 == true) {
      c2_b0 = true;
    }

    c2_p = c2_b0;
  }

  return c2_p;
}

static void c2_error(SFc2_ErmittlungderAPsInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 31), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_y));
}

static real_T c2_b_mpower(SFc2_ErmittlungderAPsInstanceStruct *chartInstance,
  real_T c2_a)
{
  real_T c2_b_c;
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_x;
  real_T c2_d_a;
  real_T c2_b_x;
  real_T c2_c_x;
  boolean_T c2_b2;
  boolean_T c2_p;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_x = c2_c_a;
  c2_d_a = c2_x;
  c2_b_x = c2_d_a;
  c2_b_c = c2_b_x;
  c2_c_x = c2_b_c;
  c2_b2 = (c2_c_x < 0.0);
  c2_p = c2_b2;
  if (c2_p) {
    c2_b_error(chartInstance);
  }

  c2_b_c = muDoubleScalarSqrt(c2_b_c);
  if (c2_fltpower_domain_error(chartInstance, c2_c_a, 0.5)) {
    c2_error(chartInstance);
  }

  return c2_b_c;
}

static void c2_b_error(SFc2_ErmittlungderAPsInstanceStruct *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c2_b_y = NULL;
  static char_T c2_b_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_y, 14, c2_b_y));
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ErmittlungderAPsInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErmittlungderAPsInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i3;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i3, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i3;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_ErmittlungderAPsInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErmittlungderAPsInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_ErmittlungderAPs, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_ErmittlungderAPs), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_ErmittlungderAPs);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_ErmittlungderAPsInstanceStruct
  *chartInstance)
{
  chartInstance->c2_wr = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c2_Mr = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_R = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c2_c = (real_T (*)[12])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_v_c = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_theta_c = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_rho = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_n_g_inv = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
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

void sf_c2_ErmittlungderAPs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3752554180U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1403874121U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4075502029U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1715208447U);
}

mxArray* sf_c2_ErmittlungderAPs_get_post_codegen_info(void);
mxArray *sf_c2_ErmittlungderAPs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("I06s2VVnIKRZ0fVY85PXHB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
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
    mxArray* mxPostCodegenInfo = sf_c2_ErmittlungderAPs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_ErmittlungderAPs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_ErmittlungderAPs_jit_fallback_info(void)
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

mxArray *sf_c2_ErmittlungderAPs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_ErmittlungderAPs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_ErmittlungderAPs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Mr\",},{M[8],M[0],T\"is_active_c2_ErmittlungderAPs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ErmittlungderAPs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ErmittlungderAPsInstanceStruct *chartInstance =
      (SFc2_ErmittlungderAPsInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ErmittlungderAPsMachineNumber_,
           2,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_ErmittlungderAPsMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ErmittlungderAPsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ErmittlungderAPsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"wr");
          _SFD_SET_DATA_PROPS(1,1,1,0,"R");
          _SFD_SET_DATA_PROPS(2,1,1,0,"c");
          _SFD_SET_DATA_PROPS(3,1,1,0,"v_c");
          _SFD_SET_DATA_PROPS(4,1,1,0,"theta_c");
          _SFD_SET_DATA_PROPS(5,1,1,0,"rho");
          _SFD_SET_DATA_PROPS(6,1,1,0,"n_g_inv");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Mr");
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
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,535);
        _SFD_CV_INIT_EML_IF(0,1,0,50,59,-1,74);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,53,59,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ErmittlungderAPsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ErmittlungderAPsInstanceStruct *chartInstance =
      (SFc2_ErmittlungderAPsInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_wr);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c2_Mr);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_R);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c2_c);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_v_c);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c2_theta_c);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c2_rho);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c2_n_g_inv);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sUt7B5rh2dyJUtocZNEFFVF";
}

static void sf_opaque_initialize_c2_ErmittlungderAPs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_ErmittlungderAPsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct*)
    chartInstanceVar);
  initialize_c2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_ErmittlungderAPs(void *chartInstanceVar)
{
  enable_c2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_ErmittlungderAPs(void *chartInstanceVar)
{
  disable_c2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_ErmittlungderAPs(void *chartInstanceVar)
{
  sf_gateway_c2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_ErmittlungderAPs(SimStruct* S)
{
  return get_sim_state_c2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_ErmittlungderAPs(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_ErmittlungderAPs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_ErmittlungderAPsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ErmittlungderAPs_optimization_info();
    }

    finalize_c2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct*)
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
  initSimStructsc2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ErmittlungderAPs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ErmittlungderAPs((SFc2_ErmittlungderAPsInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_ErmittlungderAPs(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ErmittlungderAPs_optimization_info
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,7);
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
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2530720626U));
  ssSetChecksum1(S,(4064598349U));
  ssSetChecksum2(S,(1708725239U));
  ssSetChecksum3(S,(358566571U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_ErmittlungderAPs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_ErmittlungderAPs(SimStruct *S)
{
  SFc2_ErmittlungderAPsInstanceStruct *chartInstance;
  chartInstance = (SFc2_ErmittlungderAPsInstanceStruct *)utMalloc(sizeof
    (SFc2_ErmittlungderAPsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_ErmittlungderAPsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_ErmittlungderAPs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_ErmittlungderAPs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_ErmittlungderAPs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_ErmittlungderAPs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_ErmittlungderAPs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_ErmittlungderAPs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_ErmittlungderAPs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_ErmittlungderAPs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_ErmittlungderAPs;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_ErmittlungderAPs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_ErmittlungderAPs;
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
  mdl_start_c2_ErmittlungderAPs(chartInstance);
}

void c2_ErmittlungderAPs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_ErmittlungderAPs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ErmittlungderAPs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ErmittlungderAPs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ErmittlungderAPs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
