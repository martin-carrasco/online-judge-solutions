#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1000;

int a[MAXN], n, d, t;
multiset<int> nums;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
		cin >> n >> d;
		bool possible = true;

		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;
			a[i] = tmp;
			nums.insert(tmp);
			if (tmp > d) possible = false;
		}

		if (not possible) {
			while(1){
				auto it = nums.begin();
				auto it_final = nums.end();
				--it_final;

				int low_1 = *it;
				++it;
				int low_2 = *it;
				if (low_1 + low_2 > d) break;

				nums.erase(it_final);
				nums.insert(low_1 + low_2);


				it_final = nums.end();
				--it_final;

				if (*it_final <= d) {possible = true; break; }
			}
		}

		if (possible)
			cout << "YES\n";
		else
			cout << "NO\n";
		nums.clear();
	}



	return 0;
}
