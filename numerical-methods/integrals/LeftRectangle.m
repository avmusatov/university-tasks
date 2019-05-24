function [ Int ] = LeftRectangle( a,b,e)
    n = 2;
    h = (b - a)/n;
    Old_Int = 0;
    while (1)
        S = 0;
        for k = 1:n
           x = a + (k-1)*h;
           if x == 0
               x = 0.0000001;
           end
           S = S + f(x);
        end
        Int = S*h;
        if (abs(Int - Old_Int) < e)
            break;
        else
            n = n*2;
            h = h/2;
            Old_Int = Int;
        end
    end
    X = a:h:b;
    Y = f(X);
    hold on;
    bar(X,Y);
    plot(X,f(X),'r');
    fprintf('Number of steps: %d\n',n);
endfunction

