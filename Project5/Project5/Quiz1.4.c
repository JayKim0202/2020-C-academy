//상품 구조체 Item이 정의되어 있습니다. 다음 소스 코드를 완성하여 "한정팜"이 출력되게 만드세요.

#include <stdio.h>
#include <stdbool.h>

struct Item {
	char name[100];
	int price;
	bool limited;
};

int main()
{
	struct Item item1 = { "베를린 필하모닉 베토벤 교향곡 전집", 100000, false };

	
	struct Item* ptr;
	ptr = &item1;


	ptr->limited = true;

	if (ptr->limited == true)
		printf("한정판\n");
	else
		printf("일반판\n");

	return 0;
}