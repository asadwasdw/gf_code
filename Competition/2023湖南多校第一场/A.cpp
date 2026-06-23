#include<iostream>
#include<algorithm>
#define int long long 
using namespace std;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

typedef struct d
{
    int jl,ld,hd;
}d;
d ds[N];

bool cmp(d a,d b)
{
    return a.jl<b.jl;
}


void solve()
{
    int n,m;
    cin>>n>>m;
    
    int t=0;

    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ds[i]={a,b,c};
    }
    ds[0]={0,0,0};

    sort(ds+1,ds+n+1,cmp);

    for(int i=1;i<=n;i++)
    {
        t+=ds[i].jl-ds[i-1].jl;

       // cout<<t<<endl;
        //cout<<t%(ds[i].hd+ds[i].ld)<<endl;

        if(t%(ds[i].hd+ds[i].ld)<ds[i].ld)  
        {

        }else{
            t+=ds[i].hd+ds[i].ld-(t%(ds[i].hd+ds[i].ld));
        }
    }

    cout<<t+m-ds[n].jl<<endl;






}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}