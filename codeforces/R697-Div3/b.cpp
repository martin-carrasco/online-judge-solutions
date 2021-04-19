#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 1e6 + 5;

int t, n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> t;
	while(t--){
		cin >> n;
		while(n % 2020 != 0 and n % 2021 != 0 and n > 2021)
			n -= 2021;
		if (n % 2020 == 0 or n % 2021 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
