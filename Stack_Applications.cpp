// Stack Applications for Prefix and Postfix expressions
//
# include <iostream>
# include <stdio.h>
# include <string.h>

struct A{
    int number;
    struct A* next;
};


struct A* top=NULL;


void push(int x){
    //need to add a new element
    struct A* node= (struct A*)malloc(sizeof(A));
    node->number=x;
    node->next=top;
    top=node;
    printf("Pushed %d\n",x);
}

int pop(){
    if (top==NULL){
        printf("empty stack!\n");
        return 0;
    }
    else{
        struct A* temp=top;
        int a= int(top->number);
        free(temp);
        top=top->next;
        printf("Popped %d\n",a);
        return a;
    }    
}

void seek(){
    printf("STack top: %d\n",top->number);
}


int main(){
    //defining our postfix expression
    
    char postfix[]="23+9*5/";
    printf(postfix);
    for(int i=0;i<strlen(postfix);i++){
        if (isalnum(postfix[i]) ){
            push(int(postfix[i])-48);
        }
        else{
            int a=pop();
            int b=pop();
            if (postfix[i]=='+'){
                push(a+b);
            }
            else if (postfix[i]=='-'){
                push(b-a);
            }
            else if (postfix[i]=='*'){
                push(a*b);
            }
            else{
                push(b/a);
            }

        }}
    
    
    seek();

}

