// Stack implementation using arrays

#include <iostream>
#include <stdio.h>
/*
#define max_size 7
int A[max_size];
int top=-1;

void push(int x){
    if(top==max_size-1){ //array is full
        printf("Stack overflow");
    }
    A[++top]=x;
}

int pop(){
    if (top==-1){
        printf("error: nothing to pop");
        
    }
    top=top-1;
    return A[top+1];
}

int main(){
    push(1);
    push(3);
    printf("%d",pop());
    printf("%d",pop());
    printf("%d",pop());
}*/

struct A{
    int data;
    struct A* next;

};

struct A* top=NULL;

void Push(int x){
    struct A* node= (struct A*)malloc(sizeof(A));
    node->data=x;
    node->next=top;
    top=node;
    

}

void Pop(){
    if (top==NULL){
        printf("Empty list!");
        return;
    }
    struct A* temp=top;
    printf("%d",top->data);
    top=top->next;
    free(temp);

}

int main(){
    Pop();
    Push(5);
    Push(0);
    Pop();

}