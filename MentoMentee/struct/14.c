#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
	char title[50];
	char singer[30];
	char location[30];
	int genre;
}SONG;

void add(SONG *song);
void print(SONG song[20], int count);
void search(SONG song[20]);

int main()
{
	SONG song[20] = { 0 };
	int bttn;
	int i = 0;

	while (1)
	{
		printf("========================\n");
		printf("1. 추가\n");
		printf("2. 출력\n");
		printf("3. 검색\n");
		printf("4. 종료\n");
		printf("========================\n");
		printf("정수 값을 입력하시오 : ");
		scanf("%d", &bttn);
		
		switch (bttn)
		{
		case 1:
			add(&song[i]);
			i++;
			break;
		case 2:
			print(song, i);
			break;
		case 3:
			search(song);
			break;
		case 4:
			exit(0);
		}
	}
	return 0;
}

void add(SONG *song)
{
	printf("제목:");
	scanf(" %[^\n]s", song->title);
	printf("가수:");
	scanf(" %[^\n]s", song->singer);
	printf("위치:");
	scanf(" %[^\n]s", song->location);
	printf("장르(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악)");
	scanf("%d", &song->genre);
}
void print(SONG song[20], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("제목: %s\n", song[i].title);
		printf("가수: %s\n", song[i].singer);
		printf("위치: %s\n", song[i].location);
		printf("장르(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악): %d\n\n", song[i].genre);
	}
}
void search(SONG song[20])
{
	char search_things[50];

	printf("제목 또는 가수를 입력하세요: ");
	scanf(" %[^\n]s", &search_things);

	for (int i = 0; i < 20; i++)
	{
		if (song[i].title == NULL) break;

		if (strstr(song[i].title, search_things) != NULL)
		{
			printf("제목: %s\n", song[i].title);
			printf("가수: %s\n", song[i].singer);
			printf("위치: %s\n", song[i].location);
			printf("장르(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악): %d\n\n", song[i].genre);
			continue;
		}

		if (strstr(song[i].singer, search_things) != NULL)
		{
			printf("제목: %s\n", song[i].title);
			printf("가수: %s\n", song[i].singer);
			printf("위치: %s\n", song[i].location);
			printf("장르(0: 가요, 1: 팝, 2: 클래식, 3: 영화음악): %d\n\n", song[i].genre);
		}
	}	
}