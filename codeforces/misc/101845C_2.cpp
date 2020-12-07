#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int MAXN = 200;
ll d[MAXN][MAXN];
string no_encr, encr;
int m;

int main(){

    cin >> no_encr;
    cin >> encr;
    cin >> m;

    for(int i = 33;i <= 126;i++){
        for(int j = 33;j <= 126;j++){
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = numeric_limits<ll>::max();    
        }
    }
    
    for(int i = 0;i < m;i++){
        char src_c, dst_c;
        int src, dst;
        ll w;
        cin >> src_c;
        cin >> dst_c;
        cin >> w;

        src = (int)src_c;
        dst = (int)dst_c;

        d[src][dst] = min(w, d[src][dst]);
    }



    for(int k = 33;k <= 126;k++){
        for(int i = 33;i <= 126;i++){
            for(int j = 33;j <= 126;j++){
                if (d[i][k] < numeric_limits<ll>::max() and d[k][j] < numeric_limits<ll>::max()) 
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    ll cnt = 0;
    for(int i = 0;i < no_encr.size();i++){
        char norm_c = no_encr[i];
        char enc_c = encr[i];


        int src, dst;
        src = (int)norm_c;
        dst = (int)enc_c;
        ll c_cost = d[src][dst];

        if (c_cost == numeric_limits<ll>::max()) {
            cnt = -1;
            break;
        }
        cnt += c_cost;
    }
    cout << cnt << "\n";

    return 0;
}
