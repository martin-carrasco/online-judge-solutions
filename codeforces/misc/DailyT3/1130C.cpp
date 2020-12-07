#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;


int n, x_0, y_0, x_1, y_1;
const int MAXN = 50 + 5;
bool board[MAXN][MAXN];

vector<ii> s, d;


void bfs(int r, int c, bool dest){
	bool vis[MAXN][MAXN] = {{0}};
	queue<ii> q;

	q.push({r, c});
	while(not q.empty()){
		ii curr = q.front();
		if (dest)
			s.push_back(curr);
		else  
			d.push_back(curr);
		int x = curr.first;
		int y = curr.second;
		q.pop();

		for(auto [i, j] : {make_pair(x+1, y),
											make_pair(x-1, y),
											make_pair(x, y+1),
											make_pair(x, y-1)
											}){
			if (i < 1 or j < 1 or i > n or j > n) {continue;}
			if (board[i][j]) { continue; }
			if (vis[i][j]) { continue; }


			q.push({i, j});
			vis[i][j] = 1;
		}
	}
}

int dist (ii src, ii dst){
		return pow(src.first - dst.first, 2) + pow(src.second - dst.second, 2);
}

int main(){
	cin >> n >> x_0 >> y_0 >> x_1 >> y_1;

	for(int i = 1;i <= n;i++){
		string st;
		cin >> st;
		for (int j = 0;j < st.size();j++){
			board[i][j+1] = st[j] == '1';
		}
	}

	bfs(x_0, y_0, 1);
	bfs(x_1, y_1, 0);


	int ans = 1e9;
	for(auto [s_r, s_c] : s){
		for(auto [d_r, d_c] : d){
			if ( s_r == d_r and s_c == d_c){
				cout << 0 << "\n";
				return 0;
			}
			ans = min(dist({s_r, s_c}, {d_r, d_c}), ans);
		}
	}

	cout << ans << "\n";
	return 0;
}
