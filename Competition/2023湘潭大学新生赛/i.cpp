#include<bits/stdc++.h>
#define ll long long
#define PI 3.1415926
using namespace std;
typedef pair<int,int>vt;
typedef pair<vt,vt>PII;
const int N=1e6+10;
const int M=2*N;
const int mod=998244353;
const ll INF  = 0x3f3f3f3f3f3f3f3f;
int qpow(int a,int k,int p){int res = 1;while(k){if(k&1)res = res*a%p;a = a*a%p;k>>=1;}return res;}
int C(int a,int b,int p){if(b>a)return 0;int res = 1;for(int i=1,j=a;i<=b;i++,j--){res = res*j%p;res = res*qpow(i,p-2,p)%p;}return res;}

//优先对列
//priority_queue <int,vector<int>,less<int> > q;//递减
//priority_queue <vt,vector<vt>,greater<vt> > q;//递增


int f[2005][105];

void solve()
{
    int k,D;
    string s;

    cin>>k>>D;
    cin>>s;

    int n=s.size();
    s=" "+s;

    memset(f,0,sizeof f);

    vector<int>d(n+5);

    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')d[i]=d[i-1]+1;
        else d[i]=d[i-1];
    }

    for(int i=D;i<=n;i++)
    {
        int need=d[i]-d[i-D];
        for(int j=0;j<=k;j++)
        {
            //f[i][j]=max(f[i][j],f[i-D][j]);
            for(int t=0;t<=j;t++)
            {
                if(j-t>=need)
                {
                    //cout<<j<<" "<<t<<endl;
                    f[i][j]=max(f[i][j],f[i-D][t]+1);
                }
                else f[i][j]=max(f[i][j],f[i-1][t]);
            }
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<f[i][0]<<endl;
    // }

    cout<<f[n][k]<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    /*多组案例初始化*/
    int t;cin>>t;while(t--)
    solve();
}
