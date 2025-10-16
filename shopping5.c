#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 101

struct shopping {
	int count; //상품 종류
	int menu; //입고 메뉴
	int buy[SIZE]; //입고량
	char name[SIZE]; //상품명
	int price[SIZE]; //가격
	int sell[SIZE]; //판매량
	int item[SIZE]; //재고 (입고량 - 판매량)
	float all_buy; //모든 상품 입고량
	float all_sell; //모든 상품 판매량
	float sell_rate; //판매율
	int sell_price; //총 판매 금액
	int min[2]; //최소 판매 상품의 수량&ID
	int max[2]; //최대 판매 상품의 수량&ID
} sh;

int main(void) {
	while (1) {
		printf("종류를 1부터 100까지 사이로 정하시오.\n");
		scanf("%d", &sh.count);
		if (sh.count >= 1 && sh.count <= 100) break;
	}

	while (1) {
		printf("원하는 메뉴를 선택하세요 1. 입고, 2. 판매, 3. 상품현황, 4. 종료 (정수로 입력, ex: 1)\n");
		scanf("%d", &sh.menu);
		switch (sh.menu) {
		case 1: {
			printf("<<입고>>\n");
			for (int i = 1; i <= sh.count; i++) {
				printf("ID: %d, 당일 입고 수량을 입력하세요 (예: 2).\n", i);
				while (1) {
					scanf("%d", &sh.buy[i]);
					if (sh.buy[i] > 5) printf("수량을 5개 이하로 입력하시오.\n");
					if (sh.buy[i] <= 5) break;
				}
			}
			break;
		}
		case 2: {
			printf("<<판매>>\n");
			for (int i = 1; i <= sh.count; i++) {
				printf("ID: %d,당일 판매 수량을 입력하세요 (예: 3).\n", i);
				scanf("%d", &sh.sell[i]);
				if (i == 1) { sh.min[1] = sh.sell[i]; sh.max[1] = sh.sell[i]; }
				if (sh.max[1] <= sh.sell[i]) { sh.max[1] = sh.sell[i]; sh.max[0] = i; }
				if (sh.min[1] >= sh.sell[i]) { sh.min[1] = sh.sell[i]; sh.min[0] = i; }
			}
			break;
		}
		case 3: {
			printf("<<상품현황>>\n");
			for (int i = 1; i <= sh.count; i++) {
				sh.item[i] = sh.buy[i] - sh.sell[i];
				sh.all_buy += sh.buy[i];
				sh.all_sell += sh.sell[i];
			}
			printf("\n전체 재고수량: ");
			for (int i = 1; i <= sh.count; i++)
				printf("%d ", sh.item[i]);
			sh.sell_rate = (sh.all_sell / sh.all_buy) * 100;
			printf("\n총 판매량: %.0lf (판매율: %.2lf %)\n", sh.all_sell, sh.sell_rate);
			printf("최대 판매 상품: ID %d, 판매량: %d\n", sh.max[0], sh.max[1]);
			printf("최소 판매 상품: ID %d, 판매량: %d\n", sh.min[0], sh.min[1]);
			for (int i = 1; i <= sh.count; i++) {
				if (sh.item[i] <= 2) printf("상품 ID %d : 재고부족(%d)\n", i, sh.item[i]);
			}
			break;
		}
		case 4: {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		default: {
			printf("올바르지 않은 선택입니다.\n");
			break;
		}
		}
		if (sh.menu == 4) break;
	}




	return 0;
}