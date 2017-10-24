function [ outData ] = OdchylenieStandardowe( inData )
%ODCHYLENIESTANDARDOWE Summary of this function goes here
%   Detailed explanation goes here
wartOczek = WartOczekiwana(inData);
estymator = mean((inData - wartOczek).^2);
outData = sqrt(estymator);

end

