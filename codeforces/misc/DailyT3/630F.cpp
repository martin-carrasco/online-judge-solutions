#include "bits/stdc++.h"

using namespace std;
using ll = long long;

ll nChoosek( unsigned n, unsigned k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= 1LL * (n-i+1);
        result /= i;
    }
    return result;
}

int main(){
	int n;
	cin >> n;
	ll total = 0;
	for(int i = 5;i <=7;i++){
		total += nChoosek(n,i) * 1LL;
	}

	cout << total << "\n";
	return 0;
}

