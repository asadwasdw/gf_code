#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

vector<PII>a,b;

void solve()
{
    int n,m;
    scanf("%d\n",&n);
    for(int i = 1; i <= n; i ++){
        int h,m,s,wa;
        scanf("%d:%d:%d %d\n",&h, &m, &s, &wa);
        a.push_back({h * 3600 + m * 60 + s,h * 3600 + m * 60 + s + wa * 20 * 60});
    }
    scanf("%d\n",&m);

    for(int i = 1; i <= m; i ++){
        int h,m,s,wa;
        scanf("%d:%d:%d %d\n",&h, &m, &s, &wa);
        b.push_back({h * 3600 + m * 60 + s ,h * 3600 + m * 60 + s + wa * 20 * 60});
    }

    bool ky = false;
    int ta = 0,cnta = 0, tb = 0,cntb = 0;

    for(int i = 0; i < 2e4; i ++ ) {
        while(cnta < (int)(a.size()) && i == a[cnta].first) {
            ta += a[cnta].second;
            cnta ++;
        }

        while(cntb < (int)(b.size()) && i == b[cntb].first) {
            tb += b[cntb].second;
            cntb ++;
        }

        if(cnta > cntb) ky = true;
        else if(cnta == cntb && ta < tb) ky = true;
    }
    // cout << cnta << ' ' << cntb << endl;

    if(ky) cout << "Yes";
    else cout << "No\n";

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}