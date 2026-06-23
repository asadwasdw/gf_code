//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1613

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=55;
int l[N][N][N];
int mp[N][N];

int main()
{
    int n;cin>>n;
    int m;cin>>m;
    memset(mp,0x3f,sizeof mp);

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a][b]=1;
        l[a][b][0]=1;
    }

    for(int t=1;t<=32;t++){

        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++){
                    if(l[i][k][t-1]&&l[k][j][t-1]){
                        l[i][j][t]=1;
                        mp[i][j]=1;
                    }
                }
            }
        }
    }


    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }

    cout<<mp[1][n]<<endl;
}