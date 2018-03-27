function delta_u = Optimierung(F,H,r,GAMMA,LAMBDA,x_k)

delta_u =(inv(H'*GAMMA*H+LAMBDA))*H'*GAMMA*(r-(F*x_k));