#include <stdio.h>

typedef struct _empInfo
{
	int empNum;		// 직원의 고유번호
	int age;		// 직원의 나이
	int hash;
} EmpInfo;

EmpInfo empInfoArr[100];

int GetHashValue1(int empNum)
{
	return empNum % 100;
}

int GetHashValue2(int empNum)
{
	return 1 + (empNum % 7); // 1 + (empNum % c) -> c는 상수(소수)
}

int main()
{

	EmpInfo emp1 = { 20120003, 42, 0 };
	EmpInfo emp2 = { 20130003, 33, 0 };
	EmpInfo emp3 = { 20170049, 27, 0 };

	EmpInfo r1, r2, r3;
	int num[10] = { 0 };

	// 키를 인덱스 값을 이용해 저장(이중해쉬)
	num[0] = GetHashValue1(emp1.empNum);
	empInfoArr[num[0]] = emp1;

	num[1] = GetHashValue1(emp1.empNum);
	if (num[0] == num[1])
	{
		empInfoArr[GetHashValue2(emp2.empNum)] = emp2;
		empInfoArr[GetHashValue2(emp2.empNum)].hash = 1;
	}
	else
		empInfoArr[num[1]] = emp2;

	num[2] = GetHashValue1(emp3.empNum);
	if (num[2] == num[0] || num[2] == num[1])
	{
		empInfoArr[GetHashValue2(emp3.empNum)] = emp3;
		empInfoArr[GetHashValue2(emp3.empNum)].hash = 1;
	}
	else
		empInfoArr[num[2]] = emp3;

	// 키를 인덱스 값으로 이용해서 탐색 (이중해쉬)
	r1 = empInfoArr[GetHashValue1(20120003)];
	if (empInfoArr[GetHashValue2(20130003)].hash == 1)
		r2 = empInfoArr[GetHashValue2(20130003)];
	else
		r2 = empInfoArr[GetHashValue1(20130003)];
	if (empInfoArr[GetHashValue2(20170049)].hash == 1)
		r3 = empInfoArr[GetHashValue2(20170049)];
	else
		r3 = empInfoArr[GetHashValue1(20170049)];


	/*
	// 키를 인덱스 값을 이용해서 저장 (이중해쉬가 아닐 때)
	empInfoArr[GetHashValue(emp1.empNum)] = emp1;
	empInfoArr[GetHashValue(emp2.empNum)] = emp2;
	empInfoArr[GetHashValue(emp3.empNum)] = emp3;

	// 키를 인덱스 값으로 이용해서 탐색 (이중해쉬기 아닐 때)
	r1 = empInfoArr[GetHashValue(20120003)];
	r2 = empInfoArr[GetHashValue(20130003)];
	r3 = empInfoArr[GetHashValue(20170049)];
	*/

	// 탐색 결과 확인
	printf("사번 %d, 나이 %d \n", r1.empNum, r1.age);
	printf("사번 %d, 나이 %d \n", r2.empNum, r2.age);
	printf("사번 %d, 나이 %d \n", r3.empNum, r3.age);
}