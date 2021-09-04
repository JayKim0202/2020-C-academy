//다음 소스 코드에서 자동차의 속도, 연료, 주행거리, 엔진 온도, 회전수를 표현하는 계기찬 구조체를 정의하고, 계기판 정보가 출력되게 만드세요.
#include <stdio.h>

typedef struct _Dashboard {
	int speed;
	char fuel;
	float mileage;
	int engineTemp;
	int rpm;
} Dashboard;

int main()
{
	Dashboard d1;

	d1.speed = 80;
	d1.fuel = 'F';
	d1.mileage = 5821.442871f;
	d1.engineTemp = 200;
	d1.rpm = 1830;

	printf("Speed: %dkm/h\n", d1.speed);
	printf("Fuel: %c\n", d1.fuel);
	printf("Mileage: %fkm\n", d1.mileage);
	printf("Engine temp: %d℃\n", d1.engineTemp);
	printf("RPM: %d\n", d1.rpm);

	return 0;
}