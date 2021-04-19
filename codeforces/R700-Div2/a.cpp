#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;

const int MAXN = 2e5 + 5;

int t, n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
		string s;
		cin >> s;


		for(int i = 0;i < s.size();i++){
			char c = s[i];
			if (i % 2 == 0) {
				if (c > 'a') {
					cout << "a";
				} else {
					cout << "b";	
				}
			} else {
				if (c < 'z'){
					cout << "z";
				}
				else {
					cout << "y";
				}
			}
		}
		cout << "\n";
		
	}
	return 0;
}
