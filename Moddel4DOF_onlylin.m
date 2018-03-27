%$-Degree-of-Freedom

clc;
clear all;

m_T = 436865; %kg
m_B = 4435;%kg
N = 3; %Anzahl der Blätter
J_r = 38759227; %kgm^2 rotor inertia
J_g = 5025347; %kgm^2 generator inertia

d_T = 7000; %Ns/m
d_B = 2000; %Ns/m
d_s = 6215000; %Nm s
n_g = 97; %gearbox ration

k_T = 1981900; %N/m
k_B = 40000; %N/m
k_s = 867637000; %Nm

rho = 1.225; %kg/m^3
R= 63; %rotor radius


M=[m_T+N+m_B,N*m_B,0,0;N*m_B,N*m_B,0,0;0,0,J_r,0;0,0,0,J_g];
Dmpf=[d_T,0,0,0;0,N*d_B,0,0;0,0,d_s,-(d_s/n_g);0,0,-(d_s/n_g),(d_s/n_g)];
K =[k_T,0,0;0,N*k_B,0;0,0,k_s;0,0,-k_s];
Y=[1,0,0,0;0,1,0,0;0,0,1,-1];
AZ= zeros(3);
A=[AZ,Y;-inv(M)*K,-inv(M)*Dmpf]
BZ=zeros(7,1);
B=[BZ,BZ;0,-(n_g/J_g)];