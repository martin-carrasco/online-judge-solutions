#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const ll MAXN = 1e10 + 10;
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
	int t;
	cin  >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> factors = trial_division1(n);	
		if (factors.size() == 1){
			cout << 1 << "\n" << factors[0] << "\n";
			continue;
		}
		sort(factors.begin(), factors.end());
		while(factors.size() > 1){
			if (factors[factors.size() - 2] == 2 and factors[factors.size() - 1] % factors[factors.size()-2] == 0)
				break;
			ll last_num = factors.back();
			factors.pop_back();
			last_num *= factors.back();
			factors.pop_back();
			factors.push_back(last_num);
		}
		cout << factors.size() << "\n";
		for(auto fact : factors){
			cout << fact << " ";
		}
		cout << "\n";
	}
	return 0;
}
