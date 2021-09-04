/*
ex) 4 Jessie Joybat 5 2 1 1

등번호는 0 ~ 18까지 범위 제한

등번호(back number) 이름(first name, last name) 타수(at bats) 안타(hits) 볼넷(walks) 타점(RBIs: runs batted in)

구조체 -> 선수의 이름, 선수의 성씨, 타수, 안타, 볼넷, 타점, 타율(나중에 계산한다)
선수의 등번호를 배열 인덱스로 사용할 수 있다.

각 선수에 대해 누계 유지

타율(betting average = 안타(홈런포함) / 타수

선수들의 개개인의 누적 데이터와 틴 전체 통계 표시
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
		fputs("baseball_players.bin 파일을 열 수 없습니다.\n", stderr);
		exit(1);
	}

	rewind(player);

	while (count < BACKNUMBER && fread(&players[count], size, 1, player) == 1)
	{
		if (count == 0)
			puts("선수 정보");
		printf("%s\t타수: %d 안타: %d 볼넷: %d 타점: %d\n",
			players[count].fullname, players[count].atBats, players[count].hits, players[count].walks, players[count].RBIs);
		count++;
	}

	filecount = count;
	if (count == BACKNUMBER)
	{
		fputs("baseball_players.bin 파일이 가득 찾다.", stderr);
		exit(2);
	}

	puts("끝내려면 라인의 시작 위치에 [enter] 키를 누르세요.");
	puts("선수의 이름(성까지)을 입력하세요");
	while (count < BACKNUMBER && gets(players[count].fullname) != NULL && players[count].fullname[0] != '\0')
	{
		printf("%s선수의 타수를 입력하세요\n", players[count].fullname);
		scanf("%d", &players[count].atBats);
		printf("%s선수의 안타수를 입력하세요\n", players[count].fullname);
		scanf("%d", &players[count].hits);
		printf("%s선수의 볼넷수를 입력하세요\n", players[count].fullname);
		scanf("%d", &players[count].walks);
		printf("%s선수의 타점을 입력하세요\n", players[count].fullname);
		scanf("%d", &players[count].RBIs);
		//scanf("%c", empty);
		
		if (count < BACKNUMBER)
		{
			while (getchar() != '\n')
				continue;
			count++;
			puts("다른 선수의 이름을 입력하세요.");
		}
	}

	for (int i = 0; i < count; i++)
	{
		players[i].battingAverage = (float)players[i].hits / (float)players[i].atBats;
	}

	if (count > 0)
	{
		puts("(등번호)선수들의 타율");
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
		puts("선수들의 정보가 없습니다.\n");

	puts("끝.\n");
	fclose(player);

	return 0;
}