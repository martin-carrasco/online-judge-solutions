#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 2e5 + 5;
const int LOGMAX = log2(MAXN);
int n, q;

int rmq[LOGMAX][MAXN];


int query(int a, int b){
	int i = 0;
	int target = b - a + 1;

	while((1 << i) <= target) {
		i++;
	}

	if (i > 0)
		--i;

	int max_sz = b - pow(2, i) + 1;
	return min(rmq[i][a], rmq[i][max_sz]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<ii> queries;
	cin >> n >> q;

	for (int i = 1;i <= n;i++){
		cin >> rmq[0][i];
	}
	for(int i = 0;i < q;i++){
		int a,b;
		cin >> a >> b;
		queries.push_back({a, b});
	}

	int log_n = log2(n);
	for (int i = 1; i <= log_n;i++){
		int max_lg = n - pow(2, i) + 1;
		for (int j = 1;j <= max_lg;j++){
			int max_sz = j + pow(2, i-1);
			rmq[i][j] = min(rmq[i-1][j], rmq[i-1][max_sz]);
		}
	}

	for(auto& [a, b] : queries){
		cout << query(a, b) << endl;
	}

	return 0;
}
