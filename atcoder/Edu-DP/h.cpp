#include "bits/stdc++.h"

using namespace std;
const int MAX_L = 1e3 + 5;
const int mod = 1e9 + 7;
int W, H;
char m[MAX_L+1][MAX_L+1];
int dp[MAX_L+1][MAX_L+1];

void add_self(int& a, int  b){
	a+= b;
	if(a >= mod)
		a -= mod;

}

int main() {
	cin >> H >> W;

	for (int x = 0; x < H;x++){
		for (int y = 0;y < W;y++){
			cin >> m[x][y];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < H;i++){
		for (int j = 0;j < W;j++){
			for(int r : {i, i +1} ){
				int c = j;
				if (r ==  i)
					c +=1;
				if (r < H and c < W and m[r][c] == '.')
					add_self(dp[r][c], dp[i][j]);
			}
		}
	}

	cout << dp[H-1][W-1];
	return 0;
}
