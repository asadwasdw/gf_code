#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


const int N =1100;
int a[N][N];

int f[N][5][5];
int n,m;


bool check(int i,int j,int k,int z)
{
    for(int x=1;x<=m;x++)
    {
        if(a[i][x]!=a[i][x-1]&&a[i][x]!=a[i][x+1]&&(a[i][x]^k)!=(a[i-1][x]^j)&&(a[i][x]^k)!=(a[i+1][x]^z))return false;
    }
    return true;
}



bool check2(int i, int x, int y, int z){
  for (int j = 1; j <= m; j++){
    if (a[i][j] != a[i][j - 1] && a[i][j] != a[i][j + 1] && (a[i][j] ^ y) != (a[i - 1][j] ^ x) && (a[i][j] ^ y) != (a[i + 1][j] ^ z)){
      return 0;
    }
  }
  return 1;
}

int main()
{

    cin>>n>>m;
    memset(a,-1,sizeof a);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    memset(f,0x3f,sizeof f);
    f[1][0][0]=0;
    f[1][0][1]=1;
    
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
               for(int z=0;z<2;z++)
                  if(check(i-1,j,k,z))
                     f[i][k][z]=min(f[i][k][z],f[i-1][j][k]+z);   
    }


    int ans = 0x3f3f3f3f;

    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    if(check(n,i,j,0)){
       // cout<<f[n][i][j]<<" "<<i<<" "<<j<<endl;
        ans=min(f[n][i][j],ans);
    }

    if(ans==0x3f3f3f3f)ans=-1;

    cout<<ans<<endl;

}