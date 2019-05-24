function [X] = Zeidel(A, B, e)
n = size(A);
for i = 1:1:n(1)
sum = 0;
for j = 1:1:n(2)
if(i ~= j)
sum = sum + abs(A(i,j));
end 
end
if(sum > abs(A(i,i)))
fprintf('NE SHODITSA\n');
return;
end
end

fprintf('SHODITSA\n');
[X] = [0];
for i = 2:1:n(1)
[X] = [X, 0];
end
[X_old] = [X];

for i = 1:1:n(1)
sum = 0;
for j = 1:1:n(2)
if(i ~= j)
sum = sum + A(i,j)*X(j);
end 
end
X(i) = (B(i) - sum) / A(i,i);
end
min = (abs(X(1)-X_old(1)));
for i = 2:1:n(1)
if(abs(X(i)-X_old(i)) < min)
min = (abs(X(i)-X_old(i))); 
end
end
it = 1;
while (min > e)
it = it + 1;
[X_old] = [X];
for i = 1:1:n(1)
sum = 0;
for j = 1:1:n(2)
if(i ~= j)
sum = sum + A(i,j)*X(j);
end 
end
X(i) = (B(i) - sum) / A(i,i);
end
min = (abs(X(1)-X_old(1)));
for i = 2:1:n(1)
if(abs(X(i)-X_old(i)) < min)
min = (abs(X(i)-X_old(i))); 
end
end
end
fprintf('Koll Iter %d\n',it);
return;
end

