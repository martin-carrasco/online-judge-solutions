#include "bits/stdc++.h"
 
using namespace std;
using ll = long long;
 

const int MAXN = 500 + 5;
ll dp[MAXN][MAXN*MAXN];
 
const ll MOD = 1e9 + 7;
int n, total;
 
ll add(ll a, ll b){
	if (a+b >= MOD)
		return a+b-MOD;
	return a+b;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	total = (n*(n+1)) / 2;

	if (total % 2){
		cout << 0 << "\n";
		return 0;
	}

	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= ((i*(i+1))/2);j++){
			dp[i][j] = add(dp[i-1][j-1], dp[i-1][j-i]);
		}
	}
 
	cout << ((dp[n][total/2]) * binpow(2, MOD-2)) % MOD << "\n";
	return 0;
}
