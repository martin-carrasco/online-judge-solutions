#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAX_N = 100 + 5;
int n;

bool a[MAX_N][MAX_N];
bool t[MAX_N][MAX_N];

int count_clean(){
	int count = 0;
	for(int i = 0;i < n;i++){
		bool clean = true;
		for(int j = 0;j < n;j++){
			if (not t[i][j]){
				clean = false;
				break;
			}
		}
		if (clean)
			count++;
	}
	return count;
}
int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		string s;
		cin >> s;
		for(int j = 0;j < s.size();j++){
			const char& c = s[j];
			a[i][j] = c - '0';
		}
	}


	int max_clean = 0;
	for(int i = 0;i < n;i++){
		memcpy(t, a, sizeof(a));
		for(int j = 0;j < n;j++){
			if (not t[i][j]){
				for(int k = 0;k < n;k++){
					t[k][j] = not t[k][j];
				}
			}
		}
		max_clean = max(count_clean(), max_clean);
	}
	cout << max_clean << "\n";

		
	return 0;
}

