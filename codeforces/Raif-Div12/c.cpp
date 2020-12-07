#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		string s;
		stack<char> last;
		cin >> s;
		for (char c : s){
			if (c == 'A')
				last.push(c);
			else if (last.size() == 0)
				last.push(c);
			else
				last.pop();
		}

		cout << last.size() << "\n";
	}

	return 0;
}
