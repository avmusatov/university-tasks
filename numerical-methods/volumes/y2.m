function [y2] = y2 (x)
   r=2;
    R=4;
    
   % y2=((R).-sqrt((r).^2.-x.^2)).^2; NB!
   y2=((R).-sqrt((r).^2.-x.^2)).^2; 
endfunction