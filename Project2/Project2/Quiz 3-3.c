#include <stdio.h>

int main()
{
	/*ǥ�� �Է����� ����(�� ����)�� �Էµ˴ϴ�. ����ī�� �ý��ۿ��� �ó����� ����� ������ ������ �� ���̿� �°� ����� ������ ��
	�ܾ��� ��µǰ� ���弼��.(if, else if ���), ���� ����ī�忡�� 10,000���� ����ֽ��ϴ�.
	
	1.���(�ʵ��л�, �� 7�� �̻� 12�� ����): 450��
	2.û�ҳ�(��-����л�, �� 13�� �̻� 18�� ����): 720��
	3.�(�Ϲ�, �� 19�� �̻�):1,200��*/

	int balance1 = 10000;
	int balance2;
	int age;

	scanf("%d", &age);

	if (age <= 12 && age >= 7)
	{
		balance2 = balance1 - 450;
	}
	else if (age <= 18 && age >= 13)
	{
		balance2 = balance1 - 720;
	}
	else if (age >= 19)
	{
		balance2 = balance1 - 1200;
	}
	
	printf("%d\n", balance2);

	return 0;
}