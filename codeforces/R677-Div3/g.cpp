#include "bits/stdc++.h" 
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using ll = long long;
const int MAXN = 1000 + 5;
const int INF = 1e9;

int n, m, k, d[MAXN][MAXN], p[MAXN];
bool u[MAXN];

vii adj[MAXN];

void dijkstra(int s) {
	fill(p, p+n+1, -1);
	fill(u, u+n+1, false);
	fill(d[s], d[s] +n+1, INF);
	d[s][s] = 0;
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	while (!q.empty()) {
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != d[s][v])
			continue;

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[s][v] + len < d[s][to]) {
					d[s][to] = d[s][v] + len;
					p[to] = v;
					q.push({d[s][to], to});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >>n >> m >> k;

	vii edges;
	vii routes;

	for(int i = 1; i <= m;i++){
		int uu, v, w;
		cin >> uu >> v >> w;
		adj[uu].emplace_back(v, w);
		adj[v].emplace_back(uu, w);
		edges.emplace_back(uu, v);
	}

	for(int i = 1;i <= k;i++){
		int a,b;
		cin >> a >> b;
		routes.emplace_back(a, b);
	}


	for(int i = 1;i <= n;i++){
		dijkstra(i);
	}

	int ans = 1e9;
	for(auto edge : edges){
		int e_u = edge.first;
		int e_v = edge.second;

		int cost = 0;
		for(auto route : routes){
			int shortcut = min(d[route.first][e_u] + d[e_v][route.second], d[route.first][e_v] + d[e_u][route.second]);
			int curr_cost = min(shortcut, d[route.first][route.second]);
			cost += curr_cost;
		}
		ans = min(cost, ans);
	}

	cout << ans << "\n";

	return 0;
}

