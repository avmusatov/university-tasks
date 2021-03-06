% ���������� ����� ��������� x^4 - 18*x^3 - 10 = 0 �������� ��������� � 
% ����( hord.m - ��� ������������� ������ �����������; hord2.m - � ������� ������
% �����������) � ������������ � = 0.001

x = -3:0.1:2;
a = -1.5; b = 0; e = 0.001;

plot(x,f1(x));
grid on;

disp('����� ���������:')
dihot(a,b,e);
disp('����� ���� ��� �����������:')
hord(a,b,e);
disp('����� ���� � �����������:')
hord2(a,b,e);
disp('��������� �������� ����� fzero()')
fprintf('x = %d \n',fzero('f1',-1));
disp('��������� �������� ����� roots()')
p = [1,-18,0,0,-10];
r = roots(p);
fprintf('x = %d \n',r(2,1));