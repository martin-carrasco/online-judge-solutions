#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi a(n);
		for(int i = 0;i < n;i++) cin >> a[i];
		vi b = a;
		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end());
		
		string ans = "";
		int sum = 0;
		bool correct = true;
		for(int i = 0;i < n;i++){
			bool break_l = false;
			for(auto it = a.begin();it != a.end();it++){
				if (*it + sum != 0){
					sum += *it;
					ans.append(to_string(*it) + " ");
					a.erase(it);
					break_l = true;
					break;
				}
			}
			if (not break_l) {
				correct = false;
				break;
			}
		}
		if (not correct) {
			ans = "";
			sum = 0;
			correct = true;
			for(int i = 0;i < n;i++){
				bool break_l = false;
				for(auto it = b.begin();it != b.end();it++){
					if (*it + sum != 0){
						sum += *it;
						ans.append(to_string(*it) + " ");
						b.erase(it);
						break_l = true;
						break;
					}
				}
				if (not break_l) {
					correct = false;
					break;
				}
			}
		}


		if (correct) {
			cout << "YES" << "\n";
			cout << ans << "\n";
		} else {
			cout << "NO" << "\n";
		}
		
	}


	return 0;
}
