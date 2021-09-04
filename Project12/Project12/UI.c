#include <Windows.h>
#include <stdio.h>

int main()
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD CursorPosition;	//ÁÂÇ¥ ÁöÁ¤

	CursorPosition.X = 30;
	CursorPosition.Y = 7;

	SetConsoleCursorPosition(handle, CursorPosition);

	printf("ui test");


	CursorPosition.X = 0;
	CursorPosition.Y = 0;

	SetConsoleCursorPosition(handle, CursorPosition);
	printf("program test");

	return 0;
}