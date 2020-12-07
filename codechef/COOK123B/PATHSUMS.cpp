#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using viii = vector<tuple<int,int, int>>;


const int MAXN = 200 + 5;
 
vi adj[MAXN];
bool seen[MAXN];
int ans[MAXN];

void bfs(int v){
	queue<pair<int, bool>> q;
	q.push({v, 0});
	ans[v] = 2;
	while(not q.empty()){
		int u = q.front().first;
		bool odd = q.front().second;
		q.pop();

		for(int w : adj[u]){
			if (seen[w]) continue;
			int num_to_add = odd ? 1 : 2;
			ans[w] = num_to_add;
			seen[w] = 1;
			q.push({w, not odd});	
		}
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
		for(int i = 1;i <= n-1;i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bfs(1);

		for(int i = 1;i <= n;i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		for(int i = 1;i <= n;i++){
			ans[i] = 0;
			seen[i] = 0;
			adj[i].clear();
		}

	}
	return 0;
}
