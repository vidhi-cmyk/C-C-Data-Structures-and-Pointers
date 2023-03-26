// BINARY SEARCH TREE
// Value of all the nodes in left tree is lesser than node and value to the right is greater


//defining our binary node structure. We will create nodes in heap using malloc

#include <stdio.h>
#include <iostream>
struct bstnode{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

bstnode* NewNode(int data){
    struct bstnode* newnode=(struct bstnode*)malloc(sizeof(bstnode));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=data;
    return newnode;

}


bstnode* Insert(bstnode* root,int data){ //as we are implementing recursion, the root is no longer the global rootptr
     // have to pass address to make changes there
    if (root==NULL){
        root=NewNode(data); 
    }
    else{
        if(root ->data >=data){
            root->left=Insert(root->left,data);
        }
        else{
            root->right=Insert(root->right,data);
        }
    }
    return root;}

bool Search(bstnode* node,int data)  {
    if(node==NULL) return false;
    else if(node->data==data) return true;

    else if(node->data>data) return Search(node->left,data);
    else return Search(node->right,data);
}  

int Max(bstnode* root){
    if (root==NULL){
        printf("empty bst");
        return -1;
    }
    else if (root->right==NULL){
        return root->data;
    }
    return Max(root->right);  
}

int Min(bstnode* root){
    if (root==NULL){
        printf("empty bst");
        return -1;
    }
    else if (root->left==NULL){
        return root->data;
    }
    return Min(root->left);  
}

int Height(bstnode* root){
    if (root==NULL){
        return -1;
    }
    int max=(Height(root->left)>=Height(root->right))? Height(root->left):Height(root->right);
    return max +1;
}

void Preorder(bstnode* root){
    if (root==NULL) return;
    else{
        printf("%d",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

bool isBst(bstnode* node){
    if (node==NULL) return true;
    else if (node->left->data <= node->data && 
    node->right->data >= node->data &&
        isBst(node->left) &&
        isBst(node->right)) return true;
    else return false;
}

bstnode* Delete(bstnode* root, int data){
    //first we have to find the data
    if (root==NULL) return NULL;
    else if(root->data<data ) root->right=Delete(root->right,data);
    else if(root->data>data) root->left=Delete(root->left,data);
    else //found the value
    {
        //Case 1: Leaf node
        if(root->left==NULL && root->right==NULL) {
            free(root);
            root=NULL;}
        //Case 2: One Child
        else if((root->left==NULL)){
            struct bstnode* temp=root;
            root=root->right;
            free(temp);
        }
        else if((root->right==NULL)){
            struct bstnode* temp=root;
            root=root->left;
            free(temp);
        }
        else{
            root->data=Min(root->right);
            root->right=Delete(root->right,root->data);
        }
        

    }
    return root;

}


int main(){
    struct bstnode* rootptr; //defining separately to make the root pointer a global variable
    rootptr =NULL;
    rootptr=Insert(rootptr,15);
    rootptr=Insert(rootptr,20);
    rootptr=Insert(rootptr,10);
    rootptr=Insert(rootptr,25);
    rootptr=Insert(rootptr,35);
    rootptr=Delete(rootptr,20);

    
    printf("Maximum data : %d",Max(rootptr));

    
    if (Search(rootptr,15)){printf("Yes");}
    else printf("No");
    printf("%d\n",Height(rootptr));
    Preorder(rootptr);
    if(isBst(rootptr)) printf("yes");
    else printf("no");



}
