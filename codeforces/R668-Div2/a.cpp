#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 100 +5;

int n;
int a[MAXN];
int c [MAXN];
int d [MAXN];
int b[MAXN];

bool check(){
	bool dif = false;

	for(int i = 0;i < n;i++){
		if (a[i] != b[i]){
			dif = true;
			break;
		}
	}

	if (not dif)
		return dif;

	for(int i = 1;i < n;i++){
		c[i-1] = (b[i] + b[i-1]);
	}

	sort(c, c + n-1);

	for(int i = 0;i < n;i++){
		if (c[i] != d[i])
			return false;
	}
	return true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;
			a[i] = tmp;
			b[i] = tmp;
		}
		
		sort(b, b +n);
		
		for(int i = 1;i < n;i++){
			d[i-1] = a[i] + a[i-1];
		}
		sort(d, d+n-1);

	/*	do {
			bool found = check();
			if (found){
				break;
			}

		}while(next_permutation(b, b+n)); */
		
		reverse(a, a+n);
		for(int i = 0;i < n;i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}


	return 0;
}
