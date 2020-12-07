#include "bits/stdc++.h"


using namespace std;

const int MAXN = 1e5 + 5;
string s;
int dp[MAXN];
bool v[MAXN];

int solve(int pos){
	if (i > n)
		return 0;
	if(v[pos]) return dp[pos];

	f = s[i-1];
	s = s[i];

	if (f == s and (f == 'u' or f == 'n')) {
		int total = solve(pos + 1) + 1 + solve(pos + 2);

		dp[pos] = total;
	}
					
			
}

int main(){
	cin >> s;

	for(int i = 1;i < n;i++){
		char f, s;
		
	}
	return 0;
}
