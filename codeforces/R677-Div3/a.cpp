#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;

		int dig = x % 10;
		int len = 0;
		while(x > 0){
			x /= 10;
			len++;
		}
		int comp = (dig-1)*10; 
		for(int i = 1;i <= len;i++){
			comp += i;
		}
		cout << comp << "\n";
	}

	return 0;
}

