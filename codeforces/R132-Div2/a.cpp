#include "bits/stdc++.h"

using namespace std;

const int MAX_S = 50 + 5;

int a[MAX_S];
int b[MAX_S];

int gcd(int a, int b){
	while(b != 0){
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main() {
	map<int, int> sizes;
	int n,m;
	cin >> n;

	for (int i = 0;i < n;i++)
		cin >> a[i];

	cin >> m;
	for (int i = 0;i < m;i++)
		cin >> b[i];

	
	int mx = 0;
	for(int i = 0;i < n;i++){
		for (int j = 0;j < m;j++){
			int ped = a[i];
			int whel = b[j];

			if (ped == 0)
				continue;
			int gcd_n = gcd(whel, ped); 
			if (gcd_n == ped){
				int div = whel / ped; 

				if (sizes.count(div))
					sizes[div] += 1;	
				else
					sizes[div] = 1;

				if (div > mx)
					mx = div;	
			}
		}
	}
	
	cout << sizes[mx];
	return 0;
}
