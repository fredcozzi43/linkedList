#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int num;
    struct node* next;
}node_t;

void printList(struct node* n){
    while(n != NULL){
        printf(" %d ", n->num);
        n = n->next;
    }
}

void addElement(struct node* n, int val){
    node_t * current = n;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->num = val;
    current->next->next = NULL;
}

void removeElement(node_t * n){
    int returnvalue = 0;

    if (n->next==NULL){
        returnvalue = n->num;
        free(n);

    }
    node_t * current = n;
    while(current->next->next != NULL){
        current = current->next;
    }

    returnvalue = current->next->num;
    free(current->next);
    current->next = NULL;
  
}

int main(){

    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* first = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));

    head->num = 1;
    head->next = first;

    first->num = 3;
    first->next = second;

    second->num = 192;
    second->next = NULL;

    
    addElement(head, 90);
    printList(head);
    removeElement(head);
    printList(head);

}