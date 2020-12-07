#include "bits/stdc++.h"

using namespace std;
int a, b, c, d, e, f;

int main() {
	cin >> a >> b >> c >> d >> e >> f;
	int cost;
	if (e < f)
		cost = min({b, c, d}) * f + min({d -min({b, c, d}), a}) * e;
	else
		cost = min({a, d}) * e + min({d -min({a,d}), b, c}) * f;
	cout << cost << endl;
	return 0;
}

