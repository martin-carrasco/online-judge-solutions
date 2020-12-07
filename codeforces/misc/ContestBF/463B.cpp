#include "bits/stdc++.h"

using namespace std;


const int MAX_NUM = 1e5 +5;
int h[MAX_NUM];
int n;



int solve(int pos, int sm, int e){
	
	if (sm > 100)
		return 1e9;

	int money = 0;
	int c = h[pos] + sm;
	while(c + e - h[pos+1] < 0){
		money++;
		c++;
	}
	
	if (pos == n-1)
		return  money;

	int en = e + c - h[pos+1];

	int mn = min(solve(pos, sm + 1, en) + money+ 1, solve(pos+1, sm, en) + money);

	return mn;
}

int main() {

	cin >> n;	
	h[0] = 0;
	for (int i = 1;i < n+1;i++){
		cin >> h[i];
	}

	int e = 0;
	int money = 0;
	for(int i = 0;i < n;i++){
		if(h[i] - h[i+1] < 0){
			if (h[i] + e  - h[i+1] < 0){
				money	-= h[i] + e  - h[i+1];
				e = 0;
			} else{
				e += h[i] - h[i+1];
			}
		} else {
			e+=	h[i] - h[i+1];
		}
	}
	cout << money;
	//cout << solve(0, 0, 0);
	return 0;
}
