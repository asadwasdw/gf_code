#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4000+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N][N];
int s[N][N];


int js(int l1,int r1,int l2,int r2)
{
    return s[l2][r2]-s[l1-1][r2]-s[l2][r1-1]+s[l1-1][r1-1];
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
   // cout<<js(1,1,n,m)<<endl;

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)cout<<s[i][j]<<" ";cout<<endl;
    // }

    ll ans=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            // int l = 1,r=min(n-i+1,m-j+1); 
            //  int t;
            // while(l<r)
            // {
            //     int mid=(l+r+1)>>1;
            //     t= js(i,j,i+mid,j+mid);
            //     if(t)r=mid-1;
            //     else l=mid;
            // }
            // cout<<t<<" ";

            // cout<<i<<" "<<j<<" "<<l<<endl;

            // ans+=l;
            int t = 0;
            if(a[i][j])
             continue;

            for(int k=30;k>=0;k--)
            {
                int jl =t + (1ll<<k);
               // cout<<jl<<" ";
               // cout<<js(i,j,i,j)<<endl;
                if((i+jl<=n)&&(j+jl<=m)&&js(i,j,i+jl,j+jl)==0)
                {
                    t=jl;
                }
            }
            //cout<<i<<" "<<j<<" "<<t<<endl;
            ans+=t+1;
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