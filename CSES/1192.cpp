#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 1e3 + 5;

int n, m, k;
bool g[MAXN][MAXN];
int sz[MAXN*MAXN];
ii parent[MAXN*MAXN];


void make_set(ii pos){
	int coord = pos.first*m + pos.second;
	parent[coord] = pos;
	sz[coord] = 1;
}

ii find_set(ii pos){
	int coord = pos.first*m + pos.second;
	if (pos == parent[coord]) return parent[coord];
	return find_set(parent[coord]);
}

void union_set(ii pos_1, ii pos_2){
	auto root_1 = find_set(pos_1);
	auto root_2 = find_set(pos_2);
	int coord_1 =  root_1.first*m+root_1.second;
	int coord_2 =  root_2.first*m+root_2.second;
	if (root_1 != root_2) {
		if (sz[root_1.first*m+root_1.second] < sz[root_2.first*m+root_2.second])
			swap(root_1, root_2);
		coord_1 =  root_1.first*m+root_1.second;
		coord_2 =  root_2.first*m+root_2.second;
		parent[coord_2] = root_1;
		sz[coord_1] += sz[coord_2];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	set<ii> rooms;

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;
			cin >> c;
			g[i][j] = (c == '#');
		}
	}

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(g[i][j]) continue;
			vector<ii> adj_ps;													
			for(auto [x, y] : {make_pair(i+1, j),
													make_pair(i-1, j),
													make_pair(i, j+1),
													make_pair(i, j-1)})
			{
				if (g[x][y] or x < 0 or x >= n or y < 0 or y >= m) continue;
				if (x < i or y < j)
					adj_ps.push_back({x, y});
			}
			ii p = {i, j};
			make_set(p);
			for(auto [x, y] : adj_ps){
				ii tmp = {x, y};
				union_set(tmp, p);
			}
		}
	}
	
	for(int i =0;i < n;i++){
		for(int j = 0;j < n;j++){
			if (g[i][j]) continue;
			ii pos = {i, j};
			auto root = find_set(pos);
			rooms.insert(root);
		}
	}
	cout << rooms.size() << "\n";
	return 0;
}
