#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;

const int MAXN = 1e5 + 5;

int t, n;
ll A, B, a[MAXN], b[MAXN];
pair<ll, ll> c[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
		cin >> A >> B >> n;	
		for(int i = 0;i < n;i++) cin >> a[i];
		for(int i = 0;i < n;i++) {
			cin >> b[i];
			c[i] = {a[i], b[i]};
		}

		sort(c, c+n);

		bool win = true;
		for(int i = 0;i < n;i++){
			ll combat_need = ceil(c[i].second*1.0 / A);
			ll health_need = combat_need * c[i].first;	

			if (i < n-1) {
				B -= health_need;
				if (B <= 0){
					win = false;
					break;
				}
			} else {
				ll kill_hit = ceil(B*1.0 / c[i].first); 	
				if (combat_need > kill_hit)
					win = false;
				else win = true;
			}
		}
		if(win) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
