#include <stdio.h>


int main() {

	int arr[] = { 10,20,30,40 };


	printf("arr : %p\n", arr);
	printf("&arr : %p\n", &arr);

	printf("arr size : %d\n", sizeof(arr));
	printf("&arr size : %d\n", sizeof(&arr));

	printf("arr + 1 : %p\n", arr + 1);
	printf("&arr+1 : %p\n", &arr + 1);

	printf("*arr : %d\n", *arr);
	printf("*&arr:%p\n", *&arr);
	printf("**&arr:%p\n", **&arr);

	return 0;
}