function [y1] = y1 (x)
    r=2;
    R=4;
  
    % y1=((R).+sqrt((r).^2.-x.^2)).^2; NB!
    y1=((R).+sqrt((r).^2.-x.^2)).^2; 
endfunction
