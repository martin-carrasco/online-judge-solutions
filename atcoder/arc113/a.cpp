#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2e5 + 5;
int k;
int n;
vector<long long> primes;
map<int, int> mp;

void trial_division4(long long n) {
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            mp[d]++;
            n /= d;
        }
    }
    if (n > 1)
        mp[n]++;
}

int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	int ans = 1;
	vector<char> is_prime(MAXN+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= MAXN; i++) {
			if (is_prime[i]) {
					for (int j = i * i; j <= MAXN; j += i)
							is_prime[j] = false;
					if (is_prime[i]) primes.push_back(i);
			}
	}
	for(int i = 2; i <= k;i++){
		trial_division4(i);

		int times_actual = 1;
		for(auto [k, v] : mp){
			//cout << "k: " << k <<  ", v: " << v <<  "\n";
			times_actual *= C(v+2, 2);
		}
		//cout << "i: " << i << ", times: " << times_actual << "\n";
		ans += times_actual;
		mp.clear();
	}
	cout << ans << "\n";

	return 0;
}
