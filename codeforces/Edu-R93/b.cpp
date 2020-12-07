#include "bits/stdc++.h"


using namespace std;


int move(string& s){
	int n = s.size();	
	
	if (n == 1){
		s.erase();
		return 1;
	}

	int b_i, b_j;
	b_i = b_j = 0;



	int i, j;
	i = j = 0;

	for(int i = 0;i < n;i++){
		if (s[i] == '1'){
			int j = i;
			for(;j < n;j++){
				if (s[j] == '0'){
					--j;
					break;
				}
			}
			if (j == n)
				j--;
			if (j - i > b_j - b_i or (j-i == b_j - b_i and j > b_j and i > b_i)){
				b_j = j;
				b_i = i;
			}
		}
	}

	int ones = b_j - b_i + 1;
	s.erase(b_i, ones);
	return ones;
}

bool valid(string& s){
	
	for(auto& c : s){
		if (c == '1')
			return true;
	}
	return false;
}

int main(){
	vector<int> ans;
	int t;
	cin >> t;
	for (int x = 0;x < t;x++){
		string s;
		cin >> s;
		
		int move_num = 0;
		int score_alice = 0;
		int score_bob = 0;

		while(valid(s)){
			int score = move(s);			
			if (move_num & 1)
				score_bob += score;
			else
				score_alice += score;
			move_num++;
		}
		ans.push_back(score_alice);
	}

	for (auto& sc : ans){
		cout << sc << endl;
	}
	return 0;
} 

