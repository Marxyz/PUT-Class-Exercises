
sig = load('signals.dat');
f = 2;
ts= 0.001;
t = 5;
x = [0:ts:t-ts];

syg_wzor_sin = sin(2*pi*f*x);
syg_wzor_cos = cos(2*pi*f*x);

[rows,cols] =  size(sig);

for i = 1:1:rows
    
   syg_por = sig(i,1:1:cols);
   N = length(syg_por);

   [kor_sin,lags_sin] = xcorr(syg_por,syg_wzor_sin);
   
   kor_0_sin = kor_sin(N)/N;
   
   [kor_cos,lags_cos] = xcorr(syg_por,syg_wzor_cos);
 
   kor_0_cos = kor_cos(N)/N;
   
   A = sqrt(4*(kor_0_sin^2 + kor_0_cos^2))
   
   fi = rad2deg(atan2(kor_0_cos,kor_0_sin))
   
   
end