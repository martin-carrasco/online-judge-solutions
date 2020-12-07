#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 5;
int n,m,k;
int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++){
		int total = 0LL;
		int q;
		for(int j = 0;j < k;j++){
			int tmp;
			cin >> tmp;
			total += tmp;
		}
		cin >> q;
		if (total >= m and q <= 10)
			ans++;
	}
	cout << ans << "\n";
	return 0;


}
