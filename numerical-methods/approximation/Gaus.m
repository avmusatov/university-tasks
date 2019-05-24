function [X] = Gaus(A,B)

n=size(A);
AB = [A B];

if rank(A) == rank (AB)
    disp('Решение есть');
    for k=1:1:n(1)-1
         for i=k+1:1:n(1)
           m=A(i,k)/A(k,k);
           for j=1:1:n(1)
            A(i,j) = A(i,j) - m.*A(k,j);
           end
            B(i,1)=B(i,1)-m.*B(k,1);
         end
    end
    X(n(1))= B(n(1))./ A(n(1),n(1));
       for i=n(1)-1:-1:1
        s=0;
        
        for j=i+1:1:n(1)
            s=s+A(i,j).*X(j);
        end
        X(i)=(B(i,1)-s)./A(i,i);
       end
    
else
    disp('Решений нет');
    return;
end
endfunction