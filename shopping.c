#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int main() {
	int count = 0;
	int t = 1;
	int id[100];
	int buy[100];
	int sell[100];
	int item[100];

	while (1) {
		printf("������ 1���� 100���� ���̷� ���Ͻÿ�.\n");
		scanf("%d", &count);
		if (count >= 1 && count <= 100) break;
	}

	for (int i = 1; i <= count; i++) {
		id[i-1] = i;
		printf("ID: %d, �԰� ������ ���� �Ǹ� ������ ���� �Է��ϼ���.\n", i);
		scanf("%d %d", &buy[i], &sell[i]);
		item[i] = buy[i] - sell[i];
	}
	printf("ID�� �Է��Ͻÿ�.\n");
	scanf("%d", &t);
	printf("\n������: %d\n��ü ��� ����: ", item[t]);
	for (int i = 1; i <= count; i++)
		printf("%d ", item[i]);




	return 0;
}