#include "bits/stdc++.h"

using namespace std;


int main() {
	int n;
	vector<pair<int, char>> vits;
	cin >> n;

	for(int i = 0;i < n;i++){
		char val = 0;
		int p;
		string vit;

		cin >> p;
		cin >> vit;

		if (vit.find("A") != string::npos){
			val |= 1;	
		}
		if (vit.find("B") != string::npos){
			val |= (1<<1);;	
		}
		if (vit.find("C") != string::npos){
			val |= (1<<2);;	
		}

		pair<int, char> pp = {p, val};
		vits.push_back(pp);
	}

	sort(vits.begin(), vits.end());

	char to_fill = 0;
	int price = 0;
	for(int i = 0;i < vits.size();i++){
		pair<int, char> pp1 = vits[i];


		if (not (to_fill & 1) and (bt_set & 1)){ // Pick A
			to_fill |= bt_set;		
			price += val;
			cout << "Added A" << endl;
		}

		if (not (to_fill & (1 << 1)) and (bt_set & (1 << 1) )){ // Pick B
			to_fill |= bt_set; 
			price += val;
			cout << "Added B" << endl;
		}

		if (not (to_fill & (1 << 2) ) and (bt_set & (1 << 2) )){ // Pick C
			to_fill |= bt_set;
			price += val;
			cout << "Added C" << endl;
		}
		if ((to_fill & 1) and (to_fill & (1 << 1) ) and (to_fill & (1 << 2) ))
			break;
		cout << price << endl << endl;
	}

	if (not (to_fill & 1) or not (to_fill & (1 << 1) ) or not (to_fill & (1 << 2)) )
		cout << -1 << "\n";
	else
		cout << price << "\n";

	return 0;
}
