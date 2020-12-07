#include "bits/stdc++.h"

using namespace std;

int main(){
	int n;
	cin >> n;
	if (n == 2 or n == 3) {
		cout << "NO SOLUTION" << "\n";
		return 0;
	}

	for(int i = 1;i <= n;i++){
		if (i % 2 == 0)
			cout << i << " ";
	}
	for(int i = 1;i <= n;i++){
		if (i % 2 == 1)
			cout << i << " ";
	}
	cout << "\n";

	return 0;
}
