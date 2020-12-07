#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

int a[3];
int b[3];
int n;

vector<ii> comb;
vector<ii> perm;
bool vis[6];
int solve(int pos){
	if (pos == 6){
		int b1, b2, b3;
		int a1, a2, a3;

		b1 = b[0];
		b2 = b[1];
		b3 = b[2];
		a1 = a[0];
		a2 = a[1];
		a3 = a[2];

		for(int i = 0;i < perm.size();i++){
			int play = perm[i];		
						
			if (play.second == b1){
				b1 = min	
			} else if (play.second == b2){

			} else if (play.second == b3){

			}
		}
	}
	int min_score = 1e9;
	for(int i = 0;i < comb.size();i++){
		if (vis[i]) continue;

		perm.push_back(comb[i]);	
		vis[i] = 1;
		min_score = max(solve(pos+1), min_score); 
		vis[i] = 0;
		perm.pop_back();
	}
	return min_score;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for(int i = 0;i < 3;i++) cin >> a[i];
	for(int i = 0;i < 3;i++) cin >> b[i];

	comb.push_back({a[0], b[0]});
	comb.push_back({a[0], b[1]});
	comb.push_back({a[0], b[2]});
	comb.push_back({a[0], b[2]});
	comb.push_back({a[1], b[0]});
	comb.push_back({a[2], b[1]});

	int max_ans = min(a1, b2) + min(a2, b3) + min(a3, b1);
	int min_ans = 0;

	cout << min_ans << " " << max_ans << "\n";
	return 0;
}
