#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 1e6;

int n;

int main(){
	cin >> n;
	multiset<tuple<int, bool, int>> events;
	map<pair<int, int>, int> arrival_to_departure;
	set<int> rooms;
	for(int i = 0;i < n;i++){
		int a,d;
		cin >> a >> d;
		events.insert({a, false, n-i});
		arrival_to_departure[make_pair(a, n-i)] = d;
		rooms.insert(i+1);
	}

	vector<pair<int, int>> ans;
	int room_cnt = 0;
	for(auto it = events.begin();it != events.end();it++){
		tuple<int, bool, int> c_event = *it;
		if (not get<1>(c_event)) {
			auto room_it = rooms.begin();
			room_cnt = max(room_cnt, *room_it);
			ans.push_back({*room_it, get<2>(c_event)});
			int departure = arrival_to_departure[make_pair(get<0>(c_event), get<2>(c_event))];
			events.insert({departure, true, *room_it});
			rooms.erase(room_it);
		} else {
			int room = get<2>(c_event);			
			rooms.insert(room);
		}
	}
	sort(ans.begin(), ans.end(), [](auto e1, auto e2){
				return e1.second > e2.second;
			});
	cout << room_cnt << "\n";
	for (auto ele : ans)
		cout << ele.first << " ";
	cout << "\n";
	
	return 0;
}
