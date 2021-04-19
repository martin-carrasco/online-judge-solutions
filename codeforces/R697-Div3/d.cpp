#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 1e5;

int t, n, m, b[MAXN];
ii a[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;
			a[i] = {tmp, i};
		}
		for(int i = 0;i < n;i++) cin >> b[i];
		sort(a, a+n);

	}
	return 0;
}
