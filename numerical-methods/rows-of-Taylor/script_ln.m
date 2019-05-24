x = 0:0.001:1 ;

y1 = log(1+x);
y2 = ln1x(x, 0.001);

subplot(2,1,1);
plot(x , y1, 'g');
legend('ln');
grid on;

subplot(2,1,2);
plot(x, y2, 'r');
legend('myln');
grid on;