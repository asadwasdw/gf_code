#include<bits/stdc++.h>
#define ll long long
#define PI 3.1415926
#define endl '\n'
#define all(x) x.begin(),x.end()
#define debug1() cout<<"!"<<endl;
#define debug2() cout<<"-----"<<endl;
using namespace std;
typedef pair<int,int>vt;
typedef pair<vt,vt>PII;
const int N=2e6+10;
const int M=2*N;
const int mod=998244353;
const ll INF  = 0x3f3f3f3f3f3f3f3f;

struct node
{
	int l,r,k;
}q[N];

int pos[N],ans[N],cnt[N],a[N];
int n,t;
int blk;
int ANS;


bool cmp(node a,node b)
{
	if(pos[a.l]!=pos[b.l])return pos[a.l]<pos[b.l];
	if(pos[a.l]&1)return a.r>b.r;
	return a.r<b.r;
}

void init()
{
	blk=sqrt(n);
	for(int i=1;i<=n;i++)pos[i]=(i-1)/blk+1;
}

void add(int x)
{
	cnt[a[x]]++;
	if(cnt[a[x]]==1)ANS++;
}

void del(int x)
{
	cnt[a[x]]--;
	if(cnt[a[x]]==0)ANS--;
}

void solve()
{
	 cin>>n;
	  for(int i=1;i<=n;i++)cin>>a[i];
	cin>>t;
	for(int i=1;i<=t;i++){
        
        int l,r;
        cin>>l>>r;
        q[i]={l,r,i};
    }

	init();

	sort(q+1,q+t+1,cmp);

	int l=1,r=0;
	for(int i=1;i<=t;i++)
	{
        while(r<q[i].r)add(++r);
        while(r>q[i].r)del(r--);
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);

		ans[q[i].k]=ANS;
	}

	for(int i=1;i<=t;i++)cout<<ans[i]<<endl;
		return;

	
}

signed main()
{
     ios::sync_with_stdio(false);
     cin.tie(0),cout.tie(0);
    /*多组案例初始化*/
    //int t;cin>>t;while(t--)
    solve();
}