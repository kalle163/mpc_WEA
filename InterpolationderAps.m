function [F,G,H]=InterpolationderAps(apF,apG,apH,v,v_c)

if v>v_c(2)
h1=0;
elseif v<= v_c(1)
h1=1;
else
h1=(v_c(2)-v)/(v_c(2)-v_c(1));
end

if or(v<v_c(1),v>v_c(3))
h2=0;    
elseif v>=v_c(2)
h2=(v_c(3)-v)/(v_c(3)-v_c(2));
else
h2=(v-v_c(1))/(v_c(2)-v_c(1));
end

if or(v<v_c(2),v>v_c(4))
h3=0;
elseif v>=v_c(3)
h3=(v_c(4)-v)/(v_c(4)-v_c(3));
else
h3=(v-v_c(2))/(v_c(3)-v_c(2));
end

if or(v<v_c(3),v>v_c(5))
h4=0;
elseif v>=v_c(4)
h4=(v_c(5)-v)/(v_c(5)-v_c(4));
else
h4=(v-v_c(3))/(v_c(4)-v_c(3));
end

if or(v<v_c(4),v>v_c(6))
h5=0;
elseif v>=v_c(5)
h5=(v_c(6)-v)/(v_c(6)-v_c(5));
else
h5=(v-v_c(4))/(v_c(5)-v_c(4));
end

if v>= v_c(6)
h6=1;
elseif v<v_c(5)
h6=0;
else
h6=(v-v_c(5))/(v_c(6)-v_c(5))
end

F=h1*apF(1)+h2*apF(2)+h3*apF(3)+h4*apF(4)+h5*apF(5)+h6*apF(6);
G=h1*apG(1)+h2*apG(2)+h3*apG(3)+h4*apG(4)+h5*apG(5)+h6*apG(6);
H=h1*apH(1)+h2*apH(2)+h3*apH(3)+h4*apH(4)+h5*apH(5)+h6*apH(6);
end



