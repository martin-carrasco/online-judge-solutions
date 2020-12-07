#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using ll = long long;

const int MAXN = 1e5 + 5;

int n;
ii a[MAXN];
ii b[MAXN];
int cnt_a, cnt_b;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		cnt_a = cnt_b = 0;
		ll sum = 0; 
		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;

			ii p = {tmp, i};
			if (tmp < 0) {
				a[cnt_a++] = p;
			}
			else if (tmp > 0){
				sum += tmp;
				b[cnt_b++] = p;
			}
		}	

		for(int i = 0;i < cnt_a;i++){
		//	cout << "Neg Val: " << a[i].first << ", i: " << a[i].second << endl;
		}
		for(int i = 0;i < cnt_b;i++){
		//	cout << "Pos Val: " << b[i].first << ", i: " << b[i].second << endl;
		}
		//cout << endl;

		int rhs, lhs;
		rhs = cnt_b-1;
		lhs = cnt_a-1;
		while(1){
			if (rhs < 0 or lhs < 0)
				break;

			ii curr_neg = a[lhs];
			ii curr_pos = b[rhs];
		//	cout << "Neg Val: " << curr_neg.first << ", i: " << curr_neg.second << endl;
		//	cout << "Pos Val: " << curr_pos.first << ", i: " << curr_pos.second << endl;
			int f_value = min(abs(curr_neg.first), curr_pos.first);
		//	cout << "F_val: " << f_value << endl;
			if (curr_neg.second > curr_pos.second) {
				sum -= (ll) f_value;
				a[lhs].first += f_value;
				b[rhs].first -= f_value;
				if (a[lhs].first == 0)	
					lhs--;
				if(b[rhs].first == 0)
					rhs--;
			} else{
				rhs--;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
