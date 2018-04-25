function [F,G,H]=InterpolationderApsvarnr(apF,apG,apH,v,v_c)
[waste,NrofAP]=size(v_c);
if v>v_c(2)
h(1)=0;
elseif v<= v_c(1)
h(1)=1;
else
h(1)=(v_c(2)-v)/(v_c(2)-v_c(1));
end

for i=2:(NrofAP-1)
if or(v<v_c(i-1),v>v_c(i+1))
h(i)=0;    
elseif v>=v_c(i)
h(i)=(v_c(i+1)-v)/(v_c(i+1)-v_c(i));
else
h(i)=(v-v_c(i-1))/(v_c(i)-v_c(i-1));
end    
end

if v>= v_c(NrofAP)
h(NrofAP)=1;
elseif v<v_c(NrofAP-1)
h(NrofAP)=0;
else
h(NrofAP)=(v-v_c(NrofAP-1))/(v_c(NrofAP)-v_c(NrofAP-1));
end
F=0;
G=0;
H=0;
for i=1:NrofAP
F=F+(h(i)*apF(i));
G=G+(h(i)*apG(i));
H=H+(h(i)*apH(i));
end

end



