#include "bits/stdc++.h"

using namespace std;

vector < vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;
int n,m;

void dfs1 (int v) {
	used[v] = true;
	for (size_t i= 0; i < g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i = 0; i < gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

int main(){ 
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> n >> m;
		if (n == 0 and m == 0)
			break;

		order.clear();
		g.assign(n, vector<int>());
		gr.assign(n,  vector<int>());

		for (int i = 0;i < m;i++) {
			int src, dst, t;
			cin >> src >> dst >> t;
			g[src-1].push_back(dst-1);
			gr[dst-1].push_back(src-1);
			if (t == 2)  {
				g[dst-1].push_back(src-1);
				gr[src-1].push_back(dst-1);
			}
		}

		used.assign (n, false);
		for (int i= 0; i < n; ++i)
			if (!used[i])
				dfs1 (i);

		int scc = 0; 
		used.assign (n, false);
		for (int i=0; i < n; ++i) {
			int v = order[n-i-1];
			if (!used[v]) {
				dfs2 (v);
				if (component.size() > 0){
					scc++;
				}
				component.clear();
			}
		}
		cout << (scc == 1) << "\n";
	}
	return 0;
}
