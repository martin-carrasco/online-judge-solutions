#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1e6;
int a[MAXN];
vi sup;

int bs(int v){
	int l = 0;
	int r = sup.size() - 1;

	int ans = 0;
	while(l <= r){
		int mid = (l+r) / 2;

		if (sup[mid] > v){
			r = mid - 1;	
		}	else {
			l = mid + 1;
			ans = mid;
		}
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];

	for(int i = 1;i <= n;i++){
		auto l = lower_bound(sup.begin(), sup.end(), a[i]);
		int pos = distance(sup.begin(), l);
		if (l == sup.end()){
			sup.push_back(a[i]);
		} else{
			sup[pos] = a[i];
		}
	}
	cout << sup.size() << "\n";;
	return 0;
}
