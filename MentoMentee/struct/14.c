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
		printf("1. �߰�\n");
		printf("2. ���\n");
		printf("3. �˻�\n");
		printf("4. ����\n");
		printf("========================\n");
		printf("���� ���� �Է��Ͻÿ� : ");
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
	printf("����:");
	scanf(" %[^\n]s", song->title);
	printf("����:");
	scanf(" %[^\n]s", song->singer);
	printf("��ġ:");
	scanf(" %[^\n]s", song->location);
	printf("�帣(0: ����, 1: ��, 2: Ŭ����, 3: ��ȭ����)");
	scanf("%d", &song->genre);
}
void print(SONG song[20], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("����: %s\n", song[i].title);
		printf("����: %s\n", song[i].singer);
		printf("��ġ: %s\n", song[i].location);
		printf("�帣(0: ����, 1: ��, 2: Ŭ����, 3: ��ȭ����): %d\n\n", song[i].genre);
	}
}
void search(SONG song[20])
{
	char search_things[50];

	printf("���� �Ǵ� ������ �Է��ϼ���: ");
	scanf(" %[^\n]s", &search_things);

	for (int i = 0; i < 20; i++)
	{
		if (song[i].title == NULL) break;

		if (strstr(song[i].title, search_things) != NULL)
		{
			printf("����: %s\n", song[i].title);
			printf("����: %s\n", song[i].singer);
			printf("��ġ: %s\n", song[i].location);
			printf("�帣(0: ����, 1: ��, 2: Ŭ����, 3: ��ȭ����): %d\n\n", song[i].genre);
			continue;
		}

		if (strstr(song[i].singer, search_things) != NULL)
		{
			printf("����: %s\n", song[i].title);
			printf("����: %s\n", song[i].singer);
			printf("��ġ: %s\n", song[i].location);
			printf("�帣(0: ����, 1: ��, 2: Ŭ����, 3: ��ȭ����): %d\n\n", song[i].genre);
		}
	}	
}