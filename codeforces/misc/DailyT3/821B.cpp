#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using ll = long long;

const int MAX_B = 1e5;
//int dp[MAX_B][MAX_B];

ll calc(ll x, ll y){
	ll tot = 0;
	for(ll j = 0;j <= y;j++){
		tot += ((x+1)*(x+(j*2))) / 2;
	}
	return tot;
}

int main(){
	int b, m;
	cin >> m >> b;

	ll current_max = 0;
	ll mx_val = (ll) m * b;
	for(int x = 0;x <= mx_val;x++){
		ll curr = mx_val - x;
		if (curr % (ll)m != 0)
			continue;
		ll y = curr / m;
		ll tot = calc(x, y);
		//cout << "X: " << x << ", Y: " <<  y  <<  endl;
		if (tot > current_max){
			//cout << "Last: " << current_max << ", New: " << tot << endl;
			current_max = tot;
		}
	}
	cout << current_max << endl;
	return 0;
}
