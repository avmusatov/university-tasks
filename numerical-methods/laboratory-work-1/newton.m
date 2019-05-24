function [ x ] = newton( a,b,e )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
if f2(a)*f2pr2(a) > 0
    x = a;
else
    x = b;
end
i = 0;
while abs(f2(x)) > e
    x = x - f2(x)/f2pr1(x);
    i = i + 1;
    
end
    fprintf('x = %2.4f it = %d \n',x,i);
    end

