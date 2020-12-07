#include "bits/stdc++.h"

using namespace std;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string s, new_s;
	cin >> s;

	
	for(char c : s){
		if (k == 0){
			string s_c(1, c);
			new_s.append(s_c);
			continue;
		}
		int max_dist = max((int)(c - 'a'), (int)('z' - c));
		if (k >= max_dist){
			char new_c = c - 'a' > 'z' - c ? 'a' : 'z';						
			string s_c(1, new_c);
			new_s.append(s_c);
			k -=  max_dist;
		} else {
			char new_c = c + k <= 'z' ? c+k : c-k;	
			string s_c (1, new_c);
			new_s.append(s_c);
			k = 0;	
		}
	}
	if (not k)
		cout << new_s << "\n";
	else
		cout << -1 << "\n";


	return 0;
}
