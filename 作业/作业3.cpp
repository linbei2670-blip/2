#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct Node {
	int salary;
	char name[20];
	Node* next;
};
Node* Initiate();
void listInsert(Node* L, int salary, const char* name);
void Max_list(Node* L);
void listInsert(Node* L, int salary, const char* name) {
	if (salary == 0) {
		printf("结束");
		return;
	}
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	Node* newnode = (Node*)malloc(sizeof(Node));
	assert(newnode != NULL);
	strcpy(newnode->name, name);
	newnode->salary = salary;
	newnode->next = NULL;
	p->next = newnode;
}

Node* Initiate() {
	Node* p = (Node*)malloc(sizeof(Node));
	assert(p != NULL);
	p->next = NULL;
	p->salary = 0;
	p->name[0] = '\0';
	return p;
}

void Max_list(Node* L) {
	
	Node* max = L->next;
	Node* cur = L->next;
	while (cur != NULL) {
		if (cur->salary > max->salary) {
			max = cur;
		}
		cur = cur->next;
	}
	printf("最高工资员工为%s，工资为%d", max->name, max->salary);
	return;
}
int main() {
	Node* list = Initiate();

	listInsert(list, 3000, "张三");
	listInsert(list, 2000, "李四");
	listInsert(list, 5000, "王五");

	Max_list(list);
}