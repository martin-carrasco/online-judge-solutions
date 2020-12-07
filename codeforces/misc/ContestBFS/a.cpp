#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

int h,w;
int m, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	n = 1;
	while(1){
		cin >> w >> h;
		if (w == 0 and h == 0)
			break;
		n++;
		cout <<  "Board #" << n <<  ":" << endl;
		bool b[h+2][w+2] = {{0}};
		cin.ignore();
		for(int i = 1;i <= h ;i++){
			string st;
			getline(cin, st);
			for (int j = 1;j <= w;j++){
				b[i][j] = (st[j-1] == 'X');
			}
		} 

		cout << endl;
		for(int i = 1;i <= h ;i++){
			for (int j = 1;j <= w;j++){
				cout << b[i][j] << " ";
			}
			cout<< endl;
		}
		m = 1;
		while(1){ 
			int x1, y1, x2, y2;
			cin >> y1 >> x1 >> y2 >> x2;
			if (x1 == 0 and y1 == 0 and x2 == 0 and y2 == 0)
				break;
			m++;	
			bool v[h+2][w+2] = {{ 0 }};
			map<ii, int> p;
			p[make_pair(x1, y1)] = 0;

			stack<ii> stk;
			stk.push(make_pair(x1, y1));
			while(not stk.empty()){
				ii curr = stk.top();
				stk.pop();
				//cout << "X: " << curr.first << ", Y: " << curr.second << endl;


				for(auto& [row, col] : { make_pair(curr.first, curr.second + 1), make_pair(curr.first, curr.second - 1),
						make_pair(curr.first + 1, curr.second), make_pair(curr.first - 1, curr.second)}){
					if (row < 0 or row > h + 1 or  col < 0 or col > w + 1){
						//cout << "HERE 1: " << "X: " << row << ", Y: " << col << endl;
						continue;
					}
					ii curr_pair = {row, col};
					if (row == x2 and col == y2) {
						if (p.count(curr_pair))
							p[curr_pair] = min(p[curr_pair], p[curr]);
						else
							p[curr_pair] = p[curr];
						break;
					}

					if (b[row][col] ){
						//cout << "HERE 2: " << "X: " << row << ", Y: " << col << endl;
						continue;
					}
					if (v[row][col]){
						//cout << "HERE 4: " << "X: " << row << ", Y: " << col << endl;
						continue;
					}
					//cout << "HERE 3: " << "X: " << row << ", Y: " << col << endl;
					v[row][col] = 1;
					p[make_pair(row, col)] = p[curr] + 1;	
					stk.push(make_pair(row, col));
				}
			}
			cout << "Pair "<< m << ": "
			if (p.count(make_pair(x2, y2)))
				 cout << p[make_pair(x2, y2)] << " segments." << endl;
			else
				 cout << "impossible." << endl;
		}
	}
	return 0;
}
