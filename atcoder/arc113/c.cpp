#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2e5 + 5;
string s;
set<int> st_r, end_r;
map<int, int> cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;

	cnt[s.size() - 1 - 'a']++;
	int ans = 0;
	for(int i = s.size()-2; i < s.size();i--){
		if (s[i] == s[i+1]){
			int tot = s.size()-(i+2);	
			int cnt_same = cnt[s[i] - 'a'] - 1;
			//cout <<"i:" << i <<  ", cnt_same: " << cnt_same << ", tot: " << tot << "\n";
			ans += tot - cnt_same;
			cnt.clear();
			cnt[s[i] - 'a'] = tot;
		}
		cnt[s[i] - 'a']++;
	}
	cout << ans << "\n";

	return 0;
}
