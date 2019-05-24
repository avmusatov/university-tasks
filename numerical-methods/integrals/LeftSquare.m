function [It] = LeftSquare(x_low,x_high,e)
    n = 2;
    h = (x_high-x_low)/2;
    It_prev = 0;
    while 1
        S = 0;
        for k = 1:n
            x = x_low + (k-1)*h;
            S = S + f(x);
        end
        It = S*h;
        if abs(It_prev - It) < e
            break
        else
            n = n*2;
            h = h/2;
            It = It_prev;
        end
    end
end

