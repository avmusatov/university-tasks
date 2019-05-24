function [Int] = 3/8_test (a, b,e)
   
   y = f(x);
   
   maxf = max(y);
   minf = min(y);
   
   h  = abs(maxy - miny);
    
    while (1)
        S = 0;
        for k = 1:n - 1
            x = a + k*h;
            if (mod(k,3) == 0)
                S = S + 2*f(x);
            else
                S = S + 3 *f(x);
            end    
        end
        
        Int = 3*h/8*(f(a) + f(b) + S);
        if (abs(Old_Int - Int) < e)
            break;
        else
            n = n*3;
            Old_Int = Int;
            h = h/3;
        end
    end
        
endfunction
