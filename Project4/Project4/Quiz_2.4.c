//표준 입려긍로 1과 7 사이의 숫자와 길이 30 이하의 문자열이 입력됩니다. 다음 소스 코드를 완성하여 입력된 숫자의 서수 줄임말과 입력된 문자열이 출력되게 만드세요.

#include <stdio.h>

int main()
{
	int number;
	char name[31], result[40];
	
	printf("숫자와 이름을 입력하세요: ");
	scanf("%d", &number);
	scanf("%s", &name);

	if (number == 1)
		sprintf(result, "%dst %s", number, name);
	else if (number == 2)
		sprintf(result, "%dnd %s", number, name);
	else if (number == 3)
		sprintf(result, "%drd %s", number, name);
	else
		sprintf(result, "%dth %s", number, name);

	printf("%s\n", result);

	return 0;
}