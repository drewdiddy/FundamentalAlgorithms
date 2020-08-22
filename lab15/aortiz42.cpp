#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Graph {
	list<string> vertices;
	map<pair<string,string>,int> edges;
	void PrintOut(void);
	void AddEdge(string,string,int);
	bool FindVertex(string);
	int FindEdgeCost(string vert1, string vert2);
	int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
	list<string>::iterator it;
	map<pair<string,string>,int>::iterator eit;

	for(it=vertices.begin(); it!=vertices.end(); it++) {
		cout << *it << endl;
	}

	for(eit = edges.begin(); eit != edges.end(); eit++) {
		cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
	}
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
	//https://www.geeksforgeeks.org/pair-in-cpp-stl/
	//used to understand pairs
	pair<string, string> strs;
	strs.first = vert1;
	strs.second = vert2;
	edges.insert(pair<pair<string, string>, int> (strs, weight));
}

bool Graph::FindVertex(string vert1) {
	bool found = find(vertices.begin(), vertices.end(), vert1) != vertices.end();
	return found;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
	map<pair<string,string>,int>::iterator eit;
	for(eit = edges.begin(); eit != edges.end(); eit++) {
		if(vert1 == (*eit).first.first){
			if(vert2 == (*eit).first.second){
				return ((*eit).second);
			}
		}
	}
	return -1;
}

int Graph::IsReachable(string vert1, string vert2) {
	map<string,string> color;
	map<string,int> d;
	map<string,string> pi;
	queue<string> queue;
	list<string>::iterator it;
	map<pair<string,string>,int>::iterator eit;
	string top, strPair;

	for(it=vertices.begin(); it!=vertices.end(); it++) {
		color[*it] = "WHITE";	//'color' of string
		d[*it] = INT_MAX;		//num of edges (return this)
		pi[*it] = "NIL";		//predecessor of string
	}
	color[vert1] = "GRAY";
	d[vert1] = 0;
	pi[vert1] = "NIL";
	queue.push(vert1);
	while(!queue.empty()) {
		top = queue.front();
		queue.pop();
		for(eit = edges.begin(); eit != edges.end(); eit++) {
			if(top == (*eit).first.first) {
				strPair = (*eit).first.second;
				if(color[strPair] == "WHITE") {	//unvisited string
					color[strPair] = "GRAY";
					d[strPair] = d[top] + 1;
					pi[strPair] = top;
					queue.push(strPair);
				}
			}
		}
		color[top] = "BLACK";
	}
	if(d[vert2] != INT_MAX)		//destination string.edges total (if reached)
		return d[vert2];
	else
		return -1;
}

int main() {
	Graph G;
	string vertexName, startVertex, endVertex;
	int weight;
	cin >> vertexName;
	while(vertexName != "END"){
		G.vertices.push_back(vertexName);
		cin >> vertexName;
	}
	cin >>startVertex;
	while(startVertex != "END"){
		if(!G.FindVertex(startVertex)){
			cin >> startVertex;
			continue;
		}
		cin >> endVertex;
		if(!G.FindVertex(endVertex)){
			cin >> startVertex;
			continue;
		}
		else{
			cin >> weight;
			G.AddEdge(startVertex, endVertex, weight);
			cin >> startVertex;
		}
	}
	G.PrintOut();

	int opCode, cost, numOfEdges;
	string A, B;
	cin >> opCode;
	while(opCode != 0){
		if(opCode == 1){
			cin >> A;
			if(G.FindVertex(A) == true)
				cout << 1 << endl;
			else
				cout << 0 << endl;
			cin >> opCode; 
		}

		else if(opCode == 2){
			cin >> A >> B;
			cost = G.FindEdgeCost(A, B);
			cout << cost << endl; 
			cin >> opCode;
		}

		else if(opCode == 3){
			cin >> A >> B;
			numOfEdges = G.IsReachable(A, B);
			cout << numOfEdges << endl;
			cin >> opCode;
		}

		else
			return 0;
	}
	return 0;
}
