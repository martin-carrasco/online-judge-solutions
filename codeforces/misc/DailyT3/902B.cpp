#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e4 + 100;

vi adj[MAXN];
int color[MAXN];
bool v[MAXN];
int n;

int main(){
	cin >> n;
	for(int i = 2;i <=n;i++){
		int pi;
		cin >> pi;
		//adj[i].push_back(pi);
		adj[pi].push_back(i);
	}

	for(int i = 1;i <=n;i++)
		cin >> color[i];

	int steps = 1;
	queue<ii> q;
	q.push({1, color[1]});
	while(not q.empty()){
		ii np = q.front();
		int n = np.first;
		int c = np.second;
		q.pop();

		for(auto edge : adj[n]){
			if (v[edge])
				continue;
			if (color[edge] != c){
				steps++;
				q.push({edge, color[edge]});
			} else {
				q.push({edge, c});
			}
			v[edge] = 1;
		}
	}

	cout << steps << "\n";
	return 0;
}
