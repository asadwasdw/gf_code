#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10; 
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int mod=998244353;
struct node{
	int l,r;
	vector<int>a;
	vector<int>t;
}tr[N*4];
int b[N];
void pushup(int u)
{
	for(int i=0;i<mod;i++){
		tr[u].a[i]=tr[u<<1].a[i]+tr[u<<1|1].a[i];
	}
}

void pushdown(int u){
	bool xy = false;
	for(int i=0;i<mod;i++){
		if(tr[u].t[i]!=i)xy=true;
	}
	if(!xy)return;

	{
		vector<int>tmp(31);
		for(int i=0;i<mod;i++){
			tmp[tr[u].t[i]]+=tr[u<<1].a[i];
		}
		tr[u<<1].a=tmp;

		for(int i=0;i<mod;i++){
			tr[u<<1].t[i]=tr[u].t[tr[u<<1].t[i]];
		}
	}

	{
		vector<int>tmp(31);
		for(int i=0;i<mod;i++){
			tmp[tr[u].t[i]]+=tr[u<<1|1].a[i];
		}
		tr[u<<1|1].a=tmp;

		for(int i=0;i<mod;i++){
			tr[u<<1|1].t[i]=tr[u].t[tr[u<<1|1].t[i]];
		}
	}
	iota(tr[u].t.begin(), tr[u].t.end(), 0);
}

void build(int u,int l,int r){

	tr[u].l=l;
	tr[u].r=r;
	tr[u].a.resize(31);
	tr[u].t.resize(31);
	iota(tr[u].t.begin(), tr[u].t.end(), 0);

	if(l==r){
		tr[u].a[b[l]%mod]++;
		return;
	}
	int mid = l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

void modify(int u,int l,int r,vector<int> k){


	if(l<=tr[u].l&&tr[u].r<=r){

		vector<int>tmp(31);
		for(int i=0;i<mod;i++){
			tmp[k[i]]+=tr[u].a[i];
		}
		tr[u].a=tmp;

		for(int i=0;i<mod;i++){
			tr[u].t[i]=k[tr[u].t[i]];
		}
		return ;
	}


	int mid = tr[u].l+tr[u].r>>1;
	pushdown(u);
	if(l<=mid)modify(u<<1,l,r,k);
	if(r>=mid+1)modify(u<<1|1,l,r,k);
	pushup(u);
}

vector<int> query(int u,int l,int r){
	vector<int>res(31);
	if(l<=tr[u].l&&tr[u].r<=r){
		for(int i=0;i<mod;i++){
			res[i]+=tr[u].a[i];
		//	res[i]%=mod;
		}
		return res;
	}

	pushdown(u);

	vector<int>res1(31);
	vector<int>res2(31);
	int mid = tr[u].l+tr[u].r>>1;
	if(l<=mid)res1 = query(u<<1,l,r);
	if(r>=mid+1)res2 = query(u<<1|1,l,r);

	for(int i=0;i<mod;i++){
		res[i]+=res1[i]+res2[i];
	//	res[i]%=mod;
	}
	return res;
}

ll qmi(ll a,ll b,ll c){

	ll res  =1;
	while(b){
		if(b&1)res = res *a%c;
		b>>=1;
		a=a*a%c;
	}
	return res;
}

vector<int>g(int op,int k){
	//cout<<op<<" "<<k<<endl;

	vector<int> res(31);
	iota(res.begin(), res.end(), 0);
	if(op==1){
		for(int i=0;i<mod;i++){
			res[i]=(res[i]+k)%mod;
		}
	}
	else if(op==2){
		for(int i=0;i<mod;i++){
			res[i]=(res[i]*k)%mod;
		}
	}
	else if(op==3){
		for(int i=0;i<mod;i++){
			res[i]=qmi(res[i],k,mod);
		}
	}
	return res;
}


int p(int op,vector<int>a,int k){
	if(op==4){
		//cout<<"4 ";
		ll res = 0;
		for(int i=0;i<mod;i++){
			res += a[i]*qmi(i,k,mod);
			//cout<<res<<endl;
			res%=mod;
		}
		return res%mod;
	}
	else {
		//cout<<"5 ";
		int res = 1;
		for(int i=0;i<mod;i++)
		{
			res *= qmi(i,a[i],mod);
			res%=mod;
		}
		return res%mod;	
	}

}



void solve()
{
	int n;
	cin>>n;
	cin>>mod;
	for(int i=1;i<=n;i++)cin>>b[i];
	build(1,1,n);
	// auto v =query(1,1,n);
	// for(auto t:v)cout<<t<<" ";cout<<endl;

	int q;
	cin>>q;

	// auto t = query(1,1,n);
	// for(int i=0;i<mod;i++){
	// 	cout<<t[i]<<" ";
	// }
	// cout<<endl;
	for(int i=1;i<=q;i++)
	{
		int op,l,r,k;
		k=0;
		cin>>op>>l>>r;
		if(op<=3){
			cin>>k;
			auto t = g(op,k);
			//for(auto T:t)cout<<T<<" ";cout<<endl;
			modify(1,l,r,t);
		}
		else {
			cin>>k;
			auto t = query(1,l,r);
			int ans = p(op,t,k);
			cout<<ans<<endl;
		}
		// auto t = query(1,1,n);
		// for(int i=0;i<mod;i++){
		// 	cout<<t[i]<<" ";
		// }
		// cout<<endl;
		//cout<<i<<endl;
	}
	//cout<<"S"<<endl;







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