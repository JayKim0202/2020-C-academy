#include <stdio.h>

int main()
{
	char c1 = 97;     //a�� ASCII �ڵ�(10����) �� 97 ����
	char c2 = 98;     //b�� ASCII �ڵ�(10����) �� 98 ����

	//char�� %c�� ����ϸ� ���ڰ� ��µǰ�, %d�� ����ϸ� �������� ��µ�
	printf("%c, %d\n", c1, c1); //a, 97
	printf("%c, %c\n", c2, c2); //a, 98

	return 0;
}