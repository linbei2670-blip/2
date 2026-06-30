#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	float xi;
	int zhi;
	Node* next;
}Node;

Node* initiate();
void listinsert(Node* L,float xi,int zhi);
void printlist(Node* L);
void listadd(Node* L, Node* N, Node* M);
void listsur(Node* L, Node* N, Node* M);

Node* initiate() {
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->xi = 0;
	p->zhi = 0;
	return p;
}

void listinsert(Node* L, float xi, int zhi) {
	if (xi == 0) {
		return;
	}
	Node* pre = L;
	Node* p = L->next;
	while (p != NULL && p->zhi < zhi) {
		pre = p;
		p = p->next;
	}
	if (p != NULL&&p->zhi == zhi) {
		p->xi += xi;
		if (p->xi == 0) {
			pre->next = p->next;
			free(p);
		}
	}
	else {
		Node* s = (Node*)malloc(sizeof(Node));
		pre->next = s;
		s->next = p;
		s->xi = xi;
		s->zhi = zhi;
	}
}

void printlist(Node* L) {
	Node* p = L->next;
	printf("目前一元多项式为");
	while (p != NULL) {
		printf("%gx^%d", p->xi, p->zhi);
		if (p->next != NULL) {
			if (p->next->xi > 0) {
				printf("+");
			}
		}
		p = p->next;
	}
	printf("\n");
	return;
}

void listadd(Node* L, Node* N, Node* M) {
	Node* p = L->next;
	Node* q = N->next;
	while (p != NULL) {
		listinsert(M, p->xi,p->zhi);
		p = p->next;
	}
	while (q != NULL) {
		listinsert(M, q->xi, q->zhi);
		q = q->next;
	}
	return;
}

void listsur(Node* L, Node* N, Node* M) {
	Node* p = L->next;
	Node* q = N->next;
	while(p != NULL) {
		listinsert(M, p->xi, p->zhi);
		p = p->next;
	}
	while (q != NULL) {
		listinsert(M, -(q->xi),(q->zhi));
		q = q->next;
	}

}
int main() {
	Node* list1 = initiate();
	Node* list2 = initiate();

	listinsert(list1, 2, 1);
	listinsert(list1, 5, 3);
	listinsert(list1, 4, 2);
	listinsert(list1, 1, 4);
	listinsert(list2, 3, 3);
	listinsert(list2, 6, 4);
	listinsert(list2, -1, 2);
	listinsert(list2, 3, 2);
	printlist(list1);
	printlist(list2);
	Node* list3 = initiate();
	listadd(list1, list2, list3);
	printlist(list3);
	Node* list4 = initiate();
	listsur(list1, list2, list4);
	printlist(list4);
	return 0;
}

