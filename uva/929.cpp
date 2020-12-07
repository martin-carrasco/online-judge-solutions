#include "bits/stdc++.h"

using namespace std;
using pii = pair<int, int>;
using pipii = pair<int, pii>;
using tiii = tuple<int, int, int>;

const int MAXN = 1000 + 5;
int mat[MAXN][MAXN];
int d[MAXN*MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q, n, m;
	cin >> q;
	while(q--){
		cin >> n >> m;

		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> mat[i][j];
			}
		}

		for(int i = 1;i <= n*m;i++){
			d[i] =  1e9;
		}


		d[1] = 0;
		set<tiii> q;
		q.insert({0, 1, 1});
		while(not q.empty()){
			int x = get<1>(*q.begin());
			int y = get<2>(*q.begin());
			int v = ((x - 1) * m) + y;
			q.erase(q.begin());

			for(auto pos : {
						make_pair(x + 1, y),
						make_pair(x - 1, y),
						make_pair(x, y + 1),
						make_pair(x, y - 1)}){

				int r = pos.first;
				int c = pos.second;

				if (r < 1 or c < 1 or r > n or c > m)
					continue;

				int to = ((r - 1)*m) + c;
				int len = mat[r][c];
				if (d[v] + len < d[to]){
					q.erase({d[to], r, c});
					d[to] = d[v] + len;
					q.insert({d[to], r, c});
				}
			}
		}


		cout << d[n*m] + mat[1][1] << "\n";
	}

	return 0;
}
