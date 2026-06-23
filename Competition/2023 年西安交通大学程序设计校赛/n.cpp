#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;
    int w[N];

void solve()
{
    int n,m;
    cin>>n>>m;
    int x=0;
    

    int a,b,c;
    cin>>a>>b>>c;

    for(int i=1;i<=n;i++)cin>>w[i];
    int ans=c;

    int ans1=1;


    for(int i=1;i<=n;i++)
    {
        if(w[i]==x)
        {

        }
        else 
        {

            ans+=(m+w[i]-x)%m*(a+b);
                
        }

        ans+=a;
       // cout<<ans<<endl;
        x=w[i]+1;
        x%=m;
    }
    
    for(int i=2;i<=n;i++)
    {

    //cout<<(w[i]+m-w[i-1])%m<<endl;

        if(((w[i]+m-w[i-1])%m)!=1){
            ans1=-1;
            break;
        }

        
    }
    //cout<<ans1<<endl;

    if(ans1==1)
    {
        ans1=(w[1])*(a+b)+n*a;
    }
    else ans1=0x3f3f3f3f3f3f3f3f;


    cout<<min(ans,ans1)<<endl;

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