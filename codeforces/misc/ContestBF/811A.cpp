#include "bits/stdc++.h"

using namespace std;

int main() {
	int a,b, c;
	c = 1;
	cin >> a >> b;

	while(1)	{
		a -= c++;
		if (a < 0)
			break;
		b -= c++;
		if (b < 0)
			break;
	}
	
	if (b < 0)
		cout << "Valera";
	else
		cout << "Vladik";
	
	return 0;
}
