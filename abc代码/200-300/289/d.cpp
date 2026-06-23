#include<iostream>
#include<algorithm>

using namespace std;
const int N=1e6+10;

long long dp[N];
long long b[N];

int main()
{
    int n;cin>>n;
    int m,k;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    cin>>m;

    for(int i=1;i<=m;i++)
    {
        long long  t;cin>>t;
        dp[t]=-1;
    }
    cin>>k;
   // cout<<k<<endl;

    dp[0]=1;

    for(int i=0;i<=k;i++)
    {
        if(dp[i]!=1)continue;
        for(int j=1;j<=n;j++){
            if(dp[i+b[j]]!=-1){
                dp[i+b[j]]=1;
                if(i+b[j]==k){
                 //   cout<<k<<" "<<i<<" "<<b[j]<<endl;
                }
            }
        }
    }

    if(dp[k]==1){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;



}