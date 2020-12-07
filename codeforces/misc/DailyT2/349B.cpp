#include "bits/stdc++.h"

using namespace std;
using ii = pair<int,int>;
using vi = vector<int>;


const int MAXN = 1e6;
ii a[10];
int output_1[10];

void print(){
	for(int i = 9;i >= 1;i--){
		for(int j = 0;j < output_1[i];j++) {
			cout << i;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v;
	cin >> v;

	for(int i = 1;i <= 9;i++){
		int val;
		cin >> val;
		a[i] = {val, i};
	}

	sort(a, a+10);

	int v_back = v;

	int min_val = a[1].first;
	int max_len = v / a[1].first;

	if (max_len == 0) {
		cout << -1 << "\n";
		return 0;
	}

	sort(a, a+10, [](auto p1, auto p2){ return p1.second < p2.second;});

	int i = 9;
	int cnt = 1;
	while(i > 0){
		if (cnt == max_len+1)
			break;
		if (v < a[i].first) {
			i--;
			continue;
		}
		if ( (v - a[i].first) / min_val == (max_len - cnt) ) {
			cout << i;	
			v -= a[i].first;
			cnt++;
			continue;
		}
		i--;
	}
	cout << "\n";
	return 0;
}
