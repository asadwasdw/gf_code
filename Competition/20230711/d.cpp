#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int lowbit(int x)
{
    return x&-x;
}

struct tr{
    int l,r;
    int sum;
    int mul;
    int cnt;
}tr[N*4];

void pushup(int u)
{
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%mod;
    tr[u].cnt=tr[u<<1].cnt+tr[u<<1|1].cnt;
}

void pushdown(int u)
{
    if(tr[u].mul!=1)
    {

        tr[u<<1].sum=tr[u<<1].sum*tr[u].mul%mod;;
        tr[u<<1].mul=tr[u<<1].mul*tr[u].mul%mod;;

        tr[u<<1|1].sum=tr[u<<1|1].sum*tr[u].mul%mod;;
        tr[u<<1|1].mul=tr[u<<1|1].mul*tr[u].mul%mod;;
        tr[u].mul=1;
    }
}


int w[N];

void build(int u,int l,int r)
{
    if(l==r){
        tr[u]={l,r,w[l],1,0};
        if(w[l]==lowbit(w[l])){
            tr[u].cnt=1;
        }
        return ;
    }
    tr[u]={l,r,0,1,0};
    int mid =l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r)
{
 
   int mid=tr[u].l+tr[u].r>>1;
    if(tr[u].cnt==(tr[u].r-tr[u].l+1)){

       if(l<=tr[u].l&&tr[u].r<=r){
           tr[u].sum=tr[u].sum*2%mod;;
           tr[u].mul=tr[u].mul*2%mod;;
           return;
       }
         pushdown(u);
        if(l<=mid)modify(u<<1,l,r);
        if(r>=mid+1)modify(u<<1|1,l,r);
        pushup(u);
        
    }
    else 
    {
        if(tr[u].l==tr[u].r){
            tr[u].sum+=lowbit(tr[u].sum);
            //cout<<tr[u].sum<<endl;
            if(tr[u].sum==lowbit(tr[u].sum))tr[u].cnt=1;
        }
        else 
        {
            pushdown(u);
            if(l<=mid)modify(u<<1,l,r);
            if(r>=mid+1)modify(u<<1|1,l,r);
            pushup(u);
        }
    }

    
}

int query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r){
        return tr[u].sum;
    }
    pushdown(u);
    int mid =tr[u].l+tr[u].r>>1;
    ll res=0;
    if(l<=mid)res+=query(u<<1,l,r);
    if(r>=mid+1)res+=query(u<<1|1,l,r);

    return res%mod;;
}



void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            //for(int i=1;i<=n;i++)cout<<query(1,i,i)<<" ";cout<<endl;
            modify(1,l,r);
            //for(int i=1;i<=n;i++)cout<<query(1,i,i)<<" ";cout<<endl;
        }
        else cout<<query(1,l,r)%mod<<endl;
    }


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}