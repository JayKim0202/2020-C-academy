//�������� ����(����ü) ����, ����, ����, ���ǻ�
//�ִ� 10�� ����
//�Է��Լ������
//����Լ������(�Է��Լ��� ����)
//��ü �Է��� �Ǽ� ���
//������ ���� ��� ������ ���
//��ü ���� �հ�, ���
//�޴�ȭ(��ȣ�� ����)

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

	strcpy(book1.title, "�ڽ���");
	strcpy(book1.author, "Į���̰� ��/ȫ�¼� ��");
	book1.price = 16650;
	strcpy(book1.publisher, "���̾𽺺Ͻ�");

	return book1;
}

IOB book2()
{
	IOB book2;

	strcpy(book2.title, "������� �����ܼ�Ʈ");
	strcpy(book2.author, "�����");
	book2.price = 15120;
	strcpy(book2.publisher, "��ũ�ν�");

	return book2;
}

IOB book3()
{
	IOB book3;

	strcpy(book3.title, "����, �κ�");
	strcpy(book3.author, "������ �ƽø��� ��/����� ��");
	book3.price = 11700;
	strcpy(book3.publisher, "�츮����");

	return book3;
}

IOB book4()
{
	IOB book4;

	strcpy(book4.title, "����");
	strcpy(book4.author, "�ص� ���� ��/�ھƶ� ��");
	book4.price = 13500;
	strcpy(book4.publisher, "�˿���ġ�ڸ���(RHK)");

	return book4;
}

IOB book5()
{
	IOB book5;

	strcpy(book5.title, "���� �� �ѹ� ��");
	strcpy(book5.author, "��ŸĿ�� �ξ� ��/�̼��� ��");
	book5.price = 11520;
	strcpy(book5.publisher, "�����");

	return book5;
}

IOB book6()
{
	IOB book6;

	strcpy(book6.title, "���� �� �ѹ� �� 2");
	strcpy(book6.author, "��ŸĿ�� �ξ� ��/�̼��� ��");
	book6.price = 11520;
	strcpy(book6.publisher, "�����");

	return book6;
}

IOB book7()
{
	IOB book7;

	strcpy(book7.title, "���� �� �ѹ� �� 3");
	strcpy(book7.author, "��ŸĿ�� �ξ� ��/�̼��� ��");
	book7.price = 11520;
	strcpy(book7.publisher, "�����");

	return book7;
}

IOB book8()
{
	IOB book8;

	strcpy(book8.title, "���� �� �ѹ� �� 4");
	strcpy(book8.author, "��ŸĿ�� �ξ� ��/�̼��� ��");
	book8.price = 11520;
	strcpy(book8.publisher, "�����");

	return book8;
}

IOB book9()
{
	IOB book9;

	strcpy(book9.title, "���� �� �ѹ� �� 5");
	strcpy(book9.author, "��ŸĿ�� �ξ� ��/�̼��� ��");
	book9.price = 11520;
	strcpy(book9.publisher, "�����");

	return book9;
}

IOB book10()
{
	IOB book10;

	strcpy(book10.title, "���� �� �ѹ� �� 6");
	strcpy(book10.author, "��ŸĿ�� �ξ� ��/�̼��� ��");
	book10.price = 11520;
	strcpy(book10.publisher, "�����");

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

	printf("�˻� ���� ����\n");
	printf("��%s�� ", b1.title);
	printf("��%s�� ", b2.title);
	printf("��%s�� ", b3.title);
	printf("��%s�� ", b4.title);
	printf("��%s�� ", b5.title);
	printf("��%s�� ", b6.title);
	printf("��%s�� ", b7.title);
	printf("��%s�� ", b8.title);
	printf("��%s�� ", b9.title);
	printf("��%s�� ", b10.title);

	while (1)
	{
		while (1)
		{
			printf("\n\n\n�˻��� ������ ������ �Է��ϼ���: ");
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
				printf("������ : ��%s��\n", b1.title);
				printf("���� : %s\n", b1.author);
				printf("���� : %d��\n", b1.price);
				printf("���ǻ� : %s\n", b1.publisher);
				totalPrice += b1.price;
				price[i] = b1.price;
			}
			else if (num[2] == 2)
			{
				printf("������ : ��%s��\n", b2.title);
				printf("���� : %s\n", b2.author);
				printf("���� : %d��\n", b2.price);
				printf("���ǻ� : %s\n", b2.publisher);
				totalPrice += b2.price;
				price[i] = b2.price;
			}
			else if (num[3] == 3)
			{
				printf("������ : ��%s��\n", b3.title);
				printf("���� : %s\n", b3.author);
				printf("���� : %d��\n", b3.price);
				printf("���ǻ� : %s\n", b3.publisher);
				totalPrice += b3.price;
				price[i] = b3.price;
			}
			else if (num[4] == 4)
			{
				printf("������ : ��%s��\n", b4.title);
				printf("���� : %s\n", b4.author);
				printf("���� : %d��\n", b4.price);
				printf("���ǻ� : %s\n", b4.publisher);
				totalPrice += b4.price;
				price[i] = b4.price;
			}
			else if (num[5] == 5)
			{
				printf("������ : ��%s��\n", b5.title);
				printf("���� : %s\n", b5.author);
				printf("���� : %d��\n", b5.price);
				printf("���ǻ� : %s\n", b5.publisher);
				totalPrice += b5.price;
				price[i] = b5.price;
			}
			else if (num[6] == 6)
			{
				printf("������ : ��%s��\n", b6.title);
				printf("���� : %s\n", b6.author);
				printf("���� : %d��\n", b6.price);
				printf("���ǻ� : %s\n", b6.publisher);
				totalPrice += b6.price;
				price[i] = b6.price;
			}
			else if (num[7] == 7)
			{
				printf("������ : ��%s��\n", b7.title);
				printf("���� : %s\n", b7.author);
				printf("���� : %d��\n", b7.price);
				printf("���ǻ� : %s\n", b7.publisher);
				totalPrice += b7.price;
				price[i] = b7.price;
			}
			else if (num[8] == 8)
			{
				printf("������ : ��%s��\n", b8.title);
				printf("���� : %s\n", b8.author);
				printf("���� : %d��\n", b8.price);
				printf("���ǻ� : %s\n", b8.publisher);
				totalPrice += b8.price;
				price[i] = b8.price;
			}
			else if (num[9] == 9)
			{
				printf("������ : ��%s��\n", b9.title);
				printf("���� : %s\n", b9.author);
				printf("���� : %d��\n", b9.price);
				printf("���ǻ� : %s\n", b9.publisher);
				totalPrice += b9.price;
				price[i] = b9.price;
			}
			else if (num[10] == 10)
			{
				printf("������ : ��%s��\n", b10.title);
				printf("���� : %s\n", b10.author);
				printf("���� : %d��\n", b10.price);
				printf("���ǻ� : %s\n", b10.publisher);
				totalPrice += b10.price;
				price[i] = b10.price;
			}
			else
			{
				printf("��%s���� ���� ���� ������ �����ϴ�.", bookName);
				count--;
				if (count <= 0)
				{
					count = 0;
				}
			}
			i++;

			printf("\n���� �˻��� �����Ͻ÷��� 'q'�� ��������.\n");
			printf("����Ϸ��� ����Ű�� �����ּ���.\n");
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

		printf("\n\n�˻� ���� �Ǽ� : %d ��\n", count);
		printf("���� ��� ���� : %s\n", mostExpensiveBookName);
		printf("�˻� ���� ���� ���� : %d��\n", totalPrice);
		printf("�˻� ���� ���� ���� ��� : %d��\n", averagePrice);

		printf("���α׷��� �����Ͻðڽ��ϱ�?(y/n)");
		scanf("%c", &empty);
		scanf("%c", &button);
		scanf("%c", &empty);

		if (button == 'y')
			break;
	}
	return 0;
}