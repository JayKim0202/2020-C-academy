#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <Windows.h>

#define NAME 40


struct STUDENTDATA
{
	char name[NAME];
	int studentNum;
	int number;
	float kor;
	float eng;
	float math;
	float total;
};

//UI
int UI(int menu)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 7; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 7; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	coord.X = 54;
	coord.Y = 4;

	SetConsoleCursorPosition(handle, coord);

	printf("�л�����");

	coord.X = 90;
	coord.Y = 6;

	SetConsoleCursorPosition(handle, coord);

	printf("�ۼ��� : �����");

	coord.X = 90;
	coord.Y = 8;

	SetConsoleCursorPosition(handle, coord);

	printf("���� : 21.01.11");

	coord.X = 56;
	coord.Y = 11;

	SetConsoleCursorPosition(handle, coord);

	printf("*MENU*");

	coord.X = 18;
	coord.Y = 13;
	SetConsoleCursorPosition(handle, coord);
	printf("1.�л��߰�");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("2.����");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("3.��������");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("4.����");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("5.���");

	coord.X = 75;
	coord.Y = 13;
	SetConsoleCursorPosition(handle, coord);
	printf("6.����");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("7.�ε�");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("8.����");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("9.����");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("10.����");

	coord.X = 18;
	coord.Y++;
	coord.Y++;

	SetConsoleCursorPosition(handle, coord);

	printf("�޴��� �����ϼ��� : ");
	scanf("%d", &menu);
	getchar();
	system("cls");

	return menu;
}

// 1 : �л��߰�
void putStudentInfo1(struct STUDENTDATA* sd)
{
	char empty;

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");


	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("�л��� �̸��� �Է��ϼ��� : ");
	gets(sd->name);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("�й��� �Է��ϼ��� : ");
	scanf("%d", &sd->studentNum);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("��ȭ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &sd->number);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%f", &sd->kor);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%f", &sd->eng);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%f", &sd->math);
	scanf("%c", &empty);

	coord.X = 8;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("������ �߰��Ǿ����ϴ�.");

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("�߰��� ������ �����Ϸ��� �޴��� ���ư� 6���� �����ּ���.");

	coord.Y++;
	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("�޴��� ���ư����� ����Ű �������� ...");
	getchar();
	system("cls");
}

// 5 - 1 : ���
void printStudentInfo2(struct STUDENTDATA* sd, int filecount)
{
	printf("�й�: %d\t�̸�: %s\t��ȭ��ȣ: 0%d\t����: %.2f\t����: %.2f\t����: %.2f\n", sd->studentNum, sd->name, sd->number, sd->kor, sd->eng, sd->math);
}

// 5 : ���
void printStudentInfo1(struct STUDENTDATA* sd, int filecount)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("�й�: %d\t�̸�: %s\t��ȭ��ȣ: 0%d\t����: %.2f\t����: %.2f\t����: %.2f\n", sd[i].studentNum, sd[i].name, sd[i].number, sd[i].kor, sd[i].eng, sd[i].math);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("�޴��� ���ư����� ����Ű �������� ...");
	getchar();
	system("cls");
}

// 4 - 1 : ����
void plusStudentNum(struct STUDENTDATA* sd)
{
	sd->studentNum += 1;
}

// 2 - 1 : ����
void minusStudentNum(struct STUDENTDATA* sd)
{
	sd->studentNum -= 1;
}

// 3 - 1 : ����
void putStudentInfo2(struct STUDENTDATA* sd)
{
	char empty;

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");


	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("�л��� �̸��� �Է��ϼ��� : ");
	gets(sd->name);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("�й��� �Է��ϼ��� : ");
	scanf("%d", &sd->studentNum);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("��ȭ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &sd->number);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%f", &sd->kor);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%f", &sd->eng);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%f", &sd->math);
	scanf("%c", &empty);

	coord.X = 8;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("������ �����Ǿ����ϴ�.");

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("������ ������ �����Ϸ��� �޴��� ���ư� 6���� �����ּ���.");

	coord.Y++;
	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("�޴��� ���ư����� ����Ű �������� ...");
	getchar();
	system("cls");
}

// 3 : ����
void changeStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 4;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 109; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 4;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 109; i++)
	{
		printf("��");
	}

	coord.X = 114;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	coord.X = 6;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < filecount; i++)
	{
		printf("%d|  ", i);
		printStudentInfo2(&sd[i], filecount);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("������ ��ȣ�� �������ּ���.");
	scanf("%d", &number);
	
	getchar();
	system("cls");
	putStudentInfo2(&sd[number]);
}

// 4 - 1 : ����
void putStudentInfo3(struct STUDENTDATA* sd)
{
	char empty;

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");


	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("�л��� �̸��� �Է��ϼ��� : ");
	gets(sd->name);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("�й��� �Է��ϼ��� : ");
	scanf("%d", &sd->studentNum);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("��ȭ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &sd->number);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%f", &sd->kor);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%f", &sd->eng);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%f", &sd->math);
	scanf("%c", &empty);

	coord.X = 8;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("������ ��еǾ����ϴ�.");

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("������ ������ �����Ϸ��� �޴��� ���ư� 6���� �����ּ���.");

	coord.Y++;
	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("�޴��� ���ư����� ����Ű �������� ...");
	getchar();
	system("cls");
}

// 4 : ����
void insertStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 4;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 109; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 4;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 109; i++)
	{
		printf("��");
	}

	coord.X = 114;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	coord.X = 6;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < filecount; i++)
	{
		printf("%d|  ", i);
		printStudentInfo2(&sd[i], filecount);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("������ ��ȣ�� �������ּ���.");
	scanf("%d", &number);

	sd[filecount + 1] = sd[filecount];
	plusStudentNum(&sd[filecount + 1]);
	for (int i = filecount; i >= number; i--)
	{
		sd[i] = sd[i - 1];
		plusStudentNum(&sd[i]);
	}

	getchar();
	system("cls");
	putStudentInfo3(&sd[number]);
}

// 2 : ����
void deleteStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 4;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 109; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 4;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 109; i++)
	{
		printf("��");
	}

	coord.X = 114;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	coord.X = 6;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < filecount; i++)
	{
		printf("%d|  ", i);
		printStudentInfo2(&sd[i], filecount);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);

	printf("������ ��ȣ�� �������ּ���.");
	scanf("%d", &number);
	scanf("%c", &empty);
	

	for (int i = number; i <= filecount; i++)
	{
		sd[i] = sd[i + 1];
		minusStudentNum(&sd[i]);
	}

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("������ �Ϸ�Ǿ����ϴ�.");
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("������ ������ �����Ϸ��� �޴��� ���ư� 6���� ��������.");

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("�޴��� ���ư����� ����Ű �������� ...");
	getchar();
	system("cls");
}

// 8 -2 : ����
void printTotalPoint(struct STUDENTDATA* sd)
{
	sd->total = sd->kor + sd->eng + sd->math;
	printf("�̸�: %s\t����: %.2f\t����: %.2f\t����: %.2f\t����: %.2f\n", sd->name, sd->kor, sd->eng, sd->math, sd->total);
}

// 8 : ����
void totalStudentInfo(struct STUDENTDATA* sd, int filecount)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printTotalPoint(&sd[i]);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("�޴��� ���ư����� ����Ű �������� ...");
	getchar();
	system("cls");
}

// 9 - 2 : ����
float calcTotal(struct STUDENTDATA* sd)
{
	int total;

	total = sd->kor + sd->eng + sd->math;

	return total;
}

// 9 - 3 : ����
float saveTotal(struct STUDENTDATA* sd)
{
	sd->total = sd->kor + sd->eng + sd->math;
}

// 9 : ����
void rankStudentInfo(struct STUDENTDATA* sd, int filecount)
{
	int rank[100] = { 0, };
	float total[100] = { 0, };
	float biggest = 0;
	int count = 0;

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	printf("��");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < 100; i++)
	{
		printf("��");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("��");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("��");

	for (int i = 0; i < filecount; i++)
	{
		total[i] = calcTotal(&sd[i]);
		saveTotal(&sd[i]);
	}

	for (int i = 0; i < filecount; i++)
	{
		for (int j = 0; j < filecount; j++)
		{
			if (biggest < total[j])
			{
				biggest = total[j];
				count = j;
			}
		}
		rank[count] = i + 1;
		biggest = 0;
		total[count] = 0;
	}

	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	for (int i = 0; i < filecount; i++)
	{
		printf("�̸�: %s\t����: %.2f\t%d��\n", sd[i].name, sd[i].total, rank[i]);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("�޴��� ���ư����� ����Ű �������� ...");
	getchar();
	system("cls");
}

// 6 : ����
void saveStudentData(struct STUDENTDATA* sd, int filecount)
{
	char filename[1000] = { 0 };
	char filetype[50] = { 0 };

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("���ϸ��� �Է��ϼ��� : ");
	gets(filename);
	strcpy(filetype, ".bin");
	strcat(filename, filetype);

	FILE* student = fopen(&filename, "w+b");

	for (int i = 0; i < filecount; i++)
	{
		fwrite(sd[i].name, strlen(sd[i].name), 1, student);	// �̸�
		fprintf(student, "\t");
		fprintf(student, "%d", sd[i].studentNum);	// �й�
		fprintf(student, "\t");
		fprintf(student, "%d", sd[i].number);	// ��ȭ��ȣ
		fprintf(student, "\t");
		fprintf(student, "%.2f", sd[i].kor);	// ����
		fprintf(student, "\t");
		fprintf(student, "%.2f", sd[i].eng);	// ����
		fprintf(student, "\t");
		fprintf(student, "%.2f", sd[i].math);	// ����
		fprintf(student, "\t");
		saveTotal(&sd);		// ���� ���
		fprintf(student, "%.2f", sd[i].total);	// ����
		fprintf(student, "\t");
		fprintf(student, "%d", i + 1);	// �л� �� = filecount
		fprintf(student, "\n");
	}


	coord.X = 8;
	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("�ۼ��Ͻ� �л��� ������ %s���Ͽ� �����մϴ�.", filename);
	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("�޴��� ���ư����� ����Ű �������� ...");
	getchar();
	system("cls");
}

// 7 : �ε�
void fileLoad(struct STUDENTDATA sd[], int filecount)
{
	char filename[1000] = { 0 };
	char filetype[50] = { 0 };
	char buff[2000] = { 0, };
	int i, j;
	int size;
	char temp;
	char n[30] = { 0 };

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("���ϸ��� �Է��ϼ��� : ");
	gets(filename);
	strcpy(filetype, ".bin");
	strcat(filename, filetype);

	FILE* student;

	if ((student = fopen(&filename, "a+b")) == NULL)
	{
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("%s������ �������� �ʽ��ϴ�.", filename);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("�޴��� ���ư����� ����Ű�� ��������");
		getchar();
		system("cls");
	}
	else
	{
		student = fopen(&filename, "a+b");


		fseek(student, 0, SEEK_SET);
		for (int s = 0; s < filecount; s++)
		{
			memset(buff, 0, 2000);
			i = 0;
			j = 0;
			while (1)
			{
				while (1)
				{
					size = fread(&temp, 1, 1, student);
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
					strcpy(sd[s].name, buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 1)
				{
					sd[s].studentNum = atoi(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 2)
				{
					sd[s].number = atoi(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 3)
				{
					sd[s].kor = atof(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 4)
				{
					sd[s].eng = atof(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 5)
				{
					sd[s].math = atof(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 6)
				{
					sd[s].total = atof(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j > 6)
					break;
			}
		}

		coord.X = 8;
		coord.Y = 3;
		SetConsoleCursorPosition(handle, coord);
		printf("%s�����бⰡ �Ϸ�Ǿ����ϴ�.", filename);
		coord.Y += 2;
		SetConsoleCursorPosition(handle, coord);
		printf("�޴��� ���ư����� ����Ű �������� ...");
		getchar();
		system("cls");

	}
}


// 00 : ����
void fileLoadF(struct STUDENTDATA sd[], int filecount, char* filename)
{
	char filetype[50] = { 0 };
	char buff[2000] = { 0, };
	int i, j;
	int size;
	char temp;
	char n[30] = { 0 };

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("���ϸ��� �Է��ϼ��� : ");
	gets(filename);
	strcpy(filetype, ".bin");
	strcat(filename, filetype);

	FILE* student;

	if ((student = fopen(&filename, "a+b")) == NULL)
	{
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("%s������ �������� �ʽ��ϴ�.", filename);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("�޴��� ���ư����� ����Ű�� ��������");
		getchar();
		system("cls");
	}
	else
	{
		student = fopen(&filename, "a+b");


		fseek(student, 0, SEEK_SET);
		for (int s = 0; s < filecount; s++)
		{
			memset(buff, 0, 2000);
			i = 0;
			j = 0;
			while (1)
			{
				while (1)
				{
					size = fread(&temp, 1, 1, student);
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
					strcpy(sd[s].name, buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 1)
				{
					sd[s].studentNum = atoi(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 2)
				{
					sd[s].number = atoi(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 3)
				{
					sd[s].kor = atof(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 4)
				{
					sd[s].eng = atof(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 5)
				{
					sd[s].math = atof(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j == 6)
				{
					sd[s].total = atof(buff);
					memset(buff, 0, 2000);
					j++;
					i = 0;
				}
				else if (j > 6)
					break;
			}
		}

		coord.X = 8;
		coord.Y = 3;
		SetConsoleCursorPosition(handle, coord);
		printf("%s�����бⰡ �Ϸ�Ǿ����ϴ�.", filename);
		coord.Y += 2;
		SetConsoleCursorPosition(handle, coord);
		printf("�޴��� ���ư����� ����Ű �������� ...");
		getchar();
		system("cls");

	}

	return filename;
}

int main()
{
	struct STUDENTDATA sd[] = { 0, };
	int size = sizeof(struct STUDENTDATA);
	int menu = 0;
	int filecount = 0;
	int number = 0;
	char empty = 0;
	char n[30] = { 0 };
	char filename[1000] = { 0 };
	int num;

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	FILE* student;

	while (1)
	{
		menu = UI(menu);

		if (menu == 7)
		{
			fileLoadF(sd, filecount, &filename);
			break;
		}
		else
		{
			coord.X = 8;
			coord.Y = 3;
			SetConsoleCursorPosition(handle, coord);
			printf("7���� ���� ������ ���� �ҷ�������.");
			coord.Y++;
			SetConsoleCursorPosition(handle, coord);
			printf("�޴��� ���ư����� ����Ű�� ��������.");
			getchar();
			system("cls");
		}
	}

	student = fopen(&filename, "a+b");
	// txt���� �� �� -3
	// bin���� �� �� -2
	fseek(student, -2, SEEK_END);
	fread(n, 1, 1, student);
	filecount = atoi(n);

	while (1)
	{
		menu = UI(menu);

		/*if (menu == 7)
		{
			fileLoadF(sd, filecount, &filename);
			num = 0;
		}
		else
		{
			printf("7���� ���� ������ ���� �ҷ�������.");
			printf("�޴��� ���ư����� ����Ű�� ��������.");
		}

		if (num == 0)
		{
			student = fopen(&filename, "a+b");
			// txt���� �� �� -3
			// bin���� �� �� -2
			fseek(student, -2, SEEK_END);
			fread(n, 1, 1, student);
			filecount = atoi(n);
			num = 1;
		}*/


		switch (menu)
		{
		case 1:
			putStudentInfo1(&sd[filecount]);
			filecount++;
			break;
		case 2:
			deleteStudentInfo(&sd, filecount, number, empty);
			filecount--;
			break;
		case 3:
			changeStudentInfo(&sd, filecount, number, empty);
			break;
		case 4:
			insertStudentInfo(&sd, filecount, number, empty);
			filecount++;
			break;
		case 5:
			printStudentInfo1(sd, filecount);
			break;
		case 6:
			saveStudentData(&sd, filecount);
			break;
		case 7:
			fileLoad(sd, filecount);
			break;
		case 8:
			totalStudentInfo(&sd, filecount);
			break;
		case 9:
			rankStudentInfo(&sd, filecount);
			break;
		case 10:
			exit(0);
		}
	}

	printf("��\n");
	fclose(student);

	return 0;
}

//���ϸ� �Է� �� �Է��� ���ϸ����� ����

