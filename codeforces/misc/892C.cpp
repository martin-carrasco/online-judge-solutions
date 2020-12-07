#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 2000 + 5;
int a[MAX_N];

int gcd(int a, int b) {

	while(b != 0){
		int t = b;
		b = b % a;
		a = t;
	}
	return a;
}

int main() {
	int n;
	cin >> n;

	for(int i= 0;i < n;i++)
		cin >> a[i];

	sort(a, a + n);

	for(int i = 0;i < n;i++){
		if(
	}

	return 0;
}
