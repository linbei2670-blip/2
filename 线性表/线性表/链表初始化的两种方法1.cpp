#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	 Node* next;
}Node;
void ListInitiate(Node** head);

void ListInitiate(Node** head) {
	*head = (Node*)malloc(sizeof(Node));
	if (*head == NULL) {
		printf("ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
		return;
	}

	(*head)->data = 0;
	(*head)->next = NULL;
}
int main() {
	Node* list;
		ListInitiate(&list);
		printf("data: %d\n", list->data);
		printf("next: %p\n", (void*)list->next);

		free(list);

		return 0;
}

