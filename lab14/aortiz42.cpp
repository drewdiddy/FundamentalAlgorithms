#include <iostream>
#include <queue>
#include <string>
//http://www.cplusplus.com/reference/queue/priority_queue/priority_queue/
//for priority queue

using namespace std;

string str = "";

struct Node
{
	int frequency;
	Node *left;
	Node *right;
} *root;


//https://www.geeksforgeeks.org/implement-min-heap-using-stl/
//stl priority queue min heap
struct comparator{
	bool operator()(Node *left, Node *right){
		return left->frequency > right->frequency;
	}
};

void binaryConversion(Node *code, string str){
	if(code == NULL)
		return;
	binaryConversion(code->left, str + "0");
	binaryConversion(code->right, str + "1");
}

Node* huffman(int size, int arr[]){
	int i;
	Node *x = new Node;
	Node *y = new Node;
	priority_queue<Node*, vector<Node*>, comparator > queue;
	for(i = 0; i < size; i++){
		root = new Node;
		root->left = NULL;
		root->right = NULL;
		root->frequency = arr[i];
		queue.push(root);
	}

	for(i = 0; i < size; i++){
		root = new Node;
		root->left = x = queue.top();
		queue.pop();
		root->right = y = queue.top();
		queue.pop();
		root->frequency = x->frequency + y->frequency;
		queue.push(root);
	}
	return (queue.top());
}

int main(){
	int numOfChars, i;
	Node *code = new Node;
	cin >> numOfChars;

	int *arr = new int[numOfChars];
	for(i = 0; i < numOfChars; i++)
		cin >> arr[i];
	code = huffman(numOfChars, arr);
	binaryConversion(code, str);
	cout << str;
	return 0;
}
