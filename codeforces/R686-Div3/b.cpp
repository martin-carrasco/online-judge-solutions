#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2e5 + 5;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin  >> t;
	while(t--){
		int n, min_num, min_idx;
		set<ii> chosen;
		cin >> n;
		for(int i = 1;i <= n;i++){
			int tmp;cin >> tmp;
			chosen.insert({tmp, i});
		}
		bool cho = false;
		auto last_it = chosen.end();
		for(auto it = chosen.begin();it != chosen.end();it++){
			int num = it->first;
			if ((last_it == chosen.end() or last_it->first != num)  and (next(it) == chosen.end() or next(it)->first != num)) {
				cout << it->second << "\n";
				cho = true;
				break;			
			}
			last_it = it;
		}
		if(not cho)
			cout << -1 << "\n";
			
	}

	return 0;
}
