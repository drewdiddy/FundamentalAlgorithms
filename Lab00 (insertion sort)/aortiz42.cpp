#include <iostream>
using namespace std;

int main() {
	int x, i, j;
	//enter number of elements to be sorted
	cin >> x;
	int *arr = new int[x];
	//enter each element value
	for(i = 0; i < x; i++){
		int y;
		cin >> y;
		arr[i] = y;
	}
	//insertion sort algorithm
	for(i = 1; i < x; i++){
		int key = arr[i];
		j = (i-1);
		while(j>=0 && arr[j] < key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
	//print out results
	for(i = 0; i < x; i++){
		cout << arr[i] << ";";
	}
	delete[] arr;
}
