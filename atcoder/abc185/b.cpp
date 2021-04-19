#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,t;
	cin >> n >> m >> t;

	int capacity = n;
	int last_pos = 0;
	int battery = n;
	bool possible = true;
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;

		if (a - last_pos >= battery){
			possible = false;
		}
		battery -= (a - last_pos);
		//cout << "bat: " << battery << "\n";
		battery = min(battery + b - a, capacity);
		last_pos = b;
	}

	if (possible and t - last_pos >= battery) 
		possible = false;

	if (possible){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}
