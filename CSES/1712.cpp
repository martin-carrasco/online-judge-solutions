#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const ll m = 1e9 + 7;
long long binpow(long long a, long long b) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		ll a, b, c;
		cin >> a >> b >> c;
		cout << binpow(a, binpow(b, c)) << "\n";
	}

	return 0;
}
