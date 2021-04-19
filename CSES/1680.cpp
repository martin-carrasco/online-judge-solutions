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
int paths[MAXN], p[MAXN];

void dfs(int v) {
    visited[v] = true;
    for (int u : adj_back[v]) {
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
	for (int i = 1;i <= n;i++){
		paths[i] = numeric_limits<int>::max();
	}
	paths[b] = 0;	
	for (int i = 1;i <= n;i++){
		int x = ans[i-1];
		for (auto in_vert : adj[x]){
			if (paths[in_vert] == numeric_limits<int>::max()) continue;
			if (paths[in_vert] + 1 > paths[x] or paths[x] == numeric_limits<int>::max())  {
				paths[x] = paths[in_vert] + 1;
				p[x] = in_vert;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_back[v].push_back(u);
	}

	topological_sort();
	cnt_ways(1, n);

	if(paths[1] == numeric_limits<int>::max())
		cout << "IMPOSSIBLE\n";
	else {
		int w = 1;
		cout << paths[1] + 1 << "\n";
		while(1){
			cout << w << " ";
			if (w == n)
				break;
			w = p[w];
		}
		cout << "\n";
	}

	return 0;
}
