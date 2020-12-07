#include "bits/stdc++.h"

using namespace std;

int gcd(int a1, int b){
	while(b != 0){
		int t = b;
		b = a1 % b;
		a1 = t;
	}
	return a1;
}

const int MAX_N = 1e5 + 5;

int a[MAX_N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int min_e = 1e9;
		int min_pos = 0;
		for(int i = 1;i<=n;i++) {
			cin >> a[i];
			if (a[i] < min_e) {
				min_e = a[i];
				min_pos = i;		
			}
		}

		bool swapped = true;
		for(int i = 1;i < n;i++){
			if (a[i] > a[i+1]){
				swapped = false;
				for(int j = i+1;j <= n;j++){
					int gcd_b = gcd(a[j], a[i]);
					//cout << gcd_b << "\n";
					if (a[j] == a[i+1] and gcd_b == min_e){
						swap(a[i], a[j]);
						swapped = true;
						break;
					}
					if (a[j] < a[i+1] and gcd_b == min_e){
						swap(a[i], a[j]);
						swapped = true;
						break;
					}
				}
				if (not swapped){
					cout << "NO" << "\n";
					//cout << "i: " << i << ", j: " << i+1 << "\n";
					break;		
				}
			}
		}
		if (swapped)
			cout << "YES" << "\n";
	}
	return 0;
}
