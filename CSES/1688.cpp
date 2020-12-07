#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
const int MAXN = 2e5;


vi adj[MAXN];

int n, l, q;
int timer;
vi tin, tout;
vector<vi> up;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	for(int i = 0;i < n-1;i++){
		int v;
		cin >> v;
		adj[i+1].push_back(v-1);
		adj[v-1].push_back(i+1);
	}
	preprocess(0);
	
	for(int i = 0;i < q;i++){
		int u, v;
		cin >> u >> v;
		int res = lca(u-1, v-1);	
		cout << res+1 << "\n";
	}

	return 0;
}
