#include "bits/stdc++.h"


using namespace std;
using ll = long long;

const int MAX_N = 1e6 + 5;
int a[MAX_N];


int main(){
	int n = 100000;
	string s = "";
	for(int x= 0; x< n;x++){
		s.append("1");
	}

	for (int i = 0;i < n;i++){
		string sub = s.substr(i, 1);
		int num = stoi(sub);
		a[i] = i == 0 ? num : num +a[i-1];
	}
	ll res = 0;
	for(int i = 0;i < n;i++){
		for (int j = i;j < n;j++){
			int bef = i == 0 ? 0 : a[i-1];
			res += (ll)(a[j] - bef == j - i + 1);
		}			
	}
	cout << res;
	return 0;
} 

