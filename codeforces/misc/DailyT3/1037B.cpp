#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAX_N = 1e6;


int main(){
	int n;
	long long s;
	cin >> n >> s;
	vi a(n);

	for(int i= 0;i < n;i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int des_pos = (n-1) / 2;
	int current_median = a[des_pos];

	long long count = 0;
	int i = des_pos;
	if (current_median <= s){
		while(1){
			int dif = s - a[i];
			if (dif <= 0)
				break;
			count += (long long)dif;
			i++;
			if (i == n)
				break;
		}
	} else {
		while(1){
			int dif = a[i] - s;
			if (dif <= 0)
				break;
			count += (long long)dif;
			i--;
			if (i == -1)
				break;
		}

	}

	cout << count;
	return 0;
}
