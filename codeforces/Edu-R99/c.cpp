#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using vi = vector<int>;
using vii = vector<iii>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	/*adj[0].push_back({1, make_pair(0, -1)});
	adj[0].push_back({0, make_pair(-1, 0)});

	adj[1].push_back({2, make_pair(0, 0)});
	adj[1].push_back({3, make_pair(-1, 0)});

	adj[2].push_back({2, make_pair(0, -1)});
	adj[2].push_back({2, make_pair(0, -1)});

	adj[3].push_back({1, make_pair(0, -1)});
	adj[3].push_back({0, make_pair(0, 0)});*/

	while(t--){
		int x,y;
		cin >> x >> y;
		
		cout << x-1 << " " << y << "\n";

	}
	return 0;
}
