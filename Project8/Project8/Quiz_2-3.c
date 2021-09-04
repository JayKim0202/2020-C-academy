//표준 입력으로 길이 30 이하의 문자열과 정수가 입력됩니다. 다음 소스 코드를 완성하여 입력된 문자열과 숫자를 조합한 문자열을 stdout에 쓰도록 만드세요.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char name[31];
	int order;

	scanf("%s %d", name, &order);

	FILE* fp = stdout;

	fprintf(fp, "The %dth Satellite of Jupiter: %s", order, name);

	fclose(fp);

	return 0;
}