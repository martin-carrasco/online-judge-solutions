#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int p, f, cnt_s, cnt_w, w_s, w_w;
		cin >> p >> f >> cnt_s >> cnt_w >> w_s >> w_w;

		int amount = 0;

		int max_amount_me = 0;
		for (int i = 0;i <= cnt_s;i++){
			int current_amount = i;
			int current_p = p - (w_s * i);
			int current_f = f;
			int sword_amount = cnt_s - i;
			int axe_amount = cnt_w;

			if (current_p < 0)
				break;
			
			int axe_take = min((int)floor(current_p / w_w), axe_amount);
			current_p -= axe_take * w_w;
			axe_amount -= axe_take;
			current_amount += axe_take;

			int cheap_c, cheap_a, exp_c, exp_a;
			cheap_c = w_w < w_s ? w_w : w_s; 
			cheap_a = w_w < w_s  ? axe_amount : sword_amount;

			exp_c = w_w < w_s ? w_s : w_w;
			exp_a = w_w < w_s ? sword_amount : axe_amount;

			int cheap_take = min((int)floor(current_f / cheap_c), cheap_a);
			current_f -= cheap_take * cheap_c;
			current_amount += cheap_take;


			int exp_take = min( (int)floor(current_f / exp_c), exp_a);
			current_amount += exp_take;

			if (current_amount > max_amount_me){
				max_amount_me = current_amount;
			}
		}

		cout << max_amount_me << "\n";
	}
	return 0;
}
