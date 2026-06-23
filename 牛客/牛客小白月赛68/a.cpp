#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ans=INF;

    for(int i=1;i<=n;i++)
    {
        int  k,x,y;
        cin>>k>>x>>y;
        for(int j=1;j<=k;j++)
        {
            int jg;
            cin>>jg;
            int hf=jg;
            if(jg>=x)hf-=y;
            if(jg>=a)hf-=b;
            ans=min(ans,hf);
        }
    }

    cout<<max(ans,0)<<endl;



}



signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
    int t;cin>>t;while(t--)
    solve();
}