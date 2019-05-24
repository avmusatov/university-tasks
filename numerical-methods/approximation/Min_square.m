function [ z ] = Min_square( x, y )
n=size(x);
n1=size(y);
if (n1(1)==1)
    y=y';
    n1=size(y);
end
if (n(1)==1)
    x=x';
    n=size(x);
end
if (n(1)~=n1(1))
    fprintf ('Error!\n');
    return;
end
%Обнуляем обе матрицы
for q=1:1:n(1)
    for w=q:1:n(1)
        a(q, w)=0;
        b(q)=0;        
        a(w,q)=a(q, w);
    end
end
%Заполняем матрицы
for q=1:1:n(1)
    for w=q:1:n(1)
        for i=1:1:n(1)
            a(q, w)=a(q, w)+x(i)^(q+w-2);            
        end
        a(w,q)=a(q, w);
    end
end
for q=1:1:n(1)
    for i=1:1:n(1)
        b(q)=b(q)+x(i)^(q-1)*y(i);
    end
end
%Транспонируем матрицу; Ищем матрицу требуемых коэффицентов
b=b';
z=a\b;
z=z(n(1):-1:1);
%Рисуем график точек
xx=linspace (x(1), x(end), 100);
yy=polyval(z, xx);
plot (x, y, 'o', xx, yy, 'r')
%Поиск погрешностей
eps=0;
%for i=1:1:n(1)
 %   eps=eps+(func(z, x(i))-y(i))^2;
%end
%eps=sqrt(eps/n(1));
%disp (eps);
endfunction

