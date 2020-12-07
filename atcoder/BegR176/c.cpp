#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAX_N = 1e6;
ll a[MAX_N];
int n;


int main(){
	cin >> n;

	ll count = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if (i > 0){
			if (a[i-1] > a[i]){
				count += a[i-1] - a[i];
				a[i] = a[i-1];
			}
		}
	}
	cout << count;

	return 0;
}
