#include "bits/stdc++.h"

using namespace std;


int main(){
	int t = 5;

	cout << t << endl;
	int n = 1e4;
	for(int i = 0;i < t;i++){	
		cout << n << endl;
		for(int j = 0;j < n;j++){
			cout << rand() % n << " ";	
		}
		cout << "\n";
	}
	return 0;
}
