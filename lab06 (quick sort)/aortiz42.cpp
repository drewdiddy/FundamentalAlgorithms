#include<iostream>
#include <cstdlib>

using namespace std;

int partition(int arr[], int low, int high){
	int x = arr[high];
	int i = low-1;
	for(int j = low; j< high; j++){
		if(arr[j] <= x){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return (i+1);
}

int randomizedPartition(int arr[], int low, int high){
	srand (time(NULL));
	int random = rand() % (high-low + 1) + low; //randomized selection from low to (high-low + 1)
	// used this link: http://www.cplusplus.com/reference/cstdlib/rand/
	// to learn how to randomize selection of pivot for a given set
	//cout << "random num is: " << random << endl;
	swap(arr[high], arr[random]);
	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		int mid = randomizedPartition(arr, low, high);
		quickSort(arr, low, mid -1);
		quickSort(arr, mid +1, high);
	}
}

int main(){
	int x, i;
	//input array size
	cin >> x;
	int *arr = new int[x];
	//input element values
	for(i = 0; i< x; i++)
		cin >> arr[i];

	quickSort(arr, 0, x-1);

	//print results
	for(i = 0; i< x; i++)
		cout << arr[i] << ";";
	delete[] arr;
}
