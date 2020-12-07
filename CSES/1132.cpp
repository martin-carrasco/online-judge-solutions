#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1e6;
vi adj[MAXN];
int dist1[MAXN], dist2[MAXN], dist3[MAXN], sgte[MAXN];


void dfs1(int v, int p){
	//dist1[v] = 0;
	//dist3[v] = 0;
	for(auto u : adj[v]){
		if (u == p) continue;
		dfs1(u, v);
		if (dist1[u] + 1 > dist1[v]){
			dist3[v] = dist1[v];
			dist1[v] = dist1[u] + 1;
			sgte[v] = u;
		}
		else 
			dist3[v] = max(dist3[v],dist1[u] + 1);;
	}
}

void dfs2(int v, int p){
	for(auto u : adj[v]){
		if (u == p) continue;
		if (u == sgte[v])
			dist2[u] = 1 + max(dist2[v], dist3[v]);
		else
			dist2[u] = 1 + max(dist2[v], dist1[v]);
		dfs2(u, v);
	}
}

int main(){
	int n;
	cin >> n;

	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs1(1, -1);
	dfs2(1, -1);

	for(int i = 1;i <= n;i++){
		cout << dist1[i] << " " <<   dist3[i] <<  " " << dist2[i] << "\n";	
	}
	cout << "\n";
	return 0;
}
