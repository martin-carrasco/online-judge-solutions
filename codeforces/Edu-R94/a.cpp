#include "bits/stdc++.h"

using namespace std;



bool sim(string &s, string& n_s, int n){
	int i = 0;
	int j = n-1;
	while(j < s.size()){
		string curr = s.substr(i, j-i+1);	
		
		bool current_sim = false;
		for(int x = 0;x < curr.size();x++){
			if (curr[x] == n_s[x]) {
				current_sim = true;
				break;
			}
		}
		if (not current_sim)
			return false;
		i++;
		j++;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n;
		cin >> s;
		string s_0(n, '0');
		string s_1(n, '1');
		
		if (sim(s, s_0, n))
			cout << s_0 << "\n";
		else
			cout << s_1 << "\n";
	}
	return 0;
}
