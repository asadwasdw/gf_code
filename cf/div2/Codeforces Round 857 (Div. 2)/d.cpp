#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
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

PII a[N],b[N];

bool cmp(PII a,PII b)
{
    return a.first<b.first;
}

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
       int x,y;
       cin>>x>>y;
       a[i]={x,i};
       b[i]={y,i};
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);

    int t1=1,t2=1;
    int ans=INF;
    while(t1!=n||t2!=n)
    {
        if(a[t1].second==b[t2].second)
        {
           if(a[t1]<b[t2])
        {
            
            if(t1!=n)t1++;
            else t2++;
        }
        else{
           
             if(t2!=n)t2++;
             else t1++;
        }
        }
        else if(a[t1]<b[t2])
        {
            ans=min(b[t2].first-a[t1].first,ans);
            if(t1!=n)t1++;
            else t2++;
        }
        else{
             ans=min(a[t1].first-b[t2].first,ans);
             if(t2!=n)t2++;
             else t1++;
        }
    }

    cout<<ans<<endl;


}

signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
   //int t;cin>>t;while(t--)
    solve();
}