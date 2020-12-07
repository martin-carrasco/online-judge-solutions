#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using ll = long long;
using llll = pair<ll, ll>;

const int MAXN = 1e5 + 100;

ll a[MAXN], b[MAXN];

int main(){
	int n, k;
	cin >> n >> k;

	vector<llll> cs;

	for(int i = 0;i < n;i++)
		cin >> a[i];

	for(int i = 0;i < n;i++){
		cin >> b[i];
		cs.push_back({a[i], b[i]});
	}

	sort(cs.begin(), cs.end(), [](const llll& p1, const llll& p2){
				return  1.0*p2.first / p2.second < 1.0 * p1.first / p1.second;

			});


	ll lhs = 0;
	ll rhs = floor((cs[n-1].second + k + 1) / cs[n-1].first);
	int cnt = 0;
	ll ans = 0;
	while(1){
		int m = floor((rhs + lhs) / 2);
		//cout << "lhs: " << lhs << ", rhs: " << rhs << ", m: " << m << endl;
		for(int i = 0;i < n;i++){
			ii p = cs[i];	
			//cout << "a[i]: " << p.first << ", b[i]: "  << p.second << endl;
			if (a[i] * m > b[i]){
				cnt += m * a[i] - b[i];
				if (cnt > k){
					break;
				}
			}
		}
		//cout << "Count: " << cnt << endl << endl;
		if (cnt > k){
			if (rhs == m){
				int count = 0;
				for(int i = 0;i < n;i++){
					ii p = cs[i];	
					if (a[i] * lhs > b[i]){
						cnt += lhs * a[i] - b[i];
						if (cnt > k){
							break;
						}
					}
				}
				if (cnt <= k)
					ans = lhs;
				else
					ans = rhs;
				break;
			}
			cnt = 0;
			rhs = m;
		}
		else if(cnt <= k) {
			if (lhs == m){
				cnt = 0;
				for(int i = 0;i < n;i++){
					ii p = cs[i];	
					if (a[i] * rhs > b[i]){
						cnt += rhs * a[i] - b[i];
						if (cnt > k){
							break;
						}
					}
				}
				if (cnt <= k)
					ans = rhs;
				else
					ans = lhs;
				break;
			}
			cnt = 0;
			lhs = m;
		}
	}

	cout <<  ans << "\n";
	return 0;
}
