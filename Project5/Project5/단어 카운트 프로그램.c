#include <stdio.h>
#include <ctype.h> //isspace()�� ����ϱ� ����
#include <stdbool.h> //bool, true, false�� ����ϱ� ����
#define STOP '|'

int main(void)
{
	char c;					//���� ���� ����
	char prev;				//�ٷ� ���� ���� ����
	long n_chars = 0L;		//���ڼ�
	int n_lines = 0;		//���μ�
	int n_words = 0;		//�ܾ��
	int p_lines = 0;		//�ҿ����� ���� ��
	bool inword = false;	//c�� ������ �� �ܾ� �ȿ� ���� ������ true

	printf("�м��� ���� �ؽ�Ʈ�� �Է��Ͻÿ�(�������� |):\n");
	prev = '\n';						//���� ������ �ĺ��ϴ� �� ����Ѵ�.
	while ((c = getchar()) != STOP) //getchar : �ѹ��� == printf("%c", &c);
	{
		n_chars++;			//���ڸ� ī��Ʈ �Ѵ�.
		if (c == '\n')
			n_lines++;		//������ ī��Ʈ �Ѵ�.
		if (!isspace(c) && !inword)					//isspce : �������ڰ� ȭ��Ʈ�����̽�(' ', \n, \t) �����̸� ���� �����Ѵ�.
													//if (inword == false) == if (!inword)
		{
			inword = true;	//�� �ܾ �����Ѵ�.
			n_words++;		//�ܾ ī��Ʈ �Ѵ�.
		}
		if (isspace(c) && inword)					//if (inword == true) == if (inword)
			inword = false;	//�ܾ��� ���� �����ߴ�.
		prev = c;			//������ ���� �����Ѵ�.
	}

	if (prev != '\n')
		p_lines = 1;

	printf("���ڼ� = %d, �ܾ�� = %d, ���μ� = %d,", n_chars, n_words, n_lines);
	printf("�ҿ����� ���μ� = %d", p_lines);

	return 0;
}