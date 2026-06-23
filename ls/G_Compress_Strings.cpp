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
typedef unsigned long long ull;
ull p = 13331;
ull P[N];
vector<ull> h[30];
string s[30];
int f[30][30];

int dp[1<<21][21];
ull get(int a,int l,int r) {
    return h[a][r]-h[a][l-1]*P[r-l+1];
}


void solve()
{
    int n;cin>>n;
    P[0]=1;
    for(int i=1;i<=2e5;i++) {
        P[i]=P[i-1]*p;
    }
    for(int i=1;i<=n;i++) {
        cin >> s[i];
        int sum = s[i].size();
        s[i]=' '+s[i];
        h[i].resize(sum+1);
        for(int j=1;j<=sum;j++) {
            h[i][j] = h[i][j-1]*p + s[i][j] - 'a' + 1;
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<h[i].size();j++){
    //         cout<<h[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1;i<=n;i++)   
        for(int j=1;j<=n;j++) {
            if(i==j)continue;
            bool ok = false;
            int sum1 = s[i].size()-1;
            int sum2 = s[j].size()-1;
            if(sum1>=sum2) {
                for(int k = 1; k + sum2-1<=sum1;k++) {
                    if(get(i,k,k+sum2-1) == get(j,1,sum2)) {
                        f[i][j] = sum2;
                        ok=true;
                        break;
                    }
                }
            }
            if(ok) continue;

            for(int cnt = 1;cnt<=min(sum1,sum2);cnt++) {
                // cout<<cnt<<" "<<get(i,sum1-cnt+1,sum1)<<" "<<get(j,1,cnt)<<endl;
                if(get(i,sum1-cnt+1,sum1) == get(j,1,cnt)) {
                    // break;
                    f[i][j]=cnt;
                }
                
            }
        }

        
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[1 << (i - 1)][i] = s[i].size()-1;

    for(int S=0; S < (1<<n);S++ ) {
        for(int i=1;i<=n;i++) {
            if(((S>>(i-1)) & 1) == 0)continue;
            for(int j=1;j<=n;j++) {
                if((S>>(j-1)) &1) continue;
                int T = S|(1<<(j-1));
                if(f[i][j] == s[j].size()-1) 
                    dp[T][i] = min(dp[T][i],dp[S][i]);// i包含j,依旧是i结尾，结果会更好
                else 
                    dp[T][j] = min(dp[T][j], dp[S][i]+(int)s[j].size()-1-f[i][j]);
            }
        }
    }
    int ans = INF;
    for(int i=1;i<=n;i++) {
        ans = min(dp[(1<<n)-1][i],ans);
        // cout<<dp[(1<<n)-1][i]<<" ";
    }
    cout<<ans<<endl;

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