#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;

	int last_taken = x;	
	bool valid = true;
	for(int i = 0;i < n;i++){
		int l, r;
		cin >> l >> r;
		int bot = 7 - last_taken;

		int d_l, d_r;
		d_l = 7 - l;
		d_r = 7 - r;

		/*cout << "d_l: " << d_l
			<< ", d_r: " << d_r
			<< ", l: " << l
			<< ", r: " << r 
			<< ", top: " << last_taken
			<< ", bot: " << bot << endl;*/

		vi opts = {l, r, d_l, d_r, last_taken, bot};
		bool same = false;
		for(int j = 0; j < opts.size();j++){
			for(int k = j+1;k < opts.size();k++){
				if (opts[j] == opts[k]){
					same = true;
					break;
				}
			}
		}
		if (same){
			valid = false;
		}
		last_taken = bot;
	}

	if (valid)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
