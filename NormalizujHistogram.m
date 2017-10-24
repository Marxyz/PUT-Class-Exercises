function [ outData ] = NormalizujHistogram( bars, dataLength, bins, wbin )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
for i=1:bins
    value = bars(i);
    bars(i) = value/(dataLength*wbin);
end
outData = bars;

end

