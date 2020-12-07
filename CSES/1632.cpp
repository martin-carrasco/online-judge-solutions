#include "bits/stdc++.h"
 
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
 
	set<iii> times;
	set<ii> watch_times;
	for(int i = 0;i < k;i++){
		watch_times.insert({0, i});
	}
	for(int i = 0;i < n;i++){
		int s, e;
		cin >> s >> e;
		times.emplace(e, s, i);
	}
 
	 
	int cnt = 0;
	for(auto it = times.begin();it != times.end();it++){
		int curr_start_time = get<1>(*it);
		int curr_end_time = get<0>(*it);
		auto low_time = watch_times.lower_bound(make_pair(curr_start_time, 1e9));

		if (low_time == watch_times.begin())
			continue;
		--low_time;

		int idx = low_time->second;

		if (curr_start_time >= low_time->first){
			watch_times.erase(low_time);
			watch_times.insert({curr_end_time, idx});
			cnt++;
		}
	}
	cout << cnt << "\n";
 
	return 0;
}
