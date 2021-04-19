#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 100 + 5;
int n, t, h[MAXN];

set<int> pos;	

int solve(int k){
	int last_pos = -1;
	while(not pos.empty() and k){
		auto it = pos.begin();
		int idx = *it;
		h[idx]++;
		k--;
		pos.erase(it);
		last_pos = idx;
		if (h[idx] < h[idx+1]) pos.insert(idx);
		if (idx >= 2 and h[idx-1] < h[idx]) pos.insert(idx-1);
	}
	return k > 0 ? -1 : last_pos;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		int k;
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			cin >> h[i];
			if (i >= 2 and h[i] > h[i-1]) pos.insert(i-1);
		}
		cout << solve(k) << "\n";
		pos.clear();
	}
	return 0;
}
