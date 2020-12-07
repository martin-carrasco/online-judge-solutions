#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 100 + 5;
int a[MAX_N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int count = 0;
		for (int i = 0;i <n;i++)
			cin >> a[i];


		for(int i = 0;i < n-1;i++){
			for(int j = i+ 1;j < n;j++){
				int lhs = a[j];
				int rhs = a[i];
				int cmp = lhs & rhs;
				if (a[i] == (cmp))
					count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
