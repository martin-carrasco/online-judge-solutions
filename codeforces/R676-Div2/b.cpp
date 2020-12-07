#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 200 + 5;
bool g[MAXN][MAXN];
vector<ii> positions;
vector<ii> ans;
int n;


bool reach(bool tp){
	stack<ii> q;
	q.push({1, 1});
	int vis[n+1][n+1] = {{0}};
	vis[1][1] = 1;
	while(not q.empty()){
		ii pos = q.top();
		int x = pos.first;
		int y = pos.second;
		q.pop();

		for(auto [r, c] : {make_pair(x+1, y), make_pair(x-1, y), make_pair(x, y+1), make_pair(x,y-1)}){
			if(r < 1 or r > n or c < 1 or c > n) continue;
			if (vis[r][c]) continue;
			if (r == n and c == n) return true;
			if (g[r][c] != tp) continue;
			vis[r][c] = 1;
			q.push({r, c});
		}
	}
	return false;
}

bool solve(int i, int flipped){
	if (i > 3){  
		bool reach_0 = reach(0);
		bool reach_1 = reach(1);
		return not reach_1 and not reach_0;
	}

	if (flipped < 2){
		ii c_pos = positions[i];
		g[c_pos.first][c_pos.second] = not g[c_pos.first][c_pos.second];
		ans.push_back(c_pos);
		bool can_solve = solve(i+1, flipped +1);

		if (can_solve)
			return true;

		g[c_pos.first][c_pos.second] = not g[c_pos.first][c_pos.second];
		ans.pop_back();

	}
	bool can_solve = solve(i+1, flipped);
	if (can_solve)
		return true;

	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				char c;
				cin >> c;
				if (c == 'S' or c == 'F') continue;
				g[i][j] = c - '0';
			}
		}

		bool reach_0 = reach(0);
		bool reach_1 = reach(1);
		
		if (not reach_0 and not reach_1) {
			cout << 0 << "\n";
			continue;
		}

    positions = {make_pair(2,1), make_pair(1,2), make_pair(n, n-1), make_pair(n-1, n)};
		bool works = solve(0, 0);
		
		cout << ans.size() << "\n";
		for(auto ele : ans){
			cout << ele.first << " " << ele.second << "\n";
		}
		positions.clear();
		ans.clear();
	}

	return 0;
}
