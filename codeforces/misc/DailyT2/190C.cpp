#include "bits/stdc++.h"

using namespace std;

int n;
string ans = "";

bool o_pair(int cnt, bool open){
	if (n == 0)
		return false;
	string c;
	cin >> c;

	if (c == "pair") {
		ans.append("pair<");
		bool f = o_pair(cnt+1, 1);
		ans.append(",");
		f = f & o_pair(cnt+1, 0);
		ans.append(">");
		return f;
	}
	else {
		ans.append("int");
		n--;
		return true;
	}
}

int main(){
	cin >> n;

	int cnt = 0;
	string s;

	bool a = o_pair(0, 0);
	getline(cin, s);
	if (n > 0 or not s.empty()) { 
		while(n > 0) {
			cin >> s;
			n--;
		}
		cout << "Error occurred" << "\n";
		return 0;
	}
		
	if(a)
		cout << ans << "\n";
	else
		cout << "Error occurred" << "\n";
	return 0;
}
