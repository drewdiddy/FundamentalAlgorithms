#include <iostream>
using namespace std;
//function that searches the array for the desired key
int linear(int arr[], int x){
	for(int i = 0; i < x; i++){
		if(arr[i] == x)
			return i;
	}
	return -1;
}

int main(){
	int x, s, i;
	//input number of elements & key
	cin >> x;
	cin >> s;
	//create dynamic allocated array & input element values
	int *arr = new int[x];
	for(i = 0; i < x; i++){
		cin >> arr[i];
	}
	int index = linear(arr, s);
	cout << index << "\n";
	delete[] arr;
}

