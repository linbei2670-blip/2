#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
typedef struct stack {
	int* data;
	int top;
}stack;

stack* initiate() {
	stack* p = (stack*)malloc(sizeof(stack));
	assert(p != NULL);
	p->data = (int*)malloc(sizeof(int) * 10);
	assert(p->data != NULL);
	p->top = -1;
	return p;
}
void turning(stack* p, int i) {
	int num = i;
	if (num == 0) {
		return;
	}
	while (num > 0) {
		p->data[++(p->top)] = num % 2;
		num /= 2;
	}
	while (p->top != -1) {
		printf("%d", p->data[p->top--]);
	}
	printf("\n");
}

int main() {
	stack* p =initiate();
	turning(p, 3);
	turning(p, 2);
	turning(p, 5);
	
	free(p->data);
	free(p);
	return 0;
}