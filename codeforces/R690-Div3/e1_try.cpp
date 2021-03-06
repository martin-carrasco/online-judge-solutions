
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAXN = 2e5 +5;
int a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		m = 3;
		cin >> n;
		int ans = 0;
		deque<int> q(m);	
		deque<int> p(m);

		for(int i = 0;i < n;i++) cin >> a[i];

		if (n < 3){
			cout << 0 << "\n";
			continue;
		}

		for(int k = 0; k < m;k++)  {
			while(not q.empty() and a[k] <= a[q.back()]) 
				q.pop_back();
			q.push_back(k);
		}

		for(int k = 0; k < m;k++)  {
			while(not p.empty() and a[k] >= a[p.back()]) 
				p.pop_back();
			p.push_back(k);
		}

		int i = 1;
		int j = 2;
		int k = 3;
		while(1) {

			int min_e = a[q.front()];
			int max_e = a[p.front()]; 
			
			/*cout << "i: " << j - m + 1 << endl;
			cout << "j: " << j << endl;

			for(auto e : q)
				cout << a[e] << " ";
			cout << endl;

			for(auto e : q)
				cout << e << " ";
			cout << endl;

			for(auto e : p)
				cout << a[e] << " ";
			cout << endl; 

			for(auto e : p)
				cout << e << " ";
			cout << endl; */

			if (max_e - min_e <= 2) ++ans;
			
			if(k == n)
				break;

			// Remover elementos que se salieron de la ventana
			while(not q.empty() and q.front() < i)
				q.pop_front();

			while(not p.empty() and p.front() < i)
				p.pop_front();

			// Quitar elementos mayores o menores
			while(not q.empty() and a[j] <= a[q.back()])
				q.pop_back();
			q.push_back(j);
			
			while(not p.empty() and a[j] >= a[p.back()])
				p.pop_back();
			p.push_back(j);

			i++;
			j++;

		}

		cout << ans << "\n";
	}

	return 0;
}
