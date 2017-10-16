function [sygnal] = Pila ()

ts = 0.00001;
Amp = 5.12;
f = 5;
T = 2;

x = 0:ts:T-ts;

#liczba próbek w jednym schodku

n1 = 1/f * 1/ts;
krok = Amp/n1;
y1 = 0:krok:Amp - krok;

y = repmat(y1,1,f*T);

plot(x,y,'r-');
sygnal = y;



endfunction
