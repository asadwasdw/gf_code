#include<bits/stdc++.h>
//#define int long long 
using namespace std;
typedef long long ll;
const ll mod = 998244353; 
const int N = 1e6+10;
const int INF =0x3f3f3f3f;

struct node
{
    int l,r;
    ll w;
}tr[N*4][5];
int w[N];
int a[N];
int res[N];

void pushup(int u,int t)
{
    tr[u][t].w=min(tr[u<<1][t].w,tr[u<<1|1][t].w);
}

void build(int u,int l,int r,int t)
{
    if(l==r){
        tr[u][t]={l,r,INF};
    }
    else 
    {
        tr[u][t]={l,r,0};
        int mid=l+r>>1;
        build(u<<1,l,mid,t);
        build(u<<1|1,mid+1,r,t);
        pushup(u,t);
    }
}

void modify(int u,int x,int y,int t)
{
    if(x==tr[u][t].l&&x==tr[u][t].r){
        tr[u][t].w=y;
    }
    else 
    {
        int mid=tr[u][t].l+tr[u][t].r>>1;
        if(x<=mid)modify(u<<1,x,y,t);
        else if(x>mid)modify(u<<1|1,x,y,t);
        pushup(u,t);
    }
}


int query(int u,int l,int r,int t)
{
    if(l<=tr[u][t].l&&tr[u][t].r<=r)
    {
        return tr[u][t].w;
    }

    int mid = tr[u][t].l+tr[u][t].r>>1;

    int ans=INF;
    if(l<=mid)ans=min (ans,query(u<<1,l,r,t));
    if(r>=mid+1)ans=min(ans,query(u<<1|1,l,r,t));
    return ans; 
}


signed main()
{
    int n;cin>>n;
    memset(res,0x3f,sizeof res);

    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=4;i++)build(1,1,n,i);



    for(int i=1;i<=n;i++)
    {
        int ans2=query(1,a[i],n,2)+i-a[i];
        int ans4=query(1,1,a[i],4)+i+a[i];

        modify(1,a[i],a[i]-i,2);
        modify(1,a[i],-a[i]-i,4);

        res[i]=min(res[i],min(ans2,ans4));
    }


    for(int i=n;i;i--)
    {
        int ans1=query(1,a[i],n,1)-i-a[i];
        int ans3=query(1,1,a[i],3)+a[i]-i;

        modify(1,a[i],a[i]+i,1);
        modify(1,a[i],i-a[i],3);

        res[i]=min(res[i],min(ans1,ans3));

    }

    for(int i=1;i<=n;i++)cout<<res[i]<<" ";

}

