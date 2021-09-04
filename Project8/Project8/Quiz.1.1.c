/*1.b,d
2.c
3.e
4.d
5.c
*/

//다음 소스 코드를 완성하여 주민등록번호를 포한한 인적 정보가 출력되게 만드세요.

#include <stdio.h>

#define DEBUG
#define DEBUG_LEVEL 2

struct Person {
	char name[20];
	int age;
	char address[100];
#if DEBUG_LEVEL >= 2 && defined DEBUG
	char residentRefistrationNumber[15];		//주민등록번호
#endif
};

int main()
{
	struct Person p1 = {
		"홍길동",
		30,
		"서울시 용산구 한남동",
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