x = -10:0.1:10 ;
y1 = exp(x);
y2 = new_e(x, 0.01);

subplot(2,1,1);
plot(x , y1, 'g');
legend('e');
grid on;

subplot(2,1,2);
plot(x, y2, 'r');
legend('new e');
grid on;
