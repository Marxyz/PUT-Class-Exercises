signal = load("sawtooth.dat");
ts = 0.01;

fourier_trans = fft(signal);
args = angle(fourier_trans);
mod = abs(fourier_trans);

N = length(fourier_trans);
k = 0:1:N-1
fv = k/(N*ts);

sig = zeros(1,N);
fo = 2;
for ks = 1:10
    
    f2 = fo*ks;
    k2 = f2*N*ts;
    
    cks = fourier_trans(k2+1)/N;
    aks = real(cks);
    bks = -1*imag(cks);
    
    sinusy = bks*sin(2*pi*fo*ks*ts*k);
    cosinusy = aks*cos(2*pi*fo*ks*ts*k);
    
    harmon = 2 *(sinusy + cosinusy)
    
    sig = sig + harmon
    
    
end
plot(1:N,sig,'r-')

