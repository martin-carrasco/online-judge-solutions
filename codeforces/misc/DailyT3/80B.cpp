#include "bits/stdc++.h" 
using namespace std;

const int DEG_HOUR = 30;

int main(){
	int h, m;
	char c;
	cin >> h >>  c >> m;


	h = h % 12;
	double move_hour = DEG_HOUR * h + ((static_cast<double>(m) / 60) * DEG_HOUR);
	double move_minute = (static_cast<double>(m) / 5) * DEG_HOUR;


	cout << move_hour << " " << move_minute;
	return 0;
}
