#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define maxsize 100

typedef struct {
	int arr1[maxsize];
	int length;
}seqList;
void initiate(seqList* L);
int MiddleInsert(seqList* L,int e);
void ListMerge(seqList*L, seqList*M, seqList*N);
int listdelete(seqList* L, int i);

int MiddleInsert(seqList* L, int e) {

	if (L->length >= maxsize) {
		printf("溢出！");
		return 0;
	}
	int i = 0;
	while (i < L->length && L->arr1[i] < e) {
		i++;
	}

	for (int j = L->length; j > i; j--) {
		L->arr1[j] = L->arr1[j - 1];
	}

	L->arr1[i] = e;
	L->length++;
	return 1;
}
void initiate(seqList* L) {
	L->length = 0;
}
void ListMerge(seqList*L, seqList*M, seqList*N) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < L->length&&j<M->length) {
		if (L->arr1[i] > M->arr1[j]) {
			N->arr1[k++] = M->arr1[j++];
			N->length++;
		}
		else {
			N->arr1[k++] = L->arr1[i++];
			N->length++;
		}

	}
	while (i < L->length) {
		N->arr1[k++] = L->arr1[i++];
		N->length++;
	}
	while (j < M->length) {
		N->arr1[k++] = M->arr1[j++];
		N->length++;
	}
}
int listdelete(seqList* N, int i) {
	if (i<1 || i>N->length) {
		printf("删除位置有误");
		return 0;
	}
	for (int j = i-1; j < N->length - 1; j++) {
		N->arr1[j] = N->arr1[j + 1];
	}
	N->length--;
	return 1; 
}
int main() {
	seqList L;
	seqList M;
	seqList N;
	printf("初始化顺序表L\n");
	initiate(&L);
	initiate(&M);
	initiate(&N);
	int arr2[] = { 10,20,30,40,50 };
	int arr3[] = { 15,25,35,45,55 };
	for (int n = 0; n < sizeof(arr2) / sizeof(int); n++) {
		L.arr1[n] = arr2[n];
		M.arr1[n] = arr3[n];
		L.length++;
		M.length++;
	}
	printf("插入元素前:\n");
	for (int n = 0; n < L.length; n++) {
		printf("%d ", L.arr1[n]);
	}
	int e;
	printf("输入你要插入的元素\n");
	scanf("%d", &e);
	if (MiddleInsert(&L, e)) {
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
	ListMerge(&L, &M, &N);
	for (int i = 0; i < N.length; i++) {
		printf("%d ", N.arr1[i]);
	}
	printf("\n请输入要删除的位置");
	int i = 0;
	scanf("%d", &i);
	listdelete(&N,i);
	for (int i = 0; i < N.length; i++) {
		printf("%d ", N.arr1[i]);
	}

	return 0;
}