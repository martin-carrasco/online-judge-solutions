#include "bits/stdc++.h"

using namespace std;

int rooms[] = {3, 5, 7};
bool vis[3];
int cnt[3] = {0, 0, 0};

bool solve(int n){
	if (n == 0) 
		return true;
	for(int i = 0;i < n;i++){
		if (n < rooms[i]) break;
		if (vis[i]) continue;

		cnt[i]++;
		bool ans1 = solve(n - rooms[i]);
		if (ans1)
			return true;
		cnt[i]--;

		vis[i] = 1;	
		cnt[i]++;
		bool ans2 = solve(n - rooms[i]);
		vis[i] = 0;
		cnt[i]--;

		if (ans2)
			return true;
	}
	return false;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool ans = solve(n);
		if (ans) {
			for(int i = 0;i < 3;i++){
				cout << cnt[i] << " ";
			}
			cout << "\n";
		} else {
			cout << -1 << "\n";
		}
		for(int i = 0;i < 3;i++){
			cnt[i] = 0;
		}
	}

	return 0;
}

