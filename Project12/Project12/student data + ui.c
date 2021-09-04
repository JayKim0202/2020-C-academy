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

	printf("┌");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 7; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 7; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");

	coord.X = 54;
	coord.Y = 4;

	SetConsoleCursorPosition(handle, coord);

	printf("학생정보");

	coord.X = 90;
	coord.Y = 6;

	SetConsoleCursorPosition(handle, coord);

	printf("작성자 : 김수진");

	coord.X = 90;
	coord.Y = 8;

	SetConsoleCursorPosition(handle, coord);

	printf("버전 : 21.01.11");

	coord.X = 56;
	coord.Y = 11;

	SetConsoleCursorPosition(handle, coord);

	printf("*MENU*");

	coord.X = 18;
	coord.Y = 13;
	SetConsoleCursorPosition(handle, coord);
	printf("1.학생추가");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("2.삭제");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("3.정보수정");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("4.삽입");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("5.출력");

	coord.X = 75;
	coord.Y = 13;
	SetConsoleCursorPosition(handle, coord);
	printf("6.저장");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("7.로드");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("8.총점");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("9.순위");

	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("10.종료");

	coord.X = 18;
	coord.Y++;
	coord.Y++;

	SetConsoleCursorPosition(handle, coord);

	printf("메뉴를 선택하세요 : ");
	scanf("%d", &menu);
	getchar();
	system("cls");

	return menu;
}

// 1 : 학생추가
void putStudentInfo1(struct STUDENTDATA* sd)
{
	char empty;

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");


	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("학생의 이름을 입력하세요 : ");
	gets(sd->name);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("학번을 입력하세요 : ");
	scanf("%d", &sd->studentNum);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("전화번호를 입력하세요 : ");
	scanf("%d", &sd->number);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("국어 점수를 입력하세요 : ");
	scanf("%f", &sd->kor);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("영어 점수를 입력하세요 : ");
	scanf("%f", &sd->eng);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("수학 점수를 입력하세요 : ");
	scanf("%f", &sd->math);
	scanf("%c", &empty);

	coord.X = 8;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("정보가 추가되었습니다.");

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("추가한 정보를 저장하려면 메뉴로 돌아가 6번을 눌러주세요.");

	coord.Y++;
	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
	getchar();
	system("cls");
}

// 5 - 1 : 출력
void printStudentInfo2(struct STUDENTDATA* sd, int filecount)
{
	printf("학번: %d\t이름: %s\t전화번호: 0%d\t국어: %.2f\t영어: %.2f\t수학: %.2f\n", sd->studentNum, sd->name, sd->number, sd->kor, sd->eng, sd->math);
}

// 5 : 출력
void printStudentInfo1(struct STUDENTDATA* sd, int filecount)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");

	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("학번: %d\t이름: %s\t전화번호: 0%d\t국어: %.2f\t영어: %.2f\t수학: %.2f\n", sd[i].studentNum, sd[i].name, sd[i].number, sd[i].kor, sd[i].eng, sd[i].math);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
	getchar();
	system("cls");
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

// 3 - 1 : 수정
void putStudentInfo2(struct STUDENTDATA* sd)
{
	char empty;

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");


	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("학생의 이름을 입력하세요 : ");
	gets(sd->name);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("학번을 입력하세요 : ");
	scanf("%d", &sd->studentNum);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("전화번호를 입력하세요 : ");
	scanf("%d", &sd->number);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("국어 점수를 입력하세요 : ");
	scanf("%f", &sd->kor);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("영어 점수를 입력하세요 : ");
	scanf("%f", &sd->eng);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("수학 점수를 입력하세요 : ");
	scanf("%f", &sd->math);
	scanf("%c", &empty);

	coord.X = 8;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("정보가 수정되었습니다.");

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("수정한 정보를 저장하려면 메뉴로 돌아가 6번을 눌러주세요.");

	coord.Y++;
	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
	getchar();
	system("cls");
}

// 3 : 수정
void changeStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 4;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 109; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 4;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 109; i++)
	{
		printf("─");
	}

	coord.X = 114;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");

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
	printf("수정할 번호를 선택해주세요.");
	scanf("%d", &number);
	
	getchar();
	system("cls");
	putStudentInfo2(&sd[number]);
}

// 4 - 1 : 삽입
void putStudentInfo3(struct STUDENTDATA* sd)
{
	char empty;

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < 6; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");


	coord.X = 10;
	coord.Y = 3;
	SetConsoleCursorPosition(handle, coord);
	printf("학생의 이름을 입력하세요 : ");
	gets(sd->name);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("학번을 입력하세요 : ");
	scanf("%d", &sd->studentNum);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("전화번호를 입력하세요 : ");
	scanf("%d", &sd->number);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("국어 점수를 입력하세요 : ");
	scanf("%f", &sd->kor);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("영어 점수를 입력하세요 : ");
	scanf("%f", &sd->eng);

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("수학 점수를 입력하세요 : ");
	scanf("%f", &sd->math);
	scanf("%c", &empty);

	coord.X = 8;
	coord.Y = 10;
	SetConsoleCursorPosition(handle, coord);
	printf("정보가 삽압되었습니다.");

	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("삽입한 정보를 저장하려면 메뉴로 돌아가 6번을 눌러주세요.");

	coord.Y++;
	coord.Y++;
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
	getchar();
	system("cls");
}

// 4 : 삽입
void insertStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 4;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 109; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 4;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 109; i++)
	{
		printf("─");
	}

	coord.X = 114;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");

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
	printf("수정할 번호를 선택해주세요.");
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

// 2 : 삭제
void deleteStudentInfo(struct STUDENTDATA* sd, int filecount, int number, char empty)
{
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 4;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 109; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 4;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 109; i++)
	{
		printf("─");
	}

	coord.X = 114;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");

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

	printf("삭제할 번호를 선택해주세요.");
	scanf("%d", &number);
	scanf("%c", &empty);
	

	for (int i = number; i <= filecount; i++)
	{
		sd[i] = sd[i + 1];
		minusStudentNum(&sd[i]);
	}

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("삭제가 완료되었습니다.");
	coord.Y++;
	SetConsoleCursorPosition(handle, coord);
	printf("수정한 정보를 저장하려면 메뉴로 돌아가 6번을 누르세요.");

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
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
	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");

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
	printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
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

	HANDLE handle;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;

	coord.X = 8;
	coord.Y = 2;

	SetConsoleCursorPosition(handle, coord);

	printf("┌");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	printf("┐");


	coord.X = 8;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("└");

	for (int i = 0; i < 100; i++)
	{
		printf("─");
	}

	coord.X = 109;
	coord.Y = 3;

	SetConsoleCursorPosition(handle, coord);

	for (int i = 0; i < filecount; i++)
	{
		printf("│");
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	printf("┘");

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
		printf("이름: %s\t총점: %.2f\t%d등\n", sd[i].name, sd[i].total, rank[i]);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
	}

	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
	getchar();
	system("cls");
}

// 6 : 저장
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
	printf("파일명을 입력하세요 : ");
	gets(filename);
	strcpy(filetype, ".bin");
	strcat(filename, filetype);

	FILE* student = fopen(&filename, "w+b");

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


	coord.X = 8;
	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("작성하신 학생의 정보를 %s파일에 저장합니다.", filename);
	coord.Y += 2;
	SetConsoleCursorPosition(handle, coord);
	printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
	getchar();
	system("cls");
}

// 7 : 로드
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
	printf("파일명을 입력하세요 : ");
	gets(filename);
	strcpy(filetype, ".bin");
	strcat(filename, filetype);

	FILE* student;

	if ((student = fopen(&filename, "a+b")) == NULL)
	{
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("%s파일이 존재하지 않습니다.", filename);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("메뉴로 돌아가려면 엔터키를 누르세요");
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
		printf("%s파일읽기가 완료되었습니다.", filename);
		coord.Y += 2;
		SetConsoleCursorPosition(handle, coord);
		printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
		getchar();
		system("cls");

	}
}


// 00 : 시작
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
	printf("파일명을 입력하세요 : ");
	gets(filename);
	strcpy(filetype, ".bin");
	strcat(filename, filetype);

	FILE* student;

	if ((student = fopen(&filename, "a+b")) == NULL)
	{
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("%s파일이 존재하지 않습니다.", filename);
		coord.Y++;
		SetConsoleCursorPosition(handle, coord);
		printf("메뉴로 돌아가려면 엔터키를 누르세요");
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
		printf("%s파일읽기가 완료되었습니다.", filename);
		coord.Y += 2;
		SetConsoleCursorPosition(handle, coord);
		printf("메뉴로 돌아가려면 엔터키 누르세요 ...");
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
			printf("7번을 눌러 파일을 먼저 불러오세요.");
			coord.Y++;
			SetConsoleCursorPosition(handle, coord);
			printf("메뉴로 돌아가려면 엔터키를 누르세요.");
			getchar();
			system("cls");
		}
	}

	student = fopen(&filename, "a+b");
	// txt파일 일 때 -3
	// bin파일 일 때 -2
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
			printf("7번을 눌러 파일을 먼저 불러오세요.");
			printf("메뉴로 돌아가려면 엔터키를 누르세요.");
		}

		if (num == 0)
		{
			student = fopen(&filename, "a+b");
			// txt파일 일 때 -3
			// bin파일 일 때 -2
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

	printf("끝\n");
	fclose(student);

	return 0;
}

//파일명 입력 시 입력한 파일명으로 저장

