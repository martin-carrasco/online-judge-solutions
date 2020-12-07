#include "bits/stdc++.h"

using namespace std;


int m;
int main(){
	int n;
	cin >> n >> m;

	int r_p, b_p;	
	r_p = b_p = 0;
	while(n != m){
		if (m > n and m%2 == 0){
			m /= 2;
			r_p++;
		} else {
			m++;
			b_p++;
		}
	}
	cout << r_p + b_p << "\n";
	return 0;
}
