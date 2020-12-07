#include "bits/stdc++.h"


using namespace std;

const int MAXN = (1 << 15) + 5;
unordered_map<int, bool> g[MAXN];
int deg[MAXN], n, m, l;
stack<int> pC, pC_;
unordered_map<bitset<15>, int> node_idx;

void solve(){
	pC_.push(0);
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

	}
 
	if (not pC.empty()) {
		for(int i = l-2; i >= 0;i--)
			cout << ((pC.top() >> i) & 1);
		pC.pop();
	}

	while(not pC.empty()){
		int ele = pC.top();
		cout << (ele & 1);
		pC.pop();
	}
	cout << "\n";
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l;

	n = (1 << (l-1))-1;
	
	for (int i = 0;i <= n;i++){
		int t1, t2;
		t1 = t2 = i;
		t1 = (t1 << 1) | 1;
		t1 &= ~(1 << (l+1));

		t2 = (t2 << 1);
		t2 &= ~(1 << (l+1));

		//cout << "t1: " << bitset<16>(t1) << ", t2: " << bitset<16>(t2) << "\n";
		g[i][t1] = 1;
		g[i][t2] = 0;
	}
	solve();

	return 0;
}
