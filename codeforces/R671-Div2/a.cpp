#include "bits/stdc++.h"
 
using namespace std;
using vi = vector<int>;
 
const int MAXN = 1e3 + 5;
 
int a[MAXN];
bool v[MAXN];
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool odd_in_odd = false;
		bool even_in_even = false;
		for(int i = 0;i < n;i++){
			char c;
			cin >> c;
			a[i] = c - '0';
			if ((i+1) % 2 == 1 and a[i] % 2 == 1)
				odd_in_odd = true;
			if ((i+1) % 2 == 0 and a[i] % 2 == 0)
				even_in_even = true;
		}
 
		int ans;
		if (n % 2 == 0){
			if (not even_in_even) {
				ans = 1;	
			} else
				ans = 2;
		} else{
			if (odd_in_odd)
				ans = 1;
			else
				ans = 2;
		}

		cout << ans << "\n";
	}
 
	return 0;
}
