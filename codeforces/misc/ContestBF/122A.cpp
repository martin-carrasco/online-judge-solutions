#include "bits/stdc++.h"

using namespace std;


bool l(int& num){
	return num == 4 or num == 7 ;
}

int main() {
	int y, k, c, d, u;
	vector<int> divs = {4, 7, 47, 44, 77, 74, 447, 477, 474, 774, 747, 777, 444};
	
	cin >> y;


	for (auto& d : divs){
		bool di = y % d == 0;
		if(di) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	
	return 0;
}
