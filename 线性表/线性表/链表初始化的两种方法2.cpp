#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	Node* next;
}Node;
Node* ListInitiate();

Node* ListInitiate() {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
		return NULL;
	}
	head->data = 0;
	head->next = NULL;
	return head;
}
int main() {
	Node* list;
	list = ListInitiate();

	printf("data: %d\n", list->data);
	printf("next: %p\n", (void*)list->next);

	free(list);

	return 0;
}