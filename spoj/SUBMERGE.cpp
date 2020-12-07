#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1e4 + 5;
int n, m, timer, ans;
vi adj[MAXN];
bool seen[MAXN];
vector<bool> visited;
vi tin, low;

void IS_CUTPOINT(int v){
	if (not seen[v])
		ans++;
	seen[v] = 1;
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		ans = 0;
		cin >> n >> m;
		if (not n and not m)
			break;

		int u, v;
		for(int i = 0;i < m;i++){
			cin >> u >> v;
			--u;
			--v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		find_cutpoints();
		cout << ans << "\n";

		for(int i = 0; i < n;i++){
			seen[i] = 0;
			adj[i].clear();
		}
	}
	return 0;

}
