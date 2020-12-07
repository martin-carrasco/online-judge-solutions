#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using di = deque<int>;
using ii = pair<int,int>;
using pll = pair<ll, ll>;
using ordered_set =  tree<
												pll,
												null_type,
												less<pll>,
												rb_tree_tag,
												tree_order_statistics_node_update>;
const int MAXN = 1e6;


void print_deque(di& d){
	for(int i = 0;i < d.size();i++)
		cout << d[i] << " ";
	cout << endl;
}
int a[MAXN];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ordered_set nums;
		vector<pair<ll,ll>> steps;
		ll id = 0;
		for(ll i = 1;i <=n;i++) nums.insert({i, id++});

		while(nums.size() > 1){
			auto last_ele_it = nums.end();
			--last_ele_it;
			ll last_ele = last_ele_it->first;

			auto pos_it =	last_ele_it;
			--pos_it;
			ll mid_ele = pos_it->first;
			ll lost_iter = pos_it->second;

			ll new_num = (mid_ele + last_ele);
			new_num = new_num % 2 == 1 ? (new_num+1) / 2 : new_num/2; 

			nums.erase(pos_it);
			nums.erase(last_ele_it);

			nums.insert({new_num, id++});
			steps.push_back({mid_ele, last_ele});
		}

		cout << nums.begin()->first << "\n";
		for(auto step : steps){
			cout << step.first << " " << step.second << "\n";
		}
	}

	return 0;
}

