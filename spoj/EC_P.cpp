#include "bits/stdc++.h"

using namespace std; 
using vi = vector<int>;

const int MAXN = 700 + 5;
int n, m, timer;

vi adj[MAXN];
vector<bool> visited;
vi tin, low;
vector<pair<int, int>> ans;
set<pair<int, int>> seen;

void IS_BRIDGE(int u, int v){
	if (seen.count({u,v}) or seen.count({v, u}))
		return;
	if (u > v)
		seen.insert({v, u});
	else
		seen.insert({u, v});
}
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, t_p;
	cin >> t;
	t_p = t;
	while(t--){
		cin >> n >> m;
		int u,v;
		for(int i = 0;i < m;i++){
			cin >> u >> v;
			--u;
			--v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		find_bridges();
	
		cout << "Caso #" << t_p - t << "\n";
		if (seen.size() == 0)
			cout << "Sin bloqueos" << "\n";
		else {
			cout << seen.size() << "\n";
			for (auto [v, u] : seen){
				cout << v+1 << " " << u+1 << "\n";
			}
		}
		for(int i = 0;i<n;i++){
			adj[i].clear();
		}
		seen.clear();
	}

	return 0;
}
