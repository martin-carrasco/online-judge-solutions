#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 2e5 + 5;
int s[MAXN];
vector<char> is_prime(MAXN, true);


void sieve() {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAXN; i++) {
			if (is_prime[i] && (long long)i * i <= MAXN) {
					for (int j = i * i; j <= MAXN; j += i)
							is_prime[j] = false;
			}
	}

}

void factors(int n){
	int curr = s[n];
	int cnt = 1;
	while(n > 1){
			n /= s[n];
			if (curr == s[n]) {
					cnt++;
					continue;
			}
			// FOUND FACTOR AND POWER
			curr = s[n];
			cnt = 1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	//factors(n);
	int t;
	cin >> t;
	while(t--){
		int d;
		cin >> d;
		ll facts[4] = {1, 1, 1, 1};
		int cnt = 1;
		for(ll i = 2LL;i <= MAXN;i++){
			if (not is_prime[i] or i - facts[cnt-1] < d) continue;
			//cout << i << " ";
			facts[cnt++] = (ll) i;
			if (cnt == 3){
				facts[cnt] = facts[1]*facts[2];
				break;
			}
		}
		cout << facts[3] << "\n";
	}

	return 0;
}
