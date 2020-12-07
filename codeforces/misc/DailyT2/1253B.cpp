#include "bits/stdc++.h"

using namespace std;
using vi = vector<int>;

const int MAXN = 1e5 + 5;
int a[MAXN];

int main(){
	int n;
	cin >> n;
	vi ans;
	
	set<int> in_office;
	set<int> seen;
	for(int i = 0;i < n;i++)
		cin >> a[i];


	bool start = true;
	int last_split = 0;
	for(int i = 0;i < n;i++){
		int emp = abs(a[i]);
		bool enter = a[i] > 0;

		if ((enter and in_office.count(emp)) or (not enter and not in_office.count(emp))) {
			cout << -1 << "\n";
			return 0;
		}

		if (not enter and in_office.size() == 1){
			ans.push_back(i+1-last_split);
			last_split = i+1;
			in_office.clear();
			seen.clear();
			start = true;
			continue;
		}
		
		if (enter)	{
			in_office.insert(emp);
			if (seen.count(emp)){
				cout << -1 << "\n";
				return 0;
			}
			seen.insert(emp);
		}
		else
			in_office.erase(emp);

		start = false;
	}
	if (in_office.size() > 0) {
		cout << -1 << "\n";
		return 0;
	}
	cout << ans.size() << "\n";
	for (auto d : ans)
		cout << d << " ";
	cout << "\n";

	return 0;
}
