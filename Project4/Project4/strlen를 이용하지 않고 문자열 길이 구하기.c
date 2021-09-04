//strlen를 이용하지 않고, 글자의 숫자를 세는 코드 생성
//Hint : NULL

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* s1 = malloc(sizeof(char) * 50);
	int count = 0;
	int i = 0;

	gets(s1);

	// s1[i]가 NULL이 아닐 때, count + 1
	while (s1[i] != NULL)
	{
		if (s1[i] != NULL)
		{
			count += 1;
		}
		i++;
	}

	printf("%d", count);

	free(s1);

	return 0;
}