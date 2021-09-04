//표준 입력으로 게임 캐릭터의 마나와 이동 속도가 정수로 입력됩니다. 다음 소스 코드를 완성하여 마나와 이동 속도가 각 줄에 출력되게 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stats {
	float health;
	float helthRegen;
	unsigned int mana;
	float manaRegen;
	float range;
	float attackDamage;
	float armor;
	float attackSpeed;
	float magicResist;
	unsigned int movementSpeed;
};

int main()
{
	void* ptr = malloc(sizeof(struct Stats));
	struct Stats st;

	scanf("%u %u", &st.mana, &st.movementSpeed);

	memcpy(ptr, &st, sizeof(struct Stats));
	st.mana = 0;
	st.movementSpeed = 0;

	printf("%d\n", ((struct Stats*)ptr)->mana);
	printf("%d\n", ((struct Stats*)ptr)->movementSpeed);


	free(ptr);

	return 0;
}