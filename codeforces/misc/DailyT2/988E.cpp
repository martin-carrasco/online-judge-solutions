#include "bits/stdc++.h"

using namespace std;

int cnt[10];
int max_pos[10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();

	for(int i = 0;i < 10;i++) max_pos[i] = -1;

	for(int i = 0;i < n;i++){
		char c = s[i];	
		if (c == '0') {
			cnt[0]++;
			if (i > max_pos[0])
				max_pos[0] = i;
		}
		else if (c == '2'){
			cnt[2]++;
			if (i > max_pos[2])
				max_pos[2] = i;
		}
		else if (c=='5'){
			cnt[5]++;
			if (i > max_pos[5])
				max_pos[5] = i;
		}
		else if ( c =='7') {
			cnt[7]++;
			if (i > max_pos[7])
				max_pos[7] = i;
		}
	}

	if ((cnt[0] < 2) and (cnt[0] == 0 or cnt[2] == 0) and (cnt[1] == 0 or cnt[2] == 0) and (cnt[3] == 0 or cnt[2] == 0)){
		cout << -1 << "\n";
		return 0;
	}


	for(int i = 0;i < n-1;i++){
		if (
	}



	return 0;
}
