#include <iostream>
//#include <cmath> used for -INFINITY but didnt output correct results
//so changed to climits using INT_MIN instead for minimum integer
#include <climits>

using namespace std;

int maxCrossing(int arr[], int low, int mid, int high){
	int leftMaxSum = INT_MIN; 
	int rightMaxSum = INT_MIN;
	int sum = 0;
	for(int i = mid; i >= low; i--){ //for the lower array
		sum = sum + arr[i];
		if(sum >leftMaxSum)
			leftMaxSum = sum;
	}
	sum = 0;
	for(int j = mid+1; j <= high; j++){ //for the higher array
		sum = sum + arr[j];
		if(sum > rightMaxSum)
			rightMaxSum = sum;
	}
	return (leftMaxSum + rightMaxSum);

}

int maxSubArray(int arr[], int low, int high){
	int mid;
	if(high == low)
		return arr[low];
	else
		mid = (low + high)/2;
		int leftSum = maxSubArray(arr, low, mid);
		int rightSum = maxSubArray(arr, mid + 1, high);
		int crossSum = maxCrossing(arr, low, mid, high);
		
		if(leftSum >= rightSum && leftSum >= crossSum)
			return leftSum;
		else if(rightSum >= leftSum && rightSum >= crossSum)
			return rightSum;
		else
			return crossSum;
}

int main(){
	int x, n, i;
	//input array size
	cin >> x;
	int *arr = new int[x];
	//input array indeces
	for(i = 0; i< x; i++)
		cin >> arr[i];
	
	n = maxSubArray(arr, 0, x-1);
	cout << n;
	delete[] arr;
	return 0;
}
