#include "bits/stdc++.h"

using namespace std;
using vi =vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e5 + 5;

bool a[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, d;
		vector<ii> ones;
		map<int, int> mp;
		cin >> n >> d;
		string st;
		cin >> st;
		
		int s, e;
		s = e = -1;

		int cnt_ones = 0;
		for(int i = 0;i < n;i++){
			char c = st[i];
			a[i] = c - '0';

			if (a[i] == 1){
				cnt_ones++;
				s = i;
			} else{
				if (s == -1 or e == -1)
					continue;
				e = i-1;
				ones.push_back({s, e});
				s = -1;
				e = -1;
			}
		}

		if (ones.size() == 0) {
			cout << 0 << "\n";
			continue;
		}
		
		int disconnects = n - cnt_ones;
		for(int i = 0;i < n;i++){
			if (a[i] == 1)
				mp[i] = disconnects;
		}

		int future_take = 0;
		int last_connect = 0;
		for(int k = 0;k < ones.size() - 1;k++){
			if (d == 0)
				break;
			auto [i, j] = ones[k];	
			auto [n_i, n_j] = ones[k+1];

			if (i - last_connect > n_j - j){
				int disas_amount = i - last_connect - 1;
				for(int l = i;l <= j;l++){
					mp[l] -= disas_amount;
				}
				future_take = disas_amount;
				last_connect = i;
			} else {
				int disas_amount = i - last_connect -1;
				for(int l = i;l <= j;l++){
					mp[l] -= (disas_amount + future_take);
				}
				last_connect = n_j;	
			}
			d--;
		}
		for(auto p : mp){
			cout << "Diconnects: " << p.second << "\n";
		}
	}
	return 0;
}
