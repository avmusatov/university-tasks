a = 1;
b = 2;
e = 0.001;
grid on;

subplot(2,3,1);
fprintf('Rectangle method\n');
CenterRectangle(a,b,e);
fprintf('\n');

subplot(2,3,2);
fprintf('Trapezoid method\n');
trapeze(a,b,e);
fprintf('\n');

subplot(2,3,3);
fprintf('Simpson`s method\n');
simpsonold(a,b,e);
fprintf('\n');

subplot(2,3,4);
fprintf('Method 3/8 \n');
Three_8(a,b,e);
fprintf('\n');

subplot(2,3,5);
fprintf('Method Monte Carlo \n');
Monte_Carlo(a,b,500);
fprintf('\n');

