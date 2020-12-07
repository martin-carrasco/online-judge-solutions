#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e6;
int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, int> last_pos;
		map<int, int> max_dist;

		for(int i = 0;i < n;i++) cin >> a[i];
		for(int i = 0;i < n;i++){
			if (not last_pos.count(a[i])) {
				last_pos[a[i]] = i;
				max_dist[a[i]] = max(i+1, n - i);
			} else {
				max_dist[a[i]] = max(n-i, i - last_pos[a[i]]);
				last_pos[a[i]] = i;
			}
		}

		for(int i = 1; i <= n;i++){
			bool occur = false;
			for(auto [k, p] : max_dist){
				if (p <= i) {
					cout << k << " ";
					occur = true;
					break;
				}
			}
			if (not occur)
				cout << -1 << " ";
		}
		cout << "\n";
	}

	return 0;
}
