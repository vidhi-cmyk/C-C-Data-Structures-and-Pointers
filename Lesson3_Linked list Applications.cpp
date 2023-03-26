// Doubly linked list

#include <iostream>
#include <stdio.h>

struct Dbl{
    int data;
    struct Dbl* prev;
    struct Dbl* next;
};
void Inhead(Dbl*,int);
void Print(Dbl*);

int main(){
    struct Dbl* head=NULL;
    Inhead(head,3);
    Inhead(head,4);
    Print()
}

void Inhead(Dbl* head,int data){
    struct Dbl* node=(Dbl*)malloc(sizeof(Dbl*));
    node->prev=head;
    
    if (head->next==NULL){
        node->next=NULL;
    }
    else{
        node->next=head;
        node->next->prev=node;
    }
    head=node;
    node->data=data;
    
}

void Print(Dbl* head){
    struct Dbl* temp;
    temp=head;
    while (temp->next!=NULL)
    {
        printf("%d",temp->data);
    }


}
