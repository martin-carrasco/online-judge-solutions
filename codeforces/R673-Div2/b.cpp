#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;
ll a[MAXN];
ll b[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		ll k;
		cin >> n >> k;
		multiset<ll> black;
		multiset<ll> white;

		for(int i = 0;i < n;i++){
			cin >> a[i];
			b[i] = a[i];
		}

		sort(a, a+n, greater<ll>());

		/*for(int i = 0;i < n;i++){
			if(a[i] > k / 2) {
				black.insert(a[i]);
				continue;
			}
			auto it_low_l = black.lower_bound(k - a[i]); 	
			auto it_high_l = black.upper_bound(k - a[i]);

			if (*it_low_l + a[i] > k) {
				black.insert(a[i]);
			}
			else if(*it_low_l + a[i] == k){
					int cnt = distance(white.lower_bound(k - a[i]), white.upper_bound(k - a[i]));
					int blck_cnt = distance(it_low_l, it_high_l);
					if (cnt <= blck_cnt)
						white.insert(a[i]);
					else
						black.insert(a[i]);
			} else {
				black.insert(a[i]);
			}
		}

		for(int i = 0;i < n;i++){
			if (black.count(b[i])){
				black.erase(black.find(b[i]));
				cout << 1;
			}
			else if (white.count(b[i])) {
				white.erase(white.find(b[i]));
				cout << 0;
			}
			cout << " ";
		}
		cout << "\n";*/
		bool half = true;
		for(int i = 0;i < n;i++){
			if (b[i] > floor(k*1.0 / 2))
				cout << 1;
			else if (b[i] == ceil(k*1.0/2)){
				if (half)
					cout << 1;
				else
					cout << 0;
				half = !half;
			}
			else
				cout << 0;
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
