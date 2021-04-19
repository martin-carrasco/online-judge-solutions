#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2e5 + 5;
ll a,b,c;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;

	
	int unit_1 = a % 10;
	int unit_2 = b % 4;
	if (b == 1) {
		cout << unit_1 << "\n";	
		return 0;
	}
	
	if (c == 1){
		cout << binpow(a, b, 10LL) << "\n";
		return 0;
	}
	if (a == 1){
		cout << 1 << "\n";
		return 0;
	}

	if (unit_1 == 0 or unit_1 == 5 or unit_1 == 6 ){
		cout << unit_1 << "\n";
	}
	else if (unit_1 == 4 or unit_1 == 8){
		if (unit_2 == 0 or unit_2 == 2) {cout << 6 << "\n";}
		else { cout << unit_1 << "\n";}
	}
	else if (unit_1 == 2){
		if (unit_2 == 0 or unit_2 == 2){ cout << 6 << "\n";}
		else if (unit_2 == 1) {cout << 2 << "\n";}
		else { 
			if (c % 2 == 0){ cout << 2 << "\n";}
			else{ cout << 8 << "\n";}
		}
	}
	else {
		if (unit_2 == 0 or unit_2 == 2){ cout << 1 << "\n";}
		else if (unit_2 == 1){ cout << unit_1 << "\n";}
		else {
			if (c % 2 == 0) cout << unit_1 << "\n";
			else {
				int pr = ((unit_1 * unit_1) % 10) * unit_1;
				pr = pr % 10;
				cout << pr << "\n";
			}
		}
	}


	return 0;
}
