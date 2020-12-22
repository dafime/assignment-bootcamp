#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    Node *next; 
} *head, *tail, *current, *next1;

Node *createNode(int x) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->next = NULL;
    return new_node;
}

void removeDuplicates() {
    current = head;
    if (current == NULL) {
        return;
    }
    while (current->next != NULL) {
        if (current->x == current->next->x) {
            next1 = current->next->next;
            free(current->next);
            current->next = next1;
        }else {
            current = current->next;
        }
    }
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
    while (current)
    {
        printf("%d->", current->x);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    pushHead(77);
    pushHead(65);
    pushHead(56);
    pushHead(56);
    pushHead(44);
    pushTail(44);
    pushTail(44);
    pushTail(45);
    pushTail(50);
    pushTail(77);
    printf("Number before duplicate: ");
    plinkedList();
    removeDuplicates();
    printf("Number after  duplicate: ");
    plinkedList();
    return 0;
}