#include <stdio.h>

int main()
{
	// void* �������̸�; == ��� ��������
	int num1 = 10;
	char c1 = 'a';
	int* numPtr1 = &num1;
	int* cPtr1 = &c1;

	void* ptr; //void ������ ����
			   
	//������ �ڷ����� �޶� ������ ��� �߻����� ����
	ptr = numPtr1; //void �����Ϳ� int ������ ����
	ptr = cPtr1;   //viod �����Ϳ� char ������ ����

	//������ �ڷ����� �޶� ������ ��� �߻����� ����
	numPtr1 = ptr; //int �����Ϳ� void ������ ����
	cPtr1 = ptr;   //char �����Ϳ� void ������ ����

	return 0;
}