//다음 소스 코드를 완성하여 아무 정보도 출력되지 않게 만드세요(함수 안의 인수만 채우면 됩니다).

#include <stdio.h>
#include <string.h>

struct Person {
	char name[20];
	int age;
	char address[100];
};

int main()
{
	struct Person p1;

	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");

	memset(&p1, 0, sizeof(struct Person));

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);

	return 0;
}