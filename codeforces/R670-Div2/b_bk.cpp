#include "bits/stdc++.h"

using namespace std;
using vi =vector<int>;
using ll = long long;

const int MAXN = 1e5;

int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int cnt_neg = 0;
		for(int i = 0;i < n;i++) {
			int p;
			cin >> p;
			if (p < 0)
				cnt_neg++;
			a[i] = p;
		}
		sort(a, a+n);

		ll mult = 1;
		int picks = 5;	
		int l = 0;
		int r = n-1;
		
		bool pick_negative = 0;
		while(picks > 0){
			int lhs = a[l];
			int rhs = a[r];

			if (l == r){ 
				mul *= lhs;
				picks--;
			}

			if (abs(lhs) > abs(rhs)){
				if (lhs < 0){
					if (rhs < 0 and picks >= 2){
						mul *= rhs * lhs;
						l++;
						r--;
						picks -= 2;
						continue;
					}

					int next_neg = l+1;		
					if (next_neg == r and picks == 2){
						mul *= lhs;
						picks--;
						l++;
						continue;
					}
					
					int next_lhs = a[next_neg];
					ll mult_left = next_lhs * lhs;
					

				} else{
					mult *= lhs;
					picks--;
					l++;
				}
			} else{
				if (rhs < 0){
					//NEED TO PICK ANOTHER NEGATIVE
				} else{
					mul *= rhs;
					picks--;
					r--;
				}
			}
		}
	}

	return 0;
}
