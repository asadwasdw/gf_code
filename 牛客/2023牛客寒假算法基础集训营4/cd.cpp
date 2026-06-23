#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=5010;
long long dpf[N][N],dpz[N][N];
long long v[N],w[N];
long long n,m;


int main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++){
            dpz[i][j]=dpz[i-1][j];
            if(j>=v[i]){
                dpz[i][j]=max(dpz[i][j],dpz[i-1][j-v[i]]+w[i]);
            }
        }
    }

   // cout<<dpz[n][m]<<endl;


    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++){
            dpf[i][j]=dpf[i-1][j];
            if(j>=v[n-i+1]){
                dpf[i][j]=max(dpf[i][j],dpf[i-1][j-v[n-i+1]]+w[n-i+1]);
            }
        }
    }

    //cout<<dpz[n][m]<<endl;


    for(int i=1;i<=n;i++)
    {
        long long Wbx=0;
        long long Wx=0;
        for(int j=0;j<=m;j++)
        {
            Wbx=max(Wbx,dpz[i-1][j]+dpf[n-i][m-j]);
            if(j<=m-v[i]){
                Wx=max(Wx,dpz[i-1][j]+dpf[n-i][m-v[i]-j]);
            }
        }

        Wx+=w[i];
       // cout<<Wbx<<" "<<Wx<<" ";
        cout<<max((long long)0,Wbx-Wx+1)<<endl;
    }





}