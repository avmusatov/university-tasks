function[Int] = trapeze(a,b,e)

    if (a == 0)
        a = 0.000001;
    end
    if (b == 0)
        b = 0.000001;
    end
    
    n=2;
    h=(b - a)./n;
    Old_Int=0;
    while (1)
        S = (f(a) + f(b))./2;
        for k=1:n-1
            x= a + h.*k;
            if x == 0
                x = 0.00001;
            end
            S = S + f(x);
        end
        Int=S.*h;
        if ((abs(Int-Old_Int))<e)
            break;
        else
            n = n.*2;
            h = h./2;
            Old_Int = Int;
        end
    end
    fprintf('Number of steps: %d\n',n);
    fprintf('Integral: %.4f\n',Int);
    k=a;
    X=[];
    Y=[];
    hold on;
    for i=1:n
        k=k+h;
        X=[X,k];
        Y=[Y,f(k)];
        if (i>2)
            plot ([X(i-1),X(i)],[Y(i-1),Y(i)]);
            area([X(i-1),X(i)],[Y(i-1),Y(i)])
            plot([X(i-1),X(i-1)],[0,Y(i-1)]);
        end
    end    
     plot([X(n),X(n)],[0,Y(n)]);
     plot(X,f(X));
endfunction
