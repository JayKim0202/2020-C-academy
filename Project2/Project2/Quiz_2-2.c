#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� ���� 'f', 'c', 'p' �� �ϳ��� �Էµ˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ���ڰ� 'f'���
	"ȯŸ", 'c'��� "�ݶ�", 'p'��� "��ī������Ʈ"�� ����ϰ�, �ƹ� ���ڿ��� �ش����� ������ "�Ǹ����� �ʴ� �޴�"�� ��µǰ� ���弼��.*/
	char menu;

	scanf("%c", &menu);

	switch (menu)
	{
	case 'f':
		printf("ȯŸ\n");
		break;
	case 'c':
		printf("�ݶ�\n");
		break;
	case 'p':
		printf("��ī������Ʈ\n");
		break;
	default:
		printf("�Ǹ����� �ʴ� �޴�");
		break;
	}

	return 0;
}