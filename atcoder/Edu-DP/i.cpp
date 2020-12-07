#include "bits/stdc++.h"

using namespace std;
using ld = long double;

const int MAX_N = 3000 + 5;
long double p = 0;
int N;
long double ps [MAX_N];
ld dp[MAX_N];


int main(){
	cin >> N;
	for (int i = 0; i < N;i++){
		cin >> ps[i];
	}

	dp[0] = 1;
	ld sum = 0;
	for (int i = 0;i < N;i++){
		ld prob = ps[i];
		for (int j = 0;j <= i+1;j++){
			ld& t = dp[j+1] = dp[j] * prob + dp[j] * (1 - prob);
		}
	}



		
	cout << sum << endl;
	cout << dp[N-1];
	return 0;
}
