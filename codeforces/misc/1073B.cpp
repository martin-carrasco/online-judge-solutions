#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e6;

int a[MAXN];
int main(){
	int n;
	map<int, int> mp;
	cin >> n;

	for(int i = 0;i < n;i++){
		int t;
		cin >> t;
		mp[t] = i;
	}

	int max_pos = -1;
	vector<int> ans;
	for(int i = 0;i < n;i++){
		int t;
		cin >> t;
		int pos = mp[t];

		if (max_pos <= pos){
			ans.push_back(pos - max_pos);
			max_pos = pos;
		} else if (max_pos > pos){
			ans.push_back(0);
		}
	}

	for(const auto& an : ans)
		cout << an << " ";
	cout << "\n";
	return 0;
}
