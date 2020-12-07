#include "bits/stdc++.h"

using namespace std;
const int MAXN = 1e5 + 5;
set<int> L[26]; 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	for(int i = 1;i <= s.size();i++){
		int num = (int)(s[i-1] - 'a');
		L[num].insert(i);
	}

	int q;
	cin >> q;
	while(q--){
		int q_t;
		cin >> q_t;
		if (q_t == 1){
			int pos;
			char c;
			cin >> pos;
			cin >> c;

			int num = (int) (c - 'a');
			for(int i = 0;i < 26;i++){
				if (L[i].count(pos)){
					L[i].erase(pos);
					break;
				}
			}
			L[num].insert(pos);

		}else {
			int l,r;
			cin >> l >> r;
			int ans = 0;
			for(int i = 0;i < 26;i++){
				auto it_low = L[i].lower_bound(l);
				if (it_low == L[i].end())
					continue;
				auto it_up = L[i].upper_bound(r);
				int d = distance(it_low, it_up);	
				if (d > 0)
					ans++;
			}
			cout << ans << "\n";

		}
	}
	
	return 0;
}


