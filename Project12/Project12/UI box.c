#include <stdio.h>
#include <Windows.h>

int main()
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD cursorPosition;

	cursorPosition.X = 8;
	cursorPosition.Y = 2;

	SetConsoleCursorPosition(handle, cursorPosition);

	for (int i = 0; i < 102; i++)
	{
		printf("-");
	}

	cursorPosition.X = 8;
	cursorPosition.Y = 3;

	SetConsoleCursorPosition(handle, cursorPosition);

	for (int i = 0; i < 10; i++)
	{
		printf("|\n");
		cursorPosition.Y++;
		SetConsoleCursorPosition(handle, cursorPosition);
	}

	cursorPosition.X = 109;
	cursorPosition.Y = 3;

	SetConsoleCursorPosition(handle, cursorPosition);

	for (int i = 0; i < 10; i++)
	{
		printf("|\n");
		cursorPosition.Y++;
		SetConsoleCursorPosition(handle, cursorPosition);
	}

	cursorPosition.X = 8;
	cursorPosition.Y = 13;

	SetConsoleCursorPosition(handle, cursorPosition);

	for (int i = 0; i < 102; i++)
	{
		printf("-");
	}

	return 0;
}