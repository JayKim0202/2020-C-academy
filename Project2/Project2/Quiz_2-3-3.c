#include <stdio.h>

int main()
{
	printf("다음 중 switch로 판별할 수 없는 자료형을 모두 고르세요.\n");
	printf("a. float\n");
	printf("b. int\n");
	printf("c. long long\n");
	printf("d. char\n");
	printf("e. double\n");

	char ans1;
	char ans2;
	int count = 0;

	scanf("%c", &ans1);
	scanf("%c", &ans2);
	scanf("%c", &ans2);
	
	switch (ans1)
	{
	case 'a':
		count++;
		break;
	case 'b':
		break;
	case 'c':
		break;
	case 'd':
		break;
	case 'e':
		count++;
		break;
	default:
		printf("a,b,c,d,e 중 선택하시오.\n");
		break;
	}

	switch (ans2)
	{
	case 'a':
		count++;
		break;
	case 'b':
		break;
	case 'c':
		break;
	case 'd':
		break;
	case 'e':
		count++;
		break;
	default:
		printf("a,b,c,d,e 중 선택하시오.\n");
		break;
	}

	if (count == 2)
		printf("정답입니다.\n");
	else
		printf("오답입니다.\n");

	return 0;
}