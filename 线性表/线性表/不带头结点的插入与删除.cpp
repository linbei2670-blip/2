#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
     Node* next;
} Node;
void ListInitiateNoHead(Node** head);
void InsertNohead(Node** head,int e);
void ListPrintNoHead(Node* head);
void freelist(Node** head);

void ListInitiateNoHead(Node** head) {
    *head = NULL;
}
void InsertNohead(Node** head,int e) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        return;
    }
    p->data = e;
    p->next = *head;
    *head = p;
}

void ListPrintNoHead(Node* head) {
    Node* p = head;

    if (p == NULL) {
        printf("链表为空！\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
        
    }
    printf("\n");
}

void freelist(Node** head) {
    if (head == NULL) return;
    Node* p = *head;
    Node* q = NULL;;
    while (p != NULL) {
        printf("当前清理的节点数据为%d\n", p->data);
        q = p->next;
        free(p);
        p = q;
    }
    *head = NULL;
}
void DeleteFirst(Node** head) {
    if (*head == NULL) return; 
    Node* temp = *head;    
    *head = (*head)->next;    
    free(temp);        
}

int main() {
    Node* list;
    ListInitiateNoHead(&list);
    int e;
    printf("请输入要插入的元素\n");
    scanf("%d",&e);
    InsertNohead(&list, e);
    InsertNohead(&list, 1); 
    InsertNohead(&list, 2); 
    InsertNohead(&list, 3);
    InsertNohead(&list, 4);
    
    printf("删除前：");
    ListPrintNoHead(list);
    DeleteFirst(&list);
    printf("删除后：");
    ListPrintNoHead(list);
    freelist(&list);
    return 0;
}