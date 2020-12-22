#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node { 
    int x; 
    struct Node *next; 
}; 
  
void printMiddle(Node *head) { 
    int count = 0; 
    Node *mid = head; 
  
    while (head!=NULL) { 
        if (count & 1) 
            mid = mid->next; 
  
        ++count; 
        head = head->next; 
    } 
    if (mid != NULL) 
        printf("The middle element : [%d]\n\n", mid->x); 
} 
  
void push(Node **head_ref, int new_x) { 
    Node *new_node = (Node*)malloc(sizeof(struct Node)); 
    new_node->x = new_x; 
    new_node->next = (*head_ref);
    (*head_ref) = new_node; 
} 
  
void pLinkedList(Node *ptr) { 
    while (ptr != NULL) { 
        printf("%d->", ptr->x); 
        ptr = ptr->next; 
    } 
    printf("NULL\n"); 
} 
  
int main() {   
    Node *head = NULL; 
    int i; 
  
    for (i = 5; i > 0; i--) { 
        push(&head, i); 
        pLinkedList(head); 
        printMiddle(head); 
    } 
  
    return 0; 
}