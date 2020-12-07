#include "bits/stdc++.h"

using namespace std;
const int MXN = 5;
long long ans = 0;
long long a[MXN];
int main(){
   for (int i = 0; i < 3; ++i) cin>>a[i];
   sort (a, a + 3);
   if (a[1] - a[0] > 1) {
       ans += a[1] - a[0] - 1;
    a[0] += ans;
   }
   if (a[2] - a[1] > 1) {
       ans += a[2] - a[1] - 1;
    a[1] += a[2] - a[1] - 1; 
   }
   if (a[2] - a[0] > 1) {
       ans += a[2] - a[0] - 1;
   }
    cout<<ans;
	return 0;
}
