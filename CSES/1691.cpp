#include "bits/stdc++.h"
 
using namespace std;
using vi = vector<int>;
 
const int MAXN = 1e5 + 5;

unordered_map<int, int> g[MAXN];
int deg[MAXN];
stack<int> pC, pC_;

void solve(){
	pC_.push(1);
	while(not pC_.empty()) {
		int v = pC_.top();
		if (g[v].size() == 0){
			pC.push(v);
			pC_.pop();
			continue;
		}
		int u = g[v].begin()->first;
		pC_.push(u);
		g[v].erase(u);
		g[u].erase(v);

	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
	cin >> n >> m;

	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}
 
	for (int i = 1; i <= n; ++i) {
		deg[i] += g[i].size();
		if (deg[i] & 1) {
			cout << "IMPOSSIBLE" << "\n";
			return 0;
		}
	}
 
	int first = 1;
	while (first <= n && !deg[first])
			++first;
	if (first == n+1) {
			cout << "IMPOSSIBLE";
			return 0;
	}
	solve();
	if (pC.size() != m+1){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	while(not pC.empty()){
		cout << pC.top() << " ";
		pC.pop();
	}
	cout << "\n";

	return 0;
}
