#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;


const int MAXN = 1000+5;
const int MAXV = 1000*1000 + 5;

char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
char par[MAXN][MAXN];
ii dir[MAXN][MAXN];
vii exits, monsters;
int n,m;



bool is_boundry(int i, int j){
	if (g[i][j] != '.') return false;
	if (i == 0 or i == n-1) return true;
	if (j == 0 or j == m-1) return true;
	return false;
}

ii bfs(int i, int j){
	queue<ii> q;
	q.push({i,j});
	par[i][j] = 0;
	vis[i][j] = 1;
	dir[i][j] = {i, j};

	while(not q.empty()){
		ii pos = q.front();
		int x = pos.first;
		int y = pos.second;
		q.pop();


		for(int dx : {1, -1}){
			int x_n = x+dx;
			if (x_n < 0 or x_n >= n) continue;
			if(vis[x_n][y]) continue;
			if (g[x_n][y] == 'M' or g[x_n][y] =='#') continue;
			
			par[x_n][y] = dx==1?'D':'U';
			vis[x_n][y] = 1;
			dir[x_n][y] = {x, y};
			q.push({x_n, y});

			auto it = find(exits.begin(), exits.end(), make_pair(x_n, y));
			if (it != exits.end())
				return {x_n, y};
		}

		for(int dy : {1, -1}){
			int y_n = y+dy;
			if (y_n < 0 or y_n >= m) continue;
			if(vis[x][y_n]) continue;
			if (g[x][y_n] == 'M' or g[x][y_n] == '#') continue;
			
			par[x][y_n] = dy==1?'R':'L';
			dir[x][y_n] = {x, y};
			vis[x][y_n] = 1;
			q.push({x, y_n});

			auto it = find(exits.begin(), exits.end(), make_pair(x, y_n));
			if (it != exits.end())
				return {x, y_n};
		}
	}
	return {-1, -1};
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);

	cin >> n >> m;

	int x_0, y_0;

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> g[i][j] ;
			if (g[i][j] == 'M') monsters.push_back({i, j});
			if (g[i][j] == 'A'){
				x_0 = i;y_0 = j;
			}

			if (is_boundry(i, j))	exits.push_back({i,j});
		}
	}

	if (n == 1 or m == 1) {
		cout << "YES\n" << 0 << "\n";
		return 0;
	}
	ii ans = bfs(x_0, y_0);
	if (ans.first == -1) {
		cout << "NO\n";
		return 0;
	}

	ii curr_pos = ans;		

	cout << "YES\n";
	string path = "";
	cout << "i: " << curr_pos.first << ", j: " << curr_pos.second << "\n";
	while(curr_pos.first != x_0 or curr_pos.second != y_0){
		path.push_back((par[curr_pos.first][curr_pos.second]));
		curr_pos = dir[curr_pos.first][curr_pos.second];
		cout << "i: " << curr_pos.first << "j: " << curr_pos.second << "\n";
	}
	//path.push_back((par[curr_pos.first][curr_pos.second]));
	cout << path.size() << "\n";
	cout << path << "\n";
	return 0;
}
