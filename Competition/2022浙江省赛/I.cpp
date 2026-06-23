#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;
typedef pair<int,int>PII;
const int N=1e6+10;
const int P=131;
const int M=2*N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
int qpow(int a,int k,int p){int res = 1;while(k){if(k&1)res = res*a%p;a = a*a%p;k>>=1;}return res;}
int C(int a,int b,int p){if(b>a)return 0;int res = 1;for(int i=1,j=a;i<=b;i++,j--){res = res*j%p;res = res*qpow(i,p-2,p)%p;}return res;}
//优先对列
//priority_queue <int,vector<int>,less<int> > q;//递减
//priority_queue <PII,vector<PII>,greater<PII> > q;//递增
ULL p[N],hq[N],hh[N];
  int n,m;
  
ULL get1(int l,int r)
{
    return hq[r]-hq[l-1]*p[r-l+1];
}

ULL get2(int L,int R)
{
   // cout<<n<<endl;
    int l=n-R+1;
    int r=n-L+1;
   // cout<<l<<" "<<r<<endl;
    return hh[r]-hh[l-1]*p[r-l+1];
}


void solve()
{
    scanf("%d %d",&n,&m);
    char s[N];
    scanf("%s",s+1);
     char t[N];
    p[0]=1;


    for(int i=1;i<=n;i++)
    {
        hq[i]=hq[i-1]*P+s[i];
        p[i]=p[i-1]*P;
        cout<<i<<" "<<hq[i]<<endl;
    }

    for(int i=n;i;i--)
    {
        t[n-i+1]=s[i];
    }

    for(int i=1;i<=n;i++)
    {
        hh[i]=hh[i-1]*P+t[i];
    }
   cout<<get1(1,4)<<" "<<get2(2,5)<<endl;


}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    /*多组案例初始化*/
    //int t;cin>>t;while(t--)
    solve();
}