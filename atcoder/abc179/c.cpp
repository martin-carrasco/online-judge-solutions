#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	ll cnt = 0;
	for(int a = 1;a < n;a++){
		for(int b = 1;b < n;b++){
			ll res = n - a*b;
			if (res > 0)
				cnt++;
			else
				break;
		}
	}
	cout << cnt << "\n";

	return 0;
}
