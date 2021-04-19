#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
using ll = long long;

const int MAXN = 300000 + 5;

vi arr_s;
struct BIT {
private:
	vector<int> vec;
	vector<int> bit;
	int n;

public:
	BIT(int n){
		this->n = n;
		vec.assign(n, 0);
		bit.assign(n, 0); 
	}

	BIT(vector<int> arr) : BIT(arr.size()){
		for(int i = 0;i < arr.size();i++) {
			add(i, arr[i]);
			bit[i] = arr[i];
		}
	}

	void add(int i, int diff){
		for(;i < n;i |= (i+1))
			vec[i] ^= diff;
	}

	void update(int i, int val){
		add(i, val - bit[i]);
		bit[i] =  val;
	}

	int sum (int a){
		int ret = 0;
		for(;a >= 0;a = (a & (a+1))-1)
			ret ^= vec[a];
		return ret;
	}

	int query(int a, int b){
		return sum(b) ^ sum(a-1);
	}
};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;

	cin >> n >> q;

	for(int i = 0;i < n;i++){
		int val;
		cin >> val;
		arr_s.push_back(val);
	}
	BIT bit(arr_s);
	while(q--){
		int ti, x, y;
		cin >> ti >> x >> y;
		--x;
		--y;
		if (ti == 1){
			bit.add(x, (y+1));
		} else {
			cout << bit.query(x, y) << "\n";
		}
	}

	return 0;
}
