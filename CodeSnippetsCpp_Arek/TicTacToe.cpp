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