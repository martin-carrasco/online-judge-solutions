#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 2e5 + 5;
vi adj[MAXN];
int c[MAXN];
set<int> seen;

bool dfs(int u, int par = -1){
	for(auto v : adj[u]){
		if (v == par) continue;
		if(seen.count(c[v]))
			return false;
		seen.insert(c[v]);				
		bool f = dfs(v, u);
		seen.erase(c[v]);
		if (not f)
			return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for(int i = 1;i <= n;i++) cin >> c[i];

	for(int i = 1;i <= n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cnt = 0;
	for(int i = 1; i <= n;i++){
		seen.insert(c[i]);
		cnt += dfs(i);
		seen.erase(c[i]);
	}


	cout << cnt << "\n";
	return 0;
}
