#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int x, y;
    cin >> x >> y;
    int mn = INF, ansp, ansq;

    {
        int p = x, q = 0;
        int dp[35][2] = {0};

        for(int i = 30; i >= 0; i --) {
            for(int j = 0; j < 2; j ++) {
                if(j && (p >> i) & 1) continue;
            }
        }

    }






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
    return 0;
}