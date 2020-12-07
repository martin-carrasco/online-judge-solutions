#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e6;

bool a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int s, e, s_t, e_t, cnt;
		cnt = 0;
		s = e = 0;
		s_t = e_t = -1;
		for(int i = 0;i < n;i++) {
			bool v;
			cin >> v;
			a[i] = v;
			if (not v) {
				s_t = s_t == -1 ? i : s_t;
				continue;
			} 
			e_t = i-1;
			if (e_t != -1 and s_t != - 1 and e_t - s_t >= e - s){
				e = e_t;
				s = s_t;
			}
			s_t = -1;
			e_t = -1;
		}
		if (e_t != -1 and s_t != - 1 and e_t - s_t >= e - s){
			e = e_t;
			s = s_t;
		}

		int n_e, n_s;
		n_e = n_s = 0;
		s_t = e_t = -1;
		bool more_than_one = false;

		for(int i = 0;i < n;i++){
			if (a[i] == 0 and (i < s or i > e )) {
				s_t = s_t == -1 ? i : s_t;
				continue;
			} 
			e_t = i-1;
			if (e_t != -1 and s_t != -1 and e_t - s_t >= n_e - n_s){
				n_e = e_t;
				n_s = s_t;
				more_than_one = true;
			}
			s_t = -1;
			e_t = -1;
		}

		if (e_t != -1 and s_t != -1 and e_t - s_t >= n_e - n_s){
			n_e = e_t;
			n_s = s_t;
		}
		//cout << "s_t: " << s_t << ", e_t: " << e_t << "\n"; 
		//cout << "s: " << s << ", e: " << e << "\n";


		if (s != 0 and (e - s + 1) % 2 == 1) {
			if (more_than_one) {
				if ((n_e - n_s + 1) >= (e-s+2) / 2) {
					cout << "No" << "\n";
				}
				else {
					cout << "Yes" << "\n";
				}
			} else {
				cout << "Yes" << "\n";
			}
		}
		else {
			cout << "No" << "\n";
		}
	}
	return 0;
}
