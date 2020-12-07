#include "bits/stdc++.h"

using namespace std;


using ll = long long;

const ll MAX_NUM = 1e18;
bool coprime(ll a, ll b){
	while(b != 0){
		ll t = b;
		b = a % b;
		a = t;
	}
	return a == 1;
}

void solve(ll& l, ll& r){

	for(ll i = l;i < r;i++){
		ll top_j = i+50 > r ? r : i+50;
		for(ll j = i + 1; j <= top_j;j++){
			if (coprime(i, j)){
				for(ll k = j + 1;k <= top_j;k++){
					if (coprime(j, k) and not coprime(i, k)){
						cout << i << " " << j << " " << k;
						return; 
						
					}
				}
			}
		}
	}
	cout << -1;
}


int main() {
	ll l,r;				
	cin >> l >> r;

	solve(l, r);
	return 0;
}
