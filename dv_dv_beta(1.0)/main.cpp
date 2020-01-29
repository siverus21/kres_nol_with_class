/*#include <iostream>
#include <locale>
#include <ctime>

using namespace std;

int mas[3][3];
int a = 0;
int b = 0;
char name1[30];
char name2[30];

void pravilo()
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

void name()
{
	cout << endl;
	cout << "Введи свое имя, игрок 1: ";
	cin.getline(name1, 30);
	cout << endl;
	cout << "Введи свое имя, игрок 2: ";
	cin.getline(name2, 30);
	cout << endl;
}

void new_name()
{
	cout << endl;
	cout << "Введи свое имя, игрок 1: ";
	cin.getline(name1, 30);
	cin.getline(name1, 30);
	cout << endl;
	cout << "Введи свое имя, игрок 2: ";
	cin.getline(name2, 30);
	cout << endl;
}

void game()
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
}

void game1()
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
}


void obn()
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

void obnylenie()
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mas[i][j] = 0;
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int end_game = 0;
	char again_play = 'q';
	int y = 1;
	int n = 0;
	int k1 = 1;
	while (end_game != 1)
	{
		pravilo();
		if (k1 == 1)
		{
			name();
			obn();
		}
		else if (k1 != 1)
		{
			new_name();
			obnylenie();
		}
		k1++;

		int s = 0;
		int s1 = 0;
		int k = 0;
		int e = 0;

		int q = 0;
		q = rand() % 2 + 1;

		if (q == 1)
		{
			cout << "Первым ходит игрок: " << name1 << " (1)" << endl;
			cout << endl;
			for (int s1 = 0; s1 <= 4; s1++)
			{
				while (e != 1)
				{
					cin >> a;
					a--;
					if (a >= 0 && a <= 8 && mas[a / 3][a % 3] == 0)
					{
						a++;
						game();
						e = 1;
					}
					else
					{
						cout << endl;
						cout << "Это поле уже занято игроком: " << name2 << endl;
						cout << "Ходите еще раз" << endl;
						cout << endl;
						obn();
					}
				}
				e = 0;
				obn();

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
					break;
					break;
				}
				cout << endl;
				cout << "Теперь ходит игрок: " << name2 << " (2)" << endl;
				cout << endl;
				while (e != 1)
				{
					cin >> b;
					b--;
					if (b >= 0 && b <= 8 && mas[b / 3][b % 3] == 0)
					{
						b++;
						game1();
						e = 1;
					}
					else
					{
						cout << endl;
						cout << "Это поле уже занято игроком: " << name1 << endl;
						cout << "Ходите еще раз" << endl;
						cout << endl;
						obn();
					}
				}

				e = 0;
				obn();

				if (((mas[0][0] == 2) && (mas[0][1] == 2) && (mas[0][2] == 2)) ||
					((mas[1][0] == 2) && (mas[1][1] == 2) && (mas[1][2] == 2)) ||
					((mas[2][0] == 2) && (mas[2][1] == 2) && (mas[2][2] == 2)) ||
					((mas[0][0] == 2) && (mas[1][0] == 2) && (mas[2][0] == 2)) ||
					((mas[0][1] == 2) && (mas[1][1] == 2) && (mas[2][1] == 2)) ||
					((mas[0][2] == 2) && (mas[1][2] == 2) && (mas[2][2] == 2)) ||
					((mas[0][0] == 2) && (mas[1][1] == 2) && (mas[2][2] == 2)) ||
					((mas[0][2] == 2) && (mas[1][1] == 2) && (mas[2][0] == 2)))
				{
					k = 2;	//если выиграл 2 игрок
				}
				if (k == 2)
				{
					s1 = 4;
					break;
					break;
				}
				cout << endl;
				cout << "Теперь ходит игрок: " << name1 << " (1)" << endl;
				cout << endl;
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (q == 2)
		{
			cout << "Первым ходит игрок: " << name2 << " (2)" << endl;
			cout << endl;
			for (int s = 0; (s <= 4); s++)
			{
				while (e != 1)
				{
					cin >> b;
					b--;
					if (b >= 0 && b <= 8 && mas[b / 3][b % 3] == 0)
					{
						b++;
						game1();
						e = 1;
					}
					else
					{
						cout << endl;
						cout << "Это поле уже занято игроком: " << name1 << endl;
						cout << "Ходите еще раз" << endl;
						cout << endl;
						obn();
					}
				}
				e = 0;
				obn();
				if (((mas[0][0] == 2) && (mas[0][1] == 2) && (mas[0][2] == 2)) ||
					((mas[1][0] == 2) && (mas[1][1] == 2) && (mas[1][2] == 2)) ||
					((mas[2][0] == 2) && (mas[2][1] == 2) && (mas[2][2] == 2)) ||
					((mas[0][0] == 2) && (mas[1][0] == 2) && (mas[2][0] == 2)) ||
					((mas[0][1] == 2) && (mas[1][1] == 2) && (mas[2][1] == 2)) ||
					((mas[0][2] == 2) && (mas[1][2] == 2) && (mas[2][2] == 2)) ||
					((mas[0][0] == 2) && (mas[1][1] == 2) && (mas[2][2] == 2)) ||
					((mas[0][2] == 2) && (mas[1][1] == 2) && (mas[2][0] == 2)))
				{
					k = 2; //если выиграл 2 игрок;
				}
				if (k == 2)
				{
					s = 4;
					break;
					break;

				}
				cout << endl;
				cout << "Теперь ходит игрок: " << name1 << " (1)" << endl;
				cout << endl;
				while (e != 1)
				{
					cin >> a;
					a--;
					if (a >= 0 && a <= 8 && mas[a / 3][a % 3] == 0)
					{
						a++;
						game();
						e = 1;
					}
					else
					{
						cout << endl;
						cout << "Это поле уже занято игроком: " << name2 << endl;
						cout << "Ходите еще раз" << endl;
						cout << endl;
						obn();
					}
				}
				e = 0;
				obn();
				if (((mas[0][0] == 1) && (mas[0][1] == 1) && (mas[0][2] == 1)) ||
					((mas[1][0] == 1) && (mas[1][1] == 1) && (mas[1][2] == 1)) ||
					((mas[2][0] == 1) && (mas[2][1] == 1) && (mas[2][2] == 1)) ||
					((mas[0][0] == 1) && (mas[1][0] == 1) && (mas[2][0] == 1)) ||
					((mas[0][1] == 1) && (mas[1][1] == 1) && (mas[2][1] == 1)) ||
					((mas[0][2] == 1) && (mas[1][2] == 1) && (mas[2][2] == 1)) ||
					((mas[0][0] == 1) && (mas[1][1] == 1) && (mas[2][2] == 1)) ||
					((mas[0][2] == 1) && (mas[1][1] == 1) && (mas[2][0] == 1)))
				{
					k = 1; //если выиграл 1 игрок
				}
				if (k == 1)
				{
					s = 4;
					break;
					break;
				}
				cout << endl;
				cout << "Теперь ходит игрок: " << name2 << " (2)" << endl;
				cout << endl;
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (k == 1)
		{
			cout << "Победил(a): " << name1 << endl;
		}
		else if (k == 2)
		{
			cout << "Победил(a): " << name2 << endl;
		}
		else
		{
			cout << "Ничья " << endl;
		}

		cout << endl;
		cout << "Ходите сыграть еще раз? (y/n)" << endl;
		cout << endl;

		while (again_play != 'y' || again_play != 'n')
		{
			cin >> again_play;
			if (again_play == 'y')
			{
				end_game = 0;
				break;
				break;
			}
			else if (again_play == 'n')
			{
				end_game = 1;
				break;
				break;
			}
			else
			{
				cout << "Введена неверная буква" << endl;
			}
		}
		again_play = 'q';
		cout << endl;
	}

	cout << "Спасибо за игру" << endl;
	cout << endl;

	system("pause");
	return 0;
}*/