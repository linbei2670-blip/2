#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	Node* next;
	int length;
}Node;
void freelist(Node* L);
void Listnode(Node* L);
Node* ListInitiate();
void InsertTail(Node* L, int e);
void ListDelete(Node* L, int e);
Node* ListInitiate() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("内存分配失败！\n");
		return NULL;
	}

	head->length = 0;
	head->data = 0;
	head->next = NULL;
	return head;
}
void InsertTail(Node* L, int e) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL) {
		printf("p的内存分配失败");
		return;
	}
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	newnode->data = e;
	p->next = newnode;
	newnode->next = NULL;
	L->length++;
}
void Listnode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d", p->data);
		if (p->next != NULL) {
			printf(" ");
		}
		else {
			printf("\n");
		}
		p = p->next;
	}
}

void ListDelete(Node* L, int e) {
	int count = 0;
	Node* p = L->next;
	Node* pre = L;
	while (p != NULL&&p->next!=NULL) {
		if (p->data == e) {
			Node* temp = p;
			pre->next = p->next;
			p = p->next;
			free(temp);
			L->length--;
			count++;
		}
		else {
			pre = p;
			p = p->next;
		}

		}
	if (count == 0) {
		printf("不存在为%d的值", e);
	}
	else {
		printf("成功删除值为%d的元素%d个", e, count);
	}

}

void freelist(Node* L) {
	if (L == NULL) return;
	Node* p = L;
	Node* q = NULL;;
	while (p != NULL) {
		if (p != L) {
			printf("当前清理的节点数据为%d\n", p->data);
		}
		q = p->next;
		free(p);
		p = q;
	}
}
int main() {
	Node* list;
	list = ListInitiate();
	int e;
	printf("请输入要删除的元素");
	scanf("%d", &e);
	InsertTail(list, 1);
	InsertTail(list, 2);
	InsertTail(list, 3);
	InsertTail(list, 4);
	InsertTail(list, 5);
	InsertTail(list, 1);
	InsertTail(list, 2);
	InsertTail(list, 3);
	InsertTail(list, 4);
	ListDelete(list, e);
	Listnode(list);


	freelist(list);
	return 0;
}