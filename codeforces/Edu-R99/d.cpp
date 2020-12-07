#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;


const int MAXN = 500 + 5;
int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n,x;
		bool sorted = true;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			if (a[i] < a[i-1])
				sorted=false;	
		}

		bool no_pos = false;
		for(int i = 1;i <= x;i++){
			if(a[i] > a[i-1]){
				no_pos =true;
				break;
			}
		}

		if( no_pos){
			cout << -1 << "\n";
			continue;
		}
		if (sorted){
			cout << 0 << "\n";
		}
		
	}
	return 0;
}
