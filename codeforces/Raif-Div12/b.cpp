#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

const int MAXN = 3000000 + 5;

vi adj[MAXN];
bool seen[MAXN];
int n;

bool dfs(int v, bool dir){
	stack<int> q;
	q.push(v);
	while(not q.empty()){
		int u = q.top();
		q.pop();

		for(auto w : adj[u]){
			if (dir and w == (u+1)%n){
				if (w == 0)
					return true;
				q.push(w);
			} else if (not dir){
				if ((u == 0 and w == n-1) or w == u-1){
					if (w == 0)
						return true;
					q.push(w);
				}
			}
		}
	}
	return false;
}

bool find_cycle() {
	return dfs(0, 0) or dfs(0, 1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int cnt = 0;
		cin >> n;
		for(int i = 0;i < n;i++){
			char c;
			int n_i = (i+1) % n;
			cin >> c;
			if (c == '>'){
				adj[i].push_back(n_i);
			} else if (c == '<'){
				adj[n_i].push_back(i);
			} else {
				adj[i].push_back(n_i);
				adj[n_i].push_back(i);
				if (not seen[i]) {
					cnt++;
					seen[i] = 1;
				}
				if (not seen[n_i]) {
					cnt++;
					seen[n_i] = 1;
				}
			}
		}

		bool cycle = find_cycle();
		cnt = cycle ? n : cnt;

		for(int i = 0;i < n;i++) {
			seen[i] = 0;
			adj[i].clear();
		}
		cout << cnt << "\n";
	}

	return 0;
}
