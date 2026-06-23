#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int f[N],xz[N],wp[N],jdxz[N];
int find(int x)
{
    if(x!=f[x])return f[x]=find(f[x]);
    return f[x];
}


void solve()
{
    for(int i=1;i<N;i++)f[i]=i;
    for(int i=1;i<N;i++)xz[i]=i,jdxz[i]=i,wp[i]=i;
    int n,k,op,cnt,q;
    cin>>n>>q;
    k=cnt=n;


    while(q--)
    {
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            int zzdx=xz[x];
            int zzdy=xz[y];
            f[find(zzdy)]=find(zzdx);
            ++cnt;
            xz[y]=cnt;
            jdxz[cnt]=y;
        }
        else if(op==2)
        {
            int x;
            cin>>x;
            k++;
            int t = xz[x];
            wp[k]=t;
        }
        else 
        {
            int x;
            cin>>x;
            int ans=wp[x];
            ans =  find(ans);
            ans = jdxz[ans];
            cout<<ans<<endl;
        }

    }








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