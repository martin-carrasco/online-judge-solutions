#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 1e3 + 5;

int n, m, k;
bool g[MAXN][MAXN];
int sz[MAXN*MAXN];
int sights[MAXN*MAXN];

struct Point {
	int x, y, paintings;

	bool operator==(Point& other){
		return other.x == x and other.y == y;
	}
	bool operator!=(Point& other){
		return not (other == *this);
	}

	int get_coord(){
		return x*m + y;
	}
};

Point parent[MAXN*MAXN];



void make_set(Point pos){
	int coord = pos.get_coord();
	parent[coord] = pos;
	sz[coord] = 1;
	sights[coord] = pos.paintings;
}

Point find_set(Point pos){
	if (pos == parent[pos.get_coord()]) return parent[pos.get_coord()];
	return find_set(parent[pos.get_coord()]);
}

void union_set(Point pos_1, Point pos_2){
	auto root_1 = find_set(pos_1);
	auto root_2 = find_set(pos_2);
	if (root_1 != root_2) {
		if (sz[root_1.get_coord()] < sz[root_2.get_coord()])
			swap(root_1, root_2);
		parent[root_2.get_coord()] = root_1;
		sz[root_1.get_coord()] += sz[root_2.get_coord()];
		sights[root_1.get_coord()] += sights[root_2.get_coord()];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;
			cin >> c;
			g[i][j] = (c == '*');
		}
	}

	for(int i = 1;i < n-1;i++){
		for(int j = 1;j < m-1;j++){
			if(g[i][j]) continue;
			vector<ii> adj_ps;													
			int cnt_walls = 0;
			for(auto [x, y] : {make_pair(i+1, j),
													make_pair(i-1, j),
													make_pair(i, j+1),
													make_pair(i, j-1)})
			{
				if (g[x][y]){
						cnt_walls++;
						continue;
				}
				if (x < i or y < j){
					adj_ps.push_back({x, y});
				}
			}
			Point p = {.x = i, .y = j, .paintings=cnt_walls};
			make_set(p);
			for(auto [x, y] : adj_ps){
				Point tmp = {.x = x, .y = y, .paintings = 0};
				union_set(tmp, p);
			}
		}
	}
	
	for(int i = 0;i < k;i++){
		int x, y;
		cin >> x >> y;
		Point p = {.x=x-1, .y=y-1, .paintings=0};
		auto root = find_set(p);
		cout << sights[root.get_coord()] << "\n";
	}
	return 0;
}
