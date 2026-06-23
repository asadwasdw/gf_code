#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

ll a[N];
ll b[N];
ll s[N];

void solve()
{
    ll n,k;
    cin>>n>>k;
    int num = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }

    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+(b[i]-b[i-1])*(n-i+1);
        //cout<<i<<" "<<s[i]<<endl;
    }
    ll qm=0,mx=0,dy=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]>=k)
        {
            dy=k-s[i-1];
            mx=b[i-1];
            break;
        }
    }
    

    for(int i=1;i<=n;i++)
    {
        a[i]=max(0ll,a[i]-mx);
        if(a[i])num++;
    }

    if(num!=0)
    {
        //cout<<num<<endl;
        qm = dy%num;
        for(int i=1;i<=n;i++)if(a[i])
        {
            a[i]-=dy/num;
            if(qm)
            {
                qm--;
                a[i]-=1;
            }
        }
    }
  


    for(int i=1;i<=n;i++)cout<<a[i]<<" ";



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