clc;
clear all;
format long;
warning('off','all')

simulatemodells =true;

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

%Definition der Kennfeld-Konstanten 
c=[0.005,1.53,0.5,0.18,121,27.9,198,2.36,5.74,11.35,16.1,201];
a=[0.006,0.095,-4.15,2.75,0.001,7.8,-0.00016,-8.88];

% Definition der Arbeitspunkte
NrofAp=6;
T_s = 0.05; %s
v_c = [8.0,10.0,11.0,14.0,18.0,25.0]; %m/s
w_r_c =1.2671; %Hz
w_g_c=w_r_c*n_g;
lambda_c =(w_r_c*R)./v_c;
theta_c= [0,0,0,4,15,22]*pi/180; %° in rad
T_g_c = [0,0,0,43093.5,43093.5,43093.5]; %Nm     !!!!Ändern

% Symbolische Berechnugn der Matrizen D_n,K_n und F_n für das 4DOF Modell
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

%Berechnung der C und D und Einheitsmatrizen Matrizen für alle Freiheitsgrade
C1 = 1;
D1 = zeros(1,3);
I1=eye(1);

C2=[1,0,0,0];
D2=zeros(1,3);
I2=eye(4);

C3=[1,0,0,0,0,0;
    0,0,0,0,1,0;
    0,0,0,0,0,1];
D3=zeros(3,3);
I3=eye(6);

C4=[1,0,0,0,0,0,0,0;
    0,0,0,0,1,0,0,0;
    0,0,0,0,0,1,0,0;
    0,0,0,0,0,0,1,0;
    0,0,0,0,0,0,0,1];
D4=zeros(5,3);
I4=eye(8);

%Berechnung zusätzlicher Matrzien für die Simualtion und Defintion der
%Weights und Sollwerte

C2full=eye(4);
D2full=zeros(4,3);
Qw2=eye(100);
Rw2=eye(100)*0.1;
r2=zeros(1,100);




for i=1:NrofAp
%Berechnung von lambda_i und f_0-f_8
lambda_i(i) = (1/(lambda_c(i)+(0.08*theta_c(i))))-(0.035/(c(11)+(c(12)*theta_c(i)^3)));
f_0(i) = c(1)*(1+c(2)*(theta_c(i)+c(3))^(1/2));
f_1(i) = c(4)/lambda_c(i);
f_2(i) = ((c(5)*lambda_i(i))-(c(6)*theta_c(i))-(c(7)*theta_c(i)^c(8))-c(9));
f_3(i) = exp(-c(10)*lambda_i(i));
f_4(i) = a(1);
f_5(i) = a(2)*(lambda_c(i)-a(3)*theta_c(i));
f_6(i) = exp(-a(4)*theta_c(i));
f_7(i) = a(5)*lambda_c(i)^2*exp(-a(6)*theta_c(i));
f_8(i) = a(7)*lambda_c(i)^3*exp(-a(8)*theta_c(i));

%Berechnung von lambda_i und f_0-f_3 partiel abgeleitet nach lambda
lambda_i_dlambda(i) = -1/((lambda_c(i)+(0.08*theta_c(i)))^2);
f_0_dlambda(i) =0;
f_1_dlambda(i) = -(c(4)/(lambda_c(i)^2));
f_2_dlambda(i) = c(5)*lambda_i_dlambda(i);
f_3_dlambda(i) = -c(10)*lambda_i_dlambda(i)*exp(-c(10)*lambda_i(i));
f_4_dlambda(i) =0;
f_5_dlambda(i) = a(2);
f_7_dlambda(i) = 2*a(5)*lambda_c(i)*exp(-a(6)*theta_c(i));
f_8_dlambda(i) = 3*a(7)*lambda_c(i)^2*exp(-a(8)*theta_c(i));

%Berechnung von lambda_i und f_0-f_3 partial abgelitet nach theta
lambda_i_dtheta(i) = (-0.08/(lambda_c(i)+(0.08*theta_c(i)))^2)+((3*0.035*c(12)*theta_c(i)^2)/(c(11)+(c(12)*theta_c(i)^3))^2); 
f_0_dtheta(i) = 0.5*c(1)*c(2)*(theta_c(i)+c(3))^(-1/2);
f_1_dtheta(i) = 0;
f_2_dtheta(i) = (c(5)*lambda_i_dtheta(i))-c(6)-(c(7)*c(8)*theta_c(i)^(c(8)-1));
f_3_dtheta(i) = -c(10)*lambda_i_dtheta(i)*exp(-c(10)*lambda_i(i));
f_4_dtheta(i) =0;
f_5_dtheta(i) = -a(2)*a(3);
f_6_dtheta(i)= -a(4)*exp(-a(4)*theta_c(i));
f_7_dtheta(i)= -a(6)*a(5)*lambda_c(i)^2*exp(-a(6)*theta_c(i));
f_8_dtheta(i)= -a(8)*a(7)*lambda_c(i)^3*exp(-a(8)*theta_c(i));

%Berechnung von CM und deren Ableitungen 
CM_tilde(i) =f_0(i)+(f_1(i)*f_2(i)*f_3(i));
CM(i)=CM_tilde(i)*(1+sign(CM_tilde(i)))/2;
CM_dlambda(i) = (f_1_dlambda(i)*f_2(i)*f_3(i))+(f_1(i)*f_2_dlambda(i)*f_3(i))+(f_1(i)*f_2(i)*f_3_dlambda(i));
CM_dtheta(i)  = f_0_dtheta(i)+(f_1(i)*f_2_dtheta(i)*f_3(i))+(f_1(i)*f_2(i)*f_3_dtheta(i));

%Berechnung von CT und deren Ableitungen
CT_tilde(i) = f_4(i)+(f_5(i)*f_6(i))+f_7(i)+f_8(i);
CT(i)=CT_tilde(i)*(1+sign(CT_tilde(i)))/2;
CT_dlambda(i) = f_4_dlambda(i)+(f_6(i)*f_5_dlambda(i))+f_7_dlambda(i)+f_8_dlambda(i);
CT_dtheta(i) = f_4_dtheta(i)+(f_6(i)*f_5_dtheta(i))+(f_5(i)*f_6_dtheta(i))+f_7_dtheta(i)+f_8_dtheta(i);

%Berechnung zusätzlicher Arbeitspunkte
T_A_c(i) =0.5*rho*pi*R^3*v_c(i)^2*CM(i)*n_g_inv;
F_t_c(i)=0.5*rho*pi*R^2*v_c(i)^2*CT(i);

%Berechnung der Matrizen für einen Freiheitsgrad
AC1 = (1/J)*(0.5*rho*pi*R^4*v_c(i)*CM_dlambda(i));
BC1 = [(1/J)*(0.5*rho*R^3*v_c(i)^2*CM_dtheta(i)),(-1/J)*n_g,(1/J)*((-rho*pi*R^4*w_r_c)*CM_dlambda(i)+rho*pi*R^3*v_c(i)*CM(i))];
AD1 =expm(AC1*T_s); 
BD1 = inv(AC1)*(expm(AC1*T_s)-I1)*BC1;

WEA_1 =ss(AD1,BD1,C1,D1,T_s);
WEA_1.InputName = {'theta','T_g','v'}; 
WEA_1.OutputName = {'w_r'}; 
WEA_1.StateName = {'w_r'};

WEA_1All{i} = WEA_1;

apAD1{i}= AD1;
apBD1{i}= BD1;
apAC1{i}= AC1;
apBC1{i}= BC1;

BD1u=BD1(:,1:2);
BD1v=BD1(:,3);
[F1,H1,G1] = GetPredictionMatrizendis(AD1,BD1u,BD1v,C1,100,50);
[AD1a,BD1ua,BD1va,C1a]=GetArgumentedSystem(AD1,BD1u,BD1v,C1);
[F1a,H1a,G1a] = GetPredictionMatrizendis(AD1a,BD1ua,BD1va,C1a,100,50);
apBD1u{i}=BD1u;
apBD1v{i}=BD1v;
apF1{i}=F1;
apG1{i}=G1;
apH1{i}=H1;
apAD1a{i}=AD1a;
apBD1ua{i}=BD1ua;
apBD1va{i}=BD1va;
apC1a{i}=C1a;
apF1a{i}=F1a;
apG1a{i}=G1a;
apH1a{i}=H1a;

%Berechnung der Matrizen für zwei Freiheitsgrade
AC2 =[(-d_s/J_r)+(0.5*rho*pi*R^4*v_c(i)*CM_dlambda(i))/J_r,-k_s/J_r,(d_s*n_g_inv)/J_r,(k_s*n_g_inv)/J_r;
    1,0,0,0;
    (d_s*n_g_inv)/J_g,(k_s*n_g_inv)/J_g,(-d_s*n_g_inv^2)/J_g,(-k_s*n_g_inv^2)/J_g
    0,0,1,0];

BC2 =[(0.5*rho*pi*R^3*v_c(i)^2*CM_dtheta(i))/J_r,0,(-0.5*pi*rho*R^4*w_r_c*CM_dlambda(i))/J_r+(rho*pi*R^3*v_c(i)*CM(i))/J_r;
    0,0,0;
    0,(-1)/J_g,0;
    0,0,0];

AD2 =expm(AC2*T_s);
BD2 = inv(AC2)*(expm(AC2*T_s)-I2)*BC2;

WEA_2 =ss(AD2,BD2,C2,D2,T_s);
WEA_2.InputName = {'theta','T_g','v'}; 
WEA_2.OutputName = {'w_r'}; 
WEA_2.StateName = {'w_r','phi_r','w_g','phi_g'};

WEA_2All{i} = WEA_2;

apAD2{i}= AD2;
apBD2{i}= BD2;
apAC2{i}= AC2;
apBC2{i}= BC2;

%Berechnung der Prediktionsmatrzien
BD2u=BD2(:,1:2);
BD2v=BD2(:,3);
[F2,H2,G2] = GetPredictionMatrizendis(AD2,BD2u,BD2v,C2,100,50);
[AD2a,BD2ua,BD2va,C2a]=GetArgumentedSystem(AD2,BD2u,BD2v,C2);
[F2a,H2a,G2a] = GetPredictionMatrizendis(AD2a,BD2ua,BD2va,C2a,100,50);
apBD2u{i}=BD2u;
apBD2v{i}=BD2v;
apF2{i}=F2;
apG2{i}=G2;
apH2{i}=H2;
apAD2a{i}=AD2a;
apBD2ua{i}=BD2ua;
apBD2va{i}=BD2va;
apC2a{i}=C2a;
apF2a{i}=F2a;
apG2a{i}=G2a;
apH2a{i}=H2a;

%Berechnung der Matrizen für drei Freiheitsgrade
AC3 = [((1/J_r)*((0.5*rho*pi*R^4*v_c(i)*CM_dlambda(i))-d_s)),(-1/J_r)*k_s,(1/J_r)*d_s*n_g_inv,(1/J_r)*k_s*n_g_inv,0,0;
       1,0,0,0,0,0;
       (1/J_g)*d_s*n_g_inv,(1/J_g)*k_s*n_g_inv,((-1/J_g)*d_s*n_g_inv^2),(-1/J_g)*k_s*n_g_inv^2,0,0;
       0,0,1,0,0,0;
       (1/m_t)*0.5*rho*pi*R^3*v_c(i)*CT_dlambda(i),0,0,0,-(1/m_t)*d_t,-(1/m_t)*k_t;
       0,0,0,0,1,0];
   
BC3=[(1/J_r)*0.5*rho*pi*R^3*v_c(i)^2*CM_dtheta(i),0,(1/J_r)*((-0.5*rho*pi*R^4*w_r_c)*CM_dlambda(i)+rho*pi*R^3*v_c(i)*CM(i));
    0,0,0;
    0,(-1/J_g),0;
    0,0,0
    (1/m_t)*0.5*rho*pi*R^2*v_c(i)^2*CT_dtheta(i),0,(1/m_t)*(-0.5*rho*pi*R^3*w_r_c*CT_dlambda(i)+rho*pi*R^2*v_c(i)*CT(i));
    0,0,0];

AD3 =expm(AC3*T_s);
BD3 = inv(AC3)*(expm(AC3*T_s)-I3)*BC3;

WEA_3 =ss(AD3,BD3,C3,D3,T_s);
WEA_3.InputName = {'theta','T_g','v'}; 
WEA_3.OutputName = {'w_r','y_t','v_t'}; 
WEA_3.StateName = {'w_r','phi_r','w_g','phi_g','v_t','y_t'};

WEA_3All{i} = WEA_3;

apAD3{i}= AD3;
apBD3{i}= BD3;
apAC3{i}= AC3;
apBC3{i}= BC3;

BD3u=BD3(:,1:2);
BD3v=BD3(:,3);
[F3,H3,G3] = GetPredictionMatrizendis(AD3,BD3u,BD3v,C3,100,50);
[AD3a,BD3ua,BD3va,C3a]=GetArgumentedSystem(AD3,BD3u,BD3v,C3);
[F3a,H3a,G3a] = GetPredictionMatrizendis(AD3a,BD3ua,BD3va,C3a,100,50);
apBD3u{i}=BD3u;
apBD3v{i}=BD3v;
apF3{i}=F3;
apG3{i}=G3;
apH3{i}=H3;
apAD3a{i}=AD3a;
apBD3ua{i}=BD3ua;
apBD3va{i}=BD3va;
apC3a{i}=C3a;
apF3a{i}=F3a;
apG3a{i}=G3a;
apH3a{i}=H3a;

%Berechung des State Space Modell in Abhängigkeit der berechneten Werte
%aus der Symbolischen Rechnung
AC4 =[(-d_s/J_r)+(0.5*rho*pi*R^4*v_c(i)*CM_dlambda(i))/J_r,-k_s/J_r,(d_s*n_g_inv)/J_r,(k_s*n_g_inv)/J_r,0,0,0,0;
    1,0,0,0,0,0,0,0;
    (d_s*n_g_inv)/J_g,(k_s*n_g_inv)/J_g,(-d_s*n_g_inv^2)/J_g,(-k_s*n_g_inv^2)/J_g,0,0,0,0;
    0,0,1,0,0,0,0,0;
    0,0,0,0,D_n(1,1),K_n(1,1),D_n(1,2),K_n(1,2);
    0,0,0,0,1,0,0,0;
    (F_n(2,1)+F_n(2,2))*0.5*rho*pi*R^3*v_c(i)*CT_dlambda(i),0,0,0,D_n(2,1),K_n(2,1),D_n(2,2),K_n(2,2);
    0,0,0,0,0,0,1,0];

BC4=[(0.5*rho*pi*R^3*v_c(i)^2*CM_dtheta(i))/J_r,0,(-0.5*pi*rho*R^4*w_r_c*CM_dlambda(i))/J_r+(rho*pi*R^3*v_c(i)*CM(i))/J_r;
    0,0,0;
    0,(-1)/J_g,0;
    0,0,0;
    0,0,0;
    0,0,0;
    (F_n(2,1)+F_n(2,2))*0.5*rho*pi*R^2*v_c(i)^2*CT_dtheta(i),0,(F_n(2,1)+F_n(2,2))*(-0.5*rho*pi*R^3*w_r_c*CT_dlambda(i)+rho*pi*R^2*v_c(i)*CT(i));
    0,0,0];

AD4 =expm(AC4*T_s);
BD4 = inv(AC4)*(expm(AC4*T_s)-I4)*BC4;

WEA_4 =ss(AD4,BD4,C4,D4,T_s);
WEA_4.InputName = {'theta','T_g','v'}; 
WEA_4.OutputName = {'w_r','v_t','y_t','v_b','y_b'}; 
WEA_4.StateName = {'w_r','phi_r','w_g','phi_g','v_t','y_t','v_b','y_b'};

WEA_4All{i} = WEA_4;

apAD4{i}= AD4;
apBD4{i}= BD4;
apAC4{i}= AC4;
apBC4{i}= BC4;

BD4u=BD4(:,1:2);
BD4v=BD4(:,3);
[F4,H4,G4] = GetPredictionMatrizendis(AD4,BD4u,BD4v,C4,100,50);
[AD4a,BD4ua,BD4va,C4a]=GetArgumentedSystem(AD4,BD4u,BD4v,C4);
[F4a,H4a,G4a] = GetPredictionMatrizendis(AD4a,BD4ua,BD4va,C4a,100,50);
apBD4u{i}=BD4u;
apBD4v{i}=BD4v;
apF4{i}=F4;
apG4{i}=G4;
apH4{i}=H4;
apAD4a{i}=AD4a;
apBD4ua{i}=BD4ua;
apBD4va{i}=BD4va;
apC4a{i}=C4a;
apF4a{i}=F4a;
apG4a{i}=G4a;
apH4a{i}=H4a;


end
%Ermittlung der zusätzlichen Arbeitspunkte aus dem kontinuierlichen DGL-Modell.
load 'Kennfelder_Schulte.mat';
sys_Ap= 'ErmittlungderAPs';
open_system(sys_Ap);
for i=1:NrofAp
 sim(sys_Ap);
 Datalogging.yt=logsout.getElement('y_t').Values.data;
 Datalogging.yb=logsout.getElement('y_b').Values.data;
 s1=size(Datalogging.yt);
 y_t_c(i)=Datalogging.yt(s1(1));
 y_b_c(i)=Datalogging.yb(s1(1));
end
if simulatemodells
sys= 'Simulation_der_Modelle_neu';
open_system(sys);
for i=1:NrofAp
sim(sys);
DataloggingMod{i}.timecon=logsout.getElement('1DOFcon').Values.time;
DataloggingMod{i}.timedis=logsout.getElement('1DOFdis').Values.time;
DataloggingMod{i}.dof1con=logsout.getElement('1DOFcon').Values.data;
DataloggingMod{i}.dof1dis=logsout.getElement('1DOFdis').Values.data; 
DataloggingMod{i}.dof1dif=logsout.getElement('1DOFdif').Values.data;
DataloggingMod{i}.dof2con=logsout.getElement('2DOFcon').Values.data;
DataloggingMod{i}.dof2dis=logsout.getElement('2DOFdis').Values.data; 
DataloggingMod{i}.dof2dif=logsout.getElement('2DOFdif').Values.data; 
DataloggingMod{i}.dof3con=logsout.getElement('3DOFcon').Values.data;
DataloggingMod{i}.dof3dis=logsout.getElement('3DOFdis').Values.data; 
DataloggingMod{i}.dof3dif=logsout.getElement('3DOFdif').Values.data;
DataloggingMod{i}.dof4con=logsout.getElement('4DOFcon').Values.data;
DataloggingMod{i}.dof4dis=logsout.getElement('4DOFdis').Values.data; 
DataloggingMod{i}.dof4dif=logsout.getElement('4DOFdif').Values.data; 
end

ylabelnames={' w_r',' vt',' yt',' vb',' yb'};
for i=1:NrofAp
figure('name',strcat('Test des Modells für AP ',num2str(i)));
 subplot(5,2,1) 
   plot(DataloggingMod{i}.timecon, DataloggingMod{i}.dof1con,'r-')
   hold on 
   plot(DataloggingMod{i}.timedis, DataloggingMod{i}.dof1dis,'b--')
   grid on
   title('1.DOF kontinuierlich vs diskret w_r')
   ylabel('w_r')
   xlabel('t in s')
   legend('w_r con','w_r dis')
   
  subplot(5,2,2) 
   plot(DataloggingMod{i}.timecon, DataloggingMod{i}.dof2con,'r-')
   hold on 
   plot(DataloggingMod{i}.timedis, DataloggingMod{i}.dof2dis,'b--')
   grid on
   title('2.DOF kontinuierlich vs diskret w_r')
   ylabel('w_r')
   xlabel('t in s')
   legend('w_r con','w_r dis')
   
   for k=1:3
   subplot(5,2,2+k) 
   plot(DataloggingMod{i}.timecon, DataloggingMod{i}.dof3con(:,k),'r-')
   hold on 
   plot(DataloggingMod{i}.timedis, DataloggingMod{i}.dof3dis(:,k),'b--')
   grid on
   title(strcat('3.DOF kontinuierlich vs diskret ',ylabelnames{k}))
   ylabel(ylabelnames{k})
   xlabel('t in s')
   legend(strcat(ylabelnames{k},' con'),strcat(ylabelnames{k},' dis'))
   end
   
   for k=1:5
   subplot(5,2,5+k) 
   plot(DataloggingMod{i}.timecon, DataloggingMod{i}.dof4con(:,k),'r-')
   hold on 
   plot(DataloggingMod{i}.timedis, DataloggingMod{i}.dof4dis(:,k),'b--')
   grid on
   title(strcat('4.DOF kontinuierlich vs diskret ',ylabelnames{k}))
   ylabel(ylabelnames{k})
   xlabel('t in s')
   legend(strcat(ylabelnames{k},' con'),strcat(ylabelnames{k},' dis'))
   end
   
  
    
end


end
%Definition der Constrains für ale Freiheitsgrade

DeltaUmin=[-8*pi/180*T_s,-Inf];
DeltaUmax=[8*pi/180*T_s,Inf];
Umin=[0,0];
Umax=[90*pi/180,43091.5];
Ymin=0;
Ymax=Inf;


% 
% Einladen der mpc-Reglert-Strukturen (MPC-Designer Entwurf)
% load 'mpc_F1.mat';
% load 'mpc_F2.mat';
% load 'mpc_F2_u.mat';
% load 'mpc_F2_us.mat';
% load 'mpc_F4.mat';
% 
% Eigener MPC Regler Test!!!
% 

% Erstellung des Referenzvektors für das 4 DOF Modell (MPC-Designer-Regleung)
% ref_4=[w_r_c;0;y_t_c;0;y_b_c];
% 
% Implementeierung des Baseline Reglers
% load 'para_cntrl_5MWBaseline.mat'
% C4_base=[1,0,0,0,0,0,0,0;
%          0,0,1,0,0,0,0,0;
%          0,0,0,0,1,0,0,0;
%          0,0,0,0,0,1,0,0;
%          0,0,0,0,0,0,1,0;
%          0,0,0,0,0,0,0,1];
% D4_base=zeros(6,3);
% para_mdl =struct();
% para_mdl.dT =T_s;
% 
% Öffenen und Simulieren der Modelle
% sys= 'Simulation_der_Modelle';
% sys_1_r ='Simulation_der_Regler';
% open_system(sys);
% open_system(sys_1_r);
% sim(sys);
% sim(sys_1_r);
% 
% Darstellung der Ergebnisse
% DataloggingMPC.zeit      = logsout.getElement('4DOFMPCw_r').Values.time; 
% 
% 
% DataloggingMPC.w_r    = logsout.getElement('4DOFMPCw_r').Values.data;                                         
% DataloggingMPC.v_t    = logsout.getElement('4DOFMPCv_t').Values.data;
% DataloggingMPC.y_t    = logsout.getElement('4DOFMPCy_t').Values.data;
% DataloggingMPC.v_b    = logsout.getElement('4DOFMPCv_b').Values.data;
% DataloggingMPC.y_b    = logsout.getElement('4DOFMPCy_b').Values.data;
% DataloggingBASE.w_r   = logsout.getElement('4DOFBASEw_r').Values.data;
% DataloggingBASE.v_t   = logsout.getElement('4DOFBASEv_t').Values.data;
% DataloggingBASE.y_t   = logsout.getElement('4DOFBASEy_t').Values.data;
% DataloggingBASE.v_b   = logsout.getElement('4DOFBASEv_b').Values.data;
% DataloggingBASE.y_b   = logsout.getElement('4DOFBASEy_b').Values.data;
% 
% figure(1)
% subplot(5,1,1)
% 
%    plot(DataloggingMPC.zeit, DataloggingMPC.w_r,'r-')
%    hold on 
%    plot(DataloggingMPC.zeit, DataloggingBASE.w_r,'b-')
%    grid on
%    title('Rotorgeschwindigkeit')
%    ylabel('w_r')
%    xlabel('t in s')
%    legend('w_r MPC','w_r BASE')
%   
% subplot(5,1,2)
% 
%    plot(DataloggingMPC.zeit, DataloggingMPC.v_t,'r-')
%    hold on 
%    plot(DataloggingMPC.zeit, DataloggingBASE.v_t,'b-')
%    grid on
%    title('Geschwindigkeit der Turmauslenkung')
%    ylabel('v_b in m/s')
%    xlabel('t in s')
%    legend('v_b MPC','v_b BASE')
%    
% subplot(5,1,3)
% 
%    plot(DataloggingMPC.zeit, DataloggingMPC.y_t,'r-')
%    hold on 
%    plot(DataloggingMPC.zeit, DataloggingBASE.y_t,'b-')
%    grid on
%    title('Turmauslenkung')
%    ylabel('y_t in m/s')
%    xlabel('t in s')
%    legend('y_t MPC','y_t BASE')
% 
% subplot(5,1,4)
% 
%    plot(DataloggingMPC.zeit, DataloggingMPC.v_b,'r-')
%    hold on 
%    plot(DataloggingMPC.zeit, DataloggingBASE.v_b,'b-')
%    grid on
%    title('Geschwindigkeit der Blattauslenkung')
%    ylabel('v_b in m/s')
%    xlabel('t in s')
%    legend('v_b MPC','v_b BASE')
%    
%  subplot(5,1,5)
% 
%    plot(DataloggingMPC.zeit, DataloggingMPC.y_b,'r-')
%    hold on 
%    plot(DataloggingMPC.zeit, DataloggingBASE.y_b,'b-')
%    grid on
%    title('Blattauslenkung')
%    ylabel('y_b in m/s')
%    xlabel('t in s')
%    legend('y_b MPC','y_b BASE')
% 
% % 
% Einladen der mpc-Reglert-Strukturen (MPC-Designer Entwurf)
% load 'mpc_F1.mat';
% load 'mpc_F2.mat';
% load 'mpc_F2_u.mat';
% load 'mpc_F2_us.mat';
% load 'mpc_F4.mat';








   

