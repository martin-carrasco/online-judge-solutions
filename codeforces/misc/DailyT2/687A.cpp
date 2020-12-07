#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1e5 + 5;
vi adj[MAXN];
int color[MAXN];

vi A, B;

bool bfs(int v){
	queue<int> q;
	color[v] = 1;
	A.push_back(v);
	q.push(v);

	while(not q.empty()){
		int u = q.front();
		q.pop();
 
		for(auto w : adj[u]){
			if (color[w] == 0){
				color[w] = color[u] == 1 ? 2 : 1;	
				if (color[w] == 1)
					A.push_back(w);
				else
					B.push_back(w);
				q.push(w);
				continue;
			}
			if (color[w] == color[u]){
				return false;
			}
		}
	}
	return true;
}
 

int main(){
	int n, m;
	cin >> n >> m;
		
	for(int i = 0;i < m;i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool res = false;
	for(int i = 1;i <= n;i++){
		if (adj[i].size() == 0) continue;
		if (color[i] != 0) continue;
		res = bfs(i);

		if(not res)
			break;
	}

	if (not res)
		cout << -1 << "\n";
	else{
		cout << A.size() << "\n";
		for(int v : A)
			cout << v << " ";
		cout << "\n";
		cout << B.size() << "\n";
		for(int v : B)
			cout << v << " ";
		cout << "\n";
	}

	return 0;
}
