#include "bits/stdc++.h"

using namespace std;

#define M_PI       3.14159265358979323846
const int MAX_S = 1e5 + 5;

vector<int> r1s;
vector<int> p1s;
vector<int> p2s;


double mass(int& r, int& p){
	return  2 * M_PI * r * p;
}

int main() {
	map<int, int> sizes;
	int n,m, k, A, B;

	cin >> n;
	for (int i = 0;i < n;i++){
		int t;
		cin >> t;
		r1s.push_back(t);
	}

	cin >> m;
	for (int i = 0;i < m;i++){
		int t;
		cin >> t;
		p1s.push_back(t);
	}


	cin >> k;
	for (int i = 0;i < k;i++){
		int t;
		cin >> t;
		p2s.push_back(t);
	}

	cin >> A>> B;
	
	sort(p1s.begin(), p1s.end());
	sort(p2s.begin(), p2s.end());
	sort(r1s.begin(), r1s.end());

	long double r1, p1, p2;
	r1 = r1s[r1s.size() - 1]; 
	p1 = p1s[p1s.size() - 1];
	p2 = p2s[0];

	cout << r1 << " " << p1 << " "  << p2 << endl;


	long double lower_p = (1.0 * (p1 * B + p2 * A ));
	long double upper_p =  (1.0 * B * p1);
	long double div_p = upper_p / lower_p;
	long double max_r2 = r1 * sqrt( div_p * 1.0) * 1.0;
	
	cout << fixed <<  max_r2 << setprecision(17);
	return 0;
}
