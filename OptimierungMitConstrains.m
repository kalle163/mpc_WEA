function u=OptimierungMitConstrains(F,H,G,Bu,Rw,Qw,ref,dx,u,dv,Con)
s1=size(Bu,2);
s2=size(G,2);
Nu=size(H,2)/s1;
v_vec=ones(s2,1)*dv;
E=2*(H'*Rw*H+Qw);
f=2*H'*Rw*(ref-F*dx-G*v_vec);
C1=zeors(s1*Nu,s1);
C2=zeors(s1*Nu,s1*Nu);
for k=0:s1:(Nu-1)*s1
C1(k+1:k+s1+1,:)=eye(s1);
end
for k=0:s1:(Nu-1)*s1
for l=0:s1:(Nu-1)*s1
if k-l>=0
C2(k+1:k+s1+1,l+1:l+s1+1)=eye(s1);
else
C2(k+1:k+s1+1,l+1:l+s1+1)=zeros(s1);    
end
end
end
M=[-C2;C2;eye(s1)*(-1);eye(s1);-H;H];
gamma=[-Con.Umin+C1*u;Con.Umax-C1*u;
       -Con.DeltaUmin;Con.DeltaUmax;
       -Con.Ymin+F*dx+G*v-vec;Con.Ymax-F*x-G*v_vec];
u_work=quadprog(E,f,M,gamma);
u=u_work(1:1+s1);
end