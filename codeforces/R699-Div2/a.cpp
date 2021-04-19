#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e5 + 5;
int n, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		int px, py;
		cin >> px >> py;

		string s;
		cin >> s;

		int x, y;
		x = y = 0;
		bool ans = false;
		for(char c : s){
			if (c == 'U' or c == 'D'){
				if (py > y and c == 'U') y++;
				if (py < y and c == 'D') y--;
			} else {
				if (px > x and c == 'R') x++;
				if (px < x and c == 'L') x--;
			}
			if (x == px and y == py) {
				ans = true;
				break;
			}
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	
	}
	return 0;
}
