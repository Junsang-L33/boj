#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* alloc_new_node(int data){
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

Node* make_tree(Node* root, int data){
	if(root == NULL){
		return	root = alloc_new_node(data);	//root노드가 없으면 생성
	}
	if(root->data < data){
		root->right = make_tree(root->right, data); //data가 root->data보다 크면 오른쪽노드로 생성	
	}	
	if(root->data > data){
		root->left = make_tree(root->left, data);	 //data가 root->data보다 작으면 왼쪽노드로 생성 
	}

	return root;
}

void post_order(Node* root){ //후위순회
	if(root == NULL){
		return;	
	}
	post_order(root->left);
	post_order(root->right);
	printf("%d ", root->data);
	printf("\n");
}

void free_tree(Node* root){
	if(root==NULL){
		return;	
	}
	free_tree(root->left);
	free_tree(root->right);
	free(root);

}

int main(int argc, char* agrv[]){
	Node* root = NULL;	
	int data;

	while( scanf("%d ", &data) != EOF){ //몇개의 입력값이 들어올지 모르기때문에 EOF를 이용
		root = make_tree(root, data);	
	}	

	post_order(root);
	free_tree(root);	
	return 0;
}
