function [ x ] = dihot( a,b,e )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
x = (a+b)/2;
i = 0;
while abs(f1(x)) > e
    if (f1(a)*f1(x) < 0)
        b = x;
    else
        a = x;
    end
    x = (a+b)/2;
    i = i + 1;
end
fprintf('x= %2.4f it = %d\n',x,i);

end

