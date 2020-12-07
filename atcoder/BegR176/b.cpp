#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAX_N = 1e6;
ll a[MAX_N];
int n;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	ll count = 0;
	for(int i = 0;i < s.size();i++){
		char c = s[i] - '0';
		ll val = c;
		count = (count + val) % 9;
	}

	if (count == 0)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
	return 0;
}
