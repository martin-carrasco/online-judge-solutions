#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

char c[3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c[0] >> c[1] >> c[2];


	if (c[0] == c[1] and c[1] == c[2]) cout << "Won\n";
	else cout << "Lost\n";
	return 0;
}
