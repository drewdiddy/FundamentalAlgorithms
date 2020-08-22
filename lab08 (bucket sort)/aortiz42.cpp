#include <iostream>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

void bucketSort(double arr[], int size){
	list<double> *B = new list<double>[size];
	for(int i = 0; i< size; i++){
		int temp = floor(size*arr[i]);
		B[temp].push_back(arr[i]);
	}

	//sort individual buckets
	for(int i = 0; i< size; i++){
		B[i].sort();
	}

	//used this site as reference to conduct my concatenation and also to print my results
    for (int i = 1; i < size; i++)
    	B[i].merge(B[i-1]);

    for (list<double>::iterator it = B[size-1].begin(); it != B[size-1].end(); ++it)
    	cout << *it << '\n';
    delete[] B;
}

int main(){
	int x, i;
	//input array size
	cin >> x;
	double *arr = new double[x];
	//input element values
	for(i = 0; i< x; i++)
		cin >> arr[i];

	bucketSort(arr, x);
	delete[] arr;
}
