#include "bits/stdc++.h"

using namespace std;



int main() {
	int n, m, num;
	num = 0;
	cin >> n >> m;


	for (int i = 0;i <= n;i++){
		for (int j = 0;j <= m;j++){
				int r1 = i*i + j;
				if (r1 != n)
					continue;
				int r2 = i + j*j;
				if (r2 == m)
					num++;
		}
	}
	cout << num;
	return 0;
}
