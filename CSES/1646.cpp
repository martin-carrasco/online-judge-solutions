#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using viii = vector<iii>;
using vll = vector<tuple<ll, ll, ll>>;


template <class T>
struct BIT {
private:
	vector<T> vec;
	vector<T> bit;
	int n;

public:
	BIT(int n){
		this->n = n + 1;
		vec.assign(n, T{});
		bit.assign(n, T{}); 
	}

	BIT(vector<T> arr) : BIT(arr.size()){
		for(int i = 0;i < arr.size();i++) {
			add(i, arr[i]);
			bit[i] = arr[i];
		}
	}

	void add(int i, T diff){
		for(++i;i < n;i += i & -i)
			vec[i] += diff;
	}

	void update(int i, T val){
		add(i, val - bit[i]);
		bit[i] =  val;
	}

	T sum (int a){
		T ret = 0;
		for(++a;a > 0;a -= a & -a)
			ret += vec[a];
		return ret;
	}

	T query(int a, int b){
		return sum(b) - sum(a-1);
	}

};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vii queries;
	int n, q;
	cin >> n >> q;

	vector<ll> arr(n, 0);

	for (int i = 0;i < n;i++) cin >> arr[i];

	BIT<ll> tree(arr);

	for(int i = 0;i < q;i++){
		int a,b;
		cin >> a >> b;
		--a;
		--b;

		queries.push_back({a, b});
	}


	for(auto [a, b] : queries){
		cout << tree.query(a, b) << "\n";
	}

	return 0;
}
