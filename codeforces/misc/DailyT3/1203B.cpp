#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using di = deque<int>;


di sides;
int n, m;

bool valid(){
	int target_area = sides[0] * sides[m-1];
	while(not sides.empty()){
		int first, last;
		first = sides.front();
		last = sides.back();
		sides.pop_front();
		sides.pop_back();

		if (first * last != target_area)
			return false;

		if (sides.front() != first or sides.back() != last)
			return false;
		sides.pop_front();
		sides.pop_back();
		
	}
	return true;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		cin >> n;
		m = n * 4;

		for(int i = 0;i < m;i++){
			int t;
			cin >> t;
			sides.push_back(t);
		}
		
		sort(sides.begin(), sides.end());

		
		bool result = valid();

		if (result)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

		sides.clear();
	}

	return 0;
}
