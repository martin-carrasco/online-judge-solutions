#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;

const int MAXN = 8;
int n = 8;


bool board[8][8];
bool col[MAXN], diag1[MAXN], diag2[MAXN];


int cnt = 0;

void solve(int i){

	if (i == n){
		cnt++;
		return;
	}

	for(int j = 0;j < n;j++){
		if (col[j] or diag1[i+j] or  diag2[i - j + n - 1] or board[i][j]) { continue;}
		col[j] = diag1[i+j] = diag2[i-j + n -1] = 1;
		solve(i+1);
		col[j] = diag1[i+j] = diag2[i-j + n -1] = 0;
	}
}

int main(){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			char c;
			cin >> c;
			board[i][j] = c == '*';
		}
	}

	solve(0);

	cout << cnt << "\n";
	return 0;
}
