#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int A = 1234567;
const int B = 123456;
const int C = 1234;
int n;

int gcd(int a, int b){
	while (b != 0){
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int gcd(int a, int b, int c){
	return gcd(a, gcd(b, c));
}

bool solve(){
	for(ll a = 0;a*A <= n;a++){
		for (ll b = 0;b*B <= n - a*A;b++){
			int c = a * A + b * B - n;
			if (c % C == 0)	
				return 1;
		}
	}
	return 0;
}

int main() {
	cin >> n;

	bool res = solve();
	if (res)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
