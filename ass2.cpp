#include <stdio.h>
#include <stdlib.h>

struct Node {
    int x;
    Node *next; 
} *head, *tail, *current, *list, *slow, *fast;

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
 
int detectLoop(Node *list) {
    slow = list; 
    fast = list;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

void plinkedList() {
    Node *current = head;
    while (current) {
        printf("%d ", current->x);
        current = current->next;
    }
    printf("\n");
}

int main() {
    pushHead(13);
    pushHead(18);
    pushTail(24);
    pushTail(35);
    plinkedList();
    head->next->next->next->next = head;
    if (detectLoop(head)) {
        printf("Got cycle\n");
    }else {
        printf("Has No cycle\n");
    }
    return 0;
}