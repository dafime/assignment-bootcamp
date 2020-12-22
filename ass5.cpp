#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int x;
    Node* next;
};
 
void createNode(Node **head, int x) {
    struct Node* new_node = (Node*)malloc(sizeof(struct Node));
 
    new_node->x = x;
    new_node->next = *head;
    *head = new_node;
}
 
Node *gettheEnd(Node *head, int z) {
    int k = 0;
    Node *curr = head;
 
    while (curr){
        curr = curr->next;
        k++;
    }
 
    if (k >= z){
        curr = head;
        for (int i = 0; i < k - z; i++)
            curr = curr->next;
    }
    return curr;
}
 
int main(void)
{
    int keys[] = { 3, 4, 10, 7, 8 };
    int k = sizeof(keys) / sizeof(keys[0]);
 
    Node *head = NULL;
    for (int i = k - 1; i >= 0; i--)
        createNode(&head, keys[i]);
 
    int z = 2;
    Node *node = gettheEnd(head, z);
 
    if(node)
        printf("node from the end is %d\n", node->x);
 
    return 0;
}