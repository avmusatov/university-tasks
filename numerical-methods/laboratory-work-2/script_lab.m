X = [1.6;1.8;2.1;2.3;2.9];
Y = [3.36;3.35;3.19;2.79;2.67];

[n,m] = size(X);
eps = 0;
p = polyfit(X,Y,1);
xx = linspace(X(1),X(end),100);
yy = polyval(p,xx);

plot(X,Y,'o', xx,yy,'r')
grid on;
legend('Data', 'f(x)');

for i=1:1:n
   eps= eps + (phi(p, X(i,1))-Y(i,1))^2;
end
eps= sqrt(eps./n);
rel_eps = eps./Y(5,1).*100;
fprintf('Function of interpolation : y = %.3f*x + %.3f \n ', p(1), p(2));
fprintf('Error = %.3f, Relative error = %.3f percent\n',eps,rel_eps);
