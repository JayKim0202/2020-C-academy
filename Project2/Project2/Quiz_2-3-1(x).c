#include <stdio.h>

int main()
{
	char ans;

	printf("다음 중 switch로 판별할 수 없는 자료형을 모두 고르세요.\n");
	printf("a. float\n");
	printf("b. int\n");
	printf("c. long long\n");
	printf("d. char\n");
	printf("e. double\n");

	scanf("%c", &ans);

	switch (ans)
	{
	case 'a':
		printf("정답\n");
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
		break;
	}

	return 0;
}