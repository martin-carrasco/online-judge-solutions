#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2e5 + 10;

vi adj[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin  >> t;
	while(t--){
		ll n;
		cin >> n;

		for(int i = 0;i < (int)n;i++){
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ll ans = n*(n-1);
		ans -= (n-1-2);
		cout << ans << "\n";
	}
	return 0;
}
