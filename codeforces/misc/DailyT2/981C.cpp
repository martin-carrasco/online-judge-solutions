#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e6;
vi adj[MAXN];
bool vis[MAXN];
vector<ii> paths;


void trav(int v){
	vis[v] = 1;
	for(auto u : adj[v]){
		int w = u;
		vis[w] = 1;
		while(1){
			int new_w = -1;
			for(auto next_w : adj[w]) {
				if (vis[next_w]) continue;
				new_w = next_w;
				break;
			}
			if (new_w == -1)
				break;
			w = new_w;
			vis[w] = 1;
		}
		paths.push_back({v, w});
	}
}
int main(){
	int n;
	cin >> n;

	for(int i = 0;i < n-1;i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int max_size = 0;
	int v_max = 0;
	int cnt = 0;
	int cnt_big_2 = 0;

	for(int i = 1;i <= n;i++){
		if (adj[i].size() > 2)
			cnt_big_2++;
		if (adj[i].size() > max_size){
			max_size = adj[i].size();
			cnt = 1;
			v_max = i;
		}
		else if (adj[i].size() == max_size)
			cnt++;
	}

	if (max_size > 2 and cnt_big_2 > 1) {
		cout << "No" << "\n";
		return 0;
	}

	cout << "Yes" << "\n";
	int start_v = v_max;

	trav(start_v);
	cout << paths.size() << "\n";
	for(auto pr : paths){
		cout << pr.first << " " << pr.second << "\n";
	}
	return 0;	
}
