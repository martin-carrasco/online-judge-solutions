#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using vii = vector<vi>;

const int MAX_N = 1e5 + 100;



int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		map<int, bool> ex;
		vii g(n, vi());
		for(int i = 0;i < n;i++){
			int k;
			cin >> k;
			for (int j = 0;j < k;j++) {
				int tmp;
				cin >> tmp;
				g[i].push_back(tmp);
			}
		}
		
	
		vi not_match_pri;
		vi matched_prip;
		for(int pri = 0;pri < g.size();pri++){
			bool matched = 0;
			for (const int& pref : g[pri]){
				if (not ex.count(pref)) {
					ex[pref] = 1;
					matched = 1;
					matched_prip.push_back(pref);	
					break;
				}
			}
			if (not matched)
				not_match_pri.push_back(pri);
		}
		if (not_match_pri.size() == 0) {
			cout << "OPTIMAL" << endl;
			continue;
		}
		
		cout << "IMPROVE" << endl;
		sort(matched_prip.begin(), matched_prip.end());
		for(int k = 0;k < n;k++){
			if (matched_prip.size() < k+1){
				cout << not_match_pri[0] + 1 << " " << k+1 << endl;
				break;
			}
			if (k+1 != matched_prip[k]) {
				cout << not_match_pri[0] + 1 << " " << k+1 << endl;
				break;
			}
		}
	}
	return 0;
}
