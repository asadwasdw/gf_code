#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<vector>
#include<cstring>

typedef long long ll;
using namespace std;
int n,a,b,A,B;
const int N=300;

ll f[N][N][N];

int M= 998244353;

ll qmi(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}


void solve()
{
    cin>>n>>a>>b>>A>>B;

    ll maxn=2*min(n-a,n-b);

    ll adgl=qmi(A,M-2,M);
    ll bdgl=qmi(B,M-2,M);

    f[0][a][b]=1;

    for(int i=0;i<=maxn;i++)
    {
        for(int j=a;j<n;j++)
        {
            for(int k=b;k<n;k++)
            {
                if(i%2){

                  for(int z=1;z<=B;z++)
                  {
                    f[i+1][j][min(k+z,n)]+=f[i][j][k]%M*bdgl%M;
                     f[i+1][j][min(k+z,n)]%=M;
                  }
                }
                else {

                    for(int z=1;z<=A;z++)
                  {
                    f[i+1][min(j+z,n)][k]+=f[i][j][k]%M*adgl%M;
                     f[i+1][min(j+z,n)][k]%=M;
                  }
                }
            }
        }
    }

    int ans=0;

    for(int i=1;i<=maxn;i+=2)
    {
        for(int k=b;k<n;k++)
        {
            ans+=f[i][n][k]%M;
            ans%=M;
        }
    }

    cout<<ans<<endl;



    
}


int main()
{
  //int t;cin>>t;while(t--)
    solve();
}