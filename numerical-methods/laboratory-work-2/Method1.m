function [Z] = Method1 (X,Y)
    [m,k] = size(X);
    disp(m);
  
    for i = 1:1:m
        B(i,1) = Y(i,1);
    end
    
    for i = 1:1:m
        for j = 1:1:m
            A(i,j) = X(i,1)^(j - 1);
            C(i,j) = A(i,j);
        end
    end
    
    fprintf('Matrix A: = \n');
    disp(A);
    
    fprintf('Vector B: = \n');
    disp(B);
    
    Z = Gaus(A,B);
    Z = Z';
    fprintf('Answer Z = \n');
    disp (Z);
    
    for i = 1:1:m
        S = 0;
        for j = 1:1:m
            S = S + C(i,j)*Z(j,1);
            P(i,1) = B(i,1) - S;
        end
    end
    
    fprintf('Vector of errors B - AZ =\n');
    disp(P);
    
    Z = Z(end:-1:1);
    
    xx=linspace (X(1), X(end), 100);
    yy=polyval(Z, xx);
    plot (X, Y, 'o', xx, yy, 'r');
end
