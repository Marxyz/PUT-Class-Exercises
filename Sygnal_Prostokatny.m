function [sygnal] = Sygnal_Prostokatny ()
Amp = 2;
T = 2;
Ts = 0.001;
f = 5;
x = 0:Ts:T-Ts;

# dlugosc trwania skoku
# n1 = 1/f;
helper = 1;
sygnal = [];
for(y = 1:length(x))  
   if mod(x(y) * 1/Ts,1/f*1/Ts)==0
     helper++;
   end
   if mod(helper,2)==0;
     sygnal = [sygnal Amp];
   else
      sygnal=[sygnal -Amp];
   end
endfor

plot(x,sygnal,'r-');

endfunction
