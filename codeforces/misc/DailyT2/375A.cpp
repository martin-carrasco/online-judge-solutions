#include "bits/stdc++.h"

using namespace std;
int cnt[11];
int main(){
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		char c = s[i];
		if (c - '0' == '1' or c - '0' == '6' or c - '0' == '8' or c - '0' == '9' or c-'0' == 0)
			cnt[c-'0']++;
	}

	string ans = "";
	for(s.
	return 0;
}
