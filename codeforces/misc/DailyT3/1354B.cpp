#include "bits/stdc++.h"

using namespace std;

string s;

bool check(int m){

	int cnt[4] = {0};
	for(int i = 0;i < s.size();i++){
		if (i >= m) cnt[s[i - m] - '0'] -= 1;
		cnt[s[i] - '0'] += 1;	

		if (cnt[1] >= 1 and cnt[2] >= 1 and cnt[3] >= 1)
			return 1;
	}
	return 0;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> s;

		int l = 0;
		int r = s.size() * 2;
		int ans = 0;

		while(l <= r){
			int mid = (l+r) / 2;
			//cout << "l: " << l << ", r: " << r << ", mid: " << mid << "\n";
			if (!check(mid)){
				//cout << "Invalid" << "\n";
				l = mid + 1;	
			} else{
				//cout << "Valid" << "\n";
				ans = mid;	
				r = mid - 1;
			}
		}
		cout << ans  << "\n";
	}
	return 0;
}
