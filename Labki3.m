clc;
clear all;
close all;

data = -4.2 + 2.3*randn(1,100000);
%data = [-5 4 2 1 1 3 8 -2 -3 5];
%data = 9 + 2.3*randn(1,10);
%data = [-1 2 4 -3 5 7 -3 2 2 -1];
wartOczek = WartOczekiwana(data);
odchylenie = OdchylenieStandardowe(data);

maxValue = max(data);
minValue = min(data);

bins = 100;
wbin = (maxValue-minValue)/bins;
%bars = zeros(1,bins);
% for i=1:length(data)
%     yval = data(i);
%     a = (data(i)-minValue)/wbin;
%     ind = floor(a)+1;
%     if ind > bins
%         ind = ind -1;
%     end;
%     bars(ind) = bars(ind)+1 ; 
% end

% for i=1:bins
%     bars(i) = bars(i)/(length(data)*wbin);
% end

bars = CustomHistogram(data, maxValue, minValue,bins,wbin);
bars = NormalizujHistogram(bars,length(data),bins,wbin);


x = minValue:wbin:maxValue-wbin;
barh(x,bars);
hold on;
plot(normpdf2(x,-4.2,2.3),x);


