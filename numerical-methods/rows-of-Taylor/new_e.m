function [ s ] =  new_e(x,e)

a=1;
s=a;
i=1;

while  (abs(a)/abs(s)) > e 
   R= x./i;
   a= a.* R;
   s= s + a;
   i= i + 1;
end
endfunction

