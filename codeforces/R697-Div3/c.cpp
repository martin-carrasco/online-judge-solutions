#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAXN = 2e5 + 5;

int t, a, b, k;
vector<ii> arr;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> t;
	while(t--){
		cin >> a >> b >> k;
		for(int i = 0;i < k;i++){
			int tmp;
			cin >> tmp;
			arr.push_back({tmp, -1});
		}
		for(int i = 0;i < k;i++){
			int tmp;
			cin >> tmp;
			arr[i] = {arr[i].first, tmp};
		}

		sort(arr.begin(), arr.end());

		ll cnt = 0;
		for(int i = 0;i < k;i++){
			int boys = arr[i].first;	
			int girls = arr[i].second;	

			//cout << "b: " << boys << ", girls: " << girls << "\n";
			auto up = upper_bound(arr.begin(), arr.end(), make_pair(boys, (int)1e9));
			if (up == arr.end()) continue;
			int am = 0;
			if (up->second < girls) {
				//cout << "up_1: " << up->first << ", up_2: " << up->second << "\n";
				auto n_up = upper_bound(up, arr.end(), make_pair(up->first, girls-1));
				//cout << "n_up_1: " << n_up->first << ", n_up_2: " << n_up->second << "\n";
				auto nn_up = upper_bound(n_up, arr.end(), make_pair(n_up->first, girls));
				//cout << "nn_up_1: " << nn_up->first << ", up_2: " << nn_up->second << "\n";
				am = distance(up, n_up);
				//cout << "dist: " << am << "\n";
				am += distance(nn_up, arr.end());
				
			} else {
				//cout << "up_1: " << up->first << ", up_2: " << up->second << "\n";
				up = upper_bound(up, arr.end(), make_pair(up->first, girls));
				//cout << "up_1: " << up->first << ", up_2: " << up->second << "\n";
				am = distance(up, arr.end());
			}
			
			//cout << "amount: " << am << "\n";
			cnt += am;
		}
		cout << cnt << "\n";
		arr.clear();
	}
	return 0;
}
