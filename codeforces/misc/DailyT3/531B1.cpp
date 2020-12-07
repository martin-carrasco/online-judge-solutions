#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int n, m;


int f(vector<int>& p){
	int total = 0;
	for(int i = 0;i < p.size();i++){
		for(int j = i;j < p.size();j++){
			total += *min_element(p.begin() + i, p.begin() + j + 1);
		}
	}
	return total;
}

int main() {
	cin >> n >> m;
	vector<int> nums;
	vector<vector<int>> ps;

	for(int i = 1;i <= n;i++)
		nums.push_back(i);

	sort(nums.begin(), nums.end());
	int max_sum = 0;

	do {
			int curr_sum = f(nums);
			if (curr_sum > max_sum)
				max_sum = curr_sum;
	}
	while(next_permutation(nums.begin(), nums.end()));


	do {
			if (f(nums) == max_sum)
				ps.push_back(nums);
	}while(next_permutation(nums.begin(), nums.end()));

	for(auto& nu : ps[m-1]){
		cout << nu << " ";
	} 
	cout << endl;
	return 0;
}
