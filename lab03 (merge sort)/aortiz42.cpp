#include <iostream>
#include <cmath>

using namespace std;

void merge(int arr[], int low, int mid, int high){
	int i, j, k; 
    int n1 = mid - low + 1; 
    int n2 =  high - mid; 
  
    int Left[n1], Right[n2]; //temp arrays 
  	for (i = 0; i < n1; i++) 
        Left[i] = arr[low + i]; //store values in temp arrays
    for (j = 0; j < n2; j++) 
        Right[j] = arr[mid + j + 1]; //for the next indices that must be compared
 
    i = 0; 
    j = 0; 
    k = low; 
    while (i < n1 && j < n2){ //merge!
        if (Left[i] <= Right[j]){ // if element in left array <= element in right
            arr[k] = Left[i]; // store lesser value
            i++; 
        } 
        else{ 
            arr[k] = Right[j]; // if left element was > right, store that value
            j++; 
        } 
        k++; 
    }
    //for the cases where the first while loop fails due to &&, finishes the other side
    while (i < n1){ 
        arr[k] = Left[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
        arr[k] = Right[j]; 
        j++; 
        k++; 
    }
}

void mergeSort(int arr[], int low, int high){
	int mid;
	if(low < high){
		mid = (low + high)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
	return;
}

int main(){
	int x, i;
    //input array size
	cin >> x;
	int *arr = new int [x];
    //input element values
	for(i = 0; i < x; i++)
		cin >> arr[i];

	mergeSort(arr, 0, x - 1);

    //print results
	for(i = 0; i < x; i++)
		cout << arr[i] << ";";
	delete[] arr;
	return 0;	
}


