clc;
close all;
data = load('signals.dat');
[k,m] = size(data);
f = 2;
ts = 0.001;
T = 5;
x = 0:ts:T-ts;
data(1,:);
for i =1:k
    [corSin,lagsSin] = xcorr(data(i,:), sin(2*pi*f*x));
    [corCos,lagsCos] = xcorr(data(i,:), cos(2*pi*f*x));
    indSin = find(lagsSin == 0);
    indCos = find(lagsCos == 0);
    rs = corSin(indSin)/m;
    rc = corCos(indCos)/m;
    angle = round(radtodeg(atan2(rc,rs)))
    
    amplitude = round(sqrt(4*(rs^2+rc^2)),1)
    %amplitude2 = 2*rc/sin(angle)
    %amplitude3 = 2*rs/cos(angle)
     
end
