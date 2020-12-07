#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using lli = pair<long long, int>;


const int MC = 1000000;

int main() {
	int n, s;
	cin >> n >> s;
	vector<lli> c_p;
	s = MC - s;

	for(int i = 0;i < n;i++){
		ll x, y;
		int k;
		cin >> x >> y >> k;
		lli p = {(pow(x, 2) + pow(y, 2)), k };
		c_p.push_back(p);
	}

	sort(c_p.begin(), c_p.end());

	long double radius =  -1;
	for(int i = 0;i < c_p.size();i++){
		lli pr = c_p[i];
		s -= pr.second;	
		if ( s <= 0) {
			radius = sqrt(pr.first);
			cout.precision(7);
			cout << fixed <<  radius << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
	return 0;
}
