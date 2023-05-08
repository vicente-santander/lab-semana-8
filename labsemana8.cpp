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

Node* remove(Node* root, int data){  // ejercicio 7

	// Caso base: si el árbol está vacío
	if (root == NULL) {
		return root;
	}
	
	// Buscamos el nodo que deseamos eliminar
	if (data < root->data) {
	    root->left = remove(root->left, data);
	} else if (data > root->data) {
	    root->right = remove(root->right, data);
	} else {	
	    // Caso 1 y 2: el nodo no tiene hijos o tiene un hijo
	    if (root->left == NULL) {
	        Node* temp = root->right;
	        delete root;
	        return temp;
	    } else if (root->right == NULL) {
	        Node* temp = root->left;
	        delete root;
	        return temp;
	    }
	    
	    // Caso 3: el nodo tiene dos hijos
	    Node* temp = minval(root->right);
	    root->data = temp->data;
	    root->right = remove(root->right, temp->data);
	}
	
	return root;
}

int main(){
	Node *root = NULL;
	
	
	root = insert(root,3);
	root = insert(root,5);
	root = insert(root,2);
	root = insert(root,9);
	root = insert(root,12);
	root = insert(root,1);
	
	printTree(root);
	
	search(root,9);
	
	
	cout << "el valor minimo es: " << minval(root)->data <<endl;
	cout << "el valor maximo es: " << maxval(root)->data <<endl;
	
	remove(root, 2);
	remove(root, 3);
	remove(root, 10);
	
	
	printTree(root);
	
	
	return 0;
}

