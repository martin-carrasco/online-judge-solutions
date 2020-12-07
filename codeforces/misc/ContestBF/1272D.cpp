#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAX_N = 1e6 + 5;
int n;
int a[MAX_N];
int dp[MAX_N];
unordered_map<int,int> mp;



int main() {
	cin >> n;
	for (int i = 0; i < n;i++)
		cin >> a[i];

	int mx = -1e9;
	bool del = false;
	for (int i = 0;i < n;i++){
		if (mp.find(a[i] - 1) != mp.end()){
			int last_index = mp[a[i] - 1];
			if (i - last_index == 1) {
				dp[i] = dp[last_index] + 1;
			} else {
				if (not del){
					dp[i] =  dp[last_index] + 1;
					del = true;
				} else{
					dp[i] = 1;
					del = true;
				}
			}
		}
		else  {
			dp[i] = 1;
			del = false;
		}

		mp[a[i]] = i + 1;

		mx = max(mx, dp[i]);
	}
	cout << mx;
	return 0;
}
