#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 100 + 5;
using ii = pair<int, int>;
map<ii, bool> get_there;


  
unordered_set<string> st; 
void subsequence(string str)  { 
	for (int i = 0; i < str.length(); i++) { 
		for (int j = str.length(); j > i; j--) { 
			string sub_str = str.substr(i, j); 
			st.insert(sub_str); 

			for (int k = 1; k < sub_str.length() - 1; k++) { 
				string sb = sub_str; 

				sb.erase(sb.begin() + k); 
				subsequence(sb); 
			} 
		} 
	} 
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		st.clear();
		string s;
		int x0, y0, x1, y1, Q;
		map<ii, int> min_road;
		cin >> s >> x0 >> y0 >> Q;
		subsequence(s);

		for(string road : st){
			int x_n, y_n;
			x_n = x0;
			y_n = y0;
			for(auto c : road){
				if (c == 'R'){
					x_n++;
				}
				else if (c == 'L'){
					x_n--;
				}
				else if (c == 'U'){
					y_n++;
				}
				else if (c == 'D'){
					y_n--;
				}
			}
			ii prs = {x_n, y_n};
			if (min_road.count(prs)) {
				int r_size = min_road[prs];
				/*if (prs.first == 2 and prs.second == 3){
					cout << "X: " << x_n << ", Y: " << y_n << endl;
					cout << road << endl;
					cout << "RS: " << (int)road.size() << endl;
				}*/

				min_road[prs] = min((int)road.size(), r_size);
			}
			else
				min_road[prs] = road.size();
		}

		for (int i = 0;i < Q;i++) {
			cin >> x1 >> y1;
			ii prs = {x1, y1};

			if (min_road.count(prs)){
				cout << "YES " << min_road[prs] << endl; 
			}
			else 
				cout << "NO" << endl;

		}
	}
	return 0;
}
