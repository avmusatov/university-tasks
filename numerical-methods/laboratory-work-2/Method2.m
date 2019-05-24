function [Z] = Method2 (X,Y,n)
    
    [m,k] = size(X); % m - количество узлов, n - порядок полинома
    l = n + 1;  % l - порядок матрицы А
    
    for i = 1:1:l
        B(i,1) = 0;
        for j = 1:1:l
            A(i,j) = 0;
        end
    end
    
    for k = 1:1:m
        for i = 1:1:l
            B(i,1) = B(i,1) + Y(k,1)*X(k,1)^(i - 1);
            for j = i:1:l
                A(i,j) = A(i,j) + X(k,1)^(i+j - 2);
            end
        end
    end
    
    for i = 1:1:l
        for j = 1:1:l
            if i > j
                A(i,j) = A(j,i);
            end
        end
    end
    
    fprintf('Matrix A: = \n');
    disp(A);
    
    fprintf('Vector B: = \n');
    disp(B);
    
    % С - копия А, а D- копия В
    for i = 1:1:l
        D(i,1) = B(i,1);
        for j = 1:1:l
            C(i,j) = A(i,j);
        end
    end
    
    Z = Gaus(A,B);
    Z = Z';
    fprintf('Answer Z = \n');
    disp (Z);
    
    for i = 1:1:l
        S = 0;
        for j = 1:1:l
            S = S + C(i,j)*Z(j,1);
            P(i,1) = D(i,1) - S;
        end
    end
    
    fprintf('Vector of errors B - AZ =\n');
    disp(P);
    
    
    Z = Z(end:-1:1);
    xx = linspace(X(1),X(end),100);
    yy = polyval(Z,xx);
    plot(X,Y,'o',xx,yy, 'r');
    
end
