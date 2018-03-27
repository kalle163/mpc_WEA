function u = GetOptimaleStellgroese(F,H,Qw,Rw,r,x,BDu,v)
v_vec=ones(1,100)*v;
s1=size(BDu,2);
u_work= inv((H'*Rw*H)+Qw)*H'*Rw*(r-F*x+G*v_vec);
u=u_work(1:s1);

end