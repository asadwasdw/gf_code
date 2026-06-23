#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;
#define int long long
unordered_map<int,set<int>> edgs;
int arr[100000][10];

signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }

    int i,j;

    bool ky=true;

   // cout<<i*7+j<<endl;

    for(int a=1;a<=n&&ky;a++)
    {
        for(int b=1;b<=m&&ky;b++)
        {
            if(a!=1){
                if(arr[a][b]-7!=arr[a-1][b])ky=false;
            }
            if(b!=1)
            {
                
                int t=arr[a][b]%7;
                int T=arr[a][b-1]%7;
                if(arr[a][b]-arr[a][b-1]!=1)ky=false;
                if(t==0)t+=7;
                if(T==0)T+=7;
                if(t-1!=T)ky=false;
            }
           
        }
    }

    if(ky)cout<<"Yes";
    else cout<<"No";


}