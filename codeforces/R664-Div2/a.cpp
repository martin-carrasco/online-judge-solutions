#include "bits/stdc++.h"

using namespace std;
using ll = long long;

bool p(ll& r, ll& g, ll&b, ll& w){
	
	int sum = 0;
	sum += r & 1;
	sum += g & 1;
	sum += b & 1;
	sum += w & 1;

	return sum < 2;
}

int main () {
	int t;
	vector<bool> ans;
	cin >> t;
	for(int x = 0;x < t;x++){
		ll r, g ,b, w;
		cin >> r >> g >> b >>w;
		
		bool pal = pal = p(r, g, b, w);
		if (not pal and r > 0 and g > 0 and b > 0){
			r--;
			g--;
			b--;
			w+=3;
			pal = p(r, g, b, w);
		}

		/*while (1){
			if (pal)
				break;
			if (r == 0 or g == 0 or b == 0)
				break;
			r--;
			g--;
			b--;
			w+=3;
			pal = p(r, g, b, w);
		}*/

		ans.push_back(pal);
	}

	for (auto a : ans){
		if (a)
			cout << "Yes";
		else
			cout << "No";
		cout << endl;

	}
	return 0;
}

