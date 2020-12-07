#include "bits/stdc++.h"
 
using namespace std;
using ll = long long;
using ii = pair<ll, int>;
const int MAXN = 1000 + 5;
const int MAXN2 = 1000*1000 + 5;
 
ll a[MAXN];
vector<pair<ll, pair<ll, ll>>> b;
bool valid(int i, int j){
	bool f = b[i].second.first != b[j].second.first and b[i].second.first != b[j].second.second;
	bool s = b[i].second.second != b[j].second.first and b[i].second.second != b[j].second.second;

	return s and f;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll x;
	cin >> n >> x;
	
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}

	if (n < 4) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			b.push_back({a[i]+a[j], {i, j}});
		}
	}

	sort(b.begin(), b.end());

	int i = 0;
	int j = b.size() - 1;
	while(i != j){
		ll sum = b[i].first + b[j].first;	
		if (sum == x and valid(i, j)) {
			ll ans[4];
			ans[0] = b[i].second.first;
			ans[1] = b[i].second.second;
			ans[2] = b[j].second.first;
			ans[3] = b[j].second.second;
			sort(ans, ans+4);
			for(int i = 0;i < 4;i++){
				cout << ans[i]+1 << " ";
			}
			cout << "\n";
			return 0;
		}
		if (sum < x)
			i++;
		else 
			j--;
	}
	cout << "IMPOSSIBLE" << "\n";
	return 0;
}
