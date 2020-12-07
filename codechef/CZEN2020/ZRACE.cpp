#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int a[5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		for(int i = 0;i < 5;i++) cin >> a[i];
		int r = a[0];
		sort(a, a+5, greater<int>());

		if (r == a[0])
			cout << "Champions";
		else
			cout << -1;
		cout << "\n";
	}
	return 0;

}
