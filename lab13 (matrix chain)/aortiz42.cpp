#include <iostream>
#include <climits>

using namespace std;

void printOptimalParens(int *s[], int i, int j){
	if(i==j)
		cout << "A" << (i-1);
	else{
		cout<< "(";
		printOptimalParens(s, i, s[i][j]);
		cout << ".";
		printOptimalParens(s, s[i][j]+1, j);
		cout << ")";
	}
}

void matrixChainOrder(int size, int matrixDimensions[]){
	 //size = size-1;
	 int i, j, l, k, q;
	 //creating new '2D array'
	 int **m = new int*[size];
	 for(i = 0; i< size;i++)
	 	m[i] = new int[size];

	int **s = new int*[size];
	for(i = 0; i< size;i++)
	 	s[i] = new int[size];

	 //algorithm
	for(i = 1; i< size; i++)
		m[i][i] = 0;
	for(l = 2; l< size; l++){
		for(i = 1; i< (size-l+1); i++){
			j = i+l-1;
			m[i][j] = INT_MAX;
			for(k = i; k<= (j-1); k++){
				q = m[i][k] + m[(k+1)][j] + (matrixDimensions[i-1]*matrixDimensions[k]*matrixDimensions[j]);
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	cout << m[1][size-1] << endl;
	printOptimalParens(s, 1, size-1);
	cout << endl;
	//delete dynamic created '2D arrays'
	for(i = 0; i < size; ++i)
		delete [] m[i];
	delete [] m;

	for(i = 0; i < size; ++i)
		delete [] s[i];
	delete [] s;

}

int main(){
	int size, i;
	//size is only to declare the amt of matrices
	cin >> size;
	size = size+1;
	//creating matrix dimensions
	int *arr = new int[size];
	for(i = 0; i< size; i++)
		cin >> arr[i];
	matrixChainOrder(size, arr);
	delete[] arr;
}