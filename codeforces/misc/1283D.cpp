#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using plli = pair<ll, int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	queue<plli> q;
	set<ll> taken;
	
	for(int i = 0;i < n;i++) {
		ll nn;
		cin >> nn;
		taken.insert(nn);
		q.push({nn, 0});
	}

	
	ll sum = 0;
	vector<ll> pos;
	while(not q.empty()){
		pii p = q.front();
		ll v = p.first;
		ll d_v = p.second;
		q.pop();

		for(ll nv : {v-1, v+1}){
			if (taken.count(nv))
				continue;
			taken.insert(nv);
			q.push({nv, d_v + 1});
			pos.push_back(nv);
			sum += d_v + 1 ;
			m--;
			if(not m )
				break;
		}
		if (not m)
			break;
	}

	cout << sum << "\n";
	for(const auto& vert : pos)
		cout << vert << " ";
	cout << "\n";

	return 0;
}
