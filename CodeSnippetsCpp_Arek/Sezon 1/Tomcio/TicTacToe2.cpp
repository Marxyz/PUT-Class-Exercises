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

struct Plansza
{
	vector<vector<string>> board;
	string NullSign;
};

void Stworz_Plansze(Plansza& Plansza, int wys, int szer)
{
	vector<vector<string>> pl(wys);
	for (int i = 0; i < wys; i++)
	{
		pl[i].resize(szer);
		for (int j = 0; j < wys; j++)
		{
			pl[i][j] = Plansza.NullSign;
		}
	}
	Plansza.board = pl;
}

bool Sprawdz_Wynik(Plansza& plansza)
{

	// Poziome

	for (int row = 0; row < plansza.board.size(); row++)
	{
		int repeat = 0;
		string last_sign = plansza.board[row][0];
		for (int col = 0; col < plansza.board[row].size(); col++)
		{

			if (last_sign == plansza.NullSign)
			{
				break;
			}
			if (last_sign == plansza.board[row][col])
			{
				repeat += 1;
			}
			if (repeat == plansza.board.size())
			{
				return 1;
			}
			last_sign = plansza.board[row][col];

		}
	}

	// Pionowe

	for (int col = 0; col < plansza.board.size(); col++)
	{
		int repeat = 0;
		string last_sign = plansza.board[0][col];
		for (int row = 0; row < plansza.board[col].size(); row++)
		{

			if (last_sign == plansza.NullSign)
			{
				break;
			}
			if (last_sign == plansza.board[row][col])
			{
				repeat += 1;
			}
			if (repeat == plansza.board.size())
			{
				return 1;
			}
			last_sign = plansza.board[row][col];

		}
	}

	// Ukos od lewej w dól

	string last_sign = plansza.board[0][0];
	int repeat = 0;
	for (int itr = 0; itr < plansza.board.size(); itr++)
	{

		if (last_sign == plansza.NullSign)
		{
			break;
		}
		if (last_sign == plansza.board[itr][itr])
		{
			repeat += 1;

		}
		if (repeat == plansza.board.size())
		{
			return 1;
		}
		last_sign = plansza.board[itr][itr];
	}

	// Ukos od prawej w dol

	int pom = plansza.board.size() - 1;
	last_sign = plansza.board[0][pom];
	repeat = 0;
	for (int row = 0; row < plansza.board.size(); row++)
	{


		if (last_sign == plansza.NullSign)
		{
			break;
		}
		if (last_sign == plansza.board[row][pom])
		{
			repeat += 1;

		}
		if (repeat == plansza.board.size())
		{
			return 1;
		}
		last_sign = plansza.board[row][pom];
		pom--;
	}

	return 0;
}

void Wyswietl_Plansze(Plansza& plansza)
{

	for (int i = 0; i < plansza.board.size(); i++)
	{
		cout << "|";
		for (int j = 0; j < plansza.board[i].size(); j++)
		{
			cout << plansza.board[i][j] << "|";
		}

		cout << endl;
	}
}

void PosuniecieGracza(Plansza& plansza, Player* aktualnyGracz, Player Gracz1, Player Gracz2)
{

	int r;
	int c;
	do
	{
		Wyswietl_Plansze(plansza);
		cout << endl;
		cout << "Gracz " + aktualnyGracz->Name+ ", podaj wspolrzedne pola ktore chcesz zakreslic" << endl;
		cout << "Rzad = ";
		cin >> r;
		if (cin.fail())
		{
			cout << "Podaj liczbe!" << endl;
			cin.clear();
			cin.ignore(10, '\n');
			cin.sync();
			continue;
		}
		cout << "Kolumna = ";
		cin >> c;
		if (cin.fail())
		{
			cout << "Podaj liczbe!" << endl;
			cin.clear();
			cin.ignore(10, '\n');
			cin.sync();
			continue;
		}
		cout << endl;
		if (r > plansza.board.size() || c > plansza.board.size())
		{
			cout << "Pole nieprawdilowe!" << endl;
			continue;

		}
		if (plansza.board[r - 1][c - 1] == Gracz1.Symbol || plansza.board[r - 1][c - 1] == Gracz2.Symbol)
		{
			cout << "Pole zajete!" << endl;
			continue;
		}
		plansza.board[r - 1][c - 1] = aktualnyGracz->Symbol;
		break;

	} while (true);

}


bool Czy_Remis(Plansza& plansza)
{
	for (int row = 0; row < plansza.board.size(); row++)
	{
		for (int column = 0; column < plansza.board[row].size(); column++)
		{
			if (plansza.board[row][column] == plansza.NullSign)
			{
				return false;
			}
		}

	}
	return true;
}
Plansza Restart(Plansza plansza, int wym)
{
	Stworz_Plansze(plansza, wym, wym);
	return plansza;
}

int MenuKoncowe()
{

	int numer;
	cout << "Koontynuowac ? - wcisnij 1\n"
		"Zakonczyc ? - wcisnij 2" << endl;
	do
	{
		cin >> numer;
		if (cin.fail() || numer > 2)
		{
			cout << "Podaj prawidlowa liczbe (1 lub 2)!" << endl;
			cin.clear();
			cin.ignore(10, '\n');
			cin.sync();
			continue;
		}
		cout << endl;
		break;
	} while (1);
	return numer;
}

void GameIsOff(Player&gracz1, Player&gracz2) 
{
	cout << "Koniec Gry" << endl
		<< "Gracz " << gracz1.Name << " zdobyl " << gracz1.wynik << " punktow." << endl
		<< "Gracz " << gracz2.Name << " zdobyl " << gracz2.wynik << " punktow." << endl
		<< endl;
}

int main()
{
	int wym;
	do
	{
		cout << "Podaj wymiar planszy : ";
		cin >> wym;
		if (cin.fail() || wym < 0)
		{
			cout << "Podaj prawidlowa liczbe (1 lub 2)!" << endl;
			cin.clear();
			cin.ignore(10, '\n');
			cin.sync();
			continue;
		}
		break;
	} while (true);


	int tura = 1;
	bool main_loop = true;
	Player Gracz1 = { "Arek", "X", 0 };
	Player Gracz2 = { "Agnes", "O", 0 };
	Plansza plansza;
	plansza.NullSign = " ";
	Stworz_Plansze(plansza, wym, wym);
	while (main_loop)
	{
		Player* aktualnyGracz;
		if (tura % 2 == 1)
		{
			aktualnyGracz = &Gracz1;
		}
		else
		{
			aktualnyGracz = &Gracz2;
		}

		PosuniecieGracza(plansza, aktualnyGracz, Gracz1, Gracz2);

		if (Sprawdz_Wynik(plansza))
		{
			cout << "Gracz " << aktualnyGracz->Name + " odniosl epickie zwyciestwo !!!!" << endl;
			aktualnyGracz->wynik += 1;
			Wyswietl_Plansze(plansza);

			if (MenuKoncowe() == 1)
			{
				plansza = Restart(plansza, wym);
			}
			else
			{
				GameIsOff(Gracz1, Gracz2);
				break;
			}

		}

		if (Czy_Remis(plansza))
		{
			cout << "Remis, nikt nie wygral" << endl;
			if (MenuKoncowe() == 1)
			{
				plansza = Restart(plansza, wym);
			}
			else
			{
				GameIsOff(Gracz1, Gracz2);
				break;
			}
		}

		tura++;
	}

}