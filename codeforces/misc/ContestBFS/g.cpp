#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAX_N = 300 + 5;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> ans;
	int t;
	cin >> t;
	while(t--){
		int l, x0, y0, x1, y1;
		cin >> l >> x0 >> y0 >> x1 >> y1;
	
		if (x0 == x1 and y0 == y1){ 
			ans.push_back(0);
			break;
		}
			
		int v[l][l] = {{0}};
		map<pair<int,int>, int> prev;
		queue<ii> q;
		v[x0][y0] = 0;
		q.push({x0, y0});
		prev[make_pair(x0, y0)] = 0;

		while(not q.empty()){
			ii curr = q.front();
			q.pop();

			//cout << "X: " << curr.first << ", Y: " << curr.second << endl;
			for(auto& [row, col] : {make_pair(curr.first + 2, curr.second+1),
															make_pair(curr.first + 2, curr.second-1),
															make_pair(curr.first - 2, curr.second+1),
															make_pair(curr.first - 2, curr.second-1),
															make_pair(curr.first + 1, curr.second+2),
															make_pair(curr.first + 1, curr.second-2),
															make_pair(curr.first - 1, curr.second+2),
															make_pair(curr.first - 1, curr.second-2)}){
				if (row < 0 or row >= l or col < 0 or col >= l){
					//cout << "OUT: " << "X: " << row << ", Y: " << col << endl;
					continue;
				}
				if (prev.count(make_pair(row, col))){
					//cout << "PREV: " << "X: " << row << ", Y: " << col << endl;
					if (prev[make_pair(row, col)] > prev[make_pair(curr.first, curr.second)] + 1)
						prev[make_pair(row, col)] = prev[make_pair(curr.first, curr.second)] + 1;
					continue;
				}
				//cout << "NEW: " << "X: " << row << ", Y: " << col << endl;
				prev[make_pair(row, col)] = prev[make_pair(curr.first,curr.second)] + 1;
				v[row][col] = 1;
				q.push({row, col});
			}
		}
		ans.push_back(prev[make_pair(x1, y1)]);
	}

	for (auto& num : ans)
		cout  << num << endl;
	return 0;
}
