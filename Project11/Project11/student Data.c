#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
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

// 1 : �л��߰�
void putStudentInfo(struct STUDENTDATA* sd)
{
	char empty;

	printf("�л��� �̸��� �Է��ϼ���\n");
	gets(sd->name);
	printf("�й��� �Է��ϼ���\n");
	scanf("%d", &sd->studentNum);
	printf("��ȭ��ȣ�� �Է��ϼ���\n");
	scanf("%d", &sd->number);
	printf("���� ������ �Է��ϼ���\n");
	scanf("%f", &sd->kor);
	printf("���� ������ �Է��ϼ���\n");
	scanf("%f", &sd->eng);
	printf("���� ������ �Է��ϼ���\n");
	scanf("%f", &sd->math);
	scanf("%c", &empty);

	printf("\n ������ �߰��Ǿ����ϴ�.\n�߰��� ������ �����Ϸ��� �޴��� ���ư� 6���� �����ּ���.");
	printf("\n�޴��� ���ư����� �ƹ�Ű �������� ...");
	getchar();
	system("cls");
}

// 5 : ���
void printStudentInfo1(struct STUDENTDATA* sd, int filecount)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("�й�: %d\t�̸�: %s\t��ȭ��ȣ: 0%d\t����: %.2f\t����: %.2f\t����: %.2f\n", sd[i].studentNum, sd[i].name, sd[i].number, sd[i].kor, sd[i].eng, sd[i].math);
	}

	printf("\n�޴��� ���ư����� �ƹ�Ű �������� ...");
	getchar();
	system("cls");
}

// 5 - 1 : ���
void printStudentInfo2(struct STUDENTDATA* sd, int filecount)
{
	printf("�й�: %d\t�̸�: %s\t��ȭ��ȣ: 0%d\t����: %.2f\t����: %.2f\t����: %.2f\n", sd->studentNum, sd->name, sd->number, sd->kor, sd->eng, sd->math);
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

// 3 : ����
void changeStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("�������ù�ȣ: %d\t", i);
		printStudentInfo2(&sd[i],filecount);
	}
	printf("\n������ ��ȣ�� �������ּ���.");
	scanf("%d", &number);
	scanf("%c", &empty);
	putStudentInfo(&sd[number]);

	printf("\n�޴��� ���ư����� �ƹ�Ű �������� ...");
	getchar();
	system("cls");
}

// 4 : ����
void insertStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("���Լ��ù�ȣ: %d\t", i);
		printStudentInfo2(&sd[i],filecount);
	}
	printf("\n������ ��ȣ�� �������ּ���.");
	scanf("%d", &number);
	scanf("%c", &empty);

	sd[filecount + 1] = sd[filecount];
	plusStudentNum(&sd[filecount + 1]);
	for (int i = filecount; i >= number; i--)
	{
		sd[i] = sd[i - 1];
		plusStudentNum(&sd[i]);
	}

	putStudentInfo(&sd[number]);

	printf("\n������ �Ϸ�Ǿ����ϴ�. ������ ������ �����Ϸ��� �޴��� ���ư� 6���� ��������.");
	printf("\n�޴��� ���ư����� �ƹ�Ű �������� ...");
	getchar();
	system("cls");
}

// 2 : ����
void deleteStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("�������ù�ȣ: %d\t", i);
		printStudentInfo2(&sd[i], filecount);
	}
	printf("\n������ ��ȣ�� �������ּ���.");
	scanf("%d", &number);
	scanf("%c", &empty);

	for (int i = number; i <= filecount; i++)
	{
		sd[i] = sd[i + 1];
		minusStudentNum(&sd[i]);
	}

	printf("������ �Ϸ�Ǿ����ϴ�. ������ ������ �����Ϸ��� �޴��� ���ư� 6���� ��������.");
	printf("\n�޴��� ���ư����� �ƹ�Ű �������� ...");
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
	for (int i = 0; i < filecount; i++)
	{
		printTotalPoint(&sd[i]);
	}

	printf("\n�޴��� ���ư����� �ƹ�Ű �������� ...");
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

	for (int i = 0; i < filecount; i++)
	{
		printf("�̸�: %s\t����: %.2f\t%d��\n", sd[i].name, sd[i].total, rank[i]);
	}

	printf("\n�޴��� ���ư����� �ƹ�Ű �������� ...");
	getchar();
	system("cls");
}

// 6 : ����
void saveStudentData(struct STUDENTDATA* sd, int filecount)
{
	FILE* student = fopen("student.bin", "w+b");

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

	printf("\n�޴��� ���ư����� �ƹ�Ű �������� ...");
	getchar();
	system("cls");
}

// 7 : �ε�
void fileLoad(struct STUDENTDATA sd[], int filecount)
{
	char buff[2000] = { 0, };
	int i, j;
	int size;
	char temp;
	char n[30] = { 0 };

	FILE* student = fopen("student.bin", "a+b");


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

	printf("�����бⰡ �Ϸ�Ǿ����ϴ�.");
	printf("\n�޴��� ���ư����� �ƹ�Ű �������� ...");
	getchar();
	system("cls");
}

int main()
{
	struct STUDENTDATA sd[] = { 0, };
	int size = sizeof(struct STUDENTDATA);
	int menu;
	int filecount = 0;
	int number = 0;
	char empty = 0;
	char n[30] = { 0 };


	FILE* student = fopen("student.bin", "a+b");

	// txt���� �� �� -3
	// bin���� �� �� -2
	fseek(student, -2, SEEK_END);
	fread(n, 1, 1, student);
	filecount = atoi(n);

	while (1)
	{
		printf("MENU\n");
		printf("1.�л��߰� 2.���� 3.�������� 4.���� 5.��� 6.���� 7.�ε� 8.���� 9.���� 10.����\n\n");

		printf("�޴��� �����ϼ���\n");
		scanf("%d", &menu);
		getchar();
		system("cls");
	
		switch (menu)
		{
		case 1:
			putStudentInfo(&sd[filecount]);
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
			printf("�ۼ��Ͻ� �л��� ������ student.bin���Ͽ� �����մϴ�.\n");
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