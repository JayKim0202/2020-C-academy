#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <Windows.h>

typedef struct member_profile
{
	char ID[1000];
	char passward[1000];
	char name[1000];
	int number;
	struct member_profile* ptr;
}MP_node;

int MENU();
MP_node* memory_alloc();
MP_node* add(MP_node* head);
MP_node* edit(MP_node* head);
MP_node* insert(MP_node* head);
MP_node* delete_node(MP_node* head);
void print(MP_node* head);
void save_file(MP_node* head, int load_count);
MP_node* load_file(MP_node* head);

int main()
{
	MP_node* profile_node;
	int menu = 0;
	profile_node = memory_alloc();
	int load_count = 0;


	while (1)
	{
		menu = MENU();

		switch (menu)
		{
		case 1:
			profile_node = add(profile_node);
			break;
		case 2:
			profile_node = edit(profile_node);
			break;
		case 3:
			profile_node = insert(profile_node);
			break;
		case 4:
			profile_node = delete_node(profile_node);
			break;
		case 5:
			print(profile_node);
			break;
		case 6:
			save_file(profile_node, load_count);
			break;
		case 7:
			profile_node = load_file(profile_node);
			load_count = 1;
			break;
		case 8:
			exit(0);
		}
	}

	return 0;
}

int MENU()
{
	int menu;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;
	
	point.X = 28;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 22; i++)
	{
		printf("-");
	}
	printf("《 Member Profile 》");
	for (int i = 0; i < 22; i++)
	{
		printf("-");
	}

	point.X = 30;
	point.Y = 6;
	SetConsoleCursorPosition(handle, point);
	printf("1.입력");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("2.수정");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("3.삽입");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("4.삭제");
	point.X = 83;
	point.Y = 6;
	SetConsoleCursorPosition(handle, point);
	printf("5.출력");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("6.저장");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("7.로드");
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("8.종료");

	point.X = 28;
	point.Y = 14;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 65; i++)
	{
		printf("-");
	}

	point.X = 90;
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("메뉴를 입력하세요: ");
	scanf("%d", &menu);
	getchar();
	system("cls");

	return menu;
}

MP_node* memory_alloc()
{
	MP_node* temp;
	temp = (MP_node*)malloc(sizeof(MP_node));

	memset(temp->ID, NULL, sizeof(temp->ID));
	memset(temp->passward, NULL, sizeof(temp->passward));
	memset(temp->name, NULL, sizeof(temp->name));
	temp->number = NULL;
	temp->ptr = NULL;

	return temp;
}

MP_node* add(MP_node* head)
{
	MP_node* start;
	MP_node* temp;
	MP_node* print_temp;
	int i = 1;
	print_temp = head;
	start = head;
	temp = memory_alloc();

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 10;
	point.Y = 4;
	SetConsoleCursorPosition(handle, point);
	if (print_temp->ptr != NULL)
	{
		print_temp = print_temp->ptr;
		while (1)
		{
			printf("%d |\tID : %s\tPassWard : %s\t Name : %s\t Phone Number : %d", i, print_temp->ID, print_temp->passward,
				print_temp->name, print_temp->number);
			point.Y++;
			SetConsoleCursorPosition(handle, point);
			print_temp = print_temp->ptr;
			if (print_temp == NULL)
				break;
			i++;
		}
	}

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("┌");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	printf("┐");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("└");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("┘");

	point.X = 50;
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("▶회원 정보 추가◀");
	point.X = 8;
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("ID | ");
	gets(temp->ID);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("비밀번호 | ");
	gets(temp->passward);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("이름 | ");
	gets(temp->name);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("전화번호 | ");
	scanf("%d", &temp->number);
	getchar();

	//로드 전 : 첫번째 노드를 비우고 다음 노드에 입력
	//로드 후 : 로드된 다음 데이터에 입력
	if (head->ptr == NULL)
	{
		head->ptr = temp;
	}
	else
	{
		while (1)
		{
			head = head->ptr;
			if (head->ptr == NULL)
				break;
		}
		head->ptr = temp;
	}
	

	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("회원정보를 추가했습니다.");
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("엔터키를 누르면 메뉴로 돌아갑니다...");
	getchar();
	system("cls");

	return start;
}

MP_node* edit(MP_node* head)
{
	MP_node* start;
	MP_node* new_node;
	MP_node* free_node;
	MP_node* print_temp;
	int i = 1;
	int edit_num = 0;
	int count = 0;
	start = head;
	print_temp = head;
	new_node = memory_alloc();

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 10;
	point.Y = 4;
	SetConsoleCursorPosition(handle, point);
	if (print_temp->ptr != NULL)
	{
		print_temp = print_temp->ptr;
		while (1)
		{
			printf("%d |\tID : %s\tPassWard : %s\t Name : %s\t Phone Number : %d", i, print_temp->ID, print_temp->passward,
				print_temp->name, print_temp->number);
			point.Y++;
			SetConsoleCursorPosition(handle, point);
			print_temp = print_temp->ptr;
			if (print_temp == NULL)
				break;
			i++;
		}
	}

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("┌");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	printf("┐");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("└");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("┘");

	point.X = 9;
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("수정 번호 : ");
	scanf("%d", &edit_num);
	getchar();

	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("ID | ");
	gets(new_node->ID);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("비밀번호 | ");
	gets(new_node->passward);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("이름 | ");
	gets(new_node->name);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("전화번호 | ");
	scanf("%d", &new_node->number);
	getchar();

	while (1)
	{
		if (count == edit_num - 1)
		{
			new_node->ptr = head->ptr->ptr;
			free_node = head->ptr;
			free(free_node);
			head->ptr = new_node;
			break;
		}
		head = head->ptr;
		count++;
	}
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("회원정보를 수정했습니다.\n");
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("엔터키를 누르면 메뉴로 돌아갑니다...");
	getchar();
	system("cls");


	return start;
}

MP_node* insert(MP_node* head)
{
	// 입력된 숫자 다음에 삽입
	MP_node* start;
	MP_node* new_node;
	MP_node* print_temp;
	int i = 1;
	int insert_num = 0;
	int count = 1;
	new_node = memory_alloc();
	start = head;
	print_temp = head;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 10;
	point.Y = 4;
	SetConsoleCursorPosition(handle, point);
	if (print_temp->ptr != NULL)
	{
		print_temp = print_temp->ptr;
		while (1)
		{
			printf("%d |\tID : %s\tPassWard : %s\t Name : %s\t Phone Number : %d", i, print_temp->ID, print_temp->passward,
				print_temp->name, print_temp->number);
			point.Y++;
			SetConsoleCursorPosition(handle, point);
			print_temp = print_temp->ptr;
			if (print_temp == NULL)
				break;
			i++;
		}
	}

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("┌");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	printf("┐");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("└");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("┘");

	point.X = 9;
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("삽입 번호 : ");
	scanf("%d", &insert_num);
	getchar();

	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("ID | ");
	gets(new_node->ID);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("비밀번호 | ");
	gets(new_node->passward);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("이름 | ");
	gets(new_node->name);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("전화번호 | ");
	scanf("%d", &new_node->number);
	getchar();

	head = head->ptr;
	while (1)
	{
		if (count == insert_num)
		{
			new_node->ptr = head->ptr;
			head->ptr = new_node;
			break;
		}
		head = head->ptr;
		count++;
	}
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("회원정보를 삽입했습니다.");
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("엔터키를 누르면 메뉴로 돌아갑니다...");
	getchar();
	system("cls");

	return start;
}

MP_node* delete_node(MP_node* head)
{
	MP_node* start;
	MP_node* free_node;
	MP_node* print_temp;
	int delete_num = 0;
	int count = 0;
	int i = 1;
	start = head;
	print_temp = head;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 10;
	point.Y = 4;
	SetConsoleCursorPosition(handle, point);
	if (print_temp->ptr != NULL)
	{
		print_temp = print_temp->ptr;
		while (1)
		{
			printf("%d |\tID : %s\tPassWard : %s\t Name : %s\t Phone Number : %d", i, print_temp->ID, print_temp->passward,
				print_temp->name, print_temp->number);
			point.Y++;
			SetConsoleCursorPosition(handle, point);
			print_temp = print_temp->ptr;
			if (print_temp == NULL)
				break;
			i++;
		}
	}

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("┌");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	printf("┐");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("└");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("┘");

	point.X = 9;
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("삭제 번호 : ");
	scanf("%d", &delete_num);
	getchar();

	while (1)
	{
		if (count == delete_num - 1)
		{
			free_node = head->ptr;
			head->ptr = head->ptr->ptr;
			free(free_node);
			break;
		}
		head = head->ptr;
		count++;
	}
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("회원정보를 삭제했습니다.");
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("엔터키를 누르면 메뉴로 돌아갑니다...");
	getchar();
	system("cls");

	return start;
}

void print(MP_node* head)
{
	int i = 1;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("┌");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	printf("┐");
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("└");
	for (int i = 0; i < 102; i++)
	{
		printf("─");
	}
	point.X = 111;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	for (int i = 0; i < 15; i++)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("│");
	}
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("┘");

	point.X = 10;
	point.Y = 4;
	SetConsoleCursorPosition(handle, point);
	head = head->ptr;
	while (1)
	{
		printf("%d | 아이디 : %s    비밀번호 : %s    이름 :%s    전화번호 : %d\n", i, head->ID, head->passward, head->name, head->number);
		head = head->ptr;
		i++;
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		if (head == NULL) break;
	}

	point.Y = 20;
	SetConsoleCursorPosition(handle, point);
	printf("엔터키를 누르면 메뉴로 돌아갑니다...");
	getchar();
	system("cls");

	return;
}

void save_file(MP_node* head, int load_count)
{
	FILE* profile;
	char file_name[1000];
	char file_type[100];
	char answer = 0;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	strcpy(file_type, ".bin");

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("파일 이름을 입려하세요 : ");
	gets(file_name);
	strcat(file_name, file_type);

	if ((profile = fopen(&file_name, "r+b")) == NULL)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("파일이 존재하지 않습니다.");
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("파일을 생성하세겠습니까?(Y/N)");
		scanf("%c", &answer);
		getchar();
		system("cls");

		if (answer == 'y')
			profile = fopen(&file_name, "w+b");
		else if(answer == 'n')
		{
			printf("엔터키를 누르면 메뉴로 돌아갑니다...");
			getchar();
			system("cls");
			return;
		}
	}
	else
	{
		if (load_count == 1)
		{
			profile = fopen(&file_name, "w+b");
		}
		else if (load_count == 0)
		{
			profile = fopen(&file_name, "a+b");
		}
	}

	head = head->ptr;
	while (1)
	{
		fwrite(head->ID, strlen(head->ID), 1, profile);
		fprintf(profile, "\t");
		fwrite(head->passward, strlen(head->passward), 1, profile);
		fprintf(profile, "\t");
		fwrite(head->name, strlen(head->name), 1, profile);
		fprintf(profile, "\t");
		fprintf(profile, "%d", head->number);
		fprintf(profile, "\n");

		if (head->ptr != NULL)
		{
			fprintf(profile, "\n");
			head = head->ptr;
		}
		else if (head->ptr == NULL)
			break;
	}


	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("%s 피일에 자장되었습니다.", file_name);
	point.Y++;
	SetConsoleCursorPosition(handle, point);
	printf("엔터키를 누르면 메뉴로 돌아갑니다...");
	getchar();
	system("cls");
	return;
}

MP_node* load_file(MP_node* head)
{
	MP_node* start;
	MP_node* unsaved_data;
	MP_node* free_node;
	FILE* profile;
	char temp = 0;
	char buff[2000];
	char file_name[1000];
	char file_type[100];
	int i, j;
	unsaved_data = memory_alloc();
	start = head;

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD point;

	if (head->ptr != NULL)
	{
		unsaved_data->ptr = head->ptr;
	}

	head->ptr = memory_alloc();
	head = head->ptr;

	strcpy(file_type, ".bin");

	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("로드할 파일 이름을 입력하세요: ");
	gets(file_name);
	system("cls");

	strcat(file_name, file_type);

	if ((profile = fopen(&file_name, "r+b")) == NULL)
	{
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("%s파일이 존재하지 않습니다.", file_name);
		point.Y++;
		SetConsoleCursorPosition(handle, point);
		printf("엔터키를 누르면 메뉴로 돌아갑니다...");
		getchar();
		system("cls");
		return start;
	}
	else if ((profile = fopen(&file_name, "r+b")) != NULL)
	{
		profile = fopen(&file_name, "r+b");

		fseek(profile, 0, SEEK_SET);
		while (1)
		{
			if (head == NULL)
				head = memory_alloc();
			memset(buff, 0, 2000);
			i = 0;
			j = 0;

			while (1)
			{
				while (1)
				{
					fread(&temp, 1, 1, profile);
					if (temp == '\t' || temp == '\n')
					{
						buff[i++] = NULL;
						break;
					}
					buff[i++] = temp;
				}
				if (j == 0)
				{
					strcpy(head->ID, buff);
					memset(buff, 0, 2000);
					i = 0;
					j++;
				}
				else if (j == 1)
				{
					strcpy(head->passward, buff);
					memset(buff, 0, 2000);
					i = 0;
					j++;
				}
				else if (j == 2)
				{
					strcpy(head->name, buff);
					memset(buff, 0, 2000);
					i = 0;
					j++;
				}
				else if (j == 3)
				{
					head->number = atoi(buff);
					memset(buff, 0, 2000);
					i = 0;
					j++;
				}
				else if (j > 3)
				{
					j = 0;
					break;
				}
			}

			if (feof(profile) == 0)
			{
				head->ptr = memory_alloc();
				head = head->ptr;
			}
			if (feof(profile) != 0)
				break;
			
		}
	}

	if (unsaved_data->ptr != NULL)
	{
		head->ptr = memory_alloc();
		head->ptr = unsaved_data->ptr;
	}
	
	point.X = 8;
	point.Y = 3;
	SetConsoleCursorPosition(handle, point);
	printf("%s 파일의 데이터를 로드했습니다.", file_name);
	point.Y += 2;
	SetConsoleCursorPosition(handle, point);
	printf("엔터키를 누르면 메뉴로 돌아갑니다...");
	getchar();
	system("cls");

	return start;
}