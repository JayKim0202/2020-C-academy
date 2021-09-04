#include <stdio.h>

int main()
{
	char ans1;
	char ans2;
	int count = 0;

	printf("다음 중 switch로 판별할 수 없는 자료형을 모두 고르세요.\n");
	printf("a. float\n");
	printf("b. int\n");
	printf("c. long long\n");
	printf("d. char\n");
	printf("e. double\n");

	scanf("%c", &ans1);
	scanf("%c", &ans2);
	scanf("%c", &ans2);

	switch (ans1)
	{
	case 'a':
		printf("정답, ");
		count++;
		break;
	case 'b':
		printf("오답, ");
		break;
	case 'c':
		printf("오답, ");
		break;
	case 'd':
		printf("오답, ");
		break;
	case 'e':
		printf("정답, ");
		count++;
		break;
	default:
		printf("a,b,c,d,e 중에서만 선택하시오.");
		break;
	}

	switch (ans2)
	{
	case 'a':
		printf("정답\n");
		count++;
		break;
	case 'b':
		printf("오답\n");
		break;
	case 'c':
		printf("오답\n");
		break;
	case 'd':
		printf("오답\n");
		break;
	case 'e':
		printf("정답\n");
		count++;
		break;
	default:
		printf("a,b,c,d,e 중에서만 선택하시오.");
		break;
	}

	if (count == 2)
		printf("정답입니다.");
	else
		printf("오답입니다.");

	return 0;
}