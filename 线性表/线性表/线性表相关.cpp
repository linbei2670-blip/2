#include <stdio.h>
typedef int elemType;
#define maxsize 100

typedef struct {
	elemType Id[maxsize];
	int length;
}seqList;
void initiate(seqList* L);


void initiate(seqList* L) {
	L->length = 0;
}
int main() {
	seqList L;
	printf("初始化顺序表L\n");
	initiate(& L);

	if (L.length == 0) {
		printf("初始化成功，为%d\n", L.length);
		printf("所占用字节为%d", sizeof(L.Id));
	}
	else {
		printf("初始化失败");
	}
	return 0;

}
