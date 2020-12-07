#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1e5;

vi adj[MAXN];

int main(){
	int n;
	cin >> n;

	for(int i = 0;i < n-1;i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool ans = true;
	for(int i = 1;i <= n;i++){	
		if (adj[i].size() == 2){
			ans = false;
			break;
		}
	}


	if (ans)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";

	
	return 0;
}
