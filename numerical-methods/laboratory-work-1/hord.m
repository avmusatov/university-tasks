function [ x ] = hord( a,b,e )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
x=a-(f1(a)./(f1(b)-f1(a))).*(b-a);
i=0;
while (abs(f1(x))>e)
    if f1(a)*f1(x)<0
       b=x;
    else
        a=x;
    end
    x=a-(f1(a)./(f1(b)-f1(a))).*(b-a);
    i=i+1;
end
fprintf('x = %f it = %d \n',x,i);
end

