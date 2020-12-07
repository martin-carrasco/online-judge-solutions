#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;

		vi a;
		for(int i = 0;i < n;i++){
			int t;
			cin >> t;
			if (t % 3 == 0)
				continue;
			a.push_back(t);
		}


			
		int s = a.size();
		int ans = n - s;
		int tot_2 = 0;
		int tot_1 = 0;

		for(int i = 0;i < s;i++){
			if (a[i] % 3 == 1)
				tot_1++;
			else if (a[i] % 3 == 2)
				tot_2++;
		}



		int m_tot = min(tot_2, tot_1);
		ans += m_tot;

		tot_1 -= m_tot;
		tot_2 -= m_tot;


		//cout << "Tot 2: " << tot_2 << "\n";
		//cout << "Tot 1: " << tot_1 << "\n";

		int tt1 =  floor(tot_2 / 3);
		int tt2 = floor(tot_1 / 3);

		//cout << "Tot 2 div: " << tt1 << "\n";
		//cout << "Tot 1 div: " << tt2 << "\n";

		ans += max(tt1, tt2);
		cout << ans << "\n";
	}


	return 0;
}
