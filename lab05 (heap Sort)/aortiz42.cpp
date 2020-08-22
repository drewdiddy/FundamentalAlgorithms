#include <iostream>

using namespace std;

int heapSize; 	//global variable to keep value of heapSize without passing
				//through funtions

void maxHeapify(int arr[], int x){
	int largest;
	int l = (2*x + 1);
	int r = (2*x + 2);
	if(l < heapSize && arr[l] > arr[x])
		largest = l;
	else largest = x;
	if(r < heapSize && arr[r] > arr[largest])
		largest = r;
	if(largest != x){
		//in order to exchange values with two variables, used the swap fucntion
		swap(arr[x], arr[largest]);
		maxHeapify(arr, largest);
	}

}

void buildMaxHeap(int arr[], int size){
	heapSize = size;
	for(int i = (size/2) -1; i >= 0; i--)
		maxHeapify(arr, i);

}

void heapSort(int arr[], int size){
	buildMaxHeap(arr, size);
	for(int i = (size -1); i >= 1; i--){
		swap(arr[0], arr[i]);
		heapSize--;
		maxHeapify(arr, 0);
	}
}

int main(){
	int x, i;
	//cout << "please enter array length: ";
	cin >> x;
	int *arr = new int[x];
	//cout << "please enter array inputs: \n";
	for(i = 0; i < x; i++)
		cin >> arr[i];

	heapSort(arr, x);

	//print results
	for(i = 0; i< x; i++)
		cout << arr[i] << ";";
	delete[] arr;
}
