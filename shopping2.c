#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int main() {
	int count = 0; //상품 종류
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
		printf("종류를 1부터 100까지 사이로 정하시오.\n");
		scanf("%d", &count);
		if (count >= 1 && count <= 100) break;
	}

	for (int i = 1; i <= count; i++) {
		id[i] = i;
		printf("ID: %d, 입고 수량과 당일 판매 수량을 각각 입력하세요.\n", i);
		scanf("%d %d", &buy[i], &sell[i]);
		item[i] = buy[i] - sell[i];
		all_buy += buy[i];
		all_sell += sell[i];
		if (i == 1) { min[1] = sell[i]; max[1] = sell[i]; }
		if (max[1] < sell[i]) { max[1] = sell[i]; max[0] = i; }
		if (min[1] > sell[i]) { min[1] = sell[i]; min[0] = i; }
	}

	printf("ID를 입력하시오.\n");
	scanf("%d", &t);
	printf("\n재고수량: %d\n전체 재고수량: ", item[t]);
	for (int i = 1; i <= count; i++)
		printf("%d ", item[i]);
	sell_rate = (all_sell / all_buy) * 100;
	printf("\n총 판매량: %.0lf (판매율: %.2lf %)\n", all_sell, sell_rate);
	printf("최대 판매 상품: ID %d, 판매량: %d\n", max[0], max[1]);
	printf("최소 판매 상품: ID %d, 판매량: %d\n", min[0], min[1]);



	return 0;
}