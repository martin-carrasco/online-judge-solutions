#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pr = pair<int,int>;

int n, x_0, y_0;

int gcd(int a, int b) { 
    while (b != 0) {
			int t = b;
			b = a % b;
			a = t;
		}
    return a; 
} 
  


int main() {
	set<double> slps;
	bool vert = 0;
	set<pr> ps;
	int mn = 0;
	cin >> n >> x_0 >> y_0;	
	for (int i = 0;i < n;i++){
		int x, y;
		cin >> x >> y;

		int dx = x - x_0;
		int dy = y - y_0;

    int g = gcd(abs(dy), abs(dx)); 
  
		int dy_d =  dy / g;
		int dx_d =  dx / g;
		

		if (not dx_d) {
			vert = true;
			continue;
		}

		double slope = (double)  dy_d / dx_d;
		slps.insert(1.0 * dy_d / dx_d);
	}
	cout << slps.size() + vert;
	return 0;
}
