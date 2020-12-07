#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e6;

int a[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0;i < n;i++) cin >> a[i];


	set<int> seen;
	int i = 0;
	int cnt = 0;
	int ans = 0;

	for(int j = 0;j < n;j++){
		if (seen.count(a[j])){
			while(i < j){
				int ele = a[i];
				seen.erase(ele);
				i++;
				cnt--;
				if (ele == a[j])
					break;
			}
		}
		seen.insert(a[j]);
		cnt++;	
		ans = max(ans, cnt);
	}
	cout << ans << "\n";

	return 0;
}
