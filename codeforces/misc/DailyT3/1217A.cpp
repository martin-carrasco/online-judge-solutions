#include "bits/stdc++.h"

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int s,i, x;
		cin >> s >> i >> x;

		int k = x - abs(s - i);

		if (k < 0)
			k = 0;

		int cases = max(0, s - i);

		cases += ceil(k * 1.0 / 2);
		cout << min(cases, x + 1) << "\n";
	}
	return 0;
}
