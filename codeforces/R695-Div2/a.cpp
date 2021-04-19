#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int a[3] = {9, 8, 9};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int seconds = 2;
		for(int i = 0;i < n;i++){
			if (i <= 2) {
				cout << a[i];
				continue;
			}
			int num = 8;
			num = (num + seconds) % 10;
			cout << num;
			seconds++;
		}
		cout << "\n";
	}

	return 0;
}
