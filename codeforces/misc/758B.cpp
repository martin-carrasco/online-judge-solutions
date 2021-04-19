#include "bits/stdc++.h"

using namespace std;


int cnt_cols[4];
vector<char> avail_cols;
map<int, char> pos;		
map<char, int> cnt_final;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	avail_cols.push_back('R');
	avail_cols.push_back('G');
	avail_cols.push_back('B');
	avail_cols.push_back('Y');


	for(int i = 0;i < s.size();) {
		for(int j = i;j < i+4;j++){
			if (j == s.size()) break;
			if (s[j] == '!') continue;
			int idx = j % 4;
			if (pos.count(idx)) continue;
			pos[idx] = s[j];
			avail_cols.erase(find(avail_cols.begin(), avail_cols.end(), s[j]));
		}

		i+=4;
	}

	for(int i = 0;i < 4;i++){
		if (pos.count(i)) continue;
		auto it = avail_cols.begin();
		pos[i] = *it;
		avail_cols.erase(it);
	}

	for(int i = 0;i < s.size();i++){
		if (s[i] != '!') continue;
		int idx = i % 4;	
		cnt_final[pos[idx]] += 1;
	}
	cout << cnt_final['R'] << " " << cnt_final['B'] << " " << cnt_final['Y'] << " " << cnt_final['G'] << "\n";

	return 0;
}
