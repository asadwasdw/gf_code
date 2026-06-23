#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


struct node{
    int l,r,add;
    int mx,mn,lwr,rwl;
}tr[N<<2];
int w[N],nw[N];
int h[N],ne[N],e[N],idx;
int id[N],cnt;
int dep[N],sz[N],top[N],fa[N],son[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int u,int father,int depth){
    fa[u]=father;
    dep[u]=depth;
    sz[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==father)continue;
        dfs1(j,u,depth+1);
        sz[u]+=sz[j];
        if(sz[j]>sz[son[u]])son[u]=j;
    }
}

void dfs2(int u,int t){
    id[u]=++cnt,nw[cnt]=w[u],top[u]=t;
    if(!son[u])return;
    dfs2(son[u],t);
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa[u]||j==son[u])continue;
        dfs2(j,j);
    }
}


void merge(node &root,node ls,node rs) {
    root.mx = max(ls.mx,rs.mx);
    root.mn = min(ls.mn,rs.mn);
    root.lwr = max({ls.lwr,rs.lwr,rs.mx-ls.mn});
    root.rwl = max({ls.rwl,rs.rwl,ls.mx-rs.mn});
}

void pushup(int u) {
    merge(tr[u],tr[u<<1],tr[u<<1|1]);
}

void pushdown(int u){
    tr[u<<1].mx+=tr[u].add;
    tr[u<<1].mn+=tr[u].add;
    tr[u<<1].add+=tr[u].add;

    tr[u<<1|1].mx+=tr[u].add;
    tr[u<<1|1].mn+=tr[u].add;
    tr[u<<1|1].add+=tr[u].add;

    tr[u].add=0;
}

void build(int u,int l,int r){
    if(l==r){
        tr[u]={l,r,0,nw[l],nw[l],0,0};
        return;
    }
    tr[u]={l,r,0};
    int mid = l + r >> 1;
    build(u<<1, l, mid);
    build(u<<1|1, mid + 1, r);
    pushup(u);
}

void modify(int u,int l,int r,int x) {
    if(l<=tr[u].l &&  tr[u].r<=r) {
        tr[u].mx+=x;
        tr[u].add+=x;
        tr[u].mn+=x;
        return;
    }

    pushdown(u);
    
    int mid = tr[u].l+tr[u].r>>1;
    if(l<=mid)modify(u<<1,l,r,x);
    if(r>=mid+1)modify(u<<1|1,l,r,x);
    pushup(u);
}


node query(int u,int l,int r){
    if(l<=tr[u].l && tr[u].r<=r){
        return tr[u];
    }
    pushdown(u);
    int mid = tr[u].l+tr[u].r>>1;
    if(r<=mid)return query(u<<1,l,r);
    if(l>=mid+1)return query(u<<1|1,l,r);
    node res;
    merge(res,query(u<<1,l,r),query(u<<1|1,l,r));
    return res;
}

void print(node t){
    cout<<t.l<<" "<<t.r<<"| "<<t.mx<<" "<<t.mn<<" |"<<t.lwr<<" "<<t.rwl<<endl;
}

void update_path(int u,int v,int k){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        modify(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    modify(1,id[v],id[u],k);
}

int queryans(int x,int y){
    node l={0,0,0,-INF,INF,0,0},r=l;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]){
            merge(r,query(1,id[top[y]],id[y]),r);
            y=fa[top[y]];
        }
        else {
            merge(l,query(1,id[top[x]],id[x]),l);
            x=fa[top[x]];
        }
    }

    if(dep[x]>dep[y]){
        merge(l,query(1,id[y],id[x]),l);
    }
    else merge(r,query(1,id[x],id[y]),r);

    return max({l.rwl,r.lwr,r.mx-l.mn});
}

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs1(1,0,0);
    dfs2(1,1);
    build(1,1,n);
    int q;cin>>q;
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        // z=0;
        cout<<max(0ll,queryans(x,y))<<endl;
        update_path(x,y,z);
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