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

	strcpy(book1->title, "�ڽ���");
	strcpy(book1->author, "Į���̰� ��/ȫ�¼� ��");
	book1->price = 16650;
	strcpy(book1->publisher, "���̾𽺺Ͻ�");

	return *book1;
}


int main()
{
	char *bookName = malloc(sizeof(char) * 100);
	char button;
	int bookNum = 0;

	IOB b1 = book1();

	printf("�˻� ���� ����\n");
	printf("��%s�� ", b1.title);


		printf("\n\n\n�˻��� ������ ������ �Է��ϼ���: ");
		gets(bookName);

		if (bookName == b1.title)
		{
			bookNum = 1;
		}

		if (bookNum == 1)
		{
			printf("������ : ��%s��\n", b1.title);
			printf("���� : %s\n", b1.author);
			printf("���� : %d��\n", b1.price);
			printf("���ǻ� : %s\n", b1.publisher);
		}
		
		else
		{
			printf("��%s���� ���� ���� ������ �����ϴ�.", bookName);
		}

	return 0;
}