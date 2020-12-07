#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e5 + 5;
int n;
vi g[MAXN] ;
bool used[MAXN] ;
vector<ii> roads;
int cnt = 0;

void dfs(int v) {
	used[v] = true ;
	for (size_t i = 0; i < (int) g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	find_comps();

	cout << cnt << "\n";
	return 0;
}
