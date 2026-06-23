#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
const int N=5e5+10;

int w[N],v[N];

int h[N],e[N],ne[N],idx;

int L[N],R[N],cnt;

void Add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

void dfs(int u,int p)
{
    cnt++;
    L[u]=cnt;
    v[cnt]=p;

    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        dfs(j,w[i]);
    }

    R[u]=cnt;

}

struct Node{
    int l,r;
    int w;
    int add;
}tr[N*4];


void pushup(int u)
{
    tr[u].w=tr[u<<1].w+tr[u<<1|1].w;
}


void pushdown(Node &t,int add)
{
    t.add+=add;
    t.w+=(t.r-t.l+1)*add;
}


void pushdown(int u)
{
    pushdown(tr[u<<1],tr[u].add);
    pushdown(tr[u<<1|1],tr[u].add);
    tr[u].add=0;
}


void build(int u,int l,int r)
{
    if(l==r)tr[u]={l,r,v[l],0};
    else 
    {
        tr[u]={l,r};
        int mid=l+r>>1;

        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}


void modify(int u,int l,int r,int add)
{
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].add+=add;
        tr[u].w+=(tr[u].r-tr[u].l+1)*add;
    }
    else{
        pushdown(u);
        int mid=l+r>>1;
        if(r<=mid)modify(u<<1,l,r,add);
        if(l>=mid+1)modify(u<<1|1,l,r,add);
        pushup(u);
    }
}



int query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].w;

    int mid=tr[u].l+tr[u].r>>1; 
    pushdown(u);
    if(r<=mid)return query(u<<1,l,r);
    else if(l>=mid+1)return query(u<<1|1,l,r);
    else {
        return query(u<<1,l,r)+query(u<<1|1,l,r);
    }
}


signed main()
{

    int n,m;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++)
    {
        int p,W;cin>>p>>W;
        Add(p,i,W);
    }

    dfs(0,0);

    build(1,1,cnt);
   // cout<<query(1,1,4)<<endl;

    while(m--)
    {
        char c[2];
        int x,z;
       int y;
       // cin>>c>>x>>y>>z;
         scanf("%s%lld%lld%lld",&c,&x,&y,&z);
         

        if(c[0]=='S')
        {

            int t=query(1,L[x],L[x]);
            if(t<y)
            {
                modify(1,L[x],L[x],z);
            }

        }
        else 
        {
            int t=query(1,L[x],R[x]);
            //cout<<t<<endl;
            if(t<y*(R[x]-L[x]+1))
            {
                //cout<<" sss"<<endl;
                modify(1,L[x],R[x],z);
            }
        }  
    }

    

     for(int i=0;i<n;i++){
        //cout<<L[i]<<" "<<R[i]<<endl;
     }


    for(int i=0;i<n;i++)
    {
        int t=query(1,L[i],L[i]);
        cout<<t<<endl;
    }








}