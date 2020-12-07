#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 1e6;

int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> q;
	vector<int> ans;
	for(int i = 0;i < n;i++) cin >> a[i];

	for(int i = 0;i < n;i++){
		while(q.size() > 0 and a[q.top()] >= a[i])
			q.pop();

		if (q.size() > 0 )
			cout << q.top() + 1 << " ";
		else
			cout << 0 << " ";
		q.push(i);
	}
	cout << "\n";

	return 0;
}
