#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const int MAX_N = 100;
const int MAX_W = 1e5;

bool v[MAX_N][MAX_W];
ll dp[MAX_N][MAX_W];

int N, W;
vector<pair<int, ll>> ks;

ll solve(int n, int w){
	if (n == N)
		return (ll) 0;

	if (v[n][w]) return dp[n][w];

	if (ks[n].first + w > W) { 
		 ll& score = dp[n][w] = solve(n+1, w);
		 v[n][w] = 1;
		 return score;
	}
	else {
		ll& score = dp[n][w] =  max(solve(n+1, w + ks[n].first) + ks[n].second, solve(n+1, w));
		v[n][w] = 1;
		return score;
	}
	
}

int main(){
	cin >> N >> W;

	for(int i = 0;i < N;i++){
		int x;
		ll y;
		cin >> x;
		cin >> y;
		ks.push_back(make_pair(x, y));
	}

	ll sol = solve(0, 0);
	cout << sol << endl;
	return 0;
}
