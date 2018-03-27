%MPC Einarbeitung
clc;
clear workspace;
clear figures;


A = [-0.0285,-0.0014;-0.0371,-0.1476]; 
B = [-0.0850,0.0238;0.0802,0.4462]; 
C = [0,1;1,0]; 
D = zeros(2,2); 
STR = ss(A,B,C,D); 
STR.InputName = {'T_c', 'C_A_i'}; 
STR.OutputName = {'T', 'C_A'}; 
STR.StateName = {'C_A', 'T'}; 
STR.InputGroup.MV = 1; 
STR.InputGroup.UD = 2; 
STR.OutputGroup.MO = 1; 
STR.OutputGroup.UO = 2;
STR


load('mpc1.mat');


sys= 'STR_ClosedLoop';
open_system(sys);