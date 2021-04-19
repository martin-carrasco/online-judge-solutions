#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 1e5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a,b,c;
	cin >> a >> b >> c;

	if (c){
		if (a >= b) cout << "Takahashi\n";
		else cout << "Aoki\n";
	} else {
		if (a > b) cout << "Takahashi\n";
		else cout << "Aoki\n";
	}

	return 0;
}
