function [Volume] = calculateVolume()    
    a=2;
    b=4;
    e=0.01;
    
    Volume=2.*pi.*(quad(@y1,0,a,e)-quad(@y2,0,a,e));
    fprintf('\nTorus: r=%2.4f, R=%2.4f, Volume=%2.4f\n',a,b,Volume);
    
    xx=linspace(-pi,pi,100);
    a = 2; % радиус образующей
    b = 4; % радиус направл€ющей
    f = (0:10:360)*pi/180; % углова€ переменна€ (образующа€)
    v = (0:10:360)*pi/180; % углова€ переменна€ (направл€юща€)
    
    [F, V] = meshgrid(f, v);
    X = (b + a*cos(F)).*cos(V);
    Y = (b + a*cos(F)).*sin(V);
    Z = -a*sin(F); 
    surf(X,Y,Z);
    
    axis equal;
    title('Torus'); 
    xlabel('X'); 
    ylabel('Y'); 
    zlabel('Z'); 
    hold on;

endfunction
