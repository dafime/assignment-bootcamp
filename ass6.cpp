#include<stdio.h>  
#include<stdlib.h>  

struct Node {
    int x;
    Node *next;
} *head, *tail, *current;

Node *createNode(int x) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->next = NULL;
    return new_node;
}

void pushHead(int x) {
    Node *temp = createNode(x);
    if (!head) {
        head = tail = temp;
    }else {
        temp->next = head;
        head = temp;
    } 
}

void pushTail(int x) {
    Node *temp = createNode(x);
    if (!head) {
        head = tail = temp;
    }else {
        tail->next = temp;
        tail = temp;
    } 
}

void plinkedList() {
    Node *current = head;
    while (current) {
        printf("%d->", current->x);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
   int H, I, J, K;
    printf("Enter a number: ");
    scanf("%d %d %d %d", &H, &I, &J, &K);
    pushHead(J);
    pushHead(K);
    pushTail(I);
    pushTail(H);
    printf("Sorted number: ");
    plinkedList();
    return 0;
}