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

int x[N];
int y[N];
int sx[N];
int sy[N];

ll k;
int n;

bool check(int mid)
{
    ll res = 0;
    ll ans1 = INFll;
    ll ans2 = INFll;
    {
        
        int l = 1,r=1;
        for(;l<=n;l++)
        {
            while(r+1<=n && x[l]+mid>=x[r+1])r++;
            ll ans = (l-1)*x[l]-sx[l-1] + (sx[n]-sx[r])-(n-r)*(x[l]+mid);
            // cout<<ans<<endl;
            ans1=min(ans,ans1);
        }
    }


    {
        int l = 1,r=1;
        for(;l<=n;l++)
        {
            while(r+1<=n && y[l]+mid>=y[r+1])r++;
            ll ans = (l-1)*y[l]-sy[l-1] + (sy[n]-sy[r])-(n-r)*(y[l]+mid);
          //  if(mid==2)cout<<l<<" "<<r<<" "<<ans<<endl;
            ans2=min(ans,ans2);
        }
    }

    {
        int l = n,r=n;
        for(;r;r--)
        {
            while(l-1>=1 && x[l-1] >= x[r]-mid )l--;

            ll ans = ((l-1)*(x[r]-mid))-sx[l-1]+sx[n]-sx[r]-x[r]*(n-r);
            // cout<<ans<<endl;
            ans1=min(ans,ans1);
        }
    }

    {
        int l = n,r=n;
        for(;r;r--)
        {
            while(l-1>=1 && y[l-1] >= y[r]-mid )l--;

            ll ans = ((l-1)*(y[r]-mid))-sy[l-1]+sy[n]-sy[r]-y[r]*(n-r);
            // cout<<ans<<endl;
            ans2=min(ans,ans2);
        }
    }




    res=ans1+ans2;
    // cout<<mid<<" "<<res<<endl;
    //if(mid==2)cout<<ans1<<" "<<ans2<<endl;
    return res<=k;
}


void solve()
{
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }

    sort(x+1,x+n+1);
    sort(y+1,y+n+1);

    for(int i=1;i<=n;i++){
        sx[i]=x[i]+sx[i-1];
        sy[i]=y[i]+sy[i-1];
    }

    int l=0,r=1e9;
    while(l<r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    cout<<l<<endl;
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