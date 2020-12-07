#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
const int MAXN = 1e5 + 5;

int n, k;
vi adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
char color[MAXN];
vi ans;

bool dfs(int v) {
    color[v] = true;
    for (int u : adj[v]) {
			if (color[u] == 0){
				parent[u] = 0;
				if(dfs(u))
					return 1;

			} else if (color[u] == 1){
				return 1;
			}
    }
		color[v] = 2;
    ans.push_back(v);
		return false;
}


int main(){
	cin >> n >> k;
	vi nds(k, 0);

	for(int i = 0;i < k;i++){
		cin >> nds[i];
	}

	for(int i = 1;i <= n;i++){
		int reqs;
		cin >> reqs;
		for(int j = 0;j < reqs;j++){
			int src;			
			cin >> src;
			adj[i].push_back(src);
		}
	}

	for (auto i : nds) {
		if (color[i] == 0 and dfs(i)) {
			cout << -1 << "\n";
			return 0;
		}
	}

	cout << ans.size() << "\n";
	for(auto val : ans)
		cout << val << " ";
	cout << "\n";

}
