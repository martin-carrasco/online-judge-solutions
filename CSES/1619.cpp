#include "bits/stdc++.h"

using namespace std;
using iii = tuple<int, bool, int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	set<iii> times;
	for(int i = 0;i < n;i++){
		int e, l;
		cin >> e >> l;
		times.emplace(e, 1, i);
		times.emplace(l, 0, i);
	}


	int ans = 0;
	int current = 0;
	for(auto it = times.begin();it != times.end();it++){
		bool t = get<1>(*it);

		if (t)
			current++;
		else
			current--;
		ans = max(current, ans);
	}

	cout << ans << "\n";

	return 0;
}
