#include "bits/stdc++.h"

using namespace std;


char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool is_num(char& c){
	for(auto num : nums){
		if (c == num)
			return true;
	}
	return false;
}

bool is_palindrome(string& s){
	for(int i = 0;i < s.size();i++){
		if (s[i] != s[s.size()-i-1])
			return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	string full = "";
	cin >> s;

	for(int i = 0;i < s.size();i++){
		char c = s[i];
		
		if (c == '+'){
			char c_i = s[i];
			int times = 1;
			string tmp = "";

			string num = "";
			bool t_change = false;
			for(int j = i-1;j >= 0;j--){
				if (is_num(s[j])) {
					t_change = true;
					num.insert(0, &s[j], 1);
					full.pop_back();
					continue;
				}
				break;
			}

			if (t_change)
				times = stoi(num);
			i++;

			bool found_neg = false;
			while(i < s.size()){
				c_i = s[i];
				if (c_i != '-')	
					tmp.push_back(c_i);
				else {
					found_neg = true;
					break;
				}
				i++;
			}
			if (not found_neg)
				continue;
			while(times--){
				full.append(tmp);
			}
		} else {
			full.push_back(c);
		}
	}

	if (is_palindrome(full))
			cout << "Return";
	else 
			cout << "Continue";
	cout << "\n";

}
