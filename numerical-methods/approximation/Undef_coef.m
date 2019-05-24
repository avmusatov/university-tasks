function [ Z ] = Undef_coef(X,Y)

[m n]=size(X);
for i=1:1:m
    B(i)=Y(i,1);
end
for i=1:1:m
    for j=1:1:m
        A(i,j)=X(i,1)^(j-1);
        C(i,j)=A(i,j);
    end
end
for i=1:1:m+1
    Z(i)=0;
end
fprintf('A=');
disp(A);
Z=Gaus(A,Y);
fprintf('z=');
disp(Z);
endfunction


