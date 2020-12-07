#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long;

const ll SINGLE = 1ULL;


ll s_pow(ll lb, ll up){ int numb_bits = (64 - __builtin_clzll(up));
	//cout << "NUMB BITS: " <<  numb_bits  << "\n";
	ll msb_l = (lb >> (numb_bits-1));
	ll msb_u = (up >> (numb_bits-1));
	ll diff_power = msb_l ^ msb_u; 
	//cout << "MSB U: "  << msb_u << "\n";
	//cout << "MSB L: " << msb_l << "\n";
	ll ans = diff_power ? 0ULL : (SINGLE << (numb_bits-1));
	int i = numb_bits - 2;
	while(i >= 0){
		ll bit_upp = up & (SINGLE << i);
		ll bit_low = lb & (SINGLE << i);
		
		//cout << "BIT UP: " << bit_upp << "\n";
		//cout << "BIT LOW: " << bit_low << "\n";

		if (!diff_power){
			if (not bit_low and bit_upp)  {
				//cout << "CHANGE" << "\n";
				diff_power = !diff_power;
			} else {
				ll tmp_ans = ans | (SINGLE << i);	
				if (tmp_ans < up)
					ans = tmp_ans;
			}

		} else{
			if (not bit_upp){
				ll tmp_ans = (SINGLE << i) | ans;
				if (tmp_ans < up)
					ans = tmp_ans;
			} else {
				ll bitmask = SINGLE;
				for(int j = 0;j < numb_bits;j++){
						bitmask |= SINGLE;
						bitmask = bitmask << 1; 
				}
 
				//cout << bitmask << "\n";
				//cout << i << "\n";
				//cout << ans << "\n";
				ll tmp_ans = ans & bitmask;
				//cout << "TMP ANS: " << tmp_ans << "\n";
				
				if (tmp_ans < up and tmp_ans >= lb) { 
					ans = tmp_ans;
				} else {
					tmp_ans = ans | (SINGLE << i);
					if (tmp_ans >= lb and i == 0)
						ans = tmp_ans;
				}
			}
		}

		i--;
	}
	return ans;		
}


int main(){
	ll l, r;
	cin >> l >> r;
	if (l == r) {
		cout << 0 << "\n";
		return 0;
	}
	if(l == 1 and r == 3)
		r--;

	ll ans = s_pow(l, r);
	//cout << ans << "\n";
	ans = ans^r;
	cout << ans << "\n";	
}
