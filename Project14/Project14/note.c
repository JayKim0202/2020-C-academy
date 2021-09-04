#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <io.h>
#include <Windows.h>

typedef struct cursor_position
{
	int X;
	int Y;
}Cursor;

typedef struct node
{
	char contents[10][128];
	int page;
	Cursor cursor;
	struct node* next;
	struct node* prev;
}Node;

Node* memory_alloc();
int MENU();
Node* new_file(Node* tail);
void save(Node* head);
Node* prev_page_switching(Node* tail);
Node* next_page_switching(Node* tail);

int main()
{
	Node* head;
	Node* tail;

	head = memory_alloc();
	tail = memory_alloc();

	head = tail;
	
	int menu;

	while (1)
	{
		menu = MENU();

		switch (menu)
		{
		case 1:
			tail = new_file(tail);
			break;
		case 2:
			save(head);
			break;
		case 3:
			exit(0);
		}
	}
}

Node* memory_alloc()
{
	Node* temp;
	temp = malloc(sizeof(Node));

	memset(temp->contents, NULL, sizeof(temp->contents));
	temp->page = 0;
	temp->cursor.X = 0;
	temp->cursor.Y = 0;
	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

int MENU()
{
	int num;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	coord.X = 8;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	for (int i = 0; i < 45; i++)
		printf("��");
	printf(" <  NOTES  >");
	for (int i = 0; i < 45; i++)
		printf("��");
	printf("��");
	for (int i = 0; i < 7; i++)
	{
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("��");
	}
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("��");
	for (int i = 0; i < 102; i++)
		printf("��");
	printf("��");
	coord.X = 111;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < 7; i++)
	{
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("��");
	}

	coord.X = 15;
	coord.Y = 7;
	SetConsoleCursorPosition(handle, coord);
	printf("1. ������");
	coord.X += 40;
	SetConsoleCursorPosition(handle, coord);
	printf("2. ����");
	coord.X += 40;
	SetConsoleCursorPosition(handle, coord);
	printf("3. ����");

	coord.Y += 8;
	SetConsoleCursorPosition(handle, coord);
	printf("�޴� : ");
	scanf("%d", &num);

	system("cls");
	return num;
}

Node* new_file(Node* tail)
{
	Node* new_node;
	Node* fixed_node;
	fixed_node = tail;
	int i;
	int j;
	int l = 0;
	int switching;
	int end = 0;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	while (1)
	{
		new_node = memory_alloc();
		switching = 0;
		i = 0;
		j = 0;
		while (1)
		{
			if (l == 0)
			{
				coord.X = 60;
				coord.Y = 27;
				SetConsoleCursorPosition(handle, coord);
				printf("- %d -", tail->page + 1);
			}
			
			if (l == 0)
				coord.Y = 1;
			coord.X = 5;
			coord.Y++;
			SetConsoleCursorPosition(handle, coord);
			while (1)
			{
				new_node->contents[j][i++] = getch();
				new_node->contents[j][i] = 0;
				if (new_node->contents[j][i - 1] == 62)
				{
					new_node->contents[j][i - 1] = NULL;
					new_node->contents[j][i - 2] = NULL;
					end = 1;
					break;
				}
				if (new_node->contents[j][i - 1] == '\b')
				{
					for (int l = i - 2; l <= i; l++)
						new_node->contents[j][l] = NULL;
					i -= 2;
					new_node->contents[j][i] = 0;
					printf("\b \b");
				}
				else
				{
					printf("%c", new_node->contents[j][i - 1]);
				}
				if (new_node->contents[j][i - 1] == '\r') break;
				//����Ű �� �ܿ� �¿��  ������ ��ȯ
				// -> 77 224
				// <- 75 224
				if (new_node->contents[j][i - 1] == 75)
				{
					printf("\b \n�� �������� �̵��մϴ�.\n");
					if (new_node->contents != NULL)
					{
						new_node->contents[j][i - 1] = NULL;
						new_node->contents[j][i - 2] = NULL;
						i -= 2;

						new_node->cursor.X = i;
						new_node->cursor.Y = j;

						tail->next = new_node;
						new_node->prev = tail;
						new_node->page = new_node->prev->page + 1;

						tail = new_node;
					}
					prev_page_switching(tail);
					switching = 1;
					
					tail = tail->prev;
					break;
				}
				else if (new_node->contents[j][i - 1] == 77)
				{
					printf("\b \b���� �������� �̵��մϴ�.");
					if (new_node->contents != NULL)
					{
						new_node->contents[j][i - 1] = NULL;
						new_node->contents[j][i - 2] = NULL;
						i -= 2;

						new_node->cursor.X = i;
						new_node->cursor.Y = j;

						tail->next = new_node;
						new_node->prev = tail;
						new_node->page = new_node->prev->page + 1;

						tail = new_node;
						new_node = new_node->next;
					}
					next_page_switching(tail);

					if(tail ->next != NULL)
						tail = tail->next;
					//else if (tail->contents == NULL)

					switching = 1;
					break;
				}
			}
			l = 1;
			j++;
			i = 0;
			if (j == 10)
			{
				system("cls");
				coord.X = 30;
				coord.Y = 15;
				SetConsoleCursorPosition(handle, coord);
				printf("%d�������� ����ã���ϴ�. ����Ű�� ������ ���� �������� �Ѿ�ϴ�.", tail->page + 1);
				if (getchar() == '\n')
					getchar();
				system("cls");
				l = 0;
				break;
			}
			if (end == 1 || switching == 1)
				break;
		}

		if (switching == 0 && new_node->contents != NULL)
		{
			new_node->cursor.X = i;
			new_node->cursor.Y = j;

			tail->next = new_node;
			new_node->prev = tail;
			new_node->page = new_node->prev->page + 1;

			tail = new_node;
			new_node = new_node->next;
		}

		if (end == 1) break;
	}
	return tail;
}

//F4 = 62 F10 = 68

void save(Node* head)
{
	FILE* notes;

	notes = fopen("notes.bin", "w+b");

	head = head->next;
	while (1)
	{
		fwrite(head->contents, (head->contents), 1, notes);
		fprintf(notes, "\t");
		fprintf(notes, "%d", head->page);
		fprintf(notes, "\t");
		fprintf(notes, "%d", head->cursor.X);
		fprintf(notes, "\t");
		fprintf(notes, "%d", head->cursor.Y);
		fprintf(notes, "\n");

		if (head->next != NULL)
		{
			fprintf(notes, "\n");
			head = head->next;
		}
		else if (head->next == NULL) break;
	}
}

Node* prev_page_switching(Node* tail)
{
	Node* fixed_node;
	fixed_node = tail;
	int i;

	if (tail->page == 1)
	{
		printf("�� �������� �ۼ��� ������ �����ϴ�.");
		return;
	}
	else
	{
		tail = tail->prev;

		for (int j = 0; j < tail->cursor.Y-1; j++)
		{
			i = strlen(tail->contents[j]);
			for (int k = 0; k < i - 1; k++)
			{
				printf("%c", tail->contents[j][k]);
			}
			printf("\n");
			i = 0;
		}

		printf("-%d-", tail->page);
	}
}

Node* next_page_switching(Node* tail)
{
	Node* fixed_node;
	fixed_node = tail;
	int i;
	if (tail->next == NULL)
	{
		printf("���� �������� �ۼ��� ������ �����ϴ�.");
		return;
	}
	else
	{
		tail = tail->next;

		for (int j = 0; j < tail->cursor.Y - 1; j++)
		{
			i = strlen(tail->contents[j]);
			for (int k = 0; k < i - 1; k++)
			{
				printf("%c", tail->contents[j][k]);
			}
			printf("\n");
			i = 0;
		}

		printf("-%d-", tail->page);
	}
}

//�޴� -> ������, ����, ����
//300���� ���� �ִ� -> node1��
//��������ȣ
//Ŀ�� ��ġ->���ϵ���(������ ����)

//������ int�� ���� ����Ű�� ���(2����Ʈ�� ó�� ���� ������ �� �ι�° ���� ��¥ ����)

//���������� 10��
//�� ��� 128

//getchar()���ȭ�鿡 ����
//getch()���ȭ�鿡 �Ⱥ���