#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100 + 5;
vector<int> adj[MAXN];	
vector<bool> vis;
vector<int> ans;

void dfs(int v){
	vis[v] = 1;
	for(int u : adj[v]){
		if(not vis[u])
			dfs(u);
	}
	ans.push_back(v);
}

int main(){
	int n, m;
	n = m = 1;
	while(n or m){
		cin >> n >> m;
		for(int i = 1;i <= m;i++){
			int s, d;
			cin >> s >> d;
			adj[s].push_back(d);
		}
		vis.assign(n, false);
		ans.clear();
		for(int i = 1;i <= n;i++){
			if(not vis[i]){
				dfs(i);
			}
		}
		reverse(ans.begin(), ans.end());
		for(const auto& val : ans)
			cout << val << " ";
		cout << "\n";
	}

	return 0;
}
