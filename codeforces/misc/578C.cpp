#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 1e6;
int n;
int a[MAXN];

ld weakness(ld x){
	ld sum = 0;
	ld poorness_max = 0;
	ld poorness_min = 0;

	for(int i = 0;i < n;i++) {	
		sum += a[i] - x;
		poorness_max = max(poorness_max, sum);
		sum = max(sum, 0.0L);
	}

	sum = 0;
	for(int i = 0;i < n;i++){
		sum += a[i] - x;
		poorness_min = min(poorness_min, sum);
		sum = min(sum,0.0L);
	}

	return max(poorness_max, abs(poorness_min));
}

int main(){
	cin >> n;

	int max_el = 0;
	for(int i = 0;i < n;i++){
		int t;
		cin >> t;
		a[i] = t;
		max_el = max(max_el, abs(t));
	}
	
	ld l = -max_el;
	ld r = max_el;

	ld epsilon = 1e-18;
	int its = 200;
	while(its--){
		ld m1 = (l *2 + r) / 3;
		ld m2 = (l + 2*r) / 3;

		ld f1 = weakness(m1);
		ld f2 = weakness(m2);
		/*cout << l << "\n";
		cout << r << "\n";
		cout << m1 << "\n";
		cout << m2 << "\n";
		cout << f1 << "\n";
		cout << f2 << "\n" << "\n";*/

		if (f1 < f2)
			r = m2;
		else
			l = m1;
	}

	cout << fixed << setprecision(15) << weakness(l) << "\n";
	return 0;
}
