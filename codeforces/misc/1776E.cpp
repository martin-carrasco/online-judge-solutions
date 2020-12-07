#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e6;

int a[MAXN];

int main(){
	int n;
	cin >> n;
	for(int i = 0;i <n;i++)
		cin >> a[i];

	int cnt_4 = 0;
	int cnt_8 = 0;
	int cnt_15 = 0;
	int cnt_16 = 0;
	int cnt_23 = 0;
	int cnt_42 = 0;

	for(int i = 0; i < n;i++){
		if (a[i] == 4){
			cnt_4++;
		} else if (a[i] == 8 && cnt_4 > cnt_8){
				cnt_8++;
		} else if (a[i] == 15 && cnt_8 > cnt_15){
				cnt_15++;
		}else if (a[i] == 16 && cnt_15 > cnt_16){
				cnt_16++;
		}else if (a[i] == 23 && cnt_16 > cnt_23){
				cnt_23++;
		} else if (a[i] == 42 && cnt_23 > cnt_42) {
				cnt_42++;
		}
	}
	
	int comp = cnt_42;

	int mn_rem = n - comp * 6;

	cout << mn_rem << "\n";

	return 0;
}
