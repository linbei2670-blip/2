#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maxsize  100
typedef struct {
	int arr[maxsize];
	int length;
	int x;
}seqList;

int Listdelete(seqList* L, int i, int* x);
void initiate(seqList* L);

int Listdelete(seqList* L, int i, int* x) {
	if (i<1 || i>L->length) {
		printf("参数有误\n");
		return 0;
	}
	*x = L->arr[i - 1];
		for (int j = i ; j <= L->length ; j++) {
			L->arr[j - 1 ] = L->arr[j];
		}
		L->length--;
		return 1;
}
void initiate(seqList* L) {
	L->length = 0;
}
int main() {
	int i;
	seqList L;
	L.x= 0;
	initiate(&L);
	int arr2[] = {1, 2, 3, 4, 5};
	for (int n = 0; n < sizeof(arr2) / sizeof(int); n++) {
		L.arr[n] = arr2[n];
		L.length++;
	}
	printf("请输入要删除的位置\n");
	scanf("%d", &i);
	if (Listdelete(&L, i, &(L.x)) != 0) {
		printf("被删除的值为 % d\n", L.x);
		for (int n = 0; n < L.length; n++) {
			printf("%d ", L.arr[n]);
		}
	}
	return 0;
}
