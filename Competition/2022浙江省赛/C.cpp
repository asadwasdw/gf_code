#include<iostream>
#include<algorithm>
using namespace std;
//#define int long long
typedef pair<int,int>PII;
const int N=1e6+10;
const int M=2*N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
int qpow(int a,int k,int p){int res = 1;while(k){if(k&1)res = res*a%p;a = a*a%p;k>>=1;}return res;}
int C(int a,int b,int p){if(b>a)return 0;int res = 1;for(int i=1,j=a;i<=b;i++,j--){res = res*j%p;res = res*qpow(i,p-2,p)%p;}return res;}
//优先对列
//priority_queue <int,vector<int>,less<int> > q;//递减
//priority_queue <PII,vector<PII>,greater<PII> > q;//递增

int a[N],b[N];

void solve()
{

    int n,m,x;
    cin>>n>>m;
    cin>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    a[n+1]=b[m+1]=INF;
    int l=0,r=n+1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(a[mid]>=x)r=mid;
        else l=mid+1;
    }
   int ans=max(0,(n-l+1));
   // cout<<l<<endl;
    l=0,r=m+1;//cout<<ans<<endl;
    

    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(b[mid]<=x)l=mid;
        else r=mid-1;
        //cout<<l<<" "<<r<<endl;
    }
    
   // cout<<max(0,(m-l+1))<<endl;
    ans += max(0,l);
    cout<<ans<<endl;
   

}

signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
   // int t;cin>>t;while(t--)
    solve();
}