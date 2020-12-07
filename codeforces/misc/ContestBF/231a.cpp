#include "bits/stdc++.h"

using namespace std;

int main () {
	int n, P;
	P = 0;
	cin >> n;
	for (int x=0;x< n;x++){
		int a,b,c;
		cin >> a >> b >> c;
		if ( (a and b) or (b and c) or (a and c))
			P++;

	}
	cout << P;
	return 0;
}
