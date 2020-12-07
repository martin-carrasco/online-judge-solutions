
#include <bits/stdc++.h> 
using namespace std; 
using ii = pair<int, int>;
const int MAXN = 1e6;

int n;
ii a[MAXN];

int dist() { 
    map<int, int> X; 
    map<int, int> Y; 
  
    map<ii, int> XY; 
    for (int i = 0; i < n; i++) { 
			int xi = a[i].first; 
			int yi = a[i].second; 

			X[xi]++; 
			Y[yi]++; 
			XY[a[i]]++; 
    } 
  
    int xAns = 0, yAns = 0, xyAns = 0; 
  
    for (auto xCoordinatePair : X) { 
			int xFrequency = xCoordinatePair.second; 
  
			int sameXPairs =  
					 (xFrequency * (xFrequency - 1)) / 2; 
			xAns += sameXPairs; 
    } 
  
    for (auto yCoordinatePair : Y) { 
			int yFrequency = yCoordinatePair.second; 
  
			int sameYPairs = 
                (yFrequency * (yFrequency - 1)) / 2; 
        yAns += sameYPairs; 
    } 
  
    for (auto XYPair : XY) { 
        int xyFrequency = XYPair.second; 
   
        int samePointPairs =  
             (xyFrequency * (xyFrequency - 1)) / 2; 
        xyAns += samePointPairs; 
    } 
  
    return (xAns + yAns - xyAns); 
} 
int main() { 
	cin >> n;

	for(int i = 0;i < n;i++){
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}
  
	cout << dist() << "\n";
	return 0; 
} 
