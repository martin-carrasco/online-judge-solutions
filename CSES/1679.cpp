#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
const int MAXN= 1e5 + 5;
int n, m, pos[MAXN];
vi adj[MAXN], ans;
bool visited[MAXN];

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

bool check_cycle(){
	for(int i = 1;i <= n;i++){
		pos[ans[i-1]] = i;	
	}

	for(int i=1;i <= n;i++){
		for (auto v : adj[i]){
			if (pos[i] > pos[v]) return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	topological_sort();
	if (check_cycle()){
		cout << "IMPOSSIBLE" << "\n";
		return 0;
	}

	for (auto node : ans){
		cout << node << " ";
	}
	cout << "\n";

	return 0;
}
