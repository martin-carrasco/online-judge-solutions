#include "bits/stdc++.h"

using namespace std;
using pr = pair<int,int>;

const int MAX_N = 100 + 5;
int n, m, s_x, s_y;
int c_v = 1;
bool v[MAX_N][MAX_N];

bool is_valid(pr& pos){
	if (pos.first < 0 or pos.first >= n)
		return false;
	if (pos.second < 0 or pos.second >= m)
		return false;
	if (v[pos.first][pos.second])
		return false;
	return true;
}

void move_to(pr& pos){
	s_x = pos.first;
	s_y = pos.second;
	cout << s_x +1 << " " << s_y +1 << endl;
	v[s_x][s_y] = 1;
	c_v++;
}

int main () {

	cin >> n >> m >> s_x >> s_y;
	
	cout << s_x << " " << s_y << endl;
	s_x--;
	s_y--;
	v[s_x][s_y] = 1;
	while(c_v < n*m){
		for (int ne = 1; ne < max(n, m);ne++){
			pr c1 = {	s_x + ne, s_y};
			pr c2 =	{ s_x - ne, s_y};
			pr c3 = {s_x, s_y + ne};
			pr c4 = {s_x, s_y - ne};

			if (is_valid(c1)){
				move_to(c1);
				break;
			}
			else if (is_valid(c2)){
				move_to(c2);
				break;
			}
			else if (is_valid(c3)){
				move_to(c3);
				break;
			}
			else if (is_valid(c4)){
				move_to(c4);
				break;
			}
		}
	}

	return 0;
}

