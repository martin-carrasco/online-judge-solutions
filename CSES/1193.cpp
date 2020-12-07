#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 1000 + 5;
bool g[MAXN][MAXN];
pair<ii, char> parent[MAXN][MAXN];
bool vis[MAXN][MAXN];

int n, m, x_0, y_0, x_1, y_1, ans_size;

ii dfs(){
	ii pos = {x_0, y_0};	
	queue<pair<ii, int>> q;
	vis[x_0][y_0] = 1;
	parent[x_0][y_0] ={ make_pair(x_0, y_0), '\n'};
	q.push({pos, 0});

	while(not q.empty()){
		ii c_pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for(auto [x, y] : {make_pair(c_pos.first+1, c_pos.second),
											 make_pair(c_pos.first-1, c_pos.second),
											 make_pair(c_pos.first, c_pos.second+1),
											 make_pair(c_pos.first, c_pos.second-1)})
		{
			if (g[x][y] or vis[x][y] or x < 0 or x >= n or y < 0 or y >= m) continue;		
			char dir;
			if (x == c_pos.first){
				if (y > c_pos.second)
					dir = 'R';
				else
					dir = 'L';
					
			} else {
				if(x > c_pos.first)
					dir = 'D';
				else
					dir = 'U';
			}

			parent[x][y] = {make_pair(c_pos.first,c_pos.second), dir};
			if (x == x_1 and y == y_1) {
				ans_size = cnt+1;
				return {x, y};
			}

			q.push({make_pair(x, y), cnt+1});
			vis[x][y] = 1;
		}
	}
	return {-1, -1};
}
void backtrack(ii pos){
	if (parent[pos.first][pos.second].first == pos) {
		return;
	}
	backtrack(parent[pos.first][pos.second].first);	
	cout << parent[pos.first][pos.second].second;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;
			cin >> c;
			if (c == 'A'){
				x_0 = i;
				y_0 = j;
				continue;
			}
			if (c == 'B'){
				x_1 = i;
				y_1 = j;
				continue;
			}
			g[i][j] = (c == '#');
		}
	}


	ii ans = dfs();

	if (ans.first == -1){
		cout << "NO" << "\n";
	} else{
		cout << "YES\n" << ans_size << "\n";
		backtrack(ans);
		cout << "\n";
	}
	return 0 ;
}
