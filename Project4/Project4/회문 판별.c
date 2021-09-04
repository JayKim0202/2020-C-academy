#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	char word[30];				//단어를 저장할 배열
	int length;					//문자열 길이
	bool isPalindrome = true;	//회문 판별 값을 저장할 변수, 초깃값은 true

	printf("단어를 입력하세요: ");
	gets(word);

	length = strlen(word);		//문자열의 길이 구함		length == 글자갯수 + NULL

	//0부터 문자열 길이의 절반만큼 반복
	for (int i = 0; i < length / 2; i++)
	{
		if (word[i] != word[length - 1 - i])
		{
			//회문 아님
			isPalindrome = false;
			break;
		}
	}

	printf("%d\n", isPalindrome); //회문 판결 값 출력

	return 0;
}