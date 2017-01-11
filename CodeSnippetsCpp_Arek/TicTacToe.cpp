#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

struct Player
{
	string Name;
	string Symbol;
	int wynik;
};

vector<vector<string>> Stworz_Plansze(int wys, int szer)
{
	vector<vector<string>> plansza(wys);
	for (int i = 0; i < wys; i++)
	{
		plansza[i].resize(szer);
		for (int j = 0; j < wys; j++)
		{
			plansza[i][j] = " ";
		}
	}
	return plansza;
}

bool Sprawdz_Wynik(vector<vector<string>> & plansza)
{
	if ((plansza[0][2] != " " && plansza[0][2] == plansza[1][2]) && (plansza[1][2] != " " && plansza[1][2] == plansza[2][2]) && plansza[2][2] != " ")	return 1;
	if ((plansza[0][0] != " " && plansza[0][0] == plansza[1][0]) && (plansza[1][0] != " " && plansza[1][0] == plansza[2][0]) && plansza[2][0] != " ")	return 1;
	if ((plansza[0][0] != " " && plansza[0][0] == plansza[0][1]) && (plansza[0][1] != " " && plansza[0][1] == plansza[0][2]) && plansza[0][2] != " ")	return 1;
	if ((plansza[1][0] != " " && plansza[1][0] == plansza[1][1]) && (plansza[1][1] != " " && plansza[1][1] == plansza[1][2]) && plansza[1][2] != " ")	return 1;
	if ((plansza[2][0] != " " && plansza[2][0] == plansza[2][1]) && (plansza[2][1] != " " && plansza[2][1] == plansza[2][2]) && plansza[2][2] != " ")	return 1;
	if ((plansza[0][0] != " " && plansza[0][0] == plansza[1][1]) && (plansza[1][1] != " " && plansza[1][1] == plansza[2][2]) && plansza[2][2] != " ")	return 1;
	if ((plansza[0][2] != " " && plansza[0][2] == plansza[1][1]) && (plansza[1][1] != " " && plansza[1][1] == plansza[2][0]) && plansza[2][0] != " ")	return 1;
	return 0;
}

void Wyswietl_Plansze(vector<vector<string>>& plansza)
{

	for (int i = 0; i < plansza.size(); i++)
	{
		cout << "|";
		for (int j = 0; j < plansza[i].size(); j++)
		{
			cout << plansza[i][j] << "|";
		}

		cout << endl;
	}
}

void PosuniecieGracza(vector<vector<string>>& plansza, Player player)
{
	int r;
	int c;
	do
	{
		Wyswietl_Plansze(plansza);
		cout << endl;
		cout << "Gracz " + player.Name + ", podaj wspolrzedne pola ktore chcesz zakreslic" << endl;
		cout << "Rzad = ";
		cin >> r;
		cout << "Kolumna = ";
		cin >> c;
		cout << endl;
		if (r >= 4 || c >= 4)
		{
			cout << "Ochujales kiler, pole nieprawdilowe" << endl;
			continue;

		}
		if (plansza[r - 1][c - 1] == "X" || plansza[r - 1][c - 1] == "O")
		{
			cout << "Ochujales kiler, pole zajete" << endl;
			continue;
		}
		plansza[r - 1][c - 1] = player.Symbol;
		break;

	} while (true);

}

void RuchBota(vector<vector<string>>& plansza, Player bot)
{

	// Sprawdzenie mo¿liwych ruchów poziomych 
	for (int row = 0; row < plansza.size(); row++)
	{
		int pkt = 0;
		for (int column = 0; column < plansza[row].size(); column++)
		{

			if (plansza[row][column] != bot.Symbol && plansza[row][column] != " ")
			{
				pkt += 1;
			}
			if (pkt == 2)
			{
				for (int it = 0; it < plansza[row].size(); it++)
				{
					if (plansza[row][it] == " ")
					{
						plansza[row][it] == bot.Symbol;
						return;
					}
				}
			}
		}
	}

	// Ruchy pionowe
	for (int row = 0; row < plansza.size(); row++)
	{
		int pkt = 0;
		for (int column = 0; column < plansza[row].size(); column++)
		{
			int pkt = 0;
			if (plansza[column][row] != bot.Symbol && plansza[column][row] != " ")
			{
				pkt += 1;
			}
			if (pkt == 2)
			{
				for (int it = 0; it < plansza[column].size(); it++)
				{
					if (plansza[column][it] == " ")
					{
						plansza[row][it] == bot.Symbol;
						return;
					}
				}
			}
		}
	}

	//Ruchy na ukos

	//ruch w prawo na dol, na ukos, patrzac od [0][0]
	int pkt = 0;
	for (int i = 0; i < plansza.size(); i++)
	{
		if (plansza[i][i] != bot.Symbol && plansza[i][i] != " ")
		{
			pkt += 1;
		}
		if (pkt == 2)
		{
			for (int iti = 0; iti < plansza.size(); iti++)
			{
				if (plansza[iti][iti] == " ")
				{
					plansza[iti][iti] == bot.Symbol;
					return;
				}
			}
		}
	}

	//Ruch w prawo do góry na ukos, patrz¹c od [2][0]

	int pkt = 0;
	int pomo = 2;
	for (int i = 0; i < plansza.size()`; i++)
	{
		if (plansza[pomo][i] != bot.Symbol && plansza[pomo][i] != " ")
		{
			pkt += 1;
		}
		if (pkt == 2)
		{
			int pomo2 = 2;
			for (int itii = 0; itii < plansza.size()`; itii++)
			{
				if (plansza[pomo][itii] != bot.Symbol && plansza[pomom][itii] != " ")
				{
					plansza[pomo][itii] == bot.Symbol;
				}
				pomo2--;

		}
		pomo--;
	}

	// Po sprawdzeniu czy nastepny ruch bota nie jest przegrywajacym, czas sprawdzic czy botowi bardziej oplaca sie 
	// zablokowac kolumne gracza z jednym symbolem czy zaatakowac


}


int main()
{
	

	int tura = 1;
	bool main_loop = true;
	Player Gracz1 = { "Arek", "X", 0 };
	Player Gracz2 = { "Miki", "O", 0 };
	vector<vector<string>> plansza = Stworz_Plansze(3, 3);
	while (main_loop)
	{
		Player aktualnyGracz;
		if (tura % 2 == 0)
		{
			aktualnyGracz = Gracz1;
		}
		else
		{
			aktualnyGracz = Gracz2;
		}

		PosuniecieGracza(plansza, aktualnyGracz);

		if (Sprawdz_Wynik(plansza))
		{
			cout << aktualnyGracz.Name + " odniosl epickie zwyciestwo !!!!" << endl;
			Wyswietl_Plansze(plansza);
			break;
		}

		tura++;
	}

}