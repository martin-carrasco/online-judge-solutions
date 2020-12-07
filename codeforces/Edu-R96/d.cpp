#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int MAXN = 2e5;


ll solve(string s){
	if (s.size() == 1)
		return 1;
	for(int i = 0;i < s.size();i++){

	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n;
		cin >> s;

		ll ans = solve(s);
		cout << ans << "\n";
	}
	return 0;
}
