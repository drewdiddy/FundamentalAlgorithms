#include <iostream>

using namespace std;

int binary(int arr[], int x, int low, int s){
		if (low <= x){
			int mid = (low + x)/2;
			if(arr[mid] == s)
				return mid;
			if(arr[mid] > s)
				return binary(arr, mid - 1, low, s) ;
			return binary(arr, x, mid + 1, s);
	}
	return -1;
}

int main(){
	int x, s, i;
	//input array size
	cin >> x;
	if(x == 0)
		return -1;
	//input key to search for
	cin >> s;
	int *arr = new int[x];
	//input element values
	for(i = 0; i < x; i++){
		cin >> arr[i];
	}
	int index = binary(arr, x - 1, 0, s);
	cout << index;
	delete[] arr;

}
