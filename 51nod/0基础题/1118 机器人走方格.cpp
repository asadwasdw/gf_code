#include<iostream>
#include<algorithm>


using namespace std;

typedef long long ll;
const int N=1e3+10;

ll f[N][N];

const int M=1e9+7;
int main()
{
    f[1][1]=1;

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i][j],f[i-1][j]+f[i][j-1]);
            f[i][j]%=M;
        }
    }

    cout<<f[n][m]<<endl;

}