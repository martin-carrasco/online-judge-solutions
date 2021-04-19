#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;

const int MAXN = 200;


long long C(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll l;
	cin >> l;

	cout << C(l-1, 11LL)<< "\n";

	return 0;
}
