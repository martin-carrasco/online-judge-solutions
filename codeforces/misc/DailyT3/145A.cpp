#include "bits/stdc++.h"

using namespace std;

int main(){
	string a,b;
	cin >> a >> b;

	int dif_4, dif_7;
	dif_4 = dif_7 = 0;
	for(int i = 0;i < a.size();i++){
		if(a[i] != b[i]) {
			if (a[i] == '4')
				dif_4++;
			else
				dif_7++;
		}
	}

	cout << min(dif_4, dif_7) + abs(dif_4 - dif_7) << endl;

	return 0;
}
