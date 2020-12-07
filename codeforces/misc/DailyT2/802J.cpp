#include "bits/stdc++.h"

using namespace std;
using vi = vector<pair<int, int>>;

const int MAXN = 100 + 5;

bool vis[MAXN];
vi adj[MAXN]; 
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n-1;i++){
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}

	stack<pair<int, int>> q;
	q.push({0, 0});

	vis[0] = 1;
	int worst = 0;
	while(not q.empty()){
		int u = q.top().first;
		int sum = q.top().second;
		q.pop();

		for(auto [v, c] : adj[u]){
			if (vis[v]) continue;
			int accum = sum + c;
			q.push({v, accum});
			worst = max(worst, accum);
			vis[v] = 1;
		}
	}
	cout << worst << "\n";

	return 0;
}
