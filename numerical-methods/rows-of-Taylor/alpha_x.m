function [t] = alpha_x (x1,k,e)
    
    x = x1 - 1;
    i = 0;
    s = 1;
    a = 1;
    while (1)
        i = i + 1;
        R = (x.*(k - i + 1))/i;
        a = a.* R;
        s = s + a;
        if (abs(a)./abs(s)) <= e
            break;
        end
    end
    t = s;
end