function [ t ] = ln1x( x,eps )

    i=1;
    a=x;%член разложения
    S=x;

    while(1)
        i=i+1;
        a=a.*(-x);
        S= S + a./i;
        if (abs(a)./abs(S) <= eps)
            break;
        end
        if(i>10)
            break;
        end
    end 
    t=S;
    
endfunction
