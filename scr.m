clc;
clear all;
close all;

task1 = [5 16 18];
task2 = [1 3 3];
task3 = [4 7 9];
taskTab = [task1;task2;task3];

hiperOkres1 = lcm(taskTab(1,3), taskTab(2,3));
hiperOkres2 = lcm(hiperOkres1, taskTab(3,3));

table = zeros(5,18)';
for i=1:hiperOkres2
    table(i,1) = i-1;
    for k=1:3
        table(i,k+1) = sum(taskTab(k,1)*floor(((i-1-taskTab(k,2))/taskTab(k,3))+1));
    end
    table(i,5) = sum(table(i,2:4))
end

table = table'
plot(table(1,:),table(1,:))
hold on;
stairs(table(1,:),table(5,:))
