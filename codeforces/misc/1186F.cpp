#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 1e6 + 5;
using vi = vector<int>;
using vii = vector<int, vi>;

bool g[MAX_N][MAX_N];
bool v[MAX_N];

int main(){
	int n, m;
	cin >> n >> m;

	vii nodes(n, vi());
	map<int, int> quant;
	map<pair<int, int>, bool> rmd;

	int max_edges = ceil((n+m)  / 2);

	for(int i = 0;i < m;i++){
		int s, d;
		cin >> s >>d;
		nodes[s-1].push_back(d-1);
		nodes[d-1].push_back(s-1);
	}


	stack<int> stk;
	stk.push_back(0);
	v[0] = 1;
	while(not stk.empty()){
		int curr = stk.top();
		stk.pop();

		for(auto& nn : nodes[curr]){
			if(v[nn])
				continue;
			if ()
		}
	}
	return 0;
}
