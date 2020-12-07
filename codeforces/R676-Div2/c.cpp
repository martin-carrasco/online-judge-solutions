#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
vector<pair<char, int>> ans;

bool is_palindrome(const string& s){
	int i = 0;
	int j = s.size() - 1;
	while(i != j){
		if (s[i] != s[j])
			return false;
		i++;
		j++;
	}
	return true;
}

bool solve(int i, string s){
	if (is_palindrome(s))
		return true;

	string pos_1 = s;
	string n_piece = pos_1.substr(2, s.size()-2);
	reverse(n_piece.begin(), n_piece.end());
	pos_1.insert(pos_1.size(), n_piece);
	ans.push_back({'L', s.size()-1});
	bool can_solve = solve(i+1, pos_1);
	if (can_solve)
		return true;

	ans.pop_back();
	string pos_2 = s;
	string n_piece_2 = pos_2.substr(2, s.size()-2);
	reverse(n_piece_2.begin(), n_piece_2.end());
	pos_2.insert(0, n_piece);

	ans.push_back({'R', 2});
	can_solve = (solve(i+1, pos_2));
	
	if (can_solve)
		return true;
	ans.pop_back();

	return false;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	solve(0, s);
	cout << ans.size();
	for (auto ele : ans){
		cout << ele.first << " " << ele.second << "\n";
	}

	return 0;
}
