%
%�������� ������ �������������� �������������. ������ ������� ������� 4.
%
X = [1.6;1.8;2.1;2.3;2.9];
Y = [3.36;3.35;3.19;2.79;2.67];

p = Method1(X,Y);

xx=linspace(X(1),X(end),100);
yy = polyval(p,xx);

plot(X,Y,'o',xx,yy,'r')
grid on;
legend('Data', 'f(x)');