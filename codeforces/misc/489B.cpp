#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAX_N = 100 + 5;

int a[MAX_N];
int b[MAX_N];

int main(){
	int n, m;

	cin >> n;
	set<int> matched_b;
	set<int> matched_g;

	for(int i= 0;i < n;i++)
		cin >> a[i];

	cin >> m;
	for(int i= 0;i < m;i++)
		cin >> b[i];

	sort(a, a+n);
	sort(b, b+m);

	for(int i= 0;i < n;i++){
		for(int j = 0; j< m;j++){
			if (abs(a[i] - b[j]) <= 1 and not matched_b.count(i) and not matched_g.count(j)){
				matched_b.insert(i);
				matched_g.insert(j);
			}		
		}
	}

	cout << matched_b.size() << endl;
	return 0;
}
