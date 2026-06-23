#include<iostream>
#include<algorithm>

using namespace std;

const int N=110;

int st[N][N];

int main()
{

    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        st[a][b]=1;
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(st[i][k]&&st[k][j]){
                    st[i][j]=1;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int res=0;
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(st[i][j]|st[j][i]){
                res++;
            }
        }

        if(res==n-1){
            ans++;
        }
    }
    cout<<ans<<endl;


}
