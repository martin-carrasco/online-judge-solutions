#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1e3 + 5;

int a[MAXN];

int main(){
	int t;
	cin >> t;
	while(t--){
		vi remain;
		int n, k;
		cin >> n;
		k = n / 2;

		int cnt_0, cnt_1;
		cnt_0 = 0;
		cnt_1 = 0;
		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;
			if (tmp == 0)
				cnt_0++;
			if (tmp == 1)
				cnt_1++;
			a[i] = tmp;
		}
		if (cnt_1 == 0) {
			cout << n - 1 << "\n";
			for(int i = 1;i < n;i++){
				cout << a[i] << " ";
			}
			cout << "\n";
		}
		else if (cnt_1 <= k){
			cout << n - cnt_1 << "\n";
			for(int i = 0;i < n;i++){
				if (a[i] == 1)
					continue;
				cout << a[i] << " ";
			}
			cout << "\n";
		}
		else if (cnt_0 == 0){
			cout << n << "\n";
			for(int i = 0; i < n;i++)
				cout << a[i] << " ";
			cout << "\n";
		}
		else if (cnt_1 > k){
			int take_1 = 0;
			if (cnt_1 & 1)
				take_1++;
			cout << n - take_1 - cnt_0 << "\n";
			for(int i = 0;i < n;i++){
				if (a[i] == 1 and take_1 > 0){
					take_1--;
					continue;
				}
				if (a[i] == 0)
					continue;
				cout <<  a[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
