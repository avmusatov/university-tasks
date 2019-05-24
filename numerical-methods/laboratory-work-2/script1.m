X = [-1;0;1;2];
Y = [13.45; 3.01;0.67;0.15];

n = size(X)(1);
eps = 0;
p = polyfit(X,Y,2);
xx = linspace(X(1),X(end),100);
yy = polyval(p,xx);

plot(X,Y,'o', xx,yy,'r')
grid on;
legend('Data', 'f(x)');

for i=1:1:n
   eps=eps + (phi1(p,X(i,1))-Y(i,1))^2;
end

eps= sqrt(eps/n);
rel_eps = eps/Y(4,1) * 100;
%fprintf("Function of interpolation : y = %.3f*x + %.3f \n ", p(1), p(2));
fprintf("Error = %.3f, Relative error = %.3f percent\n",eps,rel_eps);