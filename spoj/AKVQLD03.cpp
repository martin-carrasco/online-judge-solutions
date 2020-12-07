#include "bits/stdc++.h"

using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	FenwickTree t(n);

	while(q--){
		string qr;
		string tmp;
		string op;
		int arg1, arg2;
		cin >> qr;

		stringstream ss(qr);
		getline(ss, op, " ");
		getline(ss, tmp, " ");
		arg1 = stoi(tmp);
		getline(ss, tmp, "\n");
		arg2 = stoi(tmp);


		cout << op << endl;
		cout << arg1 << endl;
		cout << arg2 << endl;

		if (qr == "add")
			t.add(arg2-1, arg1);
		else{
			cout << t.sum(arg1-1, arg2-1) << "\n";
		}
		

	}
	return 0;
}
