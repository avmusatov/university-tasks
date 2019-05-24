function [ x ] = simple_it( a,b,e )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
i = 0;
if (abs(phi2_pr1(a)) < 1 && abs(phi2_pr1(b))< 1)
    x = a;
    while abs(f2(x)) > e
        x = phi2(x);
        i = i + 1;
    end
else
    fprintf('¬ведите новую функцию Phi ');
end
fprintf('x = %2.4f it = %d \n',x,i);

end

