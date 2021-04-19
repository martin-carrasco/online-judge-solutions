#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX_N = 1e3 + 100;
bool a[MAX_N][MAX_N];
int h, w, x0, y0, x1, y1;


int main(){
	cin >> h >> w;
	cin >> x0 >> y0 >> x1 >> y1;

	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			char c;
			cin >> c;
			a[i][j] = c == '#';	
		}
	}

	return 0;
}
