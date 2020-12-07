#include "bits/stdc++.h"

using namespace std;


const int MAX_N = 100 + 5;
const int MAX_W = 1e9 + 5;
const int MAX_V = 1e5 + 5 ;

bool v[MAX_N][MAX_V];
int dp[MAX_N][MAX_V];
int N, W;
vector<pair<int, int>> ks;

int solve(int n, int va){
	if (va <= 0)
		return 0;

	if (n == N)
		return MAX_W;

	if (v[n][va]) return dp[n][va];
	
	dp[n][va] = min(solve(n+1, va - ks[n].second) + ks[n].first, solve(n+1, va));

	v[n][va] = 1;
	return dp[n][va];

	/*if (ks[n].first + w > W) { 
		 short& score = dp[n][w] = solve(n+1, w);
		 v[n][w] = 1;
		 return score;
	}
	else {
		short& score = dp[n][w] =  max(static_cast<short>(solve(n+1, w + ks[n].first) + ks[n].second), solve(n+1, w));
		v[n][w] = 1;
		return score;
	}*/
	
}

int max_weight(){

	for (int i = MAX_V;i >= 0;i--){
		if( solve(0, i) <= W)
			return i;
	}
	return 0;
}

int main(){
	cin >> N >> W;

	for(int i = 0;i < N;i++){
		int x;
		int y;
		cin >> x;
		cin >> y;
		ks.push_back({x, y});
	}

	cout << max_weight() << endl;
	return 0;
}
