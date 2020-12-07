#include "bits/stdc++.h"

using namespace std;
const int MAX_N = 1e6;
vector<int> a(MAX_N, numeric_limits<int>::max());
vector<int> b(MAX_N, numeric_limits<int>::max());

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0;i<n;i++)
		cin >> a[i];

	for(int i = 0;i<m;i++)
		cin >> b[i];

	sort(a.begin(), a.end());

	for(int i = 0;i < m;i++){
		auto it = lower_bound(a.begin(), a.end(), b[i]+1);	
		if (it == a.end())
			cout << 0 << " " ;
		else
			cout << distance(a.begin(), it) << " ";
	}
	cout << "\n";

	return 0;
}
