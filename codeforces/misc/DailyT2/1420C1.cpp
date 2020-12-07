#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6;

int a[MAXN];
int main(){
	int t;
	cin >> t;			

	while(t--){
		int q, n;
		cin >> n >> q;
		for(int i = 0;i < n;i++) cin >> a[i];

		ll sum = 0;
		bool sign = 1;
		for(int i = 0;i < n;i++){
			int start = i == 0 ? 0 : a[i-1];
			int end = i == n-1 ? 0 : a[i+1];
			if (sign){
				if (start < a[i] and a[i] > end){
					sum += a[i];
					sign = !sign;
				}
			} else{
				if (start > a[i] and  a[i] < end) {
					sum -= a[i];
					sign = !sign;
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
