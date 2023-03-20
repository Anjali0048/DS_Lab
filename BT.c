#include <stdio.h>
#include <stdlib.h>

struct node{
	int data ;
	struct node *left ;
	struct node *right ;
};

struct node* maketree(){
	struct node *p ;
	int info ;
	scanf("%d", &info) ;
	if(info == -1) return NULL ;
	p = (struct node *)malloc(sizeof(struct node)) ;
	p->data = info ;
	printf("Enter the left child of %d : ",info );
	p->left = maketree() ;
	printf("Enter the right child of %d : ",info );
	p->right = maketree() ;
	return p ;
}

void preorder(struct node *t){
	if(t!=NULL){
		printf("%d->", t->data) ;
		preorder(t->left) ;
		preorder(t->right) ;
	}
}

void postorder(struct node *t){
	if(t!=NULL){
		postorder(t->left) ;
		postorder(t->right) ;
		printf("%d->", t->data) ;
	}	
}

void inorder(struct node *t){
	if(t!=NULL){
		inorder(t->left) ;
		printf("%d->", t->data) ;
		inorder(t->right) ;
	}
}

int main(){
	struct node *root ;
  printf("Enter the info or -1 for null : ");
	root = maketree();

	printf("Preorder: ");
	preorder(root) ;
	printf("\n Postorder:");
	postorder(root) ;
	printf("\n Inorder:");
	inorder(root);

	return 0;
}
