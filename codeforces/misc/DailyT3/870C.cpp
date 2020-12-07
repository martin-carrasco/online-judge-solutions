#include <bits/stdc++.h> 

using namespace std; 
  
const int maxn = 16; 
  
vector<int> precompute()  { 
    vector<int> dp(maxn, -1); 
    dp[0] = 0; 
  
    for (int i = 1; i < maxn; ++i) { 
  
        for (auto j : vector<int>{ 4, 6, 9 }) { 
  
            if (i >= j && dp[i - j] != -1) { 
                dp[i] = max(dp[i], dp[i - j] + 1); 
            } 
        } 
    } 
  
    return dp; 
} 
  
int max_summand(vector<int> dp, int n) 
{ 
    if (n < maxn) 
        return dp[n]; 
  
    else { 
        int t = (n - maxn) / 4 + 1; 
        return t + dp[n - 4 * t]; 
    } 
} 
  
int main() { 
	int q;
	cin >> q;
	
	vector<int> dp = precompute(); 

	while(q--){
		int n;
		cin >> n;

		cout << max_summand(dp, n) << endl; 

	}
	return 0; 
} 
