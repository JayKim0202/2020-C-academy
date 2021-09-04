#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
}

// 5 : ���
void printStudentInfo(struct STUDENTDATA* sd)
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
void changeStudentInfo(struct STUDENTDATA *sd, int filecount, int number, char empty)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("�������ù�ȣ: %d\t", i);
		printStudentInfo(&sd[i]);
	}
	printf("������ ��ȣ�� �������ּ���.");
	scanf("%d", &number);
	scanf("%c", &empty);
	putStudentInfo(&sd[number]);
}

// 4 : ����
void insertStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	for (int i = 0; i < filecount; i++)
			{
				printf("���Լ��ù�ȣ: %d\t", i);
				printStudentInfo(&sd[i]);
			}
			printf("������ ��ȣ�� �������ּ���.");
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
}

// 2 : ����
void deleteStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("�������ù�ȣ: %d\t", i);
		printStudentInfo(&sd[i]);
	}
	printf("������ ��ȣ�� �������ּ���.");
	scanf("%d", &number);
	scanf("%c", &empty);

	for (int i = number; i <= filecount; i++)
	{
		sd[i] = sd[i + 1];
		minusStudentNum(&sd[i]);
	}
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
}

// 6 : ����
void saveStudentData(struct STUDENTDATA* sd)
{
	FILE* student = fopen("student.bin", "a+b");

	fwrite(sd->name, NAME, 1, student);	// �̸�
	fprintf(student, "\t");
	fprintf(student, "%d", sd->studentNum);	// �й�
	fprintf(student, "\t");
	fprintf(student, "%d", sd->number);	// ��ȭ��ȣ
	fprintf(student, "\t");
	fprintf(student, "%.2f", sd->kor);	// ����
	fprintf(student, "\t");
	fprintf(student, "%.2f", sd->eng);	// ����
	fprintf(student, "\t");
	fprintf(student, "%.2f", sd->math);	// ����
	fprintf(student, "\t");
	fprintf(student, "%.2f", sd->total);	// ����
	fprintf(student, "\t");
}

// 7 : �ε�
void fileLoad(struct STUDENTDATA* sd, int filecount)
{
	char buff[2000] = { 0, };
	int i, j;
	int size;
	int temp;
	char n;

	FILE* student = fopen("student.bin", "a+b");

	fseek(student, -2, SEEK_END);
	fread(n, 2, 1, student);
	filecount = atoi(n);
	printf("%d", filecount);

	fseek(student, 0, SEEK_SET);
	for (int s = 0; s < filecount; s++)
	{
		memset(buff, 0, 2000);
		i = 0;
		j = 0;

		for (; 1;)
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
			j++;
		}
		else if (j == 1)
		{
			sd[s].studentNum = atoi(buff);
			j++;
		}
		else if (j == 2)
		{
			sd[s].number = atoi(buff);
			j++;
		}
		else if (j == 3)
		{
			sd[s].kor = atoi(buff);
			j++;
		}
		else if (j == 4)
		{
			sd[s].eng = atoi(buff);
			j++;
		}
		else if (j == 5)
		{
			sd[s].math = atoi(buff);
			j++;
		}
		else if (j == 6)
		{
			sd[s].total = atoi(buff);
			j++;
		}
	}
}

/*void loadStudentInfo(struct STUDENTDATA* sd, int filecount)
{
	char c;
	char s[100];
	int size;
	int num1;
	int num2;
	FILE* student = fopen("student.bin", "rb");

	fseek(student, 0, SEEK_END);
	size = ftell(student);

	fseek(student, 0, SEEK_SET);

	for (int c = 0; c < filecount; c++)
	{
		// �̸�
		for (int i = 0; i < size; i++)
		{
			c = fgetc(student);
			s[i] = c;
			num1 = i;
			if (c == '\t')
			{
				for (int j = 0; j < i; j++)
				{
					strcpy(sd[c].name, s[j]);
				}
				break;
			}
		}

		// �й�
		for (int i = 0; i < size; i++)
		{
			c = fgetc(student);
			s[i] = c;
			num2 = i;
			if (num1 < i && c == '\t')
			{
				for (int j = num1; j < i; j++)
				{
					strcpy(sd[c].studentNum, (int)s[j]);
				}
				break;
			}
		}

		// ��ȭ��ȣ
		for (int i = 0; i < size; i++)
		{
			c = fgetc(student);
			s[i] = c;
			num1 = i;
			if (num2 < i && c == '\t')
			{
				for (int j = num2; j < i; j++)
				{
					strcpy(sd[c].number, (int)s[j]);
				}
				break;
			}
		}

		// ����
		for (int i = 0; i < size; i++)
		{
			c = fgetc(student);
			s[i] = c;
			num2 = i;
			if (num1 < i && c == '\t')
			{
				for (int j = num1; j < i; j++)
				{

				}
			}
		}
		// ����
		// ����
		// ����
	}
	


}*/

int main()
{
	struct STUDENTDATA sd[] = { 0, };
	int size = sizeof(struct STUDENTDATA);
	int menu;
	int count;
	int filecount = 0;
	int number = 0;
	char empty;
	//int rank[100] = { 0, };
	//float total[100] = { 0, };

	FILE* student = fopen("student.bin", "a+b");
	
	/*if (count == 0)
	{
		while (1)
		{
			putStudentInfo(&sd[count]);
			fwrite(&sd[count], size, 1, student);
			count++;
			printf("�Է��� �������� '0'�� �����ּ���(�ٸ� ���ڸ� ������ ��ӵ˴ϴ�.)");
			scanf("%d", &done);
			if (done == 0)
			{
				printf("��.");
				break;
			}
		}
	}
	filecount = count;*/

	count = filecount;

	while (1)
	{
		printf("\nMENU\n");
		printf("1.�л��߰� 2.���� 3.�������� 4.���� 5.��� 6.���� 7.�ε� 8.���� 9.���� 10.����\n\n");

		printf("�޴��� �����ϼ���\n");
		scanf("%d", &menu);
		scanf("%c", &empty);
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
			for (int i = 0; i < filecount; i++)
				printStudentInfo(&sd[i]);
			break;
		case 6:
			printf("�ۼ��Ͻ� �л��� ������ student.bin���Ͽ� �����մϴ�.\n");
			for (int i = count; i < filecount; i++)
				saveStudentData(&sd[i]);
			count = filecount;
			break;
		case 7:
			fileLoad(&sd, filecount);
			break;
		case 8:
			totalStudentInfo(&sd, filecount);
			break;
		case 9:
			rankStudentInfo(&sd, filecount);
			break;
		case 10:
			fprintf(student, " %d", filecount);
			exit(0);
		}
	}

	printf("��\n");
	fclose(student);

	return 0;
}