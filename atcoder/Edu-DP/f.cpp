#include "bits/stdc++.h"
#include <string>

using namespace std; 

int n1, n2;
short dp[3001][3001];
char bt[3001][3001];

int main() {
	char a[3000], b[3000];
	cin >> a;
	cin >> b;
	n1 = strlen(a);
	n2 = strlen(b);

		
	for(int i = 0; i <= n1;i++){
		for(int j = 0;j <= n2;j++){
			if (i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else{
				if (dp[i-1][j] > dp[i][j-1]){
					bt[i][j] = 0;
					dp[i][j] = dp[i-1][j];
				}
				else{
					bt[i][j] = 1;
					dp[i][j] = dp[i][j-1];
				}

				if(a[i-1] == b[j-1]) {
					if (dp[i-1][j-1] + 1 > dp[i][j]) {
						dp[i][j] = dp[i -1][j -1] + 1;
						bt[i][j] = 2;
					} 
				}

			}
		}
	}

	int answer = dp[n1][n2];

	if (answer < 1){
		cout << "";
		return 0;
	}

	vector<char> res;
	int i = n1;
	int j = n2;
	while(i > 0 && j > 0){
		if (bt[i][j] == 0){
			i--;
		}
		else if (bt[i][j] == 1){
			j--;
		}
		else if (bt[i][j] == 2){
			res.push_back(a[i-1]);
			i--;
			j--;
		}	
	}
	reverse(res.begin(), res.end());
	for(auto c : res){
		cout << c;
	}
	return 0;
}
