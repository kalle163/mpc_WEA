function [F,H] = GetPredictionMatrizen(A,B,C,N2,Nu)
%s1=size(A,2);
s2=size(B,2);
s3=size(C,1);
% OA=zeros(s2,s1);
% IBu=eye(s2);
% OC=zeros(s3,s2);
% IBv=zeros(s2,s4);
% M=[A,Bu;OA,IBu];
% N=[Bu;IBu];
% Q=[C,OC];
% P=[Bv;IBv];
for k =0:1*s3:(N2-1)*s3
   F(k+1:k+s3,:)=C*(A^(k+1));
end
for j=0:s3:(N2-1)*s3
for i=0:s2:(Nu-1)*s2
    k=j-i;
    if k >= 0
    H(j+1:j+s3,i+1:i+s2)=C*A^(k)*B;
    else  
    H(j+1:j+s3,i+1:i+s2)=zeros(s3,s2);
    end
   
end
end
end