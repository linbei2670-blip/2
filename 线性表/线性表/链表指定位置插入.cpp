#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int length;
	int data;
	Node* next;
}Node;
void freelist(Node* L);                                   //内存释放函数
void Listnode(Node* L);                                   //遍历链表函数
Node* ListInitiate();                                     //初始化函数
void InsertTail(Node* L, int e);                          //尾插函数
void listinsert(Node* L,int pos, int e);                                          //指定位置插入
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
void listinsert(Node* L, int pos,int e) {
	if (pos<1 || pos>L->length+1) {
		printf("插入位置有误");
		return;
	}
	int i = 0;
	Node* p = L;
	while (i < pos - 1) {
		p = p->next;
		i++;
	}
	Node* q = (Node*)malloc(sizeof(Node));
	if (q == NULL) {
		return;
	}
	q->data = e;
	q->next = p->next;
	p->next = q;
	L->length++;
}
int main() {
	Node* list;
	list = ListInitiate();
	InsertTail(list, 1);
	InsertTail(list, 2);
	InsertTail(list, 3);
	InsertTail(list, 4);
	InsertTail(list, 5);
	
	int e;
	int pos;
	printf("请输入要插入的位置与数据\n");
	scanf("%d %d", &pos, &e);
	listinsert(list, pos, e);
	
	Listnode(list);


	freelist(list);
	return 0;
}