#include<iostream>
#include<algorithm>

using namespace std;

int f[1010][1010];

int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    a=" "+a;
    b=" "+b;
   
   for(int i=1;i<=n;i++)f[i][0]=i;
   for(int j=1;j<=m;j++)f[0][j]=j;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){


            if(a[i]==b[j])f[i][j]=f[i-1][j-1];
            else f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
        }
    }
    cout<<f[n][m]<<endl;
}