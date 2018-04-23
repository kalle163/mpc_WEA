%Hildreth Programming Algorithem siehe Liuping Wang: Model Predictive
%Control System Design and Implementation Using MATLAB Seite 67
function u=HPA(E,f,M,gamma)
[n1,m1]=size(M);
u=-E\f;
kk=0;
for i=1:n1
    if(M(i,:)*u>gamma(i))
        kk=kk+1;
    else
        kk=kk+0;
    end
end
if(kk==0)
    return;
end
P=M*(E\M');
d=(M*(E\f)+gamma);
[n,m]=size(d);
x_ini=zeros(n,m);
lambda=x_ini;
al=10;
for km= 1:38
    lambda_p=lambda;
    for i=1:n
        w=P(i,:)*lambda-P(i,i)*lambda(i,1);
        w=w+d(i,1);
        la=-w/P(i,i);
        lambda(i,1)=max(0,la);
    end
    al=(lambda-lambda_p)'*(lambda-lambda_p);
    if(al<10e-8)
        break;
    end
end
u=-E\f-E\M'*lambda;
end