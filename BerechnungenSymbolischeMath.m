clc;
clear all;

syms Sm_t SN Sm_b Sd_t Sd_b Sk_t Sk_b SM SD SK Sf_n SD_n SK_n
SM = [Sm_t+SN*Sm_b,SN*Sm_b;SN+Sm_b,SN*Sm_b];
SD =[Sd_t,0;0,SN*Sd_b];
SK= [Sk_t,0;0,SN*Sk_b];
SD_n =-inv(SM)*SD;
SK_n=-inv(SM)*SK;

pretty(inv(SM))
pretty(SD_n)
pretty(SK_n)
