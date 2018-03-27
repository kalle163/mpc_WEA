function [F,H,G] = GetPredictionMatrizendis(A,Bu,Bv,C,N2,Nu)
s2=size(Bu,2);
s3=size(C,1);
s4=size(Bv,2);
for k =0:1*s3:(N2-1)*s3
   F(k+1:k+s3,:)=C*(A^(k+1));
end
for j=0:s3:(N2-1)*s3
for i=0:s2:(Nu-1)*s2
    k=j-(i/s2);
    if k >= 0
    H(j+1:j+s3,i+1:i+s2)=C*A^(k)*Bu;
    else  
    H(j+1:j+s3,i+1:i+s2)=zeros(s3,s2);
    end
   
end
end

for j=0:s3:(N2-1)*s3
for i=0:s4:(N2-1)*s4
    k=j-(i/s4);
    if k >= 0
    G(j+1:j+s3,i+1:i+s4)=C*A^(k)*Bv;
    else  
    G(j+1:j+s3,i+1:i+s4)=zeros(s3,s4);
    end
   
end
end

end