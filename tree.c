#include <stdio.h>

typedef struct node{
    NODE *parent;
    NODE *left;
    NODE *right;
    int num;
}NODE;

typedef struct tree{
    NODE *head;
}TREE;

NODE* NEWNODE(int i){
    NODE *out=malloc(sizeof(NODE));
    out->num=i;
    out->parent=NULL;
    out->left=NULL;
    out->right=NULL;
    return out;
}

TREE* NEWTREE(void){
    TREE *out=malloc(sizeof(TREE));
    out->head=NULL;
    return out;
}

void TREEINSERT(TREE *t,NODE *n){
    if(t->head==NULL) t->head=n;
    else{
        NODE *search=t->head;
        while(search->left!=NULL&&search->right!=NULL){
            if(search->num>n->num&&search->left!=NULL){
                search=search->left;
            }
            if(search->num<=n->num&&search->right!=NULL){
                search=search->right;
            }
            if(search->num>n->num&&search->left==NULL){
                n->parent=search;
                search->left=n;
                return 0;
            }
            if(search->num<=n->num&&search->right==NULL){
                n->parent=search;
                search->right=n;
                return 0;
            }
        }

    }
}

void PRINTNODE(NODE *n){
    if(n==NULL) return 0;
    PRINTNODE(n->left);
    printf("%d\n",n->num);
    PRINTNODE(n->right);
}

void PRINTTREE(TREE *t){
    if(t->head==NULL){
        printf("NOTHING\n");
        return 0;
    }
    else{
        PRINTNODE(t->head);
    }
}

int main(void){
    TREE *t=NEWTREE();
    int list[]={1,8,6,9,4,2,5,7,3};
    int i;
    for(i=0;i<9;i++){

    }
    return 0;
}
