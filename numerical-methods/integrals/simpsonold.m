function [Int] = simpsonold (a,b,e)
    
     if (a == 0)
        a = 0.000001;
    end
    if (b == 0)
        b = 0.000001;
    end
    
    n=2;
    m=1;
    h=(b - a)/n;
    Old_Int= 0;

    while(1)
        S=0;
        for k=1:1:m
            x = a + (2*k-1)*h;
            if (x == 0)
                x = 0.000001;
            end
            S = S + 2*f(x) + f(x+h);
        end;
        Int=(f(a) - f(b) + 2*S)* h/3;
        if(abs(Int - Old_Int) < e)
            break;
        else
            m=n;
            n=n*2;
            h=h/2;
            Old_Int = Int;
        end
    end
    
    fprintf('Number of steps: n=%d\n', n);
    fprintf('Integral: S=%f.12\n', Int);
    
    x= a:h:b;
    y= f(x);
    hold on;
    plot(x,y,'r');

    for k = 1:2:n
        X = [x(k),x(k+1),x(k+2)];
        Y = [y(k),y(k+1),y(k+2)];
        p = polyfit(X,Y,2);
        xx = linspace(X(1),X(end),100);
        yy = polyval(p,xx);
        area(xx,yy);
        plot(xx,yy,'b');
  end
endfunction
