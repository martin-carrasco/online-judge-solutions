#include "bits/stdc++.h"

using namespace std;
const int MAX_B = 1e7 + 5;
int n, k, a[MAX_B];




int main(){
	map<int, bool> vals;
	cin >> n >> k;

	for (int i = 0;i < n;i++)
		cin >> a[i];
	

	for (int i = 0;i < k;i++){
		if (i < n) { // We need to start combining soldiers
			vals[a[i]] = 1;
			cout << "1 " << a[i] << endl;
			continue;		
		}
		vector<int> vs;
		int current_val = a[start_pos];
		vs.push_back(current_val);
		while(vals.count(current_val)){
			int j = n - 1;
			for(;j >= 0;j--){
				current_val += a[j];
				vs.push_back(a[j]);
				if (not vals.count(current_val)){
					break;	
				}
			}
			if (j== 0) { // We have filled the sum of all n digits
				
			}
		}
		vals[current_val] = 1;

		cout << vs.size() << " ";
		for (auto& v : vs){
			cout  << v << " ";
		}
		cout << endl;
	}
	return 0;
}
