#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		string ans = "";
		for(int i = 9; i > 0;i--){
			if (x >= i){
				x-=i;
				ans.insert(0, 1, (char)(i + '0'));
			}
			if (x == 0)
				break;
		}
		if (x == 0)
			cout << ans << "\n";
		else
			cout << -1 << "\n";
	}

	return 0;
}
