#include <stdio.h>

int main()
{
	char linefeed1 = '\n'; //����� \n�Ҵ�
	char linefeed2 = '\t'; //����� \t�Ҵ�

	printf("%d 0x%x\n", linefeed1, linefeed1); //10 0xa: ������� ASCII�ڵ� ���
	printf("%d 0x%x\n", linefeed2, linefeed2); //9 0x9: ������� ASCII�ڵ� ���
	
}