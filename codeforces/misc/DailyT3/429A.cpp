#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using ibb = tuple<int, bool, bool>;

const int MAXN = 1e5 + 100;

vi adj[MAXN];
bool state[MAXN];
bool goal_state[MAXN];
bool v[MAXN];
vi flip_nodes;
int n;

int main(){
	cin >> n;
	for(int i = 1;i <=n-1;i++){
		int u, vn;
		cin >> u >> vn;
		adj[u].push_back(vn);
		adj[vn].push_back(u);
	}

	for(int i = 1;i <=n;i++)
		cin >> state[i];

	for(int i = 1;i <=n;i++)
		cin >> goal_state[i];


	bool first_flip = state[1] != goal_state[1];
	if (first_flip)
		flip_nodes.push_back(1);
	int steps = (int)first_flip;
	queue<ibb> q;
	q.push({1, first_flip, false});
	while(not q.empty()){
		ibb np = q.front();
		int n = get<0>(np);
		bool p_flip = get<1>(np);
		bool gp_flip = get<2>(np);
		q.pop();

		for(auto edge : adj[n]){
			if (v[edge])
				continue;
			if (gp_flip){
				if(goal_state[edge] != state[edge]) { // correct state
					q.push({edge, true, p_flip});
				} else {
					steps++;
					q.push({edge, false, p_flip});
					flip_nodes.push_back(edge);
				}
			} else {
				if (goal_state[edge] == state[edge]){
					q.push({edge, false, p_flip});
				} else {
					steps++;
					q.push({edge, true, p_flip});
					flip_nodes.push_back(edge);
				}
			}
			v[edge] = 1;
		}
	}

	cout << steps << "\n";
	for (auto e : flip_nodes){
		cout << e << "\n";
	}
	return 0;
}
