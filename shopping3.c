#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 101

int main() {
	int count = 0; //��ǰ ����
	int menu = 0;
	int id[SIZE]; //id
	int buy[SIZE]; //�԰�
	int sell[SIZE]; //�Ǹ�
	int item[SIZE]; //��� (�԰� - �Ǹ�)
	float all_buy = 0; //��� ��ǰ �԰�
	float all_sell = 0; //��� ��ǰ �Ǹŷ�
	float sell_rate = 0; //�Ǹ���
	int min[2]; //�ּ� �Ǹ� ����
	int max[2]; //�ִ� �Ǹ� ����

	while (1) {
		printf("������ 1���� 100���� ���̷� ���Ͻÿ�.\n");
		scanf("%d", &count);
		if (count >= 1 && count <= 100) break;
	}

	for (int i = 1; i <= count; i++) {
		id[i] = i;
		printf("ID: %d, �԰� ������ ���� �Ǹ� ������ ���� �Է��ϼ��� (��: 2 1).\n", i);
		scanf("%d %d", &buy[i], &sell[i]);
		item[i] = buy[i] - sell[i];
		all_buy += buy[i];
		all_sell += sell[i];
		if (i == 1) { min[1] = sell[i]; max[1] = sell[i]; }
		if (max[1] <= sell[i]) { max[1] = sell[i]; max[0] = i; }
		if (min[1] >= sell[i]) { min[1] = sell[i]; min[0] = i; }
	}

	printf("\n��ü ������: ");
	for (int i = 1; i <= count; i++)
		printf("%d ", item[i]);
	sell_rate = (all_sell / all_buy) * 100;
	printf("\n�� �Ǹŷ�: %.0lf (�Ǹ���: %.2lf %)\n", all_sell, sell_rate);
	printf("�ִ� �Ǹ� ��ǰ: ID %d, �Ǹŷ�: %d\n", max[0], max[1]);
	printf("�ּ� �Ǹ� ��ǰ: ID %d, �Ǹŷ�: %d\n", min[0], min[1]);
	for (int i = 1; i <= count; i++) {
		if (item[i] <= 2) printf("��ǰ ID %d : ������(%d)\n", i, item[i]);
	}

	while (1) {
		printf("���ϴ� �޴��� �����ϼ��� 1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ���� (������ �Է�, ex: 1)\n");
		scanf("%d", &menu);
		switch (menu) {
		case '1': {
			printf("�԰�\n");
			break;
		}
		case '2': {
			printf("�Ǹ�\n");
			break;
		}
		case '3': {
			printf("��ǰ��Ȳ\n");
			break;
		}
		case '4': {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		default: {
			printf("�ùٸ��� ���� �����Դϴ�.\n");
			break;
		}
		}
	}
	return 0;
}