function [y] = f2pr2(x)
%UNTITLED10 Summary of this function goes here
%   Detailed explanation goes here
y = ((2+ 2/x^3)*(1+(x^2+1/x)^2) - (2*x - 1/x^2)*(2*x^2 + 2/x)*(2*x-1/x^2))/(1+(x^2+1/x)^2)^2;
end

