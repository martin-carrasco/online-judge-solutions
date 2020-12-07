#include "bits/stdc++.h"

using namespace std;
using vi =vector<int>;
using ll = long long;
using pib = pair<ll, bool>;

const int MAXN = 1e5 + 5;

ll min_sign(vector<pib>& vec, bool is_pos){
	ll min_c = 1e9;	
	for(int i = 0;i < vec.size();i++){
		if (vec[i].first < min_c and vec[i].second == is_pos){
			min_c = vec[i].first; 
		}
	}

	if (is_pos)
		return min_c;
	return min_c * -1LL;
}


ll max_sign(vector<pib>& vec, bool is_pos){
	ll max_c = 0;	
	for(int i = 0;i < vec.size();i++){
		if (vec[i].first > max_c and vec[i].second == is_pos){
			max_c = vec[i].first; 
		}
	}
	
	if (is_pos)
		return max_c;
	return max_c * -1LL;
}

pib a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		for(int i = 0;i < n;i++) {
			ll p;
			cin >> p;
			a[i] = {abs(p), p >= 0};
		}

		sort(a, a+n, greater<pib>());
		
		vector<pib> chosen;
		ll mult = 1;
		for(int i = 0;i < n;i++){
			if (i <= 4){
				ll sign_p = a[i].second ? 1LL : -1LL;
				mult *= a[i].first * sign_p;
				chosen.push_back(a[i]);
				continue;
			}
			else if (mult < 0){
				//Find next negative
				ll next_negativ = -1LL;
				ll min_negativ = 1e9;
				ll pos = -1LL;

				for(int j = i;j < n;j++){
					if (a[j].second == 0) {
						next_negativ = max(a[j].first, next_negativ);
						min_negativ = min(min_negativ, a[j].first);
					}
					else if (a[j].second == 1 ){
						pos = max(a[j].first, pos);
					}
				}

				next_negativ *= -1LL;
				min_negativ *= -1LL;

				ll min_neg = min_sign(chosen, false);
				ll min_pos = min_sign(chosen, true);
				ll max_neg = max_sign(chosen, false);

				// If theres no other negative, positive is the best answer
				

				if (min_pos == 1e9) {
					if (pos != -1LL)
						mult = mult / min_neg * pos;
					else
						mult = mult / max_neg * min_negativ;
				}

				if (next_negativ == -1LL){
					mult = max(mult, mult / min_neg * pos);
					break;
				}



				ll final_op1 = mult / min_pos * next_negativ;
				ll final_op2 = mult / min_neg * pos;
				mult = max({mult, final_op1, final_op2, mult / max_neg * min_negativ});
			} 
			break;
		}
		cout << mult << "\n";
	}

	return 0;
}
