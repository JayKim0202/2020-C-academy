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

// 1 : 학생추가
void putStudentInfo(struct STUDENTDATA* sd)
{
	char empty;

	printf("학생의 이름을 입력하세요\n");
	gets(sd->name);
	printf("학번을 입력하세요\n");
	scanf("%d", &sd->studentNum);
	printf("전화번호를 입력하세요\n");
	scanf("%d", &sd->number);
	printf("국어 점수를 입력하세요\n");
	scanf("%f", &sd->kor);
	printf("영어 점수를 입력하세요\n");
	scanf("%f", &sd->eng);
	printf("수학 점수를 입력하세요\n");
	scanf("%f", &sd->math);
	scanf("%c", &empty);

	printf("\n 정보가 추가되었습니다.\n추가한 정보를 저장하려면 메뉴로 돌아가 6번을 눌러주세요.");
	printf("\n메뉴로 돌아가려면 아무키 누르세요 ...");
	getchar();
	system("cls");
}

// 5 : 출력
void printStudentInfo1(struct STUDENTDATA* sd, int filecount)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("학번: %d\t이름: %s\t전화번호: 0%d\t국어: %.2f\t영어: %.2f\t수학: %.2f\n", sd[i].studentNum, sd[i].name, sd[i].number, sd[i].kor, sd[i].eng, sd[i].math);
	}

	printf("\n메뉴로 돌아가려면 아무키 누르세요 ...");
	getchar();
	system("cls");
}

// 5 - 1 : 출력
void printStudentInfo2(struct STUDENTDATA* sd, int filecount)
{
	printf("학번: %d\t이름: %s\t전화번호: 0%d\t국어: %.2f\t영어: %.2f\t수학: %.2f\n", sd->studentNum, sd->name, sd->number, sd->kor, sd->eng, sd->math);
}

// 4 - 1 : 삽입
void plusStudentNum(struct STUDENTDATA* sd)
{
	sd->studentNum += 1;
}

// 2 - 1 : 삭제
void minusStudentNum(struct STUDENTDATA* sd)
{
	sd->studentNum -= 1;
}

// 3 : 수정
void changeStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("수정선택번호: %d\t", i);
		printStudentInfo2(&sd[i],filecount);
	}
	printf("\n수정할 번호를 선택해주세요.");
	scanf("%d", &number);
	scanf("%c", &empty);
	putStudentInfo(&sd[number]);

	printf("\n메뉴로 돌아가려면 아무키 누르세요 ...");
	getchar();
	system("cls");
}

// 4 : 삽입
void insertStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("삽입선택번호: %d\t", i);
		printStudentInfo2(&sd[i],filecount);
	}
	printf("\n삽입할 번호를 선택해주세요.");
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

	printf("\n수정이 완료되었습니다. 수정한 정보를 저장하려면 메뉴로 돌아가 6번을 누르세요.");
	printf("\n메뉴로 돌아가려면 아무키 누르세요 ...");
	getchar();
	system("cls");
}

// 2 : 삭제
void deleteStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	for (int i = 0; i < filecount; i++)
	{
		printf("삭제선택번호: %d\t", i);
		printStudentInfo2(&sd[i], filecount);
	}
	printf("\n삭제할 번호를 선택해주세요.");
	scanf("%d", &number);
	scanf("%c", &empty);

	for (int i = number; i <= filecount; i++)
	{
		sd[i] = sd[i + 1];
		minusStudentNum(&sd[i]);
	}

	printf("삭제가 완료되었습니다. 수정한 정보를 저장하려면 메뉴로 돌아가 6번을 누르세요.");
	printf("\n메뉴로 돌아가려면 아무키 누르세요 ...");
	getchar();
	system("cls");
}

// 8 -2 : 총점
void printTotalPoint(struct STUDENTDATA* sd)
{
	sd->total = sd->kor + sd->eng + sd->math;
	printf("이름: %s\t국어: %.2f\t영어: %.2f\t수학: %.2f\t총점: %.2f\n", sd->name, sd->kor, sd->eng, sd->math, sd->total);
}

// 8 : 총점
void totalStudentInfo(struct STUDENTDATA* sd, int filecount)
{
	for (int i = 0; i < filecount; i++)
	{
		printTotalPoint(&sd[i]);
	}

	printf("\n메뉴로 돌아가려면 아무키 누르세요 ...");
	getchar();
	system("cls");
}

// 9 - 2 : 순위
float calcTotal(struct STUDENTDATA* sd)
{
	int total;

	total = sd->kor + sd->eng + sd->math;

	return total;
}

// 9 - 3 : 순위
float saveTotal(struct STUDENTDATA* sd)
{
	sd->total = sd->kor + sd->eng + sd->math;
}

// 9 : 순위
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
		printf("이름: %s\t총점: %.2f\t%d등\n", sd[i].name, sd[i].total, rank[i]);
	}

	printf("\n메뉴로 돌아가려면 아무키 누르세요 ...");
	getchar();
	system("cls");
}

// 6 : 저장
void saveStudentData(struct STUDENTDATA* sd, int filecount)
{
	FILE* student = fopen("student.bin", "w+b");

	for (int i = 0; i < filecount; i++)
	{
		fwrite(sd[i].name, strlen(sd[i].name), 1, student);	// 이름
		fprintf(student, "\t");
		fprintf(student, "%d", sd[i].studentNum);	// 학번
		fprintf(student, "\t");
		fprintf(student, "%d", sd[i].number);	// 전화번호
		fprintf(student, "\t");
		fprintf(student, "%.2f", sd[i].kor);	// 국어
		fprintf(student, "\t");
		fprintf(student, "%.2f", sd[i].eng);	// 영어
		fprintf(student, "\t");
		fprintf(student, "%.2f", sd[i].math);	// 수학
		fprintf(student, "\t");
		saveTotal(&sd);		// 총점 계산
		fprintf(student, "%.2f", sd[i].total);	// 총점
		fprintf(student, "\t");
		fprintf(student, "%d", i + 1);	// 학생 수 = filecount
		fprintf(student, "\n");
	}

	printf("\n메뉴로 돌아가려면 아무키 누르세요 ...");
	getchar();
	system("cls");
}

// 7 : 로드
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

	printf("파일읽기가 완료되었습니다.");
	printf("\n메뉴로 돌아가려면 아무키 누르세요 ...");
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

	// txt파일 일 때 -3
	// bin파일 일 때 -2
	fseek(student, -2, SEEK_END);
	fread(n, 1, 1, student);
	filecount = atoi(n);

	while (1)
	{
		printf("MENU\n");
		printf("1.학생추가 2.삭제 3.정보수정 4.삽입 5.출력 6.저장 7.로드 8.총점 9.순위 10.종료\n\n");

		printf("메뉴를 선택하세요\n");
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
			printf("작성하신 학생의 정보를 student.bin파일에 저장합니다.\n");
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

	printf("끝\n");
	fclose(student);

	return 0;
}