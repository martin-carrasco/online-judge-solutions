#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

int n;

int gcd(int a, int b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		vi v, a(n, 0);
		for(int i = 0;i < n;i++){
			int tmp;
			cin >> tmp;
			a[i] = tmp;;
		}
		
		sort(a.begin(), a.end(), greater<int>());
		int last_gcd = *a.begin();
		a.erase(a.begin());
		v.push_back(last_gcd);
		
		while(not a.empty()) {
			int curr_max = 1;
			auto max_it = a.begin();
			for(auto it = a.begin();it != a.end();it++){
				int cu_gcd = gcd(*it, last_gcd);
				if (cu_gcd > curr_max){
					curr_max = cu_gcd;
					max_it = it;
				}
			}

			v.push_back(*max_it);
			a.erase(max_it);
			last_gcd = curr_max;
		}	
		
		for(int i = 0;i < n;i++)
			cout << v[i] << " ";
		cout << "\n";
	}
	return 0;
}
