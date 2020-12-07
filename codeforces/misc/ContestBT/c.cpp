#include "bits/stdc++.h"

using namespace std;
int n, m;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m) {
		cin >> n >> m;
		int g[n][n];

		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				g[i][g] = 0;
			}
		}

		for (int i = 0;i < m;i++){
			int s, d;
			cin >> s >> d;
			g[s][d] = 1;
		}
			
	}
	return 0;
}
