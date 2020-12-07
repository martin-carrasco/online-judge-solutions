#include "bits/stdc++.h"

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a,b,c;
		int a_x, b_x, c_x;
		a_x = b_x = c_x=0;
		string hand;
		cin >> a >> b >> c;
		cin >> hand;

		for(char ch : hand){
			if (ch == 'R') {
				a_x++;
			}
			else if(ch == 'P') {
				b_x++;
			}
			else {
				c_x++;
			}
		}
		
		int play_a = a >= c_x ? c_x : a;
		int play_b = b >= a_x ? a_x : b;
		int play_c = c >= b_x ? b_x : c;

		int rem_a = a -play_a;
		int rem_b = b - play_b;
		int rem_c = c - play_c;

		int ans = play_a + play_b + play_c;

		if (ans >= ceil((n * 1.0) / 2)) {
			cout << "YES" << "\n";
			for (char ch : hand){
				if (ch == 'R'){
					if (play_b){
						cout << "P";
						play_b--;
					} else if (rem_a){
						cout << "R";
						rem_a--;
					} else{
						cout << "S";
						rem_c--;
					}
				} else if (ch == 'P') {
					if (play_c){
						cout << "S";
						play_c--;
					} else if (rem_a){
						cout << "R";
						rem_a--;
					} else{
						cout << "P";
						rem_b--;
					}
				} else {
					if (play_a){
						cout << "R";
						play_a--;
					} 
					else if (rem_b){
						cout << "P";
						rem_b--;
					} else{
						cout << "S";
						rem_c--;
					}
				}
			}
			cout << "\n";
		}
		else
			cout << "NO" << "\n";
	}

	return 0;
}
