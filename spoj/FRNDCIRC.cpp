#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e5 + 5;

int parent[MAXN];
int sz[MAXN];


void make_set(int v){
	parent[v] = v;
	sz[v] = 1;
}

int find_set(int v){
	if(parent[v] == v) return v;
	return find_set(parent[v]);
}

void union_set(int v, int u){
	v = find_set(v);
	u = find_set(u);
	if (u != v){
		if (sz[u] < sz[v])
			swap(u, v);
		parent[v] = u;
		sz[u] += sz[v];
	}
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int cnt = 0;
		map<string, int> mp;

		for(int i = 0;i < n;i++) {
			string first, second;
			cin >> first >> second;

			int u, v;

			if (not mp.count(first)) {
				mp[first] = cnt++; 
				make_set(mp[first]);
			}
			if (not mp.count(second)) {
				mp[second] = cnt++;
				make_set(mp[second]);
			}

			u = mp[first];
			v = mp[second];

			union_set(u, v);	

			int root = find_set(u);
			cout << sz[root] << "\n";
		}
		for(int i = 0;i <= cnt;i++){
			parent[i] = 0;
			sz[i] = 0;
		}
	}

	return 0;
}
