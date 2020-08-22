#include <iostream>
#include <list>

using namespace std;

//used list to implement my hash table
//I utilized the push_front function and the erase function

int main(){
	int m;
	cin >> m;
	list<int> *hashTable = new list<int>[m];
	char option;
	cin >> option;

	while(option != 'e'){
		if(option == 'i'){ //insert into hash
			int k, key;
			cin >> k;
			key = k % m;
			hashTable[key].push_front(k);
			cin >> option;
		}
		else if(option == 'd'){ //delete from hash
			int k, key;
			bool found = false;
			cin >> k;
			key = k % m;
			for (list<int>::iterator it = hashTable[key].begin(); it != hashTable[key].end(); ++it){
    			if(*it == k){
    				hashTable[key].erase(it);
    				cout << k << " : DELETED" << endl;
    				cout << "++++++++++++++++++++" << endl;
    				cin >> option;
    				found = true;
    				break;
    			}
    		}
    		if(found == false){
    			cout << k << " : DELETE FAILED" << endl;
    			cout << "++++++++++++++++++++" << endl;
    			cin >> option;
    		}	
		}
		else if(option == 's'){ //search in hash
			int k, key;
			bool found = false;
			int count = 0;
			cin >> k;
			key = k % m;
			for (list<int>::iterator it = hashTable[key].begin(); it != hashTable[key].end(); ++it){
    			if(*it == k){
    				cout << k << " : FOUND AT " << key << "," << count << endl;
    				cout << "++++++++++++++++++++" << endl;
    				cin >> option;
    				found = true;
    				break;
    			}
    		count++;
    		}	
    		if(found == false){
    			cout << k << " : NOT FOUND" << endl;
    			cout << "++++++++++++++++++++" << endl;
    			cin >> option;
   			}
		}
		else if(option == 'o'){ // output hash
			for(int i = 0; i < m; i++){
				cout << i << " : ";
				int size = hashTable[i].size();
				int count = 0;
				for(list<int>::iterator it = hashTable[i].begin(); it != hashTable[i].end(); ++it){
					if(count < size-1){
						cout << *it << "->";
						count++;
					}
					else
						cout << *it;
				}
				cout << endl;
			}
			cout << "++++++++++++++++++++" << endl;
			cin >> option;
		}
		else
			break;
	}
	delete[] hashTable;
}
