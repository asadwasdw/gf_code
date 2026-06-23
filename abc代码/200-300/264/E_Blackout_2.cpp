#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int n,m,k;
int f[N],sz[N];
int st[N];
int find(int x)
{
    if(x!=f[x])return f[x]=find(f[x]);
    return x;
}

struct e
{
    int l,r;
}edg[N];

int ans[N];
int op[N];
bool ste[N];

void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n+m;i++)
    {
        f[i]=i;
        sz[i]=1;
        st[i]=(i>n);
      //  cout<<i<<" "<<st[i]<<endl;
    }

    for(int i=1;i<=k;i++){
        cin>>edg[i].l>>edg[i].r;
        //if(edg[i].l>edg[i].r)swap(edg[i].l,edg[i].r);
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        op[i]=x;
        ste[x]=true;
    }


    int res = 0;
    for(int i=1;i<=k;i++){
        if(ste[i])continue;


        int l=edg[i].l;
        int r=edg[i].r;

        int fl=find(l);
        int fr=find(r);

        if(fl==fr)continue;
        //if(st[fr]&&st[fl])continue;

        if(st[fr]&&!st[fl]){
            res+=sz[fl];
            sz[fr]+=sz[fl];
            f[fl]=fr;
        }
        else if(!st[fr]&&st[fl]){
            res +=sz[fr];
            sz[fl]+=sz[fr];
            f[fr]=fl;
        }
        else {
            sz[fr]+=sz[fl];
            f[fl]=fr;
        }

    }

   // cout<<res<<endl;



    for(int i=q;i;i--){

        ans[i]=res;
        int t = op[i];
        int l=edg[t].l;
        int r=edg[t].r;

        int fl=find(l);
        int fr=find(r);

        //cout<<t<<" "<<fl<<" "<<fr<<endl;

        if(fl==fr)
        {
            //cout<<"s"<<i<<" "<<t<<endl;
            continue;
        }

        if(st[fr]&&!st[fl]){
            res+=sz[fl];
            sz[fr]+=sz[fl];
            f[fl]=fr;
        }
        else if(!st[fr]&&st[fl]){
            res +=sz[fr];
            sz[fl]+=sz[fr];
            f[fr]=fl;
        }
        else {
            sz[fr]+=sz[fl];
            f[fl]=fr;
        }
    }

    for(int i=1;i<=q;i++)cout<<ans[i]<<endl;


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