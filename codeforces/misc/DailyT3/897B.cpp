#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;


int k, p;
ll sum = 0;
ll mod(string num, int a) { 
    ll res = 0; 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (ll)num[i] - '0') % (ll)a; 
    return res; 
} 

int main(){
	cin >> k >> p;
	
	while(k){
		string s = to_string(k);
		string r = s;
		reverse(r.begin(), r.end());
		string f = s.append(r);
		ll rhs = mod(f, p);
		sum = (sum + rhs) % (ll)p;
		k--;
	}
	cout << sum << "\n";
	return 0;
}

