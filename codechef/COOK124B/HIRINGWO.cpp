#include "bits/stdc++.h"

using namespace std;
const int MAXN = 1e6;
const int MAXV = 1e3;
long long k, x;

deque<long long> trial_division1(long long n) {
    deque<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		multiset<long long> nums;
		cin >> k >> x;
		auto factors = trial_division1(x);
		for(auto ele : factors){
			nums.insert(ele);
		}

		long long ans = 0;
		while(nums.size() > k){
			long long tmp = *nums.begin();
			nums.erase(nums.begin());
			tmp *= (*nums.begin());
			nums.erase(nums.begin());
			nums.insert(tmp);
		}
		for(auto it = nums.begin(); it != nums.end();it++){
			auto current_num = *it;	
			//cout << "factor: " << current_num << "\n";
			ans += current_num;
		}
		if (nums.size() < k){
			ans += (long long)k-nums.size();
		}
		cout << ans << "\n";
	}

	return 0;
}
