#include "bits/stdc++.h"

using namespace std;
using ll = long long;



int main(){
	int n;
	string x;
	cin >> n;
	cin >> x;
	string ans = "";


	for(char c : x){
		if (c == '0' or c == '1')
			continue;
		else if (c == '2' or c == '3' or c == '5' or c == '7'){
			ans += c;
		}
		else if (c == '4'){
			ans.append("2");
			ans.append("2");
			ans.append("3");
		}
		else if (c == '6'){
			ans.append("5");
			ans.append("3");
		}
		else if (c == '8'){
			ans.append("7");
			ans.append("2");
			ans.append("2");
			ans.append("2");
		}
		else if (c == '9'){
			ans.append("7");
			ans.append("3");
			ans.append("3");
			ans.append("2");
		}
	}

	sort(ans.begin(), ans.end(), greater<char>());
	cout << ans << "\n";
	return 0;
}
