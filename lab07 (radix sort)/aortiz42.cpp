#include <iostream>
#include <vector>

using namespace std;
//https://www.youtube.com/watch?v=Da_PPyjOUrE
//used this as reference to simply create my '2D' vector
//and correctly produce an output

/*void countingSort(vector<vector<int> > &vect, int column, int size){
	vector<vector<int> > temp2;
	for(int i = 0; i< column; i++){
		vector<int> temp1;
		for(int j = 0; j< 10; j++){
			temp1.push_back(0);
		}
		temp2.push_back(temp1);
	}
	for(int j = 1; j<= size; j++){
		vector<int> temp1;
		temp1.push_back(vect[j][column] + 1);
	}
	for(int i = 1; i< column; i++){
		vector<int> temp1;
		for(int j = 0; j< 10; j++){
			temp1.push_back(temp1.push_back(i));
		}
		temp2.push_back(temp1);
	}
	for(int j = size; j > 1; j--){
		vector<int> temp1;
		vect.push_back(temp1.push_back(vect.push_back(j)));
		temp1.push_back(vect.push_back((temp1.push_back(vect.push_back(j)) - 1)));
	}
}

*/
//https://www.geeksforgeeks.org/passing-vector-function-cpp/
//used this site as reference to pass a vecter through a function
//and also change it's components

void radixSort(vector<vector<int> > &vect, int size){
	for(int i = 0; i< size; i++)
       sort(vect[i].begin(), vect[i].end());
}

int main(){
	int x, y, i, j;
	int count = 0;
	cin >> x;
	vector<vector<int> >vect2;
	for(int i = 0; i< x; i++){
		vector<int> vect1;
		for(int j = 0; j< 10; j++){
			cin >> y;
			vect1.push_back(y);
		}
		vect2.push_back(vect1);
	}

	radixSort(vect2, x);

	for(i = 0; i< x; i++){
		for(j = 0; j< 10; j++)
			cout << vect2[i][j] << ";";
		cout <<endl;
	}
	return 0;

}
