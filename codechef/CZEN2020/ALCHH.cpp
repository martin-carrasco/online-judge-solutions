#include "bits/stdc++.h"

using namespace std;


char vowels[] = {'A', 'E', 'I', 'O', 'U'};

bool is_vowel(const char& c){
	for(auto vow : vowels){
			if (vow == c)
				return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int cnt_bowel = 0;
	int cnt_conso = 0;
	int running_bowel = 0;

	for(int i = 0;i < s.size();i++){
		char c = s[i];

		if (is_vowel(c)) {
			running_bowel++;
		}
		else{
			cnt_conso++;
			running_bowel = 0;
		}
		cnt_bowel = max(running_bowel, cnt_bowel);
	}

	if (cnt_bowel >= 3 and cnt_conso > 5)
		cout << "GOOD";
	else
		cout << -1;
	cout << "\n";
}
