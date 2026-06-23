#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

vector<vector<PII>>edg(N);

int id[N],dep[N],top[N],fa[N],sz[N],son[N],cnt;
int w[N],nw[N];
int n,m,q;
struct node{
	ll l,r;
	ll add,sum;
}tr[N*4];

void dfs1(int u,int father,int depth)
{
	fa[u]=father;
	dep[u]=depth;
	sz[u]=1;
	for(auto T : edg[u])
	{
        int t = T.first;
        
		if(t==father)continue;
        w[t] = T.second;
		dfs1(t,u,depth+1);
		sz[u]+=sz[t];
		if(sz[t]>sz[son[u]])son[u]=t;
	}
}

void dfs2(int u,int t)
{
	top[u]=t;
	id[u]=++cnt;
	nw[cnt]=w[u];

	if(!son[u])return;

	dfs2(son[u],t);

	for(auto T : edg[u])
	{
        int j = T.first;
		if(j==fa[u]||j==son[u])continue;
		dfs2(j,j);
	}
}


void pushup(int u)
{
	tr[u].sum = tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u)
{
	auto &root = tr[u],&left = tr[u<<1],&right = tr[u<<1|1];

	if(root.add)
	{
		left.sum+=root.add*(left.r-left.l+1);left.add+=root.add;
		right.sum+=root.add*(right.r-right.l+1);right.add+=root.add;
		root.add=0;
	}
}

void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]={l,r,0,nw[l]};
		return;
	}
	tr[u]={l,r,0,0};
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}


void update(int u,int l,int r,int k)
{
	if(l<=tr[u].l&&tr[u].r<=r){
		tr[u].sum+=k*(tr[u].r-tr[u].l+1);
		tr[u].add+=k;
		return ;
	}
	pushdown(u);
	int mid = tr[u].l+tr[u].r>>1;
	if(l<=mid)update(u<<1,l,r,k);
	if(r>mid)update(u<<1|1,l,r,k);
	pushup(u);
}

ll query(int u,int l,int r)
{
	if(l<=tr[u].l&&tr[u].r<=r)
	{
		return tr[u].sum;
	}
	pushdown(u);
	int mid = tr[u].l+tr[u].r>>1;
	ll res=0;
	if(l<=mid)res+=query(u<<1,l,r);
	if(r>mid)res+=query(u<<1|1,l,r);
	return res;
}

void update_node(int u,int k)
{
	update(1,id[u],id[u],k);
}

void update_tree(int u,int k)
{
	update(1,id[u],id[u]+sz[u]-1,k);
}

void update_path(int u,int v,int k)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		update(1,id[top[u]],id[u],k);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])swap(u,v);
	update(1,id[v],id[u],k);
}

int FA[N][20];

void dfs3(int x,int father){
    FA[x][0]=father;

    for(int i=1;(1<<i)<=dep[x];i++){
        FA[x][i]=FA[FA[x][i-1]][i-1];
    }

    for(auto t:edg[x])
    {
        if(t.first!=father)dfs3(t.first,x);
    }
}

int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);

    for(int i=19;i>=0;i--)
        if(dep[x]-(1<<i)>=dep[y]){
            x=FA[x][i];
        }

        if(x==y)return x;

        for(int i=19;i>=0;i--)
            if(FA[x][i]!=FA[y][i]){
                x=FA[x][i];
                y=FA[y][i];
            }

         return FA[x][0];   
}





ll query_path(int u,int v)
{
	ll res=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		res+=query(1,id[top[u]],id[u]);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])swap(u,v);
    res+=query(1,id[v],id[u]);
	return res;
}



void solve()
{
	cin>>n>>m>>q;


	for(int i=1;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edg[a].push_back({b,c});
		edg[b].push_back({a,c});
	}

	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);
    dfs3(1,0);

    //for(int i=1;i<=n;i++)cout<<w[i]<<" ";cout<<endl;

    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        update_path(x,y,z);
        int t =lca(x,y);
        //cout<<lca(x,y)<<endl;
        update_path(t,t,-z);
    }

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int t = lca(l,r);
        cout<<query_path(l,r)-query_path(t,t)<<endl;
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