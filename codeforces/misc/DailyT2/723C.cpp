#include "bits/stdc++.h"

using namespace std;
using ii = pair<int, int>;

const int MAXN = 2000;
int n, m;
int a[MAXN];
int b[MAXN];

int min_occurr(){
	int min_val = 1e9;	
	int min_key = 0;
	for(int i = 1;i <= m; i++){
		if (b[i] < min_val){
			min_val = b[i];
			min_key = i;
		}
	}
	return min_key;
}

int max_occurr(){
	int max_val = 0;
	int max_key = 0;
	for(int i = 1;i <= m;i++){
		if (b[i] > max_val){
			max_val = b[i];
			max_key = i;
		}
	}
	return max_key;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int max_size = n / m;
	queue<int> q;

	for(int i = 0;i < n;i++){
		int t;
		cin >> t;
		if (t <= m)
			b[t]++;
		else
			q.push(i);
		a[i] = t;
	}

	int min_band = min_occurr();
	int max_band = max_occurr();

	int changes = 0;
	while(b[min_band] < max_size){
		if (q.size() > 0){
			int pos = q.front();
			q.pop();
			a[pos] = min_band;
			b[min_band]++;
			changes++;
		} else {
			for(int i = 0;i < n;i++){
				if (a[i] == max_band) {
					a[i] = min_band;		
					b[min_band]++;
					b[max_band]--;
					changes++;
					break;
				}
			}
		}
		//cout << "Min val: " << b[min_band] << ", with index: " << min_band << "\n";
		//cout << "Max val: " << b[max_band] << ", index: " << max_size  << "\n";
		min_band = min_occurr();
		max_band = max_occurr();
	}

	int b_i =  b[min_occurr()];
		
	cout << b_i << " " << changes << "\n";
	for(int i = 0;i < n;i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}
