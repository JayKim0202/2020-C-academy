/*1.b,d
2.c
3.e
4.d
5.c
*/

//���� �ҽ� �ڵ带 �ϼ��Ͽ� �ֹε�Ϲ�ȣ�� ������ ���� ������ ��µǰ� ���弼��.

#include <stdio.h>

#define DEBUG
#define DEBUG_LEVEL 2

struct Person {
	char name[20];
	int age;
	char address[100];
#if DEBUG_LEVEL >= 2 && defined DEBUG
	char residentRefistrationNumber[15];		//�ֹε�Ϲ�ȣ
#endif
};

int main()
{
	struct Person p1 = {
		"ȫ�浿",
		30,
		"����� ��걸 �ѳ���",
#if DEBUG_LEVEL >= 2 && defined DEBUG
		"860821-1326821"
#endif
	};

#if DEBUG_LEVEL >= 2 && defined DEBUG
	printf("%s %d %s %s\n", p1.name, p1.age, p1.address, p1.residentRefistrationNumber);
#else
	printf("%s %d %s\n", p1.name, p1.age, p1.address);
#endif

	return 0;
}