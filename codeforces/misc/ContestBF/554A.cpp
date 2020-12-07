#include "bits/stdc++.h"

using namespace std;
const int MAX_CHAR = 26;

const int start_char = 97;

string s;
int solve() {
	vector<string> v;
	for(int i = 0;i < s.size() + 1;i++) {
		for (char c = start_char;c < start_char + MAX_CHAR;c++){
			string tmp = s;
			tmp.insert(tmp.begin() + i, c);
			v.push_back(tmp);
		}
	}
	set<string> st;
	unsigned size = v.size();
	for( unsigned i = 0; i < size; ++i ) st.insert( v[i] );
	v.assign( st.begin(), st.end() );

	/*for (auto& tr : st )
		cout << tr << endl;*/
	return st.size();
}
int main() {
	cin >> s;

	cout << solve() << endl; 
	return 0;
}
