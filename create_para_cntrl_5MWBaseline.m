% Parameters for the BaselineController for 5MW NREL Windturbine
% Creation of the Script: 10.07.2017
% By: Florian Pöschke; poeschke@htw-berlin.de

% most of the parameters are based on: 
% [1] Definition of a 5-MW Reference Wind Turbine for Offshore System Development; J. Jonkman; 
% Technical Report NREL/TP-500-38060, February 2009

% initialize an empty struct object
para_cntrl = struct();

%% options
para_cntrl.var_Trq_Reg3 = 0; % 1: Variable Torque in Region 3 depending on wg, 0:  Tg=Tgmax in Region 3

%% Reference Values

para_cntrl.ref.wg_d = 12.1*97/30*pi; % wr_d[rpm]*ngear/30*pi in [rad/s]
para_cntrl.ref.Tgmax = 4.30935e+04;
para_cntrl.ref.wg_SP_15 = 670/30*pi;                    % wg cut in rad/s
para_cntrl.ref.wg_SP_2 = 871/30*pi;                        % Drehzahl in rad/s für Übergang von lin. Rampe in Optimal Torque Control
para_cntrl.ref.wg_SP_3 = .99*para_cntrl.ref.wg_d;

para_cntrl.ref.betak = 8*pi/180; %6.302336*pi/180; [rad]; used for the Gain Scheduling Pitch Controller, see [1]

%% Limits on the control values
para_cntrl.limits.beta_rate = 8; % 8 °/s limit [1]
para_cntrl.limits.Tg_rate = 15e3; % 15.000 Nm/s [1] 

%% Some parameters to calculate the Pitch Controller, see [1]
para_cntrl.para.P0 = 5.296610E6;
para_cntrl.para.ng = 97;
para_cntrl.para.Om0 = para_cntrl.ref.wg_d/para_cntrl.para.ng; % in rad (rotational speed of the wind turbine rotor, not the generator!)
para_cntrl.para.dP_db0 = -25.52E+6; % in W/rad
para_cntrl.para.Jr = 38759227;
para_cntrl.para.Jg = 534;
para_cntrl.para.xi = .7;
para_cntrl.para.wn = .6;

%% Initial conditions: 
para_cntrl.initial.int_PCntrl = 0;%2.5e3; % initial value for the integrator used for the PI Pitch Controller

%% filter parameters
para_cntrl.filter.fc = .25; % corner frequency for the measurement of the generator angular speed wg [1]

%% cntrl parameters

para_cntrl.Kopt = 0.0255764; % [1]; Region (2) Optimal Torque, Open Loop Kopt*wr^2; [Nm/rpm^2] (the rotational speeds are converted to rpm in the controller when in this region)
para_cntrl.Tg_slope15 = para_cntrl.Kopt*(para_cntrl.ref.wg_SP_2*30/pi)^2/(para_cntrl.ref.wg_SP_2-para_cntrl.ref.wg_SP_15); % [1]; calculated from the corresponding rotational speeds and the Torque from Kopt*wg^2, where wg is the entering value into region 2 (optimal torque)[Nm/rad*s]
% note that for the calculation of slope15 partly the rotational speed in
% rpm has to be used, since Kopt is [Nm/rpm^2]

para_cntrl.Tg_slope25 = para_cntrl.ref.Tgmax/(para_cntrl.ref.wg_d-.9*para_cntrl.ref.wg_d);
para_cntrl.Tgx = para_cntrl.ref.Tgmax - para_cntrl.ref.Tgmax/0.1;%or Tgmax-Tg_slope25*wr % needed for the calculation of the set point of region 2,5: Tg = Tg_slope25*wg + Tgx; 

% --- Pitch Controller Gains for beta = 0 (used for scheduling), see [1]
para_cntrl.Kp0 = 2*(para_cntrl.para.Jr+para_cntrl.para.ng^2*para_cntrl.para.Jg)*para_cntrl.para.Om0*para_cntrl.para.xi*para_cntrl.para.wn/para_cntrl.para.ng/-para_cntrl.para.dP_db0; % resulting in beta_d in [rad]
para_cntrl.Ki0 = (para_cntrl.para.Jr+para_cntrl.para.ng^2*para_cntrl.para.Jg)*para_cntrl.para.Om0*para_cntrl.para.wn^2/para_cntrl.para.ng/-para_cntrl.para.dP_db0; % resulting in beta_d in [rad]

%% calculate parameter in pu
para_cntrl.pu.Kopt = para_cntrl.Kopt*(para_cntrl.ref.wg_d*30/pi)^2/para_cntrl.ref.Tgmax;
para_cntrl.pu.Tg_slope25 = para_cntrl.Tg_slope25*para_cntrl.ref.wg_d/para_cntrl.ref.Tgmax;
para_cntrl.pu.Tgx = para_cntrl.Tgx/para_cntrl.ref.Tgmax;

para_cntrl.pu.Tg_slope15 = para_cntrl.Tg_slope15/para_cntrl.ref.Tgmax*para_cntrl.ref.wg_d;
para_cntrl.pu.wg_SP_15 =   para_cntrl.ref.wg_SP_15/para_cntrl.ref.wg_d;              % wg cut in rad/s
para_cntrl.pu.wg_SP_2 = para_cntrl.ref.wg_SP_2/para_cntrl.ref.wg_d; 

%% calculate the transition generator speed between 2->2.5
% the calculation is done in pu, since [Kopt]=Nm/rpm^2 and [Tg_slope25]=Nm/rad*s
para_cntrl.pu.wg_SP_25 =  para_cntrl.pu.Tg_slope25/2/para_cntrl.pu.Kopt - sqrt((para_cntrl.pu.Tg_slope25/2/para_cntrl.pu.Kopt)^2 + para_cntrl.pu.Tgx/para_cntrl.pu.Kopt); % one solution of the quadratic equation, where function Tg = Kopt*w^2 and Tg = Tg_slope25*wg + Tgx meet
para_cntrl.ref.wg_SP_25 = para_cntrl.pu.wg_SP_25*para_cntrl.ref.wg_d; % calculate the setpoint in [rad/s]
%% save the parameters in .mat file 
save para_cntrl_5MWBaseline.mat para_cntrl

