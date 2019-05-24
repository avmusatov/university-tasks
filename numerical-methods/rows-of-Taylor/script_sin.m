x = linspace(-pi,pi,1000);

y1 = sin(x);
y2 = new_sin(x, 0.0000001);

subplot(2,1,1);
plot(x , y1, 'g');
legend('sin');
grid on;

subplot(2,1,2);
plot(x, y2, 'r');
legend('my sin');
grid on