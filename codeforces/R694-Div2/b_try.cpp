#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e5 + 5;
ll a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		queue<pair<ll, int>> st;
		ll n, x;
		cin >> n >> x;
		ll sum = 0L;

		for(ll i = 0;i < n;i++){
			cin >> a[i];
			st.push({a[i], 0});
		}

		while(not st.empty()){
			auto curr = st.front();
			st.pop();

			ll val = curr.first * pow(x, curr.second);
			//cout << "curr: " << curr.first << ", dep: " << curr.second << ", val: " << val << "\n";
			sum += val;
			if (curr.first % x != 0) break; 
			st.push({curr.first / x, curr.second+1});
		}

		while(not st.empty()){
			auto curr = st.front();
			sum += curr.first * pow(x, curr.second);
			st.pop();
		}

		cout << sum << "\n";
	}


	return 0;
}
