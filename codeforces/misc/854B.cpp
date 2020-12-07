#include "bits/stdc++.h"

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	int max_apt = min(n - k, k*2);

	int min_apt = k < n and k > 0 ? 1 : 0;

	cout << min_apt << " " << max_apt << "\n";
	return 0;
}
