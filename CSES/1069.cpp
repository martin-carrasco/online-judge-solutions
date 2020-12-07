#include "bits/stdc++.h"

using namespace std;

int main(){
	string s;
	cin >> s;

	char last_char = -1;
	int max_sub = 0;
	int current_sub = 0;
	for(char c : s){
		if (last_char != c){
			max_sub = max(current_sub, max_sub);
			current_sub = 0;
		}
		current_sub++;
		last_char = c;
	}
	max_sub = max(max_sub, current_sub);
	cout << max_sub << "\n";
	return 0;
}
