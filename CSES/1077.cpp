#include "bits/stdc++.h"

using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	multiset<int> wind;
	int n, k;
	cin >> n >> k;
	for(int i = 0;i < n;i++) cin >> a[i];

	for(int i = 0;i < k;i++)
		wind.insert(a[i]);
		
	int median = *(wind.begin() + ((k-1) / 2));
	int total = 0;

	for(int i = k;i < n;i++){

		total -= (abs(a[i-k] - median));
		wind.erase(wind.find(a[i-k]));

		int median = *(wind.begin() + ((k-1) / 2));	

	}

	return 0;
}
