#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int  t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if (n == 1) {
			cout << 0 << "\n";
			continue;
		}

		int i = 1;
		int moves = 1e9 + 5;
		for(;i <= 63244;i++){
			int max_num = ceil((n*1.0) / i) + i - 1;
			if (max_num <= moves) {
				moves = max_num;
				continue;
			}
			break;
		}
		cout << moves-1 << "\n";
	}
	return 0;
}
