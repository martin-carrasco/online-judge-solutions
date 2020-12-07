#pragma GCC optimize("O2") 
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e6;
int n, m;

int p[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	set<ii> tickets;
	for(int i = 0;i < n;i++)  {
		int t;
		cin >> t;
		tickets.emplace(t, i);		
	}

	for(int i = 0;i < m;i++){
		int max_pay;
		cin >> max_pay;

		auto it = tickets.upper_bound({max_pay, 1e9});
		if (it == tickets.begin())
			cout << -1 << "\n";
		else {
			--it;
			cout << it->first << "\n";
			tickets.erase(it);
		}
	}
	return 0;
}

