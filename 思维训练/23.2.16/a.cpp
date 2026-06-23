#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int num[15];
long long a[500];
void solve()
{
    int n;cin>>n;
    int cnt=0;
    memset(num,0,sizeof num);
    memset(a,0,sizeof a);

    for(int i=1;i<=n;i++)
    {
        long long x;cin>>x;
        x%=10;
        num[x]++;
        if(num[x]<=3){
            a[++cnt]=x;
        }
       // cout<<a[cnt]<<endl;
    }

    sort(a+1,a+cnt+1);


    bool ky=false;
    for(int i=1;i<=cnt&&!ky;i++){
        for(int j=i+1;j<=cnt;j++){
            for(int k=j+1;k<=cnt;k++){
             //   cout<<a[i]<<a[j]<<a[k]<<(a[i]+a[j]+a[k]%10)<<endl;
                if((a[i]+a[j]+a[k])%10==3)
                    ky=true;
            }
        }
    }

    if(ky)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}

int main()
{
    int t;cin>>t;while(t--)
    {
      //  cout<<t<<endl;
        solve();
    }
}