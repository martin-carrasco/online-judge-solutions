#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;

const int MAXN = 20;

vi p1, p2;
map<int, bool> v;
int a[MAXN];
int n;

ll mn = 1e18;

void solve(int i){

	if (i == n){
		ll sum_1, sum_2;
		sum_1 = sum_2 = 0;
	//	cout << "P1: [";
		for(auto e : p1) {
	//		cout  << e << ",";
			sum_1 += e;
		}
	//	cout << "\n";
	//	cout << "P2: [";
		for(auto e : p2){
	//		cout << e<< ",";
			sum_2 += e;
		}
	//		cout << "\n";
		
		mn = min(mn, llabs(sum_2 - sum_1));
		return;
	}

	int e = a[i];
	p1.push_back(e);
	solve(i+1);
	p1.pop_back();
	p2.push_back(e);
	solve(i+1);
	v[e] = 0;
	p2.pop_back();
}

int main(){
	cin >> n;

	for(int i = 0;i < n;i++)
		cin >> a[i];

	solve(0);

	cout << mn << "\n";
	return 0;
}
