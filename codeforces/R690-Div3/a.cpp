#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 300 + 5;
int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi seq_final;
		for(int i = 0;i < n;i++) cin >> a[i];
		
		int i, j;
		i = 0;
		j = n-1;
		while(i < n and j >= 0){
			if (i > j) break;
			seq_final.push_back(a[i]);
			if (i == j)	break; 
			seq_final.push_back(a[j]);

			i++;
			j--;
		}
		for(auto ele:seq_final)
			cout << ele << " ";
		cout << "\n";
	}

	return 0;
}
