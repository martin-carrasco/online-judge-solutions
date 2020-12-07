#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1e5 + 5;
int n,m;

int labels[MAXN];
int sz = 1;
vi g[MAXN], gr[MAXN], order, component;
vector<bool> used;

void FOUND_COMPONENT(){
	for(auto val : component){
		labels[val] = sz;
	}
	++sz;
}
void dfs1 (int v) {
		used[v] = true;
		for (size_t i=0; i<g[v].size(); ++i)
				if (!used[ g[v][i] ])
						dfs1 (g[v][i]);
		order.push_back (v);
}

void dfs2 (int v) {
		used[v] = true;
		component.push_back (v);
		for (size_t i=0; i<gr[v].size(); ++i)
				if (!used[ gr[v][i] ])
						dfs2 (gr[v][i]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
		gr[v].push_back(u);
	}

	used.assign (n, false);
	for (int i=0; i<n; ++i)
			if (!used[i])
					dfs1 (i);

	used.assign (n, false);
	for (int i=0; i<n; ++i) {
			int v = order[n-1-i];
			if (!used[v]) {
					dfs2 (v);
					FOUND_COMPONENT();
					component.clear();
			}
	}

	cout << sz-1 << "\n";
	for(int i = 0;i < n;i++)
		cout << labels[i] << " ";
	cout << "\n";

	return 0;
}
