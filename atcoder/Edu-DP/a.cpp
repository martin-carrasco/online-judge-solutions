#include "bits/stdc++.h"

using namespace std;

int * h;
int * dp;
bool * v;
int solve(int n, const int& max){
	if (n == max -1)
		return 0;
	
	if (n == max){
		return	1e9;
	}
	
	if (v[n]) return dp[n];
	int cost = dp[n] = min(solve(n+1, max) + abs(h[n]  - h[n+1]), solve(n+2, max) + abs(h[n] - h[n+2]));
	v[n] = 1;

	return cost;
}

int main (){
	int N;
	cin >> N;

	h = new int[N];	
	dp = new int[N];
	v = new bool[N];

	fill(dp, dp + N, 0);
	fill(v, v + N, 0);

	for(int i= 0; i < N;i++){
		cin >> h[i];
	}


	cout << solve(0, N) << endl;
	return 0;
}
