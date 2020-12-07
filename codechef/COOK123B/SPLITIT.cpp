#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);


	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;

		int i = n-2;
		int j = n-1;
		
		bool ans = false;
		while(i >= 0){
			if (s[i] == s[j]){
				ans = true;
				break;
			} else {
				i--;
			}
		}
		if (ans)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}
