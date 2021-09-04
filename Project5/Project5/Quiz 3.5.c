//다음 소스 코드를 완성하여 "명상"이 출력되게 만드세요.

#include <stdio.h>

enum MasterYiSkill {
	AlphaStrike = 1,
	Meditation,
	WujuStlye,
	Highlander
};

int main()
{
	enum MasterYiSkill skill;

	skill = Meditation;

	switch (skill)
	{
	case AlphaStrike:
		printf("일격 필살\n");
		break;
	case Meditation:
		printf("명상\n");
		break;
	case WujuStlye:
		printf("우주류 검술\n");
		break;
	case Highlander:
		printf("최후의 전사\n");
		break;
	default:
		break;
	}

	return 0;
}