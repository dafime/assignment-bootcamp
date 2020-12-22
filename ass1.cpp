#include<stdio.h>
#include<stdlib.h>

struct Node {
    int x;
    Node *next;
};

void pushHead(struct Node** flag, int y){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node-> x = y;
    new_node->next = (*flag); 
    (*flag) = new_node; 
} 

Node* Sort(Node* a, Node* b){ 
    Node* temp = NULL; 
    if (a == NULL)  
        return(b); 
    else if (b==NULL)  
        return(a); 
    if (a->x < b->x){ 
        temp = a; 
        temp->next = Sort(a->next, b); 
    } 
    else { 
        temp = b; 
        temp->next = Sort(a, b->next); 
    } 
    return(temp); 
}

void plinkedlist (Node *node){
    while (node != NULL){
        printf ("%d ",node -> x);
        node = node -> next;
    }
}

int main (){
    Node *a = NULL;
    Node *b = NULL;
    Node *ans = NULL;
    pushHead (&a, 17);
    pushHead (&a, 15);
    pushHead (&a, 10);
    pushHead (&b, 24);
    pushHead (&b, 18);
    pushHead (&b, 11);

    ans = Sort(a, b);
    printf ("Merged Linked list: ");
    plinkedlist(ans);
}
