#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3500+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

char c[N][N];
int n,m;
int a[N][N];
int pd(int x,int y) {
    int res = 0;
    int len = 0;

    while(y-len>=1&&y+len<=m&&x+len<=n) {
        len ++;
        if(c[x+len][y-len]!='*' || c[x+len][y+len]!='*')break;
        if(a[x+len][y+len]-a[x+len][y-len-1]==2*len+1)res++;
    }
    // cout<<x<<" "<<y<<" "<<len<<" "<<res<<endl;

    return res;
}

void solve()
{
   
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>c[i][j];
            if(c[i][j]=='*')a[i][j]=1;
            a[i][j]+=a[i][j-1];
            // cout<<a[i][j]<<" ";
        }
        // cout<<endl;

    }

    int ans = 0;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(c[i][j]=='*') {
                ans += pd(i,j);
            }
        }
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