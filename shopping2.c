#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int main() {
	int count = 0; //��ǰ ����
	int t = 1;
	int id[101];
	int buy[101];
	int sell[101];
	int item[101];
	float all_sell = 0;
	float all_buy = 0;
	float sell_rate = 0;
	int min[2];
	int max[2];

	while (1) {
		printf("������ 1���� 100���� ���̷� ���Ͻÿ�.\n");
		scanf("%d", &count);
		if (count >= 1 && count <= 100) break;
	}

	for (int i = 1; i <= count; i++) {
		id[i] = i;
		printf("ID: %d, �԰� ������ ���� �Ǹ� ������ ���� �Է��ϼ���.\n", i);
		scanf("%d %d", &buy[i], &sell[i]);
		item[i] = buy[i] - sell[i];
		all_buy += buy[i];
		all_sell += sell[i];
		if (i == 1) { min[1] = sell[i]; max[1] = sell[i]; }
		if (max[1] < sell[i]) { max[1] = sell[i]; max[0] = i; }
		if (min[1] > sell[i]) { min[1] = sell[i]; min[0] = i; }
	}

	printf("ID�� �Է��Ͻÿ�.\n");
	scanf("%d", &t);
	printf("\n������: %d\n��ü ������: ", item[t]);
	for (int i = 1; i <= count; i++)
		printf("%d ", item[i]);
	sell_rate = (all_sell / all_buy) * 100;
	printf("\n�� �Ǹŷ�: %.0lf (�Ǹ���: %.2lf %)\n", all_sell, sell_rate);
	printf("�ִ� �Ǹ� ��ǰ: ID %d, �Ǹŷ�: %d\n", max[0], max[1]);
	printf("�ּ� �Ǹ� ��ǰ: ID %d, �Ǹŷ�: %d\n", min[0], min[1]);



	return 0;
}