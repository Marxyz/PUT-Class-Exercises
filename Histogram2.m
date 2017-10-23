
rozklad = -4.2 + 2.3*randn(1,1000);

#plot(1:1:20,rozklad,'b.');


l_koszy = 500;
kosze = zeros(1,l_koszy);
min_w = min(rozklad)
max_w = max(rozklad)
szerok_przedzialu = max_w - min_w
sz_kosza = szerok_przedzialu / l_koszy
for k = (1:length(rozklad))
  wart = rozklad(k);
  indeks = (wart - min_w)/sz_kosza;
  if indeks == l_koszy
    kosze(indeks) = kosze(indeks) + 1; 
  else
  indeks = floor(indeks) +1;
  kosze(indeks) = kosze(indeks) + 1;
  end
end
bar(kosze);
