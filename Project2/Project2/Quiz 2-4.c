#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� ���ڰ� �Էµ˴ϴ�. �Էµ� ���ڱ� a�̸� "a�Դϴ�."�� ����ϰ�, a�� �ƴϸ� "a�� �ƴմϴ�."�� ����ϴ� ���ѱ׷��� ���弼��.*/

	char c1;

	scanf("%c", &c1);

	if (c1 == 'a')
		printf("a�Դϴ�.\n");
	else
		printf("a�� �ƴմϴ�.\n");

	return 0;
}