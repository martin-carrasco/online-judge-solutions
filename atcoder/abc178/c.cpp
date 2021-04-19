#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
				}
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
	ll n;
	cin >> n;


	ll pow_t = n - 2;
	ll ans = binpow(10, n);
	ll ans_not = binpow(8, n);
	ll ans_nott = binpow(9, n);
	ans = (ans - 2 * ans_nott) % MOD;


	cout << ans << "\n";
}
