function [t] = new_sin(x,e)

a = (-1)*(x.^3)./6;
s = x + a;
i = 3;

while  (1)
    R = (-1).*(x.^2)./((2.*i - 2)*(2.*i - 1)); 
    a = a .* R;
    s = s + a;
    i = i + 1;
    if (abs(a)./abs(s)) <= e
        break;
    end
end
t = s;

endfunction