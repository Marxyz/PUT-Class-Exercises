clear all;
close all;
clc;

t = 0.01;
A = 10;
f = 5;
T = 2;
x = 0:t:T-t;
n1 = (1/t)*(1/f);
y(1:n1/2)=10;
y((n1/2)+1:n1)=-10;
y_end = repmat(y,1,f*T);
length(y)
length(x)
plot(x,y_end);
