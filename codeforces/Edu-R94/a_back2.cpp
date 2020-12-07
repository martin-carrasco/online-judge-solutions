#include "bits/stdc++.h"

using namespace std;

void gen(int n, int arr[], int i, vector<string>& vec) { 
	if (i == n) { 
		string new_str = "";
		for(int x_i = 0;x_i < n;x_i++){
			if(arr[x_i] == 1)
				new_str.append("1");
			else
				new_str.append("0");
		}
		vec.push_back(new_str);
		return; 
	} 

	arr[i] = 0; 
	gen(n, arr, i + 1, vec); 

	arr[i] = 1; 
	gen(n, arr, i + 1, vec); 
} 
bool sim(string &s, string& n_s, int n){
	int i = 0;
	int j = n-1;
	int counter = 0;
	bool all_sim = false;
	while(1){
		bool o_sim = false;
		for (int x = i;i <= j;i++){
			if (s[x] == n_s[x-counter]){
				o_sim = true;
				break;
			}
		}
		if (not o_sim)
			return false;
		all_sim = true;
		i++;
		j++;
		counter++;
		if (j == s.size())
			break;
	}
	return all_sim;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n;
		cin >> s;
		int arr[n] = {0};

		vector<string> perms;
		cout << perms.size() << endl;
		gen(n, arr, 0, perms);

		for(string try_s : perms){
			cout << try_s << endl;
			if (sim(s, try_s, n)){
				cout << try_s << "\n";
				break;
			}
		}
		
	}
	return 0;
}
