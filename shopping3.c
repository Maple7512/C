#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 101

int main() {
	int count = 0; //상품 종류
	int menu = 0;
	int id[SIZE]; //id
	int buy[SIZE]; //입고
	int sell[SIZE]; //판매
	int item[SIZE]; //재고 (입고 - 판매)
	float all_buy = 0; //모든 상품 입고량
	float all_sell = 0; //모든 상품 판매량
	float sell_rate = 0; //판매율
	int min[2]; //최소 판매 수량
	int max[2]; //최대 판매 수량

	while (1) {
		printf("종류를 1부터 100까지 사이로 정하시오.\n");
		scanf("%d", &count);
		if (count >= 1 && count <= 100) break;
	}

	for (int i = 1; i <= count; i++) {
		id[i] = i;
		printf("ID: %d, 입고 수량과 당일 판매 수량을 각각 입력하세요 (예: 2 1).\n", i);
		scanf("%d %d", &buy[i], &sell[i]);
		item[i] = buy[i] - sell[i];
		all_buy += buy[i];
		all_sell += sell[i];
		if (i == 1) { min[1] = sell[i]; max[1] = sell[i]; }
		if (max[1] <= sell[i]) { max[1] = sell[i]; max[0] = i; }
		if (min[1] >= sell[i]) { min[1] = sell[i]; min[0] = i; }
	}

	printf("\n전체 재고수량: ");
	for (int i = 1; i <= count; i++)
		printf("%d ", item[i]);
	sell_rate = (all_sell / all_buy) * 100;
	printf("\n총 판매량: %.0lf (판매율: %.2lf %)\n", all_sell, sell_rate);
	printf("최대 판매 상품: ID %d, 판매량: %d\n", max[0], max[1]);
	printf("최소 판매 상품: ID %d, 판매량: %d\n", min[0], min[1]);
	for (int i = 1; i <= count; i++) {
		if (item[i] <= 2) printf("상품 ID %d : 재고부족(%d)\n", i, item[i]);
	}

	while (1) {
		printf("원하는 메뉴를 선택하세요 1. 입고, 2. 판매, 3. 상품현황, 4. 종료 (정수로 입력, ex: 1)\n");
		scanf("%d", &menu);
		switch (menu) {
		case '1': {
			printf("입고\n");
			break;
		}
		case '2': {
			printf("판매\n");
			break;
		}
		case '3': {
			printf("상품현황\n");
			break;
		}
		case '4': {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		default: {
			printf("올바르지 않은 선택입니다.\n");
			break;
		}
		}
	}
	return 0;
}