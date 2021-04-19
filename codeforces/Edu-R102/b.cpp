#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}


vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

string s_1, s_2;
int t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
		cin >> s_1 >> s_2;
		int a, b;

		a = s_1.size();
		b = s_2.size();

		auto z_a = z_function(s_1);
		auto z_b = z_function(s_2);

		vector<string> possible_a, possible_b;

		for(int i = 0;i < a;i++){
			if (i + z_a[i] == a and z_a[i] != 0 and  a % i == 0) {
				possible_a.push_back(s_1.substr(0, i));			
			}
		}
		if (possible_a.size() == 0){
			possible_a.push_back(s_1);
		}

		for(int i = 0;i < b;i++){
			if (i + z_b[i] == b and z_b[i] != 0 and b % i == 0) {
				possible_b.push_back(s_2.substr(0, i));			
			}
		}
		if (possible_b.size() == 0){
			possible_b.push_back(s_2);
		}

		string out = "";
		for(auto str_1 : possible_a){
			for(auto str_2 : possible_b){
				if (str_1.compare(str_2) == 0 and (str_1.size() < out.size() or out.size() == 0)){
					out = str_1;
				}
			}
		}

		int lcm = abs(a*b) / gcd(a, b);
		int c = out.size();
		if (c == 0){
			cout << "-1\n";
			continue;
		}
		for(int i = 0;i < lcm / c;i++){
			cout << out;
		}
		cout << "\n";
	}

	return 0;
}
