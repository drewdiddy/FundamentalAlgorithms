#include <iostream>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

struct Graph {
	vector<int> vertices;
	map<pair<int,int>,int> edges;
	bool FindVertex(int);
	void prim(void);
	//int FindEdgeCost(string vert1, string vert2);
};

void Graph::prim(Graph g, int root){
	int u;
	map<int, int> key;
	map<int, int> pi;
	list<string>::iterator it;
	//map<pair<string,string>,int>::iterator eit;

	for(it=vertices.begin(); it!=vertices.end(); it++) {
		key[*it] = INT_MAX;
		pi[*it] = -1;
		//queue.push_back(*it);
	}
	//queue.erase(queue.begin());
	key[root] = 0;
	list<int> queue = g.vertices;
	queue.sort();
	while(!queue.empty()){
		u = queue.front();
		queue.pop_back();
	}

}

bool FindVertex(int vert1) {
	//https://stackoverflow.com/questions/24139428/check-if-element-is-in-the-list-contains
	//used in place of contains to find if string is in list
	bool found = find(vertices.begin(), vertices.end(), vert1) != vertices.end();
	return found;
}

int main(){
	Graph g;
	pair<int, int> path_cost;
	int i,root = 0,numOfVert,numOfEdge,vertex1,vertex2,weight;
	cin >> numOfVert;
	cin >> numOfEdge;
	for(i = 0; i < numOfEdge; i++){
		cin >> vertex1 >> vertex2 >> weight;
		if(FindVertex(vertex1) == false){
			g.vertices.push_back(vertex1);
		}
		if(FindVertex(vertex2) == false){
			g.vertices.push_back(vertex2);
		}

		path_cost.first = vertex1;
		path_cost.second = weight;
		g.edges.insert(path_cost, vertex2);
	}
	prim(g, root);
}
