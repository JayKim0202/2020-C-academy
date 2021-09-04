#include <stdio.h>

int main()
{
	/*표준 입력으로 문자 'f', 'c', 'p' 중 하나가 입력됩니다. 다음 소스 코드를 완성하여 입력된 문자가 'f'라면
	"환타", 'c'라면 "콜라", 'p'라면 "포카리스웨트"를 출력하고, 아무 문자에도 해당하지 않으면 "판매하지 않는 메뉴"가 출력되게 만드세요.*/
	char menu;

	scanf("%c", &menu);

	switch (menu)
	{
	case 'f':
		printf("환타\n");
		break;
	case 'c':
		printf("콜라\n");
		break;
	case 'p':
		printf("포카리스웨트\n");
		break;
	default:
		printf("판매하지 않는 메뉴");
		break;
	}

	return 0;
}