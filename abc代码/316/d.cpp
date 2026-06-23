#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

vector<vector<int>>edg(N);

int h[2010][30];
int l[2010][30];
int a[2010][2010];

set<int> H[N],L[N];
int hh[N],ll[N];

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            char t;
            cin>>t;
            a[i][j]=(t-'a');
            h[i][a[i][j]]++;
            l[j][a[i][j]]++;
        }
    }



    int ans1 = 0;
    int ans2 = 0;

    while(1)
    {
        bool xy =false;
        for(int i=1;i<=n;i++){
            if(hh[i]<=ans2+1){
                hh[i]=INF;
                ans1++;
                xy=true;
            }
        }

        for(int j=1;j<=m;j++)
        {
            if(ll[j]<=ans1+1)
            {
                ll[j]=INF;
                ans2++;
                xy=true;
            }
        }

        








        if(xy==false)break;
    }
   // cout<<ans1<<" "<<ans2<<endl;

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(h[i][a[i][j]]<=1&&l[j][a[i][j]]<=1&&ll[j]==INF&&hh[i]==INF)ans++;
        }
    }
    cout<<n*m-ans1*m-ans2*n+ans1*ans2+ans<<endl;







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