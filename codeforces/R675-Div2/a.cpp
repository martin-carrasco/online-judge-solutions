#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll sides[3];
		for(int i = 0;i < 3;i++)
			cin >> sides[i];
		sort(sides, sides+3);

		ll  other = sides[1] - sides[0];

		ll d = ceil(sqrt( 1.0*(sides[2]*sides[2] + other*other)));
		cout << d << "\n";
	}

	return 0;
}
