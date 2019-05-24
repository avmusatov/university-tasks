function [ t ] = mycos( x,eps )

n=0;
a=1;%член разложения
S=1;

while(1)
    n=n+1;
    R = ((-1)*x.*x)/((2*n-1)*(2*n));
    a=a.*R;
    S=S+a;
    if (abs(a)./abs(S) <= eps)
        break;
    end
end

t = S;

endfunction
