function [Aa,Bua,Bva,Ca] = GetArgumentedSystem(A,Bu,Bv,C)
[p,n]=size(C);
I=eye(p);
O=zeros(p,n);

Aa =[A,O';C*A,I];
Bua =[Bu;C*Bu];
Bva =[Bv;C*Bv];
Ca=[O,I];
end