#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long ULL;
const int N=250;
ULL a[N][N];

void solve()
{
    int n,m;
    cin>>n>>m;
    int x=1<<11;
    cout<<n*m<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]==0;
            if(i==1)
            {
                if(j==1)
                {
                    a[i][j]=x;
                }
                else if(j==2) {
                    a[i][j]=x+1;
                }
                else a[i][j]=a[i][j-2]+4;
            }
            else if(i==2){
                a[i][j]=a[i-1][j]+2;
            }
            else {
                a[i][j]=a[i-1][j]+x;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j]<<" ";
        }

        cout<<endl;
    }

    // for(int i=1;i<=n-2;i++)
    // {
    //     for(int j=1;j<=m-2;j++){
    //         cout<<i<<" "<<j<<" ----";
    //         cout<<((a[i][j])^(a[i+1][j])^(a[i][j+1])^(a[i+1][j+1]))<<endl;
    //     }
    // }

}

int main()
{
    int t;cin>>t;while(t--)
    solve();

}