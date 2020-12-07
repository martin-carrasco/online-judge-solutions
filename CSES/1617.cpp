#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int m = 1e9 + 7;

ll binpow(ll a, ll b) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
	ll n;
	cin >> n;

	cout << binpow(2, n) << "\n";
}
