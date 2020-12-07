#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;

	map<int, ii> mp =  
	{
		{0, {4, 2}},
		{1, {1, 1}},
		{2, {1, 2}},
		{3, {1, 3}},
		{4, {2, 1}},
		{5, {2, 2}},
		{6, {2, 3}},
		{7, {3, 1}},
		{8, {3, 2}},
		{9, {3, 3}}

	};

	vector<ii> vec_seq;


	ii last = {-1, -1};
	for(char ch : s){
		int c = (int)(ch - '0');
		if (last.first == -1 and last.second == -1)
			last = mp[c];
		else{
			ii current = mp[c];	
			ii new_p = {current.first - last.first, current.second - last.second};
			vec_seq.push_back(new_p);
			last = current;
		}
	}
	int first_digit = (int)(s[0] - '0');
	for(int d = 0;d <= 9;d++){
		ii current_pos = mp[d];
		if (d == first_digit)
			continue;
		bool another = true;
		for(const auto& [x, y] : vec_seq){
			int c_x = current_pos.first + x;
			int c_y = current_pos.second + y;
			if (c_x > 4 or c_y > 3 or c_x < 1 or c_y < 1) {
				another = false;
				break;
			}
			if (c_x == 4 and (c_y == 1 or c_y == 3)) {
				another = false;
				break;
			}
			current_pos = {c_x, c_y};
		}
		if (another) {
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";
	return 0;
}
