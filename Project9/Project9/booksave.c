/*booksave.c -- 구조체의 내용을 파일에 저장한다.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char* s_gets(char* st, int n);

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main()
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("book.dat 파일을 열 수 없습니다.\n", stderr);
		exit(1);
	}

	rewind(pbooks);

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("book.dat에 현재 들어 있는 내용:");
		printf("%s by %s: &%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}

	filecount = count;
	if (count == MAXBKS)
	{
		fputs("book.dat 파일이 가득 찾다.", stderr);
		exit(2);
	}

	puts("새 도서 제목들을 입력하시오.");
	puts("끝내려면 라인의 시작 위치에 [enter] 키를 누르시오.");
	while (count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0')
	{
		puts("저자명을 입력하시오.");
		s_gets(library[count].author, MAXAUTL);
		puts("정가를 입력하시오.");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("다음 타이틀을 입력하시오.");
	}

	if (count > 0)
	{
		puts("다음 소장하고 있는 도서들의 목록입니다.");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("책이 한 한권도 없어요! 야, 장하다 장해.\n");

	puts("끝.\n");
	fclose(pbooks);

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}