#include "bits/stdc++.h" 
using namespace std;

const int MAX_N = 1e6;

int main(){
	string s;
	cin >> s;
	int tot, bad;
	tot = bad = 0;

	for(char& c : s){
		if (c == '(') 
			tot++;
		else if (c == ')')
			tot--;
		if (tot < 0) {
			bad++;
			tot = 0;
		}
	}

	bad += tot;


	cout << s.size() - bad  << endl; 
	return 0;
}
