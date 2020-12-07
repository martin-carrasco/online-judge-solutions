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
		string s;
		cin >> s;
		int max_vals = s.size();
		if (s.size() > 1 and s[0] == '1'){
			bool fnd = true;
			for(int i =	1;i < s.size();i++){
				if (s[i] != '0') {
					fnd = false;
					break;
				}
			}
			if (fnd)
				max_vals--;
		}
		cout << max_vals << "\n";
	}


	return 0;
}
