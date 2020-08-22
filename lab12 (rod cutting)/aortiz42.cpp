#include <iostream>
#include <climits>

using namespace std;

void bottomUpCutRod(int prices[], int size){
	int *r = new int[size];
	int *s = new int[size];
	r[0] = 0;
	for(int j = 1; j <= size; j++){
		int q = INT_MIN;
		for(int i = 1;i <= j; i++){
			if(q < (prices[i] + r[j-i])){
				q = (prices[i] + r[j-i]);
				s[j] = i;
			}
		}
		r[j] = q;
	}
	cout << r[size] << endl;
	while(size > 0){
		cout << s[size] << " ";
		size = size - s[size];
	}
	cout << "-1" << endl;
	//cout << endl;
	delete[] r;
	delete[] s;
}

int main(){
	int size, i;
	//input array size
	cin >> size;
	int *prices = new int[size+1];
	//rod of size zero cannot be sold (can't sell nothing)
	prices[0] = 0;
	for(i = 1; i <= size; i++)
		cin >> prices[i];
	bottomUpCutRod(prices, size);
	delete[] prices;
	return 0;
}
