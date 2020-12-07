#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int MAXN = 1e9 + 5;

ll inv[100];

ll mult(ll a, ll b){
	a = a % MOD;
	b = b % MOD;
	return (a*b) % MOD;
}

ll binpow(ll a, ll b) {
	a %= MOD;
	ll res = 1;
	while (b > 0) {
			if (b & 1)
					res = res * a % MOD;
			a = a * a % MOD;
			b >>= 1;
	}
	return res;
}


ll sum(ll a, ll b){
	if ( a >= MOD)
		a = a % MOD;
	return (a+b) % MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll aa, bb, cc;
	cin >> aa >> bb >> cc;

	inv[1] = 1LL;
	for(int i = 2; i < 3; ++i)
			inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;


	ll ans = 1LL;
	
	ll a_part = mult(inv[2], mult(aa, sum(aa, 1LL)));
	ll b_part = mult(inv[2], mult(bb, sum(bb, 1LL)));
	ll c_part = mult(inv[2], mult(cc, sum(cc, 1LL)));

	ans = mult(ans, a_part);
	ans = mult(ans, b_part);
	ans = mult(ans, c_part);

	/*
	ans = mult(mod_inv_2, mult(cc, cc+1));
	ans = mult(ans, mult(mod_inv_2, mult(bb, bb+1)));
	ans = mult(ans, mult(mod_inv_2, mult(aa, aa+1)));
	*/

	cout << ans << "\n";

	return 0;
}
