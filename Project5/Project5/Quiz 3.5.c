//���� �ҽ� �ڵ带 �ϼ��Ͽ� "���"�� ��µǰ� ���弼��.

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
		printf("�ϰ� �ʻ�\n");
		break;
	case Meditation:
		printf("���\n");
		break;
	case WujuStlye:
		printf("���ַ� �˼�\n");
		break;
	case Highlander:
		printf("������ ����\n");
		break;
	default:
		break;
	}

	return 0;
}