#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1e4;
bool vis[MAXN][MAXN];

bool check_attack(ii p1, p2){
	//TODO
}

ll solve(int placed, int k){
	if (placed == 2)
		return 1LL;

	ll ways = 0;
	for(int j = 0;j <= k;j++){
		if (vis[k][j]) continue;	
		
		if (placed == 1 and check_attack()) {
			//Continue because there's a collition
		}
		vis[k][j] = 1;
		ways += solve(placed+1, k);
		vis[k][j] = 0;
	}

	for(int i = 0;i < k;i++){
			
	}

}

int main(){
	int n;
	cin >> n;

	for(int i = 1;i < n;i++){

	}

	return 0;
}
