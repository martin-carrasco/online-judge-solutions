#include "bits/stdc++.h"

using namespace std;

const int MAXN = 55;
int d[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int  p, r, nt_cnt;

	nt_cnt = p = r = 1;
	while(1){
		cin >> p >> r;
		if (not p and not r)
			break;
		map<string, int> mp;
		int cnt = 0;

		for(int i = 0;i < p;i++){
			for(int j = 0;j < p;j++){
				if (i == j)
					d[i][j] = 0;
				else
					d[i][j] = 1e9;	
			}
		}
		
		for(int i = 0;i < r;i++){
			string s, des;

			cin >> s >> des;

			if (not mp.count(s)){
				mp[s] = cnt++;
			}

			if (not mp.count(des)) {
				mp[des] = cnt++;
			}

			int x = mp.at(s);
			int y = mp.at(des);

			d[x][y] = 0;
			d[y][x] = 0;
		}

		for(int k = 0;k < p;k++){
			for(int i = 0;i < p;i++){
				for(int j = 0;j < p;j++){
					d[i][j] = min(d[i][j], d[i][k] + d[k][j] + 1);
				}
			}
		}

		int max_deg = 0;
		for(int i = 0;i < p;i++){
			for(int j = 0;j < p;j++){
				if (d[i][j] > max_deg)
					max_deg = d[i][j];
			}
		}

		cout << "Network " << nt_cnt << ": ";
		if (max_deg == 1e9)
			cout << "DISCONNECTED";
		else
			cout << max_deg + 1;
		cout << "\n" << "\n";
		nt_cnt++;
	}

	return 0;
}
