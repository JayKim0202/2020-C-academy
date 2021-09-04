//도서정보 관리(구조체) 제목, 저자, 가격, 출판사
//최대 10권 저장
//입력함수만들기
//출력함수만들기(입력함수랑 따로)
//전체 입력한 권수 출력
//가격이 가장 비싼 도서명 출력
//전체 가격 합계, 평균
//메뉴화(번호로 선택)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct informationOfBooks {
	char title[100];
	char author[100];
	int price;
	char publisher[100];
} IOB;

IOB book1()
{
	IOB book1;

	strcpy(book1.title, "코스모스");
	strcpy(book1.author, "칼세이건 저/홍승수 역");
	book1.price = 16650;
	strcpy(book1.publisher, "사이언스북스");

	return book1;
}

IOB book2()
{
	IOB book2;

	strcpy(book2.title, "정재승의 과학콘서트");
	strcpy(book2.author, "정재승");
	book2.price = 15120;
	strcpy(book2.publisher, "어크로스");

	return book2;
}

IOB book3()
{
	IOB book3;

	strcpy(book3.title, "아이, 로봇");
	strcpy(book3.author, "아이작 아시모프 저/김옥수 역");
	book3.price = 11700;
	strcpy(book3.publisher, "우리교육");

	return book3;
}

IOB book4()
{
	IOB book4;

	strcpy(book4.title, "마션");
	strcpy(book4.author, "앤디 위어 저/박아람 역");
	book4.price = 13500;
	strcpy(book4.publisher, "알에이치코리아(RHK)");

	return book4;
}

IOB book5()
{
	IOB book5;

	strcpy(book5.title, "아이 엠 넘버 포");
	strcpy(book5.author, "피타커스 로어 저/이수영 역");
	book5.price = 11520;
	strcpy(book5.publisher, "세계사");

	return book5;
}

IOB book6()
{
	IOB book6;

	strcpy(book6.title, "아이 엠 넘버 포 2");
	strcpy(book6.author, "피타커스 로어 저/이수영 역");
	book6.price = 11520;
	strcpy(book6.publisher, "세계사");

	return book6;
}

IOB book7()
{
	IOB book7;

	strcpy(book7.title, "아이 엠 넘버 포 3");
	strcpy(book7.author, "피타커스 로어 저/이수영 역");
	book7.price = 11520;
	strcpy(book7.publisher, "세계사");

	return book7;
}

IOB book8()
{
	IOB book8;

	strcpy(book8.title, "아이 엠 넘버 포 4");
	strcpy(book8.author, "피타커스 로어 저/이수영 역");
	book8.price = 11520;
	strcpy(book8.publisher, "세계사");

	return book8;
}

IOB book9()
{
	IOB book9;

	strcpy(book9.title, "아이 엠 넘버 포 5");
	strcpy(book9.author, "피타커스 로어 저/이수영 역");
	book9.price = 11520;
	strcpy(book9.publisher, "세계사");

	return book9;
}

IOB book10()
{
	IOB book10;

	strcpy(book10.title, "아이 엠 넘버 포 6");
	strcpy(book10.author, "피타커스 로어 저/이수영 역");
	book10.price = 11520;
	strcpy(book10.publisher, "세계사");

	return book10;
}

int main()
{
	char bookName[100];
	char button;
	int count = 0;
	char empty;
	int totalPrice = 0;
	int averagePrice = 0;
	int price[30] = { 0 };
	int i = 0;
	int mostExpensive;
	char mostExpensiveBookName[100];
	int num[12] = { 0 };
	int j = 0;

	IOB b1 = book1();
	IOB b2 = book2();
	IOB b3 = book3();
	IOB b4 = book4();
	IOB b5 = book5();
	IOB b6 = book6();
	IOB b7 = book7();
	IOB b8 = book8();
	IOB b9 = book9();
	IOB b10 = book10();

	printf("검색 가능 도서\n");
	printf("『%s』 ", b1.title);
	printf("『%s』 ", b2.title);
	printf("『%s』 ", b3.title);
	printf("『%s』 ", b4.title);
	printf("『%s』 ", b5.title);
	printf("『%s』 ", b6.title);
	printf("『%s』 ", b7.title);
	printf("『%s』 ", b8.title);
	printf("『%s』 ", b9.title);
	printf("『%s』 ", b10.title);

	while (1)
	{
		while (1)
		{
			printf("\n\n\n검색할 도서의 제목을 입력하세요: ");
			gets(bookName);
			/*if (bookName == b6.title || bookName == b7.title || bookName == b8.title || bookName == b9.title || bookName == b10.title)
			{
				scanf("%c", empty);
			}*/
			
			num[1] = strcmp(bookName, b1.title);
			if (num[1] == 0)
				num[1] = 1;
			else
				num[1] = 0;
			
			num[2] = strcmp(bookName, b2.title);
			if (num[2] == 0)
				num[2] = 2;
			else
				num[2] = 0;
			
			num[3] = strcmp(bookName, b3.title);
			if (num[3] == 0)
				num[3] = 3;
			else
				num[3] = 0;

			num[4] = strcmp(bookName, b4.title);
			if (num[4] == 0)
				num[4] = 4;
			else
				num[4] = 0;

			num[5] = strcmp(bookName, b5.title);
			if (num[5] == 0)
				num[5] = 5;
			else
				num[5] = 0;

			num[6] = strcmp(bookName, b6.title);
			if (num[6] == 0)
				num[6] = 6;
			else
				num[6] = 0;

			num[7] = strcmp(bookName, b7.title);
			if (num[7] == 0)
				num[7] = 7;
			else
				num[7] = 0;
			
			num[8] = strcmp(bookName, b8.title);
			if (num[8] == 0)
				num[8] = 8;
			else
				num[8] = 0;

			num[9] = strcmp(bookName, b9.title);
			if (num[9] == 0)
				num[9] = 9;
			else
				num[9] = 0;

			num[10] = strcmp(bookName, b10.title);
			if (num[10] == 0)
				num[10] = 10;
			else
				num[10] = 0;

			if (num[1] == 1)
			{
				printf("도서명 : 『%s』\n", b1.title);
				printf("저자 : %s\n", b1.author);
				printf("가격 : %d원\n", b1.price);
				printf("출판사 : %s\n", b1.publisher);
				totalPrice += b1.price;
				price[i] = b1.price;
			}
			else if (num[2] == 2)
			{
				printf("도서명 : 『%s』\n", b2.title);
				printf("저자 : %s\n", b2.author);
				printf("가격 : %d원\n", b2.price);
				printf("출판사 : %s\n", b2.publisher);
				totalPrice += b2.price;
				price[i] = b2.price;
			}
			else if (num[3] == 3)
			{
				printf("도서명 : 『%s』\n", b3.title);
				printf("저자 : %s\n", b3.author);
				printf("가격 : %d원\n", b3.price);
				printf("출판사 : %s\n", b3.publisher);
				totalPrice += b3.price;
				price[i] = b3.price;
			}
			else if (num[4] == 4)
			{
				printf("도서명 : 『%s』\n", b4.title);
				printf("저자 : %s\n", b4.author);
				printf("가격 : %d원\n", b4.price);
				printf("출판사 : %s\n", b4.publisher);
				totalPrice += b4.price;
				price[i] = b4.price;
			}
			else if (num[5] == 5)
			{
				printf("도서명 : 『%s』\n", b5.title);
				printf("저자 : %s\n", b5.author);
				printf("가격 : %d원\n", b5.price);
				printf("출판사 : %s\n", b5.publisher);
				totalPrice += b5.price;
				price[i] = b5.price;
			}
			else if (num[6] == 6)
			{
				printf("도서명 : 『%s』\n", b6.title);
				printf("저자 : %s\n", b6.author);
				printf("가격 : %d원\n", b6.price);
				printf("출판사 : %s\n", b6.publisher);
				totalPrice += b6.price;
				price[i] = b6.price;
			}
			else if (num[7] == 7)
			{
				printf("도서명 : 『%s』\n", b7.title);
				printf("저자 : %s\n", b7.author);
				printf("가격 : %d원\n", b7.price);
				printf("출판사 : %s\n", b7.publisher);
				totalPrice += b7.price;
				price[i] = b7.price;
			}
			else if (num[8] == 8)
			{
				printf("도서명 : 『%s』\n", b8.title);
				printf("저자 : %s\n", b8.author);
				printf("가격 : %d원\n", b8.price);
				printf("출판사 : %s\n", b8.publisher);
				totalPrice += b8.price;
				price[i] = b8.price;
			}
			else if (num[9] == 9)
			{
				printf("도서명 : 『%s』\n", b9.title);
				printf("저자 : %s\n", b9.author);
				printf("가격 : %d원\n", b9.price);
				printf("출판사 : %s\n", b9.publisher);
				totalPrice += b9.price;
				price[i] = b9.price;
			}
			else if (num[10] == 10)
			{
				printf("도서명 : 『%s』\n", b10.title);
				printf("저자 : %s\n", b10.author);
				printf("가격 : %d원\n", b10.price);
				printf("출판사 : %s\n", b10.publisher);
				totalPrice += b10.price;
				price[i] = b10.price;
			}
			else
			{
				printf("『%s』에 대한 도서 정보가 없습니다.", bookName);
				count--;
				if (count <= 0)
				{
					count = 0;
				}
			}
			i++;

			printf("\n도서 검색을 종료하시려면 'q'를 누르세요.\n");
			printf("계속하려면 엔터키를 눌러주세요.\n");
			scanf("%c", &button);

			if (button == 'q')
			{
				count++;
				break;
			}
			else
			{
				count++;
			}



		}

		mostExpensive = price[1];

		for (int j = 0; j < i; j++)
		{
			if (mostExpensive < price[j])
			{
				mostExpensive = price[j];
			}
		}

		if (mostExpensive == b1.price)
			strcpy(mostExpensiveBookName, b1.title);
		else if (mostExpensive == b2.price)
			strcpy(mostExpensiveBookName, b2.title);
		else if (mostExpensive == b3.title)
			strcpy(mostExpensiveBookName, b3.title);
		else if (mostExpensive == b4.title)
			strcpy(mostExpensiveBookName, b4.title);
		else if (mostExpensive == b5.title)
			strcpy(mostExpensiveBookName, b5.title);
		else if (mostExpensive == b6.title)
			strcpy(mostExpensiveBookName, b6.title);
		else if (mostExpensive == b7.title)
			strcpy(mostExpensiveBookName, b7.title);
		else if (mostExpensive == b8.title)
			strcpy(mostExpensiveBookName, b8.title);
		else if (mostExpensive == b9.title)
			strcpy(mostExpensiveBookName, b9.title);
		else if (mostExpensive == b10.title)
			strcpy(mostExpensiveBookName, b10.title);

		averagePrice = totalPrice / count;

		printf("\n\n검색 도서 권수 : %d 권\n", count);
		printf("가장 비싼 도서 : %s\n", mostExpensiveBookName);
		printf("검색 도서 전권 가격 : %d원\n", totalPrice);
		printf("검색 도서 전권 가격 평균 : %d원\n", averagePrice);

		printf("프로그램을 종료하시겠습니까?(y/n)");
		scanf("%c", &empty);
		scanf("%c", &button);
		scanf("%c", &empty);

		if (button == 'y')
			break;
	}
	return 0;
}