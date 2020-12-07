#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		unsigned int a, b, c;
		cin >> a >> b;	
		c = 0;

		for(int i = 0;i <= 31;i++){
			bool a_state = (a & (1 << (i - 1)));
			bool b_state = (b & (1 << (i - 1)));

			if (a_state and b_state)
				c |= (1 << (i-1));
		}
		int res = (a^c) + (b^c);
		cout << res << "\n";

	}

	return 0;
}
