#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 1e5 + 5;

int a[MAXN];
ii c[MAXN];
int main(){
	int s, b;
	cin >> s >> b;

	for(int i = 0;i < s;i++)
		cin >> a[i];

	for(int i = 0;i < b;i++){
		int d, g;
		cin >> d >> g;

		c[i] = {d, g};
	}

	sort(c, c+b);

	for(int i = 1;i < b;i++){
		c[i].second += c[i-1].second;
	}

	for(int i = 0;i < s;i++){
	
		int l = 0;
		int r = b-1;

		int ans = 0;
		while(l <= r){
			int mid = (l+r) / 2; 

			if (c[mid].first <= a[i] ){
				ans = c[mid].second;
				l = mid+1;
			} else{
				r = mid - 1;
			}
		}
		cout << ans << " ";
	}
	cout << "\n";

	return 0;
}
