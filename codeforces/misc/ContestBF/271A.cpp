#include "bits/stdc++.h"

using namespace std;
int y;

int main() {
  int k, c, d, u;
	cin >> y;

	k = y / 1000;
	c = ( y % 1000) / 100;
	d = ((y % 1000) % 100) / 10;
	u = ((y % 1000) % 100) % 10;
	
	
	while(1){
		u++;
		if (u == 10) {
			u = 0;
			d++;
		}
		if (d == 10) { 
			d = 0;
			c++;
		}
		if (c == 10) { 
			c = 0;
			k++;
		}
		if (k != c and k != u and k != d and c != d and c != u and d != u){
			if (k ==0 and c == 0 and d == 0)
				cout << (int)u << endl;
			else if (k ==0 and c == 0)
				cout << (int)d << (int)u;
			else if (k == 0)
				cout << (int)c << (int)d << (int)u;
			else
				cout << (int)k << (int)c << (int)d << (int)u;
			break;
		}
	}
	return 0;
}

