#include "bits/stdc++.h"

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string a,b;
		cin >> a >> b;
		int cnt_disjoint_even, cnt_disjoint_odd;	
		cnt_disjoint_odd = cnt_disjoint_even = 0;

		bool last_valid = false;

		// Count disjoint even bits
		for(int i = 0;i < a.size();i+=2){
			if (a[i] != b[i]){
				if (last_valid)
					continue;
				cnt_disjoint_even++;
				last_valid = true;
			} else{
				last_valid = false;
			}
		}

		//Count disjoint odd bits
		last_valid = false;
		for(int i = 1;i < a.size();i+=2){
			if (a[i] != b[i]){
				if (last_valid)
					continue;
				cnt_disjoint_odd++;
				last_valid = true;
			} else{
				last_valid = false;
			}
		}

		cout << cnt_disjoint_even + cnt_disjoint_odd << "\n";
	}

	return 0;
}
