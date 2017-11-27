clc;
clear all;
close all;
f = 2;
T = 2;

fs = 20;
fi = degtorad(90);

x = 0:1/fs:T-1/fs;

sinus = sin(2*pi*f*x);
win = window(@gausswin,length(sinus));

% plot(sinus)
% sinus2 = sin(2*pi*f*x + fi);

fft_data = fft(sinus);

N = length(fft_data);
k_tmp = 0:1:N-1;
f = k_tmp*fs/(N);

modul = abs(fft_data);
arg = angle(fft_data);

sig = win'.*sinus;
fft_data2 = fft(sig);


modul2 = abs(fft_data2);
arg2 = angle(fft_data2);

figure
subplot(2,2,1);
bar(f, modul);
subplot(2,2,2);
plot(f,arg, '-g');

subplot(2,2,3);
bar(f,modul2);
subplot(2,2,4);
plot(f,arg2, '-r');

