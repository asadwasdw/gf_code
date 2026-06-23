#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
#define PI 3.1415926
using namespace std;
typedef pair<int,int>vt;
typedef pair<vt,vt>PII;
const int N=2e5+10;
const int M=2*N;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f3f3f3f3f;
int qpow(int a,int k,int p){int res = 1;while(k){if(k&1)res = res*a%p;a = a*a%p;k>>=1;}return res;}
int C(int a,int b,int p){if(b>a)return 0;int res = 1;for(int i=1,j=a;i<=b;i++,j--){res = res*j%p;res = res*qpow(i,p-2,p)%p;}return res;}

int a[N];
int n,q;

struct Node
{
    int l,r;
    int v,s;
}tr[4*N];

void pushup(Node &u,Node &l,Node &r)
{
	u.s=l.s+r.s;
}

void pushup(int u)
{
	pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]={l,r,a[l],0};
	}
	else
	{
	tr[u]={l,r};
    int mid=l+r >> 1 ;
    build(u<<1,l,mid),build( u<< 1|1,mid+1,r);
	}
}

Node query(int u,int l,int r,int x)
{

	if(tr[u].l==tr[u].r)
	{
		if(tr[u].v!=0&&tr[u].v%x==0)tr[u].s=1;
		else if(tr[u].v!=0) tr[u].s=0;

		//cout<<u<<"->"<<tr[u].v<<endl;
		return tr[u];
	}

	int mid=tr[u].l+tr[u].r>>1;

	if(r<=mid)return query(u<<1,l,r,x);
	else if(l>mid)return query(u<<1|1,l,r,x);
	else
	{
		auto left=query(u<<1,l,r,x);
		auto right=query(u<<1|1,l,r,x);

		Node res;
		pushup(res,left,right);
		return res;
	}

	pushup(u);
}

void modify(int u,int x,int v)
{
    if(tr[u].l==tr[u].r)tr[u].v=v;
    else{
    int mid=tr[u].l+tr[u].r >> 1;
    if(x<=mid)modify(u<<1,x,v);
    else modify(u<< 1|1,x,v);
    }
}

void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];

	build(1,1,200005);

	int len=n;

	while(q--)
	{
		int op,x;
		cin>>op>>x;
		if(op==1)
		{
			modify(1,len+1,x);
			len++;
		}
		else
		{
			//cout<<a[x]<<endl;
			auto ans=query(1,x+1,len,a[x]);
			cout<<ans.s<<endl;
		}
	}


}

signed main()
{
	ios::sync_with_stdio(false);
	/*多组案例初始化*/
	//int t;cin>>t;while(t--)
	solve();
}