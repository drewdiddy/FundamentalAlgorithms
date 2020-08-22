#include <iostream>
#include <string>
#include <sstream>
//#include <stdlib.h>

using namespace std;

struct Node
{
	int key_value; // Key value of the node
	Node *left; // Pointer to the left child node
	Node *right; // Pointer to the right child node
	Node *parent; // Pointer to the parent node
} *root;

Node *search(int key, Node *leaf){
	if(leaf != NULL)
	{
		if(key==leaf->key_value)
			return leaf;
		if(key< leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}

	else
		return NULL;
}

Node *treeMin(Node *x){
	while(x->left != NULL)
		x = x->left;
	return x;
}

void transplant(Node *current, Node *leaf){
	if(current->parent == NULL)
		root = leaf;
	else if(current == current->parent->left)
		current->parent->left = leaf;
	else
		current->parent->right = leaf;
	
	if(leaf != NULL)
		leaf->parent = current->parent;
}

void deleteNode(int key){
	Node *gotcha = search(key, root);
	if(gotcha != NULL){
		if(gotcha->left == NULL){
			transplant(gotcha, gotcha->right);
		}
		else if(gotcha->right == NULL){
			transplant(gotcha, gotcha->left);
		}
		else{
			Node *temp = treeMin(gotcha->right);
			if(temp->parent != gotcha){
				transplant(temp, temp->right);
				temp->right = gotcha->right;
				temp->right->parent = temp;
			}

			transplant(gotcha, temp);
			temp->left = gotcha->left;
			temp->left->parent = temp;
		}

	}
}	

void insert2(int key, Node *leaf){
	if(key < leaf->key_value){
		if(leaf->left != NULL)
			insert2(key, leaf->left);
		else{
			leaf->left = new Node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;// SETS LEFT CHILD OF CHILD NODE TO NULL
			leaf->left->right = NULL;// SETS RIGHT CHILD OF CHILD NODE TO NULL
			leaf->left->parent = leaf;		
		}
	}
	else if(key >= leaf->key_value){
		if(leaf->right != NULL)
			insert2(key, leaf->right);
		else{
			leaf->right = new Node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
			leaf->right->parent = leaf;		
		}
	}
}

void insert(int key){
	if(root != NULL)
		insert2(key, root);
	else
	{	//SET VALUE FOR ROOT AND MAKE ITS CHILDREN NULL
		root = new Node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
	}
}

void preorderTreeWalk(Node *printNode){
	if(printNode != NULL){
		cout << printNode->key_value << endl;
		preorderTreeWalk(printNode->left);
		preorderTreeWalk(printNode->right);
	}
}

void postorderTreeWalk(Node *printNode){
	if(printNode != NULL){
		postorderTreeWalk(printNode->left);
		postorderTreeWalk(printNode->right);
		cout << printNode->key_value << endl;
	}
}

void inorderTreeWalk(Node *printNode){
	if(printNode != NULL){
		inorderTreeWalk(printNode->left);
		cout << printNode->key_value << endl;
		inorderTreeWalk(printNode->right);
	}
}

int main(){
	string option;
	/*
	enter an option
	
	i#: insert
	d#: delete
	pre: preorder traversal
	post: post-order traversal
	in: in-order traversal
	e: exit

	where # represents any integer
	*/
	cin >> option;
	string temp;

	temp = option[1]; //only has the number in here

	stringstream ss(temp);
	int key = 0;
	ss >> key; //convert to int

   	//cout << "this is string: " << option[0] <<"this is int: " << key << endl;

	while(option != "e"){
		if(option == "i"){
			int key;
			cin >> key;
			insert(key);
			cin >> option;
		}
		else if(option == "d" ){
			int key;
			cin >> key;
			deleteNode(key);
			cin >> option;	
		}
		else if(option == "pre"){ // REMEMBER TO CHECK IF OPTION[0] == P --> OPTION[1] == R || O
			preorderTreeWalk(root);
			cout << "++++++++++++++++++++\n";
			cin >> option;
		}
		else if(option == "post"){
			postorderTreeWalk(root);
			cout << "++++++++++++++++++++\n";
			cin >> option;
		}
		else if(option == "in"){
			inorderTreeWalk(root);
			cout << "++++++++++++++++++++\n";
			cin >> option;
		}
		else
			break;
	}
}
