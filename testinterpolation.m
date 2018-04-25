v_c=[9,9.5,10,11,14,15,18,25];
v=8:0.1:27;
for i=1:length(v)
   h(i)=InterpolationderApsvarnr(v(i),v_c)
end
plot(v,h)