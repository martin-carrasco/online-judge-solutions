#include "bits/stdc++.h"

using namespace std;
int ps(int& n) {
    int h = n & 0xF;
    if (h > 9)
        return 0;
    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
        int t = (int) floor( sqrt((double) n) + 0.5 );
        return t*t == n;
    }
    return 0;
}
int main() {
	int n;
	cin >> n;

	int count = 0;
	for(int c = 1;c <=n;c++){
		int c_p = pow(c, 2);
		for(int a = 1;a <= c;a++){
			int a_p = pow(a, 2);
			int b_p = c_p - a_p;
			if (b_p > 0 and ps(b_p) and b_p > pow(c-a, 2) and pow(a + c, 2) > b_p and b_p  > pow(a -c, 2)){
				count++;
			}
		}
	}
	cout << count / 2;
	return 0;
}
