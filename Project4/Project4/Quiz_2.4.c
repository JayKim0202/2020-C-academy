//ǥ�� �Է���� 1�� 7 ������ ���ڿ� ���� 30 ������ ���ڿ��� �Էµ˴ϴ�. ���� �ҽ� �ڵ带 �ϼ��Ͽ� �Էµ� ������ ���� ���Ӹ��� �Էµ� ���ڿ��� ��µǰ� ���弼��.

#include <stdio.h>

int main()
{
	int number;
	char name[31], result[40];
	
	printf("���ڿ� �̸��� �Է��ϼ���: ");
	scanf("%d", &number);
	scanf("%s", &name);

	if (number == 1)
		sprintf(result, "%dst %s", number, name);
	else if (number == 2)
		sprintf(result, "%dnd %s", number, name);
	else if (number == 3)
		sprintf(result, "%drd %s", number, name);
	else
		sprintf(result, "%dth %s", number, name);

	printf("%s\n", result);

	return 0;
}