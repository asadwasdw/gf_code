#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

#define lson tr[u<<1]
#define rson tr[u<<1|1]
#define fa tr[u]

int a[N];

struct xx{
    int lx,rx,sx;
    int len;
    
    xx(){};
    xx(int t){
        lx=rx=sx=t;
        len = 1;
    }
};

struct node{
    int l,r;
    xx x[2];  
    int tag;
}tr[N*4];


void pushup(int u,int i)
{
    if(lson.x[i].sx == lson.x[i].len)fa.x[i].lx = lson.x[i].sx + rson.x[i].lx;
    else fa.x[i].lx = lson.x[i].lx;

    if(rson.x[i].sx == rson.x[i].len)fa.x[i].rx = rson.x[i].sx + lson.x[i].rx;
    else fa.x[i].rx = rson.x[i].rx;

    fa.x[i].sx = max({ lson.x[i].sx , rson.x[i].sx , lson.x[i].rx+rson.x[i].lx});
    fa.x[i].len = lson.x[i].len+rson.x[i].len;
}

void pushup(int u)
{
    pushup(u,1);
    pushup(u,0);
}

void pushdown(int u)
{
    if(fa.tag){
        swap(lson.x[0],lson.x[1]);
        swap(rson.x[0],rson.x[1]);
        lson.tag^=1;
        rson.tag^=1;
    }

    fa.tag = 0;
}


void build(int u,int l,int r)
{  
    tr[u].l=l;
    tr[u].r=r;

    if(l==r){
        tr[u].x[0]= xx(0);
        tr[u].x[1]= xx(0);
        tr[u].x[a[l]]=xx(1);
        return ;
    }

    int mid = l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r){

    if(l<=tr[u].l&&tr[u].r<=r){
        fa.tag^=1;
        swap(fa.x[1],fa.x[0]);
        return ;
    }

    pushdown(u);
    int mid = tr[u].l+tr[u].r>>1;

    if(l<=mid)modify(u<<1,l,r);
    if(r>=mid+1)modify(u<<1|1,l,r);
    pushup(u);
}

xx query(int u,int l,int r){
   

    if(l<=tr[u].l&&tr[u].r<=r){
        return tr[u].x[1];
    } 
    //cout<<tr[u].l<<" "<<tr[u].r<<endl;
    
    int mid = tr[u].l+tr[u].r>>1;
   pushdown(u);
    if(r<=mid)return query(u<<1,l,r);
    else if(l>=mid+1)return query(u<<1|1,l,r);
    else {
       
        xx res1 = query(u<<1,l,r);
        xx res2 = query(u<<1|1,l,r);
        xx res = xx(0);
     

        if(res1.len==res1.lx)res.lx = res1.lx+res2.lx;
        else res.lx = res1.lx;

        if(res2.len==res2.rx)res.rx = res1.rx+res2.rx;
        else res.rx = res2.rx;

        res.sx = max({res1.sx,res2.sx,res1.rx+res2.lx});
        res.len = res1.len+res2.len;
        return res;
    }
}

void solve()
{
    int n,q;
    cin>>n;
    cin>>q;
    for(int i=1;i<=n;i++){
       char t;cin>>t;
       a[i]=t-'0';
    }

 // for(int i=1;i<=n;i++)cout<<a[i];cout<<endl;
    build(1,1,n);
    while(q--)
    {
        int op,l,r;
        cin>>op>>l>>r;

        if(op==1){
            modify(1,l,r);
        }
        else {
            cout<<query(1,l,r).sx<<endl;
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