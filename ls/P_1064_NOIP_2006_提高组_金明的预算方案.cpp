#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define v first
#define w second

//vector<vector<int>>adj(N);
typedef pair<int,int>PII;
PII a[65];
vector<PII> b[65];
int dp[N];


void solve()
{
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= n; i ++) {
        int v, w, t;
        cin >> v >> w >> t;
        w *= v;

        if(t == 0) {
            a[i] = {v, w};
        } else {
            b[t].push_back({v, w});
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= 0; j --) {
            for(int t = 0; t < 1<<b[i].size(); t ++) {
                int v = a[i].v, w = a[i].w;
                for(int k = 0; k < b[i].size(); k ++) {
                    if(t >> k & 1) {
                        v += b[i][k].v;
                        w += b[i][k].w;
                    }
                }

                if(j >= v)dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }

    cout << dp[m];
}


void solve2() {
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= n; i ++) {
        int v, w, t;
        cin >> v >> w >> t;
        w *= v;

        if(t == 0) {
            a[i] = {v, w};
        } else {
            b[t].push_back({v, w});
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= 0; j --) {

            if(j >= a[i].v) dp[j] = max(dp[j],dp[j - a[i].v] + a[i].w);

            if(b[i].size() >= 1) {
                if(j >= a[i].v + b[i][0].v) dp[j] = max(dp[j],dp[j - (a[i].v + b[i][0].v)] + a[i].w + b[i][0].w);
            }

            if(b[i].size() >= 2) {
                if(j >= a[i].v + b[i][1].v) dp[j] = max(dp[j],dp[j - (a[i].v + b[i][1].v)] + a[i].w + b[i][1].w);
                if(j >= a[i].v + b[i][0].v + b[i][1].v) dp[j] = max(dp[j],dp[j - (a[i].v + b[i][0].v + b[i][1].v)] + a[i].w + b[i][0].w + + b[i][1].w);
            }
        }
    }

    cout << dp[m];
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
        solve2();
    }
    return 0;
}