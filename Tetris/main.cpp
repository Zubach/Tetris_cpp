#include <iostream>
#include <ctime>
#include <windows.h>
#include <Conio.h>
#include <iomanip>

//KeyBoard codes
#define ArrowUp 72
#define ArrowRight 77
#define ArrowLeft 75 
#define ArrowDown 80
#define Num8 56
#define Num2 50
#define KeyP 112

//SIZE
//#define FIELD_HEIGHT 15
//#define FIELD_WIDTH 12

using namespace std;

int score = 0;
void PrintArr(char** arr, int row, int col, int score) {
	for (int i = 0; i < row; i++) {

		cout << char(186);
		for (int j = 0; j < col; j++)
			cout << arr[i][j];
		cout << char(186);
		if (i == 1)
			cout << "Pause: <Press P>";
		if (i == 5)
			cout << "Score: " << score;
		cout << endl;
	}
	cout << char(200);
	for (int i = 0; i < col; i++)
		cout << char(205);
	cout << char(188) << endl;
}
void FillArr(char** arr, int row, int col) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = ' ';
}
char** CreateArr(int row, int col) {
	char** arr = new char* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new char[col];
	return arr;
}
void RandFigure(char** arr, int row, int col, int& x, int& y, int& x1, int& y1, int& type) {
	type = rand() % 5 + 1;
	//type = 1;
	switch (type) {
	case 1:
		arr[0][5] = '*';
		arr[1][4] = '*';
		arr[1][5] = '*';
		arr[1][6] = '*';
		x = 0;
		y = 4;
		x1 = 1;
		y1 = 6;
		break;
	case 2:
		arr[0][5] = '*';
		arr[1][5] = '*';
		arr[2][5] = '*';
		arr[3][5] = '*';
		x = 0;
		y = 5;
		x1 = 3;
		y1 = 5;
		break;
	case 3:
		arr[0][6] = '*';
		arr[1][4] = '*';
		arr[1][5] = '*';
		arr[1][6] = '*';
		x = 0;
		y = 4;
		x1 = 1;
		y1 = 6;
		break;
	case 4:
		arr[0][5] = '*';
		arr[0][6] = '*';
		arr[1][5] = '*';
		arr[1][4] = '*';
		x = 0;
		y = 4;
		x1 = 1;
		y1 = 6;
		break;
	case 5:
		arr[0][5] = '*';
		arr[0][6] = '*';
		arr[1][5] = '*';
		arr[1][6] = '*';
		x = 0;
		y = 5;
		x1 = 1;
		y1 = 6;
	}
}
void gameOver()
{
	cout << " #####     #    #     # ####### ####### #     # ####### ######\n";
	cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
	cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
	cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
	cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
	cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
	cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
}
void PrintFigure(char** arr, char** f, int x, int y, int x1, int y1) {
	for (int i = x, k = 0; i <= x1; i++, k++)
		for (int j = y, m = 0; j <= y1; j++, m++) {
			if (f[k][m] == '*' && arr[i][j] != '*')
				arr[i][j] = f[k][m];

		}
}
void SaveFigure(char** f, int type) {
	switch (type) {
	case 1:
		f[0][1] = '*';
		f[1][0] = '*';
		f[1][1] = '*';
		f[1][2] = '*';
		break;
	case 2:
		f[0][0] = '*';
		f[1][0] = '*';
		f[2][0] = '*';
		f[3][0] = '*';
		break;
	case 3:
		f[0][2] = '*';
		f[1][0] = '*';
		f[1][1] = '*';
		f[1][2] = '*';
		break;
	case 4:
		f[0][1] = '*';
		f[0][2] = '*';
		f[1][0] = '*';
		f[1][1] = '*';
		break;
	case 5:
		f[0][0] = '*';
		f[0][1] = '*';
		f[1][0] = '*';
		f[1][1] = '*';
		break;
	}
}
void Rotate(char** f, int& x, int& y, int& x1, int& y1, int type, int& rotate_c) {
	switch (type) {
	case 1:
		switch (rotate_c) {
		case 1:
			FillArr(f, 4, 4);
			f[0][0] = '*';
			f[1][0] = '*';
			f[2][0] = '*';
			f[1][1] = '*';
			x1 = x1 + 1;
			y1 = y1 - 1;
			break;
		case 2:
			FillArr(f, 4, 4);
			f[0][0] = '*';
			f[0][1] = '*';
			f[0][2] = '*';
			f[1][1] = '*';
			x1 = x1 - 1;
			y1 = y1 + 1;
			break;
		case 3:
			FillArr(f, 4, 4);
			f[0][1] = '*';
			f[1][1] = '*';
			f[2][1] = '*';
			f[1][0] = '*';
			x1 = x1 + 1;
			y1 = y1 - 1;
			break;
		case 4:
			FillArr(f, 4, 4);
			f[0][1] = '*';
			f[1][0] = '*';
			f[1][1] = '*';
			f[1][2] = '*';
			x1 = x1 - 1;
			y1 = y1 + 1;
			break;

		}
		break;
	case 2:
		switch (rotate_c) {
		case 0:
			FillArr(f, 4, 4);
			f[0][0] = '*';
			f[1][0] = '*';
			f[2][0] = '*';
			f[3][0] = '*';
			x1 = x + 3;
			y1 = y;
			break;
		case 1:
			FillArr(f, 4, 4);
			f[0][0] = '*';
			f[0][1] = '*';
			f[0][2] = '*';
			f[0][3] = '*';
			x1 = x;
			y1 = y + 3;
			break;
		}
		break;
	case 3:
		switch (rotate_c) {
		case 1:
			FillArr(f, 4, 4);
			f[2][1] = '*';
			f[2][0] = '*';
			f[1][0] = '*';
			f[0][0] = '*';
			x1 = x1 + 1;
			y1 = y1 - 1;
			break;
		case 2:
			FillArr(f, 4, 4);
			f[0][0] = '*';
			f[0][1] = '*';
			f[0][2] = '*';
			f[1][0] = '*';
			x1 = x1 - 1;
			y1 = y1 + 1;
			break;
		case 3:
			FillArr(f, 4, 4);
			f[0][0] = '*';
			f[0][1] = '*';
			f[1][1] = '*';
			f[2][1] = '*';
			x1 = x1 + 1;
			y1 = y1 - 1;
			break;
		case 4:
			FillArr(f, 4, 4);
			f[0][0] = '*';
			f[1][0] = '*';
			f[1][1] = '*';
			f[1][2] = '*';
			x1 = x1 - 1;
			y1 = y1 + 1;
			break;

		}
		break;
	case 4:
		switch (rotate_c) {
		case 0:
			FillArr(f, 4, 4);
			f[0][1] = '*';
			f[0][2] = '*';
			f[1][0] = '*';
			f[1][1] = '*';
			x1 = x1 - 1;
			y1 = y1 + 1;
			break;
		case 1:
			FillArr(f, 4, 4);
			f[0][0] = '*';
			f[1][0] = '*';
			f[1][1] = '*';
			f[2][1] = '*';
			x1 = x1 + 1;
			y1 = y1 - 1;
			break;


		}
		break;
	case 5:
		break;
	}

}
bool CheckDown(char** arr, int x, int y, int x1, int y1, int type, int rotate_c) {
	switch (type) {
	case 1:
		switch (rotate_c) {
		case 0:
			if (arr[x1 + 1][y1] == '*')
				return false;
			if (arr[x1 + 1][y1 - 1] == '*')
				return false;
			if (arr[x1 + 1][y] == '*')
				return false;
			break;
		case 1:
			if (arr[x1][y1] == '*')
				return false;
			if (arr[x1 + 1][y] == '*')
				return false;
			break;
		case 2:
			if (arr[x1][y1] == '*')
				return false;
			if (arr[x1 + 1][y1 - 1] == '*')
				return false;
			if (arr[x1][y] == '*')
				return false;
			break;
		case 3:
			if (arr[x1 + 1][y1] == '*')
				return false;
			if (arr[x1][y] == '*')
				return false;
			break;
		}
		break;
	case 2:
		switch (rotate_c) {
		case 0:
			if (arr[x1 + 1][y1] == '*')
				return false;
			break;
		case 1:
			if (arr[x1 + 1][y] == '*')
				return false;
			if (arr[x1 + 1][y + 1] == '*')
				return false;
			if (arr[x1 + 1][y + 2] == '*')
				return false;
			if (arr[x1 + 1][y1] == '*')
				return false;
			break;
		}
		break;
	case 3:
		switch (rotate_c) {
		case 0:
			if (arr[x1 + 1][y1] == '*')
				return false;
			if (arr[x1 + 1][y1 - 1] == '*')
				return false;
			if (arr[x1 + 1][y] == '*')
				return false;
			break;
		case 1:
			if (arr[x1 + 1][y1] == '*')
				return false;
			if (arr[x1 + 1][y] == '*')
				return false;
			break;
		case 2:
			if (arr[x1 + 1][y] == '*')
				return false;
			if (arr[x1][y1] == '*')
				return false;
			if (arr[x1][y1 - 1] == '*')
				return false;
			break;
		case 3:
			if (arr[x1 + 1][y1] == '*')
				return false;
			if (arr[x + 1][y] == '*')
				return false;
			break;
		}
		break;
	case 4:
		switch (rotate_c) {
		case 0:
			if (arr[x1][y1] == '*')
				return false;
			if (arr[x1 + 1][y1 - 1] == '*')
				return false;
			if (arr[x1 + 1][y] == '*')
				return false;
			break;
		case 1:
			if (arr[x1 + 1][y1] == '*')
				return false;
			if (arr[x1][y] == '*')
				return false;
		}
		break;
	case 5:
		if (arr[x1 + 1][y1] == '*')
			return false;
		if (arr[x1 + 1][y] == '*')
			return false;
		break;
	}
	return true;
}
int row = 15;
int col = 12;
void game() {
	system("cls");
	srand(time(NULL));
	int SLEEP = 500;


	char** figure = CreateArr(4, 4);

	char** arr = CreateArr(row, col);
	FillArr(arr, row, col);
	PrintArr(arr, row, col, score);
start:
	int x, y, x1, y1, type;
	RandFigure(arr, row, col, x, y, x1, y1, type);

	FillArr(figure, 4, 4);
	SaveFigure(figure, type);
	int rotate_c = 0;
	while (x1 != row - 1 && CheckDown(arr, x, y, x1, y1, type, rotate_c)) {

		if (_kbhit()) {
			int Key = _getch();
			if (Key == ArrowRight && arr[x][y1 + 1] != '*' && arr[x1][y1 + 1] != '*' && (y1 + 1 < col)) {
				for (int i = x; i <= x1; i++)
					for (int j = y; j <= y1; j++)
						arr[i][j] = ' ';
				x = x;
				y = y + 1;
				x1 = x1;
				y1 = y1 + 1;
				PrintFigure(arr, figure, x, y, x1, y1);
				SLEEP = 10;
				PrintArr(arr, row, col, score);
				

			}
			if (Key == ArrowLeft && arr[x][y - 1] != '*' && arr[x1][y - 1] != '*' && (y - 1 >= 0)) {
				for (int i = x; i <= x1; i++)
					for (int j = y; j <= y1; j++)
						arr[i][j] = ' ';

				x = x;
				y = y - 1;
				x1 = x1;
				y1 = y1 - 1;
				PrintFigure(arr, figure, x, y, x1, y1);
				system("cls");
				PrintArr(arr, row, col, score);
			}
			if (Key == ArrowDown) {
				SLEEP = 100;
			}
			if (Key == ArrowUp) {
				for (int i = x; i <= x1; i++)
					for (int j = y; j <= y1; j++)
						arr[i][j] = ' ';
				rotate_c++;
				if ((type == 4 || type == 2) && rotate_c == 3)
					rotate_c = 0;
				else if (rotate_c == 5) {
					rotate_c = 0;
				}
				Rotate(figure, x, y, x1, y1, type, rotate_c);
				PrintFigure(arr, figure, x, y, x1, y1);
				system("cls");
				PrintArr(arr, row, col, score);
			}
			if (Key == KeyP) {
				system("pause");
			}
		}
		else {
			Sleep(SLEEP);
			for (int i = x, k = 0; i <= x1; i++, k++)
				for (int j = y, m = 0; j <= y1; j++, m++)
					if (figure[k][m] == '*')
						arr[i][j] = ' ';

			x = x + 1;
			y = y;
			x1 = x1 + 1;
			y1 = y1;

			PrintFigure(arr, figure, x, y, x1, y1);
			system("cls");
			PrintArr(arr, row, col, score);

			SLEEP = 1000;

		}
		/*cout << "( " << x << " ; " << y << " )" << endl;
		cout << "( " << x1 << " ; " << y1 << " )" << endl;*/
	}
	if (arr[1][5] == '*')
		gameOver();
	else {

		for (int i = 0; i < row; i++) {
			bool check = false;
			for (int f = 0; f < col; f++)
				if (arr[i][f] == ' ')
					check = true;


			if (check == false) {
				for (int j = i - 1; j > 0; j--)
					for (int m = 0; m < col; m++)
						arr[j + 1][m] = arr[j][m];
				score += 1000;
			}
		}

		goto start;
	}


}
int AlignCenter(int ind) {
	switch (ind) {
	case 0:
		return 12;
	case 1:
		return 13;
	case 2:
		return 12;
	}
}
int AlignCenterChoice(int ind) {
	switch (ind) {
	case 0:
		return 8;
	case 1:
		return 6;
	case 2:
		return 8;
	}
}
int default_color = 7;
int OutPut(int ind) {
	switch (ind) {
	case 0:
		return default_color;
	case 1:
		return row;
	case 2:
		return col;
	}
}
void menu();
void Options() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	char Menu[3][15] = { { "Change color" },{ "Change height" },{ "Change width" } };
	SetConsoleTextAttribute(console, default_color);
	int ind = 0;
	cout << "#==============================================================================#\n";

	cout << "####### ####### ####### ######    ###    #####\n";
	cout << "   #    #          #    #     #    #    #     #\n";
	cout << "   #    #          #    #     #    #    #\n";
	cout << "   #    #####      #    ######     #     #####\n";
	cout << "   #    #          #    #   #      #          #\n";
	cout << "   #    #          #    #    #     #    #     #\n";
	cout << "   #    #######    #    #     #   ###    #####\n";
	cout << "\n\n\n\n";
	cout << "(Use: Num8 or Num2) so as increase or reduce metrics" << endl;
	cout << "#==============================================================================#\n";
	for (int i = 0; i < ind; i++)
		cout << setw(30) << Menu[i] << "( " << OutPut(i) << " )" << endl;

	SetConsoleTextAttribute(console, default_color - 5);
	cout << setw(18) << ">> " << Menu[ind] << "( " << OutPut(ind) << " )" << " << " << endl;
	SetConsoleTextAttribute(console, default_color);

	for (int i = ind + 1; i < 3; i++)
		cout << setw(30) << Menu[i] << "( " << OutPut(i) << " )" << endl;
begin:
	while (true) {
		if (_kbhit) {
			int Key = _getch();
			switch (Key) {
			case ArrowDown:
				system("cls");
				if (ind == 2)
					ind = 0;
				else
					ind++;
				goto Print;
				break;
			case ArrowUp:
				system("cls");
				if (ind == 0)
					ind = 2;
				else
					ind--;
				goto Print;
				break;
			case Num8:
				switch (ind) {
				case 0:
					if (default_color == 240)
						default_color = 0;
					else
						default_color++;
					break;
				case 1:
					if (row == 22)
						row = 12;
					else
						row++;
					break;
				case 2:
					if (col == 38)
						col = 10;
					else
						col++;
					break;
				}
				system("cls");
				goto Print;
				break;
			case Num2:
				switch (ind) {
				case 0:
					if (default_color == 0)
						default_color = 240;
					else
						default_color--;
					break;
				case 1:
					if (row == 12)
						row = 22;
					else
						row--;
					break;
				case 2:
					if (col == 10)
						col = 38;
					else
						col--;
					break;
				}
				system("cls");
				goto Print;
				break;
			case ArrowLeft:
				system("cls");
				menu();
				break;
			}
		}
	}
Print:
	cout << "#==============================================================================#\n";

	cout << "####### ####### ####### ######    ###    #####\n";
	cout << "   #    #          #    #     #    #    #     #\n";
	cout << "   #    #          #    #     #    #    #\n";
	cout << "   #    #####      #    ######     #     #####\n";
	cout << "   #    #          #    #   #      #          #\n";
	cout << "   #    #          #    #    #     #    #     #\n";
	cout << "   #    #######    #    #     #   ###    #####\n";
	cout << "\n\n\n\n";
	cout << "(Use: Num8 or Num2) so as increase or reduce metrics" << endl;
	cout << "#==============================================================================#\n";
	for (int i = 0; i < ind; i++)
		cout << setw(30) << Menu[i] << "( " << OutPut(i) << " )" << endl;

	SetConsoleTextAttribute(console, default_color - 5);
	cout << setw(18) << ">> " << Menu[ind] << "( " << OutPut(ind) << " )" << " << " << endl;
	SetConsoleTextAttribute(console, default_color);

	for (int i = ind + 1; i < 3; i++)
		cout << setw(30) << Menu[i] << "( " << OutPut(i) << " )" << endl;
	goto begin;



}
void menu() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	char Menu[3][15] = { { "Play" },{ "Options" },{ "Exit" } };
	SetConsoleTextAttribute(console, default_color);
	int ind = 0;
	cout << "#==============================================================================#\n";

	cout << "####### ####### ####### ######    ###    #####\n";
	cout << "   #    #          #    #     #    #    #     #\n";
	cout << "   #    #          #    #     #    #    #\n";
	cout << "   #    #####      #    ######     #     #####\n";
	cout << "   #    #          #    #   #      #          #\n";
	cout << "   #    #          #    #    #     #    #     #\n";
	cout << "   #    #######    #    #     #   ###    #####\n";
	cout << "\n\n\n\n";
	cout << "#==============================================================================#\n";
	for (int i = 0; i < ind; i++)
		cout << setw(AlignCenter(i)) << Menu[i] << endl;

	SetConsoleTextAttribute(console, default_color - 5);
	cout << setw(8) << ">> " << Menu[ind] << " << " << endl;
	SetConsoleTextAttribute(console, default_color);

	for (int i = ind + 1; i < 3; i++)
		cout << setw(AlignCenter(i)) << Menu[i] << endl;

begin:
	while (true) {
		if (_kbhit) {
			int Key = _getch();
			switch (Key) {
			case ArrowDown:
				system("cls");
				if (ind == 2)
					ind = 0;
				else
					ind++;
				goto Print;
				break;
			case ArrowUp:
				system("cls");
				if (ind == 0)
					ind = 2;
				else
					ind--;
				goto Print;
				break;
			case ArrowRight:
				switch (ind) {
				case 0:
					game();
					break;
				case 1:
					Options();
					break;
				case 2:
					exit(0);
					break;
				}

				break;
			}
		}
	}
Print:
	cout << "#==============================================================================#\n";

	cout << "####### ####### ####### ######    ###    #####\n";
	cout << "   #    #          #    #     #    #    #     #\n";
	cout << "   #    #          #    #     #    #    #\n";
	cout << "   #    #####      #    ######     #     #####\n";
	cout << "   #    #          #    #   #      #          #\n";
	cout << "   #    #          #    #    #     #    #     #\n";
	cout << "   #    #######    #    #     #   ###    #####\n";
	cout << "\n\n\n\n";
	cout << "#==============================================================================#\n";
	for (int i = 0; i < ind; i++)
		cout << setw(AlignCenter(i)) << Menu[i] << endl;

	SetConsoleTextAttribute(console, 2);
	cout << setw(AlignCenterChoice(ind)) << ">> " << Menu[ind] << " << " << endl;
	SetConsoleTextAttribute(console, default_color);

	for (int i = ind + 1; i < 3; i++)
		cout << setw(AlignCenter(i)) << Menu[i] << endl;
	goto begin;
}

void main() {
	menu();
	//game();


	system("pause");
}