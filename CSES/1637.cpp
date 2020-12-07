#include "bits/stdc++.h"

using namespace std;

int biggest_num(int n){
	int max_num = n % 10;	

	while(n > 0){
		max_num = max(max_num, n % 10);
		n/= 10;
	}
	return max_num;
}
int solve(int n){
	if (n < 10 )
		return n > 0 ? 1 : 0;
	int max_num = biggest_num(n);	
	return solve(n-max_num) + 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	cout << solve(n) << "\n";
	return 0;
}
