#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

void frame();
int print(int num, int player);
void get_loc(int player);
int check_over(int player, char loc);
int cursor_view();
int CtoI(char num);

int main()
{
	cursor_view();

	frame();
	while (1)
	{
		get_loc(1);
		get_loc(2);
	}

	return 0;
}

int cursor_view()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int CtoI(char num) {
	switch (num)
	{
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	}
}

int check_over(int player, char loc)
{
	static int _1p_check[9] = { 0 };
	static int _2p_check[9] = { 0 };
	static int all_check[9] = { 0 };
	int i_loc;

	i_loc = CtoI(loc);

	if ((player == 1 && _2p_check[i_loc - 1] == 1) || (player == 2 && _1p_check[i_loc - 1] == 1) || (player == 1 && _1p_check[i_loc - 1] == 1) || (player == 2 && _2p_check[i_loc - 1] == 1))
		return -1;

	if (player == 1)
		_1p_check[i_loc - 1] = 1;
	else
		_2p_check[i_loc - 1] = 1;

	all_check[i_loc - 1] = 1;

	if ((_1p_check[0] == 1 && _1p_check[1] == 1 && _1p_check[2] == 1) || (_1p_check[3] == 1 && _1p_check[4] == 1 && _1p_check[5] == 1) || (_1p_check[6] == 1 && _1p_check[7] == 1 && _1p_check[8] == 1) || (_1p_check[0] == 1 && _1p_check[4] == 1 && _1p_check[8] == 1) || (_1p_check[2] == 1 && _1p_check[4] == 1 && _1p_check[6] == 1) || (_1p_check[0] == 1 && _1p_check[3] == 1 && _1p_check[6] == 1) || (_1p_check[1] == 1 && _1p_check[4] == 1 && _1p_check[7] == 1) || (_1p_check[2] == 1 && _1p_check[5] == 1 && _1p_check[8] == 1))
	{
		system("cls");
		printf("1p win");
		exit(0);
	}
	else if ((_2p_check[0] == 1 && _2p_check[1] == 1 && _2p_check[2] == 1) || (_2p_check[3] == 1 && _2p_check[4] == 1 && _2p_check[5] == 1) || (_2p_check[6] == 1 && _2p_check[7] == 1 && _2p_check[8] == 1) || (_2p_check[0] == 1 && _2p_check[4] == 1 && _2p_check[8] == 1) || (_2p_check[2] == 1 && _2p_check[4] == 1 && _2p_check[6] == 1) || (_2p_check[0] == 1 && _2p_check[3] == 1 && _2p_check[6] == 1) || (_2p_check[1] == 1 && _2p_check[4] == 1 && _2p_check[7] == 1) || (_2p_check[2] == 1 && _2p_check[5] == 1 && _2p_check[8] == 1))
	{
		system("cls");
		printf("2p win");
		exit(0);
	}

	if (all_check[0] && all_check[1] && all_check[2] && all_check[3] && all_check[4] && all_check[5] && all_check[6] && all_check[7] && all_check[8])
	{
		system("cls");
		printf("draw");
		exit(0);
	}
}

void get_loc(int player)
{
	char loc;
	static int count = 0;
	int again;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	while (1)
	{
		pos.X = 0;
		pos.Y = 8;
		SetConsoleCursorPosition(handle, pos);

		printf("%dp turn", player);
		loc = _getch();
		count++;
		if (count == 1 && loc == '5')
		{
			printf("\n첫 턴에서는 5를 선택할 수 없습니다.");
			Sleep(1000);
			system("cls");
			frame();
			continue;
		}
		else
			break;
	}
	again = print(loc, player);
	if (again == -1)
		get_loc(player);
}

void frame()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	for (int i = 0; i < 2; i++)
	{
		printf("    |    |\n");
		for (int j = 0; j < 14; j++)
			printf("-");
		printf("\n");
	}
	printf("    |    |\n");

	pos.X = 1;
	pos.Y = 0;
	SetConsoleCursorPosition(handle, pos);
	printf("1");

	pos.X = 6;
	SetConsoleCursorPosition(handle, pos);
	printf("2");

	pos.X = 11;
	SetConsoleCursorPosition(handle, pos);
	printf("3");

	pos.X = 1;
	pos.Y = 2;
	SetConsoleCursorPosition(handle, pos);
	printf("4");

	pos.X = 6;
	SetConsoleCursorPosition(handle, pos);
	printf("5");

	pos.X = 11;
	SetConsoleCursorPosition(handle, pos);
	printf("6");

	pos.X = 1;
	pos.Y = 4;
	SetConsoleCursorPosition(handle, pos);
	printf("7");

	pos.X = 6;
	SetConsoleCursorPosition(handle, pos);
	printf("8");

	pos.X = 11;
	SetConsoleCursorPosition(handle, pos);
	printf("9");
}

int print(int num, int player)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	int is_same;

	is_same = check_over(player, num);
	if (is_same == -1)
		return -1;

	if (player == 1)
	{
		switch (num)
		{
		case '1':
			pos.X = 1;
			pos.Y = 0;
			SetConsoleCursorPosition(handle, pos);
			printf("O");
			break;
		case '2':
			pos.X = 6;
			pos.Y = 0;
			SetConsoleCursorPosition(handle, pos);
			printf("O");
			break;
		case '3':
			pos.X = 11;
			pos.Y = 0;
			SetConsoleCursorPosition(handle, pos);
			printf("O");
			break;
		case '4':
			pos.X = 1;
			pos.Y = 2;
			SetConsoleCursorPosition(handle, pos);
			printf("O");
			break;
		case '5':
			pos.X = 6;
			pos.Y = 2;
			SetConsoleCursorPosition(handle, pos);
			printf("O");
			break;
		case '6':
			pos.X = 11;
			pos.Y = 2;
			SetConsoleCursorPosition(handle, pos);
			printf("O");
			break;
		case '7':
			pos.X = 1;
			pos.Y = 4;
			SetConsoleCursorPosition(handle, pos);
			printf("O");
			break;
		case '8':
			pos.X = 6;
			pos.Y = 4;
			SetConsoleCursorPosition(handle, pos);
			printf("O");
			break;
		case '9':
			pos.X = 11;
			pos.Y = 4;
			SetConsoleCursorPosition(handle, pos);
			printf("O");
			break;
		}
	}
	else
	{
		switch (num)
		{
		case '1':
			pos.X = 1;
			pos.Y = 0;
			SetConsoleCursorPosition(handle, pos);
			printf("X");
			break;
		case '2':
			pos.X = 6;
			pos.Y = 0;
			SetConsoleCursorPosition(handle, pos);
			printf("X");
			break;
		case '3':
			pos.X = 11;
			pos.Y = 0;
			SetConsoleCursorPosition(handle, pos);
			printf("X");
			break;
		case '4':
			pos.X = 1;
			pos.Y = 2;
			SetConsoleCursorPosition(handle, pos);
			printf("X");
			break;
		case '5':
			pos.X = 6;
			pos.Y = 2;
			SetConsoleCursorPosition(handle, pos);
			printf("X");
			break;
		case '6':
			pos.X = 11;
			pos.Y = 2;
			SetConsoleCursorPosition(handle, pos);
			printf("X");
			break;
		case '7':
			pos.X = 1;
			pos.Y = 4;
			SetConsoleCursorPosition(handle, pos);
			printf("X");
			break;
		case '8':
			pos.X = 6;
			pos.Y = 4;
			SetConsoleCursorPosition(handle, pos);
			printf("X");
			break;
		case '9':
			pos.X = 11;
			pos.Y = 4;
			SetConsoleCursorPosition(handle, pos);
			printf("X");
			break;
		}
	}
	check_over(player, num);
}