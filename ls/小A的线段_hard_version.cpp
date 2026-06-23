#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

struct xd
{
    int l,r;
}x[N];

vector<int>lsh;

bool cmp(xd a, xd b) {
    if(a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

int dp[210][410][410];

void add(int &a, int b) {
    a += b;
    if(a > mod) a-=mod;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> x[i].l >> x[i].r;
        // x[i].l --;
        lsh.push_back(x[i].l - 1);
        lsh.push_back(x[i].l);
        lsh.push_back(x[i].r);
    }

    sort(x + 1, x + m + 1, cmp);
    lsh.push_back(0), lsh.push_back(n);
    sort(lsh.begin(), lsh.end());
    lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());

    n = lsh.size();

    for(int i = 1; i <= m; i ++) {
        x[i].l = lower_bound(lsh.begin(), lsh.end(), x[i].l) - lsh.begin();
        x[i].r = lower_bound(lsh.begin(), lsh.end(), x[i].r) - lsh.begin();
    }
    // memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 1;

    for(int i = 1; i <= m; i ++) {
        for(int j = 0; j < n; j ++) {
            for(int k = 0; k < n; k ++) {
                if(dp[i - 1][j][k] == 0) continue;
               
                add(dp[i][j][k] , dp[i - 1][j][k]);
                if(x[i].l - 1 <= j ) {
                    add(dp[i][max(j, min(k, x[i].r))][max(k, x[i].r)],dp[i - 1][j][k]);
                }
            }
        }
    }

    // for(int k = 1; k <= m; k ++) {
    //     for(int i = 0; i < n; i ++) {
    //         for(int j = 0; j < n; j ++) {
    //             if(dp[k - 1][i][j] == 0) continue;
    //             add(dp[k][i][j], dp[k - 1][i][j]);
               
    //             if (x[k].l <= i) {
    //                 cout << x[k].l << " " <<  i << endl; 
    //                 add(dp[k][ max(i, min(j, x[k].r)) ][max(j, x[k].r)], dp[k - 1][i][j]);
    //             }
    //         }
    //     }
    // }



    cout << dp[m][n - 1][n - 1] << endl;







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