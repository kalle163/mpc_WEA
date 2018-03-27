function [F,H] = Prediktor(A,B,C,N_1,N_2,N_u)
    F=zeros((N_2-N_1+1),2);
for k=1:1:(N_2-N_1+1)
    F(k,1:2)=C*(A^(N_1+k));
end
    H=zeros((N_2-N_1+1),(N_u+1));
for k=1:1:(N_2-N_1+1)
for l=1:1:N_u
    m=k+N_1-l;
    if m>=1
    H(k,l)=C*(A^(m-1))*B;    
    else 
    H(k,l)=0;    
    end    
end
end
end
