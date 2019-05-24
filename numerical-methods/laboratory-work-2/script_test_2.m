%
%Проверка метода наименьших квадратов. Третьим параметром функция принимает степерь полинома.
%В данном случае есть смысл строить полиномы степени <= 4.
%
X = [1.6;1.8;2.1;2.3;2.9];
Y = [3.36;3.35;3.19;2.79;2.67];

p1 = Method2(X,Y,1);
p2 = Method2(X,Y,2);
p3 = Method2(X,Y,3);
p4 = Method2(X,Y,4);

xx=linspace(X(1),X(end),100);

yy1=polyval(p1,xx);
yy2=polyval(p2,xx);
yy3=polyval(p3,xx);
yy4 = polyval(p4,xx);


plot(X,Y,'o',xx,yy1,'r',xx,yy2,'g',xx,yy3,'b', xx,yy4)

grid on;
legend('Data', '1st degree', '2nd degree', '3rd degree', '4th degree');