#include <stdio.h>

int main()
{
	char c1 = 'a';				//���� a �Ҵ�
	char c2 = 'b';				//���� b �Ҵ�
	char linefeed1 = '\n';		//����� \n�Ҵ�
	char linefeed2 = '\t';		//����� \t�Ҵ�

	printf("%c%c%c%c", c1, linefeed1, c2, linefeed1);	//����ڵ� %c�� ����� �� ����
	printf("%c%c%C%C", c1, linefeed2, c2, linefeed1);

	return 0;
}