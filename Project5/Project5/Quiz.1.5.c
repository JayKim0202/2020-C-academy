/*자동자에서 속도, 연료, 주행거리, 엔진 온도, 회전수를 표현하는 계기판 구조체가 정의되어 있습니다.
다음 소스코드를 완성하여 계기판 정보가 출력되게 만드세요.*/
#include <stdio.h>

struct Dashboard {
	int speed;
	char fuel;
	float mileage;
	int engineTemp;
	int rpm;
};

int main()
{
	struct Dashboard DB1;

	DB1.speed = 80;
	DB1.fuel = 'F';
	DB1.mileage = 5821.442871f;
	DB1.engineTemp = 200;
	DB1. rpm = 1830;

	printf("Speed: %dkm/h\n", DB1.speed);
	printf("Fuel: %c\n", DB1.fuel);
	printf("Mileage: %fkm\n", DB1.mileage);
	printf("Engine temp: %d℃\n", DB1.engineTemp);
	printf("RPM: %d\n", DB1.rpm);

	return 0;
}