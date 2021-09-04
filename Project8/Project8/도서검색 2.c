#define _CRT_SECURE_NO_WANINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct informationOfBooks {
	char title[100];
	char author[100];
	int price;
	char publisher[100];
} IOB;

IOB book1()
{
	IOB *book1 = malloc(sizeof(IOB));

	strcpy(book1->title, "코스모스");
	strcpy(book1->author, "칼세이건 저/홍승수 역");
	book1->price = 16650;
	strcpy(book1->publisher, "사이언스북스");

	return *book1;
}


int main()
{
	char *bookName = malloc(sizeof(char) * 100);
	char button;
	int bookNum = 0;

	IOB b1 = book1();

	printf("검색 가능 도서\n");
	printf("『%s』 ", b1.title);


		printf("\n\n\n검색할 도서의 제목을 입력하세요: ");
		gets(bookName);

		if (bookName == b1.title)
		{
			bookNum = 1;
		}

		if (bookNum == 1)
		{
			printf("도서명 : 『%s』\n", b1.title);
			printf("저자 : %s\n", b1.author);
			printf("가격 : %d원\n", b1.price);
			printf("출판사 : %s\n", b1.publisher);
		}
		
		else
		{
			printf("『%s』에 대한 도서 정보가 없습니다.", bookName);
		}

	return 0;
}