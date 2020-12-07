#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

const int MAXN =  5000 + 5;
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

		sort(a, a+n);

		if (a[0].first	== a[n-1].first) {
			cout << "NO" << "\n";
			continue;
		}
		
		cout << "YES" << "\n";
		int root = 0;
		int last_leaf = -1;
		int i = n-1;
		for(;i >= 0;i--){
			if (a[i].first == a[root].first)
				break;
			cout << a[root].second+1 << " " << a[i].second+1 << "\n";
			last_leaf = i;
		}
		for(;i > 0;i--){
			cout << a[last_leaf].second + 1 <<  " " << a[i].second + 1 << "\n";	
		}
	}

	return 0;
}

