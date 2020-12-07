#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, x, y;
		cin >> n >> x >> y;
		vi ans;

		int start = 0;
		int end = y - x;
		ans.push_back(x);
		ans.push_back(y);
		for(int i = 1;i <= end;i++){
			//cout << "i: " << i  << " ";
			if (end % i != 0) { // If we can reach both numbers
				//cout << "CRB" << "\n";
				continue;
			}
			if ((n-1) * i + x < y){ // And the amount of numbers between them is not n
				//cout << "ENB" << "\n";
				continue;
			}
			int steps = end / i; // How many numbers we have between the both
			int dec_count = x;
			while(steps != n-1){
				dec_count -= i;	
				if (dec_count < 1)
					break;
				ans.push_back(dec_count);
				steps++;
			}
			for(int r = x+i;r < y;r+=i){
				ans.push_back(r);	
			}
			int inc_count = y;
			while(steps < n - 1){
				inc_count += i;
				steps++;
				ans.push_back(inc_count);
			}
			//cout << "\n";
			break;
		}
		for(const auto& v : ans)
			cout << v << " ";
		cout << "\n";
	}

	return 0;
}
