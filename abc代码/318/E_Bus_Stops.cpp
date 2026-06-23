#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int p[N], t[N];
int ans[N];
int n, x, y;

int mn(int T) {
    for(int i = 1; i < n; i++) {
        int T2 = T % p[i];
        if (T2 == 0) {
            T2 = p[i];
        }

        T += p[i] - T2;
        T+=t[i];
    }
    return T;
}



void solve()
{

    cin >> n >> x >> y;

    int T =  1;
    for (int  i = 1;i < n;i ++ ) {
        cin >> p[i] >> t[i];
        T = p[i] * T / __gcd(p[i],T);
    }

    for(int i = 0; i < T; i++) {
        ans[i] = mn(i);
       // cout << ans[i] << endl;
    }

    int q; cin >> q;
    while(q--) {
        int cf;
        cin >> cf;
        cout <<  y + ans[(cf + x)%T] + (cf + x)/T*T << endl;
    }
    // cout << t << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}