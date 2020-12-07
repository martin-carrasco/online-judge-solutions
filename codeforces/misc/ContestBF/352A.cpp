#include "bits/stdc++.h"

using namespace std;

int n, n_5, n_0;

int main() {
				
	cin >> n;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		if (t == 5){
			n_5++;
		}
		else {
			n_0++;
		}
	}

	string max = "";
	string current = "";
	int sum = 0;
	while(n_5 > 0){
		current.append("5");
		sum += 5;
		if ( sum % 9 == 0){
			max = current;
		}
		n_5--;
	}
	if (not max.empty() and n_0 > 0){ 
		for(int i = 0;i < n_0;i++){
			max.append("0");
		}
		cout << max;
	} else if (max.empty() and n_0 > 0) {
		cout << 0;
	}
	else {
		cout << -1;
	}
	return 0;
	//string solution = solve(0, 0, "" );
	/*for(int i = 0;i < solution.size();i++){
		char ch = solution[i];
		if (ch != '0') {
			cout << solution;
			return 0;
		}
	}
	cout << 0;*/
	/*if (solution.size() == 0)
		cout << 0;
	else
		cout << solution;
	return 0;*/
}
