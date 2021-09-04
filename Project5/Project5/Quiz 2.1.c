/*1.d
2.c
3.b
4.d*/

//다음 소스 코드를 완성하여 334 1.240000이 출력되게 만드세요.

#include <stdio.h>
#include <string.h>

struct Stats {
	float health;
	float healthRegen;
	unsigned int mana;
	float manaRegen;
	float attackDamage;
	float armor;
	float attackSpeed;
	float magicResist;
	unsigned int movementSpeed;
};

struct champion {
	char name[20];
	struct Stats stats;
	float abilityPower;
};

int main()
{

	struct champion lux;

	strcpy(lux.name, "Lux");
	lux.stats.health = 477.72f;
	lux.stats.healthRegen = 1.08f;
	lux.stats.mana = 334;
	lux.stats.manaRegen = 1.24f;
	lux.stats.attackDamage = 55.55f;
	lux.stats.attackSpeed = 0.625f;
	lux.stats.armor = 18.72f;
	lux.stats.movementSpeed = 330;
	lux.abilityPower = 0;

	printf("%u %f\n", lux.stats.mana, lux.stats.manaRegen);

	return 0;
}