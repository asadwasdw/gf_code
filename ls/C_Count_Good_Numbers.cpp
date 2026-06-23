#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int p[] = {2, 3, 5, 7};

ll calc(ll x) {
    ll res = x;

    for(ll st = 1; st < (1 << 4); st ++)  {
        int cnt = 0;
        ll mul = 1;
        for(int i = 0; i < 4; i ++) {
            if((st >> i) & 1) {
                mul *= p[i];
                cnt ++;
            }
        }
        ll t = x / mul;
        if(cnt % 2 == 1) res -= t;
        else res += t;
    }

    return res;
}

void solve()
{

    ll l, r;
    cin >> l >> r;
    cout << calc(r) -  calc(l - 1) << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}