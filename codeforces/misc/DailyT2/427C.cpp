#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ii = pair<int,int>;
using ll = long long;

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

vi g[MAXN], gr[MAXN];
vector<bool> used;
int cost[MAXN], n, m;
ii ans[MAXN];
int cnt = 0;
vi order, component;

void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}

void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

void process_ccs(){
	if (component.size() == 0)
		return;

	int num_min = 0;
	int min_node = 0;
	int min_val = 1e9;
	for(auto node : component){
		if (cost[node] < min_val){
			num_min = 1;
			min_node = node;
			min_val = cost[node];
		} else if (cost[node] == min_val){
			num_min++;
		}
	}
	ans[cnt++] = {min_val, num_min};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	

	for(int i = 0;i < n; i++) cin >> cost[i];

	cin >> m;

	for (int i = 0;i < m;i++) {
			int a, b;
			cin >> a >> b;
			--a;
			--b;
			g[a].push_back(b);
			gr[b].push_back(a);
	}

	used.assign (n, false);
	for (int i=0; i<n; ++i)
			if (!used[i])
					dfs1 (i);
	used.assign (n, false);
	for (int i=0; i<n; ++i) {
			int v = order[n-1-i];
			if (!used[v]) {
					dfs2 (v);
					process_ccs();
					component.clear();
			}
	}
	ll ans_times = 1LL;	
	ll ans_val = 0LL;
	for(int i = 0;i < cnt;i++){
		auto curr = ans[i];
		ans_times = ((ans_times % MOD) * (((ll) curr.second)) % MOD) % MOD ;
		ans_val += curr.first;
	}
	cout << ans_val << " " << ans_times << "\n";
}
