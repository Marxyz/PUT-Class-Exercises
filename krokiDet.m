close all;
clear all;

% lista katalogow z danymi z krokomierza
dirs = {'Krokomierz1/', 'Krokomierz2/', 'Krokomierz3/'};

% dla wszystkich katalogow
for d = 1 : length(dirs)
    % wczytywanie danych, format wierszu w pliku: timestamp ax ay az
    data = load(strcat(dirs{d}, 'data.log'));
    % rzeczywisty dystans
    realDist = load(strcat(dirs{d}, 'realDistance.txt'));
    
    % parametry sygnalu
    tlog = 1e-9;
    % wektor czasu
    t = data(:, 1)*tlog;
    % aby czas zaczynal sie od 0
    t = t - min(t);
    Tl = max(t);
    ts = Tl/(length(t) - 1);
    
    % sygnal jako dlugosc wektora przyspieszenia
    x = sqrt(data(:, 2).^2 + data(:, 3).^2 + data(:, 4).^2);
    % wyswietlanie sygnalu
    figure;
    plot(t, x);

    % zmienna, ktora nalezy zwiekszac wraz z wykrywaniem krokow
    dist = 0;
    
    % dlugosc okna - prosze dobrac optymalna wartosc
    Nw = 64;
    
    % ------------------------------------
    % miejsce na dodatkowe zmienne 
    
    % sr dlugosc kroku
    dl = 0.43;

    
    % koniec
    % ------------------------------------

    for i = 1 : length(x) - Nw + 1
        curx = x(i : i + Nw - 1);
        data1 = fft(curx)/Nw;
        modul = abs(data1);
%         plot(modul);
%         pause();
       
        N = length(data1);
        k1 = round(1.2*N*ts);
        k2 = round(2.5*N*ts);
        
        maxVal = 0.3;
        k_max = 0;
        for k=k1:k2
            if modul(k+1)>maxVal
                maxVal = modul(k+1);
                k_max = k;
            end
        end
        % trick
%         [maxval. maxind] = max(abs(x(kmin+1: kmax+1)));
%         k = kmin + maxind-1;

        ftmp = k_max/(N*ts);
        v = ftmp*dl;
        distx = v*ts;
        dist = dist + distx;
        
        % ------------------------------------
        % tutaj powinien sie znalezc kod rozpoznajacy kroki

        
                
        % koniec
        % ------------------------------------
        
    end

    disp(['Obliczony dystans = ', num2str(dist)]);
    disp(['Rzeczywisty dystans = ', num2str(realDist)]);
    
end
