#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2* 1e5 + 100;
vi adj[MAXN];
int color[MAXN];
vector<ii> ans;

bool bfs(int v){
	queue<pair<int, bool>> q;
	q.push({v, false});

	while(not q.empty()){
		pair<int, bool> cu = q.front();
		int u = cu.first;
		int dir = cu.second;
		q.pop();

		bool valid = true;
		for(auto w : adj[u]){
			if (color[w] == 0){
				color[w] = color[u] == 1 ? 2 : 1;	

				if (not dir) {
					ans.push_back({u, w});
					q.push({w, !dir});
				} else{
					ans.push_back({w, u});
					q.push({w, !dir});
				}

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
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ii> local_ans;
	for(int i = 0;i < m;i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		local_ans.push_back({u, v});
	}

	bool colorable = false;
	for(int i = 1;i <= n;i++){
		if (adj[i].empty()){
			continue;
		}
		color[i] = 1;
		colorable = bfs(i);
		break;
	}

	if (not colorable)
		cout << "NO" << "\n";
	else{
		cout << "YES" << "\n"; 
		for(auto edge : local_ans){
			auto [u, v] = edge;
			cout << 2 - color[u];
		}
		cout << "\n";
	}
	return 0;
}
