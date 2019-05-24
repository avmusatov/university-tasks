function [ x ] = hord2( a,b,e )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
if f1(a)*f1pr2(b) < 0
    xn= b;
    x0= a;
else
    xn=a;
    x0=b;
end
i = 0;
x1=x0-((xn-x0)/(f1(xn)-f1(x0)))*f1(x0);
x0=x1;
while (abs(f1(x1))>e)
    x1=x0-((xn-x0)/(f1(xn)-f1(x0)))*f1(x0);
x0=x1;
i = i + 1;
end
fprintf('x = %2.4f it = %d\n',x1,i);
end
