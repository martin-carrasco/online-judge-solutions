#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2e5 + 10;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin  >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, int> last_num;
		map<int, int> cnt_gaps;
		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;
			if(last_num.find(tmp) == last_num.end()){
				last_num[tmp] = i;
				cnt_gaps[tmp] = 1;
				if (i == 0)
					cnt_gaps[tmp]--;
				continue;
			} 
			int last_pos = last_num[tmp];
			last_num[tmp] = i;
			if (last_pos == i-1){
				continue;
			}
			cnt_gaps[tmp]++;
		}
		if (last_num.size() == 1){
			cout << 0 << "\n";
			continue;
		}
		if ( last_num.size() == n){
			cout << 1 << "\n";
			continue;
		}
		int min_cnt = 1e9;
		for(auto [k, v] : cnt_gaps){
			int cnt = last_num[k] == n-1 ? v : v+1;
			if(cnt < min_cnt){
				min_cnt = cnt;
			}
		}
		cout << min_cnt << "\n";
	}

	return 0;
}
