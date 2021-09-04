#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <io.h>

struct BusData {
	int busNumber;
	char startingPoint[100];
	char terminal[100];
};

struct BusData* MemoryAlloc(int psize);
int Menu(int menu);
void addBus(struct BusData* bus, int count);
void print(struct BusData* bus, int count);
void changeBus(struct BusData* bus, int count);
void deleteBus(struct BusData* bus, int count);
void insertBus(struct BusData* bus, int count);
void save(struct BusData* bus, int count, int loadcount);
void saveToExistingFile1(struct BusData* bus, int count, int savepoint, char filename[1000]);
void saveToExistingFile2(struct BusData* bus, int count, char filename[1000]);
void saveToNewFile(struct BusData* bus, int count, char filename[1000]);
int load(struct BustData* bus, int count);
struct BusData* increaseMemory(struct BusData* bus, int filesize);
struct BusData* decreaseMemory(struct BusData* bus, int filesize);

int main()
{
	int menu = 0;
	int count = 0;
	struct BusData* bus;
	int filesize = 5;
	int loadcount = 0;
	bus = MemoryAlloc(filesize);

	while (1)
	{
		menu = Menu(menu);
		
		switch (menu)
		{
		case 1:
			addBus(bus, count);
			count++;
			if (filesize == count)
			{
				filesize++;
				bus = increaseMemory(bus, filesize);
			}
			break;
		case 2:
			changeBus(bus, count);
			break;
		case 3:
			deleteBus(bus, count);
			count--;
			if (filesize > count || filesize > 5)
			{
				filesize--;
				bus = decreaseMemory(bus, filesize);
			}
			break;
		case 4:
			insertBus(bus, count);
			count++;
			break;
		case 5:
			print(bus, count);
			break;
		case 6:
			save(bus, count, loadcount);
			break;
		case 7:
			count = load(bus, count);
			loadcount = 1;
			break;
		case 8:
			exit(0);
		}
	}
	return 0;
}

struct BusData* MemoryAlloc(int psize)
{
	struct BusData* temp;

	temp = malloc(sizeof(struct BusData) * psize);
	memset(temp, 0, sizeof(struct BusData) * psize);

	return temp;
}

int Menu(int menu)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 28;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 22; i++)
	{
		printf("-");
	}
	printf("�� BUS INFORMATION ��");
	for (int i = 0; i < 22; i++)
	{
		printf("-");
	}

	point.X = 30;
	point.Y = 6;
	SetConsoleCursorPosition(handle, point);
	printf("1.�Է�");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("2.����");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("3.����");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("4.����");
	point.X = 83;
	point.Y = 6;
	SetConsoleCursorPosition(handle, point);
	printf("5.���");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("6.����");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("7.�ε�");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("8.����");


	point.X = 28;
	point.Y = 14;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 65; i++)
	{
		printf("-");
	}

	point.X = 90;
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("�޴��� �Է��ϼ���: ");
	scanf("%d", &menu);
	getchar();
	system("cls");

	return menu;
}

void addBus(struct BusData* bus, int count)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	if (count != 0)
	{
		point.X = 10;
		point.Y = 4;
		SetConsoleCursorPosition(handle, point);
		for (int i = 0; i < count; i++)
		{
			printf("%d | %d\t ���: %s\t����: %s", i, bus[i].busNumber, bus[i].startingPoint, bus[i].terminal);
			point.Y++;
			SetConsoleCursorPosition(handle, point);
		}
	}

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	printf("��");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");


	point.X = 10;
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &bus[count].busNumber);
	getchar();
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ��� ������ �Է����ּ���: ");
	gets(bus[count].startingPoint);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ���� ������ �Է����ּ���: ");
	gets(bus[count].terminal);

	point.Y += 3;
	SetConsoleCursorPosition(handle, point);
	printf("���� ������ �ԷµǾ����ϴ�.");
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("�Է��Ͻ� ������ ������� �޴��� ���ư� 6���� �����ּ���.");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("����Ű�� ������ �޴��� ���ư��ϴ�...");
	getchar();
	system("cls");
}

void print(struct BusData* bus, int count)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	printf("��");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");

	point.X = 10;
	point.Y = 4;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < count; i++)
	{
		printf("%d | %d\t ���: %s\t����: %s", i, bus[i].busNumber, bus[i].startingPoint, bus[i].terminal);
		point.Y++;
		SetConsoleCursorPosition(handle, point);
	}

	point.Y = 20;
	SetConsoleCursorPosition(handle, point);
	printf("����Ű�� ������ �޴��� ���ư��ϴ�...");
	getchar();
	system("cls");
}

void changeBus(struct BusData* bus, int count)
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	printf("��");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");

	point.X = 10;
	point.Y = 4;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < count; i++)
	{
		printf("%d | %d\t ���: %s\t����: %s", i, bus[i].busNumber, bus[i].startingPoint, bus[i].terminal);
		point.Y++;
		SetConsoleCursorPosition(handle, point);
	}

	point.Y = 20;
	SetConsoleCursorPosition(handle, point);
	printf("������ ������ ��ȣ�� �Է��ϼ���(| �տ��ִ� ��ȣ�� �Է��ϼ���) : ");
	scanf("%d", &count);

	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &bus[count].busNumber);
	getchar();
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ��� ������ �Է����ּ���: ");
	gets(bus[count].startingPoint);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ���� ������ �Է����ּ���:");
	gets(bus[count].terminal);

	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("������ �Ϸ�Ǿ����ϴ�.");
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ������ �����Ϸ��� �޴��� ���ư� 6���� �����ּ���.");
	point.Y += 3;
	SetConsoleCursorPosition(handle, point);
	printf("����Ű�� ������ �޴��� ���ư��ϴ�...");
	getchar();
	system("cls");
}

void deleteBus(struct BusData* bus, int count)
{
	int num = 0;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	printf("��");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");

	point.X = 10;
	point.Y = 4;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < count; i++)
	{
		printf("%d | %d\t ���: %s\t����: %s", i, bus[i].busNumber, bus[i].startingPoint, bus[i].terminal);
		point.Y++;
		SetConsoleCursorPosition(handle, point);
	}

	point.Y = 20;
	SetConsoleCursorPosition(handle, point);
	printf("������ ������ ��ȣ�� �Է��ϼ���(| �տ��ִ� ��ȣ�� �Է��ϼ���) : ");
	scanf("%d", &num);
	getchar();

	for (int i = num; i < count; i++)
	{
		bus[i].busNumber = bus[i + 1].busNumber;
		strcpy(bus[i].startingPoint, bus[i + 1].startingPoint);
		strcpy(bus[i].terminal, bus[i + 1].terminal);
	}
	
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("������ �Ϸ�Ǿ����ϴ�.");
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ������ �����Ϸ��� �޴��� ���ư� 6���� �����ּ���.");
	point.Y += 3;
	SetConsoleCursorPosition(handle, point);
	printf("����Ű�� ������ �޴��� ���ư��ϴ�...");
	getchar();
	system("cls");
}

void insertBus(struct BusData* bus, int count)
{
	int num = 0;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	printf("��");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");
	for (int i = 0; i < 102; i++)
	{
		printf("��");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("��");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("��");

	point.X = 10;
	point.Y = 4;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < count; i++)
	{
		printf("%d | %d\t ���: %s\t����: %s", i, bus[i].busNumber, bus[i].startingPoint, bus[i].terminal);
		point.Y++;
		SetConsoleCursorPosition(handle, point);
	}

	point.Y = 20;
	SetConsoleCursorPosition(handle, point);
	printf("������ ������ ��ȣ�� �Է��ϼ���(| �տ��ִ� ��ȣ�� �Է��ϼ���) : ");
	scanf("%d", &num);
	for (int i = count; i > num; i--)
	{
		bus[i + 1].busNumber = bus[i].busNumber;
		strcpy(bus[i + 1].startingPoint, bus[i].startingPoint);
		strcpy(bus[i + 1].terminal, bus[i].terminal);
	}



	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &bus[num + 1].busNumber);
	getchar();
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ��� ������ �Է����ּ���: ");
	gets(bus[num + 1].startingPoint);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ���� ������ �Է����ּ���: ");
	gets(bus[num + 1].terminal);


	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("������ �Ϸ�Ǿ����ϴ�.");
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("������ ������ �����Ϸ��� �޴��� ���ư� 6���� �����ּ���.");
	point.Y += 3;
	SetConsoleCursorPosition(handle, point);
	printf("����Ű�� ������ �޴��� ���ư��ϴ�...");
	getchar();
	system("cls");
}

void save(struct BusData *bus, int count, int loadcount)
{
	char filename[1000] = { 0 };
	char filetype[50] = { 0 };
	int savepoint = 0;
	char n[30] = { 0 };
	char answer = 0;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("���ϸ��� �Է��ϼ��� : ");
	gets(filename);
	strcpy(filetype, ".bin");
	strcat(filename, filetype);

	FILE* BUS;

	if ((BUS = fopen(&filename, "r+b")) != NULL)
	{
		fseek(BUS, -2, SEEK_END);
		fread(n, 1, 1, BUS);
		savepoint = atoi(n);
		if (loadcount == 0)
		{
			saveToExistingFile1(bus, count, savepoint, filename);
			point.Y++;
			SetConsoleCursorPosition(handle, point);
			printf("%s���Ͽ� ������ �Ϸ�Ǿ����ϴ�.", filename);
			point.Y += 3;
			SetConsoleCursorPosition(handle, point);
			printf("����Ű�� ������ �޴��� ���ư��ϴ�.");
			getchar();
			system("cls");
		}
		else if(loadcount == 1)
		{
			saveToExistingFile2(bus, count, filename);
			point.Y++;
			SetConsoleCursorPosition(handle, point);
			printf("%s���Ͽ� ������ �Ϸ�Ǿ����ϴ�.", filename);
			point.Y += 3;
			SetConsoleCursorPosition(handle, point);
			printf("����Ű�� ������ �޴��� ���ư��ϴ�.");
			getchar();
			system("cls");
		}
	}
	else if ((BUS = fopen(&filename, "r+b")) == NULL)
	{
		point.Y += 2;
		SetConsoleCursorPosition(handle, point);
		printf("������ �������� �ʽ��ϴ�.");
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("������ �����Ͻðڽ��ϱ�? (Y/N)");
		scanf("%c", &answer);
		getchar();
		
		switch (answer)
		{
		case 'y':
			saveToNewFile(bus, count, filename);
			point.Y += 2;
			SetConsoleCursorPosition(handle, point);
			printf("%s������ �����ϰ� �����߽��ϴ�.", filename);
			point.Y += 2;
			SetConsoleCursorPosition(handle, point);
			printf("����Ű�� ������ �޴��� ���ư��ϴ�...");
			getchar();
			system("cls");
			break;
		case 'n':
			point.Y += 2;
			SetConsoleCursorPosition(handle, point);
			printf("����Ű�� ������ �޴��� ���ư��ϴ�...");
			getchar();
			system("cls");
			break;
		}
	}
}

//�ε带 ���� �ʾ��� ��
void saveToExistingFile1(struct BusData* bus, int count, int savepoint, char filename[1000])
{
	char name[1000];
	strcpy(name, filename);
	FILE* BUS = fopen(&name, "a+b");

	for (int i = 0; i < count; i++)
	{
		savepoint++;
		fprintf(BUS, "%d", bus[i].busNumber);
		fprintf(BUS, "\t");
		fwrite(bus[i].startingPoint, strlen(bus[i].startingPoint), 1, BUS);
		fprintf(BUS, "\t");
		fwrite(bus[i].terminal, strlen(bus[i].terminal), 1, BUS);
		fprintf(BUS, "\t");
		fprintf(BUS, "%d", savepoint);
		fprintf(BUS, "\n");
	}
}

//�ε带 ���� ��
void saveToExistingFile2(struct BusData* bus, int count, char filename[1000])
{
	char name[1000];
	strcpy(name, filename);
	FILE* BUS = fopen(&name, "w+b");

	for (int i = 0; i < count; i++)
	{
		fprintf(BUS, "%d", bus[i].busNumber);
		fprintf(BUS, "\t");
		fwrite(bus[i].startingPoint, strlen(bus[i].startingPoint), 1, BUS);
		fprintf(BUS, "\t");
		fwrite(bus[i].terminal, strlen(bus[i].terminal), 1, BUS);
		fprintf(BUS, "\t");
		fprintf(BUS, "%d", i + 1);
		fprintf(BUS, "\n");
	}
}

void saveToNewFile(struct BusData* bus, int count, char filename[1000])
{
	char name[1000];
	strcpy(name, filename);
	FILE* BUS = fopen(&name, "w+b");

	for (int i = 0; i < count; i++)
	{
		fprintf(BUS, "%d", bus[i].busNumber);
		fprintf(BUS, "\t");
		fwrite(bus[i].startingPoint, strlen(bus[i].startingPoint), 1, BUS);
		fprintf(BUS, "\t");
		fwrite(bus[i].terminal, strlen(bus[i].terminal), 1, BUS);
		fprintf(BUS, "\t");
		fprintf(BUS, "%d", i + 1);
		fprintf(BUS, "\n");
	}
}

int load(struct BusData* bus, int count)
{
	char filename[1000] = { 0 };
	char filetype[50] = { 0 };
	char buff[2000] = { 0 };
	int i, j;
	int size;
	char temp;
	char n[30] = { 0 };
	int tempNum = 0;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("���ϸ��� �Է��ϼ��� : ");
	gets(filename);
	strcpy(filetype, ".bin");
	strcat(filename, filetype);

	FILE* BUS;

	if ((BUS = fopen(&filename, "r+b")) == NULL)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("%s������ �������� �ʽ��ϴ�.", filename);
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("����Ű�� ������ �޴��� ���ư��ϴ�...");
		getchar();
		system("cls");
		return 0;
	}
	else
	{
		BUS = fopen(&filename, "a+b");

		fseek(BUS, -2, SEEK_END);
		fread(n, 1, 1, BUS);
		tempNum = atoi(n);

		for (int k = 0; k < count; k++)
		{
			bus[tempNum + k].busNumber = bus[k].busNumber;
			strcpy(bus[tempNum + k].startingPoint, bus[k].startingPoint);
			strcpy(bus[tempNum + k].terminal, bus[k].terminal);
		}
		tempNum += count;

		fseek(BUS, 0, SEEK_SET);
		for (int s = 0; s < tempNum; s++)
		{
			memset(buff, 0, 2000);
			i = 0;
			j = 0;
			while (1)
			{
				while (1)
				{
					size = fread(&temp, 1, 1, BUS);
					if (size == 0)
						break;
					if (temp == '\t' || temp == '\n')
						break;
					buff[i++] = temp;
				}
				if (size == 0)
					break;
				if (j == 0)
				{
					bus[s].busNumber = atoi(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 1)
				{
					strcpy(bus[s].startingPoint, buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 2)
				{
					strcpy(bus[s].terminal, buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j > 2)
				{
					memset(buff, 0, 2000);
					j = 0;
					i = 0;
					break;
				}
			}
		}
	}
		point.X = 8;
		point.Y = 3;
		SetConsoleCursorPosition(handle, point);
		printf("%s�����бⰡ �Ϸ�Ǿ����ϴ�.", filename);
		point.Y += 2;
		SetConsoleCursorPosition(handle, point);
		printf("����Ű�� ������ �޴��� ���ư��ϴ�...");
		getchar();
		system("cls");

		return tempNum;
}

struct BusData* increaseMemory(struct BusData* bus, int filesize)
{
	struct BusData* temp;

	temp = malloc(sizeof(struct BusData) * filesize);
	memset(temp, 0, sizeof(struct BusData) * filesize);

	for (int i = 0; i < filesize; i++)
	{
		temp[i].busNumber = bus[i].busNumber;
		strcpy(temp[i].startingPoint, bus[i].startingPoint);
		strcpy(temp[i].terminal, bus[i].terminal);
	}

	return temp;
}

struct BusData* decreaseMemory(struct BusData* bus, int filesize)
{
	struct BusData* temp;

	temp = malloc(sizeof(struct BusData) * filesize);
	memset(temp, 0, sizeof(struct BusData) * filesize);

	for (int i = 0; i < filesize; i++)
	{
		temp[i].busNumber = bus[i].busNumber;
		strcpy(temp[i].startingPoint, bus[i].startingPoint);
		strcpy(temp[i].terminal, bus[i].terminal);
	}

	return temp;
}

// increaseMemory ������ ��� �޴��� ���ư� 1.�Է��� ������ �� �����߻�.
// load�� ����� �޸𸮰� 10���� �Ѿ ��� �����ڸ� ���ڸ� ����.
// decreaseMemory�� �����غ��� ����.

//�޸𸮴� \n������ �Ǵ� �õ�