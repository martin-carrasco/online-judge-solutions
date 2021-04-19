#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 1e5 + 5;


int n;
int c[MAXN], a[MAXN], b[MAXN];
vi adj[MAXN];
int id = 1;

int v_id(){
	id++;
	return id-1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> c[i];
			for(int j = 1;j <= c[i];j++){
				int c_id = v_id();
				if (j == 1) continue;
				adj[c_id].push_back(c_id-1);
				adj[c_id-1].push_back(c_id);
			}
		}
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 0;i <= n;i++) cin >> b[i];
		
		int idx_sum = c[i];
		for(int i = 2;i <= n;i++){
			int verts = c[i];	
			int connect = a[i];

			int idx_connect = idx_sum - c[i-1] + a[i]-1;

			adj[idx_sum].push_back(idx_connect);
			adj[idx_connect].push_back(idx_sum);

			idx_sum += verts;

			idx_connect = idx_sum - 1 - c[i-1] + b[i] - 1;

			adj[idx_connect].push_back(idx_sum - 1);
			adj[idx_sum - 1].push_back(idx_connect);
		}
	}
	return 0;
}
