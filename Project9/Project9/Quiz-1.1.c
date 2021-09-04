/*
ex) 4 Jessie Joybat 5 2 1 1

���ȣ�� 0 ~ 18���� ���� ����

���ȣ(back number) �̸�(first name, last name) Ÿ��(at bats) ��Ÿ(hits) ����(walks) Ÿ��(RBIs: runs batted in)

����ü -> ������ �̸�, ������ ����, Ÿ��, ��Ÿ, ����, Ÿ��, Ÿ��(���߿� ����Ѵ�)
������ ���ȣ�� �迭 �ε����� ����� �� �ִ�.

�� ������ ���� ���� ����

Ÿ��(betting average = ��Ÿ(Ȩ������) / Ÿ��

�������� �������� ���� �����Ϳ� ƾ ��ü ��� ǥ��
*/

#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BACKNUMBER 18
#define NAME 40

struct playerInfo {
	char fullname[NAME];
	int atBats;
	int hits;
	int walks;
	int RBIs;
	float battingAverage;
} Players;

int main()
{
	struct playerInfo players[BACKNUMBER];
	int count = 0;
	int index, filecount;
	FILE* player;
	int size = sizeof(struct playerInfo);
	char empty;

	if ((player = fopen("baseball_players.bin", "a+b")) == NULL)
	{
		fputs("baseball_players.bin ������ �� �� �����ϴ�.\n", stderr);
		exit(1);
	}

	rewind(player);

	while (count < BACKNUMBER && fread(&players[count], size, 1, player) == 1)
	{
		if (count == 0)
			puts("���� ����");
		printf("%s\tŸ��: %d ��Ÿ: %d ����: %d Ÿ��: %d\n",
			players[count].fullname, players[count].atBats, players[count].hits, players[count].walks, players[count].RBIs);
		count++;
	}

	filecount = count;
	if (count == BACKNUMBER)
	{
		fputs("baseball_players.bin ������ ���� ã��.", stderr);
		exit(2);
	}

	puts("�������� ������ ���� ��ġ�� [enter] Ű�� ��������.");
	puts("������ �̸�(������)�� �Է��ϼ���");
	while (count < BACKNUMBER && gets(players[count].fullname) != NULL && players[count].fullname[0] != '\0')
	{
		printf("%s������ Ÿ���� �Է��ϼ���\n", players[count].fullname);
		scanf("%d", &players[count].atBats);
		printf("%s������ ��Ÿ���� �Է��ϼ���\n", players[count].fullname);
		scanf("%d", &players[count].hits);
		printf("%s������ ���ݼ��� �Է��ϼ���\n", players[count].fullname);
		scanf("%d", &players[count].walks);
		printf("%s������ Ÿ���� �Է��ϼ���\n", players[count].fullname);
		scanf("%d", &players[count].RBIs);
		//scanf("%c", empty);
		
		if (count < BACKNUMBER)
		{
			while (getchar() != '\n')
				continue;
			count++;
			puts("�ٸ� ������ �̸��� �Է��ϼ���.");
		}
	}

	for (int i = 0; i < count; i++)
	{
		players[i].battingAverage = (float)players[i].hits / (float)players[i].atBats;
	}

	if (count > 0)
	{
		puts("(���ȣ)�������� Ÿ��");
		for (index = 0; index < count; index++)
		{
			printf("%d %s\t : %f\n", index, players[index].fullname, players[index].battingAverage);
			
		}
		for (int i = filecount; i < count; i++)
		{
			fwrite(&players[filecount], size, 1, player);
			filecount++;
		}
	}
	else
		puts("�������� ������ �����ϴ�.\n");

	puts("��.\n");
	fclose(player);

	return 0;
}