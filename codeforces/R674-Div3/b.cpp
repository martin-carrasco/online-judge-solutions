#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 2 * 100 +5;
ii a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int  t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;

		int count_symmetric = 0;
		for(int i = 0;i < n;i++)		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (y1 == x2)
				count_symmetric++;
		}
		if (m % 2 == 1 or count_symmetric == 0) {
			cout << "NO" << "\n";
			continue;
		}
		cout << "YES" << "\n";
	}
	return 0;
}
