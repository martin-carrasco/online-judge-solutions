#include "bits/stdc++.h"

using namespace std;


const int MAX_NUM = 1e3 +5;
int a[MAX_NUM];

int main() {
	int n;
	vector<int> n1;
	vector<int> n2;
	vector<int> n3;
	cin >> n;
	bool z_p = false;	
	int count_neg = 0;

	for (int i = 0;i < n;i++){
		cin >> a[i];
		if (a[i] < 0)
			count_neg++;
	}
	if (count_neg & 1){
		int max_pos = count_neg-1;
		for (int i = 0;i <n;i++){
			int& t = a[i];
			if (t > 0) 
				n2.push_back(t);
			else if (t == 0)
				n3.push_back(t);
			else if  (max_pos > 0) {
				n2.push_back(t);
				max_pos--;
			}
			else
				n1.push_back(t);
		}
	} else {
		bool odd = false;
		int max_pos = count_neg -2;
		for (int i = 0;i <n;i++){
			int& t = a[i];
			if (t > 0) 
				n2.push_back(t);
			else if (t == 0)
				n3.push_back(t);
			else if  (not odd){
				n3.push_back(t);
				odd = true;
			}
			else if  (max_pos > 0) {
				n2.push_back(t);
				max_pos--;
			}
			else
				n1.push_back(t);
		}
	}
	cout << n1.size() << " ";
	for (auto& v : n1)
		cout << v << " ";
	cout << endl;
	
	cout << n2.size() << " ";
	for (auto& v : n2)
		cout << v << " ";
	cout << endl;

	cout << n3.size() << " ";
	for (auto& v : n3)
		cout << v << " ";
	cout << endl;
	return 0;
}
