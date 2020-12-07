#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1e6 + 5;
vi adj[MAXN];
bool vis[MAXN];

vi A;

void bfs(int v, bool first){
	stack<pair<int, bool>> q;
	vis[v] = first;
	q.push({v, first});

	while(not q.empty()){
		pair<int, bool> cu = q.top();
		int u = cu.first;
		bool pr = cu.second;
		q.pop();

		if (pr)
			A.push_back(u);
 
		for(auto w : adj[u]){
			if (vis[w]) continue;
			q.push({w, !pr});
			vis[w] = 1;
		}	
	}
}
 

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
			
		for(int i = 0;i < m;i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bfs(1, false);
		if (A.size() > n / 2){
			A.clear();
			for(int i = 1;i <= n;i++)
				vis[i] = 0;
			bfs(1, true);
		}
		cout << A.size() << "\n";
		for(int v : A)
			cout << v << " ";
		cout << "\n";
		/*cout << B.size() << "\n";
		for(int v : B)
			cout << v << " ";
		cout << "\n";*/

		for(int i = 1;i <= n;i++) {
			adj[i].clear();
			vis[i] = 0;
		}
		A.clear();
	}

	return 0;
}
