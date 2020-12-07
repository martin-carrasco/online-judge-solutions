#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 1e6;
bool vis[10];
bool seen[MAXN];
ll n;
ll perm = 0;
vector<ll> digits;

vector<ll> calc_factors(){
	vector<ll> vec;
	for(ll i = 2;i <= 9;i++){
		if (n % i == 0)
			vec.push_back(i);
	}
	return vec;
}


int is_valid(){
	if (seen[perm]) return 3;
	ll total = 1;
	for(auto dig : digits){
		total *= dig;
	}
	/*cout << "total: " << total << "\n";
	cout << "perm: " << perm << "\n";
	cout << "valid: " << (total == n) << "\n";
	cout << "\n";*/
	seen[perm] = 1;
	if (total == n)
		return 1;
	else if(total < n)
		return 0;
	else
		return 2;
}
ll count_permutations(vector<ll>& nums, int pos){
	ll count_valid = 0;
	if (perm > 1e6)
		return count_valid;

	int valid_seq = is_valid();
	if (valid_seq == 1) {
		count_valid++;
	}
	else if(valid_seq == 2)
		return count_valid;

	for(int i = 0;i < nums.size();i++){
		if (vis[i]) continue;
		ll next_pe = pow(10, pos-1) * nums[i];

		perm += next_pe; 	
		digits.push_back(nums[i]);
		count_valid += count_permutations(nums, pos+1);
		perm -= next_pe;
		digits.pop_back();

		perm += next_pe;
		digits.push_back(nums[i]);
		vis[i] = 1;
		count_valid += count_permutations(nums, pos+1);
		perm -=  next_pe;
		vis[i] = 0;
		digits.pop_back();

	}
	return count_valid;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<ll> factors = calc_factors();


	int cnt_special = count_permutations(factors, 1);
	factors.push_back(1LL);
	int cnt_pspecial = count_permutations(factors, 1);
		
	cout << cnt_special << " " << cnt_pspecial << "\n";
}

