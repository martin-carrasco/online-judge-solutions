#include "bits/stdc++.h"
 
using namespace std;
using vi = vector<int>;
 
const int MAXN = 1e5 + 5;
 
int a[MAXN]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for(int i = 0;i < n;i++){
		cin >> a[i];
	}

	sort(a, a+n);

	int num = max((int)ceil((n-2)*1.0 / 2), 0);


	cout << num << "\n";
	if (n < 3){
		for(int i = 0;i < n;i++)
			cout << a[i] << " ";
		cout << "\n";
		return 0;
	}

	cout <<  a[n-2] << " ";
	int i = 0; 
	int j = n-3;

	do{
			
			if (i != j)
				cout << a[i] << " " << a[j] << " ";
			else
				cout << a[i] << " ";
			i++;
			j--;
	}
	while(i <= j);

	cout << a[n-1] << " " << "\n";
		
	return 0;
}
