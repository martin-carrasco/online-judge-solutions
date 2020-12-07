#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 200 + 5;
int n, m;
int a[MAX_N], b[MAX_N];


int main () {

	cin >> n >> m;

	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 0;i < m;i++)
		cin >> b[i];

	int mat[n][m] = {{0}};
	for (int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			int an = a[i];
			int bn = b[j];
			int c = an & bn;
			mat[i][j] = c;
			}
		}
	}

	int tot = 0;
	for(auto& a : resps){
		//cout << a << endl;
		tot |= a;
	}
	cout << tot;

	return 0;
}

