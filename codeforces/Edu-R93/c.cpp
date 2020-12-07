#include "bits/stdc++.h"


using namespace std;
using ll = long long;

const int MAX_N = 1e6 + 5;
int a[MAX_N];


int main(){
	vector<int> ans;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		char ci;

		map<int, int> mp;
		for (int i = 0;i < n;i++){
			cin >> ci;	
			int num = ci - '0';
			a[i] = i == 0 ? num : num + a[i-1];
		}

		ll res = 0;
		mp[0] = 1;
		for(int i = 0;i < n;i++){
			if (i == 0){
				res += mp[a[0]];
				mp[a[0]] += 1;
			}
			else {
				res += (ll)mp[a[i] - i + 1];
				mp[a[i] - i + 1] += 1;
			}
		}
		ans.push_back(res);
	}

	for (auto& sc : ans){
		cout << sc << endl;
	}
	return 0;
} 

