#include "bits/stdc++.h"
#define M_PI       3.14159265358979323846
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;

		double up_s = cos(M_PI / (n*2));
		double down_s = 2 * sin(M_PI / (n*2));
		double ans =  2 * (up_s / down_s);

		cout << fixed << setprecision(9) << ans << "\n";
	}

	return 0;
}
