#include "bits/stdc++.h"

using namespace std;

int main(){
	int n;
	cin >> n;
	map<string, int> mp;

	mp["polycarp"] = 1;
	for(int i = 0;i < n;i++){
		string st, from, to;
		cin >> to;
		cin  >> st;
		cin >> from;
		for_each(from.begin(), from.end(), [](char& c){ c = ::tolower(c); });
		for_each(to.begin(), to.end(), [](char& c){ c = ::tolower(c); });

		mp[to] = mp[from] + 1;
	}

	int max_len = 0;
	for(auto it = mp.begin();it != mp.end();it++){
		max_len = max(max_len, it->second);	
	}

	cout << max_len << "\n";
	return 0;
}
