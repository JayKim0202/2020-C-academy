/*�ڵ��ڿ��� �ӵ�, ����, ����Ÿ�, ���� �µ�, ȸ������ ǥ���ϴ� ����� ����ü�� ���ǵǾ� �ֽ��ϴ�.
���� �ҽ��ڵ带 �ϼ��Ͽ� ����� ������ ��µǰ� ���弼��.*/
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
	printf("Engine temp: %d��\n", DB1.engineTemp);
	printf("RPM: %d\n", DB1.rpm);

	return 0;
}