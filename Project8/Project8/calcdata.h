#ifndef CALC_DATA_H		// CALC_DATA_H가 정의되어 있지 않다면
#define CALC_DATA_H		// CALC_DATA_H 매크로 정의

typedef struct _CLAC_DATA {		// 계산 테이터 구조체 정의
	int operand1;				// 계산할 값1
	int operand2;				// 계산할 값2
	char operate;				// 연산자 문자
	int result;					// 계산 결과
} CALC_DATA;

#endif