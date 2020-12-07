#include "bits/stdc++.h"

using namespace std;
using iii = tuple<int, int, int>;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	set<iii> times;
	for(int i = 0;i < n;i++){
		int s, e;
		cin >> s >> e;
		times.emplace(e, s, i);
	}


	int time = 0;
	int cnt = 0;
	for(auto it = times.begin();it != times.end();it++){
		if (get<1>(*it) >= time){
			time = get<0>(*it);
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}
