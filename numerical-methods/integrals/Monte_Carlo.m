function [ Int ] = Monte_Carlo(a,b,n)
    x = linspace(a,b,100);
    y = f(x);
    count_right = 0;
    hold on;
    
    maxy = max(y);
    miny = min(y);
    h = abs(maxy - miny);
    S = (b - a)*h;
    
    X = a + (b-a)*rand(1,n);
    Y = miny + (maxy - miny)*rand(1,n);
    
    for k = 1:n
        if (Y(k) < f(X(k))&& Y(k) > 0 || Y(k) > f(X(k))&& Y(k) < 0)
            plot(X(k),Y(k),'g');
            count_right = count_right + 1;
        else
            plot(X(k),Y(k),'r');
        end
    end
    
    plot(x,f(x));
    plot(x,0);
    s = 0;
    for i= 1:n
        s = s + f(X(i));
    end
    
    Int = s/n*(b-a);
    fprintf('Integral: %.4f\n',Int);

end

