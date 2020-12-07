#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using pi = pair<int, int>;

const int MAX_N = 2000 + 5;

bool g[MAX_N][MAX_N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
	int n, m, k;
	queue<pi> s_fires;
	cin >> n >> m >> k;
	for(int i = 0;i < k;i++){
		int x, y;
		cin >> x >> y;
		s_fires.push({x-1, y-1});	
		g[x-1][y-1] = 1;
	}
	while(not s_fires.empty()){
		pi curr = s_fires.front();
		s_fires.pop();
		//cout << "X: " << curr.first << ", Y: " << curr.second << endl; 

		for(auto& [row, col] : {make_pair(curr.first + 1, curr.second),
														make_pair(curr.first - 1, curr.second),
														make_pair(curr.first, curr.second +	1),
														make_pair(curr.first, curr.second - 1)}){
			if (row < 0 or row == n or col < 0 or col == m){
				//cout << "OUT " << "X: " << row << ", Y: " << col << endl; 
				continue;
			}
			if (g[row][col]) {
				//cout << "BURNED " << "X: " << row << ", Y: " << col << endl; 
				continue;
			}
			//cout << "NEW " << "X: " << row << ", Y: " << col << endl; 
			s_fires.push(make_pair(row, col));
			g[row][col] = 1;
		}
		if (s_fires.size() == 0)
			cout << curr.first + 1 << " " << curr.second + 1 << endl;
	}

	return 0;
}
