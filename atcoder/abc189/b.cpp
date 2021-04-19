#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN =1e3 + 5;
int n;
ll x, val[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x;

	x*=100;
	ll ans = 0LL;
	for(int i = 1;i <= n;i++){
		ll v,p;
		cin >> v >> p;
		val[i] = (v * p);
	}


	for(int i = 1;i <= n;i++){
		ans += val[i];
		if (ans > x){
			cout << i << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";

	return 0;
}
