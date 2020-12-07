#include "bits/stdc++.h"

using namespace std;
const int MAX_N = 1e6;


int main(){
	string s;
	cin >> s;
	set<char> uc;

	int min_k = s.size();
	for(const char& c : s){
		uc.insert(c);
	}

	for(auto c : uc){
		int max_segment = 0;
		int current_segment = 0;
		for(int i = 0;i < s.size();i++){
			if (s[i] == c) {
				//cout << "c: "  << c << ", s[i]: " << s[i] << ", max: " <<  current_segment <<  "\n";
				if (current_segment > max_segment)
					max_segment = current_segment;
				current_segment = 0;
			}
			else
				current_segment++;
		}
		max_segment = max(max_segment, current_segment);
		max_segment++;

		if (max_segment < min_k)
			min_k = max_segment;
	}
	cout << min_k  << "\n";
	return 0;
}
