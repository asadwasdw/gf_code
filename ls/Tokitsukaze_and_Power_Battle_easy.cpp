#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const int MAX=1e6+5;
//vector<vector<int>>edg(N);
ll n,m;
ll a[MAX];
int tr[N];

int lowbit(int x)
{
    return x&-x;
}

void add(int x,int c)
{
    for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}

int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}


struct node
{
	ll sum,lz;
	ll mx,mn;
}d[MAX<<2];

void push_up(int p)
{
	d[p].sum=d[2*p].sum+d[2*p+1].sum;
	d[p].mx=max(d[2*p].mx,d[2*p+1].mx);
	d[p].mn=min(d[2*p].mn,d[2*p+1].mn);
}
void push_down(int s,int t,int mid,int p)
{
	if(d[p].lz==0)return ;
		/*
		d[2*p].sum=(t-s+1)*d[p].lz;
		d[2*p].lz=d[p].lz;
		d[2*p].mx=d[p].lz;
		d[2*p].mn=d[p].lz;	
		d[2*p+1].sum=(t-s)*d[p].lz;
		d[2*p+1].lz=d[p].lz;
		d[2*p+1].mx=d[p].lz;
		d[2*p+1].mn=d[p].lz;
		d[p].lz=0;	
		*/
		d[2*p].sum+=(mid-s+1)*d[p].lz;
		d[2*p].lz+=d[p].lz;
		d[2*p].mx+=d[p].lz;
		d[2*p].mn+=d[p].lz;	
		d[2*p+1].sum+=(t-mid)*d[p].lz;
		d[2*p+1].lz+=d[p].lz;
		d[2*p+1].mx+=d[p].lz;
		d[2*p+1].mn+=d[p].lz;
		d[p].lz=0;	
}
void build(int s,int t,int p)
{
	d[p].lz=0;
	if(s==t){
		d[p].sum=a[s];
		d[p].mx=d[p].mn=a[s];
		return;
	}
	int mid=(s+t)/2;
	build(s,mid,2*p);
	build(mid+1,t,2*p+1);
	push_up(p);
}

void update(int l,int r,int c,int s,int t,int p)  //区间修改
{
	if(l<=s&&t<=r)
	{
		/*
		d[p].sum=(t-s+1)*c;
		d[p].lz=c;
		d[p].mx=c;
		d[p].mn=c;
		*/	
		d[p].sum+=(t-s+1)*c;
		d[p].lz+=c;
		d[p].mx+=c;
		d[p].mn+=c;
		return ;
	}
	int mid=(s+t)/2;
	push_down(s,t,mid,p);
	if(l<=mid)update(l,r,c,s,mid,2*p);
	if(r>mid)update(l,r,c,mid+1,t,2*p+1);
	push_up(p);
}

void update(int l,int r,int c)
{
    if(l>r)return;
	update(l,r,c,1,n,1);
}

ll getmax(int l,int r,int s,int t,int p) 
{
	if(l<=s&&t<=r){
		return d[p].mx;
	}
	int mid=(s+t)/2;
	push_down(s,t,mid,p);
	ll ans=INT_MIN;
	if(l<=mid)ans=max(ans,getmax(l,r,s,mid,2*p));
	if(r>mid)ans=max(ans,getmax(l,r,mid+1,t,2*p+1));
	return ans; 
} 

ll getmin(int l,int r,int s,int t,int p)  //区间查询最小值 
{
	if(l<=s&&t<=r){
		return d[p].mn;
	}
	int mid=(s+t)/2;
	push_down(s,t,mid,p);
	ll ans=INT_MAX;
	if(l<=mid)ans=min(ans,getmin(l,r,s,mid,2*p));
	if(r>mid)ans=min(ans,getmin(l,r,mid+1,t,2*p+1));
	return ans;
}
ll getmax(int l,int r)
{
	return getmax(l,r,1,n,1);
}
ll getmin(int l,int r)
{
	return getmin(l,r,1,n,1);
}

void solve()
{
    int k;
    cin>>n>>k;

    for(int i=1;i<=n;i++) {
        add(i,-a[i]);
        cin>>a[i];
        add(i,a[i]);
    }

    build(1,n,1);

    while(k--) {
        int op,x,y;
        cin>>op>>x>>y;

        if(op==1){

            add(x,-a[x]+y);
            // cout<<getmax(10,10)<<endl;
            update(x+1,n,-a[x]+y);
            //    cout<<getmax(10,10)<<endl;
            update(x,x,+a[x]-y);
            //    cout<<getmax(10,10)<<endl;
            a[x]=y;
        }
        else  {
            // for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
            // cout<<getmax(x+1,y)<<" "<<sum(x-1)<<" "<<x<<" "<<y<<" "<<getmax(,10)<<endl;
            cout<<getmax(x+1,y)-getmin(x,y)<<endl;
        }
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