#include<iostream>
#include<algorithm>
using namespace std;

#define int long long

const int N=3e5+10,MOD=998244353;

int w[N];
 int n;
struct Node{
    int l,r;
    int yh,mul;
}tr[N*4];

void pushup(int u)
{
    tr[u].yh=(tr[u<<1].yh)|(tr[u<<1|1].yh);
    tr[u].mul=(tr[u<<1].mul+tr[u<<1|1].mul)%MOD;
}

void build(int u,int l,int r)
{
    if(l==r)tr[u]={l,r,w[l],w[l]*w[l]%MOD};
    else 
    {
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int x)
{

    if(tr[u].yh&(~x)==0)return;
    if(tr[u].l==tr[u].r&&tr[u].l>=l&&tr[u].r<=r){
        //cout<<tr[u].l<<endl;
        tr[u].yh &= x;
        tr[u].mul=tr[u].yh*tr[u].yh%MOD;
        return;
    }

    if(tr[u].l==tr[u].r||tr[u].r<l||tr[u].l>r)return;

    int mid=tr[u].l+tr[u].r>>1;

    if((tr[u<<1].yh&(~x) )!=0)
    modify(u<<1,l,r,x);
    if((tr[u<<1|1].yh&(~x) )!=0)
    modify(u<<1|1,l,r,x);

    pushup(u);
}


int query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u].mul%MOD;
    }
    int mid=tr[u].l+tr[u].r>>1;
    if(r<=mid)return query(u<<1,l,r)%MOD;
    else if(l>=mid+1)return query(u<<1|1,l,r)%MOD;
    else {
        return query(u<<1|1,l,r)%MOD+query(u<<1,l,r)%MOD;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    build(1,1,n);

    int m;
    scanf("%lld",&m);
    while(m--)
    {
        int op,l,r,x;
        scanf("%lld%lld%lld",&op,&l,&r);
        if(op==1)
        {
              scanf("%lld",&x);
            modify(1,l,r,x);
        }
        else{

            cout<<query(1,l,r)%MOD<<endl;
        }
    }

    return 0;

}
