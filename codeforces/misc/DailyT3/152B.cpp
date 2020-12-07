#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<ii>;

int main(){
	int n, m, k, x0, y0;
	cin >> n >> m  >> x0 >> y0 >> k;

	vi vecs;
	for(int i = 0;i < k;i++){
		int dx, dy;
		cin >> dx >> dy;
		vecs.push_back({dx, dy});
	}

	int dist_x = n - x0;
	int dist_y = m - y0;
	
	ll sum = 0;
	for(const auto& [dx, dy] : vecs){
		int move_x = dx == 0 ? numeric_limits<int>::max() : (dx < 0 ? (n - dist_x - 1) / abs(dx) : dist_x / dx);
		int move_y = dy == 0 ? numeric_limits<int>::max() :  (dy < 0 ? (m - dist_y - 1) / abs(dy) : dist_y / dy);

		int move = min(move_x, move_y);
		dist_x -= move * dx;
		dist_y -= move * dy;
		sum += (ll) move;

	}

	cout << sum << "\n";
	return 0;
}
