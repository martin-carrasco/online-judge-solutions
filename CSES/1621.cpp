#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e6;
int a[MAXN];
int main(){
	int n;
	cin >> n;

  set<int> seen;	
	for(int i = 0;i < n;i++){
		int t;
		cin >> t;
		if (not seen.count(t))
			seen.insert(t);
	}	

	cout << seen.size() << "\n";	
	return 0;
}
