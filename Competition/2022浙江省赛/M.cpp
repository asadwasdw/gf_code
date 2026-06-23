#include<bits/stdc++.h>
#define int long long
#define PI 3.1415926
using namespace std;
typedef pair<int,int>PII;
const int N=1010;
const int M=2*N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
int qpow(int a,int k,int p){int res = 1;while(k){if(k&1)res = res*a%p;a = a*a%p;k>>=1;}return res;}
int C(int a,int b,int p){if(b>a)return 0;int res = 1;for(int i=1,j=a;i<=b;i++,j--){res = res*j%p;res = res*qpow(i,p-2,p)%p;}return res;}
//优先对列
//priority_queue <int,vector<int>,less<int> > q;//递减
//priority_queue <PII,vector<PII>,greater<PII> > q;//递增

char a[N][N];
int n,m;
char p[7][7]={
    "######",
    "##..##",
    "#....#",
    "#....#",
    "##..##",
    "######",
};

bool pd(int x,int y)
{
  

    for(int i=0;i<=5;i++)
    for(int j=0;j<=5;j++)
    {
        if(i+x>n||j+y>m)return false;
        if(a[i+x][j+y]!=p[i][j])
        {
            //if(x==2&&y==3)cout<<i+x<<" "<<j+y<<endl;
           return false;
        }
    }
    return true;
}

void solve()
{
    cin>>n>>m;
    int num1=0;
    int num2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];

        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='#')num1++;
            if(pd(i,j))num2++;
        }
    }
  //  cout<<num1<<endl;
    int x=(100*num2-num1)/54;
    int y=(num2-2*x);

    cout<<x<<" "<<y<<endl;


}

signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
    //int t;cin>>t;while(t--)
    solve();
}