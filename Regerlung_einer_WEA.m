clc;
clear all;
format long;
%Defintion der kompletten Anlagenparameter
m_t = 436865;%kg
m_b = 4435;%kg
N = 3; %Anzahl der Blätter
J_r = 38759227; %kgm^2 rotor inertia
J_g = 534; %kgm^2 generator inertia

d_t = 7000; %Ns/m
d_b = 2000; %Ns/m
d_s = 6215000; %Nm s
n_g = 97; %gearbox ratio
n_g_inv = 1/n_g; %inverse gearbox ratio

k_t = 1981900; %N/m
k_b = 40000; %N/m
k_s = 867637000; %Nm

rho = 1.225; %kg/m^3
R= 63; %rotor radius
J= J_r + (n_g^2*J_g);

c=[0.005,1.53,0.5,0.18,121,27.9,198,2.36,5.74,11.35,16.1,201];
a=[0.006,0.095,-4.15,2.75,0.001,7.8,-0.00016,-8.88];
% Definition der Arbeitspunkte
T_s = 0.05; %s
v_c = 14.0; %m/s
w_r_c =1.2671; %Hz
lambda_c =(w_r_c*R)/v_c;
theta_c= 4*pi/180; %° in rad
T_g_c = 43093.5; %Nm

%Berechnung von lambda_i und f_0-f_3
lambda_i = (1/(lambda_c+(0.08*theta_c)))-(0.035/(c(11)+(c(12)*theta_c^3)));
f_0 = c(1)*(1+c(2)*(theta_c+c(3))^(1/2));
f_1 = c(4)/lambda_c;
f_2 = ((c(5)*lambda_i)-(c(6)*theta_c)-(c(7)*theta_c^c(8))-c(9));
f_3 = exp(-c(10)*lambda_i);
f_4 = a(1);
f_5 = a(2)*(lambda_c-a(3)*theta_c);
f_6 = exp(-a(4)*theta_c);
f_7 = a(5)*lambda_c^2*exp(-a(6)*theta_c);
f_8 = a(7)*lambda_c^3*exp(-a(8)*theta_c);

%Berechnung von lambda_i und f_0-f_3 partiel abgeleitet nach lambda
lambda_i_dlambda = -1/((lambda_c+(0.08*theta_c))^2);
f_0_dlambda =0;
f_1_dlambda = -(c(4)/(lambda_c^2));
f_2_dlambda = c(5)*lambda_i_dlambda;
f_3_dlambda = -c(10)*lambda_i_dlambda*exp(-c(10)*lambda_i);
f_4_dlambda =0;
f_5_dlambda = a(2);
f_7_dlambda = 2*a(5)*lambda_c*exp(-a(6)*theta_c);
f_8_dlambda = 3*a(7)*lambda_c^2*exp(-a(8)*theta_c);

%Berechnung von lambda_i und f_0-f_3 partial abgelitet nach theta
lambda_i_dtheta = (-0.08/(lambda_c+(0.08*theta_c))^2)+((3*0.035*c(12)*theta_c^2)/(c(11)+(c(12)*theta_c^3))^2); 
f_0_dtheta = 0.5*c(1)*c(2)*(theta_c+c(3))^(-1/2);
f_1_dtheta = 0;
f_2_dtheta = (c(5)*lambda_i_dtheta)-c(6)-(c(7)*c(8)*theta_c^(c(8)-1));
f_3_dtheta = -c(10)*lambda_i_dtheta*exp(-c(10)*lambda_i);
f_4_dtheta =0;
f_5_dtheta = -a(2)*a(3);
f_6_dtheta = -a(4)*exp(-a(4)*theta_c);
f_7_dtheta = -a(6)*a(5)*lambda_c^2*exp(-a(6)*theta_c);
f_8_dtheta = -a(8)*a(7)*lambda_c^3*exp(-a(8)*theta_c);

%Berechnung von CM und deren Ableitungen 
CM_tilde =f_0+(f_1*f_2*f_3);
CM=CM_tilde*(1+sign(CM_tilde))/2;
CM_dlambda = (f_1_dlambda*f_2*f_3)+(f_1*f_2_dlambda*f_3)+(f_1*f_2*f_3_dlambda);
CM_dtheta  = f_0_dtheta+(f_1*f_2_dtheta*f_3)+(f_1*f_2*f_3_dtheta);

%Berechnung von CT und deren Ableitungen
CT_tilde = f_4+(f_5*f_6)+f_7+f_8;
CT=CT_tilde*(1+sign(CT_tilde))/2;
CT_dlambda = f_4_dlambda+(f_6*f_5_dlambda)+f_7_dlambda+f_8_dlambda;
CT_dtheta = f_4_dtheta+(f_6*f_5_dtheta)+(f_5*f_6_dtheta)+f_7_dtheta+f_8_dtheta;

%Berechnung zusätzlicher Arbeitspunkte
T_A_c =0.5*rho*pi*R^3*v_c^2*CM*n_g_inv;
F_t_c=0.5*rho*pi*R^2*v_c^2*CT;

%Berechnung der Matrizen für einen Freiheitsgrad
AC1 = (1/J)*(0.5*rho*pi*R^4*v_c*CM_dlambda);
BC1 = [(1/J)*(0.5*rho*R^3*v_c^2*CM_dtheta),(-1/J)*n_g,(1/J)*((-rho*pi*R^4*w_r_c)*CM_dlambda+rho*pi*R^3*v_c*CM)];
C1 = 1;
D1 = zeros(1,3);

AD1 =expm(AC1*T_s); 
I1=eye(1);
BD1 = inv(AC1)*(expm(AC1*T_s)-I1)*BC1;


WEA_1 =ss(AD1,BD1,C1,D1,T_s);
WEA_1.InputName = {'theta','T_g','v'}; 
WEA_1.OutputName = {'w_r'}; 
WEA_1.StateName = {'w_r'}; 
WEA_1   

%Berechnung der Matrizen für zwei Freiheitsgrade
AC2 =[(-d_s/J_r)+(0.5*rho*pi*R^4*v_c*CM_dlambda)/J_r,-k_s/J_r,(d_s*n_g_inv)/J_r,(k_s*n_g_inv)/J_r;
    1,0,0,0;
    (d_s*n_g_inv)/J_g,(k_s*n_g_inv)/J_g,(-d_s*n_g_inv^2)/J_g,(-k_s*n_g_inv^2)/J_g
    0,0,1,0];

BC2 =[(0.5*rho*pi*R^3*v_c^2*CM_dtheta)/J_r,0,(-0.5*pi*rho*R^4*w_r_c*CM_dlambda)/J_r+(rho*pi*R^3*v_c*CM)/J_r;
    0,0,0;
    0,(-1)/J_g,0;
    0,0,0];

AD2 =expm(AC2*T_s);
I2=eye(4);
BD2 = inv(AC2)*(expm(AC2*T_s)-I2)*BC2;

C2=[1,0,0,0];
D2=zeros(1,3);

WEA_2 =ss(AD2,BD2,C2,D2,T_s);
WEA_2.InputName = {'theta','T_g','v'}; 
WEA_2.OutputName = {'w_r'}; 
WEA_2.StateName = {'w_r','phi_r','w_g','phi_g'};
WEA_2


%Berechnung der Matrizen für drei Freiheitsgrade
AC3 = [((1/J_r)*((0.5*rho*pi*R^4*v_c*CM_dlambda)-d_s)),(-1/J_r)*k_s,(1/J_r)*d_s*n_g_inv,(1/J_r)*k_s*n_g_inv,0,0;
       1,0,0,0,0,0;
       (1/J_g)*d_s*n_g_inv,(1/J_g)*k_s*n_g_inv,((-1/J_g)*d_s*n_g_inv^2),(-1/J_g)*k_s*n_g_inv^2,0,0;
       0,0,1,0,0,0;
       (1/m_t)*0.5*rho*pi*R^3*v_c*CT_dlambda,0,0,0,-(1/m_t)*d_t,-(1/m_t)*k_t;
       0,0,0,0,1,0];
   
BC3=[(1/J_r)*0.5*rho*pi*R^3*v_c^2*CM_dtheta,0,(1/J_r)*((-0.5*rho*pi*R^4*w_r_c)*CM_dlambda+rho*pi*R^3*v_c*CM);
    0,0,0;
    0,(-1/J_g),0;
    0,0,0
    (1/m_t)*0.5*rho*pi*R^2*v_c^2*CT_dtheta,0,(1/m_t)*(-0.5*rho*pi*R^3*w_r_c*CT_dlambda+rho*pi*R^2*v_c*CT);
    0,0,0];

C3=[1,0,0,0,0,0;
    0,0,0,0,1,0;
    0,0,0,0,0,1];
D3=zeros(3,3);

AD3 =expm(AC3*T_s);
I3=eye(6);
BD3 = inv(AC3)*(expm(AC3*T_s)-I3)*BC3;

WEA_3 =ss(AD3,BD3,C3,D3,T_s);
WEA_3.InputName = {'theta','T_g','v'}; 
WEA_3.OutputName = {'w_r','y_t','v_t'}; 
WEA_3.StateName = {'w_r','phi_r','w_g','phi_g','v_t','y_t'};
WEA_3

%Berechnugn des Modells mit vier Freiheitsgraden
% Symbolische Berechnugn der Matrizen D_n,K_n und F_n
syms Sm_t SN Sm_b Sd_t Sd_b Sk_t Sk_b SM SD SK SF_n SD_n SK_n
SM = [Sm_t+SN*Sm_b,SN*Sm_b;SN+Sm_b,SN*Sm_b];
SD =[Sd_t,0;0,SN*Sd_b];
SK= [Sk_t,0;0,SN*Sk_b];
SD_n =-inv(SM)*SD;
SK_n=-inv(SM)*SK;
SF_n=inv(SM);

pretty(SF_n)
pretty(SD_n)
pretty(SK_n)
D_n =double(subs(SD_n,[Sm_t,SN,Sm_b,Sd_t,Sd_b],[m_t,N,m_b,d_t,d_b]));
K_n =double(subs(SK_n,[Sm_t,SN,Sm_b,Sk_t,Sk_b],[m_t,N,m_b,k_t,k_b]));
F_n =double(subs(SF_n,[Sm_t,SN,Sm_b],[m_t,N,m_b]));


%Berechung des State Space Modell in Abhängigkeit der berechneten Werte
%aus der Symbolischen Rechnung
AC4 =[(-d_s/J_r)+(0.5*rho*pi*R^4*v_c*CM_dlambda)/J_r,-k_s/J_r,(d_s*n_g_inv)/J_r,(k_s*n_g_inv)/J_r,0,0,0,0;
    1,0,0,0,0,0,0,0;
    (d_s*n_g_inv)/J_g,(k_s*n_g_inv)/J_g,(-d_s*n_g_inv^2)/J_g,(-k_s*n_g_inv^2)/J_g,0,0,0,0;
    0,0,1,0,0,0,0,0;
    0,0,0,0,D_n(1,1),K_n(1,1),D_n(1,2),K_n(1,2);
    0,0,0,0,1,0,0,0;
    (F_n(2,1)+F_n(2,2))*0.5*rho*pi*R^3*v_c*CT_dlambda,0,0,0,D_n(2,1),K_n(2,1),D_n(2,2),K_n(2,2);
    0,0,0,0,0,0,1,0];

BC4=[(0.5*rho*pi*R^3*v_c^2*CM_dtheta)/J_r,0,(-0.5*pi*rho*R^4*w_r_c*CM_dlambda)/J_r+(rho*pi*R^3*v_c*CM)/J_r;
    0,0,0;
    0,(-1)/J_g,0;
    0,0,0;
    0,0,0;
    0,0,0;
    (F_n(2,1)+F_n(2,2))*0.5*rho*pi*R^2*v_c^2*CT_dtheta,0,(F_n(2,1)+F_n(2,2))*(-0.5*rho*pi*R^3*w_r_c*CT_dlambda+rho*pi*R^2*v_c*CT);
    0,0,0];

AD4 =expm(AC4*T_s);
I4=eye(8);
BD4 = inv(AC4)*(expm(AC4*T_s)-I4)*BC4;

C4=[1,0,0,0,0,0,0,0;
    0,0,0,0,1,0,0,0;
    0,0,0,0,0,1,0,0;
    0,0,0,0,0,0,1,0;
    0,0,0,0,0,0,0,1];

D4=zeros(5,3);

WEA_4 =ss(AD4,BD4,C4,D4,T_s);
WEA_4.InputName = {'theta','T_g','v'}; 
WEA_4.OutputName = {'w_r','v_t','y_t','v_b','y_b'}; 
WEA_4.StateName = {'w_r','phi_r','w_g','phi_g','v_t','y_t','v_b','y_b'};
WEA_4


%Ermittlung der zusätzlichen Arbeitspunkte aus dem kontinuierlichen DGL-Modell.
load 'Kennfelder_Schulte.mat';
sys_Ap= 'ErmittlungderAPs';
open_system(sys_Ap);
sim(sys_Ap);
Datalogging.yt=logsout.getElement('y_t').Values.data;
Datalogging.yb=logsout.getElement('y_b').Values.data;
s1=size(Datalogging.yt);
y_t_c=Datalogging.yt(s1(1));
y_b_c=Datalogging.yb(s1(1));
w_g_c=w_r_c*n_g;

%Einladen der mpc-Reglert-Strukturen (MPC-Designer Entwurf)
load 'mpc_F1.mat';
load 'mpc_F2.mat';
load 'mpc_F2_u.mat';
load 'mpc_F2_us.mat';
load 'mpc_F4.mat';

%Eigener MPC Regler Test!!!
BD2u=BD2(:,1:2);
BD2v=BD2(:,3);
[F2,H2,G2] = GetPredictionMatrizendis(AD2,BD2u,BD2v,C2,100,50);
[AD2a,BD2ua,BD2va,C2a]=GetArgumentedSystem(AD2,BD2u,BD2v,C2);
[F2a,H2a,G2a] = GetPredictionMatrizendis(AD2a,BD2ua,BD2va,C2a,100,50);
C2full=eye(4);
D2full=zeros(4,3);
Qw2=eye(100)*0.1;
Rw2=eye(100);
r2=zeros(1,100);
%Constraind Case
DeltaU2min=[-8*pi/180*T_s,-Inf];
DeltaU2max=[8+pi/180+T_s,Inf];
U2min=[0,0];
U2max=[90*pi/180,43091.5];
Y2min=0;
Y2max=Inf;
%Erstellung des Referenzvektors für das 4 DOF Modell (MPC-Designer-Regleung)
ref_4=[w_r_c;0;y_t_c;0;y_b_c];

%Implementeierung des Baseline Reglers
load 'para_cntrl_5MWBaseline.mat'
C4_base=[1,0,0,0,0,0,0,0;
         0,0,1,0,0,0,0,0;
         0,0,0,0,1,0,0,0;
         0,0,0,0,0,1,0,0;
         0,0,0,0,0,0,1,0;
         0,0,0,0,0,0,0,1];
D4_base=zeros(6,3);
para_mdl =struct();
para_mdl.dT =T_s;

%Öffenen und Simulieren der Modelle
sys= 'Simulation_der_Modelle';
sys_1_r ='Simulation_der_Regler';
open_system(sys);
open_system(sys_1_r);
sim(sys);
sim(sys_1_r);








   

