#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 5

struct shopping {
	int menu; //입고 메뉴
	int ID[SIZE]; //상품 ID
	int buy[SIZE]; //입고 수량
	char name[SIZE][100]; //상품명
	int price[SIZE]; //가격
	int sell[SIZE]; //판매 수량
	int item[SIZE]; //재고 (입고량 - 판매량)
	float all_buy; //모든 상품 입고량
	float all_sell; //모든 상품 판매량
	float sell_rate; //판매율
	int sell_price; //총 판매 금액
	int min[2]; //최소 판매 상품의 수량&ID
	int max[2]; //최대 판매 상품의 수량&ID
} SH;

int main(void) {
	int i;

	while (1) {
		printf("원하는 메뉴를 선택하세요 1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료, 6. 저장, 7. 불러오기 (정수로 입력, ex: 1)\n");
		scanf("%d", &SH.menu);
		switch (SH.menu) {
		case 1: {
			printf("<<입고>>\n");
			printf("상품 ID: ");
			scanf("%d", &i);
			SH.ID[i] = i;
			printf("\n상품명: ");
			scanf("%s", SH.name[i]);
			printf("\n입고 수량: ");
			scanf("%d", &SH.buy[i]);
			printf("\n판매 가격: ");
			scanf("%d", &SH.price[i]);
			break;
		}
		case 2: {
			printf("<<판매>>\n");
			printf("상품 ID: ");
			scanf("%d", &i);
			if (SH.ID[i] != i) {
				printf("ERROR: 해당 ID가 존재하지 않습니다.\n");
				break;
			}
			if (SH.ID[i] == i) {
				printf("판매 수량: ");
				scanf("%d", &SH.sell[i]);
			}
			break;
		}
		case 3: {
			printf("<<개별현황>>\n");
			printf("상품 ID: ");
			scanf("%d", &i);
			printf("\n상품명: %s\n", SH.name[i]);
			printf("가격: %d원\n", SH.price[i]);
			break;
		}
		case 4: {
			printf("<<전체현황>>\n");
			for (int i = 1; i <= SIZE; i++) {
				if (SH.ID[i] == i) {
					SH.item[i] = SH.buy[i] - SH.sell[i];
					SH.all_buy += SH.buy[i];
					SH.all_sell += SH.sell[i];
					SH.item[i] = SH.buy[i] - SH.sell[i];
					SH.all_buy += SH.buy[i];
					SH.all_sell += SH.sell[i];
					if (i == 1) { SH.min[1] = SH.sell[i]; SH.max[1] = SH.sell[i]; }
					if (SH.max[1] <= SH.sell[i]) { SH.max[1] = SH.sell[i]; SH.max[0] = i; }
					if (SH.min[1] >= SH.sell[i]) { SH.min[1] = SH.sell[i]; SH.min[0] = i; }
				}
			}
			SH.sell_rate = (SH.all_sell / SH.all_buy) * 100;
			printf("\n총 판매량: %.0lf (판매율: %.2lf %)\n", SH.all_sell, SH.sell_rate);
			printf("최대 판매 상품: ID %d, 판매량: %d\n", SH.max[0], SH.max[1]);
			printf("최소 판매 상품: ID %d, 판매량: %d\n", SH.min[0], SH.min[1]);
			for (int i = 1; i <= SIZE; i++) {
				if (SH.ID[i] == i && SH.item[i] <= 2) printf("상품 ID %d : 재고부족(%d)\n", i, SH.item[i]);
			}
			break;
		}
		case 5: {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		case 6: {
			FILE* fp = fopen("product.dat", "wb");
			if (fp == NULL) {
				printf("파일 저장 실패!\n");
				break;
			}
			fwrite(&SH, sizeof(struct shopping), 1, fp);
			fclose(fp);
			printf("상품 정보가 저장되었습니다.\n");
			break;
		}
		case 7: {
			FILE* fp = fopen("product.dat", "rb");
			if (fp == NULL) {
				printf("저장된 상품 정보가 없습니다.\n");
				break;
			}
			fread(&SH, sizeof(struct shopping), 1, fp);
			fclose(fp);
			printf("상품 정보를 불러오는데 성공했습니다.\n");
			break;
		}
		default: {
			printf("올바르지 않은 선택입니다.\n");
			break;
		}
		}
		if (SH.menu == 5) break;
	}




	return 0;
}