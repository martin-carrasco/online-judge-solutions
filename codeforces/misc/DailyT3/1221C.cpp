#include "bits/stdc++.h"

using namespace std;

int main() {
	int q;
	cin >> q;

	while(q--){

		int c, m, x;
		cin >> c >> m >> x;

		int lhs = 0;
		int rhs = min(c, m); 

		while (lhs < rhs){
			int mid = lhs  + (rhs - lhs) /  2;
			//cout << "LHS: " << lhs << ", RHS: " << rhs << ", MID: " <<  mid << "\n";
			
			int c_c, c_m;
			c_c = c - mid;
			c_m = m - mid;

			int remaining = c_c + c_m + x;

			if (c_c < 0 or c_m < 0 or remaining < mid){
				rhs = mid-1;
				//cout << "LOWER" << "\n";
				continue;
			}

			if (c_c >= 1 and c_m >= 1 and remaining >= 3 ){
				c_c = c - rhs;
				c_m = m - rhs;
				remaining = c_c + c_m + x;
				if (c_c >= 0 and c_m >= 0 and remaining >= rhs){
					lhs = mid = rhs;
					break;
				}
				if (abs(rhs - lhs) == 1){
					rhs = lhs = mid;
					break;
				}
				//cout << "HIGHER" << "\n";
				lhs = mid;
				continue;
			}

			lhs = rhs = mid;
			break;
		}
		cout << lhs << "\n"; 
	}

	return 0;
}
