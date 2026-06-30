#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maxsize 100

typedef struct {
	int arr1[maxsize];
	int length;
}seqList;
void initiate(seqList* L);
int ListInsert(seqList* L, int i, int e);
int listfind(seqList* L, int x, int i);

int ListInsert(seqList* L, int i, int e) {
	if (i<1 || i>L->length+1) {
		printf("参数有误");
		return 0 ;
	}
	if (L->length >= maxsize) {
		printf("顺序表已满");
		return 0;
	}
	for (int j = L->length-1; j >= i-1; j--) {
		L->arr1[j+1] = L->arr1[j];
	}
	L->arr1[i-1] = e;
	L->length++;
	return 1;
}

void initiate(seqList* L) {
	L->length = 0;
}

int listfind(seqList* L, int x, int i) {
	if (i<1 || i>L->length) {
		printf("选择的位置有误");
		return -1;
	}
	for (int j = i-1; j < L->length; j++) {
		if (L->arr1[j] == x) {
			printf("查询成功，所查找的元素为arr1[%d]", j);
			return 0;
		}
	}
	printf("未查询到该元素");
	return -1;
}
int main() {
	seqList L;
	printf("初始化顺序表L\n");
	initiate(&L);
	int arr2[] = { 1,2,3,4,5 };
	for (int n = 0; n < sizeof(arr2) / sizeof(int); n++) {
		L.arr1[n] = arr2[n];
		L.length++;
	}
	printf("插入元素前:\n");
	for (int n = 0; n < L.length; n++) {
		printf("%d ", L.arr1[n]);
	}
	int i;
	int e;
	printf("输入你要插入的位置与插入的元素\n");
	scanf("%d %d", &i,&e);
	if (ListInsert(&L, i, e)) {
		printf("\n插入成功！\n");
		printf("--- 更新后的顺序表 ---\n");
		for (int n = 0; n < L.length; n++) {
			printf("%d ", L.arr1[n]);
		}
		printf("\n新长度: %d\n", L.length);
	}
	else {
		printf("\n[提示] 操作未执行，顺序表保持原样。\n");
	}
	int x;
	printf("请输入要查找的元素与开始的位置");
	scanf("%d %d", &x, &i);
	listfind(&L, x, i);
	return 0;
}