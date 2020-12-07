#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 1000 + 5;
using ii = pair<int, int>;

bool g[MAX_N][MAX_N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;

	vector<
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		for(int j= 1;j <= m;j++) {
			char c;
			cin >> c;
			cout << c << endl;
			g[i][j] = c - '0';
		}
	}
 
	cin >> q;

	for(int i = 0;i < q;i++){
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;

		for(int x = x0;x <= x1;x++){
			for(int y = y0;y <= y1;y++){
				g[x][y] = not g[x][y];	
			}
		}
	}

	for(int i = 1; i <= n;i++){
		for(int j= 1;j <= m;j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
