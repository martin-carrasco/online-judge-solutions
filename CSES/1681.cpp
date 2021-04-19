#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 +7;
bool visited[MAXN];
int n,m;
vi adj[MAXN], ans;
vi adj_back[MAXN];
ll paths[MAXN];

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
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

void cnt_ways(int a, int b){
	paths[a] = 1LL;	
	for (int i = 1;i <= n;i++){
		int x = ans[i-1];
		for (auto in_vert : adj_back[x]){
			paths[x] = (paths[x] +  paths[in_vert]) % MOD;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_back[v].push_back(u);
	}

	topological_sort();
	cnt_ways(1, n);

	cout << paths[n] << "\n";

	return 0;
}
