//다음 소스 코드를 완성하여 20.500000, "false"가 각 줄에 출력되게 만드세요.

#include <stdio.h>
#include <stdbool.h>

float getArmor()
{
	return 20.5f;
}

bool hasSlowSkill()
{
	return false;
}

int main()
{
	float armor;
	bool slow;

	armor = getArmor();
	slow = hasSlowSkill();

	printf("%f\n", armor);
	printf("%s\n", slow == true ? "true" : "false");

	return 0;
}