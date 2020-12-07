#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 200;
ll d[MAXN][MAXN];
string no_encr, encr;
int m;

int main(){

	map<char, int> mp;
	cin >> no_encr >> encr;
	cin >> m;

	int dif = 0;

	for(int i = 0;i < MAXN;i++){
		for(int j = 0;j < MAXN;j++){
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = numeric_limits<ll>::max();	
		}
	}
	
	for(int i = 0;i < m;i++){
		char src_c, dst_c;
		int src, dst;
		ll w;

		cin >> src_c;
		cin >> dst_c;

		if(not mp.count(src_c))
			mp[src_c] = dif++;

		if(not mp.count(dst_c))
			mp[dst_c] = dif++;

		src = mp[src_c];
		dst = mp[dst_c];

		cin >> w;

		d[src][dst] = min(w, d[src][dst]);
	}


	int max_link = mp.size();

	for(int k = 0;k <= max_link;k++){
		for(int i = 0;i <= max_link;i++){
			for(int j = 0;j <= max_link;j++){
				if (d[i][k] < numeric_limits<ll>::max() and d[k][j] < numeric_limits<ll>::max()) 
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	ll cnt = 0;
	for(int i = 0;i < no_encr.size();i++){
		char norm_c = no_encr[i];
		char enc_c = encr[i];

		if(norm_c == enc_c)
			continue;

		if (not mp.count(norm_c) or not mp.count(enc_c)){
			cnt = -1;
			break;
		}

		int src, dst;
		src = mp[norm_c];
		dst = mp[enc_c];

		ll c_cost = d[src][dst];

		cnt += c_cost;
	}
	cout << cnt << "\n";

	return 0;
}
