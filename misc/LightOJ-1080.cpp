#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;
const int MAXN = 1e5+5;

int n;
bool num[MAXN];
char digits[MAXN];

struct BIT {
private:
	vi vec;
	int n;

public:
	BIT(int nn){
		this->n = nn+5;
		vec.assign(this->n, 0);
	}

	BIT(vi arr) : BIT(arr.size()){
		for(int i = 0;i < arr.size();i++) {
			add(i, arr[i]);
		}
	}


	void add(int i, int diff){
		for(;i < n;i = i | (i+1))
			vec[i] += diff;
	}

	int sum (int a){
		int ret = 0;
		for(;a >= 0;a = (a & (a+1) )-1)
			ret += vec[a];
		return ret;
	}

	void range_add(int l, int r, int val){
		add(l, val);
		add(r + 1, -val);
	}

	int query(int a, int b){
		return sum(b) - sum(a-1);
	}
};

int main(){
	int t;
	scanf("%d", &t);
	int curr = 1;
	while(t--){
		vector<int> ans;
    int q;
		scanf("%s\n", digits);
		scanf("%d\n", &q);

		n = strlen(digits);
		BIT b1(n);

		for(int i = 0;i < q;i++){
			char c;
			scanf(" %c ", &c);
			if (c == 'Q'){
				int q_bit;
				scanf("%d", &q_bit);
				--q_bit;
				int res = b1.sum(q_bit);
				bool curr_ans;
				if (res & 1)
					curr_ans = not ((int)(digits[q_bit] - '0'));
				else
					curr_ans = ((int)(digits[q_bit] - '0'));
				ans.push_back(curr_ans);
			} else {
				int l, r;
				scanf(" %d ", &l);
				scanf(" %d ", &r);
				--l;--r;
				b1.range_add(l, r, 1);
			}
		}

		printf("Case %d:\n", curr);
		for(auto curr_a : ans){
			printf("%d\n", curr_a);	
		}
		curr++;
	}
	return 0;
}
