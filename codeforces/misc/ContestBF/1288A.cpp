#include "bits/stdc++.h"

using namespace std;


int main() {
	int t;
	vector<bool> ans;
	cin >> t;
	for (int x = 0;x < t;x++){
		int n, d;
		cin >> n >> d;

		bool fit = 0;
		for (int i = 0;i <= n;i++){
			double db= static_cast<double>(d) / static_cast<double>(i+1);
			int n_d = ceil(db) + i;		
			//cout << n_d << " " << i << " " <<  db << endl;
			if (n_d <= n){
				fit = 1;
				break;
			}

		}
		ans.push_back(fit);
	}

	for(auto r : ans){
		if(r)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}
