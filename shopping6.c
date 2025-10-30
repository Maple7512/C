#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 5

struct shopping {
	int menu; //입고 메뉴
	int ID[SIZE]; //상품 ID
	int buy[SIZE]; //입고 수량
	char name[SIZE]; //상품명
	int price[SIZE]; //가격
	int sell[SIZE]; //판매 수량
	int item[SIZE]; //재고 (입고량 - 판매량)
	float all_buy; //모든 상품 입고량
	float all_sell; //모든 상품 판매량
	float sell_rate; //판매율
	int sell_price; //총 판매 금액
	int min[2]; //최소 판매 상품의 수량&ID
	int max[2]; //최대 판매 상품의 수량&ID
} sh;

int main(void) {
	int i, j;

	while (1) {
		printf("원하는 메뉴를 선택하세요 1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료 (정수로 입력, ex: 1)\n");
		scanf("%d", &sh.menu);
		switch (sh.menu) {
		case 1: {
			printf("<<입고>>\n");
			printf("상품 ID: ");
			scanf("%d", &i);
			sh.ID[i] = i;
			printf("\n상품명: ");
			scanf("%s", &sh.name[i]);
			printf("\n입고 수량: ");
			scanf("%d", &sh.buy[i]);
			printf("\n판매 가격: ");
			scanf("%d", &sh.price[i]);
			break;
		}
		case 2: {
			printf("<<판매>>\n");
			printf("상품 ID: ");
			scanf("%d", &i);
			if (sh.ID[i] != i) {
				printf("ERROR: 해당 ID가 존재하지 않습니다.\n");
				break;
			}
			if (sh.ID[i] == i) {
				printf("판매 수량: ");
				scanf("%d", &sh.sell[i]);
			}
			break;
		}
		case 3: {
			printf("<<상품현황>>\n");
			/*for (int i = 1; i <= sh.count; i++) {
				sh.item[i] = sh.buy[i] - sh.sell[i];
				sh.all_buy += sh.buy[i];
				sh.all_sell += sh.sell[i];
			}*/
			printf("\n전체 재고수량: ");
			/*for (int i = 1; i <= sh.count; i++)
				printf("%d ", sh.item[i]);
			sh.sell_rate = (sh.all_sell / sh.all_buy) * 100;
			printf("\n총 판매량: %.0lf (판매율: %.2lf %)\n", sh.all_sell, sh.sell_rate);
			printf("최대 판매 상품: ID %d, 판매량: %d\n", sh.max[0], sh.max[1]);
			printf("최소 판매 상품: ID %d, 판매량: %d\n", sh.min[0], sh.min[1]);
			for (int i = 1; i <= sh.count; i++) {
				if (sh.item[i] <= 2) printf("상품 ID %d : 재고부족(%d)\n", i, sh.item[i]);
			}*/
			break;
		}
		case 4: {

		}
		case 5: {
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