#include "bits/stdc++.h"

using namespace std;

const int MAXN = 3000 + 5;

int a[MAXN];

int main(){
	int n;
	cin >> n;
	set<int> oc;
	for(int i = 0;i < n;i++)
		cin >> a[i];

	sort(a, a+n);

	int ans = 0;
	for(int i = 0; i < n;i++){
		int badge = a[i];
		while (oc.count(badge)) {
			badge++;
			ans++;
		}
		oc.insert(badge);
	}
	
	cout << ans << "\n";

	return 0;
}
