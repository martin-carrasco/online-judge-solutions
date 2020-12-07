#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        bool f=0;
        if(str.size()%2!=1)
        {
            for(int i=1; i<n; i+=2)
            {
                if((str[i]-'0')%2==0)f=1;

            }
            f=1-f;

        }
        else
        {
            for(int i=0; i<n; i+=2)
                if((str[i]-'0')%2==1)
                    f=1;
        }
        if(!f)cout<<2<<endl;
        else cout<<1<<endl;
    }
    return 0;

}
