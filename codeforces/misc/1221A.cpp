#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 100;

int a[MAXN];

int main(){
	int q;
	cin >> q;
	vi powers;

	for(int i = 0;i <= 10;i++){
		powers.push_back((1 << i));	
	}

	while(q--){
		int n;
		cin >> n;
		map<int, int> mp;

		for(int i = 0;i < n;i++){
			int t;
			cin >> t;
			
			if (t > 2048)
				continue;
			if (not mp.count(t) > 0)
				mp[t] = 1;
			else
				mp[t]++;
		}


		for(int pow_2 : powers){
			int grp = mp.count(pow_2) ? floor(mp[pow_2] / 2) : 0;
			int n_pow = (pow_2 << 1);
			mp[n_pow] += grp;
		}

		if (mp[2048] > 0) {
			cout << "YES" << "\n";
		}
		else
			cout << "NO" << "\n";
	}

	return 0;
}
