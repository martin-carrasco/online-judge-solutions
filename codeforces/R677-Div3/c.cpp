#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

const int MAXN = 3e5 + 5;

ii a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;
			a[i] = {tmp, i};
		}

		int ans = -2;
		int ans_idx = -2;
		for(int i = 0;i < n;i++){
			if (i - 1 >= 0 and a[i-1].first < a[i].first){
				if (a[i].first > ans) {
					ans = a[i].first;
					ans_idx = i;
				}
			}
			if (i+1 < n and a[i+1].first < a[i].first){
				if (a[i].first > ans) {
					ans = a[i].first;
					ans_idx = i;
				}

			}
		}
		
		cout << ans_idx + 1 << "\n";
	}

	return 0;
}

