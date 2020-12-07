#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;

const int MAXN = 1e5 + 5;

vi adj[MAXN];
bool v[MAXN];
ll cnt_f = 0;
ll cnt_t = 0;
int cnt_alone = 0;


void dfs(int vt){
	queue<pair<int, bool>> q;
	q.push({vt, false});
	v[vt] = 1;
	cnt_f++;

	while(not q.empty()){
		pair<int, bool> p = q.front();
		int node = p.first;
		bool color = p.second;
		q.pop();

		for(auto nn : adj[node]){
			if(v[nn]){ continue;}
			if (color)	
				cnt_f++;
			else
				cnt_t++;
			q.push({nn, not color});
			v[nn] = 1;
		}
	}
}

int main(){
	int n;
	cin >> n;
	
	for(int i = 0;i < n-1;i++){
		int s, d;
		cin >> s >> d;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}
	
	dfs(1);

	ll current = (ll)n-1;
	ll ans = cnt_t * cnt_f - current;
	cout << ans << "\n";
	return 0;
}
