#include<bits/stdc++.h> 
using namespace std;  
vector<int>num;
int abs(int x,int y){
	int f=x-y;
	if(f<0){
		f*=-1;
	}
	return f;
}
int main(){ 
int menge,nummer,test;
cin>>test;
string s;
for(int t=0;t<test;t++){
	cin>>menge;
	int maxi=0,mini=INT_MAX;
	for(int i=0;i<menge;i++){
		int numm;
		cin>>numm;
		num.push_back(numm);
		maxi=max(maxi,numm);
		mini=min(numm,mini);
	}
	if(maxi==mini){
		cout<<-1<<"\n";
		num.clear();
		continue;
	}
	for(int i=0;i<menge;i++){
		if(num[i]==maxi){
			if(i>0){
				if(num[i-1]<num[i]){
					cout<<i+1<<"\n";
					break;
				}
			}
			if(i<num.size()-1){
				if(num[i+1]<num[i]){
					cout<<i+1<<"\n";
					break;
				}
			}
		}
	}
	num.clear();
	
}
return 0;

}
