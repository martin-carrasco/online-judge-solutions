#include "bits/stdc++.h"


using namespace std;


const int MAX_N = 1e6 + 5;
int a[MAX_N];
int main(){
	vector<string> ans;
	int t;
	cin >> t;
	for (int x = 0;x < t;x++){
		int n;
		cin >> n;
		for(int i = 0;i < n;i++)
			cin >> a[i];


		bool found = false;


		if (a[n-1] >= a[0] + a[1]){
			ans.push_back(to_string(1) + " " + to_string(2) + " " + to_string(n));
		}
		else{
			ans.push_back("-1");
		}

/*
		bool found = false;
		for (int k = 2;k < n;k++){
			if (found) break;
			for (int j = 1;j < k;j++){
				if (found) break;
				for (int i = 0;i < j;i++){
					if (a[k] > a[i] + a[j]){
						ans.push_back(to_string(i+1) + " " + to_string(j+1) + " " + to_string(k+1));
						found = true;
						break;
					}
				}
			}
		}*/

	}

	for (auto& s : ans){
		cout << s << endl;
	}
	return 0;
} 

