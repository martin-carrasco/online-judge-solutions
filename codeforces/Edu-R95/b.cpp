#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;


const int MAXN = 100 + 5;
int a[MAXN];
bool locks[MAXN];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		vi v;
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}

		for(int i = 0;i < n;i++){
			bool st;
			cin >> st;

			if(not st)
				v.push_back(a[i]);
			locks[i] = st;
		}

		sort(v.begin(), v.end(), greater<int>());

		int k = 0;
		int idx = 0;
		ll sum = 0;
		for(int i = 0;i < n;i++){
			if (locks[i] == 1) {
				sum += a[i];
			} else  {
				int val = v[idx++];
				sum += val;
				a[i] = val;
			}
			if (sum < 0)
				k = i;
		}
		for(int i = 0;i < n;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
