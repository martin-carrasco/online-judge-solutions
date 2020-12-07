#include "bits/stdc++.h"

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	if (s[s.size() - 1] == 's')
		s.append("es");
	else
		s.append("s");
	cout << s<< "\n";

	return 0;
}
