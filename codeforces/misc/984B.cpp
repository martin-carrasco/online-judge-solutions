#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100 + 5;

int n, m;
char mt[MAXN][MAXN];


bool val_pos(int i, int j, int num){
	int cnt = 0;
	for(int x : {i-1, i, i+1}){
		for(int y : {j-1, j, j+1}){
			if(x < 0 or x >= n or y < 0 or y >= m) continue;
			if(mt[x][y] == '*')
				cnt++;
		}
	}
	return cnt == num;
}

bool check(){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if (mt[i][j] == '*') continue;
			if (not val_pos(i, j, mt[i][j] - '0'))
				return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;
			cin >> c;
			if (c == '.')
				mt[i][j] = '0';
			else
				mt[i][j] = c;
		}
	}

	if(check())
		cout << "YES";
	else
		cout << "NO";
	cout << "\n";

	return 0;
}
