#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

const int N=1e2+10;
char a[N][N];
char b[N][N];
char c[N][N];
int n;

void bh()
{
    char t[N][N];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            t[i][j]=a[n-j+1][i];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           a[i][j]=t[i][j];
        }
    }

}


bool pd()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            if(a[i][j]=='1')
            {
                if(b[i][j]!='1')return false;
            }
        }
    }

    return true;
}

void solve()
{
    cin>>n;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>b[i][j];
        }
    }

    bool ky=false;
    for(int i=1;i<=4;i++)
    {
        bh();
        if(pd())ky=true;
    }

    if(ky)cout<<"Yes";
    else cout<<"No";
    
}


int main()
{
    //int t;cin>>t;while(t--)
    solve();
}