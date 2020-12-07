#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAX_N = 1e6;

int a[MAX_N];
ll p[MAX_N];

int main(){
	int n;
	cin >> n;

	for(int i = 1;i<=n;i++){
		cin >> a[i];
		p[i] = a[i] + p[i-1];
	}

	
	ll max_count = 0;
	int top_left = 1;
	int bot_right = n;
	while(top_left != bot_right){
		ll lhs = p[top_left];
		ll rhs = p[n] - p[bot_right-1];
		//cout << "top l: " << top_left <<  ", val: " << lhs << "\n" <<
		//"bot r: " << bot_right <<  ", val: " << rhs << "\n" << "\n";


		if (lhs == rhs) {
			max_count = lhs > max_count ? lhs : max_count;
			bot_right--; // TODO CHECK VALID
		}
		else if (lhs  < rhs){
			top_left++;
		}
		else {
			bot_right--;
		}
	}
	cout << max_count << "\n";
		
	return 0;
}
