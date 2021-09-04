#include <stdio.h>

int main()
{
	char name0[30];
	char name1[30];
	char name2[30];
	int age0;
	int age1;
	int age2;
	char address0[100];
	char address1[100];
	char address2[100];
	int x;

	printf("이름, 나이, 주소 순으로 입력하시오.\n");
	gets(name0);
	scanf("%d", &age0);
	scanf("%d", &x);				//숫자 + 문자를 입력시 숫자 뒤에 임시변수를 넣어줘야함.
	gets(address0);
	printf("이름, 나이, 주소 순으로 입력하시오.\n");
	gets(name1);
	scanf("%d", &age1);
	scanf("%d", &x);
	gets(address1);
	printf("이름, 나이, 주소 순으로 입력하시오.\n");
	gets(name2);
	scanf("%d", &age2);
	scanf("%d", &x);
	gets(address2);


	printf("이름: %s 나이: %d 주소: %s ", name0, age0, address0);
	printf("이름: %s 나이: %d 주소: %s ", name1, age1, address1);
	printf("이름: %s 나이: %d 주소: %s ", name2, age2, address2);

	return 0;
}