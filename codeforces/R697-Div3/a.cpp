#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 1e5;

ll n;
int t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> t;
	while(t--){
		cin >> n;
		if (n % 2 == 1){
			cout << "YES\n";
			continue;
		}

		while(n % 2 == 0 and n > 1){
			n /= 2;
		}
		if (n == 1LL) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}
