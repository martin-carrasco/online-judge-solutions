#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100 + 5;
int d[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int src, dst;
	int cnt_nxt = 1;
	while(1){
		cin >> src >> dst;

		if (src == 0 and dst == 0)
			break;

		map<int, int> mp;
		int cnt = 1;
		
		while(1){
			if(not mp.count(src))
				mp[src] = cnt++;
			if(not mp.count(dst))
				mp[dst] = cnt++;

			int x, y;
			x  = mp[src];
			y = mp[dst];
			d[x][y] = 1;

			cin >> src >> dst;
			if (src == 0 and dst == 0)
				break;
		}

		int max_link = cnt;

		for(int i = 1;i <= max_link;i++){
			for(int j = 1;j <= max_link;j++){
				if (d[i][j] == 0)
					d[i][j] = 1e9;	
			}
		}

		for(int k = 1;k <= max_link;k++){
			for(int i = 1;i <= max_link;i++){
				for(int j = 1;j <= max_link;j++){
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}


		int deg_sum = 0;
		for(int i = 1;i <= max_link;i++){
			for(int j = 1;j <= max_link;j++){
				if (i != j and d[i][j] != 1e9)
					deg_sum += d[i][j];
			}
		}

		int num_per_node = mp.size() == 1 ? mp.size() : (mp.size() * (mp.size() - 1));
		double ans = 1.0*deg_sum / num_per_node;

		
		cout << "Case " << cnt_nxt << ": average length between pages = " << fixed << setprecision(3) << ans << " clicks" <<	"\n";
		cnt_nxt++;
		
		for(int i = 0;i < MAXN;i++){
			for(int j = 0;j < MAXN;j++){
				d[i][j] =0;	
			}
		}
	}
	return 0;
}
