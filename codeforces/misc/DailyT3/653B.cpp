#include "bits/stdc++.h"

using namespace std;

vector<string> perms;
void perm_str(char st[], string prefix, int n, int k){
	if (k == 0){
		perms.push_back(prefix);
		return;
	}

	for(int i = 0;i < n;i++){
		string new_pref;

		new_pref = prefix + st[i];

		perm_str(st, new_pref, n, k-1);
	}

}

int main(){
	int n, q;
	cin >> n >> q;
	map<string, char> mp;
	char ab[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	perm_str(ab, "", 6, n);

	while(q--){
		string tmp;
		char to;
		cin >> tmp;
		cin >> to;
		mp[tmp] = to;
	}

	int count = 0;
	for(string perm_try : perms){
		string red_perm = perm_try;
		while(red_perm.size() > 1){
			string sub_perm = red_perm.substr(0, 2);
			if (not mp.count(sub_perm))
				break;
			red_perm.erase(0, 2);
			red_perm.insert(0, 1, mp[sub_perm]);
		}

		bool correct = red_perm.size() == 1 and red_perm[0] == 'a';
		count += correct;
	}
	cout << count << "\n";
	return 0;
}
