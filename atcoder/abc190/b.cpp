#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 1e5;

int n,s,d;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool dmg = false;
	cin >> n >> s >> d;
	for(int i = 0;i < n;i++){
		int x_i, y_i;
		cin >> x_i >> y_i;
		if (x_i >= s or y_i <= d) continue;
		dmg = true;
	}
	if (dmg) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
