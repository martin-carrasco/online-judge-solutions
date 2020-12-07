#include "bits/stdc++.h"

using namespace std;

bool sim(string &s, string& n_s, int n){
	int i = 0;
	int j = n-1;
	int counter = 0;
	bool all_sim = false;
	while(1){
		bool o_sim = false;
		for (int x = i;i <= j;i++){
			if (s[x] == n_s[x-counter]){
				o_sim = true;
				break;
			}
		}
		if (not o_sim)
			return false;
		all_sim = true;
		i++;
		j++;
		counter++;
		if (j == s.size())
			break;
	}
	return all_sim;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		string s, new_s;
		new_s = "";
		cin >> n;
		cin >> s;

		int i = 0;
		int j = n-1;
		bool sim_a = false;
		while(1){
			string tr = s.substr(i, j-i + 1);
			bool sim_n = false;
			do{
				if (sim(s, tr, n)) {
					sim_n = true;
				}

			}while(next_permutation(tr.begin(), tr.end()));
			if (sim_n) {
				sim_a = true;
				cout << tr << "\n";
				break;
			}
			i++;
			j++;
			if (j == s.size()) {
				sim_a = false;
				break;
			}
		}

		if (sim_a)
			continue;

		i = 0;
		j = n -1;
		string final_s = "";
		vector<string> strs;
		while(j != s.size()){
			strs.push_back(s.substr(i, j-i + 1));
			i++;j++;
		}
		for(int iter = 0;iter < n;iter++){
			int sim_1 = 0;
			int sim_0 = 0;
			for(string st_iter : strs){
				if (st_iter[iter] == '1')
					sim_1++;
				else
					sim_0++;
			}
			if (sim_1 > sim_0)
				final_s.append("1");
			else
				final_s.append("0");
		}
		cout << final_s << "\n";
	}
	return 0;
}
