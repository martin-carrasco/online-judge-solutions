#include "bits/stdc++.h"

using namespace std;
const int MAXN = 1e6;

int a[MAXN];

int main(){
	int n;
	cin >>n;

	for(int i = 0;i < n-1;i++)
		cin >> a[i];

	sort(a, a+n-1);


	for(int i = 0;i <= n-1;i++){
		if (a[i] != (i+1)) {
			cout << i+1 << "\n";
			break;
		}

	}


	return 0;
}
