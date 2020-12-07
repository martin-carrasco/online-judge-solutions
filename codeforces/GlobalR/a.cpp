#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		int ele;
		cin >> ele;
		int ans = n;
		for(int i = 0;i < n-1;i++) {
			int tmp;
			cin >> tmp;
			if (tmp != ele){
				ans = 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
