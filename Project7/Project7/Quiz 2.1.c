/*1.c
2.d
3.d
4.b*/

//다음 소스 코드를 완성하여 222, 0.679000, 1이 각 줄에 출력되게 만드세요.

#include <stdio.h>
#include <stdbool.h>

int getMana()
{
	return 222;
}

float getAttackSpeed()
{
	return 0.679000;
}

bool isMelee()
{
	return true;
}

int main()
{
	int mana;
	float attackSpeed;
	bool melee;

	mana = getMana();
	attackSpeed = getAttackSpeed();
	melee = isMelee();

	printf("%d\n", mana);
	printf("%f\n", attackSpeed);
	printf("%d\n", melee);

	return 0;
}