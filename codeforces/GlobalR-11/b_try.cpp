#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;
using ii = pair<int, int>;

ll n;

ll score(ll k, string s){
		multiset<int> gains;
		ll first_block = 0;
		ll block_size = 0;
		ll ans = 0;
		char last_char = -1;
		bool first_block_yet = false;
		for(int i = 0;i < s.size();i++){
			if (not first_block_yet){
				if (s[i] == 'W')  {
					first_block_yet = true;
					ans++;
				}
				else  {
					gains.insert(2);
					first_block++;
				}
				last_char = s[i];
				continue;
			}
			if (s[i] == 'L'){
				if (i+1 < s.size() and s[i+1] == 'W' and last_char == 'W') {
					if (k > 0) {
						ans+=2;
						k--;
						s[i] = 'W';	
					}
				} else {
					block_size++;
				}
			}
			else if(s[i] == 'W'){
				block_size = 0;
				ans++;
				if (last_char == 'W')
					ans++;
			}
			last_char = s[i];
		}


		int end = n - block_size;
		int start = first_block;
		for(int i = start;i < end;i++){
			if (s[i] == 'L'){
				if (i+1 < end and s[i+1] == 'W')
					gains.insert(3);
				else
					gains.insert(2);
			}
		}
		for(int i = 0;i < start){
			if (i == 0) {
				gains.insert(1);
			} else {
				gains.insert(2);
			}
		}

		if (k > 0){
			if (first_block == n) {
				ans+= 1;
				k--;
				first_block--;
			}
			if (k > 0 ) {
				ans += min(k, first_block)*2;
				k -= min(k, first_block);
			}
		}

		if (k > 0){
			ans += min(k, block_size)*2;
			k -= min(k, block_size);
		}

		return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll k;
		string s;
		cin >> n >> k;
		cin >> s;

		ll p_ans = score(k, s);
		reverse(s.begin(), s.end());	
		ll p_ans2 = score(k, s);

		ll ans = max(p_ans, p_ans2);
		cout << ans << "\n";
	}
	return 0;
}
