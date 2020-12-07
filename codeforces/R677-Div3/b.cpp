#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii =vector<ii>;
using ll = long long;

const int MAXN = 50 + 5;


bool a[MAXN];
vii inters;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0;i < n;i++) cin >> a[i];
		
		int st, end;
		st = end = -1;
		for(int i = 0;i < n;i++){
			if (a[i] and st == -1){
				st = i;
			} else if (st != -1 and not a[i]) {
				end = i-1;
				inters.push_back({st, end});
				st = -1;
			}
		}

		if (st != -1)
			inters.push_back({st, n-1});

		int cnt = 0;
		int last_end = -1;
		for(auto block : inters){

			if(last_end == -1){
				last_end = block.second;
				continue;
			}

			cnt += block.first - last_end - 1;
			last_end = block.second;
		}

		cout << cnt << "\n";
		inters.clear();
	}

	return 0;
}

