#include "bits/stdc++.h"

using namespace std;

int * h;
int * dp;
bool * v;
int solve(int n, const int& max, const int& k){
	if (n == max -1)
		return 0;
	
	if (n == max){
		return	1e9;
	}
	
	if (v[n]) return dp[n];

	int * jp = new int[k];
	int mn = 1e9;
	for(int i = 1;i <=k;++i){
		if (n + i > max)
			break;
		jp[i-1] = solve(n+i, max, k) + abs(h[n] - h[n+i]);
		if (jp[i-1] < mn)
			mn = jp[i-1];
	}

	int cost = dp[n] = mn;
	v[n] = 1;

	return cost;
}

int main (){
	int N, k;
	cin >> N;
	cin >> k;

	h = new int[N];	
	dp = new int[N];
	v = new bool[N];

	fill(dp, dp + N, 0);
	fill(v, v + N, 0);

	for(int i= 0; i < N;i++){
		cin >> h[i];
	}


	cout << solve(0, N, k) << endl;
	return 0;
}
