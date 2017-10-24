function [ outData ] = CustomHistogram( data, maxValue, minValue,bins,wbin)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
bars = zeros(1,bins);
for i=1:length(data)
    yval = data(i);
    a = (data(i)-minValue)/wbin;
    ind = floor(a)+1;
    if ind > bins
        ind = ind -1;
    end;
    bars(ind) = bars(ind)+1 ; 
end
outData = bars;

end

