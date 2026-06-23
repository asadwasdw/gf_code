#include<iostream>
#include<algorithm>

using namespace std;
const int N=110,M=10010;
int a[N],v[N];
int f[N][M];
int main()
{
    int n,x;
    cin>>n>>x;

    for(int i=1;i<=n;i++)
    cin>>v[i]>>a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            for(int k=0;k<=a[i];k++)
            {
                if(j>=k*v[i]&&f[i-1][j-k*v[i]])f[i][j]=1;
            }
        }
    }

    if(f[n][x])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;



}