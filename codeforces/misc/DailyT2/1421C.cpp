#include "bits/stdc++.h"

using namespace std;

bool is_palindrome(string s){
	int i = 0;
	int j = s.size() - 1;

	while(i < j){
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int len = s.size();

	if (is_palindrome(s)){
		cout << 0 << "\n";
		return 0;
	}

	cout <<  4 << "\n";
	cout << "R " << 2 << "\n";
	len += (len-2);
	cout << "R " << len-1 << "\n";
	len++;
	cout << "L " << len-1 << "\n";
	cout << "L " << 2 << "\n";

	return 0;
}
