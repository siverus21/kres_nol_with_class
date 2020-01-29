#include <iostream>
#include <locale>
#include <ctime>

using namespace std;

class Players
{
public:
	void Pravilo(int a)
	{
		if (a == 0)
		{
		cout << "Каждый игрок ходит по очереди." << endl;
		cout << endl;
		cout << "Первым ходит игрок1 и у него код '1'." << endl;
		cout << endl;
		cout << "После 1 игрока, ходит игрок2 и у него код '2'." << endl;
		cout << endl;
		cout << "[1] [2] [3] " << endl;
		cout << "[4] [5] [6] " << endl;
		cout << "[7] [8] [9] " << endl;
		}
		
	}
	int Player1(int a, int mas[2][2])
	{
		if (a == 1) {
			mas[0][0] = 1;
		}
		else if (a == 2) {
			mas[0][1] = 1;
		}
		else if (a == 3) {
			mas[0][2] = 1;
		}
		else if (a == 4) {
			mas[1][0] = 1;
		}
		else if (a == 5) {
			mas[1][1] = 1;
		}
		else if (a == 6) {
			mas[1][2] = 1;
		}
		else if (a == 7) {
			mas[2][0] = 1;
		}
		else if (a == 8) {
			mas[2][1] = 1;
		}
		else if (a == 9) {
			mas[2][2] = 1;
		}
		return mas[2][2], a;
	}
	int Player2(int b, int mas[2][2])
	{
		if (b == 1) {
			mas[0][0] = 2;
		}
		else if (b == 2) {
			mas[0][1] = 2;
		}
		else if (b == 3) {
			mas[0][2] = 2;
		}
		else if (b == 4) {
			mas[1][0] = 2;
		}
		else if (b == 5) {
			mas[1][1] = 2;
		}
		else if (b == 6) {
			mas[1][2] = 2;
		}
		else if (b == 7) {
			mas[2][0] = 2;
		}
		else if (b == 8) {
			mas[2][1] = 2;
		}
		else if (b == 9) {
			mas[2][2] = 2;
		}
		return mas[2][2], b;
	}
	void obnylenie(int mas[2][2])
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mas[i][j] = 0;
			}
		}
	}
	void name(char name1[30], char name2[30])
	{
		cout << endl;
		cout << "Введи свое имя, игрок 1: ";
		cin.getline(name1, 30);
		cout << endl;
		cout << "Введи свое имя, игрок 2: ";
		cin.getline(name2, 30);
		cout << endl;
	}
	 void obn(int mas[2][2])
	 {
		cout << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	 }
	int win_first_player(int mas[2][2], int k, int s1)
	{
		if (((mas[0][0] == 1) && (mas[0][1] == 1) && (mas[0][2] == 1)) ||
			((mas[1][0] == 1) && (mas[1][1] == 1) && (mas[1][2] == 1)) ||
			((mas[2][0] == 1) && (mas[2][1] == 1) && (mas[2][2] == 1)) ||
			((mas[0][0] == 1) && (mas[1][0] == 1) && (mas[2][0] == 1)) ||
			((mas[0][1] == 1) && (mas[1][1] == 1) && (mas[2][1] == 1)) ||
			((mas[0][2] == 1) && (mas[1][2] == 1) && (mas[2][2] == 1)) ||
			((mas[0][0] == 1) && (mas[1][1] == 1) && (mas[2][2] == 1)) ||
			((mas[0][2] == 1) && (mas[1][1] == 1) && (mas[2][0] == 1)))
		{
			k = 1;		//если выиграл 1 игрок
		}
		if (k == 1)
		{
			s1 = 4;
		}
		return mas[2][2], k, s1;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	int FirstPlayer, SecondPlayer;
	int mas[2][2];
	char name1[30];
	char name2[30];
	char again_play = 'q';
	int k = 1;
	int q = 0;
	int e = 0;
	
	int prav = 0;

	Players Game;
	bool end_game = false;
	while (end_game != true)
	{
		Game.Pravilo(prav);
		Game.obnylenie(mas);
		if (k == 1)
		{
			Game.name(name1, name2);
			Game.obn(mas);
		}
		else if (k != 1)
		{
			Game.name(name1, name2);	
		}
		k++;
		q = rand() % 2 + 1;
		if (q == 1)
		{
			cout << "Первым ходит игрок: " << name1 << " (1)" << endl;
			cout << endl;
			for (int s1 = 0; s1 <= 4; s1++)
			{
				while (e != 1)
				{
					cin >> FirstPlayer;
					FirstPlayer--;
					if (FirstPlayer >= 0 && FirstPlayer <= 8 && mas[FirstPlayer / 3][FirstPlayer % 3] == 0)
					{
						FirstPlayer++;
						Game.Player1(FirstPlayer, mas);
						e = 1;
					}
					else
					{
						cout << endl;
						cout << "Это поле уже занято игроком: " << name2 << endl;
						cout << "Ходите еще раз" << endl;
						cout << endl;
						Game.obn(mas);
					}
				}
			}
		}
		else if (q == 2)
		{

		}
		end_game = false;
	}
	system("pause");
	return 0;
}