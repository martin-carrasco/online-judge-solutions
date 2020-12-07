#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100 + 5;
int a[MAXN];
int b[MAXN];

int gcd (int a1, int b1) {
    while (b1) {
        a1 %= b1;
        swap(a1, b1);
    }
    return a1;
}

pair<int, int> reduce(int num, int denum){
	int divisor = gcd(num, denum);
	while(divisor != 1){
		num /= divisor;
		denum /= divisor;
		divisor = gcd(num, denum);
	}
	return {num, denum};
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < n+1;i++) cin >> a[i];
	for(int i = 0;i < m+1;i++) cin >> b[i];

	if (n > m){
		if ((a[0] < 0 or b[0] < 0) and not (a[0] < 0 and b[0] < 0))
			cout << "-";
		cout << "Infinity" << "\n";
	}
	else if (n < m){
		cout << "0/1" << "\n";
	} else{
		bool neg = (a[0] < 0 or b[0] < 0) and not (a[0] < 0 and b[0] < 0);
		
		pair<int, int> den_num = reduce(a[0], b[0]);

		if (neg)
			cout << "-";
		cout << abs(den_num.first) << "/" << abs(den_num.second) << "\n";
	}
	return 0;
}
