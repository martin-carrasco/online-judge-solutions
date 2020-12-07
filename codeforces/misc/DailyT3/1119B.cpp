#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e3 + 5;
int a[MAXN];
int main(){
	int n, h;
	cin >> n >> h;
	for(int i = 0;i < n;i++)
		cin >> a[i];

	sort(a, a+n);

	int lhs = 0;
	int rhs = h; 

	while(lhs != rhs){
		int m = floor((lhs + rhs) / 2);

		int cnt_blw, cnt_above = 0;
		for(int i = 0;i < n;i++){
			if (a[i] <= m)
				cnt_blw++;
			if (cnt_blw == 2)
				break;
		}
		for(int i = 0;i < n;i++){
			if (a[i] <= (h - m)){

			}
		}
		

	}

	return 0;
}
