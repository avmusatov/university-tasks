x = linspace(-2*pi,2*pi,1000);

y1 = cos(x);
y2 = mycos(x, 0.001);

subplot(2,1,1);
plot(x , y1, 'g');
legend('cos');
grid on;

subplot(2,1,2);
plot(x, y2, 'r');
legend('my cos');
grid on;