#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 2e5;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		int n;
		cin >> n >> s;
		for(int i = 0;i < s.size();i++){
			char c = s[i];	
			if (c == '1'){
				if (i > 0 and s[i-1] == '2')
					cout << '0';
				else  {
					s[i] = '2';
					cout << '1';
				}
			}
			if (c == '0'){
				if (i > 0 and s[i-1] == '1')
					cout << '0';
				else  {
					s[i] = '1';
					cout << '1';
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
