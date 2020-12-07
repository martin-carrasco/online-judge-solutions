#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e4 + 5;

int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k ,l;
		deque<int> q;
		cin >> n >> k >> l;

		for(int i = 0;i < k;i++){
			a[i] = l;
			q.push_back(i);
		}
		
		int last_idx = -1;
		string ans = "";
		bool done = false;
		for(int i = 0;i < n;i++){

			int c_idx = q.front();
			q.pop_front();
			while(a[c_idx] == 0){
				if (q.size() == 0) {
					done = true;
					break;
				}
				c_idx = q.front();
				q.pop_front();
			}
			if (c_idx == last_idx) 
				done = true;
			if (done)
				break;

			a[c_idx]--;
			ans.append(to_string(c_idx+1) + " ");
			last_idx = c_idx;
			q.push_back(c_idx);

		}
		if (not done)
			cout << ans << "\n";
		else
			cout << -1 << "\n";
	}
	return 0;
}
