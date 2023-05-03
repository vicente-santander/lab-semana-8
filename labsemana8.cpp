#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data) { // ejercicio 1
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insert(Node* root, int data){ // ejercicio 2 
	if(root == NULL){
		root = createNode(data);
	}
	else{
		if(root->data > data){
			root->left = insert(root->left, data);
		}
		else{
			root->right = insert(root->right, data);
		}
	}
	return root;
}


void printTree(Node* root){ // ejercicio 3
	
	if (root == NULL) {
		return;
	}
	
	printTree(root->left);
	cout << root->data << " ";
	printTree(root->right);
}

void search(Node* root, int num){ // ejercicio 4
	if(root == NULL){
		cout << endl<< "El arbol esta vacio." << endl;
		return;
	}
	
	if(root->data == num){
		cout << endl << num << " se encuentra en el arbol." << endl;
		return;
	}
	
	if(root->data > num){
		search(root->left, num);
	}
	else{
		search(root->right, num);
	}		
}

Node* minval(Node* root){ // ejercicio 5
	if(root->left == NULL){
		return root;
	}
	minval(root->left);
}

Node* maxval(Node* root){ // ejercicio 6
	if(root->right == NULL){
		return root;
	}
	maxval(root->right);
}

void free(Node* root, int elim) {
	
	
	
}

int main(){
	Node *root = NULL;
	
	
	root = insert(root,3);
	root = insert(root,5);
	root = insert(root,2);
	root = insert(root,9);
	
	printTree(root);
	
	search(root,9);
	
	
	cout << "el valor minimo es: " << minval(root)->data <<endl;
	cout << "el valor maximo es: " << maxval(root)->data <<endl;
	free(root,5);
	
	
	
	return 0;
}

