#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1000+5;

int main(){
	int n;
	cin >> n;
	vi a(n, 0), b(n, 0), c(n, 0);

	for(int i = 0;i < n;i++){
		char c;
		cin >> c;
		a[i] = (int) c - '0';
	}

	for(int i = 0;i < n;i++){
		char c;
		cin >> c;
		b[i] = (int) c - '0';
	}
				
	sort(b.begin(), b.end());
	c = b;

	int min_hit = 0;
	for(int i = 0;i < n;i++){
		bool no_hit = true;
		for(auto it = c.begin();it != c.end();it++){
			int cu = *it;
			if (a[i] <= cu){
				c.erase(it);	
				no_hit = false;
				break;
			}
		}
		min_hit += no_hit;
	}


	int max_hit = 0;
	for(int i = 0;i < n;i++){
		bool no_hit = false;
		for(auto it = b.begin();it != b.end();it++){
			int cu = *it;
			if (cu > a[i]){
				b.erase(it);	
				no_hit = true;
				break;
			}
		}
		max_hit += no_hit;
	}


	cout << min_hit << "\n";
	cout << max_hit << "\n";
	return 0;
}
