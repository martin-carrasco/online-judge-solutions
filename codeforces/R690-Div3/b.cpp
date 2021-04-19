#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const string S = "2020";
const int MAXN = 300 + 5;
int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n;
		cin >> s;

		set<int> two_pos;
		set<int> zero_pos;

		for(int i = 0;i < s.size();i++){
			if (s[i] == '2') two_pos.insert(i);
			if (s[i] == '0') zero_pos.insert(i);
		}

		bool ans = false;
		for(int f_two_pos : two_pos){
			if (f_two_pos + 3 == n-1 and s[f_two_pos +1]	== '0' and s[f_two_pos+2] == '2' and s[f_two_pos+3] == '0'){
				ans = true;
				break;
			}

			if (f_two_pos == 0){
				int digits = 3;
				if (s[f_two_pos+1] == '0'){
					digits--;
					if (s[f_two_pos+2] == '2'){
						digits--;
						if(s[f_two_pos+3] == '0'){
							ans = true;
							break;
						}
					}
				} 

				string sub = s.substr(n - digits, digits);
				string r_sub =  S.substr(4 - digits, digits);
				//cout << sub << endl;
				//cout << r_sub << endl;
				if (sub.compare(r_sub) == 0){
					ans = true;
					break;
				}
			}
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
