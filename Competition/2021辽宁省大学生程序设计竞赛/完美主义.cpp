#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int a[N],b[N];
struct node{
    int l,r,w;
}tr[N*4];

void pushup(int u)
{
    tr[u].w=min(tr[u<<1].w,tr[u<<1|1].w);
}

void build(int u,int l,int r)
{
    if(l==r){
       // cout<<l<<" "<<b[l]<<endl;
        tr[u]={l,r,b[l]};
        return ;
    }
    int mid = l + r>>1;
    tr[u]={l,r};
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int k,int x)
{
    if(tr[u].l==tr[u].r&&tr[u].l==k){
      //  cout<<tr[u].l<<x<<endl;
        tr[u].w=x;
        return ;
    }

    int mid = tr[u].l+tr[u].r>>1;
   if(k<=mid)modify(u<<1,k,x);
    if(k>=mid+1)modify(u<<1|1,k,x);
    pushup(u);
}

int query(int u,int l,int r)
{
    if(l>r)return 1;
   // cout<<u<<" "<<l<<" "<<r<<" "<<tr[u].l<<" "<<tr[u].r<<endl;
    if(l<=tr[u].l&&tr[u].r<=r){
        return tr[u].w;
    }

    int mid = tr[u].l+tr[u].r>>1;
    int ans =INF;
    if(l<=mid)ans=min(ans,query(u<<1,l,r));
    if(r>=mid+1)ans=min(ans,query(u<<1|1,l,r));
    return ans;
}

void solve()
{

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]-a[i-1];
        //cout<<i<<" "<<b[i]<<endl;
    }

    build(1,1,n);

    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            a[x]=y;
            b[x]=a[x]-a[x-1];
            b[x+1]=a[x+1]-a[x];
            modify(1,x,b[x]);
            if(x!=n)modify(1,x+1,b[x+1]);
        }
        else {
            int t = query(1,x+1,y);
            //cout<<t<<endl;
            if(t>=0)cout<<"Yes";
            else cout<<"No";
            cout<<"\n";
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<b[i]<<" "<<query(1,i,i)<<endl;
    // }

    //cout<<"s"<<endl;







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