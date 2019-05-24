function [ Int ] = Three_8( a, b, e )

    if (a == 0)
        a = 0.000001;
    end
    if (b == 0)
        b = 0.000001;
    end
    
    n=3;
    Old_Int =0;
    h=(b - a)/n;
    while (1)
        sum = 0;
        for k=1:n-1
            x = a+k.*h;
            if (x == 0)
            x = x + 0.00001;
            end
            if (mod(k, 3) == 0)
                sum = sum + 2*f(x);
            else 
                sum = sum + 3*f(x);
            end
        end
        Int=(f(a)+f(b)+sum).*h.*3./8;
    
        if (abs(Int-Old_Int) < e)
            break;
        end
        n = n*3;
        h = h/3;
        Old_Int = Int;
    end
    
    fprintf('Number of steps: n=%d\n', n);
    fprintf('Integral: S=%f.12\n', Int);

    X=a:0.001:b;
    plot(X, f(X), 'r');
    hold on;

    for i=a:h:b-h
        xx=linspace(i, i+h, 100);
        x=[i, i+h/3, i+h*2/3, i+h];
        y=f(x);
        xx_poly=polyfit(x, y, 3);
        yy = polyval(xx_poly, xx);
        hold on;
        area(xx, yy, 'FaceColor', [rand 0 rand]);
    end
end