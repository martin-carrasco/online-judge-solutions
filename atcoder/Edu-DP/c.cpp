#include "bits/stdc++.h"

using namespace std;


bool ** v;
int ** dp;
int *a, *b, *c;
int solve(int n, const int& max, char last){
	if (n == max)
		return 0;

	if (v[n][last]) return dp[n][last];
	
	int score_a = last == 'a' ? 0 : solve(n+1, max, 'a') + a[n];
	int score_b = last == 'b' ? 0 : solve(n+1, max, 'b') + b[n];
	int score_c = last == 'c' ? 0 : solve(n+1, max, 'c') + c[n];

	dp[n][last] = std::max({score_a, score_b, score_c});
	v[n][last] = 1;

	return dp[n][last];


	
}

int main(){
	int N;
	cin >> N;
	v = new bool*[N];
	a = new int[N];
	b = new int[N];
	c = new int[N];
	dp = new int*[N];


	for(int i = 0;i < N;i++){
		v[i] = new bool[3];
		dp[i] = new int[3];
		cin  >> a[i];
		cin >> b[i];
		cin >> c[i];
	}


	//fill(&dp[0][0], &dp[0][0] + sizeof(dp), 0);
	//fill(&v[0][0], &v[0][0] + sizeof(v), 0);

	cout << solve(0, N, 0) << endl;
	return 0;
}
