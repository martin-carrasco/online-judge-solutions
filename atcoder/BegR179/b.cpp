#include "bits/stdc++.h"

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	bool h = false;
	for(int i = 0;i < n;i++){
		int d_1, d_2;
		cin >> d_1 >> d_2;
		if (d_1 == d_2)
			cnt++;
		else
			cnt = 0;

		if (cnt == 3)
			h = true;
	}

	if (h)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";

	return 0;
}
