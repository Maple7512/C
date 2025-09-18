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
		printf("종류를 1부터 100까지 사이로 정하시오.\n");
		scanf("%d", &count);
		if (count >= 1 && count <= 100) break;
	}

	for (int i = 1; i <= count; i++) {
		id[i-1] = i;
		printf("ID: %d, 입고 수량과 당일 판매 수량을 각각 입력하세요.\n", i);
		scanf("%d %d", &buy[i], &sell[i]);
		item[i] = buy[i] - sell[i];
	}
	printf("ID를 입력하시오.\n");
	scanf("%d", &t);
	printf("\n재고수량: %d\n전체 재고 수량: ", item[t]);
	for (int i = 1; i <= count; i++)
		printf("%d ", item[i]);




	return 0;
}