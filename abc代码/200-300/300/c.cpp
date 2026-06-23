#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;

char a[N][N];
int num[N];

bool st[N][N];
int main()
{
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;
            cin>>t;
            a[i][j]=t;
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         cout<<a[i][j]<<" ";
    //     }

    //     cout<<endl;
    // }

    


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(st[i][j])continue;
            if(a[i][j]=='.')continue;
            int k=0;
            for(;k<=n;k++)
            {
                int x=i+k;
                int y=j+k;
                if(x>n||y>m)break;
                if(a[x][y]=='.')break;
                st[x][y]=true;
            }

            num[k/2]++;
        }
    }

    for(int i=1;i<=min(n,m);i++)cout<<num[i]<<" ";


}