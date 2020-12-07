#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using ll = long long;

const int MAX_N = 1e5;

vector<pair<int, ll>> adj[MAX_N];

int main(){
	int n, m, t, k, p;
	unordered_set<int> ps;
	cin >> n >> m >> t >> k >> p;


	for(int i = 0;i < p;i++){
		int tmp;
		cin >> tmp;
		ps.insert(tmp);
	}


	for(int i = 0;i < m;i++){
		int s, dest, w;
		cin >> s >> dest >> w;
		adj[s].push_back({dest, w * 60});

	}

	vector<ll> d(n+1, numeric_limits<ll>::max());
	d[1] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	q.push({0, 1});
	while(not q.empty()){
		int v = q.top().second;
		ll d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for(auto edge : adj[v]){
			int to = edge.first;
			ll len = edge.second;
			if (ps.count(to))
				len += k; 
			if ( d[v] + len < d[to]){
				d[to] = d[v] + len;
				q.push({d[to], to});
			}
		}
	}

	if ( d[n] != numeric_limits<ll>::max() and d[n] <= (1LL * t * 60))
		cout << d[n] << endl;
	else 
		cout << -1 << endl;
	return 0;
}
