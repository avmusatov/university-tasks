x = linspace(0,1,100);

y1 = x.^0.5;
y2 = alpha_x(x,0.5,0.001);

plot(x , y1, 'g', x, y2, 'r');
grid on;