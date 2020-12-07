#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pair<int ,int>>;
using ll = long long;

const int MAX_N = 1e5 + 5;

bool v[MAX_N];

void bfs(int nd){

}

int main() {
	int n, m;
	cin >> n >> m;
	vpi c;
	vii g (n, vi());
	
	for(int i = 0;i < n;i++) {
		int cost;
		cin >> cost;
		c.push_back({i, cost});
	}

	sort(c.begin(), c.end(), 
			[](auto& p1, auto& p2){
				return p1.second < p2.second;
			}
	);

	for(int i = 0;i < m;i++){
		int x, y;
		cin >> x >> y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}

	ll cost = 0;
	for(int i = 0;i < n;i++){
		if (v[c[i].first])
			continue;
		cost += c[i].second;
		queue<int> q;
		q.push(c[i].first);
		while(not q.empty()){
			int curr = q.front();
			q.pop();
			
			for(auto& nn : g[curr]){
				if(not v[nn]){
					q.push(nn);
					v[nn] = 1;
				}
			}
		}
	}
	cout << cost << endl;
	return 0;
}
