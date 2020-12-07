#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;
using ii = pair<int, int>;

const int MAXN = 50 + 5;

vi adj[MAXN];
bool v[MAXN];
ll ans = 1;

void dfs(int vt){
	queue<pair<int, int>> q;
	q.push({vt, 0});
	v[vt] = 1;

	while(not q.empty()){
		pair<int, int> p = q.front();
		int node = p.first;
		int l = p.second;
		q.pop();

		for(auto nn : adj[node]){
			if(v[nn]){ continue;}
			ans *= 2;
			q.push({nn, l+1});
			v[nn] = 1;
		}
	}
}
int main(){
	int n, m;
	cin >> n >> m;

	for(int i = 0;i < m;i++){
		int s, d;
		cin >> s >> d;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}

	for(int i = 1;i <= n;i++) {
		if (v[i]) continue;
		dfs(i);
	}


	cout << ans << "\n";
	return 0;
}
