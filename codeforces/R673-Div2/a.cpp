#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1000 + 5;
int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		set<int> orders;

		for(int i = 0;i < n;i++) cin >> a[i];

		sort(a, a+n);

		int min_val = a[0];

		int cnt = 0;
		for(int i = 1;i < n;i++){
			int x = k - a[i];	
			cnt += x / min_val;
		}

		cout << cnt << "\n";
	}

	return 0;
}
